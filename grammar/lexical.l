%{
  #include "../src/syntax/main.h"
  #include "syntax.tab.hh"
  #define YY_DECL yy::parser::symbol_type yylex(Context& context)
  void invalid_token(std::string token, int line);
%}

%option noyywrap nounput noinput

%%
\n+                                            { context.line += yyleng; }
[ \t\r]+                                       {}
"int"                                          { return yy::parser::make_TYPE_INT(NodeType::INT); }
"float"                                        { return yy::parser::make_TYPE_FLOAT(NodeType::FLOAT); }
"double"                                       { return yy::parser::make_TYPE_DOUBLE(NodeType::DOUBLE); }
"long"                                         { return yy::parser::make_TYPE_LONG(NodeType::LONG); }
"byte"                                         { return yy::parser::make_TYPE_BYTE(NodeType::BYTE); }
"string"                                       { return yy::parser::make_TYPE_STRING(NodeType::STRING); }
"char"                                         { return yy::parser::make_TYPE_CHAR(NodeType::CHAR); }
"bool"                                         { return yy::parser::make_TYPE_BOOL(NodeType::BOOL); }
"pointer"                                      { return yy::parser::make_TYPE_POINTER(NodeType::POINTER); }
"option"                                       { return yy::parser::make_TYPE_OPTION(NodeType::OPTION); }
"--"                                           { return yy::parser::make_DECREMENT(); }
"++"                                           { return yy::parser::make_INCREMENT(); }
"**"                                           { return yy::parser::make_EXP(); }      
"=="                                           { return yy::parser::make_EQ(); }
"&="                                           { return yy::parser::make_AND_ATTR(); }
"|="                                           { return yy::parser::make_OR_ATTR(); }
"&&="                                          { return yy::parser::make_LAZY_AND_ATTR(); }
"||="                                          { return yy::parser::make_LAZY_OR_ATTR(); }
"%="                                           { return yy::parser::make_MOD_ATTR(); }
"^="                                           { return yy::parser::make_XOR_ATTR(); }
"+="                                           { return yy::parser::make_PLUS_ATTR(); }
"++="                                          { return yy::parser::make_CONCAT_ATTR(); }
"-="                                           { return yy::parser::make_MINUS_ATTR(); }
"*="                                           { return yy::parser::make_MULT_ATTR(); }
"/="                                           { return yy::parser::make_DIV_ATTR(); }
"&&"                                           { return yy::parser::make_AND(); }
"||"                                           { return yy::parser::make_OR(); }
"&"                                            { return yy::parser::make_REF(); }
"|"                                            { return yy::parser::make_BAR(); }
"!="                                           { return yy::parser::make_NOT_EQ(); }
"<="                                           { return yy::parser::make_LT_EQ(); }
">="                                           { return yy::parser::make_GT_EQ(); }
"<"                                            { return yy::parser::make_LT(); }
">"                                            { return yy::parser::make_GT(); }
"!"                                            { return yy::parser::make_NOT(); }
"~"                                            { return yy::parser::make_REV(); }
"%"                                            { return yy::parser::make_MOD(); }
"^"                                            { return yy::parser::make_XOR(); }
"="                                            { return yy::parser::make_ATTR(); }
"-"                                            { return yy::parser::make_MINUS(); }
"+"                                            { return yy::parser::make_PLUS(); }
"*"                                            { return yy::parser::make_MULT(); }
"/"                                            { return yy::parser::make_DIV(); }
\"([^"\\]|\\.)*\"                              { string content = string(yytext); return yy::parser::make_STRING(content.substr(1, content.length() - 2)); }
^'([^"\\]|\\.)'$                               { return yy::parser::make_CHAR(yytext[1]); }
[0-9]+[lL]                                     { return yy::parser::make_LONG(stoll(yytext)); }
[0-9]+[bB]                                     { return yy::parser::make_BYTE(stoi(yytext)); }
[0-9]+(\.[0-9]+)?[fF]                          { return yy::parser::make_FLOAT(stof(yytext)); }
[0-9]+(\.[0-9]+)?[dD]                          { return yy::parser::make_DOUBLE(stod(yytext)); }
[0-9]+                                         { return yy::parser::make_INT(stoi(yytext)); }
"true"                                         { return yy::parser::make_BOOL(true); }
"false"                                        { return yy::parser::make_BOOL(false); }
"new"                                          { return yy::parser::make_NEW(); }
"var"                                          { return yy::parser::make_VAR(); }
"const"                                        { return yy::parser::make_CONST(); }
".."                                           { return yy::parser::make_RANGE(); }
"."                                            { return yy::parser::make_DOT(); }
","                                            { return yy::parser::make_COMMA(); }
":"                                            { return yy::parser::make_COLON(); }
"::"                                           { return yy::parser::make_DOUBLE_COLON(); }
";"                                            { return yy::parser::make_SEMICOLON(); }
"("                                            { return yy::parser::make_LEFT_PAREN(); }
")"                                            { return yy::parser::make_RIGHT_PAREN(); }
"["                                            { return yy::parser::make_LEFT_BRACKET(); }
"]"                                            { return yy::parser::make_RIGHT_BRACKET(); }
"{"                                            { return yy::parser::make_LEFT_BRACE(); }
"}"                                            { return yy::parser::make_RIGHT_BRACE(); }
"if"                                           { return yy::parser::make_IF(); }
"endif"                                        { return yy::parser::make_END_IF(); }
"then"                                         { return yy::parser::make_THEN(); }
"elif"                                         { return yy::parser::make_ELIF(); }
"else"                                         { return yy::parser::make_ELSE(); }
"for"                                          { return yy::parser::make_FOR(); }
"while"                                        { return yy::parser::make_WHILE(); }
"endwhile"                                     { return yy::parser::make_END_WHILE(); }
"repeat"                                       { return yy::parser::make_REPEAT(); }
"until"                                        { return yy::parser::make_UNTIL(); }
"endfor"                                       { return yy::parser::make_END_FOR(); }
"break"                                        { return yy::parser::make_BREAK(); }
"continue"                                     { return yy::parser::make_CONTINUE(); }
"switch"                                       { return yy::parser::make_SWITCH(); }
"case"                                         { return yy::parser::make_CASE(); }
"default"                                      { return yy::parser::make_DEFAULT(); }
"endswitch"                                    { return yy::parser::make_END_SWITCH(); }
"in"                                           { return yy::parser::make_IN(); }
"some"                                         { return yy::parser::make_SOME(); }
"none"                                         { return yy::parser::make_NONE(); }
"fn"                                           { return yy::parser::make_FUNCTION(); }
"endfn"                                        { return yy::parser::make_END_FUNCTION(); }
"proc"                                         { return yy::parser::make_PROCEDURE(); }
"endproc"                                      { return yy::parser::make_END_PROCEDURE(); }
"enum"                                         { return yy::parser::make_ENUM(); }
"endenum"                                      { return yy::parser::make_END_ENUM(); }
"struct"                                       { return yy::parser::make_STRUCT(); }
"endstruct"                                    { return yy::parser::make_END_STRUCT(); }
"self"                                         { return yy::parser::make_SELF(); }
"impl"                                         { return yy::parser::make_IMPL(); }
"endimpl"                                      { return yy::parser::make_END_IMPL(); }
"trait"                                        { return yy::parser::make_TRAIT(); }
"endtrait"                                     { return yy::parser::make_END_TRAIT(); }
"return"                                       { return yy::parser::make_RETURN(); }
[A-Z][_A-Z0-9]*                                { return yy::parser::make_CONST_NAME(string(yytext)); } 
[A-Z][a-zA-Z0-9]*                              { return yy::parser::make_NAME(string(yytext)); }
[_a-z][_a-zA-Z0-9]*                            { return yy::parser::make_ID(string(yytext)); }
.                                              { invalid_token(yytext, context.line); }
%%

void invalid_token(std::string token, int line) {
  printf("Erro léxico: caractere invalido '%s' na linha %d!\n", token.c_str(), line);
}