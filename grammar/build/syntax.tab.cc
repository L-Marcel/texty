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
      case symbol_kind::S_trait_fn: // trait_fn
      case symbol_kind::S_impl_fn: // impl_fn
        value.YY_MOVE_OR_COPY< FunctionNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_end: // if_end
        value.YY_MOVE_OR_COPY< IfEndNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if: // if
        value.YY_MOVE_OR_COPY< IfNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_impl: // impl
        value.YY_MOVE_OR_COPY< ImplNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_program_slice: // program_slice
      case symbol_kind::S_stmt: // stmt
        value.YY_MOVE_OR_COPY< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_proc: // proc
      case symbol_kind::S_trait_proc: // trait_proc
      case symbol_kind::S_impl_proc: // impl_proc
        value.YY_MOVE_OR_COPY< ProcedureNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_range_expr: // range_expr
        value.YY_MOVE_OR_COPY< RangeNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_return: // return
        value.YY_MOVE_OR_COPY< ReturnNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_allocation: // struct_allocation
        value.YY_MOVE_OR_COPY< StructAllocationNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct: // struct
        value.YY_MOVE_OR_COPY< StructNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subprogram_call: // subprogram_call
        value.YY_MOVE_OR_COPY< SubprogramCallNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subprogram: // subprogram
      case symbol_kind::S_trait_subprogram: // trait_subprogram
      case symbol_kind::S_impl_subprogram: // impl_subprogram
        value.YY_MOVE_OR_COPY< SubprogramNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_switch: // switch
        value.YY_MOVE_OR_COPY< SwitchNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_trait: // trait
        value.YY_MOVE_OR_COPY< TraitNode* > (YY_MOVE (that.value));
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
      case symbol_kind::S_TYPE_POINTER: // TYPE_POINTER
      case symbol_kind::S_TYPE_OPTION: // TYPE_OPTION
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

      case symbol_kind::S_trait_subprograms: // trait_subprograms
      case symbol_kind::S_impl_subprograms: // impl_subprograms
        value.YY_MOVE_OR_COPY< vector<SubprogramNode*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_allocation_values: // struct_allocation_values
        value.YY_MOVE_OR_COPY< vector<pair<string, ExpressionNode*>> > (YY_MOVE (that.value));
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
      case symbol_kind::S_trait_fn: // trait_fn
      case symbol_kind::S_impl_fn: // impl_fn
        value.move< FunctionNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_end: // if_end
        value.move< IfEndNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if: // if
        value.move< IfNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_impl: // impl
        value.move< ImplNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_program_slice: // program_slice
      case symbol_kind::S_stmt: // stmt
        value.move< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_proc: // proc
      case symbol_kind::S_trait_proc: // trait_proc
      case symbol_kind::S_impl_proc: // impl_proc
        value.move< ProcedureNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_range_expr: // range_expr
        value.move< RangeNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_return: // return
        value.move< ReturnNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_allocation: // struct_allocation
        value.move< StructAllocationNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct: // struct
        value.move< StructNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subprogram_call: // subprogram_call
        value.move< SubprogramCallNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subprogram: // subprogram
      case symbol_kind::S_trait_subprogram: // trait_subprogram
      case symbol_kind::S_impl_subprogram: // impl_subprogram
        value.move< SubprogramNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_switch: // switch
        value.move< SwitchNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_trait: // trait
        value.move< TraitNode* > (YY_MOVE (that.value));
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
      case symbol_kind::S_TYPE_POINTER: // TYPE_POINTER
      case symbol_kind::S_TYPE_OPTION: // TYPE_OPTION
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

      case symbol_kind::S_trait_subprograms: // trait_subprograms
      case symbol_kind::S_impl_subprograms: // impl_subprograms
        value.move< vector<SubprogramNode*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_allocation_values: // struct_allocation_values
        value.move< vector<pair<string, ExpressionNode*>> > (YY_MOVE (that.value));
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
      case symbol_kind::S_trait_fn: // trait_fn
      case symbol_kind::S_impl_fn: // impl_fn
        value.copy< FunctionNode* > (that.value);
        break;

      case symbol_kind::S_if_end: // if_end
        value.copy< IfEndNode* > (that.value);
        break;

      case symbol_kind::S_if: // if
        value.copy< IfNode* > (that.value);
        break;

      case symbol_kind::S_impl: // impl
        value.copy< ImplNode* > (that.value);
        break;

      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_program_slice: // program_slice
      case symbol_kind::S_stmt: // stmt
        value.copy< Node* > (that.value);
        break;

      case symbol_kind::S_proc: // proc
      case symbol_kind::S_trait_proc: // trait_proc
      case symbol_kind::S_impl_proc: // impl_proc
        value.copy< ProcedureNode* > (that.value);
        break;

      case symbol_kind::S_range_expr: // range_expr
        value.copy< RangeNode* > (that.value);
        break;

      case symbol_kind::S_return: // return
        value.copy< ReturnNode* > (that.value);
        break;

      case symbol_kind::S_struct_allocation: // struct_allocation
        value.copy< StructAllocationNode* > (that.value);
        break;

      case symbol_kind::S_struct: // struct
        value.copy< StructNode* > (that.value);
        break;

      case symbol_kind::S_subprogram_call: // subprogram_call
        value.copy< SubprogramCallNode* > (that.value);
        break;

      case symbol_kind::S_subprogram: // subprogram
      case symbol_kind::S_trait_subprogram: // trait_subprogram
      case symbol_kind::S_impl_subprogram: // impl_subprogram
        value.copy< SubprogramNode* > (that.value);
        break;

      case symbol_kind::S_switch: // switch
        value.copy< SwitchNode* > (that.value);
        break;

      case symbol_kind::S_trait: // trait
        value.copy< TraitNode* > (that.value);
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
      case symbol_kind::S_TYPE_POINTER: // TYPE_POINTER
      case symbol_kind::S_TYPE_OPTION: // TYPE_OPTION
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

      case symbol_kind::S_trait_subprograms: // trait_subprograms
      case symbol_kind::S_impl_subprograms: // impl_subprograms
        value.copy< vector<SubprogramNode*> > (that.value);
        break;

      case symbol_kind::S_struct_allocation_values: // struct_allocation_values
        value.copy< vector<pair<string, ExpressionNode*>> > (that.value);
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
      case symbol_kind::S_trait_fn: // trait_fn
      case symbol_kind::S_impl_fn: // impl_fn
        value.move< FunctionNode* > (that.value);
        break;

      case symbol_kind::S_if_end: // if_end
        value.move< IfEndNode* > (that.value);
        break;

      case symbol_kind::S_if: // if
        value.move< IfNode* > (that.value);
        break;

      case symbol_kind::S_impl: // impl
        value.move< ImplNode* > (that.value);
        break;

      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_program_slice: // program_slice
      case symbol_kind::S_stmt: // stmt
        value.move< Node* > (that.value);
        break;

      case symbol_kind::S_proc: // proc
      case symbol_kind::S_trait_proc: // trait_proc
      case symbol_kind::S_impl_proc: // impl_proc
        value.move< ProcedureNode* > (that.value);
        break;

      case symbol_kind::S_range_expr: // range_expr
        value.move< RangeNode* > (that.value);
        break;

      case symbol_kind::S_return: // return
        value.move< ReturnNode* > (that.value);
        break;

      case symbol_kind::S_struct_allocation: // struct_allocation
        value.move< StructAllocationNode* > (that.value);
        break;

      case symbol_kind::S_struct: // struct
        value.move< StructNode* > (that.value);
        break;

      case symbol_kind::S_subprogram_call: // subprogram_call
        value.move< SubprogramCallNode* > (that.value);
        break;

      case symbol_kind::S_subprogram: // subprogram
      case symbol_kind::S_trait_subprogram: // trait_subprogram
      case symbol_kind::S_impl_subprogram: // impl_subprogram
        value.move< SubprogramNode* > (that.value);
        break;

      case symbol_kind::S_switch: // switch
        value.move< SwitchNode* > (that.value);
        break;

      case symbol_kind::S_trait: // trait
        value.move< TraitNode* > (that.value);
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
      case symbol_kind::S_TYPE_POINTER: // TYPE_POINTER
      case symbol_kind::S_TYPE_OPTION: // TYPE_OPTION
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

      case symbol_kind::S_trait_subprograms: // trait_subprograms
      case symbol_kind::S_impl_subprograms: // impl_subprograms
        value.move< vector<SubprogramNode*> > (that.value);
        break;

      case symbol_kind::S_struct_allocation_values: // struct_allocation_values
        value.move< vector<pair<string, ExpressionNode*>> > (that.value);
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
      case symbol_kind::S_trait_fn: // trait_fn
      case symbol_kind::S_impl_fn: // impl_fn
        yylhs.value.emplace< FunctionNode* > ();
        break;

      case symbol_kind::S_if_end: // if_end
        yylhs.value.emplace< IfEndNode* > ();
        break;

      case symbol_kind::S_if: // if
        yylhs.value.emplace< IfNode* > ();
        break;

      case symbol_kind::S_impl: // impl
        yylhs.value.emplace< ImplNode* > ();
        break;

      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_program_slice: // program_slice
      case symbol_kind::S_stmt: // stmt
        yylhs.value.emplace< Node* > ();
        break;

      case symbol_kind::S_proc: // proc
      case symbol_kind::S_trait_proc: // trait_proc
      case symbol_kind::S_impl_proc: // impl_proc
        yylhs.value.emplace< ProcedureNode* > ();
        break;

      case symbol_kind::S_range_expr: // range_expr
        yylhs.value.emplace< RangeNode* > ();
        break;

      case symbol_kind::S_return: // return
        yylhs.value.emplace< ReturnNode* > ();
        break;

      case symbol_kind::S_struct_allocation: // struct_allocation
        yylhs.value.emplace< StructAllocationNode* > ();
        break;

      case symbol_kind::S_struct: // struct
        yylhs.value.emplace< StructNode* > ();
        break;

      case symbol_kind::S_subprogram_call: // subprogram_call
        yylhs.value.emplace< SubprogramCallNode* > ();
        break;

      case symbol_kind::S_subprogram: // subprogram
      case symbol_kind::S_trait_subprogram: // trait_subprogram
      case symbol_kind::S_impl_subprogram: // impl_subprogram
        yylhs.value.emplace< SubprogramNode* > ();
        break;

      case symbol_kind::S_switch: // switch
        yylhs.value.emplace< SwitchNode* > ();
        break;

      case symbol_kind::S_trait: // trait
        yylhs.value.emplace< TraitNode* > ();
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
      case symbol_kind::S_TYPE_POINTER: // TYPE_POINTER
      case symbol_kind::S_TYPE_OPTION: // TYPE_OPTION
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

      case symbol_kind::S_trait_subprograms: // trait_subprograms
      case symbol_kind::S_impl_subprograms: // impl_subprograms
        yylhs.value.emplace< vector<SubprogramNode*> > ();
        break;

      case symbol_kind::S_struct_allocation_values: // struct_allocation_values
        yylhs.value.emplace< vector<pair<string, ExpressionNode*>> > ();
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
#line 106 "grammar/syntax.y"
              {
  ctx.root = yystack_[0].value.as < Node* > ();
}
#line 1602 "grammar/build/syntax.tab.cc"
    break;

  case 3: // program: program program_slice
#line 110 "grammar/syntax.y"
                               {
  yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > ();
  yystack_[1].value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
}
#line 1611 "grammar/build/syntax.tab.cc"
    break;

  case 4: // program: program_slice
#line 113 "grammar/syntax.y"
                  {
  yylhs.value.as < Node* > () = new Node(ctx.line, "PROGRAM");
  yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
}
#line 1620 "grammar/build/syntax.tab.cc"
    break;

  case 5: // program_slice: subprogram
#line 118 "grammar/syntax.y"
                          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < SubprogramNode* > ();
}
#line 1628 "grammar/build/syntax.tab.cc"
    break;

  case 6: // program_slice: enum
#line 120 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < EnumNode* > ();
}
#line 1636 "grammar/build/syntax.tab.cc"
    break;

  case 7: // program_slice: struct
#line 122 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < StructNode* > ();
}
#line 1644 "grammar/build/syntax.tab.cc"
    break;

  case 8: // program_slice: trait
#line 124 "grammar/syntax.y"
          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < TraitNode* > ();
}
#line 1652 "grammar/build/syntax.tab.cc"
    break;

  case 9: // program_slice: impl
