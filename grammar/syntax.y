%language "c++"

%code requires {
  #include <string>
  #include <cstdint>
  #include "../src/syntax/main.h"
  #include "../src/context.h"
}

%define api.token.constructor 
%define api.value.type variant
%define parse.assert

%param { Context& context }

%code {
  yy::parser::symbol_type yylex(Context& context);
}

%token <uint8_t>     BYTE
%token <int32_t>     INT
%token <int64_t>     LONG
%token <float>       FLOAT
%token <double>      DOUBLE
%token <bool>        BOOL
%token <std::string> ID NAME CONST_NAME
%token <std::string> STRING
%token <char>        CHAR

%token <NodeType>    TYPE_BYTE
%token <NodeType>    TYPE_INT
%token <NodeType>    TYPE_LONG
%token <NodeType>    TYPE_FLOAT
%token <NodeType>    TYPE_DOUBLE
%token <NodeType>    TYPE_BOOL
%token <NodeType>    TYPE_STRING
%token <NodeType>    TYPE_CHAR
%token <NodeType>    TYPE_POINTER
%token <NodeType>    TYPE_OPTION

%token DECREMENT INCREMENT EXP EQ AND_ATTR OR_ATTR
%token LAZY_AND_ATTR LAZY_OR_ATTR MOD_ATTR XOR_ATTR PLUS_ATTR
%token CONCAT_ATTR MINUS_ATTR MULT_ATTR DIV_ATTR AND OR REF BAR
%token NOT_EQ LT_EQ GT_EQ LT GT NOT REV MOD XOR ATTR MINUS PLUS
%token MULT DIV NEW VAR CONST RANGE DOT COMMA COLON DOUBLE_COLON
%token SEMICOLON LEFT_PAREN RIGHT_PAREN LEFT_BRACKET RIGHT_BRACKET
%token LEFT_BRACE RIGHT_BRACE IF END_IF THEN ELIF ELSE FOR WHILE
%token END_WHILE REPEAT UNTIL END_FOR BREAK CONTINUE SWITCH CASE
%token DEFAULT END_SWITCH IN SOME NONE FUNCTION END_FUNCTION
%token PROCEDURE END_PROCEDURE ENUM END_ENUM STRUCT END_STRUCT SELF
%token IMPL END_IMPL TRAIT END_TRAIT RETURN

%type <Node*> program sum_expr mult_expr unary_expr exp_expr postfix_expr term
%start program

%%
program: sum_expr {
  context.root = $1; // "Entrega" a árvore pronta para o contexto
};

sum_expr: sum_expr PLUS mult_expr {
  $$ = new BinaryOperationNode(BinaryOperation::PLUS, $1, $3);
} | sum_expr MINUS mult_expr {
  $$ = new BinaryOperationNode(BinaryOperation::MINUS, $1, $3);
} | mult_expr {
  $$ = $1;
};

mult_expr: mult_expr MULT unary_expr {
  $$ = new BinaryOperationNode(BinaryOperation::MULT, $1, $3);
} | mult_expr DIV unary_expr {
  $$ = new BinaryOperationNode(BinaryOperation::DIV, $1, $3);
} | mult_expr MOD unary_expr {
  $$ = new BinaryOperationNode(BinaryOperation::MOD, $1, $3);
} | unary_expr {
  $$ = $1;
};

unary_expr: MINUS exp_expr {
  $$ = new UnaryOperationNode(UnaryOperation::MINUS, $2);
} | REV exp_expr {
  $$ = new UnaryOperationNode(UnaryOperation::REV, $2);
} | NOT exp_expr {
  $$ = new UnaryOperationNode(UnaryOperation::NOT, $2);
} | REF exp_expr {
  $$ = new UnaryOperationNode(UnaryOperation::REF, $2);
} | INCREMENT exp_expr {
  $$ = new UnaryOperationNode(UnaryOperation::INCREMENT, $2);
} | DECREMENT exp_expr {
  $$ = new UnaryOperationNode(UnaryOperation::DECREMENT, $2);
} | exp_expr {
  $$ = $1;
};

exp_expr: postfix_expr EXP exp_expr {
  $$ = new BinaryOperationNode(BinaryOperation::EXP, $1, $3);
} | postfix_expr {
  $$ = $1;
};

postfix_expr: term INCREMENT {
  $$ = new UnaryOperationNode(true, UnaryOperation::INCREMENT, $1);
} | term DECREMENT {
  $$ = new UnaryOperationNode(true, UnaryOperation::DECREMENT, $1);
} | term {
  $$ = $1;
};

term: INT {
  $$ = new IntNode(context.line, $1);
} | LONG {
  $$ = new LongNode(context.line, $1);
} | FLOAT {
  $$ = new FloatNode(context.line, $1);
} | DOUBLE {
  $$ = new DoubleNode(context.line, $1);
} | BYTE {
  $$ = new ByteNode(context.line, $1);
} | BOOL {
  $$ = new BoolNode(context.line, $1);
} | STRING {
  $$ = new StringNode(context.line, $1);
} | CHAR {
  $$ = new CharNode(context.line, $1);
};
%%