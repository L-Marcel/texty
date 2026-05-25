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
#line 20 "grammar/syntax.y"

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

      case symbol_kind::S_array_allocation: // array_allocation
        value.YY_MOVE_OR_COPY< ArrayAllocationNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assign: // assign
        value.YY_MOVE_OR_COPY< AssignNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attr: // attr
        value.YY_MOVE_OR_COPY< AttrNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_case: // case
      case symbol_kind::S_default_case: // default_case
        value.YY_MOVE_OR_COPY< CaseNode* > (YY_MOVE (that.value));
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

      case symbol_kind::S_switch: // switch
        value.YY_MOVE_OR_COPY< SwitchNode* > (YY_MOVE (that.value));
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

      case symbol_kind::S_while: // while
      case symbol_kind::S_repeat: // repeat
        value.YY_MOVE_OR_COPY< WhileNode* > (YY_MOVE (that.value));
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

      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case_list: // case_list
        value.YY_MOVE_OR_COPY< vector<CaseNode*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_call_params_list: // call_params_list
      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_case_values: // case_values
      case symbol_kind::S_array_allocation_values: // array_allocation_values
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

      case symbol_kind::S_array_allocation: // array_allocation
        value.move< ArrayAllocationNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assign: // assign
        value.move< AssignNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attr: // attr
        value.move< AttrNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_case: // case
      case symbol_kind::S_default_case: // default_case
        value.move< CaseNode* > (YY_MOVE (that.value));
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

      case symbol_kind::S_switch: // switch
        value.move< SwitchNode* > (YY_MOVE (that.value));
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

      case symbol_kind::S_while: // while
      case symbol_kind::S_repeat: // repeat
        value.move< WhileNode* > (YY_MOVE (that.value));
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

      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case_list: // case_list
        value.move< vector<CaseNode*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_call_params_list: // call_params_list
      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_case_values: // case_values
      case symbol_kind::S_array_allocation_values: // array_allocation_values
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

      case symbol_kind::S_array_allocation: // array_allocation
        value.copy< ArrayAllocationNode* > (that.value);
        break;

      case symbol_kind::S_assign: // assign
        value.copy< AssignNode* > (that.value);
        break;

      case symbol_kind::S_attr: // attr
        value.copy< AttrNode* > (that.value);
        break;

      case symbol_kind::S_case: // case
      case symbol_kind::S_default_case: // default_case
        value.copy< CaseNode* > (that.value);
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

      case symbol_kind::S_switch: // switch
        value.copy< SwitchNode* > (that.value);
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

      case symbol_kind::S_while: // while
      case symbol_kind::S_repeat: // repeat
        value.copy< WhileNode* > (that.value);
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

      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case_list: // case_list
        value.copy< vector<CaseNode*> > (that.value);
        break;

      case symbol_kind::S_call_params_list: // call_params_list
      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_case_values: // case_values
      case symbol_kind::S_array_allocation_values: // array_allocation_values
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

      case symbol_kind::S_array_allocation: // array_allocation
        value.move< ArrayAllocationNode* > (that.value);
        break;

      case symbol_kind::S_assign: // assign
        value.move< AssignNode* > (that.value);
        break;

      case symbol_kind::S_attr: // attr
        value.move< AttrNode* > (that.value);
        break;

      case symbol_kind::S_case: // case
      case symbol_kind::S_default_case: // default_case
        value.move< CaseNode* > (that.value);
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

      case symbol_kind::S_switch: // switch
        value.move< SwitchNode* > (that.value);
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

      case symbol_kind::S_while: // while
      case symbol_kind::S_repeat: // repeat
        value.move< WhileNode* > (that.value);
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

      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case_list: // case_list
        value.move< vector<CaseNode*> > (that.value);
        break;

      case symbol_kind::S_call_params_list: // call_params_list
      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_case_values: // case_values
      case symbol_kind::S_array_allocation_values: // array_allocation_values
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

      case symbol_kind::S_array_allocation: // array_allocation
        yylhs.value.emplace< ArrayAllocationNode* > ();
        break;

      case symbol_kind::S_assign: // assign
        yylhs.value.emplace< AssignNode* > ();
        break;

      case symbol_kind::S_attr: // attr
        yylhs.value.emplace< AttrNode* > ();
        break;

      case symbol_kind::S_case: // case
      case symbol_kind::S_default_case: // default_case
        yylhs.value.emplace< CaseNode* > ();
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

      case symbol_kind::S_switch: // switch
        yylhs.value.emplace< SwitchNode* > ();
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

      case symbol_kind::S_while: // while
      case symbol_kind::S_repeat: // repeat
        yylhs.value.emplace< WhileNode* > ();
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

      case symbol_kind::S_cases: // cases
      case symbol_kind::S_case_list: // case_list
        yylhs.value.emplace< vector<CaseNode*> > ();
        break;

      case symbol_kind::S_call_params_list: // call_params_list
      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_case_values: // case_values
      case symbol_kind::S_array_allocation_values: // array_allocation_values
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
#line 102 "grammar/syntax.y"
              {
  ctx.root = yystack_[0].value.as < Node* > ();
}
#line 1467 "grammar/build/syntax.tab.cc"
    break;

  case 3: // program: program program_slice
#line 106 "grammar/syntax.y"
                               {
  yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > ();
  yystack_[1].value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
}
#line 1476 "grammar/build/syntax.tab.cc"
    break;

  case 4: // program: program_slice
#line 109 "grammar/syntax.y"
                  {
  yylhs.value.as < Node* > () = new Node(ctx.line, "PROGRAM");
  yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
}
#line 1485 "grammar/build/syntax.tab.cc"
    break;

  case 5: // program_slice: subprogram
#line 114 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1493 "grammar/build/syntax.tab.cc"
    break;

  case 6: // program_slice: enum
#line 116 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1501 "grammar/build/syntax.tab.cc"
    break;

  case 7: // program_slice: struct
#line 118 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1509 "grammar/build/syntax.tab.cc"
    break;

  case 8: // program_slice: trait
#line 120 "grammar/syntax.y"
          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1517 "grammar/build/syntax.tab.cc"
    break;

  case 9: // program_slice: impl
#line 122 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1525 "grammar/build/syntax.tab.cc"
    break;

  case 10: // subprogram: fn
#line 126 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = yystack_[0].value.as < FunctionNode* > ();
}
#line 1533 "grammar/build/syntax.tab.cc"
    break;

  case 11: // subprogram: proc
#line 128 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ProcedureNode* > ();
}
#line 1541 "grammar/build/syntax.tab.cc"
    break;

  case 12: // fn: FUNCTION ID params_list COLON type stmts END_FUNCTION SEMICOLON
#line 132 "grammar/syntax.y"
                                                                    {
  yylhs.value.as < FunctionNode* > () = new FunctionNode(ctx.line, yystack_[6].value.as < string > (), *yystack_[3].value.as < Type* > (), yystack_[5].value.as < vector<Param> > ());
  for (size_t i = 0; i < yystack_[2].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < FunctionNode* > ()->children.push_back(yystack_[2].value.as < vector<Node*> > ()[i]);
  };
}
#line 1552 "grammar/build/syntax.tab.cc"
    break;

  case 13: // proc: PROCEDURE ID params_list stmts END_PROCEDURE SEMICOLON
#line 139 "grammar/syntax.y"
                                                             {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[4].value.as < string > (), yystack_[3].value.as < vector<Param> > ());
  for (size_t i = 0; i < yystack_[2].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < ProcedureNode* > ()->children.push_back(yystack_[2].value.as < vector<Node*> > ()[i]);
  };
}
#line 1563 "grammar/build/syntax.tab.cc"
    break;

  case 14: // proc: PROCEDURE ID params_list END_PROCEDURE SEMICOLON
#line 144 "grammar/syntax.y"
                                                     {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[3].value.as < string > (), yystack_[2].value.as < vector<Param> > ());
}
#line 1571 "grammar/build/syntax.tab.cc"
    break;

  case 15: // params_self_list: LEFT_PAREN SELF SEMICOLON params RIGHT_PAREN
#line 148 "grammar/syntax.y"
                                                               {
  yylhs.value.as < vector<Param> > () = yystack_[1].value.as < vector<Param> > ();
}
#line 1579 "grammar/build/syntax.tab.cc"
    break;

  case 16: // params_self_list: LEFT_PAREN SELF RIGHT_PAREN
#line 150 "grammar/syntax.y"
                                {
  yylhs.value.as < vector<Param> > () = vector<Param>();
}
#line 1587 "grammar/build/syntax.tab.cc"
    break;

  case 17: // params_list: LEFT_PAREN params RIGHT_PAREN
#line 154 "grammar/syntax.y"
                                           {
  yylhs.value.as < vector<Param> > () = yystack_[1].value.as < vector<Param> > ();
}
#line 1595 "grammar/build/syntax.tab.cc"
    break;

  case 18: // params_list: LEFT_PAREN RIGHT_PAREN
#line 156 "grammar/syntax.y"
                           {
  yylhs.value.as < vector<Param> > () = vector<Param>();
}
#line 1603 "grammar/build/syntax.tab.cc"
    break;

  case 19: // params: params SEMICOLON param
