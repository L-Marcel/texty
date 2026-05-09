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

      case symbol_kind::S_assign: // assign
        value.YY_MOVE_OR_COPY< AssignNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attr: // attr
        value.YY_MOVE_OR_COPY< AttrNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
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

      case symbol_kind::S_for: // for
        value.YY_MOVE_OR_COPY< ForNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fn: // fn
        value.YY_MOVE_OR_COPY< FunctionNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_end: // if_end
        value.YY_MOVE_OR_COPY< IfEndNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if: // if
        value.YY_MOVE_OR_COPY< IfNode* > (YY_MOVE (that.value));
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
      case symbol_kind::S_switch: // switch
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_case: // case
      case symbol_kind::S_case_values: // case_values
      case symbol_kind::S_default_case: // default_case
      case symbol_kind::S_while: // while
      case symbol_kind::S_repeat: // repeat
      case symbol_kind::S_array_allocation: // array_allocation
      case symbol_kind::S_array_allocation_values: // array_allocation_values
      case symbol_kind::S_struct_allocation: // struct_allocation
      case symbol_kind::S_struct_allocation_values: // struct_allocation_values
        value.YY_MOVE_OR_COPY< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_proc: // proc
        value.YY_MOVE_OR_COPY< ProcedureNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_range_expr: // range_expr
        value.YY_MOVE_OR_COPY< RangeNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_return: // return
        value.YY_MOVE_OR_COPY< ReturnNode* > (YY_MOVE (that.value));
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

      case symbol_kind::S_range_interval: // range_interval
        value.YY_MOVE_OR_COPY< pair<RangeInclusionType, RangeInclusionType> > (YY_MOVE (that.value));
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

      case symbol_kind::S_assign: // assign
        value.move< AssignNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attr: // attr
        value.move< AttrNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
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

      case symbol_kind::S_for: // for
        value.move< ForNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fn: // fn
        value.move< FunctionNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_end: // if_end
        value.move< IfEndNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if: // if
        value.move< IfNode* > (YY_MOVE (that.value));
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
      case symbol_kind::S_switch: // switch
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_case: // case
      case symbol_kind::S_case_values: // case_values
      case symbol_kind::S_default_case: // default_case
      case symbol_kind::S_while: // while
      case symbol_kind::S_repeat: // repeat
      case symbol_kind::S_array_allocation: // array_allocation
      case symbol_kind::S_array_allocation_values: // array_allocation_values
      case symbol_kind::S_struct_allocation: // struct_allocation
      case symbol_kind::S_struct_allocation_values: // struct_allocation_values
        value.move< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_proc: // proc
        value.move< ProcedureNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_range_expr: // range_expr
        value.move< RangeNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_return: // return
        value.move< ReturnNode* > (YY_MOVE (that.value));
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

      case symbol_kind::S_range_interval: // range_interval
        value.move< pair<RangeInclusionType, RangeInclusionType> > (YY_MOVE (that.value));
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

      case symbol_kind::S_assign: // assign
        value.copy< AssignNode* > (that.value);
        break;

      case symbol_kind::S_attr: // attr
        value.copy< AttrNode* > (that.value);
        break;

      case symbol_kind::S_expr: // expr
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

      case symbol_kind::S_for: // for
        value.copy< ForNode* > (that.value);
        break;

      case symbol_kind::S_fn: // fn
        value.copy< FunctionNode* > (that.value);
        break;

      case symbol_kind::S_if_end: // if_end
        value.copy< IfEndNode* > (that.value);
        break;

      case symbol_kind::S_if: // if
        value.copy< IfNode* > (that.value);
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
      case symbol_kind::S_switch: // switch
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_case: // case
      case symbol_kind::S_case_values: // case_values
      case symbol_kind::S_default_case: // default_case
      case symbol_kind::S_while: // while
      case symbol_kind::S_repeat: // repeat
      case symbol_kind::S_array_allocation: // array_allocation
      case symbol_kind::S_array_allocation_values: // array_allocation_values
      case symbol_kind::S_struct_allocation: // struct_allocation
      case symbol_kind::S_struct_allocation_values: // struct_allocation_values
        value.copy< Node* > (that.value);
        break;

      case symbol_kind::S_proc: // proc
        value.copy< ProcedureNode* > (that.value);
        break;

      case symbol_kind::S_range_expr: // range_expr
        value.copy< RangeNode* > (that.value);
        break;

      case symbol_kind::S_return: // return
        value.copy< ReturnNode* > (that.value);
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

      case symbol_kind::S_range_interval: // range_interval
        value.copy< pair<RangeInclusionType, RangeInclusionType> > (that.value);
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

      case symbol_kind::S_assign: // assign
        value.move< AssignNode* > (that.value);
        break;

      case symbol_kind::S_attr: // attr
        value.move< AttrNode* > (that.value);
        break;

      case symbol_kind::S_expr: // expr
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

      case symbol_kind::S_for: // for
        value.move< ForNode* > (that.value);
        break;

      case symbol_kind::S_fn: // fn
        value.move< FunctionNode* > (that.value);
        break;

      case symbol_kind::S_if_end: // if_end
        value.move< IfEndNode* > (that.value);
        break;

      case symbol_kind::S_if: // if
        value.move< IfNode* > (that.value);
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
      case symbol_kind::S_switch: // switch
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_case: // case
      case symbol_kind::S_case_values: // case_values
      case symbol_kind::S_default_case: // default_case
      case symbol_kind::S_while: // while
      case symbol_kind::S_repeat: // repeat
      case symbol_kind::S_array_allocation: // array_allocation
      case symbol_kind::S_array_allocation_values: // array_allocation_values
      case symbol_kind::S_struct_allocation: // struct_allocation
      case symbol_kind::S_struct_allocation_values: // struct_allocation_values
        value.move< Node* > (that.value);
        break;

      case symbol_kind::S_proc: // proc
        value.move< ProcedureNode* > (that.value);
        break;

      case symbol_kind::S_range_expr: // range_expr
        value.move< RangeNode* > (that.value);
        break;

      case symbol_kind::S_return: // return
        value.move< ReturnNode* > (that.value);
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

      case symbol_kind::S_range_interval: // range_interval
        value.move< pair<RangeInclusionType, RangeInclusionType> > (that.value);
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

      case symbol_kind::S_assign: // assign
        yylhs.value.emplace< AssignNode* > ();
        break;

      case symbol_kind::S_attr: // attr
        yylhs.value.emplace< AttrNode* > ();
        break;

      case symbol_kind::S_expr: // expr
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

      case symbol_kind::S_for: // for
        yylhs.value.emplace< ForNode* > ();
        break;

      case symbol_kind::S_fn: // fn
        yylhs.value.emplace< FunctionNode* > ();
        break;

      case symbol_kind::S_if_end: // if_end
        yylhs.value.emplace< IfEndNode* > ();
        break;

      case symbol_kind::S_if: // if
        yylhs.value.emplace< IfNode* > ();
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
      case symbol_kind::S_switch: // switch
      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_case: // case
      case symbol_kind::S_case_values: // case_values
      case symbol_kind::S_default_case: // default_case
      case symbol_kind::S_while: // while
      case symbol_kind::S_repeat: // repeat
      case symbol_kind::S_array_allocation: // array_allocation
      case symbol_kind::S_array_allocation_values: // array_allocation_values
      case symbol_kind::S_struct_allocation: // struct_allocation
      case symbol_kind::S_struct_allocation_values: // struct_allocation_values
        yylhs.value.emplace< Node* > ();
        break;

      case symbol_kind::S_proc: // proc
        yylhs.value.emplace< ProcedureNode* > ();
        break;

      case symbol_kind::S_range_expr: // range_expr
        yylhs.value.emplace< RangeNode* > ();
        break;

      case symbol_kind::S_return: // return
        yylhs.value.emplace< ReturnNode* > ();
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

      case symbol_kind::S_range_interval: // range_interval
        yylhs.value.emplace< pair<RangeInclusionType, RangeInclusionType> > ();
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
#line 85 "grammar/syntax.y"
              {
  ctx.root = yystack_[0].value.as < Node* > ();
}
#line 1392 "grammar/build/syntax.tab.cc"
    break;

  case 3: // program: program program_slice
#line 89 "grammar/syntax.y"
                               {
  yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > ();
  yystack_[1].value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
}
#line 1401 "grammar/build/syntax.tab.cc"
    break;

  case 4: // program: program_slice
#line 92 "grammar/syntax.y"
                  {
  yylhs.value.as < Node* > () = new Node(ctx.line, "PROGRAM");
  yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
}
#line 1410 "grammar/build/syntax.tab.cc"
    break;

  case 5: // program_slice: subprogram
#line 97 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1418 "grammar/build/syntax.tab.cc"
    break;

  case 6: // program_slice: enum
#line 99 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1426 "grammar/build/syntax.tab.cc"
    break;

  case 7: // program_slice: struct
#line 101 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1434 "grammar/build/syntax.tab.cc"
    break;

  case 8: // program_slice: trait
#line 103 "grammar/syntax.y"
          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1442 "grammar/build/syntax.tab.cc"
    break;

  case 9: // program_slice: impl
#line 105 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1450 "grammar/build/syntax.tab.cc"
    break;

  case 10: // subprogram: fn
#line 109 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = yystack_[0].value.as < FunctionNode* > ();
}
#line 1458 "grammar/build/syntax.tab.cc"
    break;

  case 11: // subprogram: proc
