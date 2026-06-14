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
%token <string>      ID NAME CONST_NAME
%token <string>      STRING
%token <char>        CHAR

%token <TypeKind>    TYPE_BYTE
%token <TypeKind>    TYPE_INT
%token <TypeKind>    TYPE_LONG
%token <TypeKind>    TYPE_FLOAT
%token <TypeKind>    TYPE_DOUBLE
%token <TypeKind>    TYPE_BOOL
%token <TypeKind>    TYPE_STRING
%token <TypeKind>    TYPE_CHAR
%token <TypeKind>    TYPE_POINTER
%token <TypeKind>    TYPE_OPTION

%token DECREMENT INCREMENT EXP EQ AND_ATTR OR_ATTR CONCAT
%token LAZY_AND_ATTR LAZY_OR_ATTR MOD_ATTR XOR_ATTR PLUS_ATTR
%token CONCAT_ATTR MINUS_ATTR MULT_ATTR DIV_ATTR AND OR REF BAR
%token NOT_EQ LT_EQ GT_EQ LT GT NOT REV MOD XOR ATTR MINUS PLUS
%token MULT DIV NEW VAR CONST RANGE RANGE_INC RANGE_EXC RANGE_EXC_INC 
%token DOT COMMA COLON DOUBLE_COLON SEMICOLON LEFT_PAREN RIGHT_PAREN 
%token LEFT_BRACKET RIGHT_BRACKET LEFT_BRACE RIGHT_BRACE IF END_IF THEN 
%token ELIF ELSE FOR WHILE END_WHILE REPEAT UNTIL END_FOR BREAK CONTINUE 
%token SWITCH CASE DEFAULT END_SWITCH IN SOME NONE FUNCTION END_FUNCTION
%token PROCEDURE END_PROCEDURE ENUM END_ENUM STRUCT END_STRUCT SELF
%token IMPL END_IMPL TRAIT END_TRAIT RETURN

%type <TraitNode*> trait
%type <ImplNode*> impl
%type <SubprogramNode*> trait_subprogram impl_subprogram
%type <vector<SubprogramNode*>> trait_subprograms impl_subprograms
%type <string> id name
%type <vector<Node*>> stmts 
%type <AccessBaseNode*> access_base
%type <SubprogramCallNode*> subprogram_call
%type <pair<RangeInclusionType, RangeInclusionType>> range_interval
%type <RangeNode*> range_expr
%type <AttrNode*> attr
%type <AssignNode*> assign
%type <ReturnNode*> return
%type <AccessNode*> access
%type <IfNode*> if
%type <IfEndNode*> if_end
%type <ForNode*> for
%type <WhileNode*> while repeat
%type <SwitchNode*> switch 
%type <CaseNode*> case default_case
%type <vector<ExpressionNode*>> case_values
%type <vector<CaseNode*>> cases case_list
%type <ProgramNode*> root program
%type <Node*> program_slice stmt
%type <SubprogramNode*> subprogram
%type <Type*> type basic_type
%type <vector<pair<string, Type>>> params_self_list params_list params 
%type <vector<pair<string, Type>>> param struct_attrs struct_attr
%type <vector<string>> id_list enum_values
%type <EnumNode*> enum
%type <StructNode*> struct
%type <FunctionNode*> fn trait_fn impl_fn
%type <ProcedureNode*> proc trait_proc impl_proc
%type <ArrayAllocationNode*> array_allocation
%type <vector<ExpressionNode*>> call_params_list call_params array_allocation_values
%type <StructAllocationNode*> struct_allocation
%type <vector<pair<string, ExpressionNode*>>> struct_allocation_values
%type <ExpressionNode*> expr or_expr and_expr bit_or_expr bit_xor_expr
%type <ExpressionNode*> bit_and_expr equals_expr rel_expr concat_expr sum_expr 
%type <ExpressionNode*> mult_expr unary_expr exp_expr postfix_expr term
%start root

