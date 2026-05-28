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

      case symbol_kind::S_enum: // enum
        value.YY_MOVE_OR_COPY< EnumNode* > (YY_MOVE (that.value));
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

      case symbol_kind::S_struct: // struct
        value.YY_MOVE_OR_COPY< StructNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subprogram_call: // subprogram_call
        value.YY_MOVE_OR_COPY< SubprogramCallNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_switch: // switch
        value.YY_MOVE_OR_COPY< SwitchNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_basic_type: // basic_type
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
      case symbol_kind::S_struct_attrs: // struct_attrs
      case symbol_kind::S_struct_attr: // struct_attr
        value.YY_MOVE_OR_COPY< vector<pair<string, Type>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id_list: // id_list
      case symbol_kind::S_enum_values: // enum_values
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

      case symbol_kind::S_enum: // enum
        value.move< EnumNode* > (YY_MOVE (that.value));
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

      case symbol_kind::S_struct: // struct
        value.move< StructNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subprogram_call: // subprogram_call
        value.move< SubprogramCallNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_switch: // switch
        value.move< SwitchNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_basic_type: // basic_type
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
      case symbol_kind::S_struct_attrs: // struct_attrs
      case symbol_kind::S_struct_attr: // struct_attr
        value.move< vector<pair<string, Type>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id_list: // id_list
      case symbol_kind::S_enum_values: // enum_values
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

      case symbol_kind::S_enum: // enum
        value.copy< EnumNode* > (that.value);
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

      case symbol_kind::S_struct: // struct
        value.copy< StructNode* > (that.value);
        break;

      case symbol_kind::S_subprogram_call: // subprogram_call
        value.copy< SubprogramCallNode* > (that.value);
        break;

      case symbol_kind::S_switch: // switch
        value.copy< SwitchNode* > (that.value);
        break;

      case symbol_kind::S_basic_type: // basic_type
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
      case symbol_kind::S_struct_attrs: // struct_attrs
      case symbol_kind::S_struct_attr: // struct_attr
        value.copy< vector<pair<string, Type>> > (that.value);
        break;

      case symbol_kind::S_id_list: // id_list
      case symbol_kind::S_enum_values: // enum_values
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

      case symbol_kind::S_enum: // enum
        value.move< EnumNode* > (that.value);
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

      case symbol_kind::S_struct: // struct
        value.move< StructNode* > (that.value);
        break;

      case symbol_kind::S_subprogram_call: // subprogram_call
        value.move< SubprogramCallNode* > (that.value);
        break;

      case symbol_kind::S_switch: // switch
        value.move< SwitchNode* > (that.value);
        break;

      case symbol_kind::S_basic_type: // basic_type
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
      case symbol_kind::S_struct_attrs: // struct_attrs
      case symbol_kind::S_struct_attr: // struct_attr
        value.move< vector<pair<string, Type>> > (that.value);
        break;

      case symbol_kind::S_id_list: // id_list
      case symbol_kind::S_enum_values: // enum_values
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

      case symbol_kind::S_enum: // enum
        yylhs.value.emplace< EnumNode* > ();
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

      case symbol_kind::S_struct: // struct
        yylhs.value.emplace< StructNode* > ();
        break;

      case symbol_kind::S_subprogram_call: // subprogram_call
        yylhs.value.emplace< SubprogramCallNode* > ();
        break;

      case symbol_kind::S_switch: // switch
        yylhs.value.emplace< SwitchNode* > ();
        break;

      case symbol_kind::S_basic_type: // basic_type
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
      case symbol_kind::S_struct_attrs: // struct_attrs
      case symbol_kind::S_struct_attr: // struct_attr
        yylhs.value.emplace< vector<pair<string, Type>> > ();
        break;

      case symbol_kind::S_id_list: // id_list
      case symbol_kind::S_enum_values: // enum_values
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
#line 104 "grammar/syntax.y"
              {
  ctx.root = yystack_[0].value.as < Node* > ();
}
#line 1502 "grammar/build/syntax.tab.cc"
    break;

  case 3: // program: program program_slice
#line 108 "grammar/syntax.y"
                               {
  yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > ();
  yystack_[1].value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
}
#line 1511 "grammar/build/syntax.tab.cc"
    break;

  case 4: // program: program_slice
#line 111 "grammar/syntax.y"
                  {
  yylhs.value.as < Node* > () = new Node(ctx.line, "PROGRAM");
  yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
}
#line 1520 "grammar/build/syntax.tab.cc"
    break;

  case 5: // program_slice: subprogram
#line 116 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1528 "grammar/build/syntax.tab.cc"
    break;

  case 6: // program_slice: enum
#line 118 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < EnumNode* > ();
}
#line 1536 "grammar/build/syntax.tab.cc"
    break;

  case 7: // program_slice: struct
#line 120 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < StructNode* > ();
}
#line 1544 "grammar/build/syntax.tab.cc"
    break;

  case 8: // program_slice: trait
#line 122 "grammar/syntax.y"
          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1552 "grammar/build/syntax.tab.cc"
    break;

  case 9: // program_slice: impl
#line 124 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 1560 "grammar/build/syntax.tab.cc"
    break;

  case 10: // subprogram: fn
#line 128 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = yystack_[0].value.as < FunctionNode* > ();
}
#line 1568 "grammar/build/syntax.tab.cc"
    break;

  case 11: // subprogram: proc
#line 130 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ProcedureNode* > ();
}
#line 1576 "grammar/build/syntax.tab.cc"
    break;

  case 12: // fn: FUNCTION ID params_list COLON type stmts END_FUNCTION SEMICOLON
#line 134 "grammar/syntax.y"
                                                                    {
  yylhs.value.as < FunctionNode* > () = new FunctionNode(ctx.line, yystack_[6].value.as < string > (), *yystack_[3].value.as < Type* > (), yystack_[5].value.as < vector<pair<string, Type>> > ());
  for (size_t i = 0; i < yystack_[2].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < FunctionNode* > ()->children.push_back(yystack_[2].value.as < vector<Node*> > ()[i]);
  };
}
#line 1587 "grammar/build/syntax.tab.cc"
    break;

  case 13: // proc: PROCEDURE ID params_list stmts END_PROCEDURE SEMICOLON
#line 141 "grammar/syntax.y"
                                                             {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[4].value.as < string > (), yystack_[3].value.as < vector<pair<string, Type>> > ());
  for (size_t i = 0; i < yystack_[2].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < ProcedureNode* > ()->children.push_back(yystack_[2].value.as < vector<Node*> > ()[i]);
  };
}
#line 1598 "grammar/build/syntax.tab.cc"
    break;

  case 14: // proc: PROCEDURE ID params_list END_PROCEDURE SEMICOLON
#line 146 "grammar/syntax.y"
                                                     {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[3].value.as < string > (), yystack_[2].value.as < vector<pair<string, Type>> > ());
}
#line 1606 "grammar/build/syntax.tab.cc"
    break;

  case 15: // params_self_list: LEFT_PAREN SELF SEMICOLON params RIGHT_PAREN
#line 150 "grammar/syntax.y"
                                                               {
  yylhs.value.as < vector<pair<string, Type>> > () = yystack_[1].value.as < vector<pair<string, Type>> > ();
}
#line 1614 "grammar/build/syntax.tab.cc"
    break;

  case 16: // params_self_list: LEFT_PAREN SELF RIGHT_PAREN
#line 152 "grammar/syntax.y"
                                {
  yylhs.value.as < vector<pair<string, Type>> > () = vector<pair<string, Type>>();
}
#line 1622 "grammar/build/syntax.tab.cc"
    break;

  case 17: // params_list: LEFT_PAREN params RIGHT_PAREN
#line 156 "grammar/syntax.y"
                                           {
  yylhs.value.as < vector<pair<string, Type>> > () = yystack_[1].value.as < vector<pair<string, Type>> > ();
}
#line 1630 "grammar/build/syntax.tab.cc"
    break;

  case 18: // params_list: LEFT_PAREN RIGHT_PAREN
#line 158 "grammar/syntax.y"
                           {
  yylhs.value.as < vector<pair<string, Type>> > () = vector<pair<string, Type>>();
}
#line 1638 "grammar/build/syntax.tab.cc"
    break;

  case 19: // params: params SEMICOLON param
#line 162 "grammar/syntax.y"
                               {
  yylhs.value.as < vector<pair<string, Type>> > () = yystack_[2].value.as < vector<pair<string, Type>> > ();
  for (size_t i = 0; i < yystack_[0].value.as < vector<pair<string, Type>> > ().size(); i++) {
    yylhs.value.as < vector<pair<string, Type>> > ().push_back(yystack_[0].value.as < vector<pair<string, Type>> > ()[i]);
  };
}
#line 1649 "grammar/build/syntax.tab.cc"
    break;

  case 20: // params: param
#line 167 "grammar/syntax.y"
          {
  yylhs.value.as < vector<pair<string, Type>> > () = vector<pair<string, Type>>();
  for (size_t i = 0; i < yystack_[0].value.as < vector<pair<string, Type>> > ().size(); i++) {
    yylhs.value.as < vector<pair<string, Type>> > ().push_back(yystack_[0].value.as < vector<pair<string, Type>> > ()[i]);
  };
}
#line 1660 "grammar/build/syntax.tab.cc"
    break;

  case 21: // param: id_list COLON type
#line 174 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<pair<string, Type>> > () = vector<pair<string, Type>>();
  for (size_t i = 0; i < yystack_[2].value.as < vector<string> > ().size(); i++) {
    yylhs.value.as < vector<pair<string, Type>> > ().push_back({yystack_[2].value.as < vector<string> > ()[i], *yystack_[0].value.as < Type* > ()});
  };
}
#line 1671 "grammar/build/syntax.tab.cc"
    break;

  case 22: // id_list: id_list COMMA ID
#line 181 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<string> > () = yystack_[2].value.as < vector<string> > ();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < string > ());
}
#line 1680 "grammar/build/syntax.tab.cc"
    break;

  case 23: // id_list: ID
#line 184 "grammar/syntax.y"
       {
  yylhs.value.as < vector<string> > () = vector<string>();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < string > ());
}
#line 1689 "grammar/build/syntax.tab.cc"
    break;

  case 24: // subprogram_call: access call_params_list
#line 189 "grammar/syntax.y"
                                         {
  yylhs.value.as < SubprogramCallNode* > () = new SubprogramCallNode(ctx.line, yystack_[1].value.as < AccessNode* > (), yystack_[0].value.as < vector<ExpressionNode*> > ());
}
#line 1697 "grammar/build/syntax.tab.cc"
    break;

  case 25: // subprogram_call: basic_type call_params_list