#line 160 "grammar/syntax.y"
                               {
  yylhs.value.as < vector<Param> > () = yystack_[2].value.as < vector<Param> > ();
  for (size_t i = 0; i < yystack_[0].value.as < vector<Param> > ().size(); i++) {
    yylhs.value.as < vector<Param> > ().push_back(yystack_[0].value.as < vector<Param> > ()[i]);
  };
}
#line 1614 "grammar/build/syntax.tab.cc"
    break;

  case 20: // params: param
#line 165 "grammar/syntax.y"
          {
  yylhs.value.as < vector<Param> > () = vector<Param>();
  for (size_t i = 0; i < yystack_[0].value.as < vector<Param> > ().size(); i++) {
    yylhs.value.as < vector<Param> > ().push_back(yystack_[0].value.as < vector<Param> > ()[i]);
  };
}
#line 1625 "grammar/build/syntax.tab.cc"
    break;

  case 21: // param: id_list COLON type
#line 172 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<Param> > () = vector<Param>();
  for (size_t i = 0; i < yystack_[2].value.as < vector<string> > ().size(); i++) {
    yylhs.value.as < vector<Param> > ().push_back({yystack_[2].value.as < vector<string> > ()[i], *yystack_[0].value.as < Type* > ()});
  };
}
#line 1636 "grammar/build/syntax.tab.cc"
    break;

  case 22: // id_list: id_list COMMA ID
#line 179 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<string> > () = yystack_[2].value.as < vector<string> > ();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < string > ());
}
#line 1645 "grammar/build/syntax.tab.cc"
    break;

  case 23: // id_list: ID
#line 182 "grammar/syntax.y"
       {
  yylhs.value.as < vector<string> > () = vector<string>();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < string > ());
}
#line 1654 "grammar/build/syntax.tab.cc"
    break;

  case 24: // subprogram_call: access call_params_list
#line 187 "grammar/syntax.y"
                                         {
  yylhs.value.as < SubprogramCallNode* > () = new SubprogramCallNode(ctx.line, yystack_[1].value.as < AccessNode* > (), yystack_[0].value.as < vector<ExpressionNode*> > ());
}
#line 1662 "grammar/build/syntax.tab.cc"
    break;

  case 25: // subprogram_call: type call_params_list
#line 189 "grammar/syntax.y"
                          {
  yylhs.value.as < SubprogramCallNode* > () = new SubprogramCallNode(ctx.line, *yystack_[1].value.as < Type* > (), yystack_[0].value.as < vector<ExpressionNode*> > ());
}
#line 1670 "grammar/build/syntax.tab.cc"
    break;

  case 26: // call_params_list: LEFT_PAREN call_params RIGHT_PAREN
#line 193 "grammar/syntax.y"
                                                     {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[1].value.as < vector<ExpressionNode*> > ();
}
#line 1678 "grammar/build/syntax.tab.cc"
    break;

  case 27: // call_params_list: LEFT_PAREN RIGHT_PAREN
#line 195 "grammar/syntax.y"
                           {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
}
#line 1686 "grammar/build/syntax.tab.cc"
    break;

  case 28: // call_params: call_params COMMA expr