%%
root: program {
  ctx.root = $1;
};

program: program program_slice {
  $$ = $1;
  $1->children.push_back($2);
} | program_slice {
  $$ = new ProgramNode(ctx.line);
  $$->children.push_back($1);
};

program_slice: subprogram {
  $$ = $1;
} | enum {
  $$ = $1;
} | struct {
  $$ = $1;
} | trait {
  $$ = $1;
} | impl {
  $$ = $1;
};

subprogram: fn {
  $$ = $1;
} | proc {
  $$ = $1;
};

fn: FUNCTION ID params_list COLON type stmts END_FUNCTION SEMICOLON {
  $$ = new FunctionNode(ctx.line, $2, *$5, $3, false, true);
  for (size_t i = 0; i < $6.size(); i++) {
    $$->children.push_back($6[i]);
  };
};

proc: PROCEDURE ID params_list stmts END_PROCEDURE SEMICOLON {
  $$ = new ProcedureNode(ctx.line, $2, $3, false, true);
  for (size_t i = 0; i < $4.size(); i++) {
    $$->children.push_back($4[i]);
  };
} | PROCEDURE ID params_list END_PROCEDURE SEMICOLON {
  $$ = new ProcedureNode(ctx.line, $2, $3, false, true);
};

params_self_list: LEFT_PAREN SELF SEMICOLON params RIGHT_PAREN {
  $$ = $4;
} | LEFT_PAREN SELF RIGHT_PAREN {
  $$ = vector<pair<string, Type>>();
};

params_list: LEFT_PAREN params RIGHT_PAREN {
  $$ = $2;
} | LEFT_PAREN RIGHT_PAREN {
  $$ = vector<pair<string, Type>>();
};

params: params SEMICOLON param {
  $$ = $1;
  for (size_t i = 0; i < $3.size(); i++) {
    $$.push_back($3[i]);
  };
} | param {
  $$ = vector<pair<string, Type>>();
  for (size_t i = 0; i < $1.size(); i++) {
    $$.push_back($1[i]);
  };
};

param: id_list COLON type {
  $$ = vector<pair<string, Type>>();
  for (size_t i = 0; i < $1.size(); i++) {
    $$.push_back({$1[i], *$3});
  };
};

id_list: id_list COMMA ID {
  $$ = $1;
  $$.push_back($3);
} | ID {
  $$ = vector<string>();
  $$.push_back($1);
};

subprogram_call: access call_params_list {
  $$ = new SubprogramCallNode(ctx.line, $1, $2);
} | basic_type call_params_list {
  $$ = new SubprogramCallNode(ctx.line, *$1, $2);
};

call_params_list: LEFT_PAREN call_params RIGHT_PAREN {
  $$ = $2;
} | LEFT_PAREN RIGHT_PAREN {
  $$ = vector<ExpressionNode*>();
};

call_params: call_params COMMA expr {
  $$ = $1;
  $$.push_back($3);
} | expr {
  $$ = vector<ExpressionNode*>();
  $$.push_back($1);
};

enum: ENUM name enum_values END_ENUM SEMICOLON {
  $$ = new EnumNode(ctx.line, $2, $3);
} | ENUM name END_ENUM SEMICOLON {
  $$ = new EnumNode(ctx.line, $2, vector<string>());
};

enum_values: enum_values COMMA CONST_NAME {
  $$ = $1;
  $$.push_back($3);
} | CONST_NAME {
  $$ = vector<string>();
  $$.push_back($1);
};

struct: STRUCT name struct_attrs END_STRUCT SEMICOLON {
  $$ = new StructNode(ctx.line, $2, $3);
} | STRUCT name END_STRUCT SEMICOLON {
  $$ = new StructNode(ctx.line, $2, vector<pair<string, Type>>());
};