#line 191 "grammar/syntax.y"
                                {
  yylhs.value.as < SubprogramCallNode* > () = new SubprogramCallNode(ctx.line, *yystack_[1].value.as < Type* > (), yystack_[0].value.as < vector<ExpressionNode*> > ());
}
#line 1705 "grammar/build/syntax.tab.cc"
    break;

  case 26: // call_params_list: LEFT_PAREN call_params RIGHT_PAREN
#line 195 "grammar/syntax.y"
                                                     {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[1].value.as < vector<ExpressionNode*> > ();
}
#line 1713 "grammar/build/syntax.tab.cc"
    break;

  case 27: // call_params_list: LEFT_PAREN RIGHT_PAREN
#line 197 "grammar/syntax.y"
                           {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
}
#line 1721 "grammar/build/syntax.tab.cc"
    break;

  case 28: // call_params: call_params COMMA expr
#line 201 "grammar/syntax.y"
                                    {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[2].value.as < vector<ExpressionNode*> > ();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 1730 "grammar/build/syntax.tab.cc"
    break;

  case 29: // call_params: expr
#line 204 "grammar/syntax.y"
         {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 1739 "grammar/build/syntax.tab.cc"
    break;

  case 30: // enum: ENUM name enum_values END_ENUM SEMICOLON
#line 209 "grammar/syntax.y"
                                               {
  yylhs.value.as < EnumNode* > () = new EnumNode(ctx.line, yystack_[3].value.as < string > (), yystack_[2].value.as < vector<string> > ());
}
#line 1747 "grammar/build/syntax.tab.cc"
    break;

  case 31: // enum: ENUM name END_ENUM SEMICOLON
#line 211 "grammar/syntax.y"
                                 {
  yylhs.value.as < EnumNode* > () = new EnumNode(ctx.line, yystack_[2].value.as < string > (), vector<string>());
}
#line 1755 "grammar/build/syntax.tab.cc"
    break;

  case 32: // enum_values: enum_values COMMA CONST_NAME
#line 215 "grammar/syntax.y"
                                          {
  yylhs.value.as < vector<string> > () = yystack_[2].value.as < vector<string> > ();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < string > ());
}
#line 1764 "grammar/build/syntax.tab.cc"
    break;

  case 33: // enum_values: CONST_NAME
#line 218 "grammar/syntax.y"
               {
  yylhs.value.as < vector<string> > () = vector<string>();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < string > ());
}
#line 1773 "grammar/build/syntax.tab.cc"
    break;

  case 34: // struct: STRUCT name struct_attrs END_STRUCT SEMICOLON
#line 223 "grammar/syntax.y"
                                                      {
  yylhs.value.as < StructNode* > () = new StructNode(ctx.line, yystack_[3].value.as < string > (), yystack_[2].value.as < vector<pair<string, Type>> > ());
}
#line 1781 "grammar/build/syntax.tab.cc"
    break;

  case 35: // struct: STRUCT name END_STRUCT SEMICOLON
#line 225 "grammar/syntax.y"
                                     {
  yylhs.value.as < StructNode* > () = new StructNode(ctx.line, yystack_[2].value.as < string > (), vector<pair<string, Type>>());
}
#line 1789 "grammar/build/syntax.tab.cc"
    break;

  case 36: // struct_attrs: struct_attrs struct_attr SEMICOLON
#line 229 "grammar/syntax.y"
                                                 {
  yylhs.value.as < vector<pair<string, Type>> > () = yystack_[2].value.as < vector<pair<string, Type>> > ();
  for (size_t i = 0; i < yystack_[1].value.as < vector<pair<string, Type>> > ().size(); i++) {
    yylhs.value.as < vector<pair<string, Type>> > ().push_back(yystack_[1].value.as < vector<pair<string, Type>> > ()[i]);
  };
}
#line 1800 "grammar/build/syntax.tab.cc"
    break;

  case 37: // struct_attrs: struct_attr SEMICOLON
#line 234 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<pair<string, Type>> > () = yystack_[1].value.as < vector<pair<string, Type>> > ();
}
#line 1808 "grammar/build/syntax.tab.cc"
    break;

  case 38: // struct_attr: id_list COLON type
#line 238 "grammar/syntax.y"
                                {
  yylhs.value.as < vector<pair<string, Type>> > () = vector<pair<string, Type>>();
  for (size_t i = 0; i < yystack_[2].value.as < vector<string> > ().size(); i++) {
    yylhs.value.as < vector<pair<string, Type>> > ().push_back({yystack_[2].value.as < vector<string> > ()[i], *yystack_[0].value.as < Type* > ()});
  };
}
#line 1819 "grammar/build/syntax.tab.cc"
    break;

  case 39: // trait: TRAIT name trait_subprograms END_TRAIT SEMICOLON
#line 245 "grammar/syntax.y"
                                                        {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1827 "grammar/build/syntax.tab.cc"
    break;

  case 40: // trait: TRAIT name END_TRAIT SEMICOLON
#line 247 "grammar/syntax.y"
                                   {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1835 "grammar/build/syntax.tab.cc"
    break;

  case 41: // trait_subprograms: trait_subprograms trait_subprogram
#line 251 "grammar/syntax.y"
                                                      {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1843 "grammar/build/syntax.tab.cc"
    break;

  case 42: // trait_subprograms: trait_subprogram
#line 253 "grammar/syntax.y"
                     {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1851 "grammar/build/syntax.tab.cc"
    break;

  case 43: // trait_subprogram: trait_fn
#line 257 "grammar/syntax.y"
                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1859 "grammar/build/syntax.tab.cc"
    break;

  case 44: // trait_subprogram: trait_proc
#line 259 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1867 "grammar/build/syntax.tab.cc"
    break;

  case 45: // trait_fn: FUNCTION ID params_self_list COLON type END_FUNCTION SEMICOLON
#line 263 "grammar/syntax.y"
                                                                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1875 "grammar/build/syntax.tab.cc"
    break;

  case 46: // trait_fn: FUNCTION ID params_list COLON type END_FUNCTION SEMICOLON
#line 265 "grammar/syntax.y"
                                                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1883 "grammar/build/syntax.tab.cc"
    break;

  case 47: // trait_fn: fn
#line 267 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1891 "grammar/build/syntax.tab.cc"
    break;

  case 48: // trait_proc: PROCEDURE ID params_self_list END_PROCEDURE SEMICOLON
#line 271 "grammar/syntax.y"
                                                                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1899 "grammar/build/syntax.tab.cc"
    break;

  case 49: // trait_proc: proc
#line 273 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1907 "grammar/build/syntax.tab.cc"
    break;

  case 50: // impl: IMPL name impl_subprograms END_IMPL SEMICOLON
#line 277 "grammar/syntax.y"
                                                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1915 "grammar/build/syntax.tab.cc"
    break;

  case 51: // impl: IMPL name END_IMPL SEMICOLON
#line 279 "grammar/syntax.y"
                                 {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1923 "grammar/build/syntax.tab.cc"
    break;

  case 52: // impl: IMPL name impl_subprograms FOR name END_IMPL SEMICOLON
#line 281 "grammar/syntax.y"
                                                           {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1931 "grammar/build/syntax.tab.cc"
    break;

  case 53: // impl: IMPL name FOR name END_IMPL SEMICOLON
#line 283 "grammar/syntax.y"
                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1939 "grammar/build/syntax.tab.cc"
    break;

  case 54: // impl_subprograms: impl_subprograms impl_subprogram
#line 287 "grammar/syntax.y"
                                                   {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1947 "grammar/build/syntax.tab.cc"
    break;

  case 55: // impl_subprograms: impl_subprogram
#line 289 "grammar/syntax.y"
                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1955 "grammar/build/syntax.tab.cc"
    break;

  case 56: // impl_subprogram: impl_fn
#line 293 "grammar/syntax.y"
                         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1963 "grammar/build/syntax.tab.cc"
    break;

  case 57: // impl_subprogram: impl_proc
#line 295 "grammar/syntax.y"
              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1971 "grammar/build/syntax.tab.cc"
    break;

  case 58: // impl_fn: FUNCTION ID params_self_list COLON type stmts END_FUNCTION SEMICOLON
#line 299 "grammar/syntax.y"
                                                                              {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1979 "grammar/build/syntax.tab.cc"
    break;

  case 59: // impl_fn: fn
#line 301 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1987 "grammar/build/syntax.tab.cc"
    break;

  case 60: // impl_proc: PROCEDURE ID params_self_list stmts END_PROCEDURE SEMICOLON
#line 305 "grammar/syntax.y"
                                                                       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 1995 "grammar/build/syntax.tab.cc"
    break;

  case 61: // impl_proc: PROCEDURE ID params_self_list END_PROCEDURE SEMICOLON
#line 307 "grammar/syntax.y"
                                                          {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2003 "grammar/build/syntax.tab.cc"
    break;

  case 62: // impl_proc: proc
#line 309 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2011 "grammar/build/syntax.tab.cc"
    break;

  case 63: // access: access DOT CONST_NAME
#line 313 "grammar/syntax.y"
                              {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < string > (), yystack_[2].value.as < AccessNode* > (), AccessType::DOT);
}
#line 2019 "grammar/build/syntax.tab.cc"
    break;

  case 64: // access: access DOT ID
#line 315 "grammar/syntax.y"
                  {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < string > (), yystack_[2].value.as < AccessNode* > (), AccessType::DOT);
}
#line 2027 "grammar/build/syntax.tab.cc"
    break;

  case 65: // access: access LEFT_BRACKET expr RIGHT_BRACKET
#line 317 "grammar/syntax.y"
                                           {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[3].value.as < AccessNode* > (), yystack_[1].value.as < ExpressionNode* > ());
}
#line 2035 "grammar/build/syntax.tab.cc"
    break;

  case 66: // access: access DOUBLE_COLON ID
#line 319 "grammar/syntax.y"
                           {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < string > (), yystack_[2].value.as < AccessNode* > (), AccessType::STATIC);
}
#line 2043 "grammar/build/syntax.tab.cc"
    break;

  case 67: // access: subprogram_call
#line 321 "grammar/syntax.y"
                    {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < SubprogramCallNode* > ());
}
#line 2051 "grammar/build/syntax.tab.cc"
    break;

  case 68: // access: access_base
#line 323 "grammar/syntax.y"
                {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < AccessBaseNode* > ());
}
#line 2059 "grammar/build/syntax.tab.cc"
    break;

  case 69: // access_base: SELF
#line 327 "grammar/syntax.y"
                  {
  yylhs.value.as < AccessBaseNode* > () = new AccessBaseNode(ctx.line);
}
#line 2067 "grammar/build/syntax.tab.cc"
    break;

  case 70: // access_base: id
#line 329 "grammar/syntax.y"
       {
  yylhs.value.as < AccessBaseNode* > () = new AccessBaseNode(ctx.line, yystack_[0].value.as < string > ());
}
#line 2075 "grammar/build/syntax.tab.cc"
    break;

  case 71: // access_base: LEFT_PAREN expr RIGHT_PAREN
#line 331 "grammar/syntax.y"
                                {
  yylhs.value.as < AccessBaseNode* > () = new AccessBaseNode(ctx.line, yystack_[1].value.as < ExpressionNode* > ());
}
#line 2083 "grammar/build/syntax.tab.cc"
    break;

  case 72: // id: NAME
#line 335 "grammar/syntax.y"
         {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 2091 "grammar/build/syntax.tab.cc"
    break;

  case 73: // id: ID
#line 337 "grammar/syntax.y"
       {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 2099 "grammar/build/syntax.tab.cc"
    break;

  case 74: // name: NAME
#line 341 "grammar/syntax.y"
           {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 2107 "grammar/build/syntax.tab.cc"
    break;

  case 75: // name: CONST_NAME
#line 343 "grammar/syntax.y"
               {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 2115 "grammar/build/syntax.tab.cc"
    break;

  case 76: // stmts: stmts stmt SEMICOLON
#line 347 "grammar/syntax.y"
                            {
  yylhs.value.as < vector<Node*> > () = yystack_[2].value.as < vector<Node*> > ();
  yylhs.value.as < vector<Node*> > ().push_back(yystack_[1].value.as < Node* > ());
}
#line 2124 "grammar/build/syntax.tab.cc"
    break;

  case 77: // stmts: stmt SEMICOLON
#line 350 "grammar/syntax.y"
                   {
  yylhs.value.as < vector<Node*> > () = vector<Node*>();
  yylhs.value.as < vector<Node*> > ().push_back(yystack_[1].value.as < Node* > ());
}
#line 2133 "grammar/build/syntax.tab.cc"
    break;

  case 78: // stmt: BREAK
#line 355 "grammar/syntax.y"
            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2141 "grammar/build/syntax.tab.cc"
    break;

  case 79: // stmt: CONTINUE
#line 357 "grammar/syntax.y"
             {
  yylhs.value.as < Node* > () = nullptr;
}
#line 2149 "grammar/build/syntax.tab.cc"
    break;

  case 80: // stmt: attr
#line 359 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < AttrNode* > ();
}
#line 2157 "grammar/build/syntax.tab.cc"
    break;

  case 81: // stmt: assign
#line 361 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < AssignNode* > ();
}
#line 2165 "grammar/build/syntax.tab.cc"
    break;

  case 82: // stmt: return
#line 363 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ReturnNode* > ();
}
#line 2173 "grammar/build/syntax.tab.cc"
    break;

  case 83: // stmt: if
#line 365 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = yystack_[0].value.as < IfNode* > ();
}
#line 2181 "grammar/build/syntax.tab.cc"
    break;

  case 84: // stmt: for
#line 367 "grammar/syntax.y"
        {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ForNode* > ();
}
#line 2189 "grammar/build/syntax.tab.cc"
    break;

  case 85: // stmt: while
#line 369 "grammar/syntax.y"
          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < WhileNode* > ();
}
#line 2197 "grammar/build/syntax.tab.cc"
    break;

  case 86: // stmt: repeat
#line 371 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < WhileNode* > ();
}
#line 2205 "grammar/build/syntax.tab.cc"
    break;

  case 87: // stmt: switch
#line 373 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < SwitchNode* > ();
}
#line 2213 "grammar/build/syntax.tab.cc"
    break;

  case 88: // stmt: expr