#line 199 "grammar/syntax.y"
                                    {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[2].value.as < vector<ExpressionNode*> > ();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 1695 "grammar/build/syntax.tab.cc"
    break;

  case 29: // call_params: expr
#line 202 "grammar/syntax.y"
         {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 1704 "grammar/build/syntax.tab.cc"
    break;

  case 30: // enum: ENUM name enum_values END_ENUM SEMICOLON
#line 207 "grammar/syntax.y"
                                               {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1712 "grammar/build/syntax.tab.cc"
    break;

  case 31: // enum: ENUM name END_ENUM SEMICOLON
#line 209 "grammar/syntax.y"
                                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1720 "grammar/build/syntax.tab.cc"
    break;

  case 32: // enum_values: enum_values COMMA CONST_NAME
#line 213 "grammar/syntax.y"
                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1728 "grammar/build/syntax.tab.cc"
    break;

  case 33: // enum_values: CONST_NAME
#line 215 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1736 "grammar/build/syntax.tab.cc"
    break;

  case 34: // struct: STRUCT name struct_attrs END_STRUCT SEMICOLON
#line 219 "grammar/syntax.y"
                                                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1744 "grammar/build/syntax.tab.cc"
    break;

  case 35: // struct: STRUCT name END_STRUCT SEMICOLON
#line 221 "grammar/syntax.y"
                                     {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1752 "grammar/build/syntax.tab.cc"
    break;

  case 36: // struct_attrs: struct_attrs struct_attr SEMICOLON
#line 225 "grammar/syntax.y"
                                                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1760 "grammar/build/syntax.tab.cc"
    break;

  case 37: // struct_attrs: struct_attr SEMICOLON
#line 227 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1768 "grammar/build/syntax.tab.cc"
    break;

  case 38: // struct_attr: id_list COLON type
#line 231 "grammar/syntax.y"
                                {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1776 "grammar/build/syntax.tab.cc"
    break;

  case 39: // trait: TRAIT name trait_subprograms END_TRAIT SEMICOLON
#line 235 "grammar/syntax.y"
                                                        {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1784 "grammar/build/syntax.tab.cc"
    break;

  case 40: // trait: TRAIT name END_TRAIT SEMICOLON
#line 237 "grammar/syntax.y"
                                   {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1792 "grammar/build/syntax.tab.cc"
    break;

  case 41: // trait_subprograms: trait_subprograms trait_subprogram
#line 241 "grammar/syntax.y"
                                                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1800 "grammar/build/syntax.tab.cc"
    break;

  case 42: // trait_subprograms: trait_subprogram
#line 243 "grammar/syntax.y"
                     {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1808 "grammar/build/syntax.tab.cc"
    break;

  case 43: // trait_subprogram: trait_fn
#line 247 "grammar/syntax.y"
                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1816 "grammar/build/syntax.tab.cc"
    break;

  case 44: // trait_subprogram: trait_proc
#line 249 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1824 "grammar/build/syntax.tab.cc"
    break;

  case 45: // trait_fn: FUNCTION ID params_self_list COLON type END_FUNCTION SEMICOLON
#line 253 "grammar/syntax.y"
                                                                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1832 "grammar/build/syntax.tab.cc"
    break;

  case 46: // trait_fn: FUNCTION ID params_list COLON type END_FUNCTION SEMICOLON
#line 255 "grammar/syntax.y"
                                                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1840 "grammar/build/syntax.tab.cc"
    break;

  case 47: // trait_fn: fn
#line 257 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1848 "grammar/build/syntax.tab.cc"
    break;

  case 48: // trait_proc: PROCEDURE ID params_self_list END_PROCEDURE SEMICOLON
#line 261 "grammar/syntax.y"
                                                                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1856 "grammar/build/syntax.tab.cc"
    break;

  case 49: // trait_proc: proc
#line 263 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1864 "grammar/build/syntax.tab.cc"
    break;

  case 50: // impl: IMPL name impl_subprograms END_IMPL SEMICOLON
#line 267 "grammar/syntax.y"
                                                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1872 "grammar/build/syntax.tab.cc"
    break;

  case 51: // impl: IMPL name END_IMPL SEMICOLON
#line 269 "grammar/syntax.y"
                                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1880 "grammar/build/syntax.tab.cc"
    break;

  case 52: // impl: IMPL name impl_subprograms FOR name END_IMPL SEMICOLON
#line 271 "grammar/syntax.y"
                                                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1888 "grammar/build/syntax.tab.cc"
    break;

  case 53: // impl: IMPL name FOR name END_IMPL SEMICOLON
#line 273 "grammar/syntax.y"
                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1896 "grammar/build/syntax.tab.cc"
    break;

  case 54: // impl_subprograms: impl_subprograms impl_subprogram
#line 277 "grammar/syntax.y"
                                                   {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1904 "grammar/build/syntax.tab.cc"
    break;

  case 55: // impl_subprograms: impl_subprogram
#line 279 "grammar/syntax.y"
                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1912 "grammar/build/syntax.tab.cc"
    break;

  case 56: // impl_subprogram: impl_fn
#line 283 "grammar/syntax.y"
                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1920 "grammar/build/syntax.tab.cc"
    break;

  case 57: // impl_subprogram: impl_proc
#line 285 "grammar/syntax.y"
              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1928 "grammar/build/syntax.tab.cc"
    break;

  case 58: // impl_fn: FUNCTION ID params_self_list COLON type stmts END_FUNCTION SEMICOLON
#line 289 "grammar/syntax.y"
                                                                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1936 "grammar/build/syntax.tab.cc"
    break;

  case 59: // impl_fn: fn
#line 291 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1944 "grammar/build/syntax.tab.cc"
    break;

  case 60: // impl_proc: PROCEDURE ID params_self_list stmts END_PROCEDURE SEMICOLON
#line 295 "grammar/syntax.y"
                                                                       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1952 "grammar/build/syntax.tab.cc"
    break;

  case 61: // impl_proc: PROCEDURE ID params_self_list END_PROCEDURE SEMICOLON
#line 297 "grammar/syntax.y"
                                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1960 "grammar/build/syntax.tab.cc"
    break;

  case 62: // impl_proc: proc
#line 299 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1968 "grammar/build/syntax.tab.cc"
    break;

  case 63: // access: access DOT CONST_NAME
#line 303 "grammar/syntax.y"
                              {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < string > (), yystack_[2].value.as < AccessNode* > (), AccessType::DOT);
}
#line 1976 "grammar/build/syntax.tab.cc"
    break;

  case 64: // access: access DOT ID
#line 305 "grammar/syntax.y"
                  {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < string > (), yystack_[2].value.as < AccessNode* > (), AccessType::DOT);
}
#line 1984 "grammar/build/syntax.tab.cc"
    break;

  case 65: // access: access LEFT_BRACKET expr RIGHT_BRACKET
#line 307 "grammar/syntax.y"
                                           {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[3].value.as < AccessNode* > (), yystack_[1].value.as < ExpressionNode* > ());
}
#line 1992 "grammar/build/syntax.tab.cc"
    break;

  case 66: // access: access DOUBLE_COLON ID
#line 309 "grammar/syntax.y"
                           {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < string > (), yystack_[2].value.as < AccessNode* > (), AccessType::STATIC);
}
#line 2000 "grammar/build/syntax.tab.cc"
    break;

  case 67: // access: subprogram_call
#line 311 "grammar/syntax.y"
                    {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < SubprogramCallNode* > ());
}
#line 2008 "grammar/build/syntax.tab.cc"
    break;

  case 68: // access: access_base
#line 313 "grammar/syntax.y"
                {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < AccessBaseNode* > ());
}
#line 2016 "grammar/build/syntax.tab.cc"
    break;

  case 69: // access_base: SELF
#line 317 "grammar/syntax.y"
                  {
  yylhs.value.as < AccessBaseNode* > () = new AccessBaseNode(ctx.line);
}
#line 2024 "grammar/build/syntax.tab.cc"
    break;

  case 70: // access_base: id
#line 319 "grammar/syntax.y"
       {
  yylhs.value.as < AccessBaseNode* > () = new AccessBaseNode(ctx.line, yystack_[0].value.as < string > ());
}
#line 2032 "grammar/build/syntax.tab.cc"
    break;

  case 71: // access_base: LEFT_PAREN expr RIGHT_PAREN
#line 321 "grammar/syntax.y"
                                {
  yylhs.value.as < AccessBaseNode* > () = new AccessBaseNode(ctx.line, yystack_[1].value.as < ExpressionNode* > ());
}
#line 2040 "grammar/build/syntax.tab.cc"
    break;

  case 72: // id: NAME
#line 325 "grammar/syntax.y"
         {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 2048 "grammar/build/syntax.tab.cc"
    break;

  case 73: // id: ID
#line 327 "grammar/syntax.y"
       {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 2056 "grammar/build/syntax.tab.cc"
    break;

  case 74: // name: NAME
#line 331 "grammar/syntax.y"
           {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 2064 "grammar/build/syntax.tab.cc"
    break;

  case 75: // name: CONST_NAME
#line 333 "grammar/syntax.y"
               {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 2072 "grammar/build/syntax.tab.cc"
    break;

  case 76: // stmts: stmts stmt SEMICOLON
#line 337 "grammar/syntax.y"
                            {
  yylhs.value.as < vector<Node*> > () = yystack_[2].value.as < vector<Node*> > ();
  yylhs.value.as < vector<Node*> > ().push_back(yystack_[1].value.as < Node* > ());
}
#line 2081 "grammar/build/syntax.tab.cc"
    break;

  case 77: // stmts: stmt SEMICOLON
#line 340 "grammar/syntax.y"
                   {
  yylhs.value.as < vector<Node*> > () = vector<Node*>();
  yylhs.value.as < vector<Node*> > ().push_back(yystack_[1].value.as < Node* > ());
}
#line 2090 "grammar/build/syntax.tab.cc"
    break;

  case 78: // stmt: BREAK
#line 345 "grammar/syntax.y"
            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2098 "grammar/build/syntax.tab.cc"
    break;

  case 79: // stmt: CONTINUE
#line 347 "grammar/syntax.y"
             {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2106 "grammar/build/syntax.tab.cc"
    break;

  case 80: // stmt: attr
#line 349 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < AttrNode* > ();
}
#line 2114 "grammar/build/syntax.tab.cc"
    break;

  case 81: // stmt: assign
#line 351 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < AssignNode* > ();
}
#line 2122 "grammar/build/syntax.tab.cc"
    break;

  case 82: // stmt: return
#line 353 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ReturnNode* > ();
}
#line 2130 "grammar/build/syntax.tab.cc"
    break;

  case 83: // stmt: if
#line 355 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = yystack_[0].value.as < IfNode* > ();
}
#line 2138 "grammar/build/syntax.tab.cc"
    break;

  case 84: // stmt: for
#line 357 "grammar/syntax.y"
        {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ForNode* > ();
}
#line 2146 "grammar/build/syntax.tab.cc"
    break;

  case 85: // stmt: while
#line 359 "grammar/syntax.y"
          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < WhileNode* > ();
}
#line 2154 "grammar/build/syntax.tab.cc"
    break;

  case 86: // stmt: repeat
#line 361 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < WhileNode* > ();
}
#line 2162 "grammar/build/syntax.tab.cc"
    break;

  case 87: // stmt: switch
#line 363 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < SwitchNode* > ();
}
#line 2170 "grammar/build/syntax.tab.cc"
    break;

  case 88: // stmt: expr
#line 365 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2178 "grammar/build/syntax.tab.cc"
    break;

  case 89: // return: RETURN expr
#line 369 "grammar/syntax.y"
                    {
  yylhs.value.as < ReturnNode* > () = new ReturnNode(ctx.line, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2186 "grammar/build/syntax.tab.cc"
    break;

  case 90: // attr: VAR ID COLON type ATTR expr
#line 373 "grammar/syntax.y"
                                  {
  yylhs.value.as < AttrNode* > () = new AttrNode(ctx.line, yystack_[4].value.as < string > (), false, *yystack_[2].value.as < Type* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2194 "grammar/build/syntax.tab.cc"
    break;

  case 91: // attr: CONST ID COLON type ATTR expr
#line 375 "grammar/syntax.y"
                                  {
  yylhs.value.as < AttrNode* > () = new AttrNode(ctx.line, yystack_[4].value.as < string > (), true, *yystack_[2].value.as < Type* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2202 "grammar/build/syntax.tab.cc"
    break;

  case 92: // type: TYPE_INT
#line 379 "grammar/syntax.y"
               {
  yylhs.value.as < Type* > () = new Type(TypeKind::INT);
}
#line 2210 "grammar/build/syntax.tab.cc"
    break;

  case 93: // type: TYPE_FLOAT
#line 381 "grammar/syntax.y"
               {
  yylhs.value.as < Type* > () = new Type(TypeKind::FLOAT);
}
#line 2218 "grammar/build/syntax.tab.cc"
    break;

  case 94: // type: TYPE_DOUBLE
#line 383 "grammar/syntax.y"
                {
  yylhs.value.as < Type* > () = new Type(TypeKind::DOUBLE);
}
#line 2226 "grammar/build/syntax.tab.cc"
    break;

  case 95: // type: TYPE_LONG
#line 385 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::LONG);
}
#line 2234 "grammar/build/syntax.tab.cc"
    break;

  case 96: // type: TYPE_BYTE
#line 387 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::BYTE);
}
#line 2242 "grammar/build/syntax.tab.cc"
    break;

  case 97: // type: TYPE_STRING
#line 389 "grammar/syntax.y"
                {
  yylhs.value.as < Type* > () = new Type(TypeKind::STRING);
}
#line 2250 "grammar/build/syntax.tab.cc"
    break;

  case 98: // type: TYPE_CHAR
#line 391 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::CHAR);
}
#line 2258 "grammar/build/syntax.tab.cc"
    break;

  case 99: // type: TYPE_BOOL
#line 393 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::BOOL);
}
#line 2266 "grammar/build/syntax.tab.cc"
    break;

  case 100: // type: type LEFT_BRACKET RIGHT_BRACKET
#line 395 "grammar/syntax.y"
                                    {
  yylhs.value.as < Type* > () = new Type(TypeKind::ARRAY, yystack_[2].value.as < Type* > ());
}
#line 2274 "grammar/build/syntax.tab.cc"
    break;

  case 101: // type: TYPE_POINTER LT type GT
#line 397 "grammar/syntax.y"
                            {
  yylhs.value.as < Type* > () = new Type(TypeKind::POINTER, yystack_[1].value.as < Type* > ());
}
#line 2282 "grammar/build/syntax.tab.cc"
    break;

  case 102: // type: TYPE_OPTION LT type GT
#line 399 "grammar/syntax.y"
                           {
  yylhs.value.as < Type* > () = new Type(TypeKind::OPTION, yystack_[1].value.as < Type* > ());
}
#line 2290 "grammar/build/syntax.tab.cc"
    break;

  case 103: // assign: access ATTR expr
#line 403 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2298 "grammar/build/syntax.tab.cc"
    break;

  case 104: // assign: access AND_ATTR expr
#line 405 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::AND, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2306 "grammar/build/syntax.tab.cc"
    break;

  case 105: // assign: access OR_ATTR expr
#line 407 "grammar/syntax.y"
                        {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::OR, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2314 "grammar/build/syntax.tab.cc"
    break;

  case 106: // assign: access LAZY_AND_ATTR expr
#line 409 "grammar/syntax.y"
                              {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::BITWISE_AND, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2322 "grammar/build/syntax.tab.cc"
    break;

  case 107: // assign: access LAZY_OR_ATTR expr
#line 411 "grammar/syntax.y"
                             {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::BITWISE_OR, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2330 "grammar/build/syntax.tab.cc"
    break;

  case 108: // assign: access XOR_ATTR expr
#line 413 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::XOR, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2338 "grammar/build/syntax.tab.cc"
    break;

  case 109: // assign: access CONCAT_ATTR expr
#line 415 "grammar/syntax.y"
                            {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::CONCAT, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2346 "grammar/build/syntax.tab.cc"
    break;

  case 110: // assign: access MOD_ATTR expr
#line 417 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::MOD, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2354 "grammar/build/syntax.tab.cc"
    break;

  case 111: // assign: access PLUS_ATTR expr
#line 419 "grammar/syntax.y"
                          {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::PLUS, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2362 "grammar/build/syntax.tab.cc"
    break;

  case 112: // assign: access MINUS_ATTR expr
#line 421 "grammar/syntax.y"
                           {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::MINUS, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2370 "grammar/build/syntax.tab.cc"
    break;

  case 113: // assign: access MULT_ATTR expr
#line 423 "grammar/syntax.y"
                          {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::MULT, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2378 "grammar/build/syntax.tab.cc"
    break;

  case 114: // assign: access DIV_ATTR expr
#line 425 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::DIV, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2386 "grammar/build/syntax.tab.cc"
    break;

  case 115: // if: IF expr THEN stmts if_end
#line 429 "grammar/syntax.y"
                              {
  yylhs.value.as < IfNode* > () = new IfNode(ctx.line, yystack_[3].value.as < ExpressionNode* > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2397 "grammar/build/syntax.tab.cc"
    break;

  case 116: // if: IF SOME ID IN access THEN stmts if_end
#line 434 "grammar/syntax.y"
                                           {
  yylhs.value.as < IfNode* > () = new IfNode(ctx.line, yystack_[3].value.as < AccessNode* > (), yystack_[5].value.as < string > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2408 "grammar/build/syntax.tab.cc"
    break;

  case 117: // if_end: ELIF expr THEN stmts if_end
#line 441 "grammar/syntax.y"
                                    {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line, yystack_[3].value.as < ExpressionNode* > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfEndNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2419 "grammar/build/syntax.tab.cc"
    break;

  case 118: // if_end: ELIF SOME ID IN access THEN stmts if_end
#line 446 "grammar/syntax.y"
                                             {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line, yystack_[3].value.as < AccessNode* > (), yystack_[5].value.as < string > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfEndNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2430 "grammar/build/syntax.tab.cc"
    break;

  case 119: // if_end: ELSE stmts END_IF
#line 451 "grammar/syntax.y"
                      {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line, new IfEndNode(ctx.line));
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfEndNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2441 "grammar/build/syntax.tab.cc"
    break;

  case 120: // if_end: END_IF
#line 456 "grammar/syntax.y"
           {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line);
}
#line 2449 "grammar/build/syntax.tab.cc"
    break;

  case 121: // switch: SWITCH expr cases END_SWITCH
#line 460 "grammar/syntax.y"
                                     {
  yylhs.value.as < SwitchNode* > () = new SwitchNode(ctx.line, yystack_[2].value.as < ExpressionNode* > (), yystack_[1].value.as < vector<CaseNode*> > ());
}
#line 2457 "grammar/build/syntax.tab.cc"
    break;

  case 122: // cases: case_list default_case
#line 464 "grammar/syntax.y"
                              {
  yylhs.value.as < vector<CaseNode*> > () = yystack_[1].value.as < vector<CaseNode*> > ();
  yylhs.value.as < vector<CaseNode*> > ().push_back(yystack_[0].value.as < CaseNode* > ());
}
#line 2466 "grammar/build/syntax.tab.cc"
    break;

  case 123: // cases: default_case
#line 467 "grammar/syntax.y"
                 {
  yylhs.value.as < vector<CaseNode*> > () = vector<CaseNode*>();
  yylhs.value.as < vector<CaseNode*> > ().push_back(yystack_[0].value.as < CaseNode* > ());
}
#line 2475 "grammar/build/syntax.tab.cc"
    break;

  case 124: // case_list: case_list case
#line 472 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<CaseNode*> > () = yystack_[1].value.as < vector<CaseNode*> > ();
  yylhs.value.as < vector<CaseNode*> > ().push_back(yystack_[0].value.as < CaseNode* > ());
}
#line 2484 "grammar/build/syntax.tab.cc"
    break;

  case 125: // case_list: case
#line 475 "grammar/syntax.y"
         {
  yylhs.value.as < vector<CaseNode*> > () = vector<CaseNode*>();
  yylhs.value.as < vector<CaseNode*> > ().push_back(yystack_[0].value.as < CaseNode* > ());
}
#line 2493 "grammar/build/syntax.tab.cc"
    break;

  case 126: // case: CASE case_values COLON stmts
#line 480 "grammar/syntax.y"
                                   {
  yylhs.value.as < CaseNode* > () = new CaseNode(ctx.line, yystack_[2].value.as < vector<ExpressionNode*> > ());
  for (size_t i = 0; i < yystack_[0].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < CaseNode* > ()->children.push_back(yystack_[0].value.as < vector<Node*> > ()[i]);
  };
}
#line 2504 "grammar/build/syntax.tab.cc"
    break;

  case 127: // case_values: case_values COMMA term
#line 487 "grammar/syntax.y"
                                    {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[2].value.as < vector<ExpressionNode*> > ();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 2513 "grammar/build/syntax.tab.cc"
    break;

  case 128: // case_values: term
#line 490 "grammar/syntax.y"
         {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 2522 "grammar/build/syntax.tab.cc"
    break;

  case 129: // default_case: DEFAULT COLON stmts
#line 495 "grammar/syntax.y"
                                  {
  yylhs.value.as < CaseNode* > () = new CaseNode(ctx.line);
  for (size_t i = 0; i < yystack_[0].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < CaseNode* > ()->children.push_back(yystack_[0].value.as < vector<Node*> > ()[i]);
  };
}
#line 2533 "grammar/build/syntax.tab.cc"
    break;

  case 130: // for: FOR LEFT_PAREN ID IN expr RIGHT_PAREN stmts END_FOR
#line 502 "grammar/syntax.y"
                                                         {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[5].value.as < string > (), yystack_[3].value.as < ExpressionNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < ForNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2544 "grammar/build/syntax.tab.cc"
    break;

  case 131: // for: FOR LEFT_PAREN ID IN expr RIGHT_PAREN END_FOR
#line 507 "grammar/syntax.y"
                                                  {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[4].value.as < string > (), yystack_[2].value.as < ExpressionNode* > ());
}
#line 2552 "grammar/build/syntax.tab.cc"
    break;

  case 132: // for: FOR LEFT_PAREN attr SEMICOLON expr SEMICOLON expr RIGHT_PAREN stmts END_FOR
#line 509 "grammar/syntax.y"
                                                                                {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[7].value.as < AttrNode* > (), yystack_[5].value.as < ExpressionNode* > (), yystack_[3].value.as < ExpressionNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < ForNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2563 "grammar/build/syntax.tab.cc"
    break;

  case 133: // for: FOR LEFT_PAREN attr SEMICOLON expr SEMICOLON expr RIGHT_PAREN END_FOR
#line 514 "grammar/syntax.y"
                                                                          {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[6].value.as < AttrNode* > (), yystack_[4].value.as < ExpressionNode* > (), yystack_[2].value.as < ExpressionNode* > ());
}
#line 2571 "grammar/build/syntax.tab.cc"
    break;

  case 134: // while: WHILE LEFT_PAREN expr RIGHT_PAREN stmts END_WHILE
#line 518 "grammar/syntax.y"
                                                         {
  yylhs.value.as < WhileNode* > () = new WhileNode(ctx.line, yystack_[3].value.as < ExpressionNode* > (), WhileType::WHILE);
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < WhileNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2582 "grammar/build/syntax.tab.cc"
    break;

  case 135: // while: WHILE LEFT_PAREN expr RIGHT_PAREN END_WHILE
#line 523 "grammar/syntax.y"
                                                {
  yylhs.value.as < WhileNode* > () = new WhileNode(ctx.line, yystack_[2].value.as < ExpressionNode* > (), WhileType::WHILE);
}
#line 2590 "grammar/build/syntax.tab.cc"
    break;

  case 136: // repeat: REPEAT stmts UNTIL expr
#line 527 "grammar/syntax.y"
                                {
  yylhs.value.as < WhileNode* > () = new WhileNode(ctx.line, yystack_[0].value.as < ExpressionNode* > (), WhileType::REPEAT);
  for (size_t i = 0; i < yystack_[2].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < WhileNode* > ()->children.push_back(yystack_[2].value.as < vector<Node*> > ()[i]);
  };
}
#line 2601 "grammar/build/syntax.tab.cc"
    break;

  case 137: // repeat: REPEAT UNTIL expr
#line 532 "grammar/syntax.y"
                      {
  yylhs.value.as < WhileNode* > () = new WhileNode(ctx.line, yystack_[0].value.as < ExpressionNode* > (), WhileType::REPEAT);
}
#line 2609 "grammar/build/syntax.tab.cc"
    break;

  case 138: // expr: or_expr
#line 536 "grammar/syntax.y"
              {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2617 "grammar/build/syntax.tab.cc"
    break;

  case 139: // expr: range_expr
#line 538 "grammar/syntax.y"
               {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < RangeNode* > ();
}
#line 2625 "grammar/build/syntax.tab.cc"
    break;

  case 140: // range_expr: range_interval or_expr
#line 542 "grammar/syntax.y"
                                   {
  yylhs.value.as < RangeNode* > () = new RangeNode(ctx.line, false, yystack_[0].value.as < ExpressionNode* > (), yystack_[1].value.as < pair<RangeInclusionType, RangeInclusionType> > ().second);
}
#line 2633 "grammar/build/syntax.tab.cc"
    break;

  case 141: // range_expr: or_expr range_interval
#line 544 "grammar/syntax.y"
                           {
  yylhs.value.as < RangeNode* > () = new RangeNode(ctx.line, true, yystack_[1].value.as < ExpressionNode* > (), yystack_[0].value.as < pair<RangeInclusionType, RangeInclusionType> > ().first);
}
#line 2641 "grammar/build/syntax.tab.cc"
    break;

  case 142: // range_expr: or_expr range_interval or_expr
#line 546 "grammar/syntax.y"
                                   {
  yylhs.value.as < RangeNode* > () = new RangeNode(ctx.line, yystack_[2].value.as < ExpressionNode* > (), yystack_[1].value.as < pair<RangeInclusionType, RangeInclusionType> > ().first, yystack_[0].value.as < ExpressionNode* > (), yystack_[1].value.as < pair<RangeInclusionType, RangeInclusionType> > ().second);
}
#line 2649 "grammar/build/syntax.tab.cc"
    break;

  case 143: // range_interval: RANGE
#line 550 "grammar/syntax.y"
                      {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::INCLUSIVE, RangeInclusionType::EXCLUSIVE};
}
#line 2657 "grammar/build/syntax.tab.cc"
    break;

  case 144: // range_interval: RANGE_EXC
#line 552 "grammar/syntax.y"
              {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::EXCLUSIVE, RangeInclusionType::EXCLUSIVE};
}
#line 2665 "grammar/build/syntax.tab.cc"
    break;

  case 145: // range_interval: RANGE_EXC_INC
#line 554 "grammar/syntax.y"
                  {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::EXCLUSIVE, RangeInclusionType::INCLUSIVE};
}
#line 2673 "grammar/build/syntax.tab.cc"
    break;

  case 146: // range_interval: RANGE_INC
#line 556 "grammar/syntax.y"
              {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::INCLUSIVE, RangeInclusionType::INCLUSIVE};
}
#line 2681 "grammar/build/syntax.tab.cc"
    break;

  case 147: // or_expr: or_expr OR and_expr
#line 560 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::OR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2689 "grammar/build/syntax.tab.cc"
    break;

  case 148: // or_expr: and_expr
#line 562 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2697 "grammar/build/syntax.tab.cc"
    break;

  case 149: // and_expr: and_expr AND bit_or_expr
#line 566 "grammar/syntax.y"
                                   {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::AND, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2705 "grammar/build/syntax.tab.cc"
    break;

  case 150: // and_expr: bit_or_expr
#line 568 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2713 "grammar/build/syntax.tab.cc"
    break;

  case 151: // bit_or_expr: bit_or_expr BAR bit_xor_expr
#line 572 "grammar/syntax.y"
                                          {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::BITWISE_OR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2721 "grammar/build/syntax.tab.cc"
    break;

  case 152: // bit_or_expr: bit_xor_expr
#line 574 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2729 "grammar/build/syntax.tab.cc"
    break;

  case 153: // bit_xor_expr: bit_xor_expr XOR bit_and_expr
#line 578 "grammar/syntax.y"
                                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::XOR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2737 "grammar/build/syntax.tab.cc"
    break;

  case 154: // bit_xor_expr: bit_and_expr
#line 580 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2745 "grammar/build/syntax.tab.cc"
    break;

  case 155: // bit_and_expr: bit_and_expr REF equals_expr
#line 584 "grammar/syntax.y"
                                           {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::BITWISE_AND, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2753 "grammar/build/syntax.tab.cc"
    break;

  case 156: // bit_and_expr: equals_expr
#line 586 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2761 "grammar/build/syntax.tab.cc"
    break;

  case 157: // equals_expr: equals_expr EQ rel_expr
#line 590 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2769 "grammar/build/syntax.tab.cc"
    break;

  case 158: // equals_expr: equals_expr NOT_EQ rel_expr
#line 592 "grammar/syntax.y"
                                {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::NOT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2777 "grammar/build/syntax.tab.cc"
    break;

  case 159: // equals_expr: rel_expr
#line 594 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2785 "grammar/build/syntax.tab.cc"
    break;

  case 160: // rel_expr: rel_expr LT concat_expr
#line 598 "grammar/syntax.y"
                                  {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::LT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2793 "grammar/build/syntax.tab.cc"
    break;

  case 161: // rel_expr: rel_expr GT concat_expr
#line 600 "grammar/syntax.y"
                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::GT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2801 "grammar/build/syntax.tab.cc"
    break;

  case 162: // rel_expr: rel_expr LT_EQ concat_expr
#line 602 "grammar/syntax.y"
                               {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::LT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2809 "grammar/build/syntax.tab.cc"
    break;

  case 163: // rel_expr: rel_expr GT_EQ concat_expr
#line 604 "grammar/syntax.y"
                               {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::GT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2817 "grammar/build/syntax.tab.cc"
    break;

  case 164: // rel_expr: rel_expr IN concat_expr
#line 606 "grammar/syntax.y"
                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::IN, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2825 "grammar/build/syntax.tab.cc"
    break;

  case 165: // rel_expr: concat_expr
#line 608 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2833 "grammar/build/syntax.tab.cc"
    break;

  case 166: // concat_expr: concat_expr CONCAT sum_expr
#line 612 "grammar/syntax.y"
                                         {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::CONCAT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2841 "grammar/build/syntax.tab.cc"
    break;

  case 167: // concat_expr: sum_expr
#line 614 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2849 "grammar/build/syntax.tab.cc"
    break;

  case 168: // sum_expr: sum_expr PLUS mult_expr
#line 618 "grammar/syntax.y"
                                  {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::PLUS, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2857 "grammar/build/syntax.tab.cc"
    break;

  case 169: // sum_expr: sum_expr MINUS mult_expr
#line 620 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MINUS, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2865 "grammar/build/syntax.tab.cc"
    break;

  case 170: // sum_expr: mult_expr
#line 622 "grammar/syntax.y"
              {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2873 "grammar/build/syntax.tab.cc"
    break;

  case 171: // mult_expr: mult_expr MULT unary_expr
#line 626 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MULT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2881 "grammar/build/syntax.tab.cc"
    break;

  case 172: // mult_expr: mult_expr DIV unary_expr
#line 628 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::DIV, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2889 "grammar/build/syntax.tab.cc"
    break;

  case 173: // mult_expr: mult_expr MOD unary_expr
#line 630 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MOD, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2897 "grammar/build/syntax.tab.cc"
    break;

  case 174: // mult_expr: unary_expr
#line 632 "grammar/syntax.y"
               {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2905 "grammar/build/syntax.tab.cc"
    break;

  case 175: // unary_expr: MINUS exp_expr
#line 636 "grammar/syntax.y"
                           {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::MINUS, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2913 "grammar/build/syntax.tab.cc"
    break;

  case 176: // unary_expr: REV exp_expr
#line 638 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::REV, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2921 "grammar/build/syntax.tab.cc"
    break;

  case 177: // unary_expr: NOT exp_expr
#line 640 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::NOT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2929 "grammar/build/syntax.tab.cc"
    break;

  case 178: // unary_expr: REF exp_expr
#line 642 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::REF, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2937 "grammar/build/syntax.tab.cc"
    break;

  case 179: // unary_expr: INCREMENT exp_expr
#line 644 "grammar/syntax.y"
                       {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::INCREMENT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2945 "grammar/build/syntax.tab.cc"
    break;

  case 180: // unary_expr: DECREMENT exp_expr
#line 646 "grammar/syntax.y"
                       {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::DECREMENT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2953 "grammar/build/syntax.tab.cc"
    break;

  case 181: // unary_expr: MULT exp_expr
#line 648 "grammar/syntax.y"
                  {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2961 "grammar/build/syntax.tab.cc"
    break;

  case 182: // unary_expr: exp_expr
#line 650 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2969 "grammar/build/syntax.tab.cc"
    break;

  case 183: // exp_expr: postfix_expr EXP exp_expr
#line 654 "grammar/syntax.y"
                                    {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::EXP, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2977 "grammar/build/syntax.tab.cc"
    break;

  case 184: // exp_expr: postfix_expr
#line 656 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2985 "grammar/build/syntax.tab.cc"
    break;

  case 185: // postfix_expr: term INCREMENT
#line 660 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(true, UnaryOperation::INCREMENT, yystack_[1].value.as < ExpressionNode* > ());
}
#line 2993 "grammar/build/syntax.tab.cc"
    break;

  case 186: // postfix_expr: term DECREMENT
#line 662 "grammar/syntax.y"
                   {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(true, UnaryOperation::DECREMENT, yystack_[1].value.as < ExpressionNode* > ());
}
#line 3001 "grammar/build/syntax.tab.cc"
    break;

  case 187: // postfix_expr: term
#line 664 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 3009 "grammar/build/syntax.tab.cc"
    break;

  case 188: // term: INT
#line 668 "grammar/syntax.y"
          {
  yylhs.value.as < ExpressionNode* > () = new IntNode(ctx.line, yystack_[0].value.as < int32_t > ());
}
#line 3017 "grammar/build/syntax.tab.cc"
    break;

  case 189: // term: LONG
#line 670 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new LongNode(ctx.line, yystack_[0].value.as < int64_t > ());
}
#line 3025 "grammar/build/syntax.tab.cc"
    break;

  case 190: // term: FLOAT
#line 672 "grammar/syntax.y"
          {
  yylhs.value.as < ExpressionNode* > () = new FloatNode(ctx.line, yystack_[0].value.as < float > ());
}
#line 3033 "grammar/build/syntax.tab.cc"
    break;

  case 191: // term: DOUBLE
#line 674 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = new DoubleNode(ctx.line, yystack_[0].value.as < double > ());
}
#line 3041 "grammar/build/syntax.tab.cc"
    break;

  case 192: // term: BYTE
#line 676 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new ByteNode(ctx.line, yystack_[0].value.as < uint8_t > ());
}
#line 3049 "grammar/build/syntax.tab.cc"
    break;

  case 193: // term: BOOL
#line 678 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new BoolNode(ctx.line, yystack_[0].value.as < bool > ());
}
#line 3057 "grammar/build/syntax.tab.cc"
    break;

  case 194: // term: STRING
#line 680 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = new StringNode(ctx.line, yystack_[0].value.as < string > ());
}
#line 3065 "grammar/build/syntax.tab.cc"
    break;

  case 195: // term: CHAR
#line 682 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new CharNode(ctx.line, yystack_[0].value.as < char > ());
}
#line 3073 "grammar/build/syntax.tab.cc"
    break;

  case 196: // term: NONE
#line 684 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new OptionNode(ctx.line, Option());
}
#line 3081 "grammar/build/syntax.tab.cc"
    break;

  case 197: // term: array_allocation
#line 686 "grammar/syntax.y"
                     {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ArrayAllocationNode* > ();
}
#line 3089 "grammar/build/syntax.tab.cc"
    break;

  case 198: // term: struct_allocation
#line 688 "grammar/syntax.y"
                      {
  yylhs.value.as < ExpressionNode* > () = nullptr;
}
#line 3097 "grammar/build/syntax.tab.cc"
    break;

  case 199: // term: access
#line 690 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < AccessNode* > ();
}
#line 3105 "grammar/build/syntax.tab.cc"
    break;

  case 200: // term: SOME LEFT_PAREN expr RIGHT_PAREN
#line 692 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new OptionNode(ctx.line, Option());
}
#line 3113 "grammar/build/syntax.tab.cc"
    break;

  case 201: // array_allocation: NEW type LEFT_BRACKET expr RIGHT_BRACKET
#line 696 "grammar/syntax.y"
                                                           {
  yylhs.value.as < ArrayAllocationNode* > () = new ArrayAllocationNode(ctx.line, *yystack_[3].value.as < Type* > (), yystack_[1].value.as < ExpressionNode* > ());
}
#line 3121 "grammar/build/syntax.tab.cc"
    break;

  case 202: // array_allocation: NEW type LEFT_BRACKET expr RIGHT_BRACKET LEFT_BRACE array_allocation_values RIGHT_BRACE
#line 698 "grammar/syntax.y"
                                                                                            {
  yylhs.value.as < ArrayAllocationNode* > () = new ArrayAllocationNode(ctx.line, *yystack_[6].value.as < Type* > (), yystack_[4].value.as < ExpressionNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<ExpressionNode*> > ().size(); i++) {
    yylhs.value.as < ArrayAllocationNode* > ()->children.push_back(yystack_[1].value.as < vector<ExpressionNode*> > ()[i]);
  };
}
#line 3132 "grammar/build/syntax.tab.cc"
    break;

  case 203: // array_allocation_values: array_allocation_values COMMA expr
#line 705 "grammar/syntax.y"
                                                            {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[2].value.as < vector<ExpressionNode*> > ();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 3141 "grammar/build/syntax.tab.cc"
    break;

  case 204: // array_allocation_values: expr
#line 708 "grammar/syntax.y"
         {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 3150 "grammar/build/syntax.tab.cc"
    break;

  case 205: // struct_allocation: NEW type LEFT_BRACE struct_allocation_values RIGHT_BRACE
#line 713 "grammar/syntax.y"
                                                                            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3158 "grammar/build/syntax.tab.cc"
    break;

  case 206: // struct_allocation: NEW type LEFT_BRACE RIGHT_BRACE
#line 715 "grammar/syntax.y"
                                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3166 "grammar/build/syntax.tab.cc"
    break;

  case 207: // struct_allocation_values: struct_allocation_values COMMA ID COLON expr
#line 719 "grammar/syntax.y"
                                                                       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3174 "grammar/build/syntax.tab.cc"
    break;

  case 208: // struct_allocation_values: ID COLON expr
#line 721 "grammar/syntax.y"
                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3182 "grammar/build/syntax.tab.cc"
    break;


#line 3186 "grammar/build/syntax.tab.cc"

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








  const short parser::yypact_ninf_ = -377;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     131,     4,    71,   205,   205,   205,   205,    88,   131,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,    56,    56,  -377,
    -377,    22,    18,    36,   -56,  -377,  -377,     1,    29,   638,
    -377,    60,   -55,  -377,    77,   175,    19,    90,   205,   127,
     158,   116,  -377,  -377,    43,  -377,  -377,  -377,   191,   201,
     152,  -377,  -377,    57,  -377,  -377,  -377,  -377,   -28,  -377,
     187,   394,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
     177,   181,   174,   174,   174,   174,   174,   174,   174,   394,
     221,   225,  -377,  -377,  -377,  -377,  2643,  2711,   167,   169,
     745,  -377,  -377,  2643,   185,  -377,   178,  -377,  2643,  -377,
    2887,  -377,  -377,   852,   206,  -377,  -377,    13,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  2847,    99,   236,   237,
     229,   242,    67,   -11,   256,   203,    94,  -377,  -377,   263,
     235,  -377,  -377,  -377,   279,   222,  -377,   283,   394,   226,
     227,  -377,   192,   230,   230,  -377,   205,   232,  -377,   230,
     230,  -377,   238,  -377,   290,  -377,   394,   959,   394,   394,
     101,  -377,  -377,  -377,  -377,  -377,  -377,  -377,    80,   239,
     244,   233,     3,   240,    16,  2643,  2643,  1066,   172,  2643,
    -377,  -377,  2643,  2643,  2643,  2643,  2643,  2643,  2643,  2643,
    2643,  2643,  2643,  2643,   161,   296,  2457,  2643,  -377,   245,
     248,  -377,   246,  -377,   280,  2847,  2847,  2847,  2847,  2847,
    2847,  2847,  2847,  2847,  2847,  2847,  2847,  2847,  2847,  2847,
    2847,  2847,  2847,  2847,   174,  -377,  -377,  -377,  -377,  -377,
     252,  -377,  -377,   251,    15,   258,  1173,   223,  -377,   260,
     261,   241,  -377,  -377,   252,  1280,     9,    21,  2550,    -1,
     394,   394,  -377,   243,  2350,   253,   265,   264,  -377,  2643,
     174,   270,   247,   172,  -377,  -377,   273,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,   -27,  -377,   259,  -377,  -377,  -377,   236,
     280,   237,   229,   242,    67,   -11,   -11,   256,   256,   256,
     256,   256,   203,    94,    94,  -377,  -377,  -377,  -377,  -377,
     105,   394,   272,  1387,   276,   394,   394,   278,   284,  -377,
    -377,   282,   289,  -377,    12,    63,    72,    44,   424,  2643,
    2643,  1494,  -377,   198,  -377,  2350,  -377,  -377,  -377,  -377,
    2643,  -377,  -377,   290,  -377,   959,  -377,   288,  -377,   -41,
     531,  -377,  -377,   275,  2643,   349,  -377,  2643,  2643,   133,
    -377,  2779,  2350,  -377,   291,   292,  -377,  1601,   174,  2350,
    2350,  -377,   138,  1708,  -377,   295,   299,  2643,  -377,   293,
    -377,  -377,  2350,    20,   281,  1815,  1922,  2643,  -377,  -377,
    2350,  -377,   301,  -377,  -377,  -377,    52,  2643,   424,   285,
    2350,  -377,  -377,  2029,   294,  -377,  2643,  -377,  -377,  -377,
      44,   424,  -377,  2136,  -377,   134,  -377,  -377,  2243,  2350,
    -377,   424,  -377
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
       0,     0,   192,   188,   189,   190,   191,   193,    73,    72,
     194,   195,    96,    92,    95,    93,    94,    99,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   146,   144,   145,     0,     0,     0,     0,
       0,    78,    79,     0,     0,   196,     0,    69,     0,    67,
     199,    68,    70,     0,     0,    82,    80,     0,    81,    83,
      87,    84,    85,    86,    88,   139,     0,   138,   148,   150,
     152,   154,   156,   159,   165,   167,   170,   174,   182,   184,
     187,   197,   198,    31,     0,     0,    35,     0,     0,     0,
       0,    37,     0,     0,     0,    51,     0,     0,    54,     0,
       0,    40,     0,    41,     0,    17,     0,     0,     0,     0,
     199,   180,   179,   178,   177,   176,   175,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,    77,     0,    25,   140,     0,   141,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   186,   185,    32,    30,    22,
      38,    34,    36,     0,     0,     0,     0,     0,    50,     0,
       0,     0,    39,    19,    21,     0,     0,     0,     0,     0,
       0,     0,    71,     0,     0,     0,     0,     0,   137,     0,
       0,     0,     0,     0,   125,   123,     0,   104,   105,   106,
     107,   110,   108,   111,   109,   112,   113,   114,   103,    64,
      63,    66,    27,     0,    29,     0,    13,    76,   100,   147,
     142,   149,   151,   153,   155,   157,   158,   162,   163,   160,
     161,   164,   166,   169,   168,   173,   171,   172,   183,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     102,     0,     0,   206,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,   128,     0,   121,   124,   122,   200,
       0,    26,    65,     0,    16,     0,    61,     0,    52,     0,
       0,    48,    12,   201,     0,     0,   205,     0,     0,     0,
     120,     0,     0,   115,     0,     0,   135,     0,     0,     0,
     129,    28,     0,     0,    60,     0,     0,     0,   208,     0,
      90,    91,     0,     0,     0,     0,     0,     0,   134,   127,
     126,    15,     0,    45,    46,   204,     0,     0,     0,     0,
       0,   119,   131,     0,     0,    58,     0,   202,   207,   116,
       0,     0,   130,     0,   203,     0,   117,   133,     0,     0,
     132,     0,   118
  };

  const short
  parser::yypgoto_[] =
  {
    -377,  -377,  -377,   364,  -377,    24,    26,    54,   -16,    27,
     209,   111,  -377,   257,  -377,  -377,  -377,  -377,  -377,   339,
    -377,  -377,   324,  -377,  -377,  -377,  -377,   338,  -377,  -377,
     -29,  -377,  -377,     0,    -3,   -98,  -377,   199,   -38,  -377,
    -377,  -376,  -377,  -377,  -377,   112,  -377,   113,  -377,  -377,
    -377,   -94,  -377,   268,   -96,   173,   170,   179,   171,   176,
      45,    25,   190,    42,   -13,   -66,  -377,  -263,  -377,  -377,
    -377,  -377
  };

  const short
  parser::yydefgoto_[] =
  {
       0,     7,     8,     9,    10,    11,    12,   245,    29,    58,
      59,    60,   109,   208,   293,    13,    32,    14,    36,    37,
      15,    53,    54,    55,    56,    16,    44,    45,    46,    47,
     170,   111,   112,    21,   255,   114,   115,   116,   117,   118,
     119,   373,   120,   272,   273,   274,   343,   275,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   406,
     142,   334
  };

  const short
  parser::yytable_[] =
  {
     110,    28,   181,   183,    22,    23,    24,   344,   332,   188,
      33,   144,   263,    17,   191,   210,   171,   172,   173,   174,
     175,   176,   177,   167,    33,   265,   113,    33,    33,   409,
     214,   212,   419,    30,   223,   224,   225,   226,   152,   350,
      48,   164,    49,   165,   351,   426,   145,    42,    51,    43,
      52,   178,    50,    68,    69,   432,   385,   329,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    42,   330,
      43,   110,    57,   189,   333,    90,    91,    51,   365,    52,
      18,   212,   227,   206,   110,   212,    57,   366,    25,   210,
     189,   267,   268,   212,   221,   276,    61,   187,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     240,   222,   294,   295,    96,   399,   367,    38,   416,   320,
     300,    34,   149,    31,   156,   368,    27,   417,   254,   143,
     256,   257,    39,    35,    40,   212,   153,    28,   110,    39,
     215,    40,    41,   250,   212,   231,   146,    35,   107,   157,
     232,   233,   258,    48,   259,    49,   247,   210,   110,   151,
      92,    93,    94,    95,   331,   162,   204,   154,   318,   205,
     289,   206,   290,   207,   353,   342,   354,    62,    63,    64,
      65,    66,    67,    68,    69,   155,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,   204,   204,
     159,   205,   205,   206,   206,   207,   207,   164,   246,   401,
     160,   392,   429,   249,   251,    19,    20,   110,   315,   316,
     317,   161,   335,   336,   168,   210,   110,     1,   169,     2,
     179,     3,    89,     4,   180,   110,     5,   184,     6,   185,
     210,   147,   148,   323,    96,   374,   375,   190,   307,   308,
     309,   310,   311,   147,   166,   189,   381,   229,   230,   235,
     236,   338,   270,   271,   378,   379,   305,   306,   104,   105,
     388,   313,   314,   390,   391,   211,   217,   394,   107,   210,
     218,   219,   210,   355,   220,   210,   228,   359,   360,   234,
     237,   238,   239,   405,   110,   241,   242,   210,   243,    33,
     244,   248,   210,   414,   262,   291,   260,   252,   369,   110,
     210,   261,   110,   418,   296,   210,   110,   297,   264,   298,
     319,   215,   424,   210,   212,   321,   110,   325,   326,   324,
     210,   110,   352,   210,   340,   341,   337,   345,   377,   346,
     327,   356,   380,   110,   349,   358,   339,   361,   110,   387,
     110,   110,   383,   362,   110,   363,   364,   384,   389,   410,
     407,   397,   396,   110,   403,   423,   110,   110,   404,   395,
     415,   110,    26,   253,   213,   150,   400,   163,   420,   110,
     382,   110,   158,   266,   110,   347,   348,   301,   299,   408,
     303,   425,   110,   413,   110,   216,   304,   302,     0,   110,
     110,     0,   110,     0,     0,     0,     0,   421,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,   312,     0,
     428,     0,     0,     0,     0,     0,   431,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,    85,    86,     0,     0,     0,    87,     0,
      88,     0,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,    96,     0,     0,     0,     0,     0,
      97,   370,     0,   371,   372,    98,    99,     0,   100,     0,
       0,   101,   102,   103,     0,     0,     0,     0,   104,   105,
       0,     0,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     0,     0,   108,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,     0,     0,     0,     0,     0,     0,
      85,    86,     0,     0,     0,    87,     0,    88,     0,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,     0,   212,     0,     0,     0,    97,     0,     0,
       0,     0,    98,    99,     0,   100,     0,     0,   101,   102,
     103,     0,     0,     0,     0,   104,   105,     0,   386,     0,
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
       0,     0,   104,   105,     0,     0,     0,   106,     0,     0,
       0,     0,   107,     0,     0,     0,     0,   108,    62,    63,
      64,    65,    66,    67,    68,    69,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,     0,
       0,     0,     0,     0,    85,    86,     0,     0,     0,    87,
       0,    88,     0,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,    96,     0,     0,     0,     0,
       0,    97,     0,     0,     0,     0,    98,    99,     0,   100,
     186,     0,   101,   102,   103,     0,     0,     0,     0,   104,
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
       0,   209,     0,     0,     0,     0,   107,     0,     0,     0,
       0,   108,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,    85,    86,
       0,     0,     0,    87,     0,    88,     0,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
       0,   212,     0,     0,     0,    97,     0,     0,     0,     0,
      98,    99,     0,   100,     0,     0,   101,   102,   103,     0,
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
     100,   269,     0,   101,   102,   103,     0,     0,     0,     0,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,   322,     0,     0,     0,     0,   107,     0,     0,
       0,     0,   108,    62,    63,    64,    65,    66,    67,    68,
      69,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,    85,
      86,     0,     0,     0,    87,     0,    88,     0,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
      96,     0,     0,     0,     0,     0,    97,     0,     0,     0,
       0,    98,    99,     0,   100,     0,     0,   101,   102,   103,
       0,     0,     0,     0,   104,   105,     0,   328,     0,     0,
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
       0,   104,   105,     0,     0,     0,   357,     0,     0,     0,
       0,   107,     0,     0,     0,     0,   108,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,    85,    86,     0,     0,     0,    87,     0,
      88,     0,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,    96,     0,     0,     0,     0,     0,
      97,     0,     0,     0,     0,    98,    99,   376,   100,     0,
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
       0,     0,    98,    99,   398,   100,     0,     0,   101,   102,
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
       0,     0,   104,   105,     0,   402,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,     0,   108,    62,    63,
      64,    65,    66,    67,    68,    69,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,     0,
       0,     0,     0,     0,    85,    86,     0,     0,     0,    87,
       0,    88,     0,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,    96,     0,     0,     0,     0,
       0,    97,   411,     0,     0,     0,    98,    99,     0,   100,
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
       0,     0,     0,    98,    99,     0,   100,     0,   412,   101,
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
      98,    99,     0,   100,     0,   422,   101,   102,   103,     0,
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
     100,     0,   427,   101,   102,   103,     0,     0,     0,     0,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
     107,     0,     0,     0,     0,   108,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,    85,    86,     0,     0,     0,    87,     0,    88,
       0,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,     0,     0,     0,     0,     0,    97,
       0,     0,     0,     0,    98,    99,     0,   100,     0,   430,
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
       0,    98,    99,     0,   100,     0,     0,   101,   102,   103,
       0,     0,     0,     0,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,   108,
      62,    63,    64,    65,    66,    67,    68,    69,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,    85,    86,     0,     0,
       0,    87,     0,    88,     0,    89,     0,     0,    92,    93,
      94,    95,     0,     0,     0,     0,     0,    96,   292,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,    62,    63,    64,    65,    66,    67,    68,
      69,   107,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,    85,
      86,     0,     0,     0,    87,     0,    88,     0,    89,     0,
       0,    92,    93,    94,    95,     0,     0,     0,     0,     0,
      96,     0,     0,   298,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,    62,    63,    64,    65,
      66,    67,    68,    69,   107,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,    85,    86,     0,     0,     0,    87,     0,    88,
       0,    89,     0,     0,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,     0,    84,     0,     0,     0,     0,     0,     0,
      85,    86,     0,     0,     0,    87,     0,    88,     0,    89,
       0,     0,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,   182,   105,     0,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,    85,    86,
       0,     0,     0,    87,     0,    88,     0,    89,     0,     0,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
      62,    63,    64,    65,    66,    67,    68,    69,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,   393,   105,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,    85,    86,     0,     0,
       0,    87,     0,    88,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   192,   193,    96,   194,   195,
     196,   197,   198,   199,   200,   201,   202,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     203,   104,   105,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   204,     0,     0,   205,     0,   206,     0,   207
  };

  const short
  parser::yycheck_[] =
  {
      29,    17,    96,    97,     4,     5,     6,   270,     9,   103,
       9,    66,     9,     9,   108,   113,    82,    83,    84,    85,
      86,    87,    88,    61,     9,     9,    29,     9,     9,     9,
     126,    72,   408,    11,    45,    46,    47,    48,    38,    66,
      96,    69,    98,    71,    71,   421,   101,    23,    24,    23,
      24,    89,   108,     9,    10,   431,    97,    48,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    44,    48,
      44,   100,    71,    70,    75,    59,    60,    53,    66,    53,
       9,    72,    93,    70,   113,    72,    71,    75,     0,   187,
      70,   185,   186,    72,    27,   189,    67,   100,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     148,    44,   206,   207,    70,   378,    53,    81,    66,   104,
     216,   103,   103,   101,    81,    53,    70,    75,   166,    69,
     168,   169,    96,    22,    98,    72,     9,   153,   167,    96,
      41,    98,   106,   159,    72,    51,    69,    36,   104,   106,
      56,    57,    72,    96,    74,    98,   156,   255,   187,    69,
      61,    62,    63,    64,   258,   108,    65,     9,   234,    68,
       9,    70,    11,    72,    69,   269,    71,     3,     4,     5,
       6,     7,     8,     9,    10,    69,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    65,    65,
       9,    68,    68,    70,    70,    72,    72,    69,   154,    71,
       9,    78,    78,   159,   160,    10,    11,   246,   231,   232,
     233,    69,   260,   261,    47,   323,   255,    96,    47,    98,
       9,   100,    58,   102,     9,   264,   105,    70,   107,    70,
     338,    66,    67,   246,    70,   339,   340,    69,   223,   224,
     225,   226,   227,    66,    67,    70,   350,    54,    55,    24,
      25,   264,    90,    91,    66,    67,   221,   222,    94,    95,
     364,   229,   230,   367,   368,    69,    40,   371,   104,   377,
      43,    52,   380,   321,    42,   383,    30,   325,   326,    26,
      11,    69,     9,   387,   323,    69,    69,   395,   106,     9,
      70,    69,   400,   397,    71,     9,    67,    69,   337,   338,
     408,    67,   341,   407,    69,   413,   345,    69,    78,    73,
      69,    41,   416,   421,    72,    67,   355,    67,    67,   106,
     428,   360,    73,   431,    69,    71,    93,    67,   341,    92,
      99,    69,   345,   372,    71,    69,    93,    69,   377,    74,
     379,   380,   355,    69,   383,    73,    67,    69,     9,    78,
      67,    69,    71,   392,    69,    71,   395,   396,    69,   372,
      69,   400,     8,   164,   117,    36,   379,    53,    93,   408,
     353,   410,    44,   184,   413,   273,   273,   217,   215,   392,
     219,   420,   421,   396,   423,   127,   220,   218,    -1,   428,
     429,    -1,   431,    -1,    -1,    -1,    -1,   410,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   228,    -1,
     423,    -1,    -1,    -1,    -1,    -1,   429,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    77,    -1,    79,    80,    81,    82,    -1,    84,    -1,
      -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    82,    -1,    84,    -1,    -1,    87,    88,
      89,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,    -1,
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
      -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      81,    82,    -1,    84,    -1,    -1,    87,    88,    89,    -1,
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
      84,    85,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      76,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    -1,
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
      -1,    -1,    81,    82,    83,    84,    -1,    -1,    87,    88,
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
      -1,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,   109,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    77,    -1,    -1,    -1,    81,    82,    -1,    84,
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
      84,    -1,    86,    87,    88,    89,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,   109,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,    86,
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
      -1,    81,    82,    -1,    84,    -1,    -1,    87,    88,    89,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    56,    -1,    58,    -1,    -1,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,     3,     4,     5,     6,     7,     8,     9,
      10,   104,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,    -1,
      -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,     3,     4,     5,     6,
       7,     8,     9,    10,   104,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,
      -1,    58,    -1,    -1,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,
      -1,    -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    56,    -1,    58,    -1,    -1,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    70,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    65,    -1,    -1,    68,    -1,    70,    -1,    72
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
      69,    71,   161,   156,   177,    67,    92,   155,   157,    71,
      66,    71,    73,    69,    71,   148,    69,    99,    69,   148,
     148,    69,    69,    73,    67,    66,    75,    53,    53,   140,
      77,    79,    80,   151,   161,   161,    83,   144,    66,    67,
     144,   161,   119,   144,    69,    97,    97,    74,   161,     9,
     161,   161,    78,    94,   161,   144,    71,    69,    83,   177,
     144,    71,    97,    69,    69,   161,   179,    67,   144,     9,
      78,    77,    86,   144,   161,    69,    66,    75,   161,   151,
      93,   144,    86,    71,   161,   140,   151,    86,   144,    78,
      86,   144,   151
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
     151,   152,   153,   153,   154,   154,   155,   156,   156,   157,
     158,   158,   158,   158,   159,   159,   160,   160,   161,   161,
     162,   162,   162,   163,   163,   163,   163,   164,   164,   165,
     165,   166,   166,   167,   167,   168,   168,   169,   169,   169,
     170,   170,   170,   170,   170,   170,   171,   171,   172,   172,
     172,   173,   173,   173,   173,   174,   174,   174,   174,   174,
     174,   174,   174,   175,   175,   176,   176,   176,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   178,   178,   179,   179,   180,   180,   181,   181
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
       1,     4,     2,     1,     2,     1,     4,     3,     1,     3,
       8,     7,    10,     9,     6,     5,     4,     3,     1,     1,
       2,     2,     3,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     2,     2,     2,
       2,     2,     1,     3,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     8,     3,     1,     5,     4,     5,     3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   102,   102,   106,   109,   114,   116,   118,   120,   122,
     126,   128,   132,   139,   144,   148,   150,   154,   156,   160,
     165,   172,   179,   182,   187,   189,   193,   195,   199,   202,
     207,   209,   213,   215,   219,   221,   225,   227,   231,   235,
     237,   241,   243,   247,   249,   253,   255,   257,   261,   263,
     267,   269,   271,   273,   277,   279,   283,   285,   289,   291,
     295,   297,   299,   303,   305,   307,   309,   311,   313,   317,
     319,   321,   325,   327,   331,   333,   337,   340,   345,   347,
     349,   351,   353,   355,   357,   359,   361,   363,   365,   369,
     373,   375,   379,   381,   383,   385,   387,   389,   391,   393,
     395,   397,   399,   403,   405,   407,   409,   411,   413,   415,
     417,   419,   421,   423,   425,   429,   434,   441,   446,   451,
     456,   460,   464,   467,   472,   475,   480,   487,   490,   495,
     502,   507,   509,   514,   518,   523,   527,   532,   536,   538,
     542,   544,   546,   550,   552,   554,   556,   560,   562,   566,
     568,   572,   574,   578,   580,   584,   586,   590,   592,   594,
     598,   600,   602,   604,   606,   608,   612,   614,   618,   620,
     622,   626,   628,   630,   632,   636,   638,   640,   642,   644,
     646,   648,   650,   654,   656,   660,   662,   664,   668,   670,
     672,   674,   676,   678,   680,   682,   684,   686,   688,   690,
     692,   696,   698,   705,   708,   713,   715,   719,   721
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
#line 4338 "grammar/build/syntax.tab.cc"

#line 724 "grammar/syntax.y"
