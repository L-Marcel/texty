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
      case symbol_kind::S_access_base: // access_base
        value.YY_MOVE_OR_COPY< AccessBaseNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_access: // access
        value.YY_MOVE_OR_COPY< AccessNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attr: // attr
        value.YY_MOVE_OR_COPY< AttrNode* > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_return: // return
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

      case symbol_kind::S_subprogram_call: // subprogram_call
        value.YY_MOVE_OR_COPY< SubprogramCallNode* > (YY_MOVE (that.value));
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
      case symbol_kind::S_id: // id
      case symbol_kind::S_name: // name
        value.YY_MOVE_OR_COPY< string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BYTE: // BYTE
        value.YY_MOVE_OR_COPY< uint8_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_call_params_list: // call_params_list
      case symbol_kind::S_call_params: // call_params
        value.YY_MOVE_OR_COPY< vector<ExpressionNode*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.YY_MOVE_OR_COPY< vector<Node*> > (YY_MOVE (that.value));
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
      case symbol_kind::S_access_base: // access_base
        value.move< AccessBaseNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_access: // access
        value.move< AccessNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attr: // attr
        value.move< AttrNode* > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_return: // return
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

      case symbol_kind::S_subprogram_call: // subprogram_call
        value.move< SubprogramCallNode* > (YY_MOVE (that.value));
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
      case symbol_kind::S_id: // id
      case symbol_kind::S_name: // name
        value.move< string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BYTE: // BYTE
        value.move< uint8_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_call_params_list: // call_params_list
      case symbol_kind::S_call_params: // call_params
        value.move< vector<ExpressionNode*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.move< vector<Node*> > (YY_MOVE (that.value));
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
      case symbol_kind::S_access_base: // access_base
        value.copy< AccessBaseNode* > (that.value);
        break;

      case symbol_kind::S_access: // access
        value.copy< AccessNode* > (that.value);
        break;

      case symbol_kind::S_attr: // attr
        value.copy< AttrNode* > (that.value);
        break;

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
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_return: // return
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

      case symbol_kind::S_subprogram_call: // subprogram_call
        value.copy< SubprogramCallNode* > (that.value);
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
      case symbol_kind::S_id: // id
      case symbol_kind::S_name: // name
        value.copy< string > (that.value);
        break;

      case symbol_kind::S_BYTE: // BYTE
        value.copy< uint8_t > (that.value);
        break;

      case symbol_kind::S_call_params_list: // call_params_list
      case symbol_kind::S_call_params: // call_params
        value.copy< vector<ExpressionNode*> > (that.value);
        break;

      case symbol_kind::S_stmts: // stmts
        value.copy< vector<Node*> > (that.value);
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
      case symbol_kind::S_access_base: // access_base
        value.move< AccessBaseNode* > (that.value);
        break;

      case symbol_kind::S_access: // access
        value.move< AccessNode* > (that.value);
        break;

      case symbol_kind::S_attr: // attr
        value.move< AttrNode* > (that.value);
        break;

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
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_return: // return
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

      case symbol_kind::S_subprogram_call: // subprogram_call
        value.move< SubprogramCallNode* > (that.value);
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
      case symbol_kind::S_id: // id
      case symbol_kind::S_name: // name
        value.move< string > (that.value);
        break;

      case symbol_kind::S_BYTE: // BYTE
        value.move< uint8_t > (that.value);
        break;

      case symbol_kind::S_call_params_list: // call_params_list
      case symbol_kind::S_call_params: // call_params
        value.move< vector<ExpressionNode*> > (that.value);
        break;

      case symbol_kind::S_stmts: // stmts
        value.move< vector<Node*> > (that.value);
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
      case symbol_kind::S_access_base: // access_base
        yylhs.value.emplace< AccessBaseNode* > ();
        break;

      case symbol_kind::S_access: // access
        yylhs.value.emplace< AccessNode* > ();
        break;

      case symbol_kind::S_attr: // attr
        yylhs.value.emplace< AttrNode* > ();
        break;

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
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_return: // return
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

      case symbol_kind::S_subprogram_call: // subprogram_call
        yylhs.value.emplace< SubprogramCallNode* > ();
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
      case symbol_kind::S_id: // id
      case symbol_kind::S_name: // name
        yylhs.value.emplace< string > ();
        break;

      case symbol_kind::S_BYTE: // BYTE
        yylhs.value.emplace< uint8_t > ();
        break;

      case symbol_kind::S_call_params_list: // call_params_list
      case symbol_kind::S_call_params: // call_params
        yylhs.value.emplace< vector<ExpressionNode*> > ();
        break;

      case symbol_kind::S_stmts: // stmts
        yylhs.value.emplace< vector<Node*> > ();
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
#line 78 "grammar/syntax.y"
              {
  ctx.root = yystack_[0].value.as < Node* > ();
}
#line 1287 "grammar/build/syntax.tab.cc"
    break;

  case 3: // program: program program_slice
#line 82 "grammar/syntax.y"
                               {
  yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > ();
  yystack_[1].value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
}
#line 1296 "grammar/build/syntax.tab.cc"
    break;

  case 4: // program: program_slice
#line 85 "grammar/syntax.y"
                  {
  yylhs.value.as < Node* > () = new Node(ctx.line, "PROGRAM");
  yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
}
#line 1305 "grammar/build/syntax.tab.cc"
    break;

  case 5: // program_slice: subprogram
#line 90 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1313 "grammar/build/syntax.tab.cc"
    break;

  case 6: // program_slice: enum
#line 92 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1321 "grammar/build/syntax.tab.cc"
    break;

  case 7: // program_slice: struct
#line 94 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1329 "grammar/build/syntax.tab.cc"
    break;

  case 8: // program_slice: trait
#line 96 "grammar/syntax.y"
          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1337 "grammar/build/syntax.tab.cc"
    break;

  case 9: // program_slice: impl
#line 98 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1345 "grammar/build/syntax.tab.cc"
    break;

  case 10: // subprogram: fn
#line 102 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = yystack_[0].value.as < FunctionNode* > ();
}
#line 1353 "grammar/build/syntax.tab.cc"
    break;

  case 11: // subprogram: proc
#line 104 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ProcedureNode* > ();
}
#line 1361 "grammar/build/syntax.tab.cc"
    break;

  case 12: // fn: FUNCTION ID params_list COLON type stmts END_FUNCTION SEMICOLON
#line 108 "grammar/syntax.y"
                                                                    {
  yylhs.value.as < FunctionNode* > () = new FunctionNode(ctx.line, yystack_[6].value.as < string > (), *yystack_[3].value.as < Type* > (), yystack_[5].value.as < vector<Param> > ());
  for (size_t i = 0; i < yystack_[2].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < FunctionNode* > ()->children.push_back(yystack_[2].value.as < vector<Node*> > ()[i]);
  };
}
#line 1372 "grammar/build/syntax.tab.cc"
    break;

  case 13: // proc: PROCEDURE ID params_list stmts END_PROCEDURE SEMICOLON
#line 115 "grammar/syntax.y"
                                                             {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[4].value.as < string > (), yystack_[3].value.as < vector<Param> > ());
  for (size_t i = 0; i < yystack_[2].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < ProcedureNode* > ()->children.push_back(yystack_[2].value.as < vector<Node*> > ()[i]);
  };
}
#line 1383 "grammar/build/syntax.tab.cc"
    break;

  case 14: // proc: PROCEDURE ID params_list END_PROCEDURE SEMICOLON
#line 120 "grammar/syntax.y"
                                                     {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[3].value.as < string > (), yystack_[2].value.as < vector<Param> > ());
}
#line 1391 "grammar/build/syntax.tab.cc"
    break;

  case 15: // params_self_list: LEFT_PAREN SELF SEMICOLON params RIGHT_PAREN
#line 124 "grammar/syntax.y"
                                                               {
  yylhs.value.as < vector<Param> > () = yystack_[1].value.as < vector<Param> > ();
}
#line 1399 "grammar/build/syntax.tab.cc"
    break;

  case 16: // params_self_list: LEFT_PAREN SELF RIGHT_PAREN
#line 126 "grammar/syntax.y"
                                {
  yylhs.value.as < vector<Param> > () = vector<Param>();
}
#line 1407 "grammar/build/syntax.tab.cc"
    break;

  case 17: // params_list: LEFT_PAREN params RIGHT_PAREN
#line 130 "grammar/syntax.y"
                                           {
  yylhs.value.as < vector<Param> > () = yystack_[1].value.as < vector<Param> > ();
}
#line 1415 "grammar/build/syntax.tab.cc"
    break;

  case 18: // params_list: LEFT_PAREN RIGHT_PAREN
#line 132 "grammar/syntax.y"
                           {
  yylhs.value.as < vector<Param> > () = vector<Param>();
}
#line 1423 "grammar/build/syntax.tab.cc"
    break;

  case 19: // params: params SEMICOLON param
#line 136 "grammar/syntax.y"
                               {
  yylhs.value.as < vector<Param> > () = yystack_[2].value.as < vector<Param> > ();
  for (size_t i = 0; i < yystack_[0].value.as < vector<Param> > ().size(); i++) {
    yylhs.value.as < vector<Param> > ().push_back(yystack_[0].value.as < vector<Param> > ()[i]);
  };
}
#line 1434 "grammar/build/syntax.tab.cc"
    break;

  case 20: // params: param
#line 141 "grammar/syntax.y"
          {
  yylhs.value.as < vector<Param> > () = vector<Param>();
  for (size_t i = 0; i < yystack_[0].value.as < vector<Param> > ().size(); i++) {
    yylhs.value.as < vector<Param> > ().push_back(yystack_[0].value.as < vector<Param> > ()[i]);
  };
}
#line 1445 "grammar/build/syntax.tab.cc"
    break;

  case 21: // param: id_list COLON type
