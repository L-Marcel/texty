// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "syntax.tab.hh"


// Unqualified %code blocks.
#line 7 "grammar/syntax.y"

  yy::parser::symbol_type yylex(Context& ctx);

#line 50 "grammar/build/syntax.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 123 "grammar/build/syntax.tab.cc"

  /// Build a parser object.
  parser::parser (Context& ctx_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      ctx (ctx_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_range_expr: // range_expr
      case symbol_kind::S_or_expr: // or_expr
      case symbol_kind::S_and_expr: // and_expr
      case symbol_kind::S_bit_or_expr: // bit_or_expr
      case symbol_kind::S_bit_xor_expr: // bit_xor_expr
      case symbol_kind::S_bit_and_expr: // bit_and_expr
      case symbol_kind::S_equals_expr: // equals_expr
      case symbol_kind::S_rel_expr: // rel_expr
      case symbol_kind::S_concat_expr: // concat_expr
      case symbol_kind::S_sum_expr: // sum_expr
      case symbol_kind::S_mult_expr: // mult_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_exp_expr: // exp_expr
      case symbol_kind::S_postfix_expr: // postfix_expr
      case symbol_kind::S_term: // term
        value.YY_MOVE_OR_COPY< ExpressionNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fn: // fn
        value.YY_MOVE_OR_COPY< FunctionNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_program_slice: // program_slice
      case symbol_kind::S_subprogram: // subprogram
      case symbol_kind::S_subprogram_call: // subprogram_call
      case symbol_kind::S_call_params_list: // call_params_list
      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_enum: // enum
      case symbol_kind::S_enum_values: // enum_values
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_struct_attrs: // struct_attrs
      case symbol_kind::S_struct_attr: // struct_attr
      case symbol_kind::S_trait: // trait
      case symbol_kind::S_trait_subprograms: // trait_subprograms
      case symbol_kind::S_trait_subprogram: // trait_subprogram
      case symbol_kind::S_trait_fn: // trait_fn
      case symbol_kind::S_trait_proc: // trait_proc
      case symbol_kind::S_impl: // impl
      case symbol_kind::S_impl_subprograms: // impl_subprograms
      case symbol_kind::S_impl_subprogram: // impl_subprogram
      case symbol_kind::S_impl_fn: // impl_fn
      case symbol_kind::S_impl_proc: // impl_proc
      case symbol_kind::S_access: // access
      case symbol_kind::S_access_base: // access_base
      case symbol_kind::S_id: // id
      case symbol_kind::S_name: // name
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_return: // return
      case symbol_kind::S_attr: // attr
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_if: // if
      case symbol_kind::S_if_end: // if_end
      case symbol_kind::S_switch: // switch
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_case: // case
      case symbol_kind::S_case_values: // case_values
      case symbol_kind::S_default_case: // default_case
      case symbol_kind::S_for: // for
      case symbol_kind::S_while: // while
      case symbol_kind::S_repeat: // repeat
      case symbol_kind::S_range_interval: // range_interval
      case symbol_kind::S_array_allocation: // array_allocation
      case symbol_kind::S_array_allocation_values: // array_allocation_values
      case symbol_kind::S_struct_allocation: // struct_allocation
      case symbol_kind::S_struct_allocation_values: // struct_allocation_values
        value.YY_MOVE_OR_COPY< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_proc: // proc
        value.YY_MOVE_OR_COPY< ProcedureNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< Type* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TYPE_BYTE: // TYPE_BYTE
      case symbol_kind::S_TYPE_INT: // TYPE_INT
      case symbol_kind::S_TYPE_LONG: // TYPE_LONG
      case symbol_kind::S_TYPE_FLOAT: // TYPE_FLOAT
      case symbol_kind::S_TYPE_DOUBLE: // TYPE_DOUBLE
      case symbol_kind::S_TYPE_BOOL: // TYPE_BOOL
      case symbol_kind::S_TYPE_STRING: // TYPE_STRING
      case symbol_kind::S_TYPE_CHAR: // TYPE_CHAR
        value.YY_MOVE_OR_COPY< TypeKind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR: // CHAR
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.YY_MOVE_OR_COPY< int32_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LONG: // LONG
        value.YY_MOVE_OR_COPY< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_CONST_NAME: // CONST_NAME
      case symbol_kind::S_STRING: // STRING
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BYTE: // BYTE
        value.YY_MOVE_OR_COPY< uint8_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_params_self_list: // params_self_list
      case symbol_kind::S_params_list: // params_list
      case symbol_kind::S_params: // params
      case symbol_kind::S_param: // param
        value.YY_MOVE_OR_COPY< vector<Param> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id_list: // id_list
        value.YY_MOVE_OR_COPY< vector<string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_range_expr: // range_expr
      case symbol_kind::S_or_expr: // or_expr
      case symbol_kind::S_and_expr: // and_expr
      case symbol_kind::S_bit_or_expr: // bit_or_expr
      case symbol_kind::S_bit_xor_expr: // bit_xor_expr
      case symbol_kind::S_bit_and_expr: // bit_and_expr
      case symbol_kind::S_equals_expr: // equals_expr
      case symbol_kind::S_rel_expr: // rel_expr
      case symbol_kind::S_concat_expr: // concat_expr
      case symbol_kind::S_sum_expr: // sum_expr
      case symbol_kind::S_mult_expr: // mult_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_exp_expr: // exp_expr
      case symbol_kind::S_postfix_expr: // postfix_expr
      case symbol_kind::S_term: // term
        value.move< ExpressionNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fn: // fn
        value.move< FunctionNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_program_slice: // program_slice
      case symbol_kind::S_subprogram: // subprogram
      case symbol_kind::S_subprogram_call: // subprogram_call
      case symbol_kind::S_call_params_list: // call_params_list
      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_enum: // enum
      case symbol_kind::S_enum_values: // enum_values
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_struct_attrs: // struct_attrs
      case symbol_kind::S_struct_attr: // struct_attr
      case symbol_kind::S_trait: // trait
      case symbol_kind::S_trait_subprograms: // trait_subprograms
      case symbol_kind::S_trait_subprogram: // trait_subprogram
      case symbol_kind::S_trait_fn: // trait_fn
      case symbol_kind::S_trait_proc: // trait_proc
      case symbol_kind::S_impl: // impl
      case symbol_kind::S_impl_subprograms: // impl_subprograms
      case symbol_kind::S_impl_subprogram: // impl_subprogram
      case symbol_kind::S_impl_fn: // impl_fn
      case symbol_kind::S_impl_proc: // impl_proc
      case symbol_kind::S_access: // access
      case symbol_kind::S_access_base: // access_base
      case symbol_kind::S_id: // id
      case symbol_kind::S_name: // name
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_return: // return
      case symbol_kind::S_attr: // attr
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_if: // if
      case symbol_kind::S_if_end: // if_end
      case symbol_kind::S_switch: // switch
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_case: // case
      case symbol_kind::S_case_values: // case_values
      case symbol_kind::S_default_case: // default_case
      case symbol_kind::S_for: // for
      case symbol_kind::S_while: // while
      case symbol_kind::S_repeat: // repeat
      case symbol_kind::S_range_interval: // range_interval
      case symbol_kind::S_array_allocation: // array_allocation
      case symbol_kind::S_array_allocation_values: // array_allocation_values
      case symbol_kind::S_struct_allocation: // struct_allocation
      case symbol_kind::S_struct_allocation_values: // struct_allocation_values
        value.move< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_proc: // proc
        value.move< ProcedureNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.move< Type* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TYPE_BYTE: // TYPE_BYTE
      case symbol_kind::S_TYPE_INT: // TYPE_INT
      case symbol_kind::S_TYPE_LONG: // TYPE_LONG
      case symbol_kind::S_TYPE_FLOAT: // TYPE_FLOAT
      case symbol_kind::S_TYPE_DOUBLE: // TYPE_DOUBLE
      case symbol_kind::S_TYPE_BOOL: // TYPE_BOOL
      case symbol_kind::S_TYPE_STRING: // TYPE_STRING
      case symbol_kind::S_TYPE_CHAR: // TYPE_CHAR
        value.move< TypeKind > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR: // CHAR
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int32_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LONG: // LONG
        value.move< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_CONST_NAME: // CONST_NAME
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BYTE: // BYTE
        value.move< uint8_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_params_self_list: // params_self_list
      case symbol_kind::S_params_list: // params_list
      case symbol_kind::S_params: // params
      case symbol_kind::S_param: // param
        value.move< vector<Param> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id_list: // id_list
        value.move< vector<string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_range_expr: // range_expr
      case symbol_kind::S_or_expr: // or_expr
      case symbol_kind::S_and_expr: // and_expr
      case symbol_kind::S_bit_or_expr: // bit_or_expr
      case symbol_kind::S_bit_xor_expr: // bit_xor_expr
      case symbol_kind::S_bit_and_expr: // bit_and_expr
      case symbol_kind::S_equals_expr: // equals_expr
      case symbol_kind::S_rel_expr: // rel_expr
      case symbol_kind::S_concat_expr: // concat_expr
      case symbol_kind::S_sum_expr: // sum_expr
      case symbol_kind::S_mult_expr: // mult_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_exp_expr: // exp_expr
      case symbol_kind::S_postfix_expr: // postfix_expr
      case symbol_kind::S_term: // term
        value.copy< ExpressionNode* > (that.value);
        break;

      case symbol_kind::S_fn: // fn
        value.copy< FunctionNode* > (that.value);
        break;

      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_program_slice: // program_slice
      case symbol_kind::S_subprogram: // subprogram
      case symbol_kind::S_subprogram_call: // subprogram_call
      case symbol_kind::S_call_params_list: // call_params_list
      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_enum: // enum
      case symbol_kind::S_enum_values: // enum_values
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_struct_attrs: // struct_attrs
      case symbol_kind::S_struct_attr: // struct_attr
      case symbol_kind::S_trait: // trait
      case symbol_kind::S_trait_subprograms: // trait_subprograms
      case symbol_kind::S_trait_subprogram: // trait_subprogram
      case symbol_kind::S_trait_fn: // trait_fn
      case symbol_kind::S_trait_proc: // trait_proc
      case symbol_kind::S_impl: // impl
      case symbol_kind::S_impl_subprograms: // impl_subprograms
      case symbol_kind::S_impl_subprogram: // impl_subprogram
      case symbol_kind::S_impl_fn: // impl_fn
      case symbol_kind::S_impl_proc: // impl_proc
      case symbol_kind::S_access: // access
      case symbol_kind::S_access_base: // access_base
      case symbol_kind::S_id: // id
      case symbol_kind::S_name: // name
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_return: // return
      case symbol_kind::S_attr: // attr
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_if: // if
      case symbol_kind::S_if_end: // if_end
      case symbol_kind::S_switch: // switch
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_case: // case
      case symbol_kind::S_case_values: // case_values
      case symbol_kind::S_default_case: // default_case
      case symbol_kind::S_for: // for
      case symbol_kind::S_while: // while
      case symbol_kind::S_repeat: // repeat
      case symbol_kind::S_range_interval: // range_interval
      case symbol_kind::S_array_allocation: // array_allocation
      case symbol_kind::S_array_allocation_values: // array_allocation_values
      case symbol_kind::S_struct_allocation: // struct_allocation
      case symbol_kind::S_struct_allocation_values: // struct_allocation_values
        value.copy< Node* > (that.value);
        break;

      case symbol_kind::S_proc: // proc
        value.copy< ProcedureNode* > (that.value);
        break;

      case symbol_kind::S_type: // type
        value.copy< Type* > (that.value);
        break;

      case symbol_kind::S_TYPE_BYTE: // TYPE_BYTE
      case symbol_kind::S_TYPE_INT: // TYPE_INT
      case symbol_kind::S_TYPE_LONG: // TYPE_LONG
      case symbol_kind::S_TYPE_FLOAT: // TYPE_FLOAT
      case symbol_kind::S_TYPE_DOUBLE: // TYPE_DOUBLE
      case symbol_kind::S_TYPE_BOOL: // TYPE_BOOL
      case symbol_kind::S_TYPE_STRING: // TYPE_STRING
      case symbol_kind::S_TYPE_CHAR: // TYPE_CHAR
        value.copy< TypeKind > (that.value);
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_CHAR: // CHAR
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< float > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.copy< int32_t > (that.value);
        break;

      case symbol_kind::S_LONG: // LONG
        value.copy< int64_t > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_CONST_NAME: // CONST_NAME
      case symbol_kind::S_STRING: // STRING
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_BYTE: // BYTE
        value.copy< uint8_t > (that.value);
        break;

      case symbol_kind::S_params_self_list: // params_self_list
      case symbol_kind::S_params_list: // params_list
      case symbol_kind::S_params: // params
      case symbol_kind::S_param: // param
        value.copy< vector<Param> > (that.value);
        break;

      case symbol_kind::S_id_list: // id_list
        value.copy< vector<string> > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_range_expr: // range_expr
      case symbol_kind::S_or_expr: // or_expr
      case symbol_kind::S_and_expr: // and_expr
      case symbol_kind::S_bit_or_expr: // bit_or_expr
      case symbol_kind::S_bit_xor_expr: // bit_xor_expr
      case symbol_kind::S_bit_and_expr: // bit_and_expr
      case symbol_kind::S_equals_expr: // equals_expr
      case symbol_kind::S_rel_expr: // rel_expr
      case symbol_kind::S_concat_expr: // concat_expr
      case symbol_kind::S_sum_expr: // sum_expr
      case symbol_kind::S_mult_expr: // mult_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_exp_expr: // exp_expr
      case symbol_kind::S_postfix_expr: // postfix_expr
      case symbol_kind::S_term: // term
        value.move< ExpressionNode* > (that.value);
        break;

      case symbol_kind::S_fn: // fn
        value.move< FunctionNode* > (that.value);
        break;

      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_program_slice: // program_slice
      case symbol_kind::S_subprogram: // subprogram
      case symbol_kind::S_subprogram_call: // subprogram_call
      case symbol_kind::S_call_params_list: // call_params_list
      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_enum: // enum
      case symbol_kind::S_enum_values: // enum_values
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_struct_attrs: // struct_attrs
      case symbol_kind::S_struct_attr: // struct_attr
      case symbol_kind::S_trait: // trait
      case symbol_kind::S_trait_subprograms: // trait_subprograms
      case symbol_kind::S_trait_subprogram: // trait_subprogram
      case symbol_kind::S_trait_fn: // trait_fn
      case symbol_kind::S_trait_proc: // trait_proc
      case symbol_kind::S_impl: // impl
      case symbol_kind::S_impl_subprograms: // impl_subprograms
      case symbol_kind::S_impl_subprogram: // impl_subprogram
      case symbol_kind::S_impl_fn: // impl_fn
      case symbol_kind::S_impl_proc: // impl_proc
      case symbol_kind::S_access: // access
      case symbol_kind::S_access_base: // access_base
      case symbol_kind::S_id: // id
      case symbol_kind::S_name: // name
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_return: // return
      case symbol_kind::S_attr: // attr
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_if: // if
      case symbol_kind::S_if_end: // if_end
      case symbol_kind::S_switch: // switch
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_case: // case
      case symbol_kind::S_case_values: // case_values
      case symbol_kind::S_default_case: // default_case
      case symbol_kind::S_for: // for
      case symbol_kind::S_while: // while
      case symbol_kind::S_repeat: // repeat
      case symbol_kind::S_range_interval: // range_interval
      case symbol_kind::S_array_allocation: // array_allocation
      case symbol_kind::S_array_allocation_values: // array_allocation_values
      case symbol_kind::S_struct_allocation: // struct_allocation
      case symbol_kind::S_struct_allocation_values: // struct_allocation_values
        value.move< Node* > (that.value);
        break;

      case symbol_kind::S_proc: // proc
        value.move< ProcedureNode* > (that.value);
        break;

      case symbol_kind::S_type: // type
        value.move< Type* > (that.value);
        break;

      case symbol_kind::S_TYPE_BYTE: // TYPE_BYTE
      case symbol_kind::S_TYPE_INT: // TYPE_INT
      case symbol_kind::S_TYPE_LONG: // TYPE_LONG
      case symbol_kind::S_TYPE_FLOAT: // TYPE_FLOAT
      case symbol_kind::S_TYPE_DOUBLE: // TYPE_DOUBLE
      case symbol_kind::S_TYPE_BOOL: // TYPE_BOOL
      case symbol_kind::S_TYPE_STRING: // TYPE_STRING
      case symbol_kind::S_TYPE_CHAR: // TYPE_CHAR
        value.move< TypeKind > (that.value);
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_CHAR: // CHAR
        value.move< char > (that.value);
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.move< double > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< float > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.move< int32_t > (that.value);
        break;

      case symbol_kind::S_LONG: // LONG
        value.move< int64_t > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_CONST_NAME: // CONST_NAME
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_BYTE: // BYTE
        value.move< uint8_t > (that.value);
        break;

      case symbol_kind::S_params_self_list: // params_self_list
      case symbol_kind::S_params_list: // params_list
      case symbol_kind::S_params: // params
      case symbol_kind::S_param: // param
        value.move< vector<Param> > (that.value);
        break;

      case symbol_kind::S_id_list: // id_list
        value.move< vector<string> > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (ctx));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_range_expr: // range_expr
      case symbol_kind::S_or_expr: // or_expr
      case symbol_kind::S_and_expr: // and_expr
      case symbol_kind::S_bit_or_expr: // bit_or_expr
      case symbol_kind::S_bit_xor_expr: // bit_xor_expr
      case symbol_kind::S_bit_and_expr: // bit_and_expr
      case symbol_kind::S_equals_expr: // equals_expr
      case symbol_kind::S_rel_expr: // rel_expr
      case symbol_kind::S_concat_expr: // concat_expr
      case symbol_kind::S_sum_expr: // sum_expr
      case symbol_kind::S_mult_expr: // mult_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_exp_expr: // exp_expr
      case symbol_kind::S_postfix_expr: // postfix_expr
      case symbol_kind::S_term: // term
        yylhs.value.emplace< ExpressionNode* > ();
        break;

      case symbol_kind::S_fn: // fn
        yylhs.value.emplace< FunctionNode* > ();
        break;

      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_program_slice: // program_slice
      case symbol_kind::S_subprogram: // subprogram
      case symbol_kind::S_subprogram_call: // subprogram_call
      case symbol_kind::S_call_params_list: // call_params_list
      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_enum: // enum
      case symbol_kind::S_enum_values: // enum_values
      case symbol_kind::S_struct: // struct
      case symbol_kind::S_struct_attrs: // struct_attrs
      case symbol_kind::S_struct_attr: // struct_attr
      case symbol_kind::S_trait: // trait
      case symbol_kind::S_trait_subprograms: // trait_subprograms
      case symbol_kind::S_trait_subprogram: // trait_subprogram
      case symbol_kind::S_trait_fn: // trait_fn
      case symbol_kind::S_trait_proc: // trait_proc
      case symbol_kind::S_impl: // impl
      case symbol_kind::S_impl_subprograms: // impl_subprograms
      case symbol_kind::S_impl_subprogram: // impl_subprogram
      case symbol_kind::S_impl_fn: // impl_fn
      case symbol_kind::S_impl_proc: // impl_proc
      case symbol_kind::S_access: // access
      case symbol_kind::S_access_base: // access_base
      case symbol_kind::S_id: // id
      case symbol_kind::S_name: // name
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_return: // return
      case symbol_kind::S_attr: // attr
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_if: // if
      case symbol_kind::S_if_end: // if_end
      case symbol_kind::S_switch: // switch
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_case: // case
      case symbol_kind::S_case_values: // case_values
      case symbol_kind::S_default_case: // default_case
      case symbol_kind::S_for: // for
      case symbol_kind::S_while: // while
      case symbol_kind::S_repeat: // repeat
      case symbol_kind::S_range_interval: // range_interval
      case symbol_kind::S_array_allocation: // array_allocation
      case symbol_kind::S_array_allocation_values: // array_allocation_values
      case symbol_kind::S_struct_allocation: // struct_allocation
      case symbol_kind::S_struct_allocation_values: // struct_allocation_values
        yylhs.value.emplace< Node* > ();
        break;

      case symbol_kind::S_proc: // proc
        yylhs.value.emplace< ProcedureNode* > ();
        break;

      case symbol_kind::S_type: // type
        yylhs.value.emplace< Type* > ();
        break;

      case symbol_kind::S_TYPE_BYTE: // TYPE_BYTE
      case symbol_kind::S_TYPE_INT: // TYPE_INT
      case symbol_kind::S_TYPE_LONG: // TYPE_LONG
      case symbol_kind::S_TYPE_FLOAT: // TYPE_FLOAT
      case symbol_kind::S_TYPE_DOUBLE: // TYPE_DOUBLE
      case symbol_kind::S_TYPE_BOOL: // TYPE_BOOL
      case symbol_kind::S_TYPE_STRING: // TYPE_STRING
      case symbol_kind::S_TYPE_CHAR: // TYPE_CHAR
        yylhs.value.emplace< TypeKind > ();
        break;

      case symbol_kind::S_BOOL: // BOOL
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_CHAR: // CHAR
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        yylhs.value.emplace< float > ();
        break;

      case symbol_kind::S_INT: // INT
        yylhs.value.emplace< int32_t > ();
        break;

      case symbol_kind::S_LONG: // LONG
        yylhs.value.emplace< int64_t > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_CONST_NAME: // CONST_NAME
      case symbol_kind::S_STRING: // STRING
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_BYTE: // BYTE
        yylhs.value.emplace< uint8_t > ();
        break;

      case symbol_kind::S_params_self_list: // params_self_list
      case symbol_kind::S_params_list: // params_list
      case symbol_kind::S_params: // params
      case symbol_kind::S_param: // param
        yylhs.value.emplace< vector<Param> > ();
        break;

      case symbol_kind::S_id_list: // id_list
        yylhs.value.emplace< vector<string> > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: program
#line 72 "grammar/syntax.y"
              {
  ctx.root = yystack_[0].value.as < Node* > ();
}
#line 1197 "grammar/build/syntax.tab.cc"
    break;

  case 3: // program: program program_slice
#line 76 "grammar/syntax.y"
                               {
  yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > ();
  yystack_[1].value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
}
#line 1206 "grammar/build/syntax.tab.cc"
    break;

  case 4: // program: program_slice
#line 79 "grammar/syntax.y"
                  {
  yylhs.value.as < Node* > () = new Node(ctx.line, "PROGRAM");
  yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
}
#line 1215 "grammar/build/syntax.tab.cc"
    break;

  case 5: // program_slice: subprogram
#line 84 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1223 "grammar/build/syntax.tab.cc"
    break;

  case 6: // program_slice: enum
#line 86 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1231 "grammar/build/syntax.tab.cc"
    break;

  case 7: // program_slice: struct
#line 88 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1239 "grammar/build/syntax.tab.cc"
    break;

  case 8: // program_slice: trait
#line 90 "grammar/syntax.y"
          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1247 "grammar/build/syntax.tab.cc"
    break;

  case 9: // program_slice: impl
#line 92 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1255 "grammar/build/syntax.tab.cc"
    break;

  case 10: // subprogram: fn
#line 96 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = yystack_[0].value.as < FunctionNode* > ();
}
#line 1263 "grammar/build/syntax.tab.cc"
    break;

  case 11: // subprogram: proc
