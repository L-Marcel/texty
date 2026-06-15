#include "errors.hpp"

#include "main.hpp"
#include "syntax.tab.hh"

error::error(const std::string& message, int line)
    : std::runtime_error(ERROR_LABEL + "Erro semântico: " + message +
                         " na linha " + std::to_string(line)) {};

error::error(const std::string& message)
    : std::runtime_error(ERROR_LABEL + "Erro semântico: " + message) {};

void yy::parser::error(const std::string& msg) {};
void yy::parser::report_syntax_error(const yy::parser::context& yyctx) const {
  if (!this->ctx.has_lexical_error) {
    std::cerr << ERROR_LABEL << "Erro sintático: não era esperado o token '"
              << yy::parser::symbol_name(yyctx.lookahead().kind()) << "'"
              << " na linha " << this->ctx.line << std::endl;
  };
};