#line 126 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ImplNode* > ();
}
#line 1660 "grammar/build/syntax.tab.cc"
    break;

  case 10: // subprogram: fn
#line 130 "grammar/syntax.y"
               {
  yylhs.value.as < SubprogramNode* > () = yystack_[0].value.as < FunctionNode* > ();
}
#line 1668 "grammar/build/syntax.tab.cc"
    break;

  case 11: // subprogram: proc
#line 132 "grammar/syntax.y"
         {
  yylhs.value.as < SubprogramNode* > () = yystack_[0].value.as < ProcedureNode* > ();
}
#line 1676 "grammar/build/syntax.tab.cc"
    break;

  case 12: // fn: FUNCTION ID params_list COLON type stmts END_FUNCTION SEMICOLON
#line 136 "grammar/syntax.y"
                                                                    {
  yylhs.value.as < FunctionNode* > () = new FunctionNode(ctx.line, yystack_[6].value.as < string > (), *yystack_[3].value.as < Type* > (), yystack_[5].value.as < vector<pair<string, Type>> > ());
  for (size_t i = 0; i < yystack_[2].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < FunctionNode* > ()->children.push_back(yystack_[2].value.as < vector<Node*> > ()[i]);
  };
}
#line 1687 "grammar/build/syntax.tab.cc"
    break;

  case 13: // proc: PROCEDURE ID params_list stmts END_PROCEDURE SEMICOLON
#line 143 "grammar/syntax.y"
                                                             {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[4].value.as < string > (), yystack_[3].value.as < vector<pair<string, Type>> > ());
  for (size_t i = 0; i < yystack_[2].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < ProcedureNode* > ()->children.push_back(yystack_[2].value.as < vector<Node*> > ()[i]);
  };
}
#line 1698 "grammar/build/syntax.tab.cc"
    break;

  case 14: // proc: PROCEDURE ID params_list END_PROCEDURE SEMICOLON
#line 148 "grammar/syntax.y"
                                                     {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[3].value.as < string > (), yystack_[2].value.as < vector<pair<string, Type>> > ());
}
#line 1706 "grammar/build/syntax.tab.cc"
    break;

  case 15: // params_self_list: LEFT_PAREN SELF SEMICOLON params RIGHT_PAREN
#line 152 "grammar/syntax.y"
                                                               {
  yylhs.value.as < vector<pair<string, Type>> > () = yystack_[1].value.as < vector<pair<string, Type>> > ();
}
#line 1714 "grammar/build/syntax.tab.cc"
    break;

  case 16: // params_self_list: LEFT_PAREN SELF RIGHT_PAREN
#line 154 "grammar/syntax.y"
                                {
  yylhs.value.as < vector<pair<string, Type>> > () = vector<pair<string, Type>>();
}
#line 1722 "grammar/build/syntax.tab.cc"
    break;

  case 17: // params_list: LEFT_PAREN params RIGHT_PAREN
#line 158 "grammar/syntax.y"
                                           {
  yylhs.value.as < vector<pair<string, Type>> > () = yystack_[1].value.as < vector<pair<string, Type>> > ();
}
#line 1730 "grammar/build/syntax.tab.cc"
    break;

  case 18: // params_list: LEFT_PAREN RIGHT_PAREN
#line 160 "grammar/syntax.y"
                           {
  yylhs.value.as < vector<pair<string, Type>> > () = vector<pair<string, Type>>();
}
#line 1738 "grammar/build/syntax.tab.cc"
    break;

  case 19: // params: params SEMICOLON param
#line 164 "grammar/syntax.y"
                               {
  yylhs.value.as < vector<pair<string, Type>> > () = yystack_[2].value.as < vector<pair<string, Type>> > ();
  for (size_t i = 0; i < yystack_[0].value.as < vector<pair<string, Type>> > ().size(); i++) {
    yylhs.value.as < vector<pair<string, Type>> > ().push_back(yystack_[0].value.as < vector<pair<string, Type>> > ()[i]);
  };
}
#line 1749 "grammar/build/syntax.tab.cc"
    break;

  case 20: // params: param
#line 169 "grammar/syntax.y"
          {
  yylhs.value.as < vector<pair<string, Type>> > () = vector<pair<string, Type>>();
  for (size_t i = 0; i < yystack_[0].value.as < vector<pair<string, Type>> > ().size(); i++) {
    yylhs.value.as < vector<pair<string, Type>> > ().push_back(yystack_[0].value.as < vector<pair<string, Type>> > ()[i]);
  };
}
#line 1760 "grammar/build/syntax.tab.cc"
    break;

  case 21: // param: id_list COLON type
#line 176 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<pair<string, Type>> > () = vector<pair<string, Type>>();
  for (size_t i = 0; i < yystack_[2].value.as < vector<string> > ().size(); i++) {
    yylhs.value.as < vector<pair<string, Type>> > ().push_back({yystack_[2].value.as < vector<string> > ()[i], *yystack_[0].value.as < Type* > ()});
  };
}
#line 1771 "grammar/build/syntax.tab.cc"
    break;

  case 22: // id_list: id_list COMMA ID
#line 183 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<string> > () = yystack_[2].value.as < vector<string> > ();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < string > ());
}
#line 1780 "grammar/build/syntax.tab.cc"
    break;

  case 23: // id_list: ID
#line 186 "grammar/syntax.y"
       {
  yylhs.value.as < vector<string> > () = vector<string>();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < string > ());
}
#line 1789 "grammar/build/syntax.tab.cc"
    break;

  case 24: // subprogram_call: access call_params_list
#line 191 "grammar/syntax.y"
                                         {
  yylhs.value.as < SubprogramCallNode* > () = new SubprogramCallNode(ctx.line, yystack_[1].value.as < AccessNode* > (), yystack_[0].value.as < vector<ExpressionNode*> > ());
}
#line 1797 "grammar/build/syntax.tab.cc"
    break;

  case 25: // subprogram_call: basic_type call_params_list
#line 193 "grammar/syntax.y"
                                {
  yylhs.value.as < SubprogramCallNode* > () = new SubprogramCallNode(ctx.line, *yystack_[1].value.as < Type* > (), yystack_[0].value.as < vector<ExpressionNode*> > ());
}
#line 1805 "grammar/build/syntax.tab.cc"
    break;

  case 26: // call_params_list: LEFT_PAREN call_params RIGHT_PAREN
#line 197 "grammar/syntax.y"
                                                     {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[1].value.as < vector<ExpressionNode*> > ();
}
#line 1813 "grammar/build/syntax.tab.cc"
    break;

  case 27: // call_params_list: LEFT_PAREN RIGHT_PAREN
#line 199 "grammar/syntax.y"
                           {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
}
#line 1821 "grammar/build/syntax.tab.cc"
    break;

  case 28: // call_params: call_params COMMA expr
#line 203 "grammar/syntax.y"
                                    {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[2].value.as < vector<ExpressionNode*> > ();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 1830 "grammar/build/syntax.tab.cc"
    break;

  case 29: // call_params: expr
#line 206 "grammar/syntax.y"
         {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 1839 "grammar/build/syntax.tab.cc"
    break;

  case 30: // enum: ENUM name enum_values END_ENUM SEMICOLON
#line 211 "grammar/syntax.y"
                                               {
  yylhs.value.as < EnumNode* > () = new EnumNode(ctx.line, yystack_[3].value.as < string > (), yystack_[2].value.as < vector<string> > ());
}
#line 1847 "grammar/build/syntax.tab.cc"
    break;

  case 31: // enum: ENUM name END_ENUM SEMICOLON
#line 213 "grammar/syntax.y"
                                 {
  yylhs.value.as < EnumNode* > () = new EnumNode(ctx.line, yystack_[2].value.as < string > (), vector<string>());
}
#line 1855 "grammar/build/syntax.tab.cc"
    break;

  case 32: // enum_values: enum_values COMMA CONST_NAME
#line 217 "grammar/syntax.y"
                                          {
  yylhs.value.as < vector<string> > () = yystack_[2].value.as < vector<string> > ();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < string > ());
}
#line 1864 "grammar/build/syntax.tab.cc"
    break;

  case 33: // enum_values: CONST_NAME
#line 220 "grammar/syntax.y"
               {
  yylhs.value.as < vector<string> > () = vector<string>();
  yylhs.value.as < vector<string> > ().push_back(yystack_[0].value.as < string > ());
}
#line 1873 "grammar/build/syntax.tab.cc"
    break;

  case 34: // struct: STRUCT name struct_attrs END_STRUCT SEMICOLON
#line 225 "grammar/syntax.y"
                                                      {
  yylhs.value.as < StructNode* > () = new StructNode(ctx.line, yystack_[3].value.as < string > (), yystack_[2].value.as < vector<pair<string, Type>> > ());
}
#line 1881 "grammar/build/syntax.tab.cc"
    break;

  case 35: // struct: STRUCT name END_STRUCT SEMICOLON
#line 227 "grammar/syntax.y"
                                     {
  yylhs.value.as < StructNode* > () = new StructNode(ctx.line, yystack_[2].value.as < string > (), vector<pair<string, Type>>());
}
#line 1889 "grammar/build/syntax.tab.cc"
    break;

  case 36: // struct_attrs: struct_attrs struct_attr SEMICOLON
#line 231 "grammar/syntax.y"
                                                 {
  yylhs.value.as < vector<pair<string, Type>> > () = yystack_[2].value.as < vector<pair<string, Type>> > ();
  for (size_t i = 0; i < yystack_[1].value.as < vector<pair<string, Type>> > ().size(); i++) {
    yylhs.value.as < vector<pair<string, Type>> > ().push_back(yystack_[1].value.as < vector<pair<string, Type>> > ()[i]);
  };
}
#line 1900 "grammar/build/syntax.tab.cc"
    break;

  case 37: // struct_attrs: struct_attr SEMICOLON
#line 236 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<pair<string, Type>> > () = yystack_[1].value.as < vector<pair<string, Type>> > ();
}
#line 1908 "grammar/build/syntax.tab.cc"
    break;

  case 38: // struct_attr: id_list COLON type
#line 240 "grammar/syntax.y"
                                {
  yylhs.value.as < vector<pair<string, Type>> > () = vector<pair<string, Type>>();
  for (size_t i = 0; i < yystack_[2].value.as < vector<string> > ().size(); i++) {
    yylhs.value.as < vector<pair<string, Type>> > ().push_back({yystack_[2].value.as < vector<string> > ()[i], *yystack_[0].value.as < Type* > ()});
  };
}
#line 1919 "grammar/build/syntax.tab.cc"
    break;

  case 39: // trait: TRAIT name trait_subprograms END_TRAIT SEMICOLON
#line 247 "grammar/syntax.y"
                                                        {
  yylhs.value.as < TraitNode* > () = new TraitNode(ctx.line, yystack_[3].value.as < string > (), yystack_[2].value.as < vector<SubprogramNode*> > ());
}
#line 1927 "grammar/build/syntax.tab.cc"
    break;

  case 40: // trait: TRAIT name END_TRAIT SEMICOLON
#line 249 "grammar/syntax.y"
                                   {
  yylhs.value.as < TraitNode* > () = new TraitNode(ctx.line, yystack_[2].value.as < string > (), vector<SubprogramNode*>());
}
#line 1935 "grammar/build/syntax.tab.cc"
    break;

  case 41: // trait_subprograms: trait_subprograms trait_subprogram
#line 253 "grammar/syntax.y"
                                                      {
  yylhs.value.as < vector<SubprogramNode*> > () = yystack_[1].value.as < vector<SubprogramNode*> > ();
  yylhs.value.as < vector<SubprogramNode*> > ().push_back(yystack_[0].value.as < SubprogramNode* > ());
}
#line 1944 "grammar/build/syntax.tab.cc"
    break;

  case 42: // trait_subprograms: trait_subprogram
#line 256 "grammar/syntax.y"
                     {
  yylhs.value.as < vector<SubprogramNode*> > () = vector<SubprogramNode*>();
  yylhs.value.as < vector<SubprogramNode*> > ().push_back(yystack_[0].value.as < SubprogramNode* > ());
}
#line 1953 "grammar/build/syntax.tab.cc"
    break;

  case 43: // trait_subprogram: trait_fn
#line 261 "grammar/syntax.y"
                           {
  yylhs.value.as < SubprogramNode* > () = yystack_[0].value.as < FunctionNode* > ();
}
#line 1961 "grammar/build/syntax.tab.cc"
    break;

  case 44: // trait_subprogram: trait_proc