#line 98 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ProcedureNode* > ();
}
#line 1271 "grammar/build/syntax.tab.cc"
    break;

  case 12: // fn: FUNCTION ID params_list COLON type stmts END_FUNCTION SEMICOLON
#line 102 "grammar/syntax.y"
                                                                    {
  yylhs.value.as < FunctionNode* > () = new FunctionNode(ctx.line, yystack_[6].value.as < std::string > (), *yystack_[3].value.as < Type* > (), yystack_[5].value.as < vector<Param> > ());
}
#line 1279 "grammar/build/syntax.tab.cc"
    break;

  case 13: // proc: PROCEDURE ID params_list stmts END_PROCEDURE SEMICOLON
#line 106 "grammar/syntax.y"
                                                             {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[4].value.as < std::string > (), yystack_[3].value.as < vector<Param> > ());
}
#line 1287 "grammar/build/syntax.tab.cc"
    break;

  case 14: // proc: PROCEDURE ID params_list END_PROCEDURE SEMICOLON
#line 108 "grammar/syntax.y"
                                                     {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[3].value.as < std::string > (), yystack_[2].value.as < vector<Param> > ());
}
#line 1295 "grammar/build/syntax.tab.cc"
    break;

  case 15: // params_self_list: LEFT_PAREN SELF SEMICOLON params RIGHT_PAREN