struct_attrs: struct_attrs struct_attr SEMICOLON {
  $$ = $1;
  for (size_t i = 0; i < $2.size(); i++) {
    $$.push_back($2[i]);
  };
} | struct_attr SEMICOLON {
  $$ = $1;
};

struct_attr: id_list COLON type {
  $$ = vector<pair<string, Type>>();
  for (size_t i = 0; i < $1.size(); i++) {
    $$.push_back({$1[i], *$3});
  };
};

trait: TRAIT name trait_subprograms END_TRAIT SEMICOLON {
  $$ = new TraitNode(ctx.line, $2, $3);
} | TRAIT name END_TRAIT SEMICOLON {
  $$ = new TraitNode(ctx.line, $2, vector<SubprogramNode*>());
};

trait_subprograms: trait_subprograms trait_subprogram {
  $$ = $1;
  $$.push_back($2);
} | trait_subprogram {
  $$ = vector<SubprogramNode*>();
  $$.push_back($1);
};

trait_subprogram: trait_fn {
  $$ = $1;
} | trait_proc {
  $$ = $1;
};

trait_fn: FUNCTION ID params_self_list COLON type SEMICOLON {
  $$ = new FunctionNode(ctx.line, $2, *$5, $3, true, false);
} | FUNCTION ID params_list COLON type SEMICOLON {
  $$ = new FunctionNode(ctx.line, $2, *$5, $3, false, false);
};

trait_proc: PROCEDURE ID params_self_list SEMICOLON {
  $$ = new ProcedureNode(ctx.line, $2, $3, true, false);
} | PROCEDURE ID params_list SEMICOLON {
  $$ = new ProcedureNode(ctx.line, $2, $3, false, false);
};

impl: IMPL name impl_subprograms END_IMPL SEMICOLON {
  $$ = new ImplNode(ctx.line, $2, $3);
} | IMPL name END_IMPL SEMICOLON {
  $$ = new ImplNode(ctx.line, $2, vector<SubprogramNode*>());
} | IMPL name FOR name impl_subprograms END_IMPL SEMICOLON {
  $$ = new ImplNode(ctx.line, $2, $4, $5);
} | IMPL name FOR name END_IMPL SEMICOLON {
  $$ = new ImplNode(ctx.line, $2, $4, vector<SubprogramNode*>());
};

impl_subprograms: impl_subprograms impl_subprogram {
  $$ = $1;
  $$.push_back($2);
} | impl_subprogram {
  $$ = vector<SubprogramNode*>();
  $$.push_back($1);
};

impl_subprogram: impl_fn {
  $$ = $1;
} | impl_proc {
  $$ = $1;
};

impl_fn: FUNCTION ID params_self_list COLON type stmts END_FUNCTION SEMICOLON {
  $$ = new FunctionNode(ctx.line, $2, *$5, $3, true, true);
  for (size_t i = 0; i < $6.size(); i++) {
    $$->children.push_back($6[i]);
  };
} | fn {
  $$ = $1;
};

impl_proc: PROCEDURE ID params_self_list stmts END_PROCEDURE SEMICOLON {
  $$ = new ProcedureNode(ctx.line, $2, $3, true, true);
  for (size_t i = 0; i < $4.size(); i++) {
    $$->children.push_back($4[i]);
  };
} | PROCEDURE ID params_self_list END_PROCEDURE SEMICOLON {
  $$ = new ProcedureNode(ctx.line, $2, $3, true, true);
} | proc {
  $$ = $1;
};

access: access DOT CONST_NAME {
  $$ = new AccessNode(ctx.line, $3, $1, AccessType::DOT);
} | access DOT ID {
  $$ = new AccessNode(ctx.line, $3, $1, AccessType::DOT);
} | access LEFT_BRACKET expr RIGHT_BRACKET {
  $$ = new AccessNode(ctx.line, $1, $3);
} | access DOUBLE_COLON ID {
  $$ = new AccessNode(ctx.line, $3, $1, AccessType::STATIC);
} | subprogram_call {
  $$ = new AccessNode(ctx.line, $1);
} | access_base {
  $$ = new AccessNode(ctx.line, $1);
};