#line 111 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ProcedureNode* > ();
}
#line 1466 "grammar/build/syntax.tab.cc"
    break;

  case 12: // fn: FUNCTION ID params_list COLON type stmts END_FUNCTION SEMICOLON
#line 115 "grammar/syntax.y"
                                                                    {
  yylhs.value.as < FunctionNode* > () = new FunctionNode(ctx.line, yystack_[6].value.as < string > (), *yystack_[3].value.as < Type* > (), yystack_[5].value.as < vector<Param> > ());
  for (size_t i = 0; i < yystack_[2].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < FunctionNode* > ()->children.push_back(yystack_[2].value.as < vector<Node*> > ()[i]);
  };
}
#line 1477 "grammar/build/syntax.tab.cc"
    break;

  case 13: // proc: PROCEDURE ID params_list stmts END_PROCEDURE SEMICOLON
#line 122 "grammar/syntax.y"
                                                             {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[4].value.as < string > (), yystack_[3].value.as < vector<Param> > ());
  for (size_t i = 0; i < yystack_[2].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < ProcedureNode* > ()->children.push_back(yystack_[2].value.as < vector<Node*> > ()[i]);
  };
}
#line 1488 "grammar/build/syntax.tab.cc"
    break;

  case 14: // proc: PROCEDURE ID params_list END_PROCEDURE SEMICOLON
#line 127 "grammar/syntax.y"
                                                     {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[3].value.as < string > (), yystack_[2].value.as < vector<Param> > ());
}
#line 1496 "grammar/build/syntax.tab.cc"
    break;

  case 15: // params_self_list: LEFT_PAREN SELF SEMICOLON params RIGHT_PAREN
#line 131 "grammar/syntax.y"
                                                               {
  yylhs.value.as < vector<Param> > () = yystack_[1].value.as < vector<Param> > ();
}
#line 1504 "grammar/build/syntax.tab.cc"
    break;

  case 16: // params_self_list: LEFT_PAREN SELF RIGHT_PAREN
#line 133 "grammar/syntax.y"
                                {
  yylhs.value.as < vector<Param> > () = vector<Param>();
}
#line 1512 "grammar/build/syntax.tab.cc"
    break;

  case 17: // params_list: LEFT_PAREN params RIGHT_PAREN
#line 137 "grammar/syntax.y"
                                           {
  yylhs.value.as < vector<Param> > () = yystack_[1].value.as < vector<Param> > ();
}
#line 1520 "grammar/build/syntax.tab.cc"
    break;

  case 18: // params_list: LEFT_PAREN RIGHT_PAREN
#line 139 "grammar/syntax.y"
                           {
  yylhs.value.as < vector<Param> > () = vector<Param>();
}
#line 1528 "grammar/build/syntax.tab.cc"
    break;

  case 19: // params: params SEMICOLON param
#line 143 "grammar/syntax.y"
                               {
  yylhs.value.as < vector<Param> > () = yystack_[2].value.as < vector<Param> > ();
  for (size_t i = 0; i < yystack_[0].value.as < vector<Param> > ().size(); i++) {
    yylhs.value.as < vector<Param> > ().push_back(yystack_[0].value.as < vector<Param> > ()[i]);
  };
}
#line 1539 "grammar/build/syntax.tab.cc"
    break;

  case 20: // params: param
#line 148 "grammar/syntax.y"
          {
  yylhs.value.as < vector<Param> > () = vector<Param>();
  for (size_t i = 0; i < yystack_[0].value.as < vector<Param> > ().size(); i++) {
    yylhs.value.as < vector<Param> > ().push_back(yystack_[0].value.as < vector<Param> > ()[i]);
  };
}
#line 1550 "grammar/build/syntax.tab.cc"
    break;

  case 21: // param: id_list COLON type
#line 155 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<Param> > () = vector<Param>();
  for (size_t i = 0; i < yystack_[2].value.as < vector<string> > ().size(); i++) {
    yylhs.value.as < vector<Param> > ().push_back({yystack_[2].value.as < vector<string> > ()[i], *yystack_[0].value.as < Type* > ()});
  };
}
#line 1561 "grammar/build/syntax.tab.cc"
    break;

  case 22: // id_list: id_list COMMA ID
#line 162 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<string> > () = yystack_[2].value.as < vector<string> > ();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < string > ());
}
#line 1570 "grammar/build/syntax.tab.cc"
    break;

  case 23: // id_list: ID
#line 165 "grammar/syntax.y"
       {
  yylhs.value.as < vector<string> > () = vector<string>();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < string > ());
}
#line 1579 "grammar/build/syntax.tab.cc"
    break;

  case 24: // subprogram_call: access call_params_list
#line 170 "grammar/syntax.y"
                                         {
  yylhs.value.as < SubprogramCallNode* > () = new SubprogramCallNode(ctx.line, yystack_[1].value.as < AccessNode* > (), yystack_[0].value.as < vector<ExpressionNode*> > ());
}
#line 1587 "grammar/build/syntax.tab.cc"
    break;

  case 25: // subprogram_call: type call_params_list
#line 172 "grammar/syntax.y"
                          {
  yylhs.value.as < SubprogramCallNode* > () = new SubprogramCallNode(ctx.line, *yystack_[1].value.as < Type* > (), yystack_[0].value.as < vector<ExpressionNode*> > ());
}
#line 1595 "grammar/build/syntax.tab.cc"
    break;

  case 26: // call_params_list: LEFT_PAREN call_params RIGHT_PAREN
#line 176 "grammar/syntax.y"
                                                     {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[1].value.as < vector<ExpressionNode*> > ();
}
#line 1603 "grammar/build/syntax.tab.cc"
    break;

  case 27: // call_params_list: LEFT_PAREN RIGHT_PAREN
#line 178 "grammar/syntax.y"
                           {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
}
#line 1611 "grammar/build/syntax.tab.cc"
    break;

  case 28: // call_params: call_params COMMA expr