#line 263 "grammar/syntax.y"
               {
  yylhs.value.as < SubprogramNode* > () = yystack_[0].value.as < ProcedureNode* > ();
}
#line 1969 "grammar/build/syntax.tab.cc"
    break;

  case 45: // trait_fn: FUNCTION ID params_self_list COLON type SEMICOLON
#line 267 "grammar/syntax.y"
                                                            {
  yylhs.value.as < FunctionNode* > () = new FunctionNode(ctx.line, yystack_[4].value.as < string > (), *yystack_[1].value.as < Type* > (), yystack_[3].value.as < vector<pair<string, Type>> > (), true);
}
#line 1977 "grammar/build/syntax.tab.cc"
    break;

  case 46: // trait_fn: FUNCTION ID params_list COLON type SEMICOLON
#line 269 "grammar/syntax.y"
                                                 {
  yylhs.value.as < FunctionNode* > () = new FunctionNode(ctx.line, yystack_[4].value.as < string > (), *yystack_[1].value.as < Type* > (), yystack_[3].value.as < vector<pair<string, Type>> > ());
}
#line 1985 "grammar/build/syntax.tab.cc"
    break;

  case 47: // trait_proc: PROCEDURE ID params_self_list SEMICOLON
#line 273 "grammar/syntax.y"
                                                    {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[2].value.as < string > (), yystack_[1].value.as < vector<pair<string, Type>> > (), true);
}
#line 1993 "grammar/build/syntax.tab.cc"
    break;

  case 48: // trait_proc: PROCEDURE ID params_list SEMICOLON
#line 275 "grammar/syntax.y"
                                       {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[2].value.as < string > (), yystack_[1].value.as < vector<pair<string, Type>> > ());
}
#line 2001 "grammar/build/syntax.tab.cc"
    break;

  case 49: // impl: IMPL name impl_subprograms END_IMPL SEMICOLON
#line 279 "grammar/syntax.y"
                                                    {
  yylhs.value.as < ImplNode* > () = new ImplNode(ctx.line, yystack_[3].value.as < string > (), yystack_[2].value.as < vector<SubprogramNode*> > ());
}
#line 2009 "grammar/build/syntax.tab.cc"
    break;

  case 50: // impl: IMPL name END_IMPL SEMICOLON
#line 281 "grammar/syntax.y"
                                 {
  yylhs.value.as < ImplNode* > () = new ImplNode(ctx.line, yystack_[2].value.as < string > (), vector<SubprogramNode*>());
}
#line 2017 "grammar/build/syntax.tab.cc"
    break;

  case 51: // impl: IMPL name FOR name impl_subprograms END_IMPL SEMICOLON
#line 283 "grammar/syntax.y"
                                                           {
  yylhs.value.as < ImplNode* > () = new ImplNode(ctx.line, yystack_[5].value.as < string > (), yystack_[3].value.as < string > (), yystack_[2].value.as < vector<SubprogramNode*> > ());
}
#line 2025 "grammar/build/syntax.tab.cc"
    break;

  case 52: // impl: IMPL name FOR name END_IMPL SEMICOLON
#line 285 "grammar/syntax.y"
                                          {
  yylhs.value.as < ImplNode* > () = new ImplNode(ctx.line, yystack_[4].value.as < string > (), yystack_[2].value.as < string > (), vector<SubprogramNode*>());
}
#line 2033 "grammar/build/syntax.tab.cc"
    break;

  case 53: // impl_subprograms: impl_subprograms impl_subprogram
#line 289 "grammar/syntax.y"
                                                   {
  yylhs.value.as < vector<SubprogramNode*> > () = yystack_[1].value.as < vector<SubprogramNode*> > ();
  yylhs.value.as < vector<SubprogramNode*> > ().push_back(yystack_[0].value.as < SubprogramNode* > ());
}
#line 2042 "grammar/build/syntax.tab.cc"
    break;

  case 54: // impl_subprograms: impl_subprogram
#line 292 "grammar/syntax.y"
                    {
  yylhs.value.as < vector<SubprogramNode*> > () = vector<SubprogramNode*>();
  yylhs.value.as < vector<SubprogramNode*> > ().push_back(yystack_[0].value.as < SubprogramNode* > ());
}
#line 2051 "grammar/build/syntax.tab.cc"
    break;

  case 55: // impl_subprogram: impl_fn
#line 297 "grammar/syntax.y"
                         {
  yylhs.value.as < SubprogramNode* > () = yystack_[0].value.as < FunctionNode* > ();
}
#line 2059 "grammar/build/syntax.tab.cc"
    break;

  case 56: // impl_subprogram: impl_proc
#line 299 "grammar/syntax.y"
              {
  yylhs.value.as < SubprogramNode* > () = yystack_[0].value.as < ProcedureNode* > ();
}
#line 2067 "grammar/build/syntax.tab.cc"
    break;

  case 57: // impl_fn: FUNCTION ID params_self_list COLON type stmts END_FUNCTION SEMICOLON
#line 303 "grammar/syntax.y"
                                                                              {
  yylhs.value.as < FunctionNode* > () = new FunctionNode(ctx.line, yystack_[6].value.as < string > (), *yystack_[3].value.as < Type* > (), yystack_[5].value.as < vector<pair<string, Type>> > (), true);
  for (size_t i = 0; i < yystack_[2].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < FunctionNode* > ()->children.push_back(yystack_[2].value.as < vector<Node*> > ()[i]);
  };
}
#line 2078 "grammar/build/syntax.tab.cc"
    break;

  case 58: // impl_fn: fn
#line 308 "grammar/syntax.y"
       {
  yylhs.value.as < FunctionNode* > () = yystack_[0].value.as < FunctionNode* > ();
}
#line 2086 "grammar/build/syntax.tab.cc"
    break;

  case 59: // impl_proc: PROCEDURE ID params_self_list stmts END_PROCEDURE SEMICOLON
#line 312 "grammar/syntax.y"
                                                                       {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[4].value.as < string > (), yystack_[3].value.as < vector<pair<string, Type>> > (), true);
  for (size_t i = 0; i < yystack_[2].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < ProcedureNode* > ()->children.push_back(yystack_[2].value.as < vector<Node*> > ()[i]);
  };
}
#line 2097 "grammar/build/syntax.tab.cc"
    break;

  case 60: // impl_proc: PROCEDURE ID params_self_list END_PROCEDURE SEMICOLON
#line 317 "grammar/syntax.y"
                                                          {
  yylhs.value.as < ProcedureNode* > () = new ProcedureNode(ctx.line, yystack_[3].value.as < string > (), yystack_[2].value.as < vector<pair<string, Type>> > (), true);
}
#line 2105 "grammar/build/syntax.tab.cc"
    break;

  case 61: // impl_proc: proc
#line 319 "grammar/syntax.y"
         {
  yylhs.value.as < ProcedureNode* > () = yystack_[0].value.as < ProcedureNode* > ();
}
#line 2113 "grammar/build/syntax.tab.cc"
    break;

  case 62: // access: access DOT CONST_NAME
#line 323 "grammar/syntax.y"
                              {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < string > (), yystack_[2].value.as < AccessNode* > (), AccessType::DOT);
}
#line 2121 "grammar/build/syntax.tab.cc"
    break;

  case 63: // access: access DOT ID
#line 325 "grammar/syntax.y"
                  {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < string > (), yystack_[2].value.as < AccessNode* > (), AccessType::DOT);
}
#line 2129 "grammar/build/syntax.tab.cc"
    break;

  case 64: // access: access LEFT_BRACKET expr RIGHT_BRACKET
#line 327 "grammar/syntax.y"
                                           {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[3].value.as < AccessNode* > (), yystack_[1].value.as < ExpressionNode* > ());
}
#line 2137 "grammar/build/syntax.tab.cc"
    break;

  case 65: // access: access DOUBLE_COLON ID
#line 329 "grammar/syntax.y"
                           {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < string > (), yystack_[2].value.as < AccessNode* > (), AccessType::STATIC);
}
#line 2145 "grammar/build/syntax.tab.cc"
    break;

  case 66: // access: subprogram_call
#line 331 "grammar/syntax.y"
                    {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < SubprogramCallNode* > ());
}
#line 2153 "grammar/build/syntax.tab.cc"
    break;

  case 67: // access: access_base
#line 333 "grammar/syntax.y"
                {
  yylhs.value.as < AccessNode* > () = new AccessNode(ctx.line, yystack_[0].value.as < AccessBaseNode* > ());
}
#line 2161 "grammar/build/syntax.tab.cc"
    break;

  case 68: // access_base: SELF
#line 337 "grammar/syntax.y"
                  {
  yylhs.value.as < AccessBaseNode* > () = new AccessBaseNode(ctx.line);
}
#line 2169 "grammar/build/syntax.tab.cc"
    break;

  case 69: // access_base: id
#line 339 "grammar/syntax.y"
       {
  yylhs.value.as < AccessBaseNode* > () = new AccessBaseNode(ctx.line, yystack_[0].value.as < string > ());
}
#line 2177 "grammar/build/syntax.tab.cc"
    break;

  case 70: // access_base: LEFT_PAREN expr RIGHT_PAREN
#line 341 "grammar/syntax.y"
                                {
  yylhs.value.as < AccessBaseNode* > () = new AccessBaseNode(ctx.line, yystack_[1].value.as < ExpressionNode* > ());
}
#line 2185 "grammar/build/syntax.tab.cc"
    break;

  case 71: // id: NAME
#line 345 "grammar/syntax.y"
         {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 2193 "grammar/build/syntax.tab.cc"
    break;

  case 72: // id: ID
#line 347 "grammar/syntax.y"
       {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 2201 "grammar/build/syntax.tab.cc"
    break;

  case 73: // name: NAME
#line 351 "grammar/syntax.y"
           {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 2209 "grammar/build/syntax.tab.cc"
    break;

  case 74: // name: CONST_NAME
#line 353 "grammar/syntax.y"
               {
  yylhs.value.as < string > () = yystack_[0].value.as < string > ();
}
#line 2217 "grammar/build/syntax.tab.cc"
    break;

  case 75: // stmts: stmts stmt SEMICOLON
#line 357 "grammar/syntax.y"
                            {
  yylhs.value.as < vector<Node*> > () = yystack_[2].value.as < vector<Node*> > ();
  yylhs.value.as < vector<Node*> > ().push_back(yystack_[1].value.as < Node* > ());
}
#line 2226 "grammar/build/syntax.tab.cc"
    break;

  case 76: // stmts: stmt SEMICOLON
#line 360 "grammar/syntax.y"
                   {
  yylhs.value.as < vector<Node*> > () = vector<Node*>();
  yylhs.value.as < vector<Node*> > ().push_back(yystack_[1].value.as < Node* > ());
}
#line 2235 "grammar/build/syntax.tab.cc"
    break;

  case 77: // stmt: BREAK
#line 365 "grammar/syntax.y"
            {
  yylhs.value.as < Node* > () = new BreakNode(ctx.line);
}
#line 2243 "grammar/build/syntax.tab.cc"
    break;

  case 78: // stmt: CONTINUE
#line 367 "grammar/syntax.y"
             {
  yylhs.value.as < Node* > () = new ContinueNode(ctx.line);
}
#line 2251 "grammar/build/syntax.tab.cc"
    break;

  case 79: // stmt: attr
#line 369 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < AttrNode* > ();
}
#line 2259 "grammar/build/syntax.tab.cc"
    break;

  case 80: // stmt: assign
#line 371 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < AssignNode* > ();
}
#line 2267 "grammar/build/syntax.tab.cc"
    break;

  case 81: // stmt: return
#line 373 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ReturnNode* > ();
}
#line 2275 "grammar/build/syntax.tab.cc"
    break;

  case 82: // stmt: if
#line 375 "grammar/syntax.y"
       {
  yylhs.value.as < Node* > () = yystack_[0].value.as < IfNode* > ();
}
#line 2283 "grammar/build/syntax.tab.cc"
    break;

  case 83: // stmt: for
#line 377 "grammar/syntax.y"
        {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ForNode* > ();
}
#line 2291 "grammar/build/syntax.tab.cc"
    break;

  case 84: // stmt: while
#line 379 "grammar/syntax.y"
          {
  yylhs.value.as < Node* > () = yystack_[0].value.as < WhileNode* > ();
}
#line 2299 "grammar/build/syntax.tab.cc"
    break;

  case 85: // stmt: repeat
#line 381 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < WhileNode* > ();
}
#line 2307 "grammar/build/syntax.tab.cc"
    break;

  case 86: // stmt: switch