access_base: SELF {
  $$ = new AccessBaseNode(ctx.line);
} | id {
  $$ = new AccessBaseNode(ctx.line, $1);
} | LEFT_PAREN expr RIGHT_PAREN {
  $$ = new AccessBaseNode(ctx.line, $2);
};

id: NAME {
  $$ = $1;
} | ID {
  $$ = $1;
};

name: NAME {
  $$ = $1;
} | CONST_NAME {
  $$ = $1;
};

stmts: stmts stmt SEMICOLON {
  $$ = $1;
  $$.push_back($2);
} | stmt SEMICOLON {
  $$ = vector<Node*>();
  $$.push_back($1);
};

stmt: BREAK {
  $$ = new BreakNode(ctx.line);
} | CONTINUE {
  $$ = new ContinueNode(ctx.line);
} | attr {
  $$ = $1;
} | assign {
  $$ = $1;
} | return {
  $$ = $1;
} | if {
  $$ = $1;
} | for {
  $$ = $1;
} | while {
  $$ = $1;
} | repeat {
  $$ = $1;
} | switch {
  $$ = $1;
} | expr {
  $$ = $1;
};

return: RETURN expr {
  $$ = new ReturnNode(ctx.line, $2);
};

attr: VAR ID COLON type ATTR expr {
  $$ = new AttrNode(ctx.line, $2, false, *$4, $6);
} | CONST ID COLON type ATTR expr {
  $$ = new AttrNode(ctx.line, $2, true, *$4, $6);
};

basic_type: TYPE_INT {
  $$ = new Type(TypeKind::INT);
} | TYPE_FLOAT {
  $$ = new Type(TypeKind::FLOAT);
} | TYPE_DOUBLE {
  $$ = new Type(TypeKind::DOUBLE);
} | TYPE_LONG {
  $$ = new Type(TypeKind::LONG);
} | TYPE_BYTE {
  $$ = new Type(TypeKind::BYTE);
} | TYPE_STRING {
  $$ = new Type(TypeKind::STRING);
} | TYPE_CHAR {
  $$ = new Type(TypeKind::CHAR);
} | TYPE_BOOL {
  $$ = new Type(TypeKind::BOOL);
};

type: basic_type {
  $$ = $1;
} | type LEFT_BRACKET RIGHT_BRACKET {
  $$ = new Type(TypeKind::ARRAY, $1);
} | TYPE_POINTER LT type GT {
  $$ = new Type(TypeKind::POINTER, $3);
} | TYPE_OPTION LT type GT {
  $$ = new Type(TypeKind::OPTION, $3);
} | name {
  $$ = new Type(TypeKind::NAMED, $1);
};

assign: access ATTR expr {
  $$ = new AssignNode(ctx.line, $1, $3);
} | access AND_ATTR expr {
  $$ = new AssignNode(ctx.line, BinaryOperation::AND, $1, $3);
} | access OR_ATTR expr {
  $$ = new AssignNode(ctx.line, BinaryOperation::OR, $1, $3);
} | access LAZY_AND_ATTR expr {
  $$ = new AssignNode(ctx.line, BinaryOperation::BITWISE_AND, $1, $3);
} | access LAZY_OR_ATTR expr {
  $$ = new AssignNode(ctx.line, BinaryOperation::BITWISE_OR, $1, $3);
} | access XOR_ATTR expr {
  $$ = new AssignNode(ctx.line, BinaryOperation::XOR, $1, $3);
} | access CONCAT_ATTR expr {
  $$ = new AssignNode(ctx.line, BinaryOperation::CONCAT, $1, $3);
} | access MOD_ATTR expr {
  $$ = new AssignNode(ctx.line, BinaryOperation::MOD, $1, $3);
} | access PLUS_ATTR expr {
  $$ = new AssignNode(ctx.line, BinaryOperation::PLUS, $1, $3);
} | access MINUS_ATTR expr {
  $$ = new AssignNode(ctx.line, BinaryOperation::MINUS, $1, $3);
} | access MULT_ATTR expr {
  $$ = new AssignNode(ctx.line, BinaryOperation::MULT, $1, $3);
} | access DIV_ATTR expr {
  $$ = new AssignNode(ctx.line, BinaryOperation::DIV, $1, $3);
};