#line 182 "grammar/syntax.y"
                                    {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[2].value.as < vector<ExpressionNode*> > ();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 1620 "grammar/build/syntax.tab.cc"
    break;

  case 29: // call_params: expr
#line 185 "grammar/syntax.y"
         {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 1629 "grammar/build/syntax.tab.cc"
    break;

  case 30: // enum: ENUM name enum_values END_ENUM SEMICOLON
#line 190 "grammar/syntax.y"
                                               {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1637 "grammar/build/syntax.tab.cc"
    break;

  case 31: // enum: ENUM name END_ENUM SEMICOLON
#line 192 "grammar/syntax.y"
                                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1645 "grammar/build/syntax.tab.cc"
    break;

  case 32: // enum_values: enum_values COMMA CONST_NAME
#line 196 "grammar/syntax.y"
                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1653 "grammar/build/syntax.tab.cc"
    break;

  case 33: // enum_values: CONST_NAME
#line 198 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1661 "grammar/build/syntax.tab.cc"
    break;

  case 34: // struct: STRUCT name struct_attrs END_STRUCT SEMICOLON
#line 202 "grammar/syntax.y"
                                                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1669 "grammar/build/syntax.tab.cc"
    break;

  case 35: // struct: STRUCT name END_STRUCT SEMICOLON
#line 204 "grammar/syntax.y"
                                     {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1677 "grammar/build/syntax.tab.cc"
    break;

  case 36: // struct_attrs: struct_attrs struct_attr SEMICOLON
#line 208 "grammar/syntax.y"
                                                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1685 "grammar/build/syntax.tab.cc"
    break;

  case 37: // struct_attrs: struct_attr SEMICOLON
#line 210 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1693 "grammar/build/syntax.tab.cc"
    break;

  case 38: // struct_attr: id_list COLON type
#line 214 "grammar/syntax.y"
                                {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1701 "grammar/build/syntax.tab.cc"
    break;

  case 39: // trait: TRAIT name trait_subprograms END_TRAIT SEMICOLON
#line 218 "grammar/syntax.y"
                                                        {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1709 "grammar/build/syntax.tab.cc"
    break;

  case 40: // trait: TRAIT name END_TRAIT SEMICOLON
#line 220 "grammar/syntax.y"
                                   {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1717 "grammar/build/syntax.tab.cc"
    break;

  case 41: // trait_subprograms: trait_subprograms trait_subprogram
#line 224 "grammar/syntax.y"
                                                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1725 "grammar/build/syntax.tab.cc"
    break;

  case 42: // trait_subprograms: trait_subprogram
#line 226 "grammar/syntax.y"
                     {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1733 "grammar/build/syntax.tab.cc"
    break;

  case 43: // trait_subprogram: trait_fn
#line 230 "grammar/syntax.y"
                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1741 "grammar/build/syntax.tab.cc"
    break;

  case 44: // trait_subprogram: trait_proc
#line 232 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1749 "grammar/build/syntax.tab.cc"
    break;

  case 45: // trait_fn: FUNCTION ID params_self_list COLON type END_FUNCTION SEMICOLON
#line 236 "grammar/syntax.y"
                                                                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1757 "grammar/build/syntax.tab.cc"
    break;

  case 46: // trait_fn: FUNCTION ID params_list COLON type END_FUNCTION SEMICOLON
#line 238 "grammar/syntax.y"
                                                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1765 "grammar/build/syntax.tab.cc"
    break;

  case 47: // trait_fn: fn
#line 240 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1773 "grammar/build/syntax.tab.cc"
    break;

  case 48: // trait_proc: PROCEDURE ID params_self_list END_PROCEDURE SEMICOLON
#line 244 "grammar/syntax.y"
                                                                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1781 "grammar/build/syntax.tab.cc"
    break;

  case 49: // trait_proc: proc
#line 246 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1789 "grammar/build/syntax.tab.cc"
    break;

  case 50: // impl: IMPL name impl_subprograms END_IMPL SEMICOLON
#line 250 "grammar/syntax.y"
                                                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1797 "grammar/build/syntax.tab.cc"
    break;

  case 51: // impl: IMPL name END_IMPL SEMICOLON
#line 252 "grammar/syntax.y"
                                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1805 "grammar/build/syntax.tab.cc"
    break;

  case 52: // impl: IMPL name impl_subprograms FOR name END_IMPL SEMICOLON
#line 254 "grammar/syntax.y"
                                                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1813 "grammar/build/syntax.tab.cc"
    break;

  case 53: // impl: IMPL name FOR name END_IMPL SEMICOLON
#line 256 "grammar/syntax.y"
                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1821 "grammar/build/syntax.tab.cc"
    break;

  case 54: // impl_subprograms: impl_subprograms impl_subprogram
#line 260 "grammar/syntax.y"
                                                   {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1829 "grammar/build/syntax.tab.cc"
    break;

  case 55: // impl_subprograms: impl_subprogram
#line 262 "grammar/syntax.y"
                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1837 "grammar/build/syntax.tab.cc"
    break;

  case 56: // impl_subprogram: impl_fn
#line 266 "grammar/syntax.y"
                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1845 "grammar/build/syntax.tab.cc"
    break;

  case 57: // impl_subprogram: impl_proc
#line 268 "grammar/syntax.y"
              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1853 "grammar/build/syntax.tab.cc"
    break;

  case 58: // impl_fn: FUNCTION ID params_self_list COLON type stmts END_FUNCTION SEMICOLON
#line 272 "grammar/syntax.y"
                                                                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1861 "grammar/build/syntax.tab.cc"
    break;

  case 59: // impl_fn: fn
#line 274 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1869 "grammar/build/syntax.tab.cc"
    break;

  case 60: // impl_proc: PROCEDURE ID params_self_list stmts END_PROCEDURE SEMICOLON
#line 278 "grammar/syntax.y"
                                                                       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1877 "grammar/build/syntax.tab.cc"
    break;

  case 61: // impl_proc: PROCEDURE ID params_self_list END_PROCEDURE SEMICOLON
#line 280 "grammar/syntax.y"
                                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1885 "grammar/build/syntax.tab.cc"
    break;

  case 62: // impl_proc: proc
#line 282 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1893 "grammar/build/syntax.tab.cc"
    break;

  case 63: // access: access DOT CONST_NAME
#line 286 "grammar/syntax.y"
                              {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < string > (), yystack_[2].value.as < AccessNode* > (), AccessType::DOT);
}
#line 1901 "grammar/build/syntax.tab.cc"
    break;

  case 64: // access: access DOT ID
#line 288 "grammar/syntax.y"
                  {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < string > (), yystack_[2].value.as < AccessNode* > (), AccessType::DOT);
}
#line 1909 "grammar/build/syntax.tab.cc"
    break;

  case 65: // access: access LEFT_BRACKET expr RIGHT_BRACKET
#line 290 "grammar/syntax.y"
                                           {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[3].value.as < AccessNode* > (), yystack_[1].value.as < ExpressionNode* > ());
}
#line 1917 "grammar/build/syntax.tab.cc"
    break;

  case 66: // access: access DOUBLE_COLON ID
#line 292 "grammar/syntax.y"
                           {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < string > (), yystack_[2].value.as < AccessNode* > (), AccessType::STATIC);
}
#line 1925 "grammar/build/syntax.tab.cc"
    break;

  case 67: // access: subprogram_call
#line 294 "grammar/syntax.y"
                    {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < SubprogramCallNode* > ());
}
#line 1933 "grammar/build/syntax.tab.cc"
    break;

  case 68: // access: access_base
#line 296 "grammar/syntax.y"
                {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < AccessBaseNode* > ());
}
#line 1941 "grammar/build/syntax.tab.cc"
    break;

  case 69: // access_base: SELF
#line 300 "grammar/syntax.y"
                  {
  yylhs.value.as < AccessBaseNode* > () = new AccessBaseNode(ctx.line);
}
#line 1949 "grammar/build/syntax.tab.cc"
    break;

  case 70: // access_base: id
#line 302 "grammar/syntax.y"
       {
  yylhs.value.as < AccessBaseNode* > () = new AccessBaseNode(ctx.line, yystack_[0].value.as < string > ());
}
#line 1957 "grammar/build/syntax.tab.cc"
    break;

  case 71: // access_base: LEFT_PAREN expr RIGHT_PAREN
#line 304 "grammar/syntax.y"
                                {
  yylhs.value.as < AccessBaseNode* > () = new AccessBaseNode(ctx.line, yystack_[1].value.as < ExpressionNode* > ());
}
#line 1965 "grammar/build/syntax.tab.cc"
    break;

  case 72: // id: NAME
#line 308 "grammar/syntax.y"
         {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 1973 "grammar/build/syntax.tab.cc"
    break;

  case 73: // id: ID
#line 310 "grammar/syntax.y"
       {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 1981 "grammar/build/syntax.tab.cc"
    break;

  case 74: // name: NAME
#line 314 "grammar/syntax.y"
           {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 1989 "grammar/build/syntax.tab.cc"
    break;

  case 75: // name: CONST_NAME
#line 316 "grammar/syntax.y"
               {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 1997 "grammar/build/syntax.tab.cc"
    break;

  case 76: // stmts: stmts stmt SEMICOLON
#line 320 "grammar/syntax.y"
                            {
  yylhs.value.as < vector<Node*> > () = yystack_[2].value.as < vector<Node*> > ();
  yylhs.value.as < vector<Node*> > ().push_back(yystack_[1].value.as < Node* > ());
}
#line 2006 "grammar/build/syntax.tab.cc"
    break;

  case 77: // stmts: stmt SEMICOLON
#line 323 "grammar/syntax.y"
                   {
  yylhs.value.as < vector<Node*> > () = vector<Node*>();
  yylhs.value.as < vector<Node*> > ().push_back(yystack_[1].value.as < Node* > ());
}
#line 2015 "grammar/build/syntax.tab.cc"
    break;

  case 78: // stmt: BREAK
#line 328 "grammar/syntax.y"
            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2023 "grammar/build/syntax.tab.cc"
    break;

  case 79: // stmt: CONTINUE
#line 330 "grammar/syntax.y"
             {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2031 "grammar/build/syntax.tab.cc"
    break;

  case 80: // stmt: attr
#line 332 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < AttrNode* > ();
}
#line 2039 "grammar/build/syntax.tab.cc"
    break;

  case 81: // stmt: assign
#line 334 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < AssignNode* > ();
}
#line 2047 "grammar/build/syntax.tab.cc"
    break;

  case 82: // stmt: return
#line 336 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ReturnNode* > ();
}
#line 2055 "grammar/build/syntax.tab.cc"
    break;

  case 83: // stmt: if
#line 338 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = yystack_[0].value.as < IfNode* > ();
}
#line 2063 "grammar/build/syntax.tab.cc"
    break;

  case 84: // stmt: for
#line 340 "grammar/syntax.y"
        {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ForNode* > ();
}
#line 2071 "grammar/build/syntax.tab.cc"
    break;

  case 85: // stmt: while
#line 342 "grammar/syntax.y"
          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 2079 "grammar/build/syntax.tab.cc"
    break;

  case 86: // stmt: repeat
#line 344 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 2087 "grammar/build/syntax.tab.cc"
    break;

  case 87: // stmt: switch
#line 346 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 2095 "grammar/build/syntax.tab.cc"
    break;

  case 88: // stmt: expr
#line 348 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2103 "grammar/build/syntax.tab.cc"
    break;

  case 89: // return: RETURN expr
#line 352 "grammar/syntax.y"
                    {
  yylhs.value.as < ReturnNode* > () = new ReturnNode(ctx.line, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2111 "grammar/build/syntax.tab.cc"
    break;

  case 90: // attr: VAR ID COLON type ATTR expr
#line 356 "grammar/syntax.y"
                                  {
  yylhs.value.as < AttrNode* > () = new AttrNode(ctx.line, yystack_[4].value.as < string > (), false, *yystack_[2].value.as < Type* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2119 "grammar/build/syntax.tab.cc"
    break;

  case 91: // attr: CONST ID COLON type ATTR expr
#line 358 "grammar/syntax.y"
                                  {
  yylhs.value.as < AttrNode* > () = new AttrNode(ctx.line, yystack_[4].value.as < string > (), true, *yystack_[2].value.as < Type* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2127 "grammar/build/syntax.tab.cc"
    break;

  case 92: // type: TYPE_INT
#line 362 "grammar/syntax.y"
               {
  yylhs.value.as < Type* > () = new Type(TypeKind::INT);
}
#line 2135 "grammar/build/syntax.tab.cc"
    break;

  case 93: // type: TYPE_FLOAT
#line 364 "grammar/syntax.y"
               {
  yylhs.value.as < Type* > () = new Type(TypeKind::FLOAT);
}
#line 2143 "grammar/build/syntax.tab.cc"
    break;

  case 94: // type: TYPE_DOUBLE
#line 366 "grammar/syntax.y"
                {
  yylhs.value.as < Type* > () = new Type(TypeKind::DOUBLE);
}
#line 2151 "grammar/build/syntax.tab.cc"
    break;

  case 95: // type: TYPE_LONG
#line 368 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::LONG);
}
#line 2159 "grammar/build/syntax.tab.cc"
    break;

  case 96: // type: TYPE_BYTE
#line 370 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::BYTE);
}
#line 2167 "grammar/build/syntax.tab.cc"
    break;

  case 97: // type: TYPE_STRING
#line 372 "grammar/syntax.y"
                {
  yylhs.value.as < Type* > () = new Type(TypeKind::STRING);
}
#line 2175 "grammar/build/syntax.tab.cc"
    break;

  case 98: // type: TYPE_CHAR
#line 374 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::CHAR);
}
#line 2183 "grammar/build/syntax.tab.cc"
    break;

  case 99: // type: TYPE_BOOL
#line 376 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::BOOL);
}
#line 2191 "grammar/build/syntax.tab.cc"
    break;

  case 100: // type: type LEFT_BRACKET RIGHT_BRACKET
#line 378 "grammar/syntax.y"
                                    {
  yylhs.value.as < Type* > () = new Type(TypeKind::ARRAY, yystack_[2].value.as < Type* > ());
}
#line 2199 "grammar/build/syntax.tab.cc"
    break;

  case 101: // type: TYPE_POINTER LT type GT
#line 380 "grammar/syntax.y"
                            {
  yylhs.value.as < Type* > () = new Type(TypeKind::POINTER, yystack_[1].value.as < Type* > ());
}
#line 2207 "grammar/build/syntax.tab.cc"
    break;

  case 102: // type: TYPE_OPTION LT type GT
#line 382 "grammar/syntax.y"
                           {
  yylhs.value.as < Type* > () = new Type(TypeKind::OPTION, yystack_[1].value.as < Type* > ());
}
#line 2215 "grammar/build/syntax.tab.cc"
    break;

  case 103: // assign: access ATTR expr
#line 386 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2223 "grammar/build/syntax.tab.cc"
    break;

  case 104: // assign: access AND_ATTR expr
#line 388 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::AND, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2231 "grammar/build/syntax.tab.cc"
    break;

  case 105: // assign: access OR_ATTR expr
#line 390 "grammar/syntax.y"
                        {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::OR, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2239 "grammar/build/syntax.tab.cc"
    break;

  case 106: // assign: access LAZY_AND_ATTR expr
#line 392 "grammar/syntax.y"
                              {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::BITWISE_AND, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2247 "grammar/build/syntax.tab.cc"
    break;

  case 107: // assign: access LAZY_OR_ATTR expr
#line 394 "grammar/syntax.y"
                             {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::BITWISE_OR, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2255 "grammar/build/syntax.tab.cc"
    break;

  case 108: // assign: access XOR_ATTR expr
#line 396 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::XOR, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2263 "grammar/build/syntax.tab.cc"
    break;

  case 109: // assign: access CONCAT_ATTR expr
#line 398 "grammar/syntax.y"
                            {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::CONCAT, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2271 "grammar/build/syntax.tab.cc"
    break;

  case 110: // assign: access MOD_ATTR expr
#line 400 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::MOD, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2279 "grammar/build/syntax.tab.cc"
    break;

  case 111: // assign: access PLUS_ATTR expr
#line 402 "grammar/syntax.y"
                          {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::PLUS, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2287 "grammar/build/syntax.tab.cc"
    break;

  case 112: // assign: access MINUS_ATTR expr
#line 404 "grammar/syntax.y"
                           {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::MINUS, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2295 "grammar/build/syntax.tab.cc"
    break;

  case 113: // assign: access MULT_ATTR expr
#line 406 "grammar/syntax.y"
                          {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::MULT, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2303 "grammar/build/syntax.tab.cc"
    break;

  case 114: // assign: access DIV_ATTR expr
#line 408 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::DIV, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2311 "grammar/build/syntax.tab.cc"
    break;

  case 115: // if: IF expr THEN stmts if_end
#line 412 "grammar/syntax.y"
                              {
  yylhs.value.as < IfNode* > () = new IfNode(ctx.line, yystack_[3].value.as < ExpressionNode* > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2322 "grammar/build/syntax.tab.cc"
    break;

  case 116: // if: IF SOME ID IN access THEN stmts if_end
#line 417 "grammar/syntax.y"
                                           {
  yylhs.value.as < IfNode* > () = new IfNode(ctx.line, yystack_[3].value.as < AccessNode* > (), yystack_[5].value.as < string > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2333 "grammar/build/syntax.tab.cc"
    break;

  case 117: // if_end: ELIF expr THEN stmts if_end
#line 424 "grammar/syntax.y"
                                    {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line, yystack_[3].value.as < ExpressionNode* > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfEndNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2344 "grammar/build/syntax.tab.cc"
    break;

  case 118: // if_end: ELIF SOME ID IN access THEN stmts if_end
#line 429 "grammar/syntax.y"
                                             {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line, yystack_[3].value.as < AccessNode* > (), yystack_[5].value.as < string > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfEndNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2355 "grammar/build/syntax.tab.cc"
    break;

  case 119: // if_end: ELSE stmts END_IF
#line 434 "grammar/syntax.y"
                      {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line, new IfEndNode(ctx.line));
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfEndNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2366 "grammar/build/syntax.tab.cc"
    break;

  case 120: // if_end: END_IF
#line 439 "grammar/syntax.y"
           {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line);
}
#line 2374 "grammar/build/syntax.tab.cc"
    break;

  case 121: // switch: SWITCH expr cases END_SWITCH
#line 443 "grammar/syntax.y"
                                     {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2382 "grammar/build/syntax.tab.cc"
    break;

  case 122: // cases: case_list default_case
#line 447 "grammar/syntax.y"
                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2390 "grammar/build/syntax.tab.cc"
    break;

  case 123: // cases: case_list
#line 449 "grammar/syntax.y"
              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2398 "grammar/build/syntax.tab.cc"
    break;

  case 124: // cases: default_case
#line 451 "grammar/syntax.y"
                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2406 "grammar/build/syntax.tab.cc"
    break;

  case 125: // case_list: case_list case
#line 455 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2414 "grammar/build/syntax.tab.cc"
    break;

  case 126: // case_list: case
#line 457 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2422 "grammar/build/syntax.tab.cc"
    break;

  case 127: // case: CASE case_values COLON stmts
#line 461 "grammar/syntax.y"
                                   {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2430 "grammar/build/syntax.tab.cc"
    break;

  case 128: // case: CASE SOME ID COLON stmts
#line 463 "grammar/syntax.y"
                             {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2438 "grammar/build/syntax.tab.cc"
    break;

  case 129: // case: CASE NONE COLON stmts
#line 465 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2446 "grammar/build/syntax.tab.cc"
    break;

  case 130: // case_values: case_values COMMA access
#line 469 "grammar/syntax.y"
                                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2454 "grammar/build/syntax.tab.cc"
    break;

  case 131: // case_values: access
#line 471 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2462 "grammar/build/syntax.tab.cc"
    break;

  case 132: // default_case: DEFAULT COLON stmts
#line 475 "grammar/syntax.y"
                                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2470 "grammar/build/syntax.tab.cc"
    break;

  case 133: // for: FOR LEFT_PAREN ID IN expr RIGHT_PAREN stmts END_FOR
#line 479 "grammar/syntax.y"
                                                         {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[5].value.as < string > (), yystack_[3].value.as < ExpressionNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < ForNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2481 "grammar/build/syntax.tab.cc"
    break;

  case 134: // for: FOR LEFT_PAREN ID IN expr RIGHT_PAREN END_FOR
#line 484 "grammar/syntax.y"
                                                  {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[4].value.as < string > (), yystack_[2].value.as < ExpressionNode* > ());
}
#line 2489 "grammar/build/syntax.tab.cc"
    break;

  case 135: // for: FOR LEFT_PAREN attr SEMICOLON expr SEMICOLON expr RIGHT_PAREN stmts END_FOR
#line 486 "grammar/syntax.y"
                                                                                {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[7].value.as < AttrNode* > (), yystack_[5].value.as < ExpressionNode* > (), yystack_[3].value.as < ExpressionNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < ForNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2500 "grammar/build/syntax.tab.cc"
    break;

  case 136: // for: FOR LEFT_PAREN attr SEMICOLON expr SEMICOLON expr RIGHT_PAREN END_FOR
#line 491 "grammar/syntax.y"
                                                                          {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[6].value.as < AttrNode* > (), yystack_[4].value.as < ExpressionNode* > (), yystack_[2].value.as < ExpressionNode* > ());
}
#line 2508 "grammar/build/syntax.tab.cc"
    break;

  case 137: // while: WHILE LEFT_PAREN expr RIGHT_PAREN stmts END_WHILE
#line 495 "grammar/syntax.y"
                                                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2516 "grammar/build/syntax.tab.cc"
    break;

  case 138: // while: WHILE LEFT_PAREN expr RIGHT_PAREN END_WHILE
#line 497 "grammar/syntax.y"
                                                {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2524 "grammar/build/syntax.tab.cc"
    break;

  case 139: // repeat: REPEAT stmts UNTIL expr
#line 501 "grammar/syntax.y"
                                {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2532 "grammar/build/syntax.tab.cc"
    break;

  case 140: // repeat: REPEAT UNTIL expr
#line 503 "grammar/syntax.y"
                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2540 "grammar/build/syntax.tab.cc"
    break;

  case 141: // expr: or_expr
#line 507 "grammar/syntax.y"
              {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2548 "grammar/build/syntax.tab.cc"
    break;

  case 142: // expr: range_expr
#line 509 "grammar/syntax.y"
               {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < RangeNode* > ();
}
#line 2556 "grammar/build/syntax.tab.cc"
    break;

  case 143: // range_expr: range_interval or_expr
#line 513 "grammar/syntax.y"
                                   {
  yylhs.value.as < RangeNode* > () = new RangeNode(ctx.line, false, yystack_[0].value.as < ExpressionNode* > (), yystack_[1].value.as < pair<RangeInclusionType, RangeInclusionType> > ().second);
}
#line 2564 "grammar/build/syntax.tab.cc"
    break;

  case 144: // range_expr: or_expr range_interval
#line 515 "grammar/syntax.y"
                           {
  yylhs.value.as < RangeNode* > () = new RangeNode(ctx.line, true, yystack_[1].value.as < ExpressionNode* > (), yystack_[0].value.as < pair<RangeInclusionType, RangeInclusionType> > ().first);
}
#line 2572 "grammar/build/syntax.tab.cc"
    break;

  case 145: // range_expr: or_expr range_interval or_expr
#line 517 "grammar/syntax.y"
                                   {
  yylhs.value.as < RangeNode* > () = new RangeNode(ctx.line, yystack_[2].value.as < ExpressionNode* > (), yystack_[1].value.as < pair<RangeInclusionType, RangeInclusionType> > ().first, yystack_[0].value.as < ExpressionNode* > (), yystack_[1].value.as < pair<RangeInclusionType, RangeInclusionType> > ().second);
}
#line 2580 "grammar/build/syntax.tab.cc"
    break;

  case 146: // range_interval: RANGE
#line 521 "grammar/syntax.y"
                      {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::INCLUSIVE, RangeInclusionType::EXCLUSIVE};
}
#line 2588 "grammar/build/syntax.tab.cc"
    break;

  case 147: // range_interval: RANGE_EXC
#line 523 "grammar/syntax.y"
              {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::EXCLUSIVE, RangeInclusionType::EXCLUSIVE};
}
#line 2596 "grammar/build/syntax.tab.cc"
    break;

  case 148: // range_interval: RANGE_EXC_INC
#line 525 "grammar/syntax.y"
                  {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::EXCLUSIVE, RangeInclusionType::INCLUSIVE};
}
#line 2604 "grammar/build/syntax.tab.cc"
    break;

  case 149: // range_interval: RANGE_INC
#line 527 "grammar/syntax.y"
              {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::INCLUSIVE, RangeInclusionType::INCLUSIVE};
}
#line 2612 "grammar/build/syntax.tab.cc"
    break;

  case 150: // or_expr: or_expr OR and_expr
#line 531 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::OR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2620 "grammar/build/syntax.tab.cc"
    break;

  case 151: // or_expr: and_expr
#line 533 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2628 "grammar/build/syntax.tab.cc"
    break;

  case 152: // and_expr: and_expr AND bit_or_expr
#line 537 "grammar/syntax.y"
                                   {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::AND, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2636 "grammar/build/syntax.tab.cc"
    break;

  case 153: // and_expr: bit_or_expr
#line 539 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2644 "grammar/build/syntax.tab.cc"
    break;

  case 154: // bit_or_expr: bit_or_expr BAR bit_xor_expr
#line 543 "grammar/syntax.y"
                                          {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::BITWISE_OR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2652 "grammar/build/syntax.tab.cc"
    break;

  case 155: // bit_or_expr: bit_xor_expr
#line 545 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2660 "grammar/build/syntax.tab.cc"
    break;

  case 156: // bit_xor_expr: bit_xor_expr XOR bit_and_expr
#line 549 "grammar/syntax.y"
                                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::XOR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2668 "grammar/build/syntax.tab.cc"
    break;

  case 157: // bit_xor_expr: bit_and_expr
#line 551 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2676 "grammar/build/syntax.tab.cc"
    break;

  case 158: // bit_and_expr: bit_and_expr REF equals_expr
#line 555 "grammar/syntax.y"
                                           {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::BITWISE_AND, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2684 "grammar/build/syntax.tab.cc"
    break;

  case 159: // bit_and_expr: equals_expr
#line 557 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2692 "grammar/build/syntax.tab.cc"
    break;

  case 160: // equals_expr: equals_expr EQ rel_expr
#line 561 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2700 "grammar/build/syntax.tab.cc"
    break;

  case 161: // equals_expr: equals_expr NOT_EQ rel_expr
#line 563 "grammar/syntax.y"
                                {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::NOT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2708 "grammar/build/syntax.tab.cc"
    break;

  case 162: // equals_expr: rel_expr
#line 565 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2716 "grammar/build/syntax.tab.cc"
    break;

  case 163: // rel_expr: rel_expr LT concat_expr
#line 569 "grammar/syntax.y"
                                  {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::LT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2724 "grammar/build/syntax.tab.cc"
    break;

  case 164: // rel_expr: rel_expr GT concat_expr
#line 571 "grammar/syntax.y"
                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::GT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2732 "grammar/build/syntax.tab.cc"
    break;

  case 165: // rel_expr: rel_expr LT_EQ concat_expr
#line 573 "grammar/syntax.y"
                               {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::LT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2740 "grammar/build/syntax.tab.cc"
    break;

  case 166: // rel_expr: rel_expr GT_EQ concat_expr
#line 575 "grammar/syntax.y"
                               {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::GT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2748 "grammar/build/syntax.tab.cc"
    break;

  case 167: // rel_expr: rel_expr IN concat_expr
#line 577 "grammar/syntax.y"
                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::IN, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2756 "grammar/build/syntax.tab.cc"
    break;

  case 168: // rel_expr: concat_expr
#line 579 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2764 "grammar/build/syntax.tab.cc"
    break;

  case 169: // concat_expr: concat_expr CONCAT sum_expr
#line 583 "grammar/syntax.y"
                                         {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::CONCAT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2772 "grammar/build/syntax.tab.cc"
    break;

  case 170: // concat_expr: sum_expr
#line 585 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2780 "grammar/build/syntax.tab.cc"
    break;

  case 171: // sum_expr: sum_expr PLUS mult_expr
#line 589 "grammar/syntax.y"
                                  {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::PLUS, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2788 "grammar/build/syntax.tab.cc"
    break;

  case 172: // sum_expr: sum_expr MINUS mult_expr
#line 591 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MINUS, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2796 "grammar/build/syntax.tab.cc"
    break;

  case 173: // sum_expr: mult_expr
#line 593 "grammar/syntax.y"
              {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2804 "grammar/build/syntax.tab.cc"
    break;

  case 174: // mult_expr: mult_expr MULT unary_expr
#line 597 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MULT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2812 "grammar/build/syntax.tab.cc"
    break;

  case 175: // mult_expr: mult_expr DIV unary_expr
#line 599 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::DIV, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2820 "grammar/build/syntax.tab.cc"
    break;

  case 176: // mult_expr: mult_expr MOD unary_expr
#line 601 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MOD, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2828 "grammar/build/syntax.tab.cc"
    break;

  case 177: // mult_expr: unary_expr
#line 603 "grammar/syntax.y"
               {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2836 "grammar/build/syntax.tab.cc"
    break;

  case 178: // unary_expr: MINUS exp_expr
#line 607 "grammar/syntax.y"
                           {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::MINUS, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2844 "grammar/build/syntax.tab.cc"
    break;

  case 179: // unary_expr: REV exp_expr
#line 609 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::REV, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2852 "grammar/build/syntax.tab.cc"
    break;

  case 180: // unary_expr: NOT exp_expr
#line 611 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::NOT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2860 "grammar/build/syntax.tab.cc"
    break;

  case 181: // unary_expr: REF exp_expr
#line 613 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::REF, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2868 "grammar/build/syntax.tab.cc"
    break;

  case 182: // unary_expr: INCREMENT exp_expr
#line 615 "grammar/syntax.y"
                       {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::INCREMENT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2876 "grammar/build/syntax.tab.cc"
    break;

  case 183: // unary_expr: DECREMENT exp_expr
#line 617 "grammar/syntax.y"
                       {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::DECREMENT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2884 "grammar/build/syntax.tab.cc"
    break;

  case 184: // unary_expr: MULT exp_expr
#line 619 "grammar/syntax.y"
                  {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2892 "grammar/build/syntax.tab.cc"
    break;

  case 185: // unary_expr: exp_expr
#line 621 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2900 "grammar/build/syntax.tab.cc"
    break;

  case 186: // exp_expr: postfix_expr EXP exp_expr
#line 625 "grammar/syntax.y"
                                    {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::EXP, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2908 "grammar/build/syntax.tab.cc"
    break;

  case 187: // exp_expr: postfix_expr
#line 627 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2916 "grammar/build/syntax.tab.cc"
    break;

  case 188: // postfix_expr: term INCREMENT
#line 631 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(true, UnaryOperation::INCREMENT, yystack_[1].value.as < ExpressionNode* > ());
}
#line 2924 "grammar/build/syntax.tab.cc"
    break;

  case 189: // postfix_expr: term DECREMENT
#line 633 "grammar/syntax.y"
                   {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(true, UnaryOperation::DECREMENT, yystack_[1].value.as < ExpressionNode* > ());
}
#line 2932 "grammar/build/syntax.tab.cc"
    break;

  case 190: // postfix_expr: term
#line 635 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2940 "grammar/build/syntax.tab.cc"
    break;

  case 191: // term: INT
#line 639 "grammar/syntax.y"
          {
  yylhs.value.as < ExpressionNode* > () = new IntNode(ctx.line, yystack_[0].value.as < int32_t > ());
}
#line 2948 "grammar/build/syntax.tab.cc"
    break;

  case 192: // term: LONG
#line 641 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new LongNode(ctx.line, yystack_[0].value.as < int64_t > ());
}
#line 2956 "grammar/build/syntax.tab.cc"
    break;

  case 193: // term: FLOAT
#line 643 "grammar/syntax.y"
          {
  yylhs.value.as < ExpressionNode* > () = new FloatNode(ctx.line, yystack_[0].value.as < float > ());
}
#line 2964 "grammar/build/syntax.tab.cc"
    break;

  case 194: // term: DOUBLE
#line 645 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = new DoubleNode(ctx.line, yystack_[0].value.as < double > ());
}
#line 2972 "grammar/build/syntax.tab.cc"
    break;

  case 195: // term: BYTE
#line 647 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new ByteNode(ctx.line, yystack_[0].value.as < uint8_t > ());
}
#line 2980 "grammar/build/syntax.tab.cc"
    break;

  case 196: // term: BOOL
#line 649 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new BoolNode(ctx.line, yystack_[0].value.as < bool > ());
}
#line 2988 "grammar/build/syntax.tab.cc"
    break;

  case 197: // term: STRING
#line 651 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = new StringNode(ctx.line, yystack_[0].value.as < string > ());
}
#line 2996 "grammar/build/syntax.tab.cc"
    break;

  case 198: // term: CHAR
#line 653 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new CharNode(ctx.line, yystack_[0].value.as < char > ());
}
#line 3004 "grammar/build/syntax.tab.cc"
    break;

  case 199: // term: NONE
#line 655 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new OptionNode(ctx.line, Option());
}
#line 3012 "grammar/build/syntax.tab.cc"
    break;

  case 200: // term: array_allocation
#line 657 "grammar/syntax.y"
                     {
  yylhs.value.as < ExpressionNode* > () = nullptr;
}
#line 3020 "grammar/build/syntax.tab.cc"
    break;

  case 201: // term: struct_allocation
#line 659 "grammar/syntax.y"
                      {
  yylhs.value.as < ExpressionNode* > () = nullptr;
}
#line 3028 "grammar/build/syntax.tab.cc"
    break;

  case 202: // term: access
#line 661 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < AccessNode* > ();
}
#line 3036 "grammar/build/syntax.tab.cc"
    break;

  case 203: // term: SOME LEFT_PAREN expr RIGHT_PAREN
#line 663 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new OptionNode(ctx.line, Option());
}
#line 3044 "grammar/build/syntax.tab.cc"
    break;

  case 204: // array_allocation: NEW type LEFT_BRACKET expr RIGHT_BRACKET
#line 667 "grammar/syntax.y"
                                                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3052 "grammar/build/syntax.tab.cc"
    break;

  case 205: // array_allocation: NEW type LEFT_BRACKET expr RIGHT_BRACKET LEFT_BRACE array_allocation_values RIGHT_BRACE
#line 669 "grammar/syntax.y"
                                                                                            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3060 "grammar/build/syntax.tab.cc"
    break;

  case 206: // array_allocation_values: array_allocation_values COMMA expr
#line 673 "grammar/syntax.y"
                                                            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3068 "grammar/build/syntax.tab.cc"
    break;

  case 207: // array_allocation_values: expr
#line 675 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3076 "grammar/build/syntax.tab.cc"
    break;

  case 208: // struct_allocation: NEW type LEFT_BRACE struct_allocation_values RIGHT_BRACE
#line 679 "grammar/syntax.y"
                                                                            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3084 "grammar/build/syntax.tab.cc"
    break;

  case 209: // struct_allocation: NEW type LEFT_BRACE RIGHT_BRACE
#line 681 "grammar/syntax.y"
                                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3092 "grammar/build/syntax.tab.cc"
    break;

  case 210: // struct_allocation_values: struct_allocation_values COMMA ID COLON expr
#line 685 "grammar/syntax.y"
                                                                       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3100 "grammar/build/syntax.tab.cc"
    break;

  case 211: // struct_allocation_values: ID COLON expr
#line 687 "grammar/syntax.y"
                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3108 "grammar/build/syntax.tab.cc"
    break;


#line 3112 "grammar/build/syntax.tab.cc"

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








  const short parser::yypact_ninf_ = -279;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     155,    26,    34,    55,    55,    55,    55,    46,   155,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,   -17,   -17,  -279,
    -279,    -4,    13,    59,    70,  -279,  -279,    -1,     2,   667,
    -279,    27,   -56,  -279,    72,    60,    17,   104,    55,    80,
     124,   114,  -279,  -279,    65,  -279,  -279,  -279,   177,   184,
     133,  -279,  -279,    76,  -279,  -279,  -279,  -279,   179,  -279,
      82,   465,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
      39,   169,   191,   191,   191,   191,   191,   191,   191,   465,
     216,   220,  -279,  -279,  -279,  -279,  2672,  2740,   186,   204,
     774,  -279,  -279,  2672,   207,  -279,   170,  -279,  2672,  -279,
    2916,  -279,  -279,   881,   178,  -279,  -279,   117,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  2876,   118,   247,   253,
     246,   257,     7,    -6,   270,   115,    96,  -279,  -279,   275,
     152,  -279,  -279,  -279,   291,   234,  -279,   295,   465,   236,
     237,  -279,   205,   240,   240,  -279,    55,   244,  -279,   240,
     240,  -279,   245,  -279,   306,  -279,   465,   988,   465,   465,
     120,  -279,  -279,  -279,  -279,  -279,  -279,  -279,   147,   249,
     250,   251,    20,   242,    23,  2672,  2672,  1095,   173,  2672,
    -279,  -279,  2672,  2672,  2672,  2672,  2672,  2672,  2672,  2672,
    2672,  2672,  2672,  2672,   243,   312,  2486,  2672,  -279,   254,
     255,  -279,   252,  -279,   285,  2876,  2876,  2876,  2876,  2876,
    2876,  2876,  2876,  2876,  2876,  2876,  2876,  2876,  2876,  2876,
    2876,  2876,  2876,  2876,   191,  -279,  -279,  -279,  -279,  -279,
     258,  -279,  -279,   262,    14,   265,  1202,   228,  -279,   268,
     269,   238,  -279,  -279,   258,  1309,   -35,    16,  2579,    18,
     465,   465,  -279,   248,  2379,   256,   271,   267,  -279,  2672,
      40,   272,   259,   173,  -279,  -279,   273,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,   167,  -279,   274,  -279,  -279,  -279,   247,
     285,   253,   246,   257,     7,    -6,    -6,   270,   270,   270,
     270,   270,   115,    96,    96,  -279,  -279,  -279,  -279,  -279,
     202,   465,   277,  1416,   279,   465,   465,   287,   288,  -279,
    -279,   286,   276,  -279,    48,   -41,   -25,    58,   453,  2672,
    2672,  1523,  -279,   352,   296,   120,   215,  2379,  -279,  -279,
    -279,  -279,  2672,  -279,  -279,   306,  -279,   988,  -279,   293,
    -279,   -61,   560,  -279,  -279,   290,  2672,   356,  -279,  2672,
    2672,   150,  -279,  2808,  2379,  -279,   297,   300,  -279,  1630,
     305,  2379,    58,  2379,  2379,  -279,   209,  1737,  -279,   304,
     309,  2672,  -279,   313,  -279,  -279,  2379,    24,   301,  1844,
    1951,  2672,  -279,  2379,  2379,   120,  2379,  -279,   315,  -279,
    -279,  -279,    64,  2672,   453,   289,  2379,  -279,  -279,  2058,
     310,  2379,  -279,  2672,  -279,  -279,  -279,    58,   453,  -279,
    2165,  -279,   162,  -279,  -279,  2272,  2379,  -279,   453,  -279
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
       0,     0,   195,   191,   192,   193,   194,   196,    73,    72,
     197,   198,    96,    92,    95,    93,    94,    99,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   149,   147,   148,     0,     0,     0,     0,
       0,    78,    79,     0,     0,   199,     0,    69,     0,    67,
     202,    68,    70,     0,     0,    82,    80,     0,    81,    83,
      87,    84,    85,    86,    88,   142,     0,   141,   151,   153,
     155,   157,   159,   162,   168,   170,   173,   177,   185,   187,
     190,   200,   201,    31,     0,     0,    35,     0,     0,     0,
       0,    37,     0,     0,     0,    51,     0,     0,    54,     0,
       0,    40,     0,    41,     0,    17,     0,     0,     0,     0,
     202,   183,   182,   181,   180,   179,   178,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,    77,     0,    25,   143,     0,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   189,   188,    32,    30,    22,
      38,    34,    36,     0,     0,     0,     0,     0,    50,     0,
       0,     0,    39,    19,    21,     0,     0,     0,     0,     0,
       0,     0,    71,     0,     0,     0,     0,     0,   140,     0,
       0,     0,     0,   123,   126,   124,     0,   104,   105,   106,
     107,   110,   108,   111,   109,   112,   113,   114,   103,    64,
      63,    66,    27,     0,    29,     0,    13,    76,   100,   150,
     145,   152,   154,   156,   158,   160,   161,   165,   166,   163,
     164,   167,   169,   172,   171,   176,   174,   175,   186,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     102,     0,     0,   209,     0,     0,     0,     0,     0,     0,
       0,     0,   139,     0,     0,   131,     0,     0,   121,   125,
     122,   203,     0,    26,    65,     0,    16,     0,    61,     0,
      52,     0,     0,    48,    12,   204,     0,     0,   208,     0,
       0,     0,   120,     0,     0,   115,     0,     0,   138,     0,
       0,     0,     0,     0,   132,    28,     0,     0,    60,     0,
       0,     0,   211,     0,    90,    91,     0,     0,     0,     0,
       0,     0,   137,     0,   129,   130,   127,    15,     0,    45,
      46,   207,     0,     0,     0,     0,     0,   119,   134,     0,
       0,   128,    58,     0,   205,   210,   116,     0,     0,   133,
       0,   206,     0,   117,   136,     0,     0,   135,     0,   118
  };

  const short
  parser::yypgoto_[] =
  {
    -279,  -279,  -279,   378,  -279,    98,   101,    77,   -16,    41,
     225,     8,  -279,   278,  -279,  -279,  -279,  -279,  -279,   358,
    -279,  -279,   344,  -279,  -279,  -279,  -279,   360,  -279,  -279,
     -29,  -279,  -279,     0,    19,     4,  -279,   221,   -37,  -279,
    -279,  -278,  -279,  -279,  -279,   138,  -279,   139,  -279,  -279,
    -279,   -94,  -279,   294,  -101,   198,   197,   199,   201,   196,
      69,    43,   200,    63,    11,   -67,  -279,  -279,  -279,  -279,
    -279,  -279
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
     110,    28,   181,   183,    22,    23,    24,    30,    33,   188,
     144,   212,   369,   329,   191,   171,   172,   173,   174,   175,
     176,   177,    33,    33,   167,   214,    33,   332,   370,   263,
      35,   212,   265,   415,   221,    17,   389,   212,   152,   223,
     224,   225,   226,    18,    35,   145,    25,   212,   113,    68,
      69,   222,   178,    27,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,   330,    19,    20,    68,    69,    61,
      57,   110,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    90,    91,   110,    57,   168,   227,   212,   153,
     189,   267,   268,   333,   189,   276,   143,    31,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
      96,   240,   294,   295,   367,   300,    34,   210,   320,   187,
     149,    42,    51,   368,    43,    52,   147,   148,    96,   254,
     423,   256,   257,   154,   343,   344,   426,    28,   110,   424,
      38,   146,    42,   250,   107,    43,   156,   231,   147,   166,
     433,    51,   232,   233,    52,    39,   247,    40,   110,   215,
     439,    39,   107,    40,   331,    41,    48,   318,    49,   229,
     230,   157,    48,   151,    49,   342,   235,   236,    50,    92,
      93,    94,    95,   155,   162,   204,   159,   206,   205,   212,
     206,   210,   207,   160,    62,    63,    64,    65,    66,    67,
      68,    69,   161,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,   204,   169,   110,   205,   258,
     206,   259,   207,   335,   336,   179,   110,   204,   396,   180,
     205,   246,   206,   352,   207,   110,   249,   251,   353,   190,
     436,   345,   315,   316,   317,   376,   377,   211,   164,    89,
     165,     1,   289,     2,   290,     3,   184,     4,   385,   210,
       5,    96,     6,   270,   271,   323,   307,   308,   309,   310,
     311,   355,   392,   356,   185,   394,   395,   189,   164,   398,
     407,   382,   383,   338,   357,   104,   105,   217,   361,   362,
     305,   306,   313,   314,   110,   107,   218,   411,   219,   220,
     228,   234,   237,   238,   239,   241,   242,   420,   371,   110,
     244,   243,   110,   248,   252,    33,   260,   261,   110,   425,
     264,   291,   262,   296,   297,   298,   215,   210,   110,   431,
     212,   319,   321,   110,   324,   325,   326,   327,   341,   347,
     340,   337,   210,   366,   351,   110,   358,   354,   360,   339,
     110,   348,   110,   405,   110,   110,   363,   364,   110,   365,
     379,   380,   388,   381,   391,   393,   384,   110,   400,   401,
     110,   110,   403,   409,   110,   110,   387,   110,   410,   416,
     413,   430,   427,   210,   422,   110,    26,   110,   210,   253,
     110,   210,   110,   399,   150,   213,   386,   163,   432,   110,
     404,   110,   406,   210,   158,   266,   110,   110,   210,   110,
     210,   349,   350,   299,   301,   414,   304,   302,   210,   419,
     303,   216,   421,   210,     0,   210,     0,     0,   312,     0,
       0,     0,   210,     0,     0,   428,     0,     0,     0,   210,
       0,     0,   210,     0,     0,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,   438,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,    85,    86,     0,     0,     0,    87,     0,    88,
       0,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,     0,     0,     0,     0,     0,    97,
     372,     0,   373,   374,    98,    99,     0,   100,     0,     0,
     101,   102,   103,     0,     0,     0,     0,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,   108,    62,    63,    64,    65,    66,    67,    68,
      69,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,    85,
      86,     0,     0,     0,    87,     0,    88,     0,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
      96,     0,   212,     0,     0,     0,    97,     0,     0,     0,
       0,    98,    99,     0,   100,     0,     0,   101,   102,   103,
       0,     0,     0,     0,   104,   105,     0,   390,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,   108,
      62,    63,    64,    65,    66,    67,    68,    69,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,    85,    86,     0,     0,
       0,    87,     0,    88,     0,    89,    90,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     0,     0,    97,     0,     0,     0,     0,    98,    99,
       0,   100,     0,     0,   101,   102,   103,     0,     0,     0,
       0,   104,   105,     0,     0,     0,   106,     0,     0,     0,
       0,   107,     0,     0,     0,     0,   108,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,    85,    86,     0,     0,     0,    87,     0,
      88,     0,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,    96,     0,     0,     0,     0,     0,
      97,     0,     0,     0,     0,    98,    99,     0,   100,   186,
       0,   101,   102,   103,     0,     0,     0,     0,   104,   105,
       0,     0,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     0,     0,   108,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,     0,     0,     0,     0,     0,     0,
      85,    86,     0,     0,     0,    87,     0,    88,     0,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,    98,    99,     0,   100,     0,     0,   101,   102,
     103,     0,     0,     0,     0,   104,   105,     0,     0,     0,
     209,     0,     0,     0,     0,   107,     0,     0,     0,     0,
     108,    62,    63,    64,    65,    66,    67,    68,    69,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,    85,    86,     0,
       0,     0,    87,     0,    88,     0,    89,    90,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,    96,     0,
     212,     0,     0,     0,    97,     0,     0,     0,     0,    98,
      99,     0,   100,     0,     0,   101,   102,   103,     0,     0,
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
     269,     0,   101,   102,   103,     0,     0,     0,     0,   104,
     105,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,   108,    62,    63,    64,    65,    66,
      67,    68,    69,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,    85,    86,     0,     0,     0,    87,     0,    88,     0,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,    96,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,    98,    99,     0,   100,     0,     0,   101,
     102,   103,     0,     0,     0,     0,   104,   105,     0,     0,
       0,   322,     0,     0,     0,     0,   107,     0,     0,     0,
       0,   108,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,    85,    86,
       0,     0,     0,    87,     0,    88,     0,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
       0,     0,     0,     0,     0,    97,     0,     0,     0,     0,
      98,    99,     0,   100,     0,     0,   101,   102,   103,     0,
       0,     0,     0,   104,   105,     0,   328,     0,     0,     0,
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
     104,   105,     0,     0,     0,   359,     0,     0,     0,     0,
     107,     0,     0,     0,     0,   108,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,    85,    86,     0,     0,     0,    87,     0,    88,
       0,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,     0,     0,     0,     0,     0,    97,
       0,     0,     0,     0,    98,    99,   378,   100,     0,     0,
     101,   102,   103,     0,     0,     0,     0,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,   108,    62,    63,    64,    65,    66,    67,    68,
      69,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,    85,
      86,     0,     0,     0,    87,     0,    88,     0,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
      96,     0,     0,     0,     0,     0,    97,     0,     0,     0,
       0,    98,    99,   402,   100,     0,     0,   101,   102,   103,
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
       0,   100,     0,     0,   101,   102,   103,     0,     0,     0,
       0,   104,   105,     0,   408,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,   108,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,    85,    86,     0,     0,     0,    87,     0,
      88,     0,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,    96,     0,     0,     0,     0,     0,
      97,   417,     0,     0,     0,    98,    99,     0,   100,     0,
       0,   101,   102,   103,     0,     0,     0,     0,   104,   105,
       0,     0,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     0,     0,   108,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,     0,     0,     0,     0,     0,     0,
      85,    86,     0,     0,     0,    87,     0,    88,     0,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,    98,    99,     0,   100,     0,   418,   101,   102,
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
      99,     0,   100,     0,   429,   101,   102,   103,     0,     0,
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
       0,   434,   101,   102,   103,     0,     0,     0,     0,   104,
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
      98,    99,     0,   100,     0,     0,   101,   102,   103,     0,
       0,     0,     0,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,     0,   108,    62,
      63,    64,    65,    66,    67,    68,    69,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,    85,    86,     0,     0,     0,
      87,     0,    88,     0,    89,     0,     0,    92,    93,    94,
      95,     0,     0,     0,     0,     0,    96,   292,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,    62,    63,    64,    65,    66,    67,    68,    69,
     107,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,    85,    86,
       0,     0,     0,    87,     0,    88,     0,    89,     0,     0,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
       0,     0,   298,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,    62,    63,    64,    65,    66,
      67,    68,    69,   107,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,    85,    86,     0,     0,     0,    87,     0,    88,     0,
      89,     0,     0,    92,    93,    94,    95,     0,     0,     0,
       0,     0,    96,    62,    63,    64,    65,    66,    67,    68,
      69,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,   104,   105,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,    85,
      86,     0,     0,     0,    87,     0,    88,     0,    89,     0,
       0,    92,    93,    94,    95,     0,     0,     0,     0,     0,
      96,    62,    63,    64,    65,    66,    67,    68,    69,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,   182,   105,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,    85,    86,     0,
       0,     0,    87,     0,    88,     0,    89,     0,     0,    92,
      93,    94,    95,     0,     0,     0,     0,     0,    96,    62,
      63,    64,    65,    66,    67,    68,    69,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,   397,   105,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,    85,    86,     0,     0,     0,
      87,     0,    88,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,   193,    96,   194,   195,   196,
     197,   198,   199,   200,   201,   202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   203,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
     107,   204,     0,     0,   205,     0,   206,     0,   207
  };

  const short
  parser::yycheck_[] =
  {
      29,    17,    96,    97,     4,     5,     6,    11,     9,   103,
      66,    72,    53,    48,   108,    82,    83,    84,    85,    86,
      87,    88,     9,     9,    61,   126,     9,     9,    53,     9,
      22,    72,     9,     9,    27,     9,    97,    72,    38,    45,
      46,    47,    48,     9,    36,   101,     0,    72,    29,     9,
      10,    44,    89,    70,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    48,    10,    11,     9,    10,    67,
      71,   100,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    59,    60,   113,    71,    47,    93,    72,     9,
      70,   185,   186,    75,    70,   189,    69,   101,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
      70,   148,   206,   207,    66,   216,   103,   113,   104,   100,
     103,    23,    24,    75,    23,    24,    66,    67,    70,   166,
      66,   168,   169,     9,    94,    95,   414,   153,   167,    75,
      81,    69,    44,   159,   104,    44,    81,    51,    66,    67,
     428,    53,    56,    57,    53,    96,   156,    98,   187,    41,
     438,    96,   104,    98,   258,   106,    96,   234,    98,    54,
      55,   106,    96,    69,    98,   269,    24,    25,   108,    61,
      62,    63,    64,    69,   108,    65,     9,    70,    68,    72,
      70,   187,    72,     9,     3,     4,     5,     6,     7,     8,
       9,    10,    69,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    65,    47,   246,    68,    72,
      70,    74,    72,   260,   261,     9,   255,    65,    78,     9,
      68,   154,    70,    66,    72,   264,   159,   160,    71,    69,
      78,   270,   231,   232,   233,   339,   340,    69,    69,    58,
      71,    96,     9,    98,    11,   100,    70,   102,   352,   255,
     105,    70,   107,    90,    91,   246,   223,   224,   225,   226,
     227,    69,   366,    71,    70,   369,   370,    70,    69,   373,
      71,    66,    67,   264,   321,    94,    95,    40,   325,   326,
     221,   222,   229,   230,   323,   104,    43,   391,    52,    42,
      30,    26,    11,    69,     9,    69,    69,   401,   337,   338,
      70,   106,   341,    69,    69,     9,    67,    67,   347,   413,
      78,     9,    71,    69,    69,    73,    41,   323,   357,   423,
      72,    69,    67,   362,   106,    67,    67,    99,    71,    67,
      69,    93,   338,    67,    71,   374,    69,    73,    69,    93,
     379,    92,   381,   382,   383,   384,    69,    69,   387,    73,
     341,     9,    69,    67,    74,     9,   347,   396,    71,    69,
     399,   400,    67,    69,   403,   404,   357,   406,    69,    78,
      67,    71,    93,   379,    69,   414,     8,   416,   384,   164,
     419,   387,   421,   374,    36,   117,   355,    53,   427,   428,
     381,   430,   383,   399,    44,   184,   435,   436,   404,   438,
     406,   273,   273,   215,   217,   396,   220,   218,   414,   400,
     219,   127,   403,   419,    -1,   421,    -1,    -1,   228,    -1,
      -1,    -1,   428,    -1,    -1,   416,    -1,    -1,    -1,   435,
      -1,    -1,   438,    -1,    -1,    -1,    -1,    -1,    -1,   430,
      -1,    -1,    -1,    -1,    -1,   436,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      77,    -1,    79,    80,    81,    82,    -1,    84,    -1,    -1,
      87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,   109,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    81,    82,    -1,    84,    -1,    -1,    87,    88,    89,
      -1,    -1,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,
      -1,    84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,   109,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,    85,
      -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    82,    -1,    84,    -1,    -1,    87,    88,
      89,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
     109,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,
      82,    -1,    84,    -1,    -1,    87,    88,    89,    -1,    -1,
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
      85,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,   109,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    81,    82,    -1,    84,    -1,    -1,    87,
      88,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,   109,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      81,    82,    -1,    84,    -1,    -1,    87,    88,    89,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,
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
      94,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,   109,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    -1,    -1,
      87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
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
      76,    77,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,
      -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    82,    -1,    84,    -1,    86,    87,    88,
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
      81,    82,    -1,    84,    -1,    -1,    87,    88,    89,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    56,    -1,    58,    -1,    -1,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,     3,     4,     5,     6,     7,     8,     9,    10,
     104,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    56,    -1,    58,    -1,    -1,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,     3,     4,     5,     6,     7,
       8,     9,    10,   104,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,
      58,    -1,    -1,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,    -1,
      -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      -1,    -1,    54,    -1,    56,    -1,    58,    -1,    -1,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    70,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    65,    -1,    -1,    68,    -1,    70,    -1,    72
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
      69,   161,   179,    67,   144,     9,    78,    77,    86,   144,
     161,   144,    69,    66,    75,   161,   151,    93,   144,    86,
      71,   161,   140,   151,    86,   144,    78,    86,   144,   151
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
     151,   152,   153,   153,   153,   154,   154,   155,   155,   155,
     156,   156,   157,   158,   158,   158,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   162,   163,   163,   163,   163,
     164,   164,   165,   165,   166,   166,   167,   167,   168,   168,
     169,   169,   169,   170,   170,   170,   170,   170,   170,   171,
     171,   172,   172,   172,   173,   173,   173,   173,   174,   174,
     174,   174,   174,   174,   174,   174,   175,   175,   176,   176,
     176,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   178,   178,   179,   179,   180,   180,
     181,   181
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
       3,     3,     3,     3,     3,     5,     8,     5,     8,     3,
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
       0,    85,    85,    89,    92,    97,    99,   101,   103,   105,
     109,   111,   115,   122,   127,   131,   133,   137,   139,   143,
     148,   155,   162,   165,   170,   172,   176,   178,   182,   185,
     190,   192,   196,   198,   202,   204,   208,   210,   214,   218,
     220,   224,   226,   230,   232,   236,   238,   240,   244,   246,
     250,   252,   254,   256,   260,   262,   266,   268,   272,   274,
     278,   280,   282,   286,   288,   290,   292,   294,   296,   300,
     302,   304,   308,   310,   314,   316,   320,   323,   328,   330,
     332,   334,   336,   338,   340,   342,   344,   346,   348,   352,
     356,   358,   362,   364,   366,   368,   370,   372,   374,   376,
     378,   380,   382,   386,   388,   390,   392,   394,   396,   398,
     400,   402,   404,   406,   408,   412,   417,   424,   429,   434,
     439,   443,   447,   449,   451,   455,   457,   461,   463,   465,
     469,   471,   475,   479,   484,   486,   491,   495,   497,   501,
     503,   507,   509,   513,   515,   517,   521,   523,   525,   527,
     531,   533,   537,   539,   543,   545,   549,   551,   555,   557,
     561,   563,   565,   569,   571,   573,   575,   577,   579,   583,
     585,   589,   591,   593,   597,   599,   601,   603,   607,   609,
     611,   613,   615,   617,   619,   621,   625,   627,   631,   633,
     635,   639,   641,   643,   645,   647,   649,   651,   653,   655,
     657,   659,   661,   663,   667,   669,   673,   675,   679,   681,
     685,   687
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
#line 4273 "grammar/build/syntax.tab.cc"

#line 690 "grammar/syntax.y"