#line 375 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2221 "grammar/build/syntax.tab.cc"
    break;

  case 89: // return: RETURN expr
#line 379 "grammar/syntax.y"
                    {
  yylhs.value.as < ReturnNode* > () = new ReturnNode(ctx.line, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2229 "grammar/build/syntax.tab.cc"
    break;

  case 90: // attr: VAR ID COLON type ATTR expr
#line 383 "grammar/syntax.y"
                                  {
  yylhs.value.as < AttrNode* > () = new AttrNode(ctx.line, yystack_[4].value.as < string > (), false, *yystack_[2].value.as < Type* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2237 "grammar/build/syntax.tab.cc"
    break;

  case 91: // attr: CONST ID COLON type ATTR expr
#line 385 "grammar/syntax.y"
                                  {
  yylhs.value.as < AttrNode* > () = new AttrNode(ctx.line, yystack_[4].value.as < string > (), true, *yystack_[2].value.as < Type* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2245 "grammar/build/syntax.tab.cc"
    break;

  case 92: // basic_type: TYPE_INT
#line 389 "grammar/syntax.y"
                     {
  yylhs.value.as < Type* > () = new Type(TypeKind::INT);
}
#line 2253 "grammar/build/syntax.tab.cc"
    break;

  case 93: // basic_type: TYPE_FLOAT
#line 391 "grammar/syntax.y"
               {
  yylhs.value.as < Type* > () = new Type(TypeKind::FLOAT);
}
#line 2261 "grammar/build/syntax.tab.cc"
    break;

  case 94: // basic_type: TYPE_DOUBLE
#line 393 "grammar/syntax.y"
                {
  yylhs.value.as < Type* > () = new Type(TypeKind::DOUBLE);
}
#line 2269 "grammar/build/syntax.tab.cc"
    break;

  case 95: // basic_type: TYPE_LONG
#line 395 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::LONG);
}
#line 2277 "grammar/build/syntax.tab.cc"
    break;

  case 96: // basic_type: TYPE_BYTE
#line 397 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::BYTE);
}
#line 2285 "grammar/build/syntax.tab.cc"
    break;

  case 97: // basic_type: TYPE_STRING
#line 399 "grammar/syntax.y"
                {
  yylhs.value.as < Type* > () = new Type(TypeKind::STRING);
}
#line 2293 "grammar/build/syntax.tab.cc"
    break;

  case 98: // basic_type: TYPE_CHAR
#line 401 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::CHAR);
}
#line 2301 "grammar/build/syntax.tab.cc"
    break;

  case 99: // basic_type: TYPE_BOOL
#line 403 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::BOOL);
}
#line 2309 "grammar/build/syntax.tab.cc"
    break;

  case 100: // type: basic_type
#line 407 "grammar/syntax.y"
                 {
  yylhs.value.as < Type* > () = yystack_[0].value.as < Type* > ();
}
#line 2317 "grammar/build/syntax.tab.cc"
    break;

  case 101: // type: type LEFT_BRACKET RIGHT_BRACKET
#line 409 "grammar/syntax.y"
                                    {
  yylhs.value.as < Type* > () = new Type(TypeKind::ARRAY, yystack_[2].value.as < Type* > ());
}
#line 2325 "grammar/build/syntax.tab.cc"
    break;

  case 102: // type: TYPE_POINTER LT type GT
#line 411 "grammar/syntax.y"
                            {
  yylhs.value.as < Type* > () = new Type(TypeKind::POINTER, yystack_[1].value.as < Type* > ());
}
#line 2333 "grammar/build/syntax.tab.cc"
    break;

  case 103: // type: TYPE_OPTION LT type GT
#line 413 "grammar/syntax.y"
                           {
  yylhs.value.as < Type* > () = new Type(TypeKind::OPTION, yystack_[1].value.as < Type* > ());
}
#line 2341 "grammar/build/syntax.tab.cc"
    break;

  case 104: // type: name
#line 415 "grammar/syntax.y"
         {
  yylhs.value.as < Type* > () = new Type(TypeKind::NAMED, yystack_[0].value.as < string > ());
}
#line 2349 "grammar/build/syntax.tab.cc"
    break;

  case 105: // assign: access ATTR expr
#line 419 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2357 "grammar/build/syntax.tab.cc"
    break;

  case 106: // assign: access AND_ATTR expr
#line 421 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::AND, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2365 "grammar/build/syntax.tab.cc"
    break;

  case 107: // assign: access OR_ATTR expr
#line 423 "grammar/syntax.y"
                        {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::OR, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2373 "grammar/build/syntax.tab.cc"
    break;

  case 108: // assign: access LAZY_AND_ATTR expr
#line 425 "grammar/syntax.y"
                              {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::BITWISE_AND, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2381 "grammar/build/syntax.tab.cc"
    break;

  case 109: // assign: access LAZY_OR_ATTR expr
#line 427 "grammar/syntax.y"
                             {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::BITWISE_OR, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2389 "grammar/build/syntax.tab.cc"
    break;

  case 110: // assign: access XOR_ATTR expr
#line 429 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::XOR, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2397 "grammar/build/syntax.tab.cc"
    break;

  case 111: // assign: access CONCAT_ATTR expr
#line 431 "grammar/syntax.y"
                            {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::CONCAT, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2405 "grammar/build/syntax.tab.cc"
    break;

  case 112: // assign: access MOD_ATTR expr
#line 433 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::MOD, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2413 "grammar/build/syntax.tab.cc"
    break;

  case 113: // assign: access PLUS_ATTR expr
#line 435 "grammar/syntax.y"
                          {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::PLUS, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2421 "grammar/build/syntax.tab.cc"
    break;

  case 114: // assign: access MINUS_ATTR expr
#line 437 "grammar/syntax.y"
                           {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::MINUS, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2429 "grammar/build/syntax.tab.cc"
    break;

  case 115: // assign: access MULT_ATTR expr
#line 439 "grammar/syntax.y"
                          {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::MULT, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2437 "grammar/build/syntax.tab.cc"
    break;

  case 116: // assign: access DIV_ATTR expr
#line 441 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::DIV, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2445 "grammar/build/syntax.tab.cc"
    break;

  case 117: // if: IF expr THEN stmts if_end
#line 445 "grammar/syntax.y"
                              {
  yylhs.value.as < IfNode* > () = new IfNode(ctx.line, yystack_[3].value.as < ExpressionNode* > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2456 "grammar/build/syntax.tab.cc"
    break;

  case 118: // if: IF SOME ID IN access THEN stmts if_end
#line 450 "grammar/syntax.y"
                                           {
  yylhs.value.as < IfNode* > () = new IfNode(ctx.line, yystack_[3].value.as < AccessNode* > (), yystack_[5].value.as < string > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2467 "grammar/build/syntax.tab.cc"
    break;

  case 119: // if_end: ELIF expr THEN stmts if_end
#line 457 "grammar/syntax.y"
                                    {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line, yystack_[3].value.as < ExpressionNode* > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfEndNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2478 "grammar/build/syntax.tab.cc"
    break;

  case 120: // if_end: ELIF SOME ID IN access THEN stmts if_end
#line 462 "grammar/syntax.y"
                                             {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line, yystack_[3].value.as < AccessNode* > (), yystack_[5].value.as < string > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfEndNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2489 "grammar/build/syntax.tab.cc"
    break;

  case 121: // if_end: ELSE stmts END_IF
#line 467 "grammar/syntax.y"
                      {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line, new IfEndNode(ctx.line));
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfEndNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2500 "grammar/build/syntax.tab.cc"
    break;

  case 122: // if_end: END_IF
#line 472 "grammar/syntax.y"
           {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line);
}
#line 2508 "grammar/build/syntax.tab.cc"
    break;

  case 123: // switch: SWITCH expr cases END_SWITCH
#line 476 "grammar/syntax.y"
                                     {
  yylhs.value.as < SwitchNode* > () = new SwitchNode(ctx.line, yystack_[2].value.as < ExpressionNode* > (), yystack_[1].value.as < vector<CaseNode*> > ());
}
#line 2516 "grammar/build/syntax.tab.cc"
    break;

  case 124: // cases: case_list default_case
#line 480 "grammar/syntax.y"
                              {
  yylhs.value.as < vector<CaseNode*> > () = yystack_[1].value.as < vector<CaseNode*> > ();
  yylhs.value.as < vector<CaseNode*> > ().push_back(yystack_[0].value.as < CaseNode* > ());
}
#line 2525 "grammar/build/syntax.tab.cc"
    break;

  case 125: // cases: default_case
#line 483 "grammar/syntax.y"
                 {
  yylhs.value.as < vector<CaseNode*> > () = vector<CaseNode*>();
  yylhs.value.as < vector<CaseNode*> > ().push_back(yystack_[0].value.as < CaseNode* > ());
}
#line 2534 "grammar/build/syntax.tab.cc"
    break;

  case 126: // case_list: case_list case
#line 488 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<CaseNode*> > () = yystack_[1].value.as < vector<CaseNode*> > ();
  yylhs.value.as < vector<CaseNode*> > ().push_back(yystack_[0].value.as < CaseNode* > ());
}
#line 2543 "grammar/build/syntax.tab.cc"
    break;

  case 127: // case_list: case
#line 491 "grammar/syntax.y"
         {
  yylhs.value.as < vector<CaseNode*> > () = vector<CaseNode*>();
  yylhs.value.as < vector<CaseNode*> > ().push_back(yystack_[0].value.as < CaseNode* > ());
}
#line 2552 "grammar/build/syntax.tab.cc"
    break;

  case 128: // case: CASE case_values COLON stmts
#line 496 "grammar/syntax.y"
                                   {
  yylhs.value.as < CaseNode* > () = new CaseNode(ctx.line, yystack_[2].value.as < vector<ExpressionNode*> > ());
  for (size_t i = 0; i < yystack_[0].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < CaseNode* > ()->children.push_back(yystack_[0].value.as < vector<Node*> > ()[i]);
  };
}
#line 2563 "grammar/build/syntax.tab.cc"
    break;

  case 129: // case_values: case_values COMMA term
#line 503 "grammar/syntax.y"
                                    {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[2].value.as < vector<ExpressionNode*> > ();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 2572 "grammar/build/syntax.tab.cc"
    break;

  case 130: // case_values: term
#line 506 "grammar/syntax.y"
         {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 2581 "grammar/build/syntax.tab.cc"
    break;

  case 131: // default_case: DEFAULT COLON stmts
#line 511 "grammar/syntax.y"
                                  {
  yylhs.value.as < CaseNode* > () = new CaseNode(ctx.line);
  for (size_t i = 0; i < yystack_[0].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < CaseNode* > ()->children.push_back(yystack_[0].value.as < vector<Node*> > ()[i]);
  };
}
#line 2592 "grammar/build/syntax.tab.cc"
    break;

  case 132: // for: FOR LEFT_PAREN ID IN expr RIGHT_PAREN stmts END_FOR
#line 518 "grammar/syntax.y"
                                                         {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[5].value.as < string > (), yystack_[3].value.as < ExpressionNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < ForNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2603 "grammar/build/syntax.tab.cc"
    break;

  case 133: // for: FOR LEFT_PAREN ID IN expr RIGHT_PAREN END_FOR
#line 523 "grammar/syntax.y"
                                                  {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[4].value.as < string > (), yystack_[2].value.as < ExpressionNode* > ());
}
#line 2611 "grammar/build/syntax.tab.cc"
    break;

  case 134: // for: FOR LEFT_PAREN attr SEMICOLON expr SEMICOLON expr RIGHT_PAREN stmts END_FOR
#line 525 "grammar/syntax.y"
                                                                                {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[7].value.as < AttrNode* > (), yystack_[5].value.as < ExpressionNode* > (), yystack_[3].value.as < ExpressionNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < ForNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2622 "grammar/build/syntax.tab.cc"
    break;

  case 135: // for: FOR LEFT_PAREN attr SEMICOLON expr SEMICOLON expr RIGHT_PAREN END_FOR
#line 530 "grammar/syntax.y"
                                                                          {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[6].value.as < AttrNode* > (), yystack_[4].value.as < ExpressionNode* > (), yystack_[2].value.as < ExpressionNode* > ());
}
#line 2630 "grammar/build/syntax.tab.cc"
    break;

  case 136: // while: WHILE LEFT_PAREN expr RIGHT_PAREN stmts END_WHILE
#line 534 "grammar/syntax.y"
                                                         {
  yylhs.value.as < WhileNode* > () = new WhileNode(ctx.line, yystack_[3].value.as < ExpressionNode* > (), WhileType::WHILE);
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < WhileNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2641 "grammar/build/syntax.tab.cc"
    break;

  case 137: // while: WHILE LEFT_PAREN expr RIGHT_PAREN END_WHILE
#line 539 "grammar/syntax.y"
                                                {
  yylhs.value.as < WhileNode* > () = new WhileNode(ctx.line, yystack_[2].value.as < ExpressionNode* > (), WhileType::WHILE);
}
#line 2649 "grammar/build/syntax.tab.cc"
    break;

  case 138: // repeat: REPEAT stmts UNTIL expr
#line 543 "grammar/syntax.y"
                                {
  yylhs.value.as < WhileNode* > () = new WhileNode(ctx.line, yystack_[0].value.as < ExpressionNode* > (), WhileType::REPEAT);
  for (size_t i = 0; i < yystack_[2].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < WhileNode* > ()->children.push_back(yystack_[2].value.as < vector<Node*> > ()[i]);
  };
}
#line 2660 "grammar/build/syntax.tab.cc"
    break;

  case 139: // repeat: REPEAT UNTIL expr
#line 548 "grammar/syntax.y"
                      {
  yylhs.value.as < WhileNode* > () = new WhileNode(ctx.line, yystack_[0].value.as < ExpressionNode* > (), WhileType::REPEAT);
}
#line 2668 "grammar/build/syntax.tab.cc"
    break;

  case 140: // expr: or_expr
#line 552 "grammar/syntax.y"
              {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2676 "grammar/build/syntax.tab.cc"
    break;

  case 141: // expr: range_expr
#line 554 "grammar/syntax.y"
               {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < RangeNode* > ();
}
#line 2684 "grammar/build/syntax.tab.cc"
    break;

  case 142: // range_expr: range_interval or_expr
#line 558 "grammar/syntax.y"
                                   {
  yylhs.value.as < RangeNode* > () = new RangeNode(ctx.line, false, yystack_[0].value.as < ExpressionNode* > (), yystack_[1].value.as < pair<RangeInclusionType, RangeInclusionType> > ().second);
}
#line 2692 "grammar/build/syntax.tab.cc"
    break;

  case 143: // range_expr: or_expr range_interval
#line 560 "grammar/syntax.y"
                           {
  yylhs.value.as < RangeNode* > () = new RangeNode(ctx.line, true, yystack_[1].value.as < ExpressionNode* > (), yystack_[0].value.as < pair<RangeInclusionType, RangeInclusionType> > ().first);
}
#line 2700 "grammar/build/syntax.tab.cc"
    break;

  case 144: // range_expr: or_expr range_interval or_expr
#line 562 "grammar/syntax.y"
                                   {
  yylhs.value.as < RangeNode* > () = new RangeNode(ctx.line, yystack_[2].value.as < ExpressionNode* > (), yystack_[1].value.as < pair<RangeInclusionType, RangeInclusionType> > ().first, yystack_[0].value.as < ExpressionNode* > (), yystack_[1].value.as < pair<RangeInclusionType, RangeInclusionType> > ().second);
}
#line 2708 "grammar/build/syntax.tab.cc"
    break;

  case 145: // range_interval: RANGE
#line 566 "grammar/syntax.y"
                      {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::INCLUSIVE, RangeInclusionType::EXCLUSIVE};
}
#line 2716 "grammar/build/syntax.tab.cc"
    break;

  case 146: // range_interval: RANGE_EXC
#line 568 "grammar/syntax.y"
              {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::EXCLUSIVE, RangeInclusionType::EXCLUSIVE};
}
#line 2724 "grammar/build/syntax.tab.cc"
    break;

  case 147: // range_interval: RANGE_EXC_INC
#line 570 "grammar/syntax.y"
                  {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::EXCLUSIVE, RangeInclusionType::INCLUSIVE};
}
#line 2732 "grammar/build/syntax.tab.cc"
    break;

  case 148: // range_interval: RANGE_INC
#line 572 "grammar/syntax.y"
              {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::INCLUSIVE, RangeInclusionType::INCLUSIVE};
}
#line 2740 "grammar/build/syntax.tab.cc"
    break;

  case 149: // or_expr: or_expr OR and_expr
#line 576 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::OR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2748 "grammar/build/syntax.tab.cc"
    break;

  case 150: // or_expr: and_expr
#line 578 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2756 "grammar/build/syntax.tab.cc"
    break;

  case 151: // and_expr: and_expr AND bit_or_expr
#line 582 "grammar/syntax.y"
                                   {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::AND, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2764 "grammar/build/syntax.tab.cc"
    break;

  case 152: // and_expr: bit_or_expr
#line 584 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2772 "grammar/build/syntax.tab.cc"
    break;

  case 153: // bit_or_expr: bit_or_expr BAR bit_xor_expr
#line 588 "grammar/syntax.y"
                                          {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::BITWISE_OR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2780 "grammar/build/syntax.tab.cc"
    break;

  case 154: // bit_or_expr: bit_xor_expr
#line 590 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2788 "grammar/build/syntax.tab.cc"
    break;

  case 155: // bit_xor_expr: bit_xor_expr XOR bit_and_expr
#line 594 "grammar/syntax.y"
                                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::XOR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2796 "grammar/build/syntax.tab.cc"
    break;

  case 156: // bit_xor_expr: bit_and_expr
#line 596 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2804 "grammar/build/syntax.tab.cc"
    break;

  case 157: // bit_and_expr: bit_and_expr REF equals_expr
#line 600 "grammar/syntax.y"
                                           {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::BITWISE_AND, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2812 "grammar/build/syntax.tab.cc"
    break;

  case 158: // bit_and_expr: equals_expr
#line 602 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2820 "grammar/build/syntax.tab.cc"
    break;

  case 159: // equals_expr: equals_expr EQ rel_expr
#line 606 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2828 "grammar/build/syntax.tab.cc"
    break;

  case 160: // equals_expr: equals_expr NOT_EQ rel_expr
#line 608 "grammar/syntax.y"
                                {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::NOT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2836 "grammar/build/syntax.tab.cc"
    break;

  case 161: // equals_expr: rel_expr
#line 610 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2844 "grammar/build/syntax.tab.cc"
    break;

  case 162: // rel_expr: rel_expr LT concat_expr
#line 614 "grammar/syntax.y"
                                  {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::LT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2852 "grammar/build/syntax.tab.cc"
    break;

  case 163: // rel_expr: rel_expr GT concat_expr
#line 616 "grammar/syntax.y"
                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::GT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2860 "grammar/build/syntax.tab.cc"
    break;

  case 164: // rel_expr: rel_expr LT_EQ concat_expr
#line 618 "grammar/syntax.y"
                               {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::LT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2868 "grammar/build/syntax.tab.cc"
    break;

  case 165: // rel_expr: rel_expr GT_EQ concat_expr
#line 620 "grammar/syntax.y"
                               {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::GT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2876 "grammar/build/syntax.tab.cc"
    break;

  case 166: // rel_expr: rel_expr IN concat_expr
#line 622 "grammar/syntax.y"
                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::IN, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2884 "grammar/build/syntax.tab.cc"
    break;

  case 167: // rel_expr: concat_expr
#line 624 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2892 "grammar/build/syntax.tab.cc"
    break;

  case 168: // concat_expr: concat_expr CONCAT sum_expr
#line 628 "grammar/syntax.y"
                                         {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::CONCAT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2900 "grammar/build/syntax.tab.cc"
    break;

  case 169: // concat_expr: sum_expr
#line 630 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2908 "grammar/build/syntax.tab.cc"
    break;

  case 170: // sum_expr: sum_expr PLUS mult_expr
#line 634 "grammar/syntax.y"
                                  {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::PLUS, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2916 "grammar/build/syntax.tab.cc"
    break;

  case 171: // sum_expr: sum_expr MINUS mult_expr
#line 636 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MINUS, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2924 "grammar/build/syntax.tab.cc"
    break;

  case 172: // sum_expr: mult_expr
#line 638 "grammar/syntax.y"
              {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2932 "grammar/build/syntax.tab.cc"
    break;

  case 173: // mult_expr: mult_expr MULT unary_expr
#line 642 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MULT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2940 "grammar/build/syntax.tab.cc"
    break;

  case 174: // mult_expr: mult_expr DIV unary_expr
#line 644 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::DIV, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2948 "grammar/build/syntax.tab.cc"
    break;

  case 175: // mult_expr: mult_expr MOD unary_expr
#line 646 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MOD, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2956 "grammar/build/syntax.tab.cc"
    break;

  case 176: // mult_expr: unary_expr
#line 648 "grammar/syntax.y"
               {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2964 "grammar/build/syntax.tab.cc"
    break;

  case 177: // unary_expr: MINUS exp_expr
#line 652 "grammar/syntax.y"
                           {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::MINUS, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2972 "grammar/build/syntax.tab.cc"
    break;

  case 178: // unary_expr: REV exp_expr
#line 654 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::REV, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2980 "grammar/build/syntax.tab.cc"
    break;

  case 179: // unary_expr: NOT exp_expr
#line 656 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::NOT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2988 "grammar/build/syntax.tab.cc"
    break;

  case 180: // unary_expr: REF exp_expr
#line 658 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::REF, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2996 "grammar/build/syntax.tab.cc"
    break;

  case 181: // unary_expr: INCREMENT exp_expr
#line 660 "grammar/syntax.y"
                       {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::INCREMENT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 3004 "grammar/build/syntax.tab.cc"
    break;

  case 182: // unary_expr: DECREMENT exp_expr
#line 662 "grammar/syntax.y"
                       {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::DECREMENT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 3012 "grammar/build/syntax.tab.cc"
    break;

  case 183: // unary_expr: MULT exp_expr
#line 664 "grammar/syntax.y"
                  {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 3020 "grammar/build/syntax.tab.cc"
    break;

  case 184: // unary_expr: exp_expr
#line 666 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 3028 "grammar/build/syntax.tab.cc"
    break;

  case 185: // exp_expr: postfix_expr EXP exp_expr
#line 670 "grammar/syntax.y"
                                    {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::EXP, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 3036 "grammar/build/syntax.tab.cc"
    break;

  case 186: // exp_expr: postfix_expr
#line 672 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 3044 "grammar/build/syntax.tab.cc"
    break;

  case 187: // postfix_expr: term INCREMENT
#line 676 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(true, UnaryOperation::INCREMENT, yystack_[1].value.as < ExpressionNode* > ());
}
#line 3052 "grammar/build/syntax.tab.cc"
    break;

  case 188: // postfix_expr: term DECREMENT
#line 678 "grammar/syntax.y"
                   {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(true, UnaryOperation::DECREMENT, yystack_[1].value.as < ExpressionNode* > ());
}
#line 3060 "grammar/build/syntax.tab.cc"
    break;

  case 189: // postfix_expr: term
#line 680 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 3068 "grammar/build/syntax.tab.cc"
    break;

  case 190: // term: INT
#line 684 "grammar/syntax.y"
          {
  yylhs.value.as < ExpressionNode* > () = new IntNode(ctx.line, yystack_[0].value.as < int32_t > ());
}
#line 3076 "grammar/build/syntax.tab.cc"
    break;

  case 191: // term: LONG
#line 686 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new LongNode(ctx.line, yystack_[0].value.as < int64_t > ());
}
#line 3084 "grammar/build/syntax.tab.cc"
    break;

  case 192: // term: FLOAT
#line 688 "grammar/syntax.y"
          {
  yylhs.value.as < ExpressionNode* > () = new FloatNode(ctx.line, yystack_[0].value.as < float > ());
}
#line 3092 "grammar/build/syntax.tab.cc"
    break;

  case 193: // term: DOUBLE
#line 690 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = new DoubleNode(ctx.line, yystack_[0].value.as < double > ());
}
#line 3100 "grammar/build/syntax.tab.cc"
    break;

  case 194: // term: BYTE
#line 692 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new ByteNode(ctx.line, yystack_[0].value.as < uint8_t > ());
}
#line 3108 "grammar/build/syntax.tab.cc"
    break;

  case 195: // term: BOOL
#line 694 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new BoolNode(ctx.line, yystack_[0].value.as < bool > ());
}
#line 3116 "grammar/build/syntax.tab.cc"
    break;

  case 196: // term: STRING
#line 696 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = new StringNode(ctx.line, yystack_[0].value.as < string > ());
}
#line 3124 "grammar/build/syntax.tab.cc"
    break;

  case 197: // term: CHAR
#line 698 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new CharNode(ctx.line, yystack_[0].value.as < char > ());
}
#line 3132 "grammar/build/syntax.tab.cc"
    break;

  case 198: // term: NONE
#line 700 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new OptionNode(ctx.line, Option());
}
#line 3140 "grammar/build/syntax.tab.cc"
    break;

  case 199: // term: array_allocation
#line 702 "grammar/syntax.y"
                     {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ArrayAllocationNode* > ();
}
#line 3148 "grammar/build/syntax.tab.cc"
    break;

  case 200: // term: struct_allocation
#line 704 "grammar/syntax.y"
                      {
  yylhs.value.as < ExpressionNode* > () = nullptr;
}
#line 3156 "grammar/build/syntax.tab.cc"
    break;

  case 201: // term: access
#line 706 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < AccessNode* > ();
}
#line 3164 "grammar/build/syntax.tab.cc"
    break;

  case 202: // term: SOME LEFT_PAREN expr RIGHT_PAREN
#line 708 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new OptionNode(ctx.line, Option());
}
#line 3172 "grammar/build/syntax.tab.cc"
    break;

  case 203: // array_allocation: NEW type LEFT_BRACKET expr RIGHT_BRACKET
#line 712 "grammar/syntax.y"
                                                           {
  yylhs.value.as < ArrayAllocationNode* > () = new ArrayAllocationNode(ctx.line, *yystack_[3].value.as < Type* > (), yystack_[1].value.as < ExpressionNode* > ());
}
#line 3180 "grammar/build/syntax.tab.cc"
    break;

  case 204: // array_allocation: NEW type LEFT_BRACKET expr RIGHT_BRACKET LEFT_BRACE array_allocation_values RIGHT_BRACE
#line 714 "grammar/syntax.y"
                                                                                            {
  yylhs.value.as < ArrayAllocationNode* > () = new ArrayAllocationNode(ctx.line, *yystack_[6].value.as < Type* > (), yystack_[4].value.as < ExpressionNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<ExpressionNode*> > ().size(); i++) {
    yylhs.value.as < ArrayAllocationNode* > ()->children.push_back(yystack_[1].value.as < vector<ExpressionNode*> > ()[i]);
  };
}
#line 3191 "grammar/build/syntax.tab.cc"
    break;

  case 205: // array_allocation_values: array_allocation_values COMMA expr
#line 721 "grammar/syntax.y"
                                                            {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[2].value.as < vector<ExpressionNode*> > ();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 3200 "grammar/build/syntax.tab.cc"
    break;

  case 206: // array_allocation_values: expr
#line 724 "grammar/syntax.y"
         {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 3209 "grammar/build/syntax.tab.cc"
    break;

  case 207: // struct_allocation: NEW type LEFT_BRACE struct_allocation_values RIGHT_BRACE
#line 729 "grammar/syntax.y"
                                                                            {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3217 "grammar/build/syntax.tab.cc"
    break;

  case 208: // struct_allocation: NEW type LEFT_BRACE RIGHT_BRACE
#line 731 "grammar/syntax.y"
                                    {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3225 "grammar/build/syntax.tab.cc"
    break;

  case 209: // struct_allocation_values: struct_allocation_values COMMA ID COLON expr
#line 735 "grammar/syntax.y"
                                                                       {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3233 "grammar/build/syntax.tab.cc"
    break;

  case 210: // struct_allocation_values: ID COLON expr
#line 737 "grammar/syntax.y"
                  {
  yylhs.value.as < Node* > () = nullptr;
}
#line 3241 "grammar/build/syntax.tab.cc"
    break;


#line 3245 "grammar/build/syntax.tab.cc"

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
  "basic_type", "type", "assign", "if", "if_end", "switch", "cases",
  "case_list", "case", "case_values", "default_case", "for", "while",
  "repeat", "expr", "range_expr", "range_interval", "or_expr", "and_expr",
  "bit_or_expr", "bit_xor_expr", "bit_and_expr", "equals_expr", "rel_expr",
  "concat_expr", "sum_expr", "mult_expr", "unary_expr", "exp_expr",
  "postfix_expr", "term", "array_allocation", "array_allocation_values",
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








  const short parser::yypact_ninf_ = -281;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     147,     5,    72,   164,   164,   164,   164,    90,   147,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,    53,    53,  -281,
    -281,    15,    -2,    40,    56,  -281,  -281,     4,    66,   623,
    -281,    76,   -50,  -281,   117,   154,    -1,   120,   164,   150,
     153,   132,  -281,  -281,    41,  -281,  -281,  -281,   202,   209,
     161,  -281,  -281,    70,  -281,  -281,  -281,  -281,   -19,  -281,
     156,   248,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    2849,  2849,  2849,  2849,  2849,  2849,  2849,   248,   225,   228,
    -281,  -281,  -281,  -281,  2586,  2654,   176,   178,   730,  -281,
    -281,  2586,   183,  -281,   188,  -281,  2586,  -281,   159,  -281,
    -281,   837,   191,  -281,  -281,   215,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  2790,    87,   232,   239,   240,   252,
     100,    26,   265,   201,   158,  -281,  -281,   270,   249,  -281,
    -281,  -281,   286,   230,  -281,   295,   248,   236,   238,  -281,
     205,   243,   243,  -281,   164,   246,  -281,   243,   243,  -281,
     253,  -281,   308,  -281,   248,   271,   276,  -281,  -281,   944,
     134,  -281,  -281,  -281,  -281,  -281,  -281,  -281,   -18,   257,
     261,   259,     9,   254,    24,  2586,  2586,  1051,   185,  2586,
    -281,  -281,  2586,  2586,  2586,  2586,  2586,  2586,  2586,  2586,
    2586,  2586,  2586,  2586,    78,   324,  2442,  2586,  -281,   267,
     269,  -281,  -281,   298,  2790,  2790,  2790,  2790,  2790,  2790,
    2790,  2790,  2790,  2790,  2790,  2790,  2790,  2790,  2790,  2790,
    2790,  2790,  2790,  2849,  -281,  -281,  -281,  -281,  -281,   268,
    -281,  -281,   272,    -5,   275,  1158,   237,  -281,   277,   279,
     250,  -281,  -281,   268,   248,   248,   274,  1265,  2514,     2,
     248,   248,  -281,   255,  2335,   258,   288,   284,  -281,  2586,
    2849,   291,   278,   185,  -281,  -281,   289,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,    60,  -281,   290,  -281,  -281,   232,   298,
     239,   240,   252,   100,    26,    26,   265,   265,   265,   265,
     265,   201,   158,   158,  -281,  -281,  -281,  -281,  -281,   139,
     248,   293,  1372,   297,   248,   248,   302,   -12,    20,  -281,
     303,   294,   292,  -281,    19,    14,    23,    28,   409,  2586,
    2586,  1479,  -281,   212,  -281,  2335,  -281,  -281,  -281,  -281,
    2586,  -281,  -281,   308,  -281,   944,  -281,   306,  -281,   -40,
     516,  -281,  -281,  -281,  -281,   305,  2586,   355,  -281,  2586,
    2586,    95,  -281,  2722,  2335,  -281,   309,   307,  -281,  1586,
    2849,  2335,  2335,  -281,   148,  1693,  -281,   313,   315,  2586,
    -281,   310,  -281,  -281,  2335,    18,   311,  1800,  1907,  2586,
    -281,  -281,  2335,  -281,   316,  -281,  -281,  -281,    59,  2586,
     409,   304,  2335,  -281,  -281,  2014,   317,  -281,  2586,  -281,
    -281,  -281,    28,   409,  -281,  2121,  -281,   135,  -281,  -281,
    2228,  2335,  -281,   409,  -281
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
       0,     0,   194,   190,   191,   192,   193,   195,    73,    72,
     196,   197,    96,    92,    95,    93,    94,    99,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,   148,   146,   147,     0,     0,     0,     0,     0,    78,
      79,     0,     0,   198,     0,    69,     0,    67,   201,    68,
      70,     0,     0,    82,    80,     0,    81,    83,    87,    84,
      85,    86,    88,   141,     0,   140,   150,   152,   154,   156,
     158,   161,   167,   169,   172,   176,   184,   186,   189,   199,
     200,    31,     0,     0,    35,     0,     0,     0,     0,    37,
       0,     0,     0,    51,     0,     0,    54,     0,     0,    40,
       0,    41,     0,    17,     0,     0,     0,   104,   100,     0,
     201,   182,   181,   180,   179,   178,   177,   183,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,    77,    25,   142,     0,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   188,   187,    32,    30,    22,    38,
      34,    36,     0,     0,     0,     0,     0,    50,     0,     0,
       0,    39,    19,    21,     0,     0,     0,     0,     0,     0,
       0,     0,    71,     0,     0,     0,     0,     0,   139,     0,
       0,     0,     0,     0,   127,   125,     0,   106,   107,   108,
     109,   112,   110,   113,   111,   114,   115,   116,   105,    64,
      63,    66,    27,     0,    29,     0,    13,    76,   149,   144,
     151,   153,   155,   157,   159,   160,   164,   165,   162,   163,
     166,   168,   171,   170,   175,   173,   174,   185,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
       0,     0,     0,   208,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,   130,     0,   123,   126,   124,   202,
       0,    26,    65,     0,    16,     0,    61,     0,    52,     0,
       0,    48,   102,   103,    12,   203,     0,     0,   207,     0,
       0,     0,   122,     0,     0,   117,     0,     0,   137,     0,
       0,     0,   131,    28,     0,     0,    60,     0,     0,     0,
     210,     0,    90,    91,     0,     0,     0,     0,     0,     0,
     136,   129,   128,    15,     0,    45,    46,   206,     0,     0,
       0,     0,     0,   121,   133,     0,     0,    58,     0,   204,
     209,   118,     0,     0,   132,     0,   205,     0,   119,   135,
       0,     0,   134,     0,   120
  };

  const short
  parser::yypgoto_[] =
  {
    -281,  -281,  -281,   379,  -281,    11,    17,   -99,   -16,    37,
     229,    93,  -281,   280,  -281,  -281,  -281,  -281,  -281,   362,
    -281,  -281,   346,  -281,  -281,  -281,  -281,   356,  -281,  -281,
     -29,  -281,  -281,    25,   -20,   -96,  -281,   219,   -22,   -84,
    -281,  -281,  -280,  -281,  -281,  -281,   133,  -281,   136,  -281,
    -281,  -281,   -89,  -281,   282,  -122,   194,   204,   193,   213,
     216,    67,   -41,   210,    62,   -75,   -61,  -281,  -260,  -281,
    -281,  -281,  -281
  };

  const short
  parser::yydefgoto_[] =
  {
       0,     7,     8,     9,    10,    11,    12,   244,    29,    58,
      59,    60,   107,   208,   293,    13,    32,    14,    36,    37,
      15,    53,    54,    55,    56,    16,    44,    45,    46,    47,
     170,   109,   110,   167,   257,   112,   113,   114,   115,   169,
     116,   117,   375,   118,   272,   273,   274,   343,   275,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     408,   140,   334
  };

  const short
  parser::yytable_[] =
  {
     108,    28,   213,   178,    33,   181,   183,    33,    33,   111,
     344,   332,   188,    33,    17,   210,   142,   191,   263,   171,
     172,   173,   174,   175,   176,   177,    30,   411,    21,    22,
      23,    24,   256,   265,    42,    51,   362,    68,    69,   168,
      43,    52,    72,    73,    74,    75,    76,    77,    78,    79,
     162,   143,   163,   245,   258,    42,   259,   387,   248,   250,
     256,    43,   239,   150,    51,   168,    57,   369,   363,   108,
      52,   222,   223,   224,   225,    57,   370,   333,   187,   189,
     253,    18,   108,    88,    89,   367,   256,   289,   189,   290,
      25,   210,   256,   299,   368,   256,   267,   268,    94,   319,
     276,    34,   147,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,    35,    31,   294,   295,   226,
     401,    38,   154,    27,   168,   418,   350,   220,   214,    35,
     421,   351,   105,    61,   419,    28,    39,    39,    40,    40,
     108,   249,   168,   428,   221,   141,    41,   155,    90,    91,
      92,    93,    48,   434,    49,   314,   315,   316,   108,   151,
     204,   210,   152,   205,    50,   206,    48,   207,    49,   331,
     327,   328,   317,   394,    19,    20,   335,   336,   160,   246,
     342,   306,   307,   308,   309,   310,   144,   192,   193,   149,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   204,
     204,   153,   205,   205,   206,   206,   207,   207,   353,   230,
     354,   157,   203,   431,   231,   232,   108,   162,   158,   403,
     145,   146,   145,   164,   204,   322,   210,   205,   108,   206,
     159,   207,   168,   168,   179,   108,   355,   180,   168,   168,
     359,   360,   210,     1,   338,     2,   184,     3,   185,     4,
     376,   377,     5,   189,     6,   228,   229,   190,    19,    20,
     211,   383,    72,    73,    74,    75,    76,    77,    78,    79,
     165,   166,   216,   234,   235,   270,   271,   390,   380,   381,
     392,   393,   217,   210,   396,   206,   210,   304,   305,   210,
     312,   313,   218,   108,   219,   227,   233,   236,   168,   237,
     407,   210,   168,   168,   238,   240,   210,   241,   371,   108,
     416,   242,   108,   243,   210,   247,   108,    33,   254,   210,
     420,   379,   251,   255,   260,   382,   108,   210,   261,   426,
     262,   108,   264,   291,   210,   385,   296,   210,   297,   214,
     256,   318,   320,   323,   324,   108,   325,   329,   337,   326,
     108,   339,   108,   108,   397,   341,   108,   340,   345,   366,
     349,   402,   356,   352,   391,   108,   358,   365,   108,   108,
     346,   361,   364,   108,   410,   386,   399,   409,   415,   389,
     398,   108,   405,   108,   406,   417,   108,    26,   425,   412,
     384,   252,   423,   427,   108,   212,   108,   422,   148,   161,
     156,   108,   108,   266,   108,   430,   347,   215,   298,   348,
     301,   433,    62,    63,    64,    65,    66,    67,    68,    69,
     300,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,   302,     0,    80,    81,   303,     0,   311,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,     0,     0,     0,     0,     0,    83,    84,
       0,     0,     0,    85,     0,    86,     0,    87,    88,    89,
      90,    91,    92,    93,     0,     0,     0,     0,     0,    94,
       0,     0,     0,     0,     0,    95,   372,     0,   373,   374,
      96,    97,     0,    98,     0,     0,    99,   100,   101,     0,
       0,     0,     0,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,   105,     0,     0,     0,     0,   106,    62,
      63,    64,    65,    66,    67,    68,    69,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,    83,    84,     0,     0,     0,
      85,     0,    86,     0,    87,    88,    89,    90,    91,    92,
      93,     0,     0,     0,     0,     0,    94,     0,   256,     0,
       0,     0,    95,     0,     0,     0,     0,    96,    97,     0,
      98,     0,     0,    99,   100,   101,     0,     0,     0,     0,
     102,   103,     0,   388,     0,     0,     0,     0,     0,     0,
     105,     0,     0,     0,     0,   106,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,     0,     0,     0,     0,
       0,     0,    83,    84,     0,     0,     0,    85,     0,    86,
       0,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,     0,    94,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,    96,    97,     0,    98,     0,     0,
      99,   100,   101,     0,     0,     0,     0,   102,   103,     0,
       0,     0,   104,     0,     0,     0,     0,   105,     0,     0,
       0,     0,   106,    62,    63,    64,    65,    66,    67,    68,
      69,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,    83,
      84,     0,     0,     0,    85,     0,    86,     0,    87,    88,
      89,    90,    91,    92,    93,     0,     0,     0,     0,     0,
      94,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,    96,    97,     0,    98,   186,     0,    99,   100,   101,
       0,     0,     0,     0,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     0,     0,     0,     0,   106,
      62,    63,    64,    65,    66,    67,    68,    69,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
       0,     0,     0,     0,     0,     0,    83,    84,     0,     0,
       0,    85,     0,    86,     0,    87,    88,    89,    90,    91,
      92,    93,     0,     0,     0,     0,     0,    94,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,    96,    97,
       0,    98,     0,     0,    99,   100,   101,     0,     0,     0,
       0,   102,   103,     0,     0,     0,   209,     0,     0,     0,
       0,   105,     0,     0,     0,     0,   106,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,    83,    84,     0,     0,     0,    85,     0,
      86,     0,    87,    88,    89,    90,    91,    92,    93,     0,
       0,     0,     0,     0,    94,     0,   256,     0,     0,     0,
      95,     0,     0,     0,     0,    96,    97,     0,    98,     0,
       0,    99,   100,   101,     0,     0,     0,     0,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,   105,     0,
       0,     0,     0,   106,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
      83,    84,     0,     0,     0,    85,     0,    86,     0,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,     0,
       0,    94,     0,     0,     0,     0,     0,    95,     0,     0,
       0,     0,    96,    97,     0,    98,   269,     0,    99,   100,
     101,     0,     0,     0,     0,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,   105,     0,     0,     0,     0,
     106,    62,    63,    64,    65,    66,    67,    68,    69,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,    83,    84,     0,
       0,     0,    85,     0,    86,     0,    87,    88,    89,    90,
      91,    92,    93,     0,     0,     0,     0,     0,    94,     0,
       0,     0,     0,     0,    95,     0,     0,     0,     0,    96,
      97,     0,    98,     0,     0,    99,   100,   101,     0,     0,
       0,     0,   102,   103,     0,     0,     0,   321,     0,     0,
       0,     0,   105,     0,     0,     0,     0,   106,    62,    63,
      64,    65,    66,    67,    68,    69,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,     0,
       0,     0,     0,     0,    83,    84,     0,     0,     0,    85,
       0,    86,     0,    87,    88,    89,    90,    91,    92,    93,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,    95,     0,     0,     0,     0,    96,    97,     0,    98,
       0,     0,    99,   100,   101,     0,     0,     0,     0,   102,
     103,     0,   330,     0,     0,     0,     0,     0,     0,   105,
       0,     0,     0,     0,   106,    62,    63,    64,    65,    66,
      67,    68,    69,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,    83,    84,     0,     0,     0,    85,     0,    86,     0,
      87,    88,    89,    90,    91,    92,    93,     0,     0,     0,
       0,     0,    94,     0,     0,     0,     0,     0,    95,     0,
       0,     0,     0,    96,    97,     0,    98,     0,     0,    99,
     100,   101,     0,     0,     0,     0,   102,   103,     0,     0,
       0,   357,     0,     0,     0,     0,   105,     0,     0,     0,
       0,   106,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,     0,     0,     0,     0,     0,    83,    84,
       0,     0,     0,    85,     0,    86,     0,    87,    88,    89,
      90,    91,    92,    93,     0,     0,     0,     0,     0,    94,
       0,     0,     0,     0,     0,    95,     0,     0,     0,     0,
      96,    97,   378,    98,     0,     0,    99,   100,   101,     0,
       0,     0,     0,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,   105,     0,     0,     0,     0,   106,    62,
      63,    64,    65,    66,    67,    68,    69,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,    83,    84,     0,     0,     0,
      85,     0,    86,     0,    87,    88,    89,    90,    91,    92,
      93,     0,     0,     0,     0,     0,    94,     0,     0,     0,
       0,     0,    95,     0,     0,     0,     0,    96,    97,   400,
      98,     0,     0,    99,   100,   101,     0,     0,     0,     0,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
     105,     0,     0,     0,     0,   106,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,     0,     0,     0,     0,
       0,     0,    83,    84,     0,     0,     0,    85,     0,    86,
       0,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,     0,    94,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,    96,    97,     0,    98,     0,     0,
      99,   100,   101,     0,     0,     0,     0,   102,   103,     0,
     404,     0,     0,     0,     0,     0,     0,   105,     0,     0,
       0,     0,   106,    62,    63,    64,    65,    66,    67,    68,
      69,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,    83,
      84,     0,     0,     0,    85,     0,    86,     0,    87,    88,
      89,    90,    91,    92,    93,     0,     0,     0,     0,     0,
      94,     0,     0,     0,     0,     0,    95,   413,     0,     0,
       0,    96,    97,     0,    98,     0,     0,    99,   100,   101,
       0,     0,     0,     0,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     0,     0,     0,     0,   106,
      62,    63,    64,    65,    66,    67,    68,    69,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
       0,     0,     0,     0,     0,     0,    83,    84,     0,     0,
       0,    85,     0,    86,     0,    87,    88,    89,    90,    91,
      92,    93,     0,     0,     0,     0,     0,    94,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,    96,    97,
       0,    98,     0,   414,    99,   100,   101,     0,     0,     0,
       0,   102,   103,     0,     0,     0,     0,     0,     0,     0,
       0,   105,     0,     0,     0,     0,   106,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,    83,    84,     0,     0,     0,    85,     0,
      86,     0,    87,    88,    89,    90,    91,    92,    93,     0,
       0,     0,     0,     0,    94,     0,     0,     0,     0,     0,
      95,     0,     0,     0,     0,    96,    97,     0,    98,     0,
     424,    99,   100,   101,     0,     0,     0,     0,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,   105,     0,
       0,     0,     0,   106,    62,    63,    64,    65,    66,    67,
      68,    69,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
      83,    84,     0,     0,     0,    85,     0,    86,     0,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,     0,
       0,    94,     0,     0,     0,     0,     0,    95,     0,     0,
       0,     0,    96,    97,     0,    98,     0,   429,    99,   100,
     101,     0,     0,     0,     0,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,   105,     0,     0,     0,     0,
     106,    62,    63,    64,    65,    66,    67,    68,    69,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,    83,    84,     0,
       0,     0,    85,     0,    86,     0,    87,    88,    89,    90,
      91,    92,    93,     0,     0,     0,     0,     0,    94,     0,
       0,     0,     0,     0,    95,     0,     0,     0,     0,    96,
      97,     0,    98,     0,   432,    99,   100,   101,     0,     0,
       0,     0,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,   105,     0,     0,     0,     0,   106,    62,    63,
      64,    65,    66,    67,    68,    69,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,     0,
       0,     0,     0,     0,    83,    84,     0,     0,     0,    85,
       0,    86,     0,    87,    88,    89,    90,    91,    92,    93,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,    95,     0,     0,     0,     0,    96,    97,     0,    98,
       0,     0,    99,   100,   101,     0,     0,     0,     0,   102,
     103,     0,     0,     0,     0,     0,     0,     0,     0,   105,
       0,     0,     0,     0,   106,    62,    63,    64,    65,    66,
      67,    68,    69,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,    83,    84,     0,     0,     0,    85,     0,    86,     0,
      87,     0,     0,    90,    91,    92,    93,     0,     0,     0,
       0,     0,    94,   292,     0,     0,     0,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,   102,   103,    80,    81,
       0,     0,     0,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,    83,    84,     0,     0,     0,    85,     0,
      86,     0,    87,     0,     0,    90,    91,    92,    93,     0,
       0,     0,     0,     0,    94,     0,     0,   329,     0,    62,
      63,    64,    65,    66,    67,    68,    69,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,   102,   103,
      80,    81,     0,     0,     0,     0,     0,     0,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,    83,    84,     0,     0,     0,
      85,     0,    86,     0,    87,     0,     0,    90,    91,    92,
      93,     0,     0,     0,     0,     0,    94,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,    80,    81,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
     105,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,    83,    84,     0,     0,     0,    85,     0,
      86,     0,    87,     0,     0,    90,    91,    92,    93,     0,
       0,     0,     0,     0,    94,    62,    63,    64,    65,    66,
      67,    68,    69,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,     0,    80,    81,   182,   103,
       0,     0,     0,     0,     0,     0,     0,     0,   105,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,    83,    84,     0,     0,     0,    85,     0,    86,     0,
      87,     0,     0,    90,    91,    92,    93,     0,     0,     0,
       0,     0,    94,    62,    63,    64,    65,    66,    67,    68,
      69,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,     0,    80,    81,   395,   103,     0,     0,
       0,     0,     0,     0,     0,     0,   105,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,    83,
      84,     0,     0,     0,    85,     0,    86,     0,    87,     0,
       0,     0,    62,    63,    64,    65,    66,    67,    68,    69,
      94,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,   105
  };

  const short
  parser::yycheck_[] =
  {
      29,    17,   124,    87,     9,    94,    95,     9,     9,    29,
     270,     9,   101,     9,     9,   111,    66,   106,     9,    80,
      81,    82,    83,    84,    85,    86,    11,     9,     3,     4,
       5,     6,    72,     9,    23,    24,    48,     9,    10,    61,
      23,    24,    14,    15,    16,    17,    18,    19,    20,    21,
      69,   101,    71,   152,    72,    44,    74,    97,   157,   158,
      72,    44,   146,    38,    53,    87,    71,    53,    48,    98,
      53,    45,    46,    47,    48,    71,    53,    75,    98,    70,
     164,     9,   111,    59,    60,    66,    72,     9,    70,    11,
       0,   187,    72,   215,    75,    72,   185,   186,    70,   104,
     189,   103,   103,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,    22,   101,   206,   207,    93,
     380,    81,    81,    70,   146,    66,    66,    27,    41,    36,
     410,    71,   104,    67,    75,   151,    96,    96,    98,    98,
     169,   157,   164,   423,    44,    69,   106,   106,    61,    62,
      63,    64,    96,   433,    98,   230,   231,   232,   187,     9,
      65,   257,     9,    68,   108,    70,    96,    72,    98,   258,
     254,   255,   233,    78,    10,    11,   260,   261,   108,   154,
     269,   222,   223,   224,   225,   226,    69,    28,    29,    69,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    65,
      65,    69,    68,    68,    70,    70,    72,    72,    69,    51,
      71,     9,    53,    78,    56,    57,   245,    69,     9,    71,
      66,    67,    66,    67,    65,   245,   322,    68,   257,    70,
      69,    72,   254,   255,     9,   264,   320,     9,   260,   261,
     324,   325,   338,    96,   264,    98,    70,   100,    70,   102,
     339,   340,   105,    70,   107,    54,    55,    69,    10,    11,
      69,   350,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    40,    24,    25,    90,    91,   366,    66,    67,
     369,   370,    43,   379,   373,    70,   382,   220,   221,   385,
     228,   229,    52,   322,    42,    30,    26,    11,   320,    69,
     389,   397,   324,   325,     9,    69,   402,    69,   337,   338,
     399,   106,   341,    70,   410,    69,   345,     9,    47,   415,
     409,   341,    69,    47,    67,   345,   355,   423,    67,   418,
      71,   360,    78,     9,   430,   355,    69,   433,    69,    41,
      72,    69,    67,   106,    67,   374,    67,    73,    93,    99,
     379,    93,   381,   382,   374,    71,   385,    69,    67,    67,
      71,   381,    69,    73,     9,   394,    69,    73,   397,   398,
      92,    69,    69,   402,   394,    69,    69,    67,   398,    74,
      71,   410,    69,   412,    69,    69,   415,     8,    71,    78,
     353,   162,   412,   422,   423,   115,   425,    93,    36,    53,
      44,   430,   431,   184,   433,   425,   273,   125,   214,   273,
     217,   431,     3,     4,     5,     6,     7,     8,     9,    10,
     216,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   218,    -1,    24,    25,   219,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    79,    80,
      81,    82,    -1,    84,    -1,    -1,    87,    88,    89,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,    -1,
      84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,   109,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    24,    25,    -1,
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
      20,    21,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    81,    82,    -1,    84,    85,    -1,    87,    88,    89,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,
      -1,    84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,   109,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,
      -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    24,    25,    -1,    -1,    -1,
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
      -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,
      82,    -1,    84,    -1,    -1,    87,    88,    89,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,   109,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,
      -1,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,
      95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,   109,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    24,    25,    -1,    -1,
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
      21,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    -1,    -1,    87,    88,    89,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,   109,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,    -1,
      87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,   109,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,
      -1,    81,    82,    -1,    84,    -1,    -1,    87,    88,    89,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,
      -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,   109,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,    -1,
      86,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    24,    25,    -1,    -1,    -1,
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
      -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,
      82,    -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,   109,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    81,    82,    -1,    84,
      -1,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,   109,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,
      58,    -1,    -1,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    94,    95,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      56,    -1,    58,    -1,    -1,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    94,    95,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    56,    -1,    58,    -1,    -1,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    24,    25,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      56,    -1,    58,    -1,    -1,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    24,    25,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,
      58,    -1,    -1,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    24,    25,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      70,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104
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
      24,    25,    42,    49,    50,    54,    56,    58,    59,    60,
      61,    62,    63,    64,    70,    76,    81,    82,    84,    87,
      88,    89,    94,    95,    99,   104,   109,   122,   140,   141,
     142,   144,   145,   146,   147,   148,   150,   151,   153,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     181,    69,    66,   101,    69,    66,    67,   103,   129,    69,
     143,     9,     9,    69,    81,   106,   137,     9,     9,    69,
     108,   132,    69,    71,    67,    22,    23,   143,   148,   149,
     140,   176,   176,   176,   176,   176,   176,   176,   149,     9,
       9,   162,    94,   162,    70,    70,    85,   144,   162,    70,
      69,   162,    28,    29,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    53,    65,    68,    70,    72,   123,    99,
     145,    69,   123,   165,    41,   164,    40,    43,    52,    42,
      27,    44,    45,    46,    47,    48,    93,    30,    54,    55,
      51,    56,    57,    26,    24,    25,    11,    69,     9,   149,
      69,    69,   106,    70,   117,   117,   143,    69,   117,   118,
     117,    69,   120,   149,    47,    47,    72,   144,    72,    74,
      67,    67,    71,     9,    78,     9,   147,   162,   162,    85,
      90,    91,   154,   155,   156,   158,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,     9,
      11,     9,    71,   124,   162,   162,    69,    69,   166,   165,
     167,   168,   169,   170,   171,   171,   172,   172,   172,   172,
     172,   173,   174,   174,   175,   175,   175,   176,    69,   104,
      67,    99,   144,   106,    67,    67,    99,   149,   149,    73,
      97,   162,     9,    75,   182,   149,   149,    93,   144,    93,
      69,    71,   162,   157,   178,    67,    92,   156,   158,    71,
      66,    71,    73,    69,    71,   149,    69,    99,    69,   149,
     149,    69,    48,    48,    69,    73,    67,    66,    75,    53,
      53,   140,    77,    79,    80,   152,   162,   162,    83,   144,
      66,    67,   144,   162,   119,   144,    69,    97,    97,    74,
     162,     9,   162,   162,    78,    94,   162,   144,    71,    69,
      83,   178,   144,    71,    97,    69,    69,   162,   180,    67,
     144,     9,    78,    77,    86,   144,   162,    69,    66,    75,
     162,   152,    93,   144,    86,    71,   162,   140,   152,    86,
     144,    78,    86,   144,   152
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
     149,   149,   149,   149,   149,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   151,   151,   152,
     152,   152,   152,   153,   154,   154,   155,   155,   156,   157,
     157,   158,   159,   159,   159,   159,   160,   160,   161,   161,
     162,   162,   163,   163,   163,   164,   164,   164,   164,   165,
     165,   166,   166,   167,   167,   168,   168,   169,   169,   170,
     170,   170,   171,   171,   171,   171,   171,   171,   172,   172,
     173,   173,   173,   174,   174,   174,   174,   175,   175,   175,
     175,   175,   175,   175,   175,   176,   176,   177,   177,   177,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   179,   179,   180,   180,   181,   181,   182,
     182
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
       1,     3,     4,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     8,     5,
       8,     3,     1,     4,     2,     1,     2,     1,     4,     3,
       1,     3,     8,     7,    10,     9,     6,     5,     4,     3,
       1,     1,     2,     2,     3,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     2,     2,     2,
       2,     2,     2,     2,     1,     3,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     8,     3,     1,     5,     4,     5,
       3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   104,   104,   108,   111,   116,   118,   120,   122,   124,
     128,   130,   134,   141,   146,   150,   152,   156,   158,   162,
     167,   174,   181,   184,   189,   191,   195,   197,   201,   204,
     209,   211,   215,   218,   223,   225,   229,   234,   238,   245,
     247,   251,   253,   257,   259,   263,   265,   267,   271,   273,
     277,   279,   281,   283,   287,   289,   293,   295,   299,   301,
     305,   307,   309,   313,   315,   317,   319,   321,   323,   327,
     329,   331,   335,   337,   341,   343,   347,   350,   355,   357,
     359,   361,   363,   365,   367,   369,   371,   373,   375,   379,
     383,   385,   389,   391,   393,   395,   397,   399,   401,   403,
     407,   409,   411,   413,   415,   419,   421,   423,   425,   427,
     429,   431,   433,   435,   437,   439,   441,   445,   450,   457,
     462,   467,   472,   476,   480,   483,   488,   491,   496,   503,
     506,   511,   518,   523,   525,   530,   534,   539,   543,   548,
     552,   554,   558,   560,   562,   566,   568,   570,   572,   576,
     578,   582,   584,   588,   590,   594,   596,   600,   602,   606,
     608,   610,   614,   616,   618,   620,   622,   624,   628,   630,
     634,   636,   638,   642,   644,   646,   648,   652,   654,   656,
     658,   660,   662,   664,   666,   670,   672,   676,   678,   680,
     684,   686,   688,   690,   692,   694,   696,   698,   700,   702,
     704,   706,   708,   712,   714,   721,   724,   729,   731,   735,
     737
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
#line 4400 "grammar/build/syntax.tab.cc"

#line 740 "grammar/syntax.y"