if: IF expr THEN stmts if_end {
  $$ = new IfNode(ctx.line, $2, $5);
  for (size_t i = 0; i < $4.size(); i++) {
    $$->children.push_back($4[i]);
  };
} | IF SOME ID IN expr THEN stmts if_end {
  $$ = new IfNode(ctx.line, $5, $3, $8);
  for (size_t i = 0; i < $7.size(); i++) {
    $$->children.push_back($7[i]);
  };
};

if_end: ELIF expr THEN stmts if_end {
  $$ = new IfEndNode(ctx.line, $2, $5);
  for (size_t i = 0; i < $4.size(); i++) {
    $$->children.push_back($4[i]);
  };
} | ELIF SOME ID IN expr THEN stmts if_end {
  $$ = new IfEndNode(ctx.line, $5, $3, $8);
  for (size_t i = 0; i < $7.size(); i++) {
    $$->children.push_back($7[i]);
  };
} | ELSE stmts END_IF {
  $$ = new IfEndNode(ctx.line, new IfEndNode(ctx.line));
  for (size_t i = 0; i < $2.size(); i++) {
    $$->children.push_back($2[i]);
  };
} | END_IF {
  $$ = new IfEndNode(ctx.line);
};

switch: SWITCH expr cases END_SWITCH {
  $$ = new SwitchNode(ctx.line, $2, $3);
};

cases: case_list default_case {
  $$ = $1;
  $$.push_back($2);
} | default_case {
  $$ = vector<CaseNode*>();
  $$.push_back($1);
};

case_list: case_list case {
  $$ = $1;
  $$.push_back($2);
} | case {
  $$ = vector<CaseNode*>();
  $$.push_back($1);
};

case: CASE case_values COLON stmts {
  $$ = new CaseNode(ctx.line, $2);
  for (size_t i = 0; i < $4.size(); i++) {
    $$->children.push_back($4[i]);
  };
};

case_values: case_values COMMA term {
  $$ = $1;
  $$.push_back($3);
} | term {
  $$ = vector<ExpressionNode*>();
  $$.push_back($1);
};

default_case: DEFAULT COLON stmts {
  $$ = new CaseNode(ctx.line);
  for (size_t i = 0; i < $3.size(); i++) {
    $$->children.push_back($3[i]);
  };
};

for: FOR LEFT_PAREN ID IN expr RIGHT_PAREN stmts END_FOR {
  $$ = new ForNode(ctx.line, $3, $5);
  for (size_t i = 0; i < $7.size(); i++) {
    $$->children.push_back($7[i]);
  };
} | FOR LEFT_PAREN ID IN expr RIGHT_PAREN END_FOR {
  $$ = new ForNode(ctx.line, $3, $5);
} | FOR LEFT_PAREN attr SEMICOLON expr SEMICOLON expr RIGHT_PAREN stmts END_FOR {
  $$ = new ForNode(ctx.line, $3, $5, $7);
  for (size_t i = 0; i < $9.size(); i++) {
    $$->children.push_back($9[i]);
  };
} | FOR LEFT_PAREN attr SEMICOLON expr SEMICOLON expr RIGHT_PAREN END_FOR {
  $$ = new ForNode(ctx.line, $3, $5, $7);
};