#line 112 "grammar/syntax.y"
                                                               {
  yylhs.value.as < vector<Param> > () = yystack_[1].value.as < vector<Param> > ();
}
#line 1303 "grammar/build/syntax.tab.cc"
    break;

  case 16: // params_self_list: LEFT_PAREN SELF RIGHT_PAREN
#line 114 "grammar/syntax.y"
                                {
  yylhs.value.as < vector<Param> > () = vector<Param>();
}
#line 1311 "grammar/build/syntax.tab.cc"
    break;

  case 17: // params_list: LEFT_PAREN params RIGHT_PAREN
#line 118 "grammar/syntax.y"
                                           {
  yylhs.value.as < vector<Param> > () = yystack_[1].value.as < vector<Param> > ();
}
#line 1319 "grammar/build/syntax.tab.cc"
    break;

  case 18: // params_list: LEFT_PAREN RIGHT_PAREN
#line 120 "grammar/syntax.y"
                           {
  yylhs.value.as < vector<Param> > () = vector<Param>();
}
#line 1327 "grammar/build/syntax.tab.cc"
    break;

  case 19: // params: params SEMICOLON param
#line 124 "grammar/syntax.y"
                               {
  yylhs.value.as < vector<Param> > () = yystack_[2].value.as < vector<Param> > ();
  for (size_t i = 0; i < yystack_[0].value.as < vector<Param> > ().size(); i++) {
    yylhs.value.as < vector<Param> > ().push_back(yystack_[0].value.as < vector<Param> > ()[i]);
  };
}
#line 1338 "grammar/build/syntax.tab.cc"
    break;

  case 20: // params: param
#line 129 "grammar/syntax.y"
          {
  yylhs.value.as < vector<Param> > () = vector<Param>();
  for (size_t i = 0; i < yystack_[0].value.as < vector<Param> > ().size(); i++) {
    yylhs.value.as < vector<Param> > ().push_back(yystack_[0].value.as < vector<Param> > ()[i]);
  };
}
#line 1349 "grammar/build/syntax.tab.cc"
    break;

  case 21: // param: id_list COLON type
#line 136 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<Param> > () = vector<Param>();
  for (size_t i = 0; i < yystack_[2].value.as < vector<string> > ().size(); i++) {
    yylhs.value.as < vector<Param> > ().push_back({yystack_[2].value.as < vector<string> > ()[i], *yystack_[0].value.as < Type* > ()});
  };
}
#line 1360 "grammar/build/syntax.tab.cc"
    break;

  case 22: // id_list: id_list COMMA ID
#line 143 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<string> > () = yystack_[2].value.as < vector<string> > ();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < std::string > ());
}
#line 1369 "grammar/build/syntax.tab.cc"
    break;

  case 23: // id_list: ID
#line 146 "grammar/syntax.y"
       {
  yylhs.value.as < vector<string> > () = vector<string>();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < std::string > ());
}
#line 1378 "grammar/build/syntax.tab.cc"
    break;

  case 24: // subprogram_call: access call_params_list
#line 151 "grammar/syntax.y"
                                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1386 "grammar/build/syntax.tab.cc"
    break;

  case 25: // call_params_list: LEFT_PAREN call_params RIGHT_PAREN
