#include "main.hpp"
#include "syntax.tab.hh"

void yy::parser::error(const std::string& msg) {};
void yy::parser::report_syntax_error(const yy::parser::context& yyctx) const {
  if (!this->ctx.has_lexical_error) {
    std::cerr << "[ERRO] Erro sintático: não era esperado o token '"
              << yy::parser::symbol_name(yyctx.lookahead().kind()) << "'"
              << " na linha " << this->ctx.line << std::endl;
  };
};