while: WHILE LEFT_PAREN expr RIGHT_PAREN stmts END_WHILE {
  $$ = new WhileNode(ctx.line, $3, WhileType::WHILE);
  for (size_t i = 0; i < $5.size(); i++) {
    $$->children.push_back($5[i]);
  };
} | WHILE LEFT_PAREN expr RIGHT_PAREN END_WHILE {
  $$ = new WhileNode(ctx.line, $3, WhileType::WHILE);
};

repeat: REPEAT stmts UNTIL expr {
  $$ = new WhileNode(ctx.line, $4, WhileType::REPEAT);
  for (size_t i = 0; i < $2.size(); i++) {
    $$->children.push_back($2[i]);
  };
} | REPEAT UNTIL expr {
  $$ = new WhileNode(ctx.line, $3, WhileType::REPEAT);
};

expr: or_expr {
  $$ = $1;
} | range_expr {
  $$ = $1;
};

range_expr: range_interval or_expr {
  $$ = new RangeNode(ctx.line, false, $2, $1.second);
} | or_expr range_interval {
  $$ = new RangeNode(ctx.line, true, $1, $2.first);
} | or_expr range_interval or_expr {
  $$ = new RangeNode(ctx.line, $1, $2.first, $3, $2.second);
};

range_interval: RANGE {
  $$ = {RangeInclusionType::INCLUSIVE, RangeInclusionType::EXCLUSIVE};
} | RANGE_EXC {
  $$ = {RangeInclusionType::EXCLUSIVE, RangeInclusionType::EXCLUSIVE};
} | RANGE_EXC_INC {
  $$ = {RangeInclusionType::EXCLUSIVE, RangeInclusionType::INCLUSIVE};
} | RANGE_INC {
  $$ = {RangeInclusionType::INCLUSIVE, RangeInclusionType::INCLUSIVE};
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
} | MULT exp_expr {
  $$ = new UnaryOperationNode(UnaryOperation::DEREF, $2);
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
  $$ = new OptionNode(ctx.line);
} | array_allocation {
  $$ = $1;
} | struct_allocation {
  $$ = $1;
} | access {
  $$ = $1;
} | SOME LEFT_PAREN expr RIGHT_PAREN {
  $$ = new OptionNode(ctx.line, $3);
};

array_allocation: NEW type LEFT_BRACKET expr RIGHT_BRACKET {
  $$ = new ArrayAllocationNode(ctx.line, *$2, $4);
} | NEW type LEFT_BRACKET expr RIGHT_BRACKET LEFT_BRACE array_allocation_values RIGHT_BRACE {
  $$ = new ArrayAllocationNode(ctx.line, *$2, $4);
  for (size_t i = 0; i < $7.size(); i++) {
    $$->children.push_back($7[i]);
  };
} | NEW type LEFT_BRACKET RIGHT_BRACKET {
  $$ = new ArrayAllocationNode(ctx.line, *$2);
} | NEW type LEFT_BRACKET RIGHT_BRACKET LEFT_BRACE array_allocation_values RIGHT_BRACE {
  $$ = new ArrayAllocationNode(ctx.line, *$2);
  for (size_t i = 0; i < $6.size(); i++) {
    $$->children.push_back($6[i]);
  };
};

array_allocation_values: array_allocation_values COMMA expr {
  $$ = $1;
  $$.push_back($3);
} | expr {
  $$ = vector<ExpressionNode*>();
  $$.push_back($1);
};

struct_allocation: NEW name LEFT_BRACE struct_allocation_values RIGHT_BRACE {
 $$ = new StructAllocationNode(ctx.line, $2, $4);
} | NEW name LEFT_BRACE RIGHT_BRACE {
  $$ = new StructAllocationNode(ctx.line, $2, vector<pair<string, ExpressionNode*>>());
};

struct_allocation_values: struct_allocation_values COMMA ID COLON expr {
  $$ = $1;
  $$.push_back({ $3, $5});
} | ID COLON expr {
  $$ = vector<pair<string, ExpressionNode*>>();
  $$.push_back({ $1, $3});
};
%%