#line 155 "grammar/syntax.y"
                                                     {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1394 "grammar/build/syntax.tab.cc"
    break;

  case 26: // call_params_list: LEFT_PAREN RIGHT_PAREN
#line 157 "grammar/syntax.y"
                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1402 "grammar/build/syntax.tab.cc"
    break;

  case 27: // call_params: call_params COMMA expr
#line 161 "grammar/syntax.y"
                                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1410 "grammar/build/syntax.tab.cc"
    break;

  case 28: // call_params: expr
#line 163 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1418 "grammar/build/syntax.tab.cc"
    break;

  case 29: // enum: ENUM name enum_values END_ENUM SEMICOLON
#line 167 "grammar/syntax.y"
                                               {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1426 "grammar/build/syntax.tab.cc"
    break;

  case 30: // enum: ENUM name END_ENUM SEMICOLON
#line 169 "grammar/syntax.y"
                                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1434 "grammar/build/syntax.tab.cc"
    break;

  case 31: // enum_values: enum_values COMMA CONST_NAME
#line 173 "grammar/syntax.y"
                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1442 "grammar/build/syntax.tab.cc"
    break;

  case 32: // enum_values: CONST_NAME
#line 175 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1450 "grammar/build/syntax.tab.cc"
    break;

  case 33: // struct: STRUCT name struct_attrs END_STRUCT SEMICOLON
#line 179 "grammar/syntax.y"
                                                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1458 "grammar/build/syntax.tab.cc"
    break;

  case 34: // struct: STRUCT name END_STRUCT SEMICOLON
#line 181 "grammar/syntax.y"
                                     {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1466 "grammar/build/syntax.tab.cc"
    break;

  case 35: // struct_attrs: struct_attrs struct_attr SEMICOLON
#line 185 "grammar/syntax.y"
                                                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1474 "grammar/build/syntax.tab.cc"
    break;

  case 36: // struct_attrs: struct_attr SEMICOLON
#line 187 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1482 "grammar/build/syntax.tab.cc"
    break;

  case 37: // struct_attr: id_list COLON type
#line 191 "grammar/syntax.y"
                                {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1490 "grammar/build/syntax.tab.cc"
    break;

  case 38: // trait: TRAIT name trait_subprograms END_TRAIT SEMICOLON
#line 195 "grammar/syntax.y"
                                                        {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1498 "grammar/build/syntax.tab.cc"
    break;

  case 39: // trait: TRAIT name END_TRAIT SEMICOLON
#line 197 "grammar/syntax.y"
                                   {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1506 "grammar/build/syntax.tab.cc"
    break;

  case 40: // trait_subprograms: trait_subprograms trait_subprogram
#line 201 "grammar/syntax.y"
                                                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1514 "grammar/build/syntax.tab.cc"
    break;

  case 41: // trait_subprograms: trait_subprogram
#line 203 "grammar/syntax.y"
                     {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1522 "grammar/build/syntax.tab.cc"
    break;

  case 42: // trait_subprogram: trait_fn
#line 207 "grammar/syntax.y"
                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1530 "grammar/build/syntax.tab.cc"
    break;

  case 43: // trait_subprogram: trait_proc
#line 209 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1538 "grammar/build/syntax.tab.cc"
    break;

  case 44: // trait_fn: FUNCTION ID params_self_list COLON type END_FUNCTION SEMICOLON
#line 213 "grammar/syntax.y"
                                                                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1546 "grammar/build/syntax.tab.cc"
    break;

  case 45: // trait_fn: FUNCTION ID params_list COLON type END_FUNCTION SEMICOLON
#line 215 "grammar/syntax.y"
                                                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1554 "grammar/build/syntax.tab.cc"
    break;

  case 46: // trait_fn: fn
#line 217 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1562 "grammar/build/syntax.tab.cc"
    break;

  case 47: // trait_proc: PROCEDURE ID params_self_list END_PROCEDURE SEMICOLON
#line 221 "grammar/syntax.y"
                                                                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1570 "grammar/build/syntax.tab.cc"
    break;

  case 48: // trait_proc: proc
#line 223 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1578 "grammar/build/syntax.tab.cc"
    break;

  case 49: // impl: IMPL name impl_subprograms END_IMPL SEMICOLON
#line 227 "grammar/syntax.y"
                                                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1586 "grammar/build/syntax.tab.cc"
    break;

  case 50: // impl: IMPL name END_IMPL SEMICOLON
#line 229 "grammar/syntax.y"
                                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1594 "grammar/build/syntax.tab.cc"
    break;

  case 51: // impl: IMPL name impl_subprograms FOR name END_IMPL SEMICOLON
#line 231 "grammar/syntax.y"
                                                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1602 "grammar/build/syntax.tab.cc"
    break;

  case 52: // impl: IMPL name FOR name END_IMPL SEMICOLON
#line 233 "grammar/syntax.y"
                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1610 "grammar/build/syntax.tab.cc"
    break;

  case 53: // impl_subprograms: impl_subprograms impl_subprogram
#line 237 "grammar/syntax.y"
                                                   {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1618 "grammar/build/syntax.tab.cc"
    break;

  case 54: // impl_subprograms: impl_subprogram
#line 239 "grammar/syntax.y"
                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1626 "grammar/build/syntax.tab.cc"
    break;

  case 55: // impl_subprogram: impl_fn
#line 243 "grammar/syntax.y"
                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1634 "grammar/build/syntax.tab.cc"
    break;

  case 56: // impl_subprogram: impl_proc
#line 245 "grammar/syntax.y"
              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1642 "grammar/build/syntax.tab.cc"
    break;

  case 57: // impl_fn: FUNCTION ID params_self_list COLON type stmts END_FUNCTION SEMICOLON
#line 249 "grammar/syntax.y"
                                                                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1650 "grammar/build/syntax.tab.cc"
    break;

  case 58: // impl_fn: fn
#line 251 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1658 "grammar/build/syntax.tab.cc"
    break;

  case 59: // impl_proc: PROCEDURE ID params_self_list stmts END_PROCEDURE SEMICOLON
#line 255 "grammar/syntax.y"
                                                                       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1666 "grammar/build/syntax.tab.cc"
    break;

  case 60: // impl_proc: PROCEDURE ID params_self_list END_PROCEDURE SEMICOLON
#line 257 "grammar/syntax.y"
                                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1674 "grammar/build/syntax.tab.cc"
    break;

  case 61: // impl_proc: proc
#line 259 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1682 "grammar/build/syntax.tab.cc"
    break;

  case 62: // access: access DOT CONST_NAME
#line 263 "grammar/syntax.y"
                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1690 "grammar/build/syntax.tab.cc"
    break;

  case 63: // access: access DOT ID
#line 265 "grammar/syntax.y"
                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1698 "grammar/build/syntax.tab.cc"
    break;

  case 64: // access: access LEFT_BRACKET expr RIGHT_BRACKET
#line 267 "grammar/syntax.y"
                                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1706 "grammar/build/syntax.tab.cc"
    break;

  case 65: // access: access DOUBLE_COLON ID
#line 269 "grammar/syntax.y"
                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1714 "grammar/build/syntax.tab.cc"
    break;

  case 66: // access: subprogram_call
#line 271 "grammar/syntax.y"
                    {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1722 "grammar/build/syntax.tab.cc"
    break;

  case 67: // access: access_base
#line 273 "grammar/syntax.y"
                {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1730 "grammar/build/syntax.tab.cc"
    break;

  case 68: // access_base: SELF
#line 277 "grammar/syntax.y"
                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1738 "grammar/build/syntax.tab.cc"
    break;

  case 69: // access_base: id
#line 279 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1746 "grammar/build/syntax.tab.cc"
    break;

  case 70: // access_base: LEFT_PAREN expr RIGHT_PAREN
#line 281 "grammar/syntax.y"
                                {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1754 "grammar/build/syntax.tab.cc"
    break;

  case 71: // id: NAME
#line 285 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1762 "grammar/build/syntax.tab.cc"
    break;

  case 72: // id: ID
#line 287 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1770 "grammar/build/syntax.tab.cc"
    break;

  case 73: // name: NAME
#line 291 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1778 "grammar/build/syntax.tab.cc"
    break;

  case 74: // name: CONST_NAME
#line 293 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1786 "grammar/build/syntax.tab.cc"
    break;

  case 75: // stmts: stmts stmt SEMICOLON
#line 297 "grammar/syntax.y"
                            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1794 "grammar/build/syntax.tab.cc"
    break;

  case 76: // stmts: stmt SEMICOLON
#line 299 "grammar/syntax.y"
                   {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1802 "grammar/build/syntax.tab.cc"
    break;

  case 77: // stmt: BREAK
#line 303 "grammar/syntax.y"
            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1810 "grammar/build/syntax.tab.cc"
    break;

  case 78: // stmt: CONTINUE
#line 305 "grammar/syntax.y"
             {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1818 "grammar/build/syntax.tab.cc"
    break;

  case 79: // stmt: attr
#line 307 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1826 "grammar/build/syntax.tab.cc"
    break;

  case 80: // stmt: assign
#line 309 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1834 "grammar/build/syntax.tab.cc"
    break;

  case 81: // stmt: return
#line 311 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1842 "grammar/build/syntax.tab.cc"
    break;

  case 82: // stmt: if
#line 313 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1850 "grammar/build/syntax.tab.cc"
    break;

  case 83: // stmt: for
#line 315 "grammar/syntax.y"
        {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1858 "grammar/build/syntax.tab.cc"
    break;

  case 84: // stmt: while
#line 317 "grammar/syntax.y"
          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1866 "grammar/build/syntax.tab.cc"
    break;

  case 85: // stmt: repeat
#line 319 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1874 "grammar/build/syntax.tab.cc"
    break;

  case 86: // stmt: switch
#line 321 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1882 "grammar/build/syntax.tab.cc"
    break;

  case 87: // stmt: expr
#line 323 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1890 "grammar/build/syntax.tab.cc"
    break;

  case 88: // return: RETURN expr
#line 327 "grammar/syntax.y"
                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1898 "grammar/build/syntax.tab.cc"
    break;

  case 89: // attr: VAR ID COLON type ATTR expr
#line 331 "grammar/syntax.y"
                                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1906 "grammar/build/syntax.tab.cc"
    break;

  case 90: // attr: CONST ID COLON type ATTR expr
#line 333 "grammar/syntax.y"
                                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1914 "grammar/build/syntax.tab.cc"
    break;

  case 91: // type: TYPE_INT
#line 337 "grammar/syntax.y"
               {
  yylhs.value.as < Type* > () = new Type(TypeKind::INT);
}
#line 1922 "grammar/build/syntax.tab.cc"
    break;

  case 92: // type: TYPE_FLOAT
#line 339 "grammar/syntax.y"
               {
  yylhs.value.as < Type* > () = new Type(TypeKind::FLOAT);
}
#line 1930 "grammar/build/syntax.tab.cc"
    break;

  case 93: // type: TYPE_DOUBLE
#line 341 "grammar/syntax.y"
                {
  yylhs.value.as < Type* > () = new Type(TypeKind::DOUBLE);
}
#line 1938 "grammar/build/syntax.tab.cc"
    break;

  case 94: // type: TYPE_LONG
#line 343 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::LONG);
}
#line 1946 "grammar/build/syntax.tab.cc"
    break;

  case 95: // type: TYPE_BYTE
#line 345 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::BYTE);
}
#line 1954 "grammar/build/syntax.tab.cc"
    break;

  case 96: // type: TYPE_STRING
#line 347 "grammar/syntax.y"
                {
  yylhs.value.as < Type* > () = new Type(TypeKind::STRING);
}
#line 1962 "grammar/build/syntax.tab.cc"
    break;

  case 97: // type: TYPE_CHAR
#line 349 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::CHAR);
}
#line 1970 "grammar/build/syntax.tab.cc"
    break;

  case 98: // type: TYPE_BOOL
#line 351 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::BOOL);
}
#line 1978 "grammar/build/syntax.tab.cc"
    break;

  case 99: // type: type LEFT_BRACKET RIGHT_BRACKET
#line 353 "grammar/syntax.y"
                                    {
  yylhs.value.as < Type* > () = new Type(TypeKind::ARRAY, yystack_[2].value.as < Type* > ());
}
#line 1986 "grammar/build/syntax.tab.cc"
    break;

  case 100: // type: TYPE_POINTER LT type GT
#line 355 "grammar/syntax.y"
                            {
  yylhs.value.as < Type* > () = new Type(TypeKind::POINTER, yystack_[1].value.as < Type* > ());
}
#line 1994 "grammar/build/syntax.tab.cc"
    break;

  case 101: // type: TYPE_OPTION LT type GT
#line 357 "grammar/syntax.y"
                           {
  yylhs.value.as < Type* > () = new Type(TypeKind::OPTION, yystack_[1].value.as < Type* > ());
}
#line 2002 "grammar/build/syntax.tab.cc"
    break;

  case 102: // assign: access ATTR expr
#line 361 "grammar/syntax.y"
                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2010 "grammar/build/syntax.tab.cc"
    break;

  case 103: // assign: access AND_ATTR expr
#line 363 "grammar/syntax.y"
                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2018 "grammar/build/syntax.tab.cc"
    break;

  case 104: // assign: access OR_ATTR expr
#line 365 "grammar/syntax.y"
                        {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2026 "grammar/build/syntax.tab.cc"
    break;

  case 105: // assign: access LAZY_AND_ATTR expr
#line 367 "grammar/syntax.y"
                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2034 "grammar/build/syntax.tab.cc"
    break;

  case 106: // assign: access LAZY_OR_ATTR expr
#line 369 "grammar/syntax.y"
                             {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2042 "grammar/build/syntax.tab.cc"
    break;

  case 107: // assign: access XOR_ATTR expr
#line 371 "grammar/syntax.y"
                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2050 "grammar/build/syntax.tab.cc"
    break;

  case 108: // assign: access CONCAT_ATTR expr
#line 373 "grammar/syntax.y"
                            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2058 "grammar/build/syntax.tab.cc"
    break;

  case 109: // assign: access MOD_ATTR expr
#line 375 "grammar/syntax.y"
                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2066 "grammar/build/syntax.tab.cc"
    break;

  case 110: // assign: access PLUS_ATTR expr
#line 377 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2074 "grammar/build/syntax.tab.cc"
    break;

  case 111: // assign: access MINUS_ATTR expr
#line 379 "grammar/syntax.y"
                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2082 "grammar/build/syntax.tab.cc"
    break;

  case 112: // assign: access MULT_ATTR expr
#line 381 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2090 "grammar/build/syntax.tab.cc"
    break;

  case 113: // assign: access DIV_ATTR expr
#line 383 "grammar/syntax.y"
                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2098 "grammar/build/syntax.tab.cc"
    break;

  case 114: // if: IF expr THEN stmts if_end
#line 387 "grammar/syntax.y"
                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2106 "grammar/build/syntax.tab.cc"
    break;

  case 115: // if: IF SOME ID IN access THEN stmts if_end
#line 389 "grammar/syntax.y"
                                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2114 "grammar/build/syntax.tab.cc"
    break;

  case 116: // if_end: ELIF expr THEN stmts if_end
#line 393 "grammar/syntax.y"
                                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2122 "grammar/build/syntax.tab.cc"
    break;

  case 117: // if_end: ELIF SOME ID IN access THEN stmts if_end
#line 395 "grammar/syntax.y"
                                             {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2130 "grammar/build/syntax.tab.cc"
    break;

  case 118: // if_end: ELIF SOME IN access THEN stmts if_end
#line 397 "grammar/syntax.y"
                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2138 "grammar/build/syntax.tab.cc"
    break;

  case 119: // if_end: ELSE stmts END_IF
#line 399 "grammar/syntax.y"
                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2146 "grammar/build/syntax.tab.cc"
    break;

  case 120: // if_end: END_IF
#line 401 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2154 "grammar/build/syntax.tab.cc"
    break;

  case 121: // switch: SWITCH expr cases END_SWITCH
#line 405 "grammar/syntax.y"
                                     {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2162 "grammar/build/syntax.tab.cc"
    break;

  case 122: // cases: case_list default_case
#line 409 "grammar/syntax.y"
                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2170 "grammar/build/syntax.tab.cc"
    break;

  case 123: // cases: case_list
#line 411 "grammar/syntax.y"
              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2178 "grammar/build/syntax.tab.cc"
    break;

  case 124: // cases: default_case
#line 413 "grammar/syntax.y"
                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2186 "grammar/build/syntax.tab.cc"
    break;

  case 125: // case_list: case_list case
#line 417 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2194 "grammar/build/syntax.tab.cc"
    break;

  case 126: // case_list: case
#line 419 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2202 "grammar/build/syntax.tab.cc"
    break;

  case 127: // case: CASE case_values COLON stmts
#line 423 "grammar/syntax.y"
                                   {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2210 "grammar/build/syntax.tab.cc"
    break;

  case 128: // case: CASE SOME ID COLON stmts
#line 425 "grammar/syntax.y"
                             {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2218 "grammar/build/syntax.tab.cc"
    break;

  case 129: // case: CASE NONE COLON stmts
#line 427 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2226 "grammar/build/syntax.tab.cc"
    break;

  case 130: // case_values: case_values COMMA access
#line 431 "grammar/syntax.y"
                                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2234 "grammar/build/syntax.tab.cc"
    break;

  case 131: // case_values: access
#line 433 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2242 "grammar/build/syntax.tab.cc"
    break;

  case 132: // default_case: DEFAULT COLON stmts
#line 437 "grammar/syntax.y"
                                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2250 "grammar/build/syntax.tab.cc"
    break;

  case 133: // for: FOR LEFT_PAREN ID IN expr RIGHT_PAREN stmts END_FOR
#line 441 "grammar/syntax.y"
                                                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2258 "grammar/build/syntax.tab.cc"
    break;

  case 134: // for: FOR LEFT_PAREN ID IN expr RIGHT_PAREN END_FOR
#line 443 "grammar/syntax.y"
                                                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2266 "grammar/build/syntax.tab.cc"
    break;

  case 135: // for: FOR LEFT_PAREN attr SEMICOLON expr SEMICOLON expr RIGHT_PAREN stmts END_FOR
#line 445 "grammar/syntax.y"
                                                                                {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2274 "grammar/build/syntax.tab.cc"
    break;

  case 136: // for: FOR LEFT_PAREN attr SEMICOLON expr SEMICOLON expr RIGHT_PAREN END_FOR
#line 447 "grammar/syntax.y"
                                                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2282 "grammar/build/syntax.tab.cc"
    break;

  case 137: // while: WHILE LEFT_PAREN expr RIGHT_PAREN stmts END_WHILE
#line 451 "grammar/syntax.y"
                                                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2290 "grammar/build/syntax.tab.cc"
    break;

  case 138: // while: WHILE LEFT_PAREN expr RIGHT_PAREN END_WHILE
#line 453 "grammar/syntax.y"
                                                {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2298 "grammar/build/syntax.tab.cc"
    break;

  case 139: // repeat: REPEAT stmts UNTIL expr
#line 457 "grammar/syntax.y"
                                {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2306 "grammar/build/syntax.tab.cc"
    break;

  case 140: // repeat: REPEAT UNTIL expr
#line 459 "grammar/syntax.y"
                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2314 "grammar/build/syntax.tab.cc"
    break;

  case 141: // expr: or_expr
#line 463 "grammar/syntax.y"
              {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2322 "grammar/build/syntax.tab.cc"
    break;

  case 142: // expr: range_expr
#line 465 "grammar/syntax.y"
               {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2330 "grammar/build/syntax.tab.cc"
    break;

  case 143: // range_expr: range_interval or_expr
#line 469 "grammar/syntax.y"
                                   {
  yylhs.value.as < ExpressionNode* > () = nullptr;
}
#line 2338 "grammar/build/syntax.tab.cc"
    break;

  case 144: // range_expr: or_expr range_interval
#line 471 "grammar/syntax.y"
                           {
  yylhs.value.as < ExpressionNode* > () = nullptr;
}
#line 2346 "grammar/build/syntax.tab.cc"
    break;

  case 145: // range_expr: or_expr range_interval or_expr
#line 473 "grammar/syntax.y"
                                   {
  yylhs.value.as < ExpressionNode* > () = nullptr;
}
#line 2354 "grammar/build/syntax.tab.cc"
    break;

  case 146: // range_interval: RANGE
#line 477 "grammar/syntax.y"
                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2362 "grammar/build/syntax.tab.cc"
    break;

  case 147: // range_interval: RANGE_EXC
#line 479 "grammar/syntax.y"
              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2370 "grammar/build/syntax.tab.cc"
    break;

  case 148: // range_interval: RANGE_EXC_INC
#line 481 "grammar/syntax.y"
                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2378 "grammar/build/syntax.tab.cc"
    break;

  case 149: // range_interval: RANGE_INC
#line 483 "grammar/syntax.y"
              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2386 "grammar/build/syntax.tab.cc"
    break;

  case 150: // or_expr: or_expr OR and_expr
#line 487 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::OR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2394 "grammar/build/syntax.tab.cc"
    break;

  case 151: // or_expr: and_expr
#line 489 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2402 "grammar/build/syntax.tab.cc"
    break;

  case 152: // and_expr: and_expr AND bit_or_expr
#line 493 "grammar/syntax.y"
                                   {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::AND, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2410 "grammar/build/syntax.tab.cc"
    break;

  case 153: // and_expr: bit_or_expr
#line 495 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2418 "grammar/build/syntax.tab.cc"
    break;

  case 154: // bit_or_expr: bit_or_expr BAR bit_xor_expr
#line 499 "grammar/syntax.y"
                                          {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::BITWISE_OR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2426 "grammar/build/syntax.tab.cc"
    break;

  case 155: // bit_or_expr: bit_xor_expr
#line 501 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2434 "grammar/build/syntax.tab.cc"
    break;

  case 156: // bit_xor_expr: bit_xor_expr XOR bit_and_expr
#line 505 "grammar/syntax.y"
                                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::XOR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2442 "grammar/build/syntax.tab.cc"
    break;

  case 157: // bit_xor_expr: bit_and_expr
#line 507 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2450 "grammar/build/syntax.tab.cc"
    break;

  case 158: // bit_and_expr: bit_and_expr REF equals_expr
#line 511 "grammar/syntax.y"
                                           {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::BITWISE_AND, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2458 "grammar/build/syntax.tab.cc"
    break;

  case 159: // bit_and_expr: equals_expr
#line 513 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2466 "grammar/build/syntax.tab.cc"
    break;

  case 160: // equals_expr: equals_expr EQ rel_expr
#line 517 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2474 "grammar/build/syntax.tab.cc"
    break;

  case 161: // equals_expr: equals_expr NOT_EQ rel_expr
#line 519 "grammar/syntax.y"
                                {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::NOT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2482 "grammar/build/syntax.tab.cc"
    break;

  case 162: // equals_expr: rel_expr
#line 521 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2490 "grammar/build/syntax.tab.cc"
    break;

  case 163: // rel_expr: rel_expr LT concat_expr
#line 525 "grammar/syntax.y"
                                  {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::LT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2498 "grammar/build/syntax.tab.cc"
    break;

  case 164: // rel_expr: rel_expr GT concat_expr
#line 527 "grammar/syntax.y"
                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::GT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2506 "grammar/build/syntax.tab.cc"
    break;

  case 165: // rel_expr: rel_expr LT_EQ concat_expr
#line 529 "grammar/syntax.y"
                               {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::LT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2514 "grammar/build/syntax.tab.cc"
    break;

  case 166: // rel_expr: rel_expr GT_EQ concat_expr
#line 531 "grammar/syntax.y"
                               {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::GT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2522 "grammar/build/syntax.tab.cc"
    break;

  case 167: // rel_expr: rel_expr IN concat_expr
#line 533 "grammar/syntax.y"
                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::IN, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2530 "grammar/build/syntax.tab.cc"
    break;

  case 168: // rel_expr: concat_expr
#line 535 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2538 "grammar/build/syntax.tab.cc"
    break;

  case 169: // concat_expr: concat_expr CONCAT sum_expr
#line 539 "grammar/syntax.y"
                                         {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::CONCAT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2546 "grammar/build/syntax.tab.cc"
    break;

  case 170: // concat_expr: sum_expr
#line 541 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2554 "grammar/build/syntax.tab.cc"
    break;

  case 171: // sum_expr: sum_expr PLUS mult_expr
#line 545 "grammar/syntax.y"
                                  {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::PLUS, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2562 "grammar/build/syntax.tab.cc"
    break;

  case 172: // sum_expr: sum_expr MINUS mult_expr
#line 547 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MINUS, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2570 "grammar/build/syntax.tab.cc"
    break;

  case 173: // sum_expr: mult_expr
#line 549 "grammar/syntax.y"
              {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2578 "grammar/build/syntax.tab.cc"
    break;

  case 174: // mult_expr: mult_expr MULT unary_expr
#line 553 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MULT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2586 "grammar/build/syntax.tab.cc"
    break;

  case 175: // mult_expr: mult_expr DIV unary_expr
#line 555 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::DIV, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2594 "grammar/build/syntax.tab.cc"
    break;

  case 176: // mult_expr: mult_expr MOD unary_expr
#line 557 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MOD, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2602 "grammar/build/syntax.tab.cc"
    break;

  case 177: // mult_expr: unary_expr
#line 559 "grammar/syntax.y"
               {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2610 "grammar/build/syntax.tab.cc"
    break;

  case 178: // unary_expr: MINUS exp_expr
#line 563 "grammar/syntax.y"
                           {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::MINUS, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2618 "grammar/build/syntax.tab.cc"
    break;

  case 179: // unary_expr: REV exp_expr
#line 565 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::REV, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2626 "grammar/build/syntax.tab.cc"
    break;

  case 180: // unary_expr: NOT exp_expr
#line 567 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::NOT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2634 "grammar/build/syntax.tab.cc"
    break;

  case 181: // unary_expr: REF exp_expr
#line 569 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::REF, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2642 "grammar/build/syntax.tab.cc"
    break;

  case 182: // unary_expr: INCREMENT exp_expr
#line 571 "grammar/syntax.y"
                       {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::INCREMENT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2650 "grammar/build/syntax.tab.cc"
    break;

  case 183: // unary_expr: DECREMENT exp_expr
#line 573 "grammar/syntax.y"
                       {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::DECREMENT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2658 "grammar/build/syntax.tab.cc"
    break;

  case 184: // unary_expr: MULT exp_expr
#line 575 "grammar/syntax.y"
                  {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2666 "grammar/build/syntax.tab.cc"
    break;

  case 185: // unary_expr: exp_expr
#line 577 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2674 "grammar/build/syntax.tab.cc"
    break;

  case 186: // exp_expr: postfix_expr EXP exp_expr
#line 581 "grammar/syntax.y"
                                    {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::EXP, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2682 "grammar/build/syntax.tab.cc"
    break;

  case 187: // exp_expr: postfix_expr
#line 583 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2690 "grammar/build/syntax.tab.cc"
    break;

  case 188: // postfix_expr: term INCREMENT
#line 587 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(true, UnaryOperation::INCREMENT, yystack_[1].value.as < ExpressionNode* > ());
}
#line 2698 "grammar/build/syntax.tab.cc"
    break;

  case 189: // postfix_expr: term DECREMENT
#line 589 "grammar/syntax.y"
                   {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(true, UnaryOperation::DECREMENT, yystack_[1].value.as < ExpressionNode* > ());
}
#line 2706 "grammar/build/syntax.tab.cc"
    break;

  case 190: // postfix_expr: term
#line 591 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2714 "grammar/build/syntax.tab.cc"
    break;

  case 191: // term: INT
#line 595 "grammar/syntax.y"
          {
  yylhs.value.as < ExpressionNode* > () = new IntNode(ctx.line, yystack_[0].value.as < int32_t > ());
}
#line 2722 "grammar/build/syntax.tab.cc"
    break;

  case 192: // term: LONG
#line 597 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new LongNode(ctx.line, yystack_[0].value.as < int64_t > ());
}
#line 2730 "grammar/build/syntax.tab.cc"
    break;

  case 193: // term: FLOAT
#line 599 "grammar/syntax.y"
          {
  yylhs.value.as < ExpressionNode* > () = new FloatNode(ctx.line, yystack_[0].value.as < float > ());
}
#line 2738 "grammar/build/syntax.tab.cc"
    break;

  case 194: // term: DOUBLE
#line 601 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = new DoubleNode(ctx.line, yystack_[0].value.as < double > ());
}
#line 2746 "grammar/build/syntax.tab.cc"
    break;

  case 195: // term: BYTE
#line 603 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new ByteNode(ctx.line, yystack_[0].value.as < uint8_t > ());
}
#line 2754 "grammar/build/syntax.tab.cc"
    break;

  case 196: // term: BOOL
#line 605 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new BoolNode(ctx.line, yystack_[0].value.as < bool > ());
}
#line 2762 "grammar/build/syntax.tab.cc"
    break;

  case 197: // term: STRING
#line 607 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = new StringNode(ctx.line, yystack_[0].value.as < std::string > ());
}
#line 2770 "grammar/build/syntax.tab.cc"
    break;

  case 198: // term: CHAR
#line 609 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new CharNode(ctx.line, yystack_[0].value.as < char > ());
}
#line 2778 "grammar/build/syntax.tab.cc"
    break;

  case 199: // term: NONE
#line 611 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new OptionNode(ctx.line, Option());
}
#line 2786 "grammar/build/syntax.tab.cc"
    break;

  case 200: // term: array_allocation
#line 613 "grammar/syntax.y"
                     {
  yylhs.value.as < ExpressionNode* > () = nullptr;
}
#line 2794 "grammar/build/syntax.tab.cc"
    break;

  case 201: // term: struct_allocation
#line 615 "grammar/syntax.y"
                      {
  yylhs.value.as < ExpressionNode* > () = nullptr;
}
#line 2802 "grammar/build/syntax.tab.cc"
    break;

  case 202: // term: access
#line 617 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = nullptr;
}
#line 2810 "grammar/build/syntax.tab.cc"
    break;

  case 203: // term: SOME LEFT_PAREN expr RIGHT_PAREN
#line 619 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new OptionNode(ctx.line, Option());
}
#line 2818 "grammar/build/syntax.tab.cc"
    break;

  case 204: // array_allocation: NEW type LEFT_BRACKET expr RIGHT_BRACKET
#line 623 "grammar/syntax.y"
                                                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2826 "grammar/build/syntax.tab.cc"
    break;

  case 205: // array_allocation: NEW type LEFT_BRACKET expr RIGHT_BRACKET LEFT_BRACE array_allocation_values RIGHT_BRACE
#line 625 "grammar/syntax.y"
                                                                                            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2834 "grammar/build/syntax.tab.cc"
    break;

  case 206: // array_allocation_values: array_allocation_values COMMA expr
#line 629 "grammar/syntax.y"
                                                            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2842 "grammar/build/syntax.tab.cc"
    break;

  case 207: // array_allocation_values: expr
#line 631 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2850 "grammar/build/syntax.tab.cc"
    break;

  case 208: // struct_allocation: NEW type LEFT_BRACE struct_allocation_values RIGHT_BRACE
#line 635 "grammar/syntax.y"
                                                                            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2858 "grammar/build/syntax.tab.cc"
    break;

  case 209: // struct_allocation: NEW type LEFT_BRACE RIGHT_BRACE
#line 637 "grammar/syntax.y"
                                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2866 "grammar/build/syntax.tab.cc"
    break;

  case 210: // struct_allocation_values: struct_allocation_values COMMA ID COLON expr
#line 641 "grammar/syntax.y"
                                                                       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2874 "grammar/build/syntax.tab.cc"
    break;

  case 211: // struct_allocation_values: ID COLON expr
#line 643 "grammar/syntax.y"
                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2882 "grammar/build/syntax.tab.cc"
    break;


#line 2886 "grammar/build/syntax.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        report_syntax_error (yyctx);
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "BYTE", "INT", "LONG", "FLOAT",
  "DOUBLE", "BOOL", "ID", "NAME", "CONST_NAME", "STRING", "CHAR",
  "TYPE_BYTE", "TYPE_INT", "TYPE_LONG", "TYPE_FLOAT", "TYPE_DOUBLE",
  "TYPE_BOOL", "TYPE_STRING", "TYPE_CHAR", "TYPE_POINTER", "TYPE_OPTION",
  "DECREMENT", "INCREMENT", "EXP", "EQ", "AND_ATTR", "OR_ATTR", "CONCAT",
  "LAZY_AND_ATTR", "LAZY_OR_ATTR", "MOD_ATTR", "XOR_ATTR", "PLUS_ATTR",
  "CONCAT_ATTR", "MINUS_ATTR", "MULT_ATTR", "DIV_ATTR", "AND", "OR", "REF",
  "BAR", "NOT_EQ", "LT_EQ", "GT_EQ", "LT", "GT", "NOT", "REV", "MOD",
  "XOR", "ATTR", "MINUS", "PLUS", "MULT", "DIV", "NEW", "VAR", "CONST",
  "RANGE", "RANGE_INC", "RANGE_EXC", "RANGE_EXC_INC", "DOT", "COMMA",
  "COLON", "DOUBLE_COLON", "SEMICOLON", "LEFT_PAREN", "RIGHT_PAREN",
  "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_BRACE", "RIGHT_BRACE", "IF",
  "END_IF", "THEN", "ELIF", "ELSE", "FOR", "WHILE", "END_WHILE", "REPEAT",
  "UNTIL", "END_FOR", "BREAK", "CONTINUE", "SWITCH", "CASE", "DEFAULT",
  "END_SWITCH", "IN", "SOME", "NONE", "FUNCTION", "END_FUNCTION",
  "PROCEDURE", "END_PROCEDURE", "ENUM", "END_ENUM", "STRUCT", "END_STRUCT",
  "SELF", "IMPL", "END_IMPL", "TRAIT", "END_TRAIT", "RETURN", "DO",
  "$accept", "root", "program", "program_slice", "subprogram", "fn",
  "proc", "params_self_list", "params_list", "params", "param", "id_list",
  "subprogram_call", "call_params_list", "call_params", "enum",
  "enum_values", "struct", "struct_attrs", "struct_attr", "trait",
  "trait_subprograms", "trait_subprogram", "trait_fn", "trait_proc",
  "impl", "impl_subprograms", "impl_subprogram", "impl_fn", "impl_proc",
  "access", "access_base", "id", "name", "stmts", "stmt", "return", "attr",
  "type", "assign", "if", "if_end", "switch", "cases", "case_list", "case",
  "case_values", "default_case", "for", "while", "repeat", "expr",
  "range_expr", "range_interval", "or_expr", "and_expr", "bit_or_expr",
  "bit_xor_expr", "bit_and_expr", "equals_expr", "rel_expr", "concat_expr",
  "sum_expr", "mult_expr", "unary_expr", "exp_expr", "postfix_expr",
  "term", "array_allocation", "array_allocation_values",
  "struct_allocation", "struct_allocation_values", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }








  const short parser::yypact_ninf_ = -293;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     192,    27,    57,   139,   139,   139,   139,    70,   192,  -293,
    -293,  -293,  -293,  -293,  -293,  -293,  -293,    10,    10,  -293,
    -293,     6,    11,   129,   -41,  -293,  -293,    18,    24,   604,
    -293,    32,   -33,  -293,    36,   115,    14,    84,   139,   117,
     161,   124,  -293,  -293,   130,  -293,  -293,  -293,   191,   205,
     137,  -293,  -293,   -27,  -293,  -293,  -293,  -293,    87,  -293,
     167,   425,  -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,
    -293,  -293,   182,   182,   182,   182,   182,   182,   182,   425,
     232,   241,  -293,  -293,  -293,  -293,  2296,  2371,   201,   209,
     711,  -293,  -293,  2296,   212,  -293,   218,  -293,  2296,  -293,
    2472,  -293,  -293,   804,   222,  -293,  -293,  -293,  -293,  -293,
    -293,  -293,  -293,  -293,  -293,  2473,   197,   253,   255,   244,
     259,    58,   -16,   273,   164,    88,  -293,  -293,   283,   249,
    -293,  -293,  -293,   302,   246,  -293,   308,   425,   250,   256,
    -293,   224,   258,   258,  -293,   139,   262,  -293,   258,   258,
    -293,   264,  -293,   326,  -293,   425,  -293,  -293,  -293,  -293,
    -293,  -293,  -293,  -293,   290,   292,   911,    89,  -293,  -293,
    -293,  -293,  -293,  -293,  -293,   125,   274,   275,   269,    55,
     266,    13,  2296,  2296,  1004,   194,  2296,  -293,  -293,  2296,
    2296,  2296,  2296,  2296,  2296,  2296,  2296,  2296,  2296,  2296,
    2296,   237,   336,   159,  2296,  -293,   277,   278,  -293,   313,
    2473,  2473,  2473,  2473,  2473,  2473,  2473,  2473,  2473,  2473,
    2473,  2473,  2473,  2473,  2473,  2473,  2473,  2473,  2473,   182,
    -293,  -293,  -293,  -293,  -293,   285,  -293,  -293,   280,    15,
     288,  1097,   260,  -293,   300,   303,   272,  -293,  -293,   285,
     425,   425,   304,  1204,  2269,    12,   425,   425,  -293,   286,
    2176,   287,   307,   310,  -293,  2296,     5,   311,   295,   194,
    -293,  -293,   317,  -293,  -293,  -293,  -293,  -293,  -293,  -293,
    -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,  -293,    37,
    -293,   309,  -293,  -293,   253,   313,   255,   244,   259,    58,
     -16,   -16,   273,   273,   273,   273,   273,   164,    88,    88,
    -293,  -293,  -293,  -293,  -293,   195,   425,   315,  1311,   321,
     425,   425,   323,   -23,   -20,  -293,   325,   322,   329,  -293,
     -10,   -19,   -18,     9,   456,  2296,  2296,  1418,  -293,   389,
     338,    89,   240,  2176,  -293,  -293,  -293,  -293,  2296,  -293,
    -293,   326,  -293,   911,  -293,   334,  -293,   -46,    34,  -293,
    -293,  -293,  -293,   332,  2296,   401,  -293,  2296,  2296,    62,
    -293,  2398,  2176,  -293,   341,   344,  -293,  1511,   347,  2176,
       9,  2176,  2176,  -293,   198,  1604,  -293,   349,   352,  2296,
    -293,   368,  -293,  -293,  2176,    54,   371,  1711,  1804,  2296,
    -293,  2176,  2176,    89,  2176,  -293,   381,  -293,  -293,  -293,
      67,  2296,   456,   359,     9,  2176,  -293,  -293,  1897,   382,
    2176,  -293,  2296,  -293,  -293,  -293,     9,   177,   456,  -293,
    1990,  -293,   200,  2176,  -293,  -293,  2083,  2176,   456,  -293,
     456,  -293,  -293
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     2,     4,
       5,    10,    11,     6,     7,     8,     9,     0,     0,    73,
      74,     0,     0,     0,     0,     1,     3,     0,     0,     0,
      32,     0,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    61,     0,    54,    55,    56,     0,     0,
       0,    46,    48,     0,    41,    42,    43,    18,     0,    20,
       0,     0,   195,   191,   192,   193,   194,   196,    72,    71,
     197,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   149,   147,   148,     0,     0,     0,     0,
       0,    77,    78,     0,     0,   199,     0,    68,     0,    66,
     202,    67,    69,     0,     0,    81,    79,    80,    82,    86,
      83,    84,    85,    87,   142,     0,   141,   151,   153,   155,
     157,   159,   162,   168,   170,   173,   177,   185,   187,   190,
     200,   201,    30,     0,     0,    34,     0,     0,     0,     0,
      36,     0,     0,     0,    50,     0,     0,    53,     0,     0,
      39,     0,    40,     0,    17,     0,    95,    91,    94,    92,
      93,    98,    96,    97,     0,     0,     0,   202,   183,   182,
     181,   180,   179,   178,   184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,     0,    76,   143,
       0,   144,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     189,   188,    31,    29,    22,    37,    33,    35,     0,     0,
       0,     0,     0,    49,     0,     0,     0,    38,    19,    21,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,     0,     0,   140,     0,     0,     0,     0,   123,
     126,   124,     0,   103,   104,   105,   106,   109,   107,   110,
     108,   111,   112,   113,   102,    63,    62,    65,    26,     0,
      28,     0,    13,    75,   150,   145,   152,   154,   156,   158,
     160,   161,   165,   166,   163,   164,   167,   169,   172,   171,
     176,   174,   175,   186,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,     0,     0,     0,   209,
       0,     0,     0,     0,     0,     0,     0,     0,   139,     0,
       0,   131,     0,     0,   121,   125,   122,   203,     0,    25,
      64,     0,    16,     0,    60,     0,    51,     0,     0,    47,
     100,   101,    12,   204,     0,     0,   208,     0,     0,     0,
     120,     0,     0,   114,     0,     0,   138,     0,     0,     0,
       0,     0,   132,    27,     0,     0,    59,     0,     0,     0,
     211,     0,    89,    90,     0,     0,     0,     0,     0,     0,
     137,     0,   129,   130,   127,    15,     0,    44,    45,   207,
       0,     0,     0,     0,     0,     0,   119,   134,     0,     0,
     128,    57,     0,   205,   210,   115,     0,     0,     0,   133,
       0,   206,     0,     0,   116,   136,     0,     0,     0,   135,
       0,   118,   117
  };

  const short
  parser::yypgoto_[] =
  {
    -293,  -293,  -293,   447,  -293,   152,   154,   108,    -7,   105,
     314,    26,  -293,  -293,  -293,  -293,  -293,  -293,  -293,   421,
    -293,  -293,   417,  -293,  -293,  -293,  -293,   427,  -293,  -293,
     -29,  -293,  -293,     7,    21,  -102,  -293,   291,   -77,  -293,
    -293,  -292,  -293,  -293,  -293,   204,  -293,   206,  -293,  -293,
    -293,   234,  -293,   358,   -99,   267,   270,   263,   265,   268,
      95,   141,   261,    98,   -24,   -69,  -293,  -293,  -293,  -293,
    -293,  -293
  };

  const short
  parser::yydefgoto_[] =
  {
       0,     7,     8,     9,    10,    11,    12,   240,    29,    58,
      59,    60,    99,   205,   289,    13,    32,    14,    36,    37,
      15,    53,    54,    55,    56,    16,    44,    45,    46,    47,
     167,   101,   102,    21,   253,   104,   105,   106,   166,   107,
     108,   373,   109,   268,   269,   270,   342,   271,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   410,
     131,   330
  };

  const short
  parser::yytable_[] =
  {
     100,   207,   175,   168,   169,   170,   171,   172,   173,   174,
      28,    22,    23,    24,    68,    69,   209,    30,    68,    69,
      33,   328,   261,    33,    33,   360,   252,    33,   361,   218,
     219,   220,   221,   133,   367,   368,    17,    62,    63,    64,
      65,    66,    67,    68,    69,   141,    70,    71,    35,   252,
     103,   387,   252,   252,   252,    48,   365,    49,    72,    73,
     235,   100,    35,   413,   259,   366,    18,    50,   134,    48,
      25,    49,    80,    81,   100,    86,    74,   222,   249,    86,
      27,   151,   207,    75,    76,   216,    57,   329,    77,    57,
      78,    61,    79,    80,    81,    82,    83,    84,    85,   339,
     340,   132,   217,   348,    86,   135,   252,    31,   349,    97,
      87,   184,   295,    97,    34,    88,    89,   138,    90,   315,
     425,    91,    92,    93,   186,   186,   142,   201,    94,    95,
     202,   388,   203,   422,   204,    28,   434,   100,    97,   226,
     394,   245,   423,    98,   227,   228,   441,   414,   442,    19,
      20,   207,   242,   140,   201,   100,   153,   202,   154,   203,
     313,   204,    62,    63,    64,    65,    66,    67,    68,    69,
     143,    70,    71,   323,   324,    42,    51,    43,    52,   331,
     332,   136,   137,    72,    73,    62,    63,    64,    65,    66,
      67,    68,    69,   144,    70,    71,    42,   254,    43,   255,
     148,    74,   310,   311,   312,    51,   150,    52,    75,    76,
      38,   145,   100,    77,   149,    78,   207,    79,   224,   225,
      82,    83,    84,    85,   100,    39,    39,    40,    40,    86,
     288,   100,   207,   136,   155,    41,   146,   341,   210,   353,
      79,   176,   201,   357,   358,   202,   285,   203,   286,   204,
     177,   241,    86,    94,    95,   433,   244,   246,    82,    83,
      84,    85,   318,    97,   351,   201,   352,   153,   202,   405,
     203,   181,   204,   230,   231,   207,    94,    95,   437,   182,
     207,   334,   186,   207,   266,   267,    97,   187,     1,   100,
       2,   208,     3,   212,     4,   207,   214,     5,   213,     6,
     207,   215,   207,   223,   369,   100,   380,   381,   100,   229,
     207,   300,   301,   232,   100,   233,   207,   234,   207,   236,
     178,   180,   308,   309,   100,   237,   207,   185,   239,   100,
     238,   243,   188,   247,   207,    33,   207,   250,   207,   251,
     258,   256,   257,   100,   260,   287,   292,   293,   100,   314,
     100,   403,   100,   100,   210,   316,   100,   252,   377,   302,
     303,   304,   305,   306,   382,   100,   319,   320,   100,   100,
     321,   322,   100,   100,   385,   100,   336,   325,   343,   333,
     335,   337,   350,   100,   354,   427,   100,   344,   347,   100,
     356,   100,   359,   397,   362,   363,   364,   432,   378,   100,
     402,   100,   404,   386,   100,   379,   389,   100,   100,   100,
     391,   100,   398,   399,   401,   412,   263,   264,   407,   418,
     272,   408,   420,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   411,   428,   290,   291,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   415,
     421,   436,   426,   430,   438,    26,   384,   139,   440,    62,
      63,    64,    65,    66,    67,    68,    69,   248,    70,    71,
     152,   147,   262,   345,   211,   346,   297,   294,     0,   298,
      72,    73,   296,   299,   307,     0,     0,     0,   327,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,   338,
       0,     0,     0,     0,     0,    75,    76,     0,     0,     0,
      77,     0,    78,     0,    79,    80,    81,    82,    83,    84,
      85,     0,     0,     0,     0,     0,    86,     0,     0,     0,
       0,     0,    87,   370,     0,   371,   372,    88,    89,     0,
      90,     0,     0,    91,    92,    93,     0,     0,     0,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
      97,     0,     0,     0,     0,    98,     0,     0,     0,   374,
     375,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   383,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   390,     0,
       0,   392,   393,     0,     0,   396,     0,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,     0,     0,
       0,     0,     0,   409,     0,     0,     0,     0,    72,    73,
       0,     0,     0,   419,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   424,    74,     0,     0,     0,
       0,     0,     0,    75,    76,     0,   431,     0,    77,     0,
      78,     0,    79,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,    86,     0,     0,     0,     0,     0,
      87,     0,     0,     0,     0,    88,    89,     0,    90,     0,
       0,    91,    92,    93,     0,     0,     0,     0,    94,    95,
       0,     0,     0,    96,     0,     0,     0,     0,    97,     0,
       0,     0,     0,    98,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,     0,     0,
      75,    76,     0,     0,     0,    77,     0,    78,     0,    79,
      80,    81,    82,    83,    84,    85,     0,     0,     0,     0,
       0,    86,     0,     0,     0,     0,     0,    87,     0,     0,
       0,     0,    88,    89,     0,    90,   183,     0,    91,    92,
      93,     0,     0,     0,     0,    94,    95,    62,    63,    64,
      65,    66,    67,    68,    69,    97,    70,    71,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,     0,     0,     0,
       0,     0,     0,    75,    76,     0,     0,     0,    77,     0,
      78,     0,    79,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,    86,     0,     0,     0,     0,     0,
      87,     0,     0,     0,     0,    88,    89,     0,    90,     0,
       0,    91,    92,    93,     0,     0,     0,     0,    94,    95,
       0,     0,     0,   206,     0,     0,     0,     0,    97,     0,
       0,     0,     0,    98,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,     0,     0,
      75,    76,     0,     0,     0,    77,     0,    78,     0,    79,
      80,    81,    82,    83,    84,    85,     0,     0,     0,     0,
       0,    86,     0,   252,     0,     0,     0,    87,     0,     0,
       0,     0,    88,    89,     0,    90,     0,     0,    91,    92,
      93,     0,     0,     0,     0,    94,    95,    62,    63,    64,
      65,    66,    67,    68,    69,    97,    70,    71,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,     0,     0,     0,
       0,     0,     0,    75,    76,     0,     0,     0,    77,     0,
      78,     0,    79,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,    86,     0,     0,     0,     0,     0,
      87,     0,     0,     0,     0,    88,    89,     0,    90,   265,
       0,    91,    92,    93,     0,     0,     0,     0,    94,    95,
      62,    63,    64,    65,    66,    67,    68,    69,    97,    70,
      71,     0,     0,    98,     0,     0,     0,     0,     0,     0,
       0,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
       0,     0,     0,     0,     0,     0,    75,    76,     0,     0,
       0,    77,     0,    78,     0,    79,    80,    81,    82,    83,
      84,    85,     0,     0,     0,     0,     0,    86,     0,     0,
       0,     0,     0,    87,     0,     0,     0,     0,    88,    89,
       0,    90,     0,     0,    91,    92,    93,     0,     0,     0,
       0,    94,    95,     0,     0,     0,   317,     0,     0,     0,
       0,    97,     0,     0,     0,     0,    98,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,     0,     0,     0,
       0,     0,     0,    75,    76,     0,     0,     0,    77,     0,
      78,     0,    79,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,    86,     0,     0,     0,     0,     0,
      87,     0,     0,     0,     0,    88,    89,     0,    90,     0,
       0,    91,    92,    93,     0,     0,     0,     0,    94,    95,
       0,   326,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,    98,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,     0,     0,
      75,    76,     0,     0,     0,    77,     0,    78,     0,    79,
      80,    81,    82,    83,    84,    85,     0,     0,     0,     0,
       0,    86,     0,     0,     0,     0,     0,    87,     0,     0,
       0,     0,    88,    89,     0,    90,     0,     0,    91,    92,
      93,     0,     0,     0,     0,    94,    95,     0,     0,     0,
     355,     0,     0,     0,     0,    97,     0,     0,     0,     0,
      98,    62,    63,    64,    65,    66,    67,    68,    69,     0,
      70,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,     0,     0,     0,     0,     0,     0,    75,    76,     0,
       0,     0,    77,     0,    78,     0,    79,    80,    81,    82,
      83,    84,    85,     0,     0,     0,     0,     0,    86,     0,
       0,     0,     0,     0,    87,     0,     0,     0,     0,    88,
      89,   376,    90,     0,     0,    91,    92,    93,     0,     0,
       0,     0,    94,    95,    62,    63,    64,    65,    66,    67,
      68,    69,    97,    70,    71,     0,     0,    98,     0,     0,
       0,     0,     0,     0,     0,    72,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,     0,     0,
      75,    76,     0,     0,     0,    77,     0,    78,     0,    79,
      80,    81,    82,    83,    84,    85,     0,     0,     0,     0,
       0,    86,     0,     0,     0,     0,     0,    87,     0,     0,
       0,     0,    88,    89,   400,    90,     0,     0,    91,    92,
      93,     0,     0,     0,     0,    94,    95,    62,    63,    64,
      65,    66,    67,    68,    69,    97,    70,    71,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,     0,     0,     0,
       0,     0,     0,    75,    76,     0,     0,     0,    77,     0,
      78,     0,    79,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,    86,     0,     0,     0,     0,     0,
      87,     0,     0,     0,     0,    88,    89,     0,    90,     0,
       0,    91,    92,    93,     0,     0,     0,     0,    94,    95,
       0,   406,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,    98,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,     0,     0,
      75,    76,     0,     0,     0,    77,     0,    78,     0,    79,
      80,    81,    82,    83,    84,    85,     0,     0,     0,     0,
       0,    86,     0,     0,     0,     0,     0,    87,   416,     0,
       0,     0,    88,    89,     0,    90,     0,     0,    91,    92,
      93,     0,     0,     0,     0,    94,    95,    62,    63,    64,
      65,    66,    67,    68,    69,    97,    70,    71,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,     0,     0,     0,
       0,     0,     0,    75,    76,     0,     0,     0,    77,     0,
      78,     0,    79,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,    86,     0,     0,     0,     0,     0,
      87,     0,     0,     0,     0,    88,    89,     0,    90,     0,
     417,    91,    92,    93,     0,     0,     0,     0,    94,    95,
      62,    63,    64,    65,    66,    67,    68,    69,    97,    70,
      71,     0,     0,    98,     0,     0,     0,     0,     0,     0,
       0,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
       0,     0,     0,     0,     0,     0,    75,    76,     0,     0,
       0,    77,     0,    78,     0,    79,    80,    81,    82,    83,
      84,    85,     0,     0,     0,     0,     0,    86,     0,     0,
       0,     0,     0,    87,     0,     0,     0,     0,    88,    89,
       0,    90,     0,   429,    91,    92,    93,     0,     0,     0,
       0,    94,    95,    62,    63,    64,    65,    66,    67,    68,
      69,    97,    70,    71,     0,     0,    98,     0,     0,     0,
       0,     0,     0,     0,    72,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,    77,     0,    78,     0,    79,    80,
      81,    82,    83,    84,    85,     0,     0,     0,     0,     0,
      86,     0,     0,     0,     0,     0,    87,     0,     0,     0,
       0,    88,    89,     0,    90,     0,   435,    91,    92,    93,
       0,     0,     0,     0,    94,    95,    62,    63,    64,    65,
      66,    67,    68,    69,    97,    70,    71,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,     0,     0,     0,
       0,     0,    75,    76,     0,     0,     0,    77,     0,    78,
       0,    79,    80,    81,    82,    83,    84,    85,     0,     0,
       0,     0,     0,    86,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     0,    88,    89,     0,    90,     0,   439,
      91,    92,    93,     0,     0,     0,     0,    94,    95,    62,
      63,    64,    65,    66,    67,    68,    69,    97,    70,    71,
       0,     0,    98,     0,     0,     0,     0,     0,     0,     0,
      72,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,     0,
       0,     0,     0,     0,     0,    75,    76,     0,     0,     0,
      77,     0,    78,     0,    79,    80,    81,    82,    83,    84,
      85,     0,     0,     0,     0,     0,    86,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,    88,    89,     0,
      90,     0,     0,    91,    92,    93,     0,     0,     0,     0,
      94,    95,    62,    63,    64,    65,    66,    67,    68,    69,
      97,    70,    71,     0,     0,    98,     0,     0,     0,     0,
       0,     0,     0,    72,    73,     0,     0,     0,     0,    62,
      63,    64,    65,    66,    67,    68,    69,     0,    70,    71,
       0,    74,     0,     0,     0,     0,     0,     0,    75,    76,
      72,    73,     0,    77,     0,    78,     0,    79,     0,     0,
      82,    83,    84,    85,     0,     0,     0,     0,    74,    86,
       0,     0,   325,     0,     0,    75,    76,     0,     0,     0,
      77,     0,    78,     0,    79,     0,     0,    82,    83,    84,
      85,     0,     0,    94,    95,     0,    86,     0,     0,     0,
       0,     0,     0,    97,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,    71,     0,     0,     0,     0,     0,
      94,    95,     0,     0,     0,    72,    73,     0,     0,     0,
      97,    62,    63,    64,    65,    66,    67,    68,    69,     0,
      70,    71,     0,    74,     0,     0,     0,     0,     0,     0,
      75,    76,    72,    73,     0,    77,     0,    78,     0,    79,
       0,     0,    82,    83,    84,    85,     0,     0,     0,     0,
      74,    86,     0,     0,     0,     0,     0,    75,    76,     0,
       0,     0,    77,     0,    78,     0,    79,     0,     0,    82,
      83,    84,    85,     0,     0,   179,    95,     0,    86,     0,
       0,     0,     0,     0,     0,    97,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    70,    71,     0,     0,     0,
       0,     0,   395,    95,     0,     0,     0,    72,    73,     0,
     189,   190,    97,   191,   192,   193,   194,   195,   196,   197,
     198,   199,     0,     0,     0,    74,     0,     0,     0,     0,
       0,     0,    75,    76,     0,   200,     0,    77,     0,    78,
       0,    79,     0,     0,     0,     0,     0,   201,     0,     0,
     202,     0,   203,    86,   204,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,    97
  };

  const short
  parser::yycheck_[] =
  {
      29,   103,    79,    72,    73,    74,    75,    76,    77,    78,
      17,     4,     5,     6,     9,    10,   115,    11,     9,    10,
       9,     9,     9,     9,     9,    48,    72,     9,    48,    45,
      46,    47,    48,    66,    53,    53,     9,     3,     4,     5,
       6,     7,     8,     9,    10,    38,    12,    13,    22,    72,
      29,    97,    72,    72,    72,    96,    66,    98,    24,    25,
     137,    90,    36,     9,     9,    75,     9,   108,   101,    96,
       0,    98,    59,    60,   103,    70,    42,    93,   155,    70,
      70,   108,   184,    49,    50,    27,    71,    75,    54,    71,
      56,    67,    58,    59,    60,    61,    62,    63,    64,    94,
      95,    69,    44,    66,    70,    69,    72,   101,    71,   104,
      76,    90,   211,   104,   103,    81,    82,   103,    84,   104,
     412,    87,    88,    89,    70,    70,     9,    65,    94,    95,
      68,    97,    70,    66,    72,   142,   428,   166,   104,    51,
      78,   148,    75,   109,    56,    57,   438,    93,   440,    10,
      11,   253,   145,    69,    65,   184,    69,    68,    71,    70,
     229,    72,     3,     4,     5,     6,     7,     8,     9,    10,
       9,    12,    13,   250,   251,    23,    24,    23,    24,   256,
     257,    66,    67,    24,    25,     3,     4,     5,     6,     7,
       8,     9,    10,    69,    12,    13,    44,    72,    44,    74,
       9,    42,   226,   227,   228,    53,    69,    53,    49,    50,
      81,    81,   241,    54,     9,    56,   318,    58,    54,    55,
      61,    62,    63,    64,   253,    96,    96,    98,    98,    70,
      71,   260,   334,    66,    67,   106,   106,   266,    41,   316,
      58,     9,    65,   320,   321,    68,     9,    70,    11,    72,
       9,   143,    70,    94,    95,    78,   148,   149,    61,    62,
      63,    64,   241,   104,    69,    65,    71,    69,    68,    71,
      70,    70,    72,    24,    25,   377,    94,    95,    78,    70,
     382,   260,    70,   385,    90,    91,   104,    69,    96,   318,
      98,    69,   100,    40,   102,   397,    52,   105,    43,   107,
     402,    42,   404,    30,   333,   334,    66,    67,   337,    26,
     412,   216,   217,    11,   343,    69,   418,     9,   420,    69,
      86,    87,   224,   225,   353,    69,   428,    93,    70,   358,
     106,    69,    98,    69,   436,     9,   438,    47,   440,    47,
      71,    67,    67,   372,    78,     9,    69,    69,   377,    69,
     379,   380,   381,   382,    41,    67,   385,    72,   337,   218,
     219,   220,   221,   222,   343,   394,   106,    67,   397,   398,
      67,    99,   401,   402,   353,   404,    69,    73,    67,    93,
      93,    71,    73,   412,    69,   414,   415,    92,    71,   418,
      69,   420,    69,   372,    69,    73,    67,   426,     9,   428,
     379,   430,   381,    69,   433,    67,    74,   436,   437,   438,
       9,   440,    71,    69,    67,   394,   182,   183,    69,   398,
     186,    69,   401,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    67,   415,   203,   204,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    78,
      69,   430,    93,    71,   433,     8,   351,    36,   437,     3,
       4,     5,     6,     7,     8,     9,    10,   153,    12,    13,
      53,    44,   181,   269,   116,   269,   213,   210,    -1,   214,
      24,    25,   212,   215,   223,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,   265,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    77,    -1,    79,    80,    81,    82,    -1,
      84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,   335,
     336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   364,    -1,
      -1,   367,   368,    -1,    -1,   371,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,   389,    -1,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,   399,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   411,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,   422,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,
      -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    82,    -1,    84,    85,    -1,    87,    88,
      89,    -1,    -1,    -1,    -1,    94,    95,     3,     4,     5,
       6,     7,     8,     9,    10,   104,    12,    13,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,
      -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    82,    -1,    84,    -1,    -1,    87,    88,
      89,    -1,    -1,    -1,    -1,    94,    95,     3,     4,     5,
       6,     7,     8,     9,    10,   104,    12,    13,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,    85,
      -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,
       3,     4,     5,     6,     7,     8,     9,    10,   104,    12,
      13,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,
      -1,    84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,   109,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,
      -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    82,    -1,    84,    -1,    -1,    87,    88,
      89,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
     109,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    -1,    -1,    87,    88,    89,    -1,    -1,
      -1,    -1,    94,    95,     3,     4,     5,     6,     7,     8,
       9,    10,   104,    12,    13,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    -1,    -1,    87,    88,
      89,    -1,    -1,    -1,    -1,    94,    95,     3,     4,     5,
       6,     7,     8,     9,    10,   104,    12,    13,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,
      -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    81,    82,    -1,    84,    -1,    -1,    87,    88,
      89,    -1,    -1,    -1,    -1,    94,    95,     3,     4,     5,
       6,     7,     8,     9,    10,   104,    12,    13,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,
      86,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,
       3,     4,     5,     6,     7,     8,     9,    10,   104,    12,
      13,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,
      -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    94,    95,     3,     4,     5,     6,     7,     8,     9,
      10,   104,    12,    13,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    81,    82,    -1,    84,    -1,    86,    87,    88,    89,
      -1,    -1,    -1,    -1,    94,    95,     3,     4,     5,     6,
       7,     8,     9,    10,   104,    12,    13,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,     3,
       4,     5,     6,     7,     8,     9,    10,   104,    12,    13,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,    -1,
      84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,
      94,    95,     3,     4,     5,     6,     7,     8,     9,    10,
     104,    12,    13,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      24,    25,    -1,    54,    -1,    56,    -1,    58,    -1,    -1,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    42,    70,
      -1,    -1,    73,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    56,    -1,    58,    -1,    -1,    61,    62,    63,
      64,    -1,    -1,    94,    95,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,   104,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
     104,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    24,    25,    -1,    54,    -1,    56,    -1,    58,
      -1,    -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      42,    70,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      -1,    -1,    54,    -1,    56,    -1,    58,    -1,    -1,    61,
      62,    63,    64,    -1,    -1,    94,    95,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,   104,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    24,    25,    -1,
      28,    29,   104,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    53,    -1,    54,    -1,    56,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      68,    -1,    70,    70,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    96,    98,   100,   102,   105,   107,   112,   113,   114,
     115,   116,   117,   126,   128,   131,   136,     9,     9,    10,
      11,   144,   144,   144,   144,     0,   114,    70,   119,   119,
      11,   101,   127,     9,   103,   122,   129,   130,    81,    96,
      98,   106,   116,   117,   137,   138,   139,   140,    96,    98,
     108,   116,   117,   132,   133,   134,   135,    71,   120,   121,
     122,    67,     3,     4,     5,     6,     7,     8,     9,    10,
      12,    13,    24,    25,    42,    49,    50,    54,    56,    58,
      59,    60,    61,    62,    63,    64,    70,    76,    81,    82,
      84,    87,    88,    89,    94,    95,    99,   104,   109,   123,
     141,   142,   143,   145,   146,   147,   148,   150,   151,   153,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   181,    69,    66,   101,    69,    66,    67,   103,   130,
      69,   144,     9,     9,    69,    81,   106,   138,     9,     9,
      69,   108,   133,    69,    71,    67,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   149,   141,   176,   176,
     176,   176,   176,   176,   176,   149,     9,     9,   162,    94,
     162,    70,    70,    85,   145,   162,    70,    69,   162,    28,
      29,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      53,    65,    68,    70,    72,   124,    99,   146,    69,   165,
      41,   164,    40,    43,    52,    42,    27,    44,    45,    46,
      47,    48,    93,    30,    54,    55,    51,    56,    57,    26,
      24,    25,    11,    69,     9,   149,    69,    69,   106,    70,
     118,   118,   144,    69,   118,   119,   118,    69,   121,   149,
      47,    47,    72,   145,    72,    74,    67,    67,    71,     9,
      78,     9,   148,   162,   162,    85,    90,    91,   154,   155,
     156,   158,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,     9,    11,     9,    71,   125,
     162,   162,    69,    69,   166,   165,   167,   168,   169,   170,
     171,   171,   172,   172,   172,   172,   172,   173,   174,   174,
     175,   175,   175,   176,    69,   104,    67,    99,   145,   106,
      67,    67,    99,   149,   149,    73,    97,   162,     9,    75,
     182,   149,   149,    93,   145,    93,    69,    71,   162,    94,
      95,   141,   157,    67,    92,   156,   158,    71,    66,    71,
      73,    69,    71,   149,    69,    99,    69,   149,   149,    69,
      48,    48,    69,    73,    67,    66,    75,    53,    53,   141,
      77,    79,    80,   152,   162,   162,    83,   145,     9,    67,
      66,    67,   145,   162,   120,   145,    69,    97,    97,    74,
     162,     9,   162,   162,    78,    94,   162,   145,    71,    69,
      83,    67,   145,   141,   145,    71,    97,    69,    69,   162,
     180,    67,   145,     9,    93,    78,    77,    86,   145,   162,
     145,    69,    66,    75,   162,   152,    93,   141,   145,    86,
      71,   162,   141,    78,   152,    86,   145,    78,   145,    86,
     145,   152,   152
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   111,   112,   113,   113,   114,   114,   114,   114,   114,
     115,   115,   116,   117,   117,   118,   118,   119,   119,   120,
     120,   121,   122,   122,   123,   124,   124,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   131,   131,
     132,   132,   133,   133,   134,   134,   134,   135,   135,   136,
     136,   136,   136,   137,   137,   138,   138,   139,   139,   140,
     140,   140,   141,   141,   141,   141,   141,   141,   142,   142,
     142,   143,   143,   144,   144,   145,   145,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   147,   148,
     148,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   151,   151,   152,   152,   152,   152,
     152,   153,   154,   154,   154,   155,   155,   156,   156,   156,
     157,   157,   158,   159,   159,   159,   159,   160,   160,   161,
     161,   162,   162,   163,   163,   163,   164,   164,   164,   164,
     165,   165,   166,   166,   167,   167,   168,   168,   169,   169,
     170,   170,   170,   171,   171,   171,   171,   171,   171,   172,
     172,   173,   173,   173,   174,   174,   174,   174,   175,   175,
     175,   175,   175,   175,   175,   175,   176,   176,   177,   177,
     177,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   179,   179,   180,   180,   181,   181,
     182,   182
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     8,     6,     5,     5,     3,     3,     2,     3,
       1,     3,     3,     1,     2,     3,     2,     3,     1,     5,
       4,     3,     1,     5,     4,     3,     2,     3,     5,     4,
       2,     1,     1,     1,     7,     7,     1,     5,     1,     5,
       4,     7,     6,     2,     1,     1,     1,     8,     1,     6,
       5,     1,     3,     3,     4,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     6,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     8,     5,     8,     7,     3,
       1,     4,     2,     1,     1,     2,     1,     4,     5,     4,
       3,     1,     3,     8,     7,    10,     9,     6,     5,     4,
       3,     1,     1,     2,     2,     3,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       2,     2,     2,     2,     2,     1,     3,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     5,     8,     3,     1,     5,     4,
       5,     3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    72,    72,    76,    79,    84,    86,    88,    90,    92,
      96,    98,   102,   106,   108,   112,   114,   118,   120,   124,
     129,   136,   143,   146,   151,   155,   157,   161,   163,   167,
     169,   173,   175,   179,   181,   185,   187,   191,   195,   197,
     201,   203,   207,   209,   213,   215,   217,   221,   223,   227,
     229,   231,   233,   237,   239,   243,   245,   249,   251,   255,
     257,   259,   263,   265,   267,   269,   271,   273,   277,   279,
     281,   285,   287,   291,   293,   297,   299,   303,   305,   307,
     309,   311,   313,   315,   317,   319,   321,   323,   327,   331,
     333,   337,   339,   341,   343,   345,   347,   349,   351,   353,
     355,   357,   361,   363,   365,   367,   369,   371,   373,   375,
     377,   379,   381,   383,   387,   389,   393,   395,   397,   399,
     401,   405,   409,   411,   413,   417,   419,   423,   425,   427,
     431,   433,   437,   441,   443,   445,   447,   451,   453,   457,
     459,   463,   465,   469,   471,   473,   477,   479,   481,   483,
     487,   489,   493,   495,   499,   501,   505,   507,   511,   513,
     517,   519,   521,   525,   527,   529,   531,   533,   535,   539,
     541,   545,   547,   549,   553,   555,   557,   559,   563,   565,
     567,   569,   571,   573,   575,   577,   581,   583,   587,   589,
     591,   595,   597,   599,   601,   603,   605,   607,   609,   611,
     613,   615,   617,   619,   623,   625,   629,   631,   635,   637,
     641,   643
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 3968 "grammar/build/syntax.tab.cc"

#line 646 "grammar/syntax.y"