#line 383 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = yystack_[0].value.as < SwitchNode* > ();
}
#line 2315 "grammar/build/syntax.tab.cc"
    break;

  case 87: // stmt: expr
#line 385 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2323 "grammar/build/syntax.tab.cc"
    break;

  case 88: // return: RETURN expr
#line 389 "grammar/syntax.y"
                    {
  yylhs.value.as < ReturnNode* > () = new ReturnNode(ctx.line, yystack_[0].value.as < ExpressionNode* > ());
}
#line 2331 "grammar/build/syntax.tab.cc"
    break;

  case 89: // attr: VAR ID COLON type ATTR expr
#line 393 "grammar/syntax.y"
                                  {
  yylhs.value.as < AttrNode* > () = new AttrNode(ctx.line, yystack_[4].value.as < string > (), false, *yystack_[2].value.as < Type* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2339 "grammar/build/syntax.tab.cc"
    break;

  case 90: // attr: CONST ID COLON type ATTR expr
#line 395 "grammar/syntax.y"
                                  {
  yylhs.value.as < AttrNode* > () = new AttrNode(ctx.line, yystack_[4].value.as < string > (), true, *yystack_[2].value.as < Type* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2347 "grammar/build/syntax.tab.cc"
    break;

  case 91: // basic_type: TYPE_INT
#line 399 "grammar/syntax.y"
                     {
  yylhs.value.as < Type* > () = new Type(TypeKind::INT);
}
#line 2355 "grammar/build/syntax.tab.cc"
    break;

  case 92: // basic_type: TYPE_FLOAT
#line 401 "grammar/syntax.y"
               {
  yylhs.value.as < Type* > () = new Type(TypeKind::FLOAT);
}
#line 2363 "grammar/build/syntax.tab.cc"
    break;

  case 93: // basic_type: TYPE_DOUBLE
#line 403 "grammar/syntax.y"
                {
  yylhs.value.as < Type* > () = new Type(TypeKind::DOUBLE);
}
#line 2371 "grammar/build/syntax.tab.cc"
    break;

  case 94: // basic_type: TYPE_LONG
#line 405 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::LONG);
}
#line 2379 "grammar/build/syntax.tab.cc"
    break;

  case 95: // basic_type: TYPE_BYTE
#line 407 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::BYTE);
}
#line 2387 "grammar/build/syntax.tab.cc"
    break;

  case 96: // basic_type: TYPE_STRING
#line 409 "grammar/syntax.y"
                {
  yylhs.value.as < Type* > () = new Type(TypeKind::STRING);
}
#line 2395 "grammar/build/syntax.tab.cc"
    break;

  case 97: // basic_type: TYPE_CHAR
#line 411 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::CHAR);
}
#line 2403 "grammar/build/syntax.tab.cc"
    break;

  case 98: // basic_type: TYPE_BOOL
#line 413 "grammar/syntax.y"
              {
  yylhs.value.as < Type* > () = new Type(TypeKind::BOOL);
}
#line 2411 "grammar/build/syntax.tab.cc"
    break;

  case 99: // type: basic_type
#line 417 "grammar/syntax.y"
                 {
  yylhs.value.as < Type* > () = yystack_[0].value.as < Type* > ();
}
#line 2419 "grammar/build/syntax.tab.cc"
    break;

  case 100: // type: type LEFT_BRACKET RIGHT_BRACKET
#line 419 "grammar/syntax.y"
                                    {
  yylhs.value.as < Type* > () = new Type(TypeKind::ARRAY, yystack_[2].value.as < Type* > ());
}
#line 2427 "grammar/build/syntax.tab.cc"
    break;

  case 101: // type: TYPE_POINTER LT type GT
#line 421 "grammar/syntax.y"
                            {
  yylhs.value.as < Type* > () = new Type(TypeKind::POINTER, yystack_[1].value.as < Type* > ());
}
#line 2435 "grammar/build/syntax.tab.cc"
    break;

  case 102: // type: TYPE_OPTION LT type GT
#line 423 "grammar/syntax.y"
                           {
  yylhs.value.as < Type* > () = new Type(TypeKind::OPTION, yystack_[1].value.as < Type* > ());
}
#line 2443 "grammar/build/syntax.tab.cc"
    break;

  case 103: // type: name
#line 425 "grammar/syntax.y"
         {
  yylhs.value.as < Type* > () = new Type(TypeKind::NAMED, yystack_[0].value.as < string > ());
}
#line 2451 "grammar/build/syntax.tab.cc"
    break;

  case 104: // assign: access ATTR expr
#line 429 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2459 "grammar/build/syntax.tab.cc"
    break;

  case 105: // assign: access AND_ATTR expr
#line 431 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::AND, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2467 "grammar/build/syntax.tab.cc"
    break;

  case 106: // assign: access OR_ATTR expr
#line 433 "grammar/syntax.y"
                        {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::OR, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2475 "grammar/build/syntax.tab.cc"
    break;

  case 107: // assign: access LAZY_AND_ATTR expr
#line 435 "grammar/syntax.y"
                              {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::BITWISE_AND, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2483 "grammar/build/syntax.tab.cc"
    break;

  case 108: // assign: access LAZY_OR_ATTR expr
#line 437 "grammar/syntax.y"
                             {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::BITWISE_OR, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2491 "grammar/build/syntax.tab.cc"
    break;

  case 109: // assign: access XOR_ATTR expr
#line 439 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::XOR, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2499 "grammar/build/syntax.tab.cc"
    break;

  case 110: // assign: access CONCAT_ATTR expr
#line 441 "grammar/syntax.y"
                            {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::CONCAT, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2507 "grammar/build/syntax.tab.cc"
    break;

  case 111: // assign: access MOD_ATTR expr
#line 443 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::MOD, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2515 "grammar/build/syntax.tab.cc"
    break;

  case 112: // assign: access PLUS_ATTR expr
#line 445 "grammar/syntax.y"
                          {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::PLUS, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2523 "grammar/build/syntax.tab.cc"
    break;

  case 113: // assign: access MINUS_ATTR expr
#line 447 "grammar/syntax.y"
                           {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::MINUS, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2531 "grammar/build/syntax.tab.cc"
    break;

  case 114: // assign: access MULT_ATTR expr
#line 449 "grammar/syntax.y"
                          {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::MULT, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2539 "grammar/build/syntax.tab.cc"
    break;

  case 115: // assign: access DIV_ATTR expr
#line 451 "grammar/syntax.y"
                         {
  yylhs.value.as < AssignNode* > () = new AssignNode(ctx.line, BinaryOperation::DIV, yystack_[2].value.as < AccessNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2547 "grammar/build/syntax.tab.cc"
    break;

  case 116: // if: IF expr THEN stmts if_end
#line 455 "grammar/syntax.y"
                              {
  yylhs.value.as < IfNode* > () = new IfNode(ctx.line, yystack_[3].value.as < ExpressionNode* > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2558 "grammar/build/syntax.tab.cc"
    break;

  case 117: // if: IF SOME ID IN access THEN stmts if_end
#line 460 "grammar/syntax.y"
                                           {
  yylhs.value.as < IfNode* > () = new IfNode(ctx.line, yystack_[3].value.as < AccessNode* > (), yystack_[5].value.as < string > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2569 "grammar/build/syntax.tab.cc"
    break;

  case 118: // if_end: ELIF expr THEN stmts if_end
#line 467 "grammar/syntax.y"
                                    {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line, yystack_[3].value.as < ExpressionNode* > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfEndNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2580 "grammar/build/syntax.tab.cc"
    break;

  case 119: // if_end: ELIF SOME ID IN access THEN stmts if_end
#line 472 "grammar/syntax.y"
                                             {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line, yystack_[3].value.as < AccessNode* > (), yystack_[5].value.as < string > (), yystack_[0].value.as < IfEndNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfEndNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2591 "grammar/build/syntax.tab.cc"
    break;

  case 120: // if_end: ELSE stmts END_IF
#line 477 "grammar/syntax.y"
                      {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line, new IfEndNode(ctx.line));
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < IfEndNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2602 "grammar/build/syntax.tab.cc"
    break;

  case 121: // if_end: END_IF
#line 482 "grammar/syntax.y"
           {
  yylhs.value.as < IfEndNode* > () = new IfEndNode(ctx.line);
}
#line 2610 "grammar/build/syntax.tab.cc"
    break;

  case 122: // switch: SWITCH expr cases END_SWITCH
#line 486 "grammar/syntax.y"
                                     {
  yylhs.value.as < SwitchNode* > () = new SwitchNode(ctx.line, yystack_[2].value.as < ExpressionNode* > (), yystack_[1].value.as < vector<CaseNode*> > ());
}
#line 2618 "grammar/build/syntax.tab.cc"
    break;

  case 123: // cases: case_list default_case
#line 490 "grammar/syntax.y"
                              {
  yylhs.value.as < vector<CaseNode*> > () = yystack_[1].value.as < vector<CaseNode*> > ();
  yylhs.value.as < vector<CaseNode*> > ().push_back(yystack_[0].value.as < CaseNode* > ());
}
#line 2627 "grammar/build/syntax.tab.cc"
    break;

  case 124: // cases: default_case
#line 493 "grammar/syntax.y"
                 {
  yylhs.value.as < vector<CaseNode*> > () = vector<CaseNode*>();
  yylhs.value.as < vector<CaseNode*> > ().push_back(yystack_[0].value.as < CaseNode* > ());
}
#line 2636 "grammar/build/syntax.tab.cc"
    break;

  case 125: // case_list: case_list case
#line 498 "grammar/syntax.y"
                          {
  yylhs.value.as < vector<CaseNode*> > () = yystack_[1].value.as < vector<CaseNode*> > ();
  yylhs.value.as < vector<CaseNode*> > ().push_back(yystack_[0].value.as < CaseNode* > ());
}
#line 2645 "grammar/build/syntax.tab.cc"
    break;

  case 126: // case_list: case
#line 501 "grammar/syntax.y"
         {
  yylhs.value.as < vector<CaseNode*> > () = vector<CaseNode*>();
  yylhs.value.as < vector<CaseNode*> > ().push_back(yystack_[0].value.as < CaseNode* > ());
}
#line 2654 "grammar/build/syntax.tab.cc"
    break;

  case 127: // case: CASE case_values COLON stmts
#line 506 "grammar/syntax.y"
                                   {
  yylhs.value.as < CaseNode* > () = new CaseNode(ctx.line, yystack_[2].value.as < vector<ExpressionNode*> > ());
  for (size_t i = 0; i < yystack_[0].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < CaseNode* > ()->children.push_back(yystack_[0].value.as < vector<Node*> > ()[i]);
  };
}
#line 2665 "grammar/build/syntax.tab.cc"
    break;

  case 128: // case_values: case_values COMMA term
#line 513 "grammar/syntax.y"
                                    {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[2].value.as < vector<ExpressionNode*> > ();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 2674 "grammar/build/syntax.tab.cc"
    break;

  case 129: // case_values: term
#line 516 "grammar/syntax.y"
         {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 2683 "grammar/build/syntax.tab.cc"
    break;

  case 130: // default_case: DEFAULT COLON stmts
#line 521 "grammar/syntax.y"
                                  {
  yylhs.value.as < CaseNode* > () = new CaseNode(ctx.line);
  for (size_t i = 0; i < yystack_[0].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < CaseNode* > ()->children.push_back(yystack_[0].value.as < vector<Node*> > ()[i]);
  };
}
#line 2694 "grammar/build/syntax.tab.cc"
    break;

  case 131: // for: FOR LEFT_PAREN ID IN expr RIGHT_PAREN stmts END_FOR
#line 528 "grammar/syntax.y"
                                                         {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[5].value.as < string > (), yystack_[3].value.as < ExpressionNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < ForNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2705 "grammar/build/syntax.tab.cc"
    break;

  case 132: // for: FOR LEFT_PAREN ID IN expr RIGHT_PAREN END_FOR
#line 533 "grammar/syntax.y"
                                                  {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[4].value.as < string > (), yystack_[2].value.as < ExpressionNode* > ());
}
#line 2713 "grammar/build/syntax.tab.cc"
    break;

  case 133: // for: FOR LEFT_PAREN attr SEMICOLON expr SEMICOLON expr RIGHT_PAREN stmts END_FOR
#line 535 "grammar/syntax.y"
                                                                                {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[7].value.as < AttrNode* > (), yystack_[5].value.as < ExpressionNode* > (), yystack_[3].value.as < ExpressionNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < ForNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2724 "grammar/build/syntax.tab.cc"
    break;

  case 134: // for: FOR LEFT_PAREN attr SEMICOLON expr SEMICOLON expr RIGHT_PAREN END_FOR
#line 540 "grammar/syntax.y"
                                                                          {
  yylhs.value.as < ForNode* > () = new ForNode(ctx.line, yystack_[6].value.as < AttrNode* > (), yystack_[4].value.as < ExpressionNode* > (), yystack_[2].value.as < ExpressionNode* > ());
}
#line 2732 "grammar/build/syntax.tab.cc"
    break;

  case 135: // while: WHILE LEFT_PAREN expr RIGHT_PAREN stmts END_WHILE
#line 544 "grammar/syntax.y"
                                                         {
  yylhs.value.as < WhileNode* > () = new WhileNode(ctx.line, yystack_[3].value.as < ExpressionNode* > (), WhileType::WHILE);
  for (size_t i = 0; i < yystack_[1].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < WhileNode* > ()->children.push_back(yystack_[1].value.as < vector<Node*> > ()[i]);
  };
}
#line 2743 "grammar/build/syntax.tab.cc"
    break;

  case 136: // while: WHILE LEFT_PAREN expr RIGHT_PAREN END_WHILE
#line 549 "grammar/syntax.y"
                                                {
  yylhs.value.as < WhileNode* > () = new WhileNode(ctx.line, yystack_[2].value.as < ExpressionNode* > (), WhileType::WHILE);
}
#line 2751 "grammar/build/syntax.tab.cc"
    break;

  case 137: // repeat: REPEAT stmts UNTIL expr
#line 553 "grammar/syntax.y"
                                {
  yylhs.value.as < WhileNode* > () = new WhileNode(ctx.line, yystack_[0].value.as < ExpressionNode* > (), WhileType::REPEAT);
  for (size_t i = 0; i < yystack_[2].value.as < vector<Node*> > ().size(); i++) {
    yylhs.value.as < WhileNode* > ()->children.push_back(yystack_[2].value.as < vector<Node*> > ()[i]);
  };
}
#line 2762 "grammar/build/syntax.tab.cc"
    break;

  case 138: // repeat: REPEAT UNTIL expr
#line 558 "grammar/syntax.y"
                      {
  yylhs.value.as < WhileNode* > () = new WhileNode(ctx.line, yystack_[0].value.as < ExpressionNode* > (), WhileType::REPEAT);
}
#line 2770 "grammar/build/syntax.tab.cc"
    break;

  case 139: // expr: or_expr
#line 562 "grammar/syntax.y"
              {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2778 "grammar/build/syntax.tab.cc"
    break;

  case 140: // expr: range_expr
#line 564 "grammar/syntax.y"
               {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < RangeNode* > ();
}
#line 2786 "grammar/build/syntax.tab.cc"
    break;

  case 141: // range_expr: range_interval or_expr
#line 568 "grammar/syntax.y"
                                   {
  yylhs.value.as < RangeNode* > () = new RangeNode(ctx.line, false, yystack_[0].value.as < ExpressionNode* > (), yystack_[1].value.as < pair<RangeInclusionType, RangeInclusionType> > ().second);
}
#line 2794 "grammar/build/syntax.tab.cc"
    break;

  case 142: // range_expr: or_expr range_interval
#line 570 "grammar/syntax.y"
                           {
  yylhs.value.as < RangeNode* > () = new RangeNode(ctx.line, true, yystack_[1].value.as < ExpressionNode* > (), yystack_[0].value.as < pair<RangeInclusionType, RangeInclusionType> > ().first);
}
#line 2802 "grammar/build/syntax.tab.cc"
    break;

  case 143: // range_expr: or_expr range_interval or_expr
#line 572 "grammar/syntax.y"
                                   {
  yylhs.value.as < RangeNode* > () = new RangeNode(ctx.line, yystack_[2].value.as < ExpressionNode* > (), yystack_[1].value.as < pair<RangeInclusionType, RangeInclusionType> > ().first, yystack_[0].value.as < ExpressionNode* > (), yystack_[1].value.as < pair<RangeInclusionType, RangeInclusionType> > ().second);
}
#line 2810 "grammar/build/syntax.tab.cc"
    break;

  case 144: // range_interval: RANGE
#line 576 "grammar/syntax.y"
                      {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::INCLUSIVE, RangeInclusionType::EXCLUSIVE};
}
#line 2818 "grammar/build/syntax.tab.cc"
    break;

  case 145: // range_interval: RANGE_EXC
#line 578 "grammar/syntax.y"
              {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::EXCLUSIVE, RangeInclusionType::EXCLUSIVE};
}
#line 2826 "grammar/build/syntax.tab.cc"
    break;

  case 146: // range_interval: RANGE_EXC_INC
#line 580 "grammar/syntax.y"
                  {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::EXCLUSIVE, RangeInclusionType::INCLUSIVE};
}
#line 2834 "grammar/build/syntax.tab.cc"
    break;

  case 147: // range_interval: RANGE_INC
#line 582 "grammar/syntax.y"
              {
  yylhs.value.as < pair<RangeInclusionType, RangeInclusionType> > () = {RangeInclusionType::INCLUSIVE, RangeInclusionType::INCLUSIVE};
}
#line 2842 "grammar/build/syntax.tab.cc"
    break;

  case 148: // or_expr: or_expr OR and_expr
#line 586 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::OR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2850 "grammar/build/syntax.tab.cc"
    break;

  case 149: // or_expr: and_expr
#line 588 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2858 "grammar/build/syntax.tab.cc"
    break;

  case 150: // and_expr: and_expr AND bit_or_expr
#line 592 "grammar/syntax.y"
                                   {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::AND, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2866 "grammar/build/syntax.tab.cc"
    break;

  case 151: // and_expr: bit_or_expr
#line 594 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2874 "grammar/build/syntax.tab.cc"
    break;

  case 152: // bit_or_expr: bit_or_expr BAR bit_xor_expr
#line 598 "grammar/syntax.y"
                                          {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::BITWISE_OR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2882 "grammar/build/syntax.tab.cc"
    break;

  case 153: // bit_or_expr: bit_xor_expr
#line 600 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2890 "grammar/build/syntax.tab.cc"
    break;

  case 154: // bit_xor_expr: bit_xor_expr XOR bit_and_expr
#line 604 "grammar/syntax.y"
                                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::XOR, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2898 "grammar/build/syntax.tab.cc"
    break;

  case 155: // bit_xor_expr: bit_and_expr
#line 606 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2906 "grammar/build/syntax.tab.cc"
    break;

  case 156: // bit_and_expr: bit_and_expr REF equals_expr
#line 610 "grammar/syntax.y"
                                           {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::BITWISE_AND, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2914 "grammar/build/syntax.tab.cc"
    break;

  case 157: // bit_and_expr: equals_expr
#line 612 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2922 "grammar/build/syntax.tab.cc"
    break;

  case 158: // equals_expr: equals_expr EQ rel_expr
#line 616 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2930 "grammar/build/syntax.tab.cc"
    break;

  case 159: // equals_expr: equals_expr NOT_EQ rel_expr
#line 618 "grammar/syntax.y"
                                {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::NOT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2938 "grammar/build/syntax.tab.cc"
    break;

  case 160: // equals_expr: rel_expr
#line 620 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2946 "grammar/build/syntax.tab.cc"
    break;

  case 161: // rel_expr: rel_expr LT concat_expr
#line 624 "grammar/syntax.y"
                                  {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::LT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2954 "grammar/build/syntax.tab.cc"
    break;

  case 162: // rel_expr: rel_expr GT concat_expr
#line 626 "grammar/syntax.y"
                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::GT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2962 "grammar/build/syntax.tab.cc"
    break;

  case 163: // rel_expr: rel_expr LT_EQ concat_expr
#line 628 "grammar/syntax.y"
                               {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::LT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2970 "grammar/build/syntax.tab.cc"
    break;

  case 164: // rel_expr: rel_expr GT_EQ concat_expr
#line 630 "grammar/syntax.y"
                               {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::GT_EQ, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2978 "grammar/build/syntax.tab.cc"
    break;

  case 165: // rel_expr: rel_expr IN concat_expr
#line 632 "grammar/syntax.y"
                            {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::IN, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 2986 "grammar/build/syntax.tab.cc"
    break;

  case 166: // rel_expr: concat_expr
#line 634 "grammar/syntax.y"
                {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 2994 "grammar/build/syntax.tab.cc"
    break;

  case 167: // concat_expr: concat_expr CONCAT sum_expr
#line 638 "grammar/syntax.y"
                                         {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::CONCAT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 3002 "grammar/build/syntax.tab.cc"
    break;

  case 168: // concat_expr: sum_expr
#line 640 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 3010 "grammar/build/syntax.tab.cc"
    break;

  case 169: // sum_expr: sum_expr PLUS mult_expr
#line 644 "grammar/syntax.y"
                                  {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::PLUS, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 3018 "grammar/build/syntax.tab.cc"
    break;

  case 170: // sum_expr: sum_expr MINUS mult_expr
#line 646 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MINUS, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 3026 "grammar/build/syntax.tab.cc"
    break;

  case 171: // sum_expr: mult_expr
#line 648 "grammar/syntax.y"
              {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 3034 "grammar/build/syntax.tab.cc"
    break;

  case 172: // mult_expr: mult_expr MULT unary_expr
#line 652 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MULT, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 3042 "grammar/build/syntax.tab.cc"
    break;

  case 173: // mult_expr: mult_expr DIV unary_expr
#line 654 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::DIV, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 3050 "grammar/build/syntax.tab.cc"
    break;

  case 174: // mult_expr: mult_expr MOD unary_expr
#line 656 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::MOD, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 3058 "grammar/build/syntax.tab.cc"
    break;

  case 175: // mult_expr: unary_expr
#line 658 "grammar/syntax.y"
               {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 3066 "grammar/build/syntax.tab.cc"
    break;

  case 176: // unary_expr: MINUS exp_expr
#line 662 "grammar/syntax.y"
                           {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::MINUS, yystack_[0].value.as < ExpressionNode* > ());
}
#line 3074 "grammar/build/syntax.tab.cc"
    break;

  case 177: // unary_expr: REV exp_expr
#line 664 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::REV, yystack_[0].value.as < ExpressionNode* > ());
}
#line 3082 "grammar/build/syntax.tab.cc"
    break;

  case 178: // unary_expr: NOT exp_expr
#line 666 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::NOT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 3090 "grammar/build/syntax.tab.cc"
    break;

  case 179: // unary_expr: REF exp_expr
#line 668 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::REF, yystack_[0].value.as < ExpressionNode* > ());
}
#line 3098 "grammar/build/syntax.tab.cc"
    break;

  case 180: // unary_expr: INCREMENT exp_expr
#line 670 "grammar/syntax.y"
                       {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::INCREMENT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 3106 "grammar/build/syntax.tab.cc"
    break;

  case 181: // unary_expr: DECREMENT exp_expr
#line 672 "grammar/syntax.y"
                       {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(UnaryOperation::DECREMENT, yystack_[0].value.as < ExpressionNode* > ());
}
#line 3114 "grammar/build/syntax.tab.cc"
    break;

  case 182: // unary_expr: MULT exp_expr
#line 674 "grammar/syntax.y"
                  {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 3122 "grammar/build/syntax.tab.cc"
    break;

  case 183: // unary_expr: exp_expr
#line 676 "grammar/syntax.y"
             {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 3130 "grammar/build/syntax.tab.cc"
    break;

  case 184: // exp_expr: postfix_expr EXP exp_expr
#line 680 "grammar/syntax.y"
                                    {
  yylhs.value.as < ExpressionNode* > () = new BinaryOperationNode(BinaryOperation::EXP, yystack_[2].value.as < ExpressionNode* > (), yystack_[0].value.as < ExpressionNode* > ());
}
#line 3138 "grammar/build/syntax.tab.cc"
    break;

  case 185: // exp_expr: postfix_expr
#line 682 "grammar/syntax.y"
                 {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 3146 "grammar/build/syntax.tab.cc"
    break;

  case 186: // postfix_expr: term INCREMENT
#line 686 "grammar/syntax.y"
                             {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(true, UnaryOperation::INCREMENT, yystack_[1].value.as < ExpressionNode* > ());
}
#line 3154 "grammar/build/syntax.tab.cc"
    break;

  case 187: // postfix_expr: term DECREMENT
#line 688 "grammar/syntax.y"
                   {
  yylhs.value.as < ExpressionNode* > () = new UnaryOperationNode(true, UnaryOperation::DECREMENT, yystack_[1].value.as < ExpressionNode* > ());
}
#line 3162 "grammar/build/syntax.tab.cc"
    break;

  case 188: // postfix_expr: term
#line 690 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ExpressionNode* > ();
}
#line 3170 "grammar/build/syntax.tab.cc"
    break;

  case 189: // term: INT
#line 694 "grammar/syntax.y"
          {
  yylhs.value.as < ExpressionNode* > () = new IntNode(ctx.line, yystack_[0].value.as < int32_t > ());
}
#line 3178 "grammar/build/syntax.tab.cc"
    break;

  case 190: // term: LONG
#line 696 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new LongNode(ctx.line, yystack_[0].value.as < int64_t > ());
}
#line 3186 "grammar/build/syntax.tab.cc"
    break;

  case 191: // term: FLOAT
#line 698 "grammar/syntax.y"
          {
  yylhs.value.as < ExpressionNode* > () = new FloatNode(ctx.line, yystack_[0].value.as < float > ());
}
#line 3194 "grammar/build/syntax.tab.cc"
    break;

  case 192: // term: DOUBLE
#line 700 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = new DoubleNode(ctx.line, yystack_[0].value.as < double > ());
}
#line 3202 "grammar/build/syntax.tab.cc"
    break;

  case 193: // term: BYTE
#line 702 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new ByteNode(ctx.line, yystack_[0].value.as < uint8_t > ());
}
#line 3210 "grammar/build/syntax.tab.cc"
    break;

  case 194: // term: BOOL
#line 704 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new BoolNode(ctx.line, yystack_[0].value.as < bool > ());
}
#line 3218 "grammar/build/syntax.tab.cc"
    break;

  case 195: // term: STRING
#line 706 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = new StringNode(ctx.line, yystack_[0].value.as < string > ());
}
#line 3226 "grammar/build/syntax.tab.cc"
    break;

  case 196: // term: CHAR
#line 708 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new CharNode(ctx.line, yystack_[0].value.as < char > ());
}
#line 3234 "grammar/build/syntax.tab.cc"
    break;

  case 197: // term: NONE
#line 710 "grammar/syntax.y"
         {
  yylhs.value.as < ExpressionNode* > () = new OptionNode(ctx.line, Option());
}
#line 3242 "grammar/build/syntax.tab.cc"
    break;

  case 198: // term: array_allocation
#line 712 "grammar/syntax.y"
                     {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < ArrayAllocationNode* > ();
}
#line 3250 "grammar/build/syntax.tab.cc"
    break;

  case 199: // term: struct_allocation
#line 714 "grammar/syntax.y"
                      {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < StructAllocationNode* > ();
}
#line 3258 "grammar/build/syntax.tab.cc"
    break;

  case 200: // term: access
#line 716 "grammar/syntax.y"
           {
  yylhs.value.as < ExpressionNode* > () = yystack_[0].value.as < AccessNode* > ();
}
#line 3266 "grammar/build/syntax.tab.cc"
    break;

  case 201: // term: SOME LEFT_PAREN expr RIGHT_PAREN
#line 718 "grammar/syntax.y"
                                     {
  yylhs.value.as < ExpressionNode* > () = new OptionNode(ctx.line, Option());
}
#line 3274 "grammar/build/syntax.tab.cc"
    break;

  case 202: // array_allocation: NEW type LEFT_BRACKET expr RIGHT_BRACKET
#line 722 "grammar/syntax.y"
                                                           {
  yylhs.value.as < ArrayAllocationNode* > () = new ArrayAllocationNode(ctx.line, *yystack_[3].value.as < Type* > (), yystack_[1].value.as < ExpressionNode* > ());
}
#line 3282 "grammar/build/syntax.tab.cc"
    break;

  case 203: // array_allocation: NEW type LEFT_BRACKET expr RIGHT_BRACKET LEFT_BRACE array_allocation_values RIGHT_BRACE
#line 724 "grammar/syntax.y"
                                                                                            {
  yylhs.value.as < ArrayAllocationNode* > () = new ArrayAllocationNode(ctx.line, *yystack_[6].value.as < Type* > (), yystack_[4].value.as < ExpressionNode* > ());
  for (size_t i = 0; i < yystack_[1].value.as < vector<ExpressionNode*> > ().size(); i++) {
    yylhs.value.as < ArrayAllocationNode* > ()->children.push_back(yystack_[1].value.as < vector<ExpressionNode*> > ()[i]);
  };
}
#line 3293 "grammar/build/syntax.tab.cc"
    break;

  case 204: // array_allocation_values: array_allocation_values COMMA expr
#line 731 "grammar/syntax.y"
                                                            {
  yylhs.value.as < vector<ExpressionNode*> > () = yystack_[2].value.as < vector<ExpressionNode*> > ();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 3302 "grammar/build/syntax.tab.cc"
    break;

  case 205: // array_allocation_values: expr
#line 734 "grammar/syntax.y"
         {
  yylhs.value.as < vector<ExpressionNode*> > () = vector<ExpressionNode*>();
  yylhs.value.as < vector<ExpressionNode*> > ().push_back(yystack_[0].value.as < ExpressionNode* > ());
}
#line 3311 "grammar/build/syntax.tab.cc"
    break;

  case 206: // struct_allocation: NEW name LEFT_BRACE struct_allocation_values RIGHT_BRACE
#line 739 "grammar/syntax.y"
                                                                            {
 yylhs.value.as < StructAllocationNode* > () = new StructAllocationNode(ctx.line, yystack_[3].value.as < string > (), yystack_[1].value.as < vector<pair<string, ExpressionNode*>> > ());
}
#line 3319 "grammar/build/syntax.tab.cc"
    break;

  case 207: // struct_allocation: NEW name LEFT_BRACE RIGHT_BRACE
#line 741 "grammar/syntax.y"
                                    {
  yylhs.value.as < StructAllocationNode* > () = new StructAllocationNode(ctx.line, yystack_[2].value.as < string > (), vector<pair<string, ExpressionNode*>>());
}
#line 3327 "grammar/build/syntax.tab.cc"
    break;

  case 208: // struct_allocation_values: struct_allocation_values COMMA ID COLON expr
#line 745 "grammar/syntax.y"
                                                                       {
  yylhs.value.as < vector<pair<string, ExpressionNode*>> > () = yystack_[4].value.as < vector<pair<string, ExpressionNode*>> > ();
  yylhs.value.as < vector<pair<string, ExpressionNode*>> > ().push_back({ yystack_[2].value.as < string > (), yystack_[0].value.as < ExpressionNode* > ()});
}
#line 3336 "grammar/build/syntax.tab.cc"
    break;

  case 209: // struct_allocation_values: ID COLON expr
#line 748 "grammar/syntax.y"
                  {
  yylhs.value.as < vector<pair<string, ExpressionNode*>> > () = vector<pair<string, ExpressionNode*>>();
  yylhs.value.as < vector<pair<string, ExpressionNode*>> > ().push_back({ yystack_[2].value.as < string > (), yystack_[0].value.as < ExpressionNode* > ()});
}
#line 3345 "grammar/build/syntax.tab.cc"
    break;


#line 3349 "grammar/build/syntax.tab.cc"

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








  const short parser::yypact_ninf_ = -285;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      89,    14,    66,   162,   162,   162,   162,    19,    89,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,    27,    27,  -285,
    -285,    -6,     1,   -41,    31,  -285,  -285,     5,    64,   510,
    -285,    86,   -45,  -285,   110,   174,    15,   117,   162,   132,
     139,   121,  -285,  -285,    -5,  -285,  -285,  -285,   186,   205,
     157,    32,  -285,  -285,  -285,  -285,    95,  -285,   177,   202,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  2736,  2736,
    2736,  2736,  2736,  2736,  2736,   202,   223,   241,  -285,  -285,
    -285,  -285,  2473,  2541,   184,   193,   617,  -285,  -285,  2473,
     195,  -285,   192,  -285,  2473,  -285,  2730,  -285,  -285,   724,
     204,  -285,  -285,   206,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  2677,    -2,   234,   232,   225,   236,    37,   -20,
     251,   194,   149,  -285,  -285,   256,   228,  -285,  -285,  -285,
     272,   218,  -285,   280,   202,   221,   222,  -285,    56,   226,
     226,  -285,   229,  -285,   226,   226,  -285,   231,  -285,   283,
    -285,   202,   247,   248,  -285,  -285,   831,    22,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,   227,   230,   237,   238,   239,
       7,   233,     9,  2473,  2473,   938,   169,  2473,  -285,  -285,
    2473,  2473,  2473,  2473,  2473,  2473,  2473,  2473,  2473,  2473,
    2473,  2473,   224,   298,  2329,  2473,  -285,   249,   250,  -285,
    -285,   276,  2677,  2677,  2677,  2677,  2677,  2677,  2677,  2677,
    2677,  2677,  2677,  2677,  2677,  2677,  2677,  2677,  2677,  2677,
    2677,  2736,  -285,  -285,  -285,  -285,  -285,   252,  -285,  -285,
     253,    72,    -8,   254,  1045,  -285,   258,   259,   260,   261,
    -285,  -285,   252,   202,   202,   262,  1152,     4,  2401,   202,
     202,  -285,   240,  2222,   243,   268,   267,  -285,  2473,  2736,
     264,   255,   169,  -285,  -285,   269,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,    53,  -285,   266,  -285,  -285,   234,   276,   232,
     225,   236,    37,   -20,   -20,   251,   251,   251,   251,   251,
     194,   149,   149,  -285,  -285,  -285,  -285,  -285,   273,   167,
     202,   274,  1259,   202,   202,  -285,  -285,     2,    10,  -285,
     277,   278,  -285,    59,   275,   -31,    17,    28,   403,  2473,
    2473,  1366,  -285,   191,  -285,  2222,  -285,  -285,  -285,  -285,
    2473,  -285,  -285,  -285,   283,  -285,   831,  -285,   281,   108,
     130,  -285,  -285,  -285,  2473,   314,  -285,   284,  2473,  2473,
      79,  -285,  2609,  2222,  -285,   270,   285,  -285,  1473,  2736,
    2222,  2222,  -285,   168,  1580,  -285,  -285,  -285,  -285,   290,
    2473,  -285,  -285,  2222,     8,   282,  1687,  1794,  2473,  -285,
    -285,  2222,  -285,   292,  2473,  -285,    60,   403,   286,  2222,
    -285,  -285,  1901,   291,  -285,  -285,  2473,  -285,  -285,    28,
     403,  -285,  2008,  -285,    93,  -285,  -285,  2115,  2222,  -285,
     403,  -285
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     2,     4,
       5,    10,    11,     6,     7,     8,     9,     0,     0,    73,
      74,     0,     0,     0,     0,     1,     3,     0,     0,     0,
      33,     0,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    61,     0,    54,    55,    56,     0,     0,
       0,     0,    42,    43,    44,    18,     0,    20,     0,     0,
     193,   189,   190,   191,   192,   194,    72,    71,   195,   196,
      95,    91,    94,    92,    93,    98,    96,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,   147,
     145,   146,     0,     0,     0,     0,     0,    77,    78,     0,
       0,   197,     0,    68,     0,    66,   200,    67,    69,     0,
       0,    81,    79,     0,    80,    82,    86,    83,    84,    85,
      87,   140,     0,   139,   149,   151,   153,   155,   157,   160,
     166,   168,   171,   175,   183,   185,   188,   198,   199,    31,
       0,     0,    35,     0,     0,     0,     0,    37,     0,     0,
       0,    50,     0,    53,     0,     0,    40,     0,    41,     0,
      17,     0,     0,     0,   103,    99,     0,   200,   181,   180,
     179,   178,   177,   176,   182,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,     0,     0,    76,
      25,   141,     0,   142,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,   186,    32,    30,    22,    38,    34,    36,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
      39,    19,    21,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,     0,     0,     0,     0,   138,     0,     0,
       0,     0,     0,   126,   124,     0,   105,   106,   107,   108,
     111,   109,   112,   110,   113,   114,   115,   104,    63,    62,
      65,    27,     0,    29,     0,    13,    75,   148,   143,   150,
     152,   154,   156,   158,   159,   163,   164,   161,   162,   165,
     167,   170,   169,   174,   172,   173,   184,    52,     0,     0,
       0,     0,     0,     0,     0,    47,    48,     0,     0,   100,
       0,     0,   207,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,     0,   129,     0,   122,   125,   123,   201,
       0,    26,    64,    51,     0,    16,     0,    60,     0,     0,
       0,   101,   102,    12,     0,     0,   206,   202,     0,     0,
       0,   121,     0,     0,   116,     0,     0,   136,     0,     0,
       0,   130,    28,     0,     0,    59,    45,    46,   209,     0,
       0,    89,    90,     0,     0,     0,     0,     0,     0,   135,
     128,   127,    15,     0,     0,   205,     0,     0,     0,     0,
     120,   132,     0,     0,    57,   208,     0,   203,   117,     0,
       0,   131,     0,   204,     0,   118,   134,     0,     0,   133,
       0,   119
  };

  const short
  parser::yypgoto_[] =
  {
    -285,  -285,  -285,   355,  -285,   145,   159,    38,   -12,    11,
     207,    49,  -285,   257,  -285,  -285,  -285,  -285,  -285,   333,
    -285,  -285,   322,  -285,  -285,  -285,   244,   -40,  -285,  -285,
     -29,  -285,  -285,    48,   -94,   -25,  -285,   199,   -56,   -78,
    -285,  -285,  -284,  -285,  -285,  -285,   102,  -285,   103,  -285,
    -285,  -285,   -84,  -285,   263,  -111,   165,   170,   173,   178,
     172,    51,   -13,   160,    45,     0,   -48,  -285,  -257,  -285,
    -285,  -285,  -285
  };

  const short
  parser::yydefgoto_[] =
  {
       0,     7,     8,     9,    10,    42,    43,   243,    28,    56,
      57,    58,   105,   206,   292,    13,    32,    14,    36,    37,
      15,    51,    52,    53,    54,    16,    44,    45,    46,    47,
     167,   107,   108,   164,   109,   110,   111,   112,   113,   166,
     114,   115,   374,   116,   271,   272,   273,   343,   274,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     406,   138,   333
  };

  const short
  parser::yytable_[] =
  {
     106,    33,   185,   165,   153,    30,    29,   176,   179,   181,
      33,   211,   344,   331,    33,   186,   262,   408,   264,    25,
     189,   140,   368,    17,    33,   220,   221,   222,   223,   165,
     168,   169,   170,   171,   172,   173,   174,    66,    67,   212,
      38,   255,    70,    71,    72,    73,    74,    75,    76,    77,
     361,    21,    22,    23,    24,    39,   141,    40,   362,    88,
      89,    90,    91,    55,   218,    41,   237,   106,    86,    87,
     369,    35,   256,   224,   255,    18,    55,   187,   187,   332,
     106,   219,   255,   252,   208,    35,   148,   202,   165,   255,
     203,    39,   204,    40,   205,    31,   319,    27,    92,   266,
     267,   152,   298,   275,    34,   165,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   145,   350,
     293,   294,   400,   418,   351,   365,   416,    48,    48,    49,
      49,    59,   103,   175,   366,   417,   425,   106,    29,    50,
     157,   149,   247,   249,   202,    11,   431,   203,   150,   204,
     322,   205,    39,    11,    40,   139,   106,   393,   202,    12,
     208,   203,   240,   204,   159,   205,   160,    12,    39,   338,
      40,   428,    19,    20,   334,   327,   328,   386,   318,   142,
     255,   335,   336,   316,   342,     1,   147,     2,   244,     3,
     151,     4,   246,   248,     5,   154,     6,   165,   165,   387,
     228,   153,   255,   165,   165,   229,   230,   305,   306,   307,
     308,   309,    19,    20,   155,   106,    70,    71,    72,    73,
      74,    75,    76,    77,   162,   163,   156,   106,   313,   314,
     315,   208,   177,   288,   106,   289,   354,   159,   355,   402,
     143,   144,   356,   143,   161,   359,   360,   378,   226,   227,
     178,   381,   232,   233,   182,   375,   376,   379,   380,   269,
     270,   188,   384,   183,   165,   187,   382,   165,   165,   303,
     304,   311,   312,   209,   214,   215,   204,   216,   217,   396,
     388,   225,   231,   234,   391,   392,   401,   235,   395,   236,
     238,   239,    33,   106,   253,   254,   242,   208,   245,   407,
     250,   257,   258,   412,   259,   260,   405,   290,   370,   106,
     261,   263,   106,   208,   413,   420,   106,   212,   295,   296,
     415,   320,   317,   389,   255,   323,   324,   106,   427,   325,
     326,   345,   423,   337,   430,   329,   339,   340,   341,   352,
     349,   397,   353,   357,   106,   364,   363,   346,   367,   106,
     385,   106,   106,   208,   398,   106,   208,   404,   390,   208,
     409,   414,   422,    26,   106,   383,   251,   106,   106,   146,
     210,   208,   106,   158,   347,   348,   208,   297,   106,   419,
     106,   265,   208,   106,   299,   310,   213,   208,   300,   302,
     424,   106,   241,   106,   301,   208,     0,     0,   106,   106,
       0,   106,   208,     0,     0,   208,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,     0,    78,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,    81,    82,     0,     0,     0,    83,     0,    84,
       0,    85,    86,    87,    88,    89,    90,    91,     0,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,    93,
     371,     0,   372,   373,    94,    95,     0,    96,     0,     0,
      97,    98,    99,     0,     0,     0,     0,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,   103,     0,     0,
       0,     0,   104,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,     0,     0,    78,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,     0,     0,     0,     0,    81,
      82,     0,     0,     0,    83,     0,    84,     0,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,     0,
      92,     0,     0,     0,     0,     0,    93,     0,     0,     0,
       0,    94,    95,     0,    96,     0,     0,    97,    98,    99,
       0,     0,     0,     0,   100,   101,     0,     0,     0,   102,
       0,     0,     0,     0,   103,     0,     0,     0,     0,   104,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,     0,     0,     0,    81,    82,     0,     0,
       0,    83,     0,    84,     0,    85,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,     0,    92,     0,     0,
       0,     0,     0,    93,     0,     0,     0,     0,    94,    95,
       0,    96,   184,     0,    97,    98,    99,     0,     0,     0,
       0,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,     0,     0,     0,   104,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     0,     0,    78,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,     0,
       0,     0,     0,    81,    82,     0,     0,     0,    83,     0,
      84,     0,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     0,     0,     0,    92,     0,     0,     0,     0,     0,
      93,     0,     0,     0,     0,    94,    95,     0,    96,     0,
       0,    97,    98,    99,     0,     0,     0,     0,   100,   101,
       0,     0,     0,   207,     0,     0,     0,     0,   103,     0,
       0,     0,     0,   104,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,     0,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,     0,     0,     0,     0,     0,
      81,    82,     0,     0,     0,    83,     0,    84,     0,    85,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
       0,    92,     0,   255,     0,     0,     0,    93,     0,     0,
       0,     0,    94,    95,     0,    96,     0,     0,    97,    98,
      99,     0,     0,     0,     0,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,     0,     0,     0,
     104,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
       0,     0,    78,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,     0,     0,     0,     0,     0,    81,    82,     0,
       0,     0,    83,     0,    84,     0,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,     0,    92,     0,
       0,     0,     0,     0,    93,     0,     0,     0,     0,    94,
      95,     0,    96,   268,     0,    97,    98,    99,     0,     0,
       0,     0,   100,   101,     0,     0,     0,     0,     0,     0,
       0,     0,   103,     0,     0,     0,     0,   104,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,     0,    78,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
       0,     0,     0,     0,    81,    82,     0,     0,     0,    83,
       0,    84,     0,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,     0,     0,    92,     0,     0,     0,     0,
       0,    93,     0,     0,     0,     0,    94,    95,     0,    96,
       0,     0,    97,    98,    99,     0,     0,     0,     0,   100,
     101,     0,     0,     0,   321,     0,     0,     0,     0,   103,
       0,     0,     0,     0,   104,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,     0,    78,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,     0,     0,     0,     0,     0,
       0,    81,    82,     0,     0,     0,    83,     0,    84,     0,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,     0,    92,     0,     0,     0,     0,     0,    93,     0,
       0,     0,     0,    94,    95,     0,    96,     0,     0,    97,
      98,    99,     0,     0,     0,     0,   100,   101,     0,   330,
       0,     0,     0,     0,     0,     0,   103,     0,     0,     0,
       0,   104,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,     0,    78,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,    81,    82,
       0,     0,     0,    83,     0,    84,     0,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,     0,    92,
       0,     0,     0,     0,     0,    93,     0,     0,     0,     0,
      94,    95,     0,    96,     0,     0,    97,    98,    99,     0,
       0,     0,     0,   100,   101,     0,     0,     0,   358,     0,
       0,     0,     0,   103,     0,     0,     0,     0,   104,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,     0,
      78,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,     0,     0,     0,    81,    82,     0,     0,     0,
      83,     0,    84,     0,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,    92,     0,     0,     0,
       0,     0,    93,     0,     0,     0,     0,    94,    95,   377,
      96,     0,     0,    97,    98,    99,     0,     0,     0,     0,
     100,   101,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,     0,     0,   104,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,     0,    78,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,    81,    82,     0,     0,     0,    83,     0,    84,
       0,    85,    86,    87,    88,    89,    90,    91,     0,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,    93,
       0,     0,     0,     0,    94,    95,   399,    96,     0,     0,
      97,    98,    99,     0,     0,     0,     0,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,   103,     0,     0,
       0,     0,   104,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,     0,     0,    78,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,     0,     0,     0,     0,    81,
      82,     0,     0,     0,    83,     0,    84,     0,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,     0,
      92,     0,     0,     0,     0,     0,    93,     0,     0,     0,
       0,    94,    95,     0,    96,     0,     0,    97,    98,    99,
       0,     0,     0,     0,   100,   101,     0,   403,     0,     0,
       0,     0,     0,     0,   103,     0,     0,     0,     0,   104,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,     0,     0,     0,    81,    82,     0,     0,
       0,    83,     0,    84,     0,    85,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,     0,    92,     0,     0,
       0,     0,     0,    93,   410,     0,     0,     0,    94,    95,
       0,    96,     0,     0,    97,    98,    99,     0,     0,     0,
       0,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,     0,     0,     0,   104,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     0,     0,    78,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,     0,
       0,     0,     0,    81,    82,     0,     0,     0,    83,     0,
      84,     0,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     0,     0,     0,    92,     0,     0,     0,     0,     0,
      93,     0,     0,     0,     0,    94,    95,     0,    96,     0,
     411,    97,    98,    99,     0,     0,     0,     0,   100,   101,
       0,     0,     0,     0,     0,     0,     0,     0,   103,     0,
       0,     0,     0,   104,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,     0,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,     0,     0,     0,     0,     0,
      81,    82,     0,     0,     0,    83,     0,    84,     0,    85,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
       0,    92,     0,     0,     0,     0,     0,    93,     0,     0,
       0,     0,    94,    95,     0,    96,     0,   421,    97,    98,
      99,     0,     0,     0,     0,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,     0,     0,     0,
     104,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
       0,     0,    78,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,     0,     0,     0,     0,     0,    81,    82,     0,
       0,     0,    83,     0,    84,     0,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,     0,    92,     0,
       0,     0,     0,     0,    93,     0,     0,     0,     0,    94,
      95,     0,    96,     0,   426,    97,    98,    99,     0,     0,
       0,     0,   100,   101,     0,     0,     0,     0,     0,     0,
       0,     0,   103,     0,     0,     0,     0,   104,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,     0,    78,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
       0,     0,     0,     0,    81,    82,     0,     0,     0,    83,
       0,    84,     0,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,     0,     0,    92,     0,     0,     0,     0,
       0,    93,     0,     0,     0,     0,    94,    95,     0,    96,
       0,   429,    97,    98,    99,     0,     0,     0,     0,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,   103,
       0,     0,     0,     0,   104,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,     0,    78,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,     0,     0,     0,     0,     0,
       0,    81,    82,     0,     0,     0,    83,     0,    84,     0,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,     0,    92,     0,     0,     0,     0,     0,    93,     0,
       0,     0,     0,    94,    95,     0,    96,     0,     0,    97,
      98,    99,     0,     0,     0,     0,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,   103,     0,     0,     0,
       0,   104,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,     0,    78,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,    81,    82,
       0,     0,     0,    83,     0,    84,     0,    85,     0,     0,
      88,    89,    90,    91,     0,     0,     0,     0,     0,    92,
     291,     0,     0,     0,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,   100,   101,    78,    79,     0,     0,     0,
       0,     0,     0,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,     0,     0,     0,     0,     0,
      81,    82,     0,     0,     0,    83,     0,    84,     0,    85,
       0,     0,    88,    89,    90,    91,     0,     0,     0,     0,
       0,    92,     0,     0,   329,     0,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,   100,   101,    78,    79,     0,
       0,     0,     0,     0,     0,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,    81,    82,     0,     0,     0,    83,     0,    84,
       0,    85,     0,     0,    88,    89,    90,    91,     0,     0,
       0,     0,     0,    92,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,     0,    78,    79,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,   103,     0,     0,
       0,     0,     0,    80,     0,     0,     0,     0,     0,     0,
      81,    82,     0,     0,     0,    83,     0,    84,     0,    85,
       0,     0,    88,    89,    90,    91,     0,     0,     0,     0,
       0,    92,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,     0,    78,    79,   180,   101,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,     0,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,    81,    82,
       0,     0,     0,    83,     0,    84,     0,    85,     0,     0,
      88,    89,    90,    91,     0,     0,     0,     0,     0,    92,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,    78,    79,   394,   101,     0,     0,     0,     0,     0,
       0,     0,     0,   103,     0,     0,     0,     0,     0,    80,
       0,     0,     0,     0,     0,     0,    81,    82,     0,     0,
       0,    83,     0,    84,     0,    85,     0,     0,     0,    60,
      61,    62,    63,    64,    65,    66,    67,    92,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
       0,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,   201,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,   202,     0,     0,   203,     0,
     204,     0,   205,     0,     0,     0,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,   101,     0,     0,     0,     0,     0,     0,     0,     0,
     103
  };

  const short
  parser::yycheck_[] =
  {
      29,     9,    96,    59,    44,    11,    18,    85,    92,    93,
       9,   122,   269,     9,     9,    99,     9,     9,     9,     0,
     104,    66,    53,     9,     9,    45,    46,    47,    48,    85,
      78,    79,    80,    81,    82,    83,    84,     9,    10,    41,
      81,    72,    14,    15,    16,    17,    18,    19,    20,    21,
      48,     3,     4,     5,     6,    96,   101,    98,    48,    61,
      62,    63,    64,    71,    27,   106,   144,    96,    59,    60,
      53,    22,   166,    93,    72,     9,    71,    70,    70,    75,
     109,    44,    72,   161,   109,    36,    38,    65,   144,    72,
      68,    96,    70,    98,    72,   101,   104,    70,    70,   183,
     184,   106,   213,   187,   103,   161,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   103,    66,
     204,   205,   379,   407,    71,    66,    66,    96,    96,    98,
      98,    67,   104,    85,    75,    75,   420,   166,   150,   108,
     108,     9,   154,   155,    65,     0,   430,    68,     9,    70,
     244,    72,    96,     8,    98,    69,   185,    78,    65,     0,
     185,    68,   106,    70,    69,    72,    71,     8,    96,   263,
      98,    78,    10,    11,   258,   253,   254,    69,   106,    69,
      72,   259,   260,   231,   268,    96,    69,    98,   150,   100,
      69,   102,   154,   155,   105,     9,   107,   253,   254,    69,
      51,   241,    72,   259,   260,    56,    57,   220,   221,   222,
     223,   224,    10,    11,     9,   244,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    69,   256,   228,   229,
     230,   256,     9,     9,   263,    11,    69,    69,    71,    71,
      66,    67,   320,    66,    67,   323,   324,   341,    54,    55,
       9,   345,    24,    25,    70,   339,   340,    66,    67,    90,
      91,    69,   356,    70,   320,    70,   350,   323,   324,   218,
     219,   226,   227,    69,    40,    43,    70,    52,    42,   373,
     364,    30,    26,    11,   368,   369,   380,    69,   372,     9,
      69,    69,     9,   322,    47,    47,    70,   322,    69,   393,
      69,    74,    72,   397,    67,    67,   390,     9,   337,   338,
      71,    78,   341,   338,   398,   409,   345,    41,    69,    69,
     404,    67,    69,     9,    72,    67,    67,   356,   422,    69,
      69,    67,   416,    93,   428,    73,    93,    69,    71,    73,
      71,    71,    69,    69,   373,    67,    69,    92,    73,   378,
      69,   380,   381,   378,    69,   384,   381,    67,    74,   384,
      78,    69,    71,     8,   393,   354,   159,   396,   397,    36,
     113,   396,   401,    51,   272,   272,   401,   212,   407,    93,
     409,   182,   407,   412,   214,   225,   123,   412,   215,   217,
     419,   420,   148,   422,   216,   420,    -1,    -1,   427,   428,
      -1,   430,   427,    -1,    -1,   430,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      77,    -1,    79,    80,    81,    82,    -1,    84,    -1,    -1,
      87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,   109,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    81,    82,    -1,    84,    -1,    -1,    87,    88,    89,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    82,
      -1,    84,    85,    -1,    87,    88,    89,    -1,    -1,    -1,
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
      -1,    87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    82,    -1,    84,    -1,    -1,    87,    88,
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
      82,    -1,    84,    85,    -1,    87,    88,    89,    -1,    -1,
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
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,   109,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    81,    82,    -1,    84,    -1,    -1,    87,
      88,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,   109,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      81,    82,    -1,    84,    -1,    -1,    87,    88,    89,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    99,    -1,
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
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    -1,    -1,
      87,    88,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,   109,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    81,    82,    -1,    84,    -1,    -1,    87,    88,    89,
      -1,    -1,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    81,    82,
      -1,    84,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,
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
      -1,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
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
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,   109,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    56,    -1,    58,    -1,    -1,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    94,    95,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,
      -1,    -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    73,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    94,    95,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,    56,
      -1,    58,    -1,    -1,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    24,    25,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,
      -1,    -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    24,    25,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    56,    -1,    58,    -1,    -1,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    24,    25,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    54,    -1,    56,    -1,    58,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    70,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    65,    -1,    -1,    68,    -1,
      70,    -1,    72,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    96,    98,   100,   102,   105,   107,   111,   112,   113,
     114,   115,   116,   125,   127,   130,   135,     9,     9,    10,
      11,   143,   143,   143,   143,     0,   113,    70,   118,   118,
      11,   101,   126,     9,   103,   121,   128,   129,    81,    96,
      98,   106,   115,   116,   136,   137,   138,   139,    96,    98,
     108,   131,   132,   133,   134,    71,   119,   120,   121,    67,
       3,     4,     5,     6,     7,     8,     9,    10,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    24,    25,
      42,    49,    50,    54,    56,    58,    59,    60,    61,    62,
      63,    64,    70,    76,    81,    82,    84,    87,    88,    89,
      94,    95,    99,   104,   109,   122,   140,   141,   142,   144,
     145,   146,   147,   148,   150,   151,   153,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   181,    69,
      66,   101,    69,    66,    67,   103,   129,    69,   143,     9,
       9,    69,   106,   137,     9,     9,    69,   108,   132,    69,
      71,    67,    22,    23,   143,   148,   149,   140,   176,   176,
     176,   176,   176,   176,   176,   143,   149,     9,     9,   162,
      94,   162,    70,    70,    85,   144,   162,    70,    69,   162,
      28,    29,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    53,    65,    68,    70,    72,   123,    99,   145,    69,
     123,   165,    41,   164,    40,    43,    52,    42,    27,    44,
      45,    46,    47,    48,    93,    30,    54,    55,    51,    56,
      57,    26,    24,    25,    11,    69,     9,   149,    69,    69,
     106,   136,    70,   117,   117,    69,   117,   118,   117,   118,
      69,   120,   149,    47,    47,    72,   144,    74,    72,    67,
      67,    71,     9,    78,     9,   147,   162,   162,    85,    90,
      91,   154,   155,   156,   158,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,     9,    11,
       9,    71,   124,   162,   162,    69,    69,   166,   165,   167,
     168,   169,   170,   171,   171,   172,   172,   172,   172,   172,
     173,   174,   174,   175,   175,   175,   176,    69,   106,   104,
      67,    99,   144,    67,    67,    69,    69,   149,   149,    73,
      97,     9,    75,   182,   162,   149,   149,    93,   144,    93,
      69,    71,   162,   157,   178,    67,    92,   156,   158,    71,
      66,    71,    73,    69,    69,    71,   149,    69,    99,   149,
     149,    48,    48,    69,    67,    66,    75,    73,    53,    53,
     140,    77,    79,    80,   152,   162,   162,    83,   144,    66,
      67,   144,   162,   119,   144,    69,    69,    69,   162,     9,
      74,   162,   162,    78,    94,   162,   144,    71,    69,    83,
     178,   144,    71,    97,    67,   162,   180,   144,     9,    78,
      77,    86,   144,   162,    69,   162,    66,    75,   152,    93,
     144,    86,    71,   162,   140,   152,    86,   144,    78,    86,
     144,   152
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   110,   111,   112,   112,   113,   113,   113,   113,   113,
     114,   114,   115,   116,   116,   117,   117,   118,   118,   119,
     119,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   129,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   135,   135,   136,   136,   137,   137,   138,   138,   139,
     139,   139,   140,   140,   140,   140,   140,   140,   141,   141,
     141,   142,   142,   143,   143,   144,   144,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   146,   147,
     147,   148,   148,   148,   148,   148,   148,   148,   148,   149,
     149,   149,   149,   149,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   151,   151,   152,   152,
     152,   152,   153,   154,   154,   155,   155,   156,   157,   157,
     158,   159,   159,   159,   159,   160,   160,   161,   161,   162,
     162,   163,   163,   163,   164,   164,   164,   164,   165,   165,
     166,   166,   167,   167,   168,   168,   169,   169,   170,   170,
     170,   171,   171,   171,   171,   171,   171,   172,   172,   173,
     173,   173,   174,   174,   174,   174,   175,   175,   175,   175,
     175,   175,   175,   175,   176,   176,   177,   177,   177,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   179,   179,   180,   180,   181,   181,   182,   182
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     8,     6,     5,     5,     3,     3,     2,     3,
       1,     3,     3,     1,     2,     2,     3,     2,     3,     1,
       5,     4,     3,     1,     5,     4,     3,     2,     3,     5,
       4,     2,     1,     1,     1,     6,     6,     4,     4,     5,
       4,     7,     6,     2,     1,     1,     1,     8,     1,     6,
       5,     1,     3,     3,     4,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     6,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     4,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     8,     5,     8,
       3,     1,     4,     2,     1,     2,     1,     4,     3,     1,
       3,     8,     7,    10,     9,     6,     5,     4,     3,     1,
       1,     2,     2,     3,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     2,     2,
       2,     2,     2,     1,     3,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     8,     3,     1,     5,     4,     5,     3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   106,   106,   110,   113,   118,   120,   122,   124,   126,
     130,   132,   136,   143,   148,   152,   154,   158,   160,   164,
     169,   176,   183,   186,   191,   193,   197,   199,   203,   206,
     211,   213,   217,   220,   225,   227,   231,   236,   240,   247,
     249,   253,   256,   261,   263,   267,   269,   273,   275,   279,
     281,   283,   285,   289,   292,   297,   299,   303,   308,   312,
     317,   319,   323,   325,   327,   329,   331,   333,   337,   339,
     341,   345,   347,   351,   353,   357,   360,   365,   367,   369,
     371,   373,   375,   377,   379,   381,   383,   385,   389,   393,
     395,   399,   401,   403,   405,   407,   409,   411,   413,   417,
     419,   421,   423,   425,   429,   431,   433,   435,   437,   439,
     441,   443,   445,   447,   449,   451,   455,   460,   467,   472,
     477,   482,   486,   490,   493,   498,   501,   506,   513,   516,
     521,   528,   533,   535,   540,   544,   549,   553,   558,   562,
     564,   568,   570,   572,   576,   578,   580,   582,   586,   588,
     592,   594,   598,   600,   604,   606,   610,   612,   616,   618,
     620,   624,   626,   628,   630,   632,   634,   638,   640,   644,
     646,   648,   652,   654,   656,   658,   662,   664,   666,   668,
     670,   672,   674,   676,   680,   682,   686,   688,   690,   694,
     696,   698,   700,   702,   704,   706,   708,   710,   712,   714,
     716,   718,   722,   724,   731,   734,   739,   741,   745,   748
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
#line 4479 "grammar/build/syntax.tab.cc"

#line 752 "grammar/syntax.y"