#line 148 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<Param> > () = vector<Param>();
  for (size_t i = 0; i < yystack_[2].value.as < vector<string> > ().size(); i++) {
    yylhs.value.as < vector<Param> > ().push_back({yystack_[2].value.as < vector<string> > ()[i], *yystack_[0].value.as < Type* > ()});
  };
}
#line 1456 "grammar/build/syntax.tab.cc"
    break;

  case 22: // id_list: id_list COMMA ID
#line 155 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<string> > () = yystack_[2].value.as < vector<string> > ();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < string > ());
}
#line 1465 "grammar/build/syntax.tab.cc"
    break;

  case 23: // id_list: ID
#line 158 "grammar/syntax.y"
       {
  yylhs.value.as < vector<string> > () = vector<string>();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < string > ());
}
#line 1474 "grammar/build/syntax.tab.cc"
    break;

  case 24: // subprogram_call: access call_params_list
#line 163 "grammar/syntax.y"
                                         {
  yylhs.value.as < SubprogramCallNode* > () = new SubprogramCallNode(ctx.line, yystack_[1].value.as < AccessNode* > (), yystack_[0].value.as < vector<ExpressionNode*> > ());
}
#line 1482 "grammar/build/syntax.tab.cc"
    break;

  case 25: // subprogram_call: type call_params_list
#line 165 "grammar/syntax.y"
                          {
  yylhs.value.as < SubprogramCallNode* > () = new SubprogramCallNode(ctx.line, *yystack_[1].value.as < Type* > (), yystack_[0].value.as < vector<ExpressionNode*> > ());
}
#line 1490 "grammar/build/syntax.tab.cc"
    break;

  case 26: // call_params_list: LEFT_PAREN call_params RIGHT_PAREN
#line 169 "grammar/syntax.y"
                                                     {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[1].value.as < vector<ExpressionNode*> > ();
}
#line 1498 "grammar/build/syntax.tab.cc"
    break;

  case 27: // call_params_list: LEFT_PAREN RIGHT_PAREN
#line 171 "grammar/syntax.y"
                           {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
}
#line 1506 "grammar/build/syntax.tab.cc"
    break;

  case 28: // call_params: call_params COMMA expr
#line 175 "grammar/syntax.y"
                                    {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[2].value.as < vector<ExpressionNode*> > ();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 1515 "grammar/build/syntax.tab.cc"
    break;

  case 29: // call_params: expr
#line 178 "grammar/syntax.y"
         {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 1524 "grammar/build/syntax.tab.cc"
    break;

  case 30: // enum: ENUM name enum_values END_ENUM SEMICOLON
#line 183 "grammar/syntax.y"
                                               {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1532 "grammar/build/syntax.tab.cc"
    break;

  case 31: // enum: ENUM name END_ENUM SEMICOLON
#line 185 "grammar/syntax.y"
                                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1540 "grammar/build/syntax.tab.cc"
    break;

  case 32: // enum_values: enum_values COMMA CONST_NAME
#line 189 "grammar/syntax.y"
                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1548 "grammar/build/syntax.tab.cc"
    break;

  case 33: // enum_values: CONST_NAME
#line 191 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1556 "grammar/build/syntax.tab.cc"
    break;

  case 34: // struct: STRUCT name struct_attrs END_STRUCT SEMICOLON
#line 195 "grammar/syntax.y"
                                                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1564 "grammar/build/syntax.tab.cc"
    break;

  case 35: // struct: STRUCT name END_STRUCT SEMICOLON
#line 197 "grammar/syntax.y"
                                     {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1572 "grammar/build/syntax.tab.cc"
    break;

  case 36: // struct_attrs: struct_attrs struct_attr SEMICOLON
#line 201 "grammar/syntax.y"
                                                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1580 "grammar/build/syntax.tab.cc"
    break;

  case 37: // struct_attrs: struct_attr SEMICOLON
#line 203 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1588 "grammar/build/syntax.tab.cc"
    break;

  case 38: // struct_attr: id_list COLON type
#line 207 "grammar/syntax.y"
                                {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1596 "grammar/build/syntax.tab.cc"
    break;

  case 39: // trait: TRAIT name trait_subprograms END_TRAIT SEMICOLON
#line 211 "grammar/syntax.y"
                                                        {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1604 "grammar/build/syntax.tab.cc"
    break;

  case 40: // trait: TRAIT name END_TRAIT SEMICOLON
#line 213 "grammar/syntax.y"
                                   {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1612 "grammar/build/syntax.tab.cc"
    break;

  case 41: // trait_subprograms: trait_subprograms trait_subprogram
#line 217 "grammar/syntax.y"
                                                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1620 "grammar/build/syntax.tab.cc"
    break;

  case 42: // trait_subprograms: trait_subprogram
#line 219 "grammar/syntax.y"
                     {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1628 "grammar/build/syntax.tab.cc"
    break;

  case 43: // trait_subprogram: trait_fn
#line 223 "grammar/syntax.y"
                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1636 "grammar/build/syntax.tab.cc"
    break;

  case 44: // trait_subprogram: trait_proc
#line 225 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1644 "grammar/build/syntax.tab.cc"
    break;

  case 45: // trait_fn: FUNCTION ID params_self_list COLON type END_FUNCTION SEMICOLON
#line 229 "grammar/syntax.y"
                                                                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1652 "grammar/build/syntax.tab.cc"
    break;

  case 46: // trait_fn: FUNCTION ID params_list COLON type END_FUNCTION SEMICOLON
#line 231 "grammar/syntax.y"
                                                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1660 "grammar/build/syntax.tab.cc"
    break;

  case 47: // trait_fn: fn
#line 233 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1668 "grammar/build/syntax.tab.cc"
    break;

  case 48: // trait_proc: PROCEDURE ID params_self_list END_PROCEDURE SEMICOLON
#line 237 "grammar/syntax.y"
                                                                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1676 "grammar/build/syntax.tab.cc"
    break;

  case 49: // trait_proc: proc
#line 239 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1684 "grammar/build/syntax.tab.cc"
    break;

  case 50: // impl: IMPL name impl_subprograms END_IMPL SEMICOLON
#line 243 "grammar/syntax.y"
                                                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1692 "grammar/build/syntax.tab.cc"
    break;

  case 51: // impl: IMPL name END_IMPL SEMICOLON
#line 245 "grammar/syntax.y"
                                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1700 "grammar/build/syntax.tab.cc"
    break;

  case 52: // impl: IMPL name impl_subprograms FOR name END_IMPL SEMICOLON
#line 247 "grammar/syntax.y"
                                                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1708 "grammar/build/syntax.tab.cc"
    break;

  case 53: // impl: IMPL name FOR name END_IMPL SEMICOLON
#line 249 "grammar/syntax.y"
                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1716 "grammar/build/syntax.tab.cc"
    break;

  case 54: // impl_subprograms: impl_subprograms impl_subprogram
#line 253 "grammar/syntax.y"
                                                   {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1724 "grammar/build/syntax.tab.cc"
    break;

  case 55: // impl_subprograms: impl_subprogram
#line 255 "grammar/syntax.y"
                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1732 "grammar/build/syntax.tab.cc"
    break;

  case 56: // impl_subprogram: impl_fn
#line 259 "grammar/syntax.y"
                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1740 "grammar/build/syntax.tab.cc"
    break;

  case 57: // impl_subprogram: impl_proc
#line 261 "grammar/syntax.y"
              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1748 "grammar/build/syntax.tab.cc"
    break;

  case 58: // impl_fn: FUNCTION ID params_self_list COLON type stmts END_FUNCTION SEMICOLON
#line 265 "grammar/syntax.y"
                                                                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1756 "grammar/build/syntax.tab.cc"
    break;

  case 59: // impl_fn: fn
#line 267 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1764 "grammar/build/syntax.tab.cc"
    break;

  case 60: // impl_proc: PROCEDURE ID params_self_list stmts END_PROCEDURE SEMICOLON
#line 271 "grammar/syntax.y"
                                                                       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1772 "grammar/build/syntax.tab.cc"
    break;

  case 61: // impl_proc: PROCEDURE ID params_self_list END_PROCEDURE SEMICOLON
#line 273 "grammar/syntax.y"
                                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1780 "grammar/build/syntax.tab.cc"
    break;

  case 62: // impl_proc: proc
#line 275 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1788 "grammar/build/syntax.tab.cc"
    break;

  case 63: // access: access DOT CONST_NAME
#line 279 "grammar/syntax.y"
                              {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < string > (), yystack_[2].value.as < AccessNode* > (), AccessType::DOT);
}
#line 1796 "grammar/build/syntax.tab.cc"
    break;

  case 64: // access: access DOT ID
#line 281 "grammar/syntax.y"
                  {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < string > (), yystack_[2].value.as < AccessNode* > (), AccessType::DOT);
}
#line 1804 "grammar/build/syntax.tab.cc"
    break;

  case 65: // access: access LEFT_BRACKET expr RIGHT_BRACKET
#line 283 "grammar/syntax.y"
                                           {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[3].value.as < AccessNode* > (), yystack_[1].value.as < ExpressionNode* > ());
}
#line 1812 "grammar/build/syntax.tab.cc"
    break;

  case 66: // access: access DOUBLE_COLON ID
#line 285 "grammar/syntax.y"
                           {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < string > (), yystack_[2].value.as < AccessNode* > (), AccessType::STATIC);
}
#line 1820 "grammar/build/syntax.tab.cc"
    break;

  case 67: // access: subprogram_call
#line 287 "grammar/syntax.y"
                    {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < SubprogramCallNode* > ());
}
#line 1828 "grammar/build/syntax.tab.cc"
    break;

  case 68: // access: access_base
#line 289 "grammar/syntax.y"
                {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < AccessBaseNode* > ());
}
#line 1836 "grammar/build/syntax.tab.cc"
    break;

  case 69: // access_base: SELF
#line 293 "grammar/syntax.y"
                  {
  yylhs.value.as < AccessBaseNode* > () = new AccessBaseNode(ctx.line);
}
#line 1844 "grammar/build/syntax.tab.cc"
    break;

  case 70: // access_base: id
#line 295 "grammar/syntax.y"
       {
  yylhs.value.as < AccessBaseNode* > () = new AccessBaseNode(ctx.line, yystack_[0].value.as < string > ());
}
#line 1852 "grammar/build/syntax.tab.cc"
    break;

  case 71: // access_base: LEFT_PAREN expr RIGHT_PAREN
#line 297 "grammar/syntax.y"
                                {
  yylhs.value.as < AccessBaseNode* > () = new AccessBaseNode(ctx.line, yystack_[1].value.as < ExpressionNode* > ());
}
#line 1860 "grammar/build/syntax.tab.cc"
    break;

  case 72: // id: NAME
#line 301 "grammar/syntax.y"
         {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 1868 "grammar/build/syntax.tab.cc"
    break;

  case 73: // id: ID
#line 303 "grammar/syntax.y"
       {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 1876 "grammar/build/syntax.tab.cc"
    break;

  case 74: // name: NAME
#line 307 "grammar/syntax.y"
           {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 1884 "grammar/build/syntax.tab.cc"
    break;

  case 75: // name: CONST_NAME
#line 309 "grammar/syntax.y"
               {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 1892 "grammar/build/syntax.tab.cc"
    break;

  case 76: // stmts: stmts stmt SEMICOLON
#line 313 "grammar/syntax.y"
                            {
  yylhs.value.as < vector<Node*> > () = yystack_[2].value.as < vector<Node*> > ();
  yylhs.value.as < vector<Node*> > ().push_back(yystack_[1].value.as < Node* > ());
}
#line 1901 "grammar/build/syntax.tab.cc"
    break;

  case 77: // stmts: stmt SEMICOLON
#line 316 "grammar/syntax.y"
                   {
  yylhs.value.as < vector<Node*> > () = vector<Node*>();
  yylhs.value.as < vector<Node*> > ().push_back(yystack_[1].value.as < Node* > ());
}
#line 1910 "grammar/build/syntax.tab.cc"
    break;

  case 78: // stmt: BREAK
#line 321 "grammar/syntax.y"
            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1918 "grammar/build/syntax.tab.cc"
    break;

  case 79: // stmt: CONTINUE
#line 323 "grammar/syntax.y"
             {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1926 "grammar/build/syntax.tab.cc"
    break;

  case 80: // stmt: attr
#line 325 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < AttrNode* > ();
}
#line 1934 "grammar/build/syntax.tab.cc"
    break;

  case 81: // stmt: assign
#line 327 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1942 "grammar/build/syntax.tab.cc"
    break;

  case 82: // stmt: return
#line 329 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1950 "grammar/build/syntax.tab.cc"
    break;

  case 83: // stmt: if
#line 331 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1958 "grammar/build/syntax.tab.cc"
    break;

  case 84: // stmt: for
#line 333 "grammar/syntax.y"
        {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1966 "grammar/build/syntax.tab.cc"
    break;

  case 85: // stmt: while
#line 335 "grammar/syntax.y"
          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1974 "grammar/build/syntax.tab.cc"
    break;

  case 86: // stmt: repeat
#line 337 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1982 "grammar/build/syntax.tab.cc"
    break;

  case 87: // stmt: switch
#line 339 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1990 "grammar/build/syntax.tab.cc"
    break;

  case 88: // stmt: expr
#line 341 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 1998 "grammar/build/syntax.tab.cc"
    break;

  case 89: // return: RETURN expr
#line 345 "grammar/syntax.y"
                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2006 "grammar/build/syntax.tab.cc"
    break;

  case 90: // attr: VAR ID COLON type ATTR expr
#line 349 "grammar/syntax.y"
                                  {
  yylhs.value.as < AttrNode* > () = new AttrNode(ctx.line, yystack_[4].value.as < string > (), false, *yystack_[2].value.as < Type* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2014 "grammar/build/syntax.tab.cc"
    break;

  case 91: // attr: CONST ID COLON type ATTR expr
#line 351 "grammar/syntax.y"
                                  {
  yylhs.value.as < AttrNode* > () = new AttrNode(ctx.line, yystack_[4].value.as < string > (), true, *yystack_[2].value.as < Type* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2022 "grammar/build/syntax.tab.cc"
    break;

  case 92: // type: TYPE_INT
#line 355 "grammar/syntax.y"
               {
  yylhs.value.as < Type* > () = new Type(TypeKind::INT);
}
#line 2030 "grammar/build/syntax.tab.cc"
    break;

  case 93: // type: TYPE_FLOAT
#line 357 "grammar/syntax.y"
               {
  yylhs.value.as < Type* > () = new Type(TypeKind::FLOAT);
}
#line 2038 "grammar/build/syntax.tab.cc"
    break;

  case 94: // type: TYPE_DOUBLE
#line 359 "grammar/syntax.y"
                {
  yylhs.value.as < Type* > () = new Type(TypeKind::DOUBLE);
}
#line 2046 "grammar/build/syntax.tab.cc"
    break;

  case 95: // type: TYPE_LONG
#line 361 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::LONG);
}
#line 2054 "grammar/build/syntax.tab.cc"
    break;

  case 96: // type: TYPE_BYTE
#line 363 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::BYTE);
}
#line 2062 "grammar/build/syntax.tab.cc"
    break;

  case 97: // type: TYPE_STRING
#line 365 "grammar/syntax.y"
                {
  yylhs.value.as < Type* > () = new Type(TypeKind::STRING);
}
#line 2070 "grammar/build/syntax.tab.cc"
    break;

  case 98: // type: TYPE_CHAR
#line 367 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::CHAR);
}
#line 2078 "grammar/build/syntax.tab.cc"
    break;

  case 99: // type: TYPE_BOOL
#line 369 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::BOOL);
}
#line 2086 "grammar/build/syntax.tab.cc"
    break;

  case 100: // type: type LEFT_BRACKET RIGHT_BRACKET
#line 371 "grammar/syntax.y"
                                    {
  yylhs.value.as < Type* > () = new Type(TypeKind::ARRAY, yystack_[2].value.as < Type* > ());
}
#line 2094 "grammar/build/syntax.tab.cc"
    break;

  case 101: // type: TYPE_POINTER LT type GT
#line 373 "grammar/syntax.y"
                            {
  yylhs.value.as < Type* > () = new Type(TypeKind::POINTER, yystack_[1].value.as < Type* > ());
}
#line 2102 "grammar/build/syntax.tab.cc"
    break;

  case 102: // type: TYPE_OPTION LT type GT
#line 375 "grammar/syntax.y"
                           {
  yylhs.value.as < Type* > () = new Type(TypeKind::OPTION, yystack_[1].value.as < Type* > ());
}
#line 2110 "grammar/build/syntax.tab.cc"
    break;

  case 103: // assign: access ATTR expr
#line 379 "grammar/syntax.y"
                         {
  yylhs.value.as < Node* > () = new AssignNode(ctx.line, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2118 "grammar/build/syntax.tab.cc"
    break;

  case 104: // assign: access AND_ATTR expr
#line 381 "grammar/syntax.y"
                         {
  yylhs.value.as < Node* > () = new AssignNode(ctx.line, BinaryOperation::AND, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2126 "grammar/build/syntax.tab.cc"
    break;

  case 105: // assign: access OR_ATTR expr
#line 383 "grammar/syntax.y"
                        {
  yylhs.value.as < Node* > () = new AssignNode(ctx.line, BinaryOperation::OR, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2134 "grammar/build/syntax.tab.cc"
    break;

  case 106: // assign: access LAZY_AND_ATTR expr
#line 385 "grammar/syntax.y"
                              {
  yylhs.value.as < Node* > () = new AssignNode(ctx.line, BinaryOperation::BITWISE_AND, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2142 "grammar/build/syntax.tab.cc"
    break;

  case 107: // assign: access LAZY_OR_ATTR expr
#line 387 "grammar/syntax.y"
                             {
  yylhs.value.as < Node* > () = new AssignNode(ctx.line, BinaryOperation::BITWISE_OR, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2150 "grammar/build/syntax.tab.cc"
    break;

  case 108: // assign: access XOR_ATTR expr
#line 389 "grammar/syntax.y"
                         {
  yylhs.value.as < Node* > () = new AssignNode(ctx.line, BinaryOperation::XOR, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2158 "grammar/build/syntax.tab.cc"
    break;

  case 109: // assign: access CONCAT_ATTR expr
#line 391 "grammar/syntax.y"
                            {
  yylhs.value.as < Node* > () = new AssignNode(ctx.line, BinaryOperation::CONCAT, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2166 "grammar/build/syntax.tab.cc"
    break;

  case 110: // assign: access MOD_ATTR expr
#line 393 "grammar/syntax.y"
                         {
  yylhs.value.as < Node* > () = new AssignNode(ctx.line, BinaryOperation::MOD, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2174 "grammar/build/syntax.tab.cc"
    break;

  case 111: // assign: access PLUS_ATTR expr
#line 395 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = new AssignNode(ctx.line, BinaryOperation::PLUS, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2182 "grammar/build/syntax.tab.cc"
    break;

  case 112: // assign: access MINUS_ATTR expr
#line 397 "grammar/syntax.y"
                           {
  yylhs.value.as < Node* > () = new AssignNode(ctx.line, BinaryOperation::MINUS, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2190 "grammar/build/syntax.tab.cc"
    break;

  case 113: // assign: access MULT_ATTR expr
#line 399 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = new AssignNode(ctx.line, BinaryOperation::MULT, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2198 "grammar/build/syntax.tab.cc"
    break;

  case 114: // assign: access DIV_ATTR expr
#line 401 "grammar/syntax.y"
                         {
  yylhs.value.as < Node* > () = new AssignNode(ctx.line, BinaryOperation::DIV, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2206 "grammar/build/syntax.tab.cc"
    break;

  case 115: // if: IF expr THEN stmts if_end
#line 405 "grammar/syntax.y"
                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2214 "grammar/build/syntax.tab.cc"
    break;

  case 116: // if: IF SOME ID IN access THEN stmts if_end
#line 407 "grammar/syntax.y"
                                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2222 "grammar/build/syntax.tab.cc"
    break;

  case 117: // if_end: ELIF expr THEN stmts if_end
#line 411 "grammar/syntax.y"
                                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2230 "grammar/build/syntax.tab.cc"
    break;

  case 118: // if_end: ELIF SOME ID IN access THEN stmts if_end
#line 413 "grammar/syntax.y"
                                             {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2238 "grammar/build/syntax.tab.cc"
    break;

  case 119: // if_end: ELIF SOME IN access THEN stmts if_end
#line 415 "grammar/syntax.y"
                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2246 "grammar/build/syntax.tab.cc"
    break;

  case 120: // if_end: ELSE stmts END_IF
#line 417 "grammar/syntax.y"
                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2254 "grammar/build/syntax.tab.cc"
    break;

  case 121: // if_end: END_IF
#line 419 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2262 "grammar/build/syntax.tab.cc"
    break;

  case 122: // switch: SWITCH expr cases END_SWITCH
#line 423 "grammar/syntax.y"
                                     {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2270 "grammar/build/syntax.tab.cc"
    break;

  case 123: // cases: case_list default_case
#line 427 "grammar/syntax.y"
                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2278 "grammar/build/syntax.tab.cc"
    break;

  case 124: // cases: case_list
#line 429 "grammar/syntax.y"
              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2286 "grammar/build/syntax.tab.cc"
    break;

  case 125: // cases: default_case
#line 431 "grammar/syntax.y"
                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2294 "grammar/build/syntax.tab.cc"
    break;

  case 126: // case_list: case_list case
#line 435 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2302 "grammar/build/syntax.tab.cc"
    break;

  case 127: // case_list: case
#line 437 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2310 "grammar/build/syntax.tab.cc"
    break;

  case 128: // case: CASE case_values COLON stmts
#line 441 "grammar/syntax.y"
                                   {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2318 "grammar/build/syntax.tab.cc"
    break;

  case 129: // case: CASE SOME ID COLON stmts
#line 443 "grammar/syntax.y"
                             {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2326 "grammar/build/syntax.tab.cc"
    break;

  case 130: // case: CASE NONE COLON stmts
#line 445 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2334 "grammar/build/syntax.tab.cc"
    break;

  case 131: // case_values: case_values COMMA access
#line 449 "grammar/syntax.y"
                                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2342 "grammar/build/syntax.tab.cc"
    break;

  case 132: // case_values: access
#line 451 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2350 "grammar/build/syntax.tab.cc"
    break;

  case 133: // default_case: DEFAULT COLON stmts
#line 455 "grammar/syntax.y"
                                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2358 "grammar/build/syntax.tab.cc"
    break;

  case 134: // for: FOR LEFT_PAREN ID IN expr RIGHT_PAREN stmts END_FOR
#line 459 "grammar/syntax.y"
                                                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2366 "grammar/build/syntax.tab.cc"
    break;

  case 135: // for: FOR LEFT_PAREN ID IN expr RIGHT_PAREN END_FOR
#line 461 "grammar/syntax.y"
                                                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2374 "grammar/build/syntax.tab.cc"
    break;

  case 136: // for: FOR LEFT_PAREN attr SEMICOLON expr SEMICOLON expr RIGHT_PAREN stmts END_FOR
#line 463 "grammar/syntax.y"
                                                                                {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2382 "grammar/build/syntax.tab.cc"
    break;

  case 137: // for: FOR LEFT_PAREN attr SEMICOLON expr SEMICOLON expr RIGHT_PAREN END_FOR
#line 465 "grammar/syntax.y"
                                                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2390 "grammar/build/syntax.tab.cc"
    break;

  case 138: // while: WHILE LEFT_PAREN expr RIGHT_PAREN stmts END_WHILE
#line 469 "grammar/syntax.y"
                                                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2398 "grammar/build/syntax.tab.cc"
    break;

  case 139: // while: WHILE LEFT_PAREN expr RIGHT_PAREN END_WHILE
#line 471 "grammar/syntax.y"
                                                {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2406 "grammar/build/syntax.tab.cc"
    break;

  case 140: // repeat: REPEAT stmts UNTIL expr
#line 475 "grammar/syntax.y"
                                {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2414 "grammar/build/syntax.tab.cc"
    break;

  case 141: // repeat: REPEAT UNTIL expr
#line 477 "grammar/syntax.y"
                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2422 "grammar/build/syntax.tab.cc"
    break;

  case 142: // expr: or_expr
#line 481 "grammar/syntax.y"
              {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2430 "grammar/build/syntax.tab.cc"
    break;

  case 143: // expr: range_expr
#line 483 "grammar/syntax.y"
               {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2438 "grammar/build/syntax.tab.cc"
    break;

  case 144: // range_expr: range_interval or_expr
#line 487 "grammar/syntax.y"
                                   {
  yylhs.value.as < ExpressionNode* > () = nullptr;
}
#line 2446 "grammar/build/syntax.tab.cc"
    break;

  case 145: // range_expr: or_expr range_interval
#line 489 "grammar/syntax.y"
                           {
  yylhs.value.as < ExpressionNode* > () = nullptr;
}
#line 2454 "grammar/build/syntax.tab.cc"
    break;

  case 146: // range_expr: or_expr range_interval or_expr
#line 491 "grammar/syntax.y"
                                   {
  yylhs.value.as < ExpressionNode* > () = nullptr;
}
#line 2462 "grammar/build/syntax.tab.cc"
    break;

  case 147: // range_interval: RANGE
#line 495 "grammar/syntax.y"
                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2470 "grammar/build/syntax.tab.cc"
    break;

  case 148: // range_interval: RANGE_EXC
#line 497 "grammar/syntax.y"
              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2478 "grammar/build/syntax.tab.cc"
    break;

  case 149: // range_interval: RANGE_EXC_INC
#line 499 "grammar/syntax.y"
                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2486 "grammar/build/syntax.tab.cc"
    break;

  case 150: // range_interval: RANGE_INC
#line 501 "grammar/syntax.y"
              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2494 "grammar/build/syntax.tab.cc"
    break;

  case 151: // or_expr: or_expr OR and_expr
#line 505 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::OR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2502 "grammar/build/syntax.tab.cc"
    break;

  case 152: // or_expr: and_expr
#line 507 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2510 "grammar/build/syntax.tab.cc"
    break;

  case 153: // and_expr: and_expr AND bit_or_expr
#line 511 "grammar/syntax.y"
                                   {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::AND, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2518 "grammar/build/syntax.tab.cc"
    break;

  case 154: // and_expr: bit_or_expr
#line 513 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2526 "grammar/build/syntax.tab.cc"
    break;

  case 155: // bit_or_expr: bit_or_expr BAR bit_xor_expr
#line 517 "grammar/syntax.y"
                                          {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::BITWISE_OR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2534 "grammar/build/syntax.tab.cc"
    break;

  case 156: // bit_or_expr: bit_xor_expr
#line 519 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2542 "grammar/build/syntax.tab.cc"
    break;

  case 157: // bit_xor_expr: bit_xor_expr XOR bit_and_expr
#line 523 "grammar/syntax.y"
                                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::XOR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2550 "grammar/build/syntax.tab.cc"
    break;

  case 158: // bit_xor_expr: bit_and_expr
#line 525 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2558 "grammar/build/syntax.tab.cc"
    break;

  case 159: // bit_and_expr: bit_and_expr REF equals_expr
#line 529 "grammar/syntax.y"
                                           {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::BITWISE_AND, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2566 "grammar/build/syntax.tab.cc"
    break;

  case 160: // bit_and_expr: equals_expr
#line 531 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2574 "grammar/build/syntax.tab.cc"
    break;

  case 161: // equals_expr: equals_expr EQ rel_expr
#line 535 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2582 "grammar/build/syntax.tab.cc"
    break;

  case 162: // equals_expr: equals_expr NOT_EQ rel_expr
#line 537 "grammar/syntax.y"
                                {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::NOT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2590 "grammar/build/syntax.tab.cc"
    break;

  case 163: // equals_expr: rel_expr
#line 539 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2598 "grammar/build/syntax.tab.cc"
    break;

  case 164: // rel_expr: rel_expr LT concat_expr
#line 543 "grammar/syntax.y"
                                  {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::LT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2606 "grammar/build/syntax.tab.cc"
    break;

  case 165: // rel_expr: rel_expr GT concat_expr
#line 545 "grammar/syntax.y"
                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::GT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2614 "grammar/build/syntax.tab.cc"
    break;

  case 166: // rel_expr: rel_expr LT_EQ concat_expr
#line 547 "grammar/syntax.y"
                               {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::LT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2622 "grammar/build/syntax.tab.cc"
    break;

  case 167: // rel_expr: rel_expr GT_EQ concat_expr
#line 549 "grammar/syntax.y"
                               {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::GT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2630 "grammar/build/syntax.tab.cc"
    break;

  case 168: // rel_expr: rel_expr IN concat_expr
#line 551 "grammar/syntax.y"
                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::IN, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2638 "grammar/build/syntax.tab.cc"
    break;

  case 169: // rel_expr: concat_expr
#line 553 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2646 "grammar/build/syntax.tab.cc"
    break;

  case 170: // concat_expr: concat_expr CONCAT sum_expr
#line 557 "grammar/syntax.y"
                                         {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::CONCAT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2654 "grammar/build/syntax.tab.cc"
    break;

  case 171: // concat_expr: sum_expr
#line 559 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2662 "grammar/build/syntax.tab.cc"
    break;

  case 172: // sum_expr: sum_expr PLUS mult_expr
#line 563 "grammar/syntax.y"
                                  {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::PLUS, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2670 "grammar/build/syntax.tab.cc"
    break;

  case 173: // sum_expr: sum_expr MINUS mult_expr
#line 565 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MINUS, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2678 "grammar/build/syntax.tab.cc"
    break;

  case 174: // sum_expr: mult_expr
#line 567 "grammar/syntax.y"
              {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2686 "grammar/build/syntax.tab.cc"
    break;

  case 175: // mult_expr: mult_expr MULT unary_expr
#line 571 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MULT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2694 "grammar/build/syntax.tab.cc"
    break;

  case 176: // mult_expr: mult_expr DIV unary_expr
#line 573 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::DIV, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2702 "grammar/build/syntax.tab.cc"
    break;

  case 177: // mult_expr: mult_expr MOD unary_expr
#line 575 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MOD, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2710 "grammar/build/syntax.tab.cc"
    break;

  case 178: // mult_expr: unary_expr
#line 577 "grammar/syntax.y"
               {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2718 "grammar/build/syntax.tab.cc"
    break;

  case 179: // unary_expr: MINUS exp_expr
#line 581 "grammar/syntax.y"
                           {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::MINUS, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2726 "grammar/build/syntax.tab.cc"
    break;

  case 180: // unary_expr: REV exp_expr
#line 583 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::REV, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2734 "grammar/build/syntax.tab.cc"
    break;

  case 181: // unary_expr: NOT exp_expr
#line 585 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::NOT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2742 "grammar/build/syntax.tab.cc"
    break;

  case 182: // unary_expr: REF exp_expr
#line 587 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::REF, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2750 "grammar/build/syntax.tab.cc"
    break;

  case 183: // unary_expr: INCREMENT exp_expr
#line 589 "grammar/syntax.y"
                       {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::INCREMENT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2758 "grammar/build/syntax.tab.cc"
    break;

  case 184: // unary_expr: DECREMENT exp_expr
#line 591 "grammar/syntax.y"
                       {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::DECREMENT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2766 "grammar/build/syntax.tab.cc"
    break;

  case 185: // unary_expr: MULT exp_expr
#line 593 "grammar/syntax.y"
                  {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2774 "grammar/build/syntax.tab.cc"
    break;

  case 186: // unary_expr: exp_expr
#line 595 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2782 "grammar/build/syntax.tab.cc"
    break;

  case 187: // exp_expr: postfix_expr EXP exp_expr
#line 599 "grammar/syntax.y"
                                    {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::EXP, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2790 "grammar/build/syntax.tab.cc"
    break;

  case 188: // exp_expr: postfix_expr
#line 601 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2798 "grammar/build/syntax.tab.cc"
    break;

  case 189: // postfix_expr: term INCREMENT
#line 605 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(true, UnaryOperation::INCREMENT, yystack_[1].value.as < ExpressionNode* > ());
}
#line 2806 "grammar/build/syntax.tab.cc"
    break;

  case 190: // postfix_expr: term DECREMENT
#line 607 "grammar/syntax.y"
                   {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(true, UnaryOperation::DECREMENT, yystack_[1].value.as < ExpressionNode* > ());
}
#line 2814 "grammar/build/syntax.tab.cc"
    break;

  case 191: // postfix_expr: term
#line 609 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2822 "grammar/build/syntax.tab.cc"
    break;

  case 192: // term: INT
#line 613 "grammar/syntax.y"
          {
  yylhs.value.as < ExpressionNode* > () = new IntNode(ctx.line, yystack_[0].value.as < int32_t > ());
}
#line 2830 "grammar/build/syntax.tab.cc"
    break;

  case 193: // term: LONG
#line 615 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new LongNode(ctx.line, yystack_[0].value.as < int64_t > ());
}
#line 2838 "grammar/build/syntax.tab.cc"
    break;

  case 194: // term: FLOAT
#line 617 "grammar/syntax.y"
          {
  yylhs.value.as < ExpressionNode* > () = new FloatNode(ctx.line, yystack_[0].value.as < float > ());
}
#line 2846 "grammar/build/syntax.tab.cc"
    break;

  case 195: // term: DOUBLE
#line 619 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = new DoubleNode(ctx.line, yystack_[0].value.as < double > ());
}
#line 2854 "grammar/build/syntax.tab.cc"
    break;

  case 196: // term: BYTE
#line 621 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new ByteNode(ctx.line, yystack_[0].value.as < uint8_t > ());
}
#line 2862 "grammar/build/syntax.tab.cc"
    break;

  case 197: // term: BOOL
#line 623 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new BoolNode(ctx.line, yystack_[0].value.as < bool > ());
}
#line 2870 "grammar/build/syntax.tab.cc"
    break;

  case 198: // term: STRING
#line 625 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = new StringNode(ctx.line, yystack_[0].value.as < string > ());
}
#line 2878 "grammar/build/syntax.tab.cc"
    break;

  case 199: // term: CHAR
#line 627 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new CharNode(ctx.line, yystack_[0].value.as < char > ());
}
#line 2886 "grammar/build/syntax.tab.cc"
    break;

  case 200: // term: NONE
#line 629 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new OptionNode(ctx.line, Option());
}
#line 2894 "grammar/build/syntax.tab.cc"
    break;

  case 201: // term: array_allocation
#line 631 "grammar/syntax.y"
                     {
  yylhs.value.as < ExpressionNode* > () = nullptr;
}
#line 2902 "grammar/build/syntax.tab.cc"
    break;

  case 202: // term: struct_allocation
#line 633 "grammar/syntax.y"
                      {
  yylhs.value.as < ExpressionNode* > () = nullptr;
}
#line 2910 "grammar/build/syntax.tab.cc"
    break;

  case 203: // term: access
#line 635 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < AccessNode* > ();
}
#line 2918 "grammar/build/syntax.tab.cc"
    break;

  case 204: // term: SOME LEFT_PAREN expr RIGHT_PAREN
#line 637 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new OptionNode(ctx.line, Option());
}
#line 2926 "grammar/build/syntax.tab.cc"
    break;

  case 205: // array_allocation: NEW type LEFT_BRACKET expr RIGHT_BRACKET
#line 641 "grammar/syntax.y"
                                                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2934 "grammar/build/syntax.tab.cc"
    break;

  case 206: // array_allocation: NEW type LEFT_BRACKET expr RIGHT_BRACKET LEFT_BRACE array_allocation_values RIGHT_BRACE
#line 643 "grammar/syntax.y"
                                                                                            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2942 "grammar/build/syntax.tab.cc"
    break;

  case 207: // array_allocation_values: array_allocation_values COMMA expr
#line 647 "grammar/syntax.y"
                                                            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2950 "grammar/build/syntax.tab.cc"
    break;

  case 208: // array_allocation_values: expr
#line 649 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2958 "grammar/build/syntax.tab.cc"
    break;

  case 209: // struct_allocation: NEW type LEFT_BRACE struct_allocation_values RIGHT_BRACE
#line 653 "grammar/syntax.y"
                                                                            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2966 "grammar/build/syntax.tab.cc"
    break;

  case 210: // struct_allocation: NEW type LEFT_BRACE RIGHT_BRACE
#line 655 "grammar/syntax.y"
                                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2974 "grammar/build/syntax.tab.cc"
    break;

  case 211: // struct_allocation_values: struct_allocation_values COMMA ID COLON expr
#line 659 "grammar/syntax.y"
                                                                       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2982 "grammar/build/syntax.tab.cc"
    break;

  case 212: // struct_allocation_values: ID COLON expr
#line 661 "grammar/syntax.y"
                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2990 "grammar/build/syntax.tab.cc"
    break;


#line 2994 "grammar/build/syntax.tab.cc"

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
  "SELF", "IMPL", "END_IMPL", "TRAIT", "END_TRAIT", "RETURN", "$accept",
  "root", "program", "program_slice", "subprogram", "fn", "proc",
  "params_self_list", "params_list", "params", "param", "id_list",
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








  const short parser::yypact_ninf_ = -367;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     159,    21,    26,   252,   252,   252,   252,    85,   159,  -367,
    -367,  -367,  -367,  -367,  -367,  -367,  -367,    22,    22,  -367,
    -367,     0,    14,    66,   132,  -367,  -367,     6,    29,   634,
    -367,    56,   -44,  -367,    71,   206,    15,    92,   252,    57,
     164,   112,  -367,  -367,    69,  -367,  -367,  -367,   182,   195,
     138,  -367,  -367,   136,  -367,  -367,  -367,  -367,   -42,  -367,
     223,   432,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,
    -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,
     168,   174,   180,   180,   180,   180,   180,   180,   180,   432,
     233,   240,  -367,  -367,  -367,  -367,  2639,  2707,   181,   188,
     741,  -367,  -367,  2639,   190,  -367,   212,  -367,  2639,  -367,
      98,  -367,  -367,   848,   218,  -367,  -367,   104,  -367,  -367,
    -367,  -367,  -367,  -367,  -367,  -367,  2843,   116,   253,   260,
     254,   280,    31,     7,   283,   237,   103,  -367,  -367,   299,
     271,  -367,  -367,  -367,   316,   263,  -367,   320,   432,   265,
     266,  -367,   230,   268,   268,  -367,   252,   273,  -367,   268,
     268,  -367,   275,  -367,   337,  -367,   432,   955,   432,   432,
      25,  -367,  -367,  -367,  -367,  -367,  -367,  -367,   142,   281,
     282,   276,    17,   278,    19,  2639,  2639,  1062,   208,  2639,
    -367,  -367,  2639,  2639,  2639,  2639,  2639,  2639,  2639,  2639,
    2639,  2639,  2639,  2639,   234,   342,  2453,  2639,  -367,   290,
     291,  -367,   288,  -367,   321,  2843,  2843,  2843,  2843,  2843,
    2843,  2843,  2843,  2843,  2843,  2843,  2843,  2843,  2843,  2843,
    2843,  2843,  2843,  2843,   180,  -367,  -367,  -367,  -367,  -367,
     293,  -367,  -367,   294,    -1,   301,  1169,   267,  -367,   302,
     305,   277,  -367,  -367,   293,  1276,   -16,     1,  2546,    16,
     432,   432,  -367,   285,  2346,   287,   312,   311,  -367,  2639,
    2511,   317,   297,   208,  -367,  -367,   319,  -367,  -367,  -367,
    -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,
    -367,  -367,  -367,    75,  -367,   322,  -367,  -367,  -367,   253,
     321,   260,   254,   280,    31,     7,     7,   283,   283,   283,
     283,   283,   237,   103,   103,  -367,  -367,  -367,  -367,  -367,
     177,   432,   323,  1383,   325,   432,   432,   327,   328,  -367,
    -367,   329,   331,  -367,    73,    -3,    10,    24,   420,  2639,
    2639,  1490,  -367,   395,   338,    25,   244,  2346,  -367,  -367,
    -367,  -367,  2639,  -367,  -367,   337,  -367,   955,  -367,   339,
    -367,   -36,   527,  -367,  -367,   333,  2639,   403,  -367,  2639,
    2639,   140,  -367,  2775,  2346,  -367,   343,   347,  -367,  1597,
     350,  2346,    24,  2346,  2346,  -367,   185,  1704,  -367,   351,
     352,  2639,  -367,   364,  -367,  -367,  2346,    11,   341,  1811,
    1918,  2639,  -367,  2346,  2346,    25,  2346,  -367,   387,  -367,
    -367,  -367,   156,  2639,   420,   365,    24,  2346,  -367,  -367,
    2025,   386,  2346,  -367,  2639,  -367,  -367,  -367,    24,   141,
     420,  -367,  2132,  -367,   155,  2346,  -367,  -367,  2239,  2346,
     420,  -367,   420,  -367,  -367
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     2,     4,
       5,    10,    11,     6,     7,     8,     9,     0,     0,    74,
      75,     0,     0,     0,     0,     1,     3,     0,     0,     0,
      33,     0,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,    59,    62,     0,    55,    56,    57,     0,     0,
       0,    47,    49,     0,    42,    43,    44,    18,     0,    20,
       0,     0,   196,   192,   193,   194,   195,   197,    73,    72,
     198,   199,    96,    92,    95,    93,    94,    99,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   150,   148,   149,     0,     0,     0,     0,
       0,    78,    79,     0,     0,   200,     0,    69,     0,    67,
     203,    68,    70,     0,     0,    82,    80,     0,    81,    83,
      87,    84,    85,    86,    88,   143,     0,   142,   152,   154,
     156,   158,   160,   163,   169,   171,   174,   178,   186,   188,
     191,   201,   202,    31,     0,     0,    35,     0,     0,     0,
       0,    37,     0,     0,     0,    51,     0,     0,    54,     0,
       0,    40,     0,    41,     0,    17,     0,     0,     0,     0,
     203,   184,   183,   182,   181,   180,   179,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,    77,     0,    25,   144,     0,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   190,   189,    32,    30,    22,
      38,    34,    36,     0,     0,     0,     0,     0,    50,     0,
       0,     0,    39,    19,    21,     0,     0,     0,     0,     0,
       0,     0,    71,     0,     0,     0,     0,     0,   141,     0,
       0,     0,     0,   124,   127,   125,     0,   104,   105,   106,
     107,   110,   108,   111,   109,   112,   113,   114,   103,    64,
      63,    66,    27,     0,    29,     0,    13,    76,   100,   151,
     146,   153,   155,   157,   159,   161,   162,   166,   167,   164,
     165,   168,   170,   173,   172,   177,   175,   176,   187,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     102,     0,     0,   210,     0,     0,     0,     0,     0,     0,
       0,     0,   140,     0,     0,   132,     0,     0,   122,   126,
     123,   204,     0,    26,    65,     0,    16,     0,    61,     0,
      52,     0,     0,    48,    12,   205,     0,     0,   209,     0,
       0,     0,   121,     0,     0,   115,     0,     0,   139,     0,
       0,     0,     0,     0,   133,    28,     0,     0,    60,     0,
       0,     0,   212,     0,    90,    91,     0,     0,     0,     0,
       0,     0,   138,     0,   130,   131,   128,    15,     0,    45,
      46,   208,     0,     0,     0,     0,     0,     0,   120,   135,
       0,     0,   129,    58,     0,   206,   211,   116,     0,     0,
       0,   134,     0,   207,     0,     0,   117,   137,     0,     0,
       0,   136,     0,   119,   118
  };

  const short
  parser::yypgoto_[] =
  {
    -367,  -367,  -367,   451,  -367,    36,    99,   -92,    -4,   105,
     300,    50,  -367,   344,  -367,  -367,  -367,  -367,  -367,   427,
    -367,  -367,   412,  -367,  -367,  -367,  -367,   422,  -367,  -367,
     -29,  -367,  -367,    13,   -17,   -99,  -367,   284,   -24,  -367,
    -367,  -366,  -367,  -367,  -367,   194,  -367,   198,  -367,  -367,
    -367,   -87,  -367,   345,   -95,   258,   269,   257,   270,   272,
      95,    44,   249,    90,    45,   -81,  -367,  -367,  -367,  -367,
    -367,  -367
  };

  const short
  parser::yydefgoto_[] =
  {
       0,     7,     8,     9,    10,    11,    12,   245,    29,    58,
      59,    60,   109,   208,   293,    13,    32,    14,    36,    37,
      15,    53,    54,    55,    56,    16,    44,    45,    46,    47,
     170,   111,   112,    21,   255,   114,   115,   116,   117,   118,
     119,   375,   120,   272,   273,   274,   346,   275,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   412,
     142,   334
  };

  const short
  parser::yytable_[] =
  {
     110,   171,   172,   173,   174,   175,   176,   177,    33,   181,
     183,    30,   113,    28,   210,    33,   188,    22,    23,    24,
     415,   191,   144,    33,    33,   332,   263,   164,   265,   165,
      17,   214,   329,    68,    69,    18,   212,   167,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,   427,   330,
     369,   152,   223,   224,   225,   226,   212,   145,   221,    42,
      51,   389,   246,   370,   436,   178,   153,   249,   251,   212,
      57,   110,    35,   212,   443,   222,   444,    57,    90,    91,
      42,   189,   212,   187,   110,    25,    35,   189,   210,    51,
     204,   333,    27,   205,    96,   206,    61,   207,   267,   268,
     227,    31,   276,   320,   416,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,    34,   149,   294,
     295,   300,    43,    52,   240,   143,   192,   193,   107,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   110,   367,
     146,   352,   254,    43,   256,   257,   353,    38,   368,    28,
     156,   203,    52,   318,   231,   250,   210,   215,   110,   232,
     233,   151,    39,   204,    40,    39,   205,    40,   206,   247,
     207,   331,    41,   154,   206,   157,   212,    92,    93,    94,
      95,   155,   342,    62,    63,    64,    65,    66,    67,    68,
      69,   159,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,   160,   204,   204,   161,   205,   205,
     206,   206,   207,   207,   258,   168,   259,   110,   396,   435,
     204,   169,   424,   205,   210,   206,   110,   207,    48,   323,
      49,   425,    48,   439,    49,   110,   335,   336,    89,   210,
      50,   345,   179,   289,   162,   290,   355,   338,   356,   180,
      96,   184,   376,   377,   164,     1,   407,     2,   185,     3,
     189,     4,    19,    20,     5,   385,     6,   307,   308,   309,
     310,   311,   147,   148,   104,   105,   315,   316,   317,   392,
     210,   190,   394,   395,   107,   210,   398,   211,   210,   147,
     166,   229,   230,   217,   110,   235,   236,   357,   270,   271,
     210,   361,   362,   218,   411,   210,   219,   210,   371,   110,
     382,   383,   110,   228,   421,   210,   305,   306,   110,   313,
     314,   210,   220,   210,   379,   234,   426,   237,   110,   239,
     384,   210,   238,   110,   241,   242,   243,   433,   244,   210,
     387,   210,   248,   210,   252,   110,    33,   262,   260,   261,
     110,   291,   110,   405,   110,   110,   264,   399,   110,   296,
     297,   298,   215,   319,   404,   212,   406,   110,   321,   325,
     110,   110,   326,   324,   110,   110,   327,   110,   337,   414,
     339,   340,   341,   420,   347,   110,   422,   429,   110,   348,
     351,   110,   358,   110,   360,   354,   363,   364,   366,   434,
     430,   110,   365,   110,   380,   381,   110,   391,   388,   110,
     110,   110,   393,   110,   400,   438,   401,   403,   440,   417,
     409,   410,   442,    62,    63,    64,    65,    66,    67,    68,
      69,   413,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,   423,   432,   428,    26,
     386,   213,    84,   150,   253,   163,   158,   349,   266,    85,
      86,   350,   216,   299,    87,   302,    88,   312,    89,    90,
      91,    92,    93,    94,    95,     0,   301,     0,     0,   303,
      96,     0,   304,     0,     0,     0,    97,   372,     0,   373,
     374,    98,    99,     0,   100,     0,     0,   101,   102,   103,
       0,     0,     0,     0,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,   108,
      62,    63,    64,    65,    66,    67,    68,    69,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,    85,    86,     0,     0,
       0,    87,     0,    88,     0,    89,    90,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,    96,     0,   212,
       0,     0,     0,    97,     0,     0,     0,     0,    98,    99,
       0,   100,     0,     0,   101,   102,   103,     0,     0,     0,
       0,   104,   105,     0,   390,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,   108,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,    85,    86,     0,     0,     0,    87,     0,
      88,     0,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,    96,     0,     0,     0,     0,     0,
      97,     0,     0,     0,     0,    98,    99,     0,   100,     0,
       0,   101,   102,   103,     0,     0,     0,     0,   104,   105,
       0,     0,     0,   106,     0,     0,     0,     0,   107,     0,
       0,     0,     0,   108,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,     0,     0,     0,     0,     0,     0,
      85,    86,     0,     0,     0,    87,     0,    88,     0,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,    98,    99,     0,   100,   186,     0,   101,   102,
     103,     0,     0,     0,     0,   104,   105,     0,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
     108,    62,    63,    64,    65,    66,    67,    68,    69,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,    85,    86,     0,
       0,     0,    87,     0,    88,     0,    89,    90,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,    96,     0,
       0,     0,     0,     0,    97,     0,     0,     0,     0,    98,
      99,     0,   100,     0,     0,   101,   102,   103,     0,     0,
       0,     0,   104,   105,     0,     0,     0,   209,     0,     0,
       0,     0,   107,     0,     0,     0,     0,   108,    62,    63,
      64,    65,    66,    67,    68,    69,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,     0,
       0,     0,     0,     0,    85,    86,     0,     0,     0,    87,
       0,    88,     0,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,    96,     0,   212,     0,     0,
       0,    97,     0,     0,     0,     0,    98,    99,     0,   100,
       0,     0,   101,   102,   103,     0,     0,     0,     0,   104,
     105,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,   108,    62,    63,    64,    65,    66,
      67,    68,    69,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,    85,    86,     0,     0,     0,    87,     0,    88,     0,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,    96,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,    98,    99,     0,   100,   269,     0,   101,
     102,   103,     0,     0,     0,     0,   104,   105,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,     0,     0,
       0,   108,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,    85,    86,
       0,     0,     0,    87,     0,    88,     0,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
       0,     0,     0,     0,     0,    97,     0,     0,     0,     0,
      98,    99,     0,   100,     0,     0,   101,   102,   103,     0,
       0,     0,     0,   104,   105,     0,     0,     0,   322,     0,
       0,     0,     0,   107,     0,     0,     0,     0,   108,    62,
      63,    64,    65,    66,    67,    68,    69,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,    85,    86,     0,     0,     0,
      87,     0,    88,     0,    89,    90,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,    96,     0,     0,     0,
       0,     0,    97,     0,     0,     0,     0,    98,    99,     0,
     100,     0,     0,   101,   102,   103,     0,     0,     0,     0,
     104,   105,     0,   328,     0,     0,     0,     0,     0,     0,
     107,     0,     0,     0,     0,   108,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,    85,    86,     0,     0,     0,    87,     0,    88,
       0,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,     0,     0,     0,     0,     0,    97,
       0,     0,     0,     0,    98,    99,     0,   100,     0,     0,
     101,   102,   103,     0,     0,     0,     0,   104,   105,     0,
       0,     0,   359,     0,     0,     0,     0,   107,     0,     0,
       0,     0,   108,    62,    63,    64,    65,    66,    67,    68,
      69,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,    85,
      86,     0,     0,     0,    87,     0,    88,     0,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
      96,     0,     0,     0,     0,     0,    97,     0,     0,     0,
       0,    98,    99,   378,   100,     0,     0,   101,   102,   103,
       0,     0,     0,     0,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,   108,
      62,    63,    64,    65,    66,    67,    68,    69,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,    85,    86,     0,     0,
       0,    87,     0,    88,     0,    89,    90,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     0,     0,    97,     0,     0,     0,     0,    98,    99,
     402,   100,     0,     0,   101,   102,   103,     0,     0,     0,
       0,   104,   105,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,   108,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,    85,    86,     0,     0,     0,    87,     0,
      88,     0,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,    96,     0,     0,     0,     0,     0,
      97,     0,     0,     0,     0,    98,    99,     0,   100,     0,
       0,   101,   102,   103,     0,     0,     0,     0,   104,   105,
       0,   408,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     0,     0,   108,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,     0,     0,     0,     0,     0,     0,
      85,    86,     0,     0,     0,    87,     0,    88,     0,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     0,    97,   418,     0,
       0,     0,    98,    99,     0,   100,     0,     0,   101,   102,
     103,     0,     0,     0,     0,   104,   105,     0,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
     108,    62,    63,    64,    65,    66,    67,    68,    69,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,    85,    86,     0,
       0,     0,    87,     0,    88,     0,    89,    90,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,    96,     0,
       0,     0,     0,     0,    97,     0,     0,     0,     0,    98,
      99,     0,   100,     0,   419,   101,   102,   103,     0,     0,
       0,     0,   104,   105,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,     0,   108,    62,    63,
      64,    65,    66,    67,    68,    69,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,     0,
       0,     0,     0,     0,    85,    86,     0,     0,     0,    87,
       0,    88,     0,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,    96,     0,     0,     0,     0,
       0,    97,     0,     0,     0,     0,    98,    99,     0,   100,
       0,   431,   101,   102,   103,     0,     0,     0,     0,   104,
     105,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,   108,    62,    63,    64,    65,    66,
      67,    68,    69,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,    85,    86,     0,     0,     0,    87,     0,    88,     0,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,    96,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,    98,    99,     0,   100,     0,   437,   101,
     102,   103,     0,     0,     0,     0,   104,   105,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,     0,     0,
       0,   108,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,    85,    86,
       0,     0,     0,    87,     0,    88,     0,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
       0,     0,     0,     0,     0,    97,     0,     0,     0,     0,
      98,    99,     0,   100,     0,   441,   101,   102,   103,     0,
       0,     0,     0,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,     0,   108,    62,
      63,    64,    65,    66,    67,    68,    69,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,    85,    86,     0,     0,     0,
      87,     0,    88,     0,    89,    90,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,    96,     0,     0,     0,
       0,     0,    97,     0,     0,     0,     0,    98,    99,     0,
     100,     0,     0,   101,   102,   103,     0,     0,     0,     0,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
     107,     0,     0,     0,     0,   108,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,    85,    86,     0,     0,     0,    87,     0,    88,
       0,    89,     0,     0,    92,    93,    94,    95,     0,     0,
      68,    69,     0,    96,   292,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,    62,
      63,    64,    65,    66,    67,    68,    69,   107,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,    85,    86,     0,     0,     0,
      87,     0,    88,     0,    89,   343,   344,    92,    93,    94,
      95,     0,     0,     0,     0,   107,    96,     0,     0,   298,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,    62,    63,    64,    65,    66,    67,    68,    69,
     107,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,    85,    86,
       0,     0,     0,    87,     0,    88,     0,    89,     0,     0,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
      62,    63,    64,    65,    66,    67,    68,    69,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,    85,    86,     0,     0,
       0,    87,     0,    88,     0,    89,     0,     0,    92,    93,
      94,    95,     0,     0,     0,     0,     0,    96,    62,    63,
      64,    65,    66,    67,    68,    69,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,   182,   105,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,     0,    84,     0,     0,
       0,     0,     0,     0,    85,    86,     0,     0,     0,    87,
       0,    88,     0,    89,     0,     0,    92,    93,    94,    95,
       0,     0,     0,     0,     0,    96,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,   397,
     105,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,    85,    86,     0,     0,     0,    87,     0,    88,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,   107
  };

  const short
  parser::yycheck_[] =
  {
      29,    82,    83,    84,    85,    86,    87,    88,     9,    96,
      97,    11,    29,    17,   113,     9,   103,     4,     5,     6,
       9,   108,    66,     9,     9,     9,     9,    69,     9,    71,
       9,   126,    48,     9,    10,     9,    72,    61,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   414,    48,
      53,    38,    45,    46,    47,    48,    72,   101,    27,    23,
      24,    97,   154,    53,   430,    89,     9,   159,   160,    72,
      71,   100,    22,    72,   440,    44,   442,    71,    59,    60,
      44,    70,    72,   100,   113,     0,    36,    70,   187,    53,
      65,    75,    70,    68,    70,    70,    67,    72,   185,   186,
      93,   101,   189,   104,    93,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   103,   103,   206,
     207,   216,    23,    24,   148,    69,    28,    29,   104,    31,
      32,    33,    34,    35,    36,    37,    38,    39,   167,    66,
      69,    66,   166,    44,   168,   169,    71,    81,    75,   153,
      81,    53,    53,   234,    51,   159,   255,    41,   187,    56,
      57,    69,    96,    65,    98,    96,    68,    98,    70,   156,
      72,   258,   106,     9,    70,   106,    72,    61,    62,    63,
      64,    69,   269,     3,     4,     5,     6,     7,     8,     9,
      10,     9,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     9,    65,    65,    69,    68,    68,
      70,    70,    72,    72,    72,    47,    74,   246,    78,    78,
      65,    47,    66,    68,   323,    70,   255,    72,    96,   246,
      98,    75,    96,    78,    98,   264,   260,   261,    58,   338,
     108,   270,     9,     9,   108,    11,    69,   264,    71,     9,
      70,    70,   339,   340,    69,    96,    71,    98,    70,   100,
      70,   102,    10,    11,   105,   352,   107,   223,   224,   225,
     226,   227,    66,    67,    94,    95,   231,   232,   233,   366,
     379,    69,   369,   370,   104,   384,   373,    69,   387,    66,
      67,    54,    55,    40,   323,    24,    25,   321,    90,    91,
     399,   325,   326,    43,   391,   404,    52,   406,   337,   338,
      66,    67,   341,    30,   401,   414,   221,   222,   347,   229,
     230,   420,    42,   422,   341,    26,   413,    11,   357,     9,
     347,   430,    69,   362,    69,    69,   106,   424,    70,   438,
     357,   440,    69,   442,    69,   374,     9,    71,    67,    67,
     379,     9,   381,   382,   383,   384,    78,   374,   387,    69,
      69,    73,    41,    69,   381,    72,   383,   396,    67,    67,
     399,   400,    67,   106,   403,   404,    99,   406,    93,   396,
      93,    69,    71,   400,    67,   414,   403,   416,   417,    92,
      71,   420,    69,   422,    69,    73,    69,    69,    67,   428,
     417,   430,    73,   432,     9,    67,   435,    74,    69,   438,
     439,   440,     9,   442,    71,   432,    69,    67,   435,    78,
      69,    69,   439,     3,     4,     5,     6,     7,     8,     9,
      10,    67,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    69,    71,    93,     8,
     355,   117,    42,    36,   164,    53,    44,   273,   184,    49,
      50,   273,   127,   215,    54,   218,    56,   228,    58,    59,
      60,    61,    62,    63,    64,    -1,   217,    -1,    -1,   219,
      70,    -1,   220,    -1,    -1,    -1,    76,    77,    -1,    79,
      80,    81,    82,    -1,    84,    -1,    -1,    87,    88,    89,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,
      -1,    84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,
      -1,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,   109,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,
      -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    82,    -1,    84,    85,    -1,    87,    88,
      89,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
     109,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,
      82,    -1,    84,    -1,    -1,    87,    88,    89,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,   109,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,
      -1,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,   109,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    81,    82,    -1,    84,    85,    -1,    87,
      88,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,   109,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      81,    82,    -1,    84,    -1,    -1,    87,    88,    89,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,    -1,
      84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,   109,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,    -1,
      87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,   109,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    81,    82,    83,    84,    -1,    -1,    87,    88,    89,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,   109,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,
      -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    81,    82,    -1,    84,    -1,    -1,    87,    88,
      89,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
     109,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,
      82,    -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,   109,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,
      -1,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,   109,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    81,    82,    -1,    84,    -1,    86,    87,
      88,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,   109,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      81,    82,    -1,    84,    -1,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,    -1,
      84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,   109,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,
      -1,    58,    -1,    -1,    61,    62,    63,    64,    -1,    -1,
       9,    10,    -1,    70,    71,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,     3,
       4,     5,     6,     7,     8,     9,    10,   104,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    56,    -1,    58,    94,    95,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,   104,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,     3,     4,     5,     6,     7,     8,     9,    10,
     104,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    56,    -1,    58,    -1,    -1,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    56,    -1,    58,    -1,    -1,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,
      -1,    56,    -1,    58,    -1,    -1,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    96,    98,   100,   102,   105,   107,   111,   112,   113,
     114,   115,   116,   125,   127,   130,   135,     9,     9,    10,
      11,   143,   143,   143,   143,     0,   113,    70,   118,   118,
      11,   101,   126,     9,   103,   121,   128,   129,    81,    96,
      98,   106,   115,   116,   136,   137,   138,   139,    96,    98,
     108,   115,   116,   131,   132,   133,   134,    71,   119,   120,
     121,    67,     3,     4,     5,     6,     7,     8,     9,    10,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    42,    49,    50,    54,    56,    58,
      59,    60,    61,    62,    63,    64,    70,    76,    81,    82,
      84,    87,    88,    89,    94,    95,    99,   104,   109,   122,
     140,   141,   142,   144,   145,   146,   147,   148,   149,   150,
     152,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   180,    69,    66,   101,    69,    66,    67,   103,
     129,    69,   143,     9,     9,    69,    81,   106,   137,     9,
       9,    69,   108,   132,    69,    71,    67,   148,    47,    47,
     140,   175,   175,   175,   175,   175,   175,   175,   148,     9,
       9,   161,    94,   161,    70,    70,    85,   144,   161,    70,
      69,   161,    28,    29,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    53,    65,    68,    70,    72,   123,    99,
     145,    69,    72,   123,   164,    41,   163,    40,    43,    52,
      42,    27,    44,    45,    46,    47,    48,    93,    30,    54,
      55,    51,    56,    57,    26,    24,    25,    11,    69,     9,
     148,    69,    69,   106,    70,   117,   117,   143,    69,   117,
     118,   117,    69,   120,   148,   144,   148,   148,    72,    74,
      67,    67,    71,     9,    78,     9,   147,   161,   161,    85,
      90,    91,   153,   154,   155,   157,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,     9,
      11,     9,    71,   124,   161,   161,    69,    69,    73,   165,
     164,   166,   167,   168,   169,   170,   170,   171,   171,   171,
     171,   171,   172,   173,   173,   174,   174,   174,   175,    69,
     104,    67,    99,   144,   106,    67,    67,    99,    97,    48,
      48,   161,     9,    75,   181,   148,   148,    93,   144,    93,
      69,    71,   161,    94,    95,   140,   156,    67,    92,   155,
     157,    71,    66,    71,    73,    69,    71,   148,    69,    99,
      69,   148,   148,    69,    69,    73,    67,    66,    75,    53,
      53,   140,    77,    79,    80,   151,   161,   161,    83,   144,
       9,    67,    66,    67,   144,   161,   119,   144,    69,    97,
      97,    74,   161,     9,   161,   161,    78,    94,   161,   144,
      71,    69,    83,    67,   144,   140,   144,    71,    97,    69,
      69,   161,   179,    67,   144,     9,    93,    78,    77,    86,
     144,   161,   144,    69,    66,    75,   161,   151,    93,   140,
     144,    86,    71,   161,   140,    78,   151,    86,   144,    78,
     144,    86,   144,   151,   151
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   110,   111,   112,   112,   113,   113,   113,   113,   113,
     114,   114,   115,   116,   116,   117,   117,   118,   118,   119,
     119,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   129,   130,
     130,   131,   131,   132,   132,   133,   133,   133,   134,   134,
     135,   135,   135,   135,   136,   136,   137,   137,   138,   138,
     139,   139,   139,   140,   140,   140,   140,   140,   140,   141,
     141,   141,   142,   142,   143,   143,   144,   144,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   146,
     147,   147,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   150,   150,   151,   151,   151,
     151,   151,   152,   153,   153,   153,   154,   154,   155,   155,
     155,   156,   156,   157,   158,   158,   158,   158,   159,   159,
     160,   160,   161,   161,   162,   162,   162,   163,   163,   163,
     163,   164,   164,   165,   165,   166,   166,   167,   167,   168,
     168,   169,   169,   169,   170,   170,   170,   170,   170,   170,
     171,   171,   172,   172,   172,   173,   173,   173,   173,   174,
     174,   174,   174,   174,   174,   174,   174,   175,   175,   176,
     176,   176,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   178,   178,   179,   179,   180,
     180,   181,   181
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     8,     6,     5,     5,     3,     3,     2,     3,
       1,     3,     3,     1,     2,     2,     3,     2,     3,     1,
       5,     4,     3,     1,     5,     4,     3,     2,     3,     5,
       4,     2,     1,     1,     1,     7,     7,     1,     5,     1,
       5,     4,     7,     6,     2,     1,     1,     1,     8,     1,
       6,     5,     1,     3,     3,     4,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       6,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     8,     5,     8,     7,
       3,     1,     4,     2,     1,     1,     2,     1,     4,     5,
       4,     3,     1,     3,     8,     7,    10,     9,     6,     5,
       4,     3,     1,     1,     2,     2,     3,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     8,     3,     1,     5,
       4,     5,     3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    78,    78,    82,    85,    90,    92,    94,    96,    98,
     102,   104,   108,   115,   120,   124,   126,   130,   132,   136,
     141,   148,   155,   158,   163,   165,   169,   171,   175,   178,
     183,   185,   189,   191,   195,   197,   201,   203,   207,   211,
     213,   217,   219,   223,   225,   229,   231,   233,   237,   239,
     243,   245,   247,   249,   253,   255,   259,   261,   265,   267,
     271,   273,   275,   279,   281,   283,   285,   287,   289,   293,
     295,   297,   301,   303,   307,   309,   313,   316,   321,   323,
     325,   327,   329,   331,   333,   335,   337,   339,   341,   345,
     349,   351,   355,   357,   359,   361,   363,   365,   367,   369,
     371,   373,   375,   379,   381,   383,   385,   387,   389,   391,
     393,   395,   397,   399,   401,   405,   407,   411,   413,   415,
     417,   419,   423,   427,   429,   431,   435,   437,   441,   443,
     445,   449,   451,   455,   459,   461,   463,   465,   469,   471,
     475,   477,   481,   483,   487,   489,   491,   495,   497,   499,
     501,   505,   507,   511,   513,   517,   519,   523,   525,   529,
     531,   535,   537,   539,   543,   545,   547,   549,   551,   553,
     557,   559,   563,   565,   567,   571,   573,   575,   577,   581,
     583,   585,   587,   589,   591,   593,   595,   599,   601,   605,
     607,   609,   613,   615,   617,   619,   621,   623,   625,   627,
     629,   631,   633,   635,   637,   641,   643,   647,   649,   653,
     655,   659,   661
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
#line 4150 "grammar/build/syntax.tab.cc"

#line 664 "grammar/syntax.y"
