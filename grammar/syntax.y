%language "c++"

%code requires {
  #include "../src/main.hpp"
}

%code {
  yy::parser::symbol_type yylex(Context& ctx);
}

%define api.token.constructor 
%define api.value.type variant
%define parse.error custom
%define parse.assert

%param { Context& ctx }

%token <uint8_t>     BYTE
%token <int32_t>     INT
%token <int64_t>     LONG
%token <float>       FLOAT
%token <double>      DOUBLE
%token <bool>        BOOL
%token <std::string> ID NAME CONST_NAME
%token <std::string> STRING
%token <char>        CHAR

%token <Type>    TYPE_BYTE
%token <Type>    TYPE_INT
%token <Type>    TYPE_LONG
%token <Type>    TYPE_FLOAT
%token <Type>    TYPE_DOUBLE
%token <Type>    TYPE_BOOL
%token <Type>    TYPE_STRING
%token <Type>    TYPE_CHAR
%token <Type>    TYPE_POINTER
%token <Type>    TYPE_OPTION

%token DECREMENT INCREMENT EXP EQ AND_ATTR OR_ATTR CONCAT
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

%type <ExpressionNode*> program
%type <ExpressionNode*> expr or_expr and_expr bit_or_expr bit_xor_expr
%type <ExpressionNode*> bit_and_expr equals_expr rel_expr concat_expr sum_expr 
%type <ExpressionNode*> mult_expr unary_expr exp_expr postfix_expr term
%start program

%%
program: expr {
  ctx.root = $1;
  ctx.root->get_type();
};

// TODO: Restante das regras

expr: or_expr {
  $$ = $1;
};

or_expr: or_expr OR and_expr {
  $$ = new BinaryOperationNode(BinaryOperation::OR, $1, $3);
} | and_expr {
  $$ = $1;
};

and_expr: and_expr AND bit_or_expr {
  $$ = new BinaryOperationNode(BinaryOperation::AND, $1, $3);
} | bit_or_expr {
  $$ = $1;
};

bit_or_expr: bit_or_expr BAR bit_xor_expr {
  $$ = new BinaryOperationNode(BinaryOperation::BITWISE_OR, $1, $3);
} | bit_xor_expr {
  $$ = $1;
};

bit_xor_expr: bit_xor_expr XOR bit_and_expr {
  $$ = new BinaryOperationNode(BinaryOperation::XOR, $1, $3);
} | bit_and_expr {
  $$ = $1;
};

bit_and_expr: bit_and_expr REF equals_expr {
  $$ = new BinaryOperationNode(BinaryOperation::BITWISE_AND, $1, $3);
} | equals_expr {
  $$ = $1;
};

equals_expr: equals_expr EQ rel_expr {
  $$ = new BinaryOperationNode(BinaryOperation::EQ, $1, $3);
} | equals_expr NOT_EQ rel_expr {
  $$ = new BinaryOperationNode(BinaryOperation::NOT_EQ, $1, $3);
} | rel_expr {
  $$ = $1;
};

rel_expr: rel_expr LT concat_expr {
  $$ = new BinaryOperationNode(BinaryOperation::LT, $1, $3);
} | rel_expr GT concat_expr {
  $$ = new BinaryOperationNode(BinaryOperation::GT, $1, $3);
} | rel_expr LT_EQ concat_expr {
  $$ = new BinaryOperationNode(BinaryOperation::LT_EQ, $1, $3);
} | rel_expr GT_EQ concat_expr {
  $$ = new BinaryOperationNode(BinaryOperation::GT_EQ, $1, $3);
} | rel_expr IN concat_expr {
  $$ = new BinaryOperationNode(BinaryOperation::IN, $1, $3);
} | concat_expr {
  $$ = $1;
};

concat_expr: concat_expr CONCAT sum_expr {
  $$ = new BinaryOperationNode(BinaryOperation::CONCAT, $1, $3);
} | sum_expr {
  $$ = $1;
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
  $$ = new IntNode(ctx.line, $1);
} | LONG {
  $$ = new LongNode(ctx.line, $1);
} | FLOAT {
  $$ = new FloatNode(ctx.line, $1);
} | DOUBLE {
  $$ = new DoubleNode(ctx.line, $1);
} | BYTE {
  $$ = new ByteNode(ctx.line, $1);
} | BOOL {
  $$ = new BoolNode(ctx.line, $1);
} | STRING {
  $$ = new StringNode(ctx.line, $1);
} | CHAR {
  $$ = new CharNode(ctx.line, $1);
} | NONE {
  $$ = new OptionNode(ctx.line, Option());
} | SOME LEFT_PAREN expr RIGHT_PAREN {
  $$ = new OptionNode(ctx.line, Option());
} | LEFT_PAREN expr RIGHT_PAREN {
  $$ = $2;
};
%%