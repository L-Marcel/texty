%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
%}

%%
\n+                                            {}
[ \t\r]+                                       {}
"#"[^\n]*                                      {}
"int"                                          { printf("TYPE_INT\n"); }
"float"                                        { printf("TYPE_FLOAT\n"); }
"double"                                       { printf("TYPE_DOUBLE\n"); }
"long"                                         { printf("TYPE_LONG\n"); }
"byte"                                         { printf("TYPE_BYTE\n"); }
"string"                                       { printf("TYPE_STRING\n"); }
"char"                                         { printf("TYPE_CHAR\n"); }
"bool"                                         { printf("TYPE_BOOL\n"); }
"pointer"                                      { printf("TYPE_POINTER\n"); }
"option"                                       { printf("TYPE_OPTION\n"); }
"--"                                           { printf("DECREMENT\n"); }
"++"                                           { printf("INCREMENT\n"); }
"**"                                           { printf("EXP\n"); }   
"=="                                           { printf("EQ\n"); }
"&="                                           { printf("AND_ATTR\n"); }
"|="                                           { printf("OR_ATTR\n"); }
"&&="                                          { printf("LAZY_AND_ATTR\n"); }
"||="                                          { printf("LAZY_OR_ATTR\n"); }
"%="                                           { printf("MOD_ATTR\n"); }
"^="                                           { printf("XOR_ATTR\n"); }
"+="                                           { printf("PLUS_ATTR\n"); }
"<<="                                          { printf("CONCAT_ATTR\n"); }
"<<"                                           { printf("CONCAT\n"); }
"-="                                           { printf("MINUS_ATTR\n"); }
"*="                                           { printf("MULT_ATTR\n"); }
"/="                                           { printf("DIV_ATTR\n"); }
"&&"                                           { printf("AND\n"); }
"||"                                           { printf("OR\n"); }
"&"                                            { printf("REF\n"); }
"|"                                            { printf("BAR\n"); }
"!="                                           { printf("NOT_EQ\n"); }
"<="                                           { printf("LT_EQ\n"); }
">="                                           { printf("GT_EQ\n"); }
"<"                                            { printf("LT\n"); }
">"                                            { printf("GT\n"); }
"!"                                            { printf("NOT\n"); }
"~"                                            { printf("REV\n"); }
"%"                                            { printf("MOD\n"); }
"^"                                            { printf("XOR\n"); }
"="                                            { printf("ATTR\n"); }
"-"                                            { printf("MINUS\n"); }
"+"                                            { printf("PLUS\n"); }
"*"                                            { printf("MULT\n"); }
"/"                                            { printf("DIV\n"); }
\"([^\"\\]|\\.)*\"                             { yytext[yyleng-1] = '\0'; printf("STRING(%s)\n", yytext + 1); }
'([^\"\\]|\\.)'                                { printf("CHAR(%c)\n", yytext[1]); }
[0-9]+[lL]                                     { printf("LONG(%lld)\n", atoll(yytext)); }
[0-9]+[bB]                                     { printf("BYTE(%d)\n", atoi(yytext)); }
[0-9]+(\.[0-9]+)?[fF]                          { printf("FLOAT(%f)\n", atof(yytext)); }
[0-9]+(\.[0-9]+)?[dD]                          { printf("DOUBLE(%f)\n", atof(yytext)); }
[0-9]+                                         { printf("INT(%d)\n", atoi(yytext)); }
"true"                                         { printf("BOOL(true)\n"); }
"false"                                        { printf("BOOL(false)\n"); }
"new"                                          { printf("NEW\n"); }
"var"                                          { printf("VAR\n"); }
"const"                                        { printf("CONST\n"); }
".."                                           { printf("RANGE\n"); }
"..="                                          { printf("RANGE_INC\n"); }
"<.."                                          { printf("RANGE_EXC\n"); }
"<..="                                         { printf("RANGE_EXC_INC\n"); }
"."                                            { printf("DOT\n"); }
","                                            { printf("COMMA\n"); }
":"                                            { printf("COLON\n"); }
"::"                                           { printf("DOUBLE_COLON\n"); }
";"                                            { printf("SEMICOLON\n"); }
"("                                            { printf("LEFT_PAREN\n"); }
")"                                            { printf("RIGHT_PAREN\n"); }
"["                                            { printf("LEFT_BRACKET\n"); }
"]"                                            { printf("RIGHT_BRACKET\n"); }
"{"                                            { printf("LEFT_BRACE\n"); }
"}"                                            { printf("RIGHT_BRACE\n"); }
"if"                                           { printf("IF\n"); }
"endif"                                        { printf("END_IF\n"); }
"then"                                         { printf("THEN\n"); }
"elif"                                         { printf("ELIF\n"); }
"else"                                         { printf("ELSE\n"); }
"for"                                          { printf("FOR\n"); }
"while"                                        { printf("WHILE\n"); }
"endwhile"                                     { printf("END_WHILE\n"); }
"repeat"                                       { printf("REPEAT\n"); }
"until"                                        { printf("UNTIL\n"); }
"endfor"                                       { printf("END_FOR\n"); }
"break"                                        { printf("BREAK\n"); }
"continue"                                     { printf("CONTINUE\n"); }
"switch"                                       { printf("SWITCH\n"); }
"case"                                         { printf("CASE\n"); }
"default"                                      { printf("DEFAULT\n"); }
"endswitch"                                    { printf("END_SWITCH\n"); }
"in"                                           { printf("IN\n"); }
"some"                                         { printf("SOME\n"); }
"none"                                         { printf("NONE\n"); }
"fn"                                           { printf("FUNCTION\n"); }
"endfn"                                        { printf("END_FUNCTION\n"); }
"proc"                                         { printf("PROCEDURE\n"); }
"endproc"                                      { printf("END_PROCEDURE\n"); }
"enum"                                         { printf("ENUM\n"); }
"endenum"                                      { printf("END_ENUM\n"); }
"struct"                                       { printf("STRUCT\n"); }
"endstruct"                                    { printf("END_STRUCT\n"); }
"self"                                         { printf("SELF\n"); }
"impl"                                         { printf("IMPL\n"); }
"endimpl"                                      { printf("END_IMPL\n"); }
"trait"                                        { printf("TRAIT\n"); }
"endtrait"                                     { printf("END_TRAIT\n"); }
"return"                                       { printf("RETURN\n"); }
[A-Z][_A-Z0-9]*                                { printf("CONST_NAME(%s)\n", yytext); } 
[A-Z][a-zA-Z0-9]*                              { printf("NAME(%s)\n", yytext); }
[_a-z][_a-zA-Z0-9]*                            { printf("ID(%s)\n", yytext); }
.                                              { printf("ERRO\n"); }
%%

#ifndef yywrap
  int yywrap () { return 1; }
#endif

int main() {
  printf("Digite qualquer coisa (Ctrl + D para sair):\n");
  yylex();
  return 0;
}
