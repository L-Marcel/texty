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
#line 16 "grammar/syntax.y"

  yy::parser::symbol_type yylex(Context& context);

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
  parser::parser (Context& context_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      context (context_yyarg)
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
      case symbol_kind::S_program: // program
      case symbol_kind::S_sum_expr: // sum_expr
      case symbol_kind::S_mult_expr: // mult_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_exp_expr: // exp_expr
      case symbol_kind::S_postfix_expr: // postfix_expr
      case symbol_kind::S_term: // term
        value.YY_MOVE_OR_COPY< Node* > (YY_MOVE (that.value));
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
        value.YY_MOVE_OR_COPY< NodeType > (YY_MOVE (that.value));
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
      case symbol_kind::S_program: // program
      case symbol_kind::S_sum_expr: // sum_expr
      case symbol_kind::S_mult_expr: // mult_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_exp_expr: // exp_expr
      case symbol_kind::S_postfix_expr: // postfix_expr
      case symbol_kind::S_term: // term
        value.move< Node* > (YY_MOVE (that.value));
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
        value.move< NodeType > (YY_MOVE (that.value));
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
      case symbol_kind::S_program: // program
      case symbol_kind::S_sum_expr: // sum_expr
      case symbol_kind::S_mult_expr: // mult_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_exp_expr: // exp_expr
      case symbol_kind::S_postfix_expr: // postfix_expr
      case symbol_kind::S_term: // term
        value.copy< Node* > (that.value);
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
        value.copy< NodeType > (that.value);
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
      case symbol_kind::S_program: // program
      case symbol_kind::S_sum_expr: // sum_expr
      case symbol_kind::S_mult_expr: // mult_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_exp_expr: // exp_expr
      case symbol_kind::S_postfix_expr: // postfix_expr
      case symbol_kind::S_term: // term
        value.move< Node* > (that.value);
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
        value.move< NodeType > (that.value);
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
            symbol_type yylookahead (yylex (context));
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
      case symbol_kind::S_program: // program
      case symbol_kind::S_sum_expr: // sum_expr
      case symbol_kind::S_mult_expr: // mult_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_exp_expr: // exp_expr
      case symbol_kind::S_postfix_expr: // postfix_expr
      case symbol_kind::S_term: // term
        yylhs.value.emplace< Node* > ();
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
        yylhs.value.emplace< NodeType > ();
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
  case 2: // program: sum_expr
#line 57 "grammar/syntax.y"
                  {
  context.root = yystack_[0].value.as < Node* > (); // "Entrega" a árvore pronta para o contexto
}
#line 797 "grammar/build/syntax.tab.cc"
    break;

  case 3: // sum_expr: sum_expr PLUS mult_expr
#line 61 "grammar/syntax.y"
                                  {
  yylhs.value.as < Node* > () = new BinaryOperationNode(BinaryOperation::PLUS, yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > ());
}
#line 805 "grammar/build/syntax.tab.cc"
    break;

  case 4: // sum_expr: sum_expr MINUS mult_expr
#line 63 "grammar/syntax.y"
                             {
  yylhs.value.as < Node* > () = new BinaryOperationNode(BinaryOperation::MINUS, yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > ());
}
#line 813 "grammar/build/syntax.tab.cc"
    break;

  case 5: // sum_expr: mult_expr
#line 65 "grammar/syntax.y"
              {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 821 "grammar/build/syntax.tab.cc"
    break;

  case 6: // mult_expr: mult_expr MULT unary_expr
#line 69 "grammar/syntax.y"
                                     {
  yylhs.value.as < Node* > () = new BinaryOperationNode(BinaryOperation::MULT, yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > ());
}
#line 829 "grammar/build/syntax.tab.cc"
    break;

  case 7: // mult_expr: mult_expr DIV unary_expr
#line 71 "grammar/syntax.y"
                             {
  yylhs.value.as < Node* > () = new BinaryOperationNode(BinaryOperation::DIV, yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > ());
}
#line 837 "grammar/build/syntax.tab.cc"
    break;

  case 8: // mult_expr: mult_expr MOD unary_expr
#line 73 "grammar/syntax.y"
                             {
  yylhs.value.as < Node* > () = new BinaryOperationNode(BinaryOperation::MOD, yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > ());
}
#line 845 "grammar/build/syntax.tab.cc"
    break;

  case 9: // mult_expr: unary_expr
#line 75 "grammar/syntax.y"
               {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 853 "grammar/build/syntax.tab.cc"
    break;

  case 10: // unary_expr: MINUS exp_expr
#line 79 "grammar/syntax.y"
                           {
  yylhs.value.as < Node* > () = new UnaryOperationNode(UnaryOperation::MINUS, yystack_[0].value.as < Node* > ());
}
#line 861 "grammar/build/syntax.tab.cc"
    break;

  case 11: // unary_expr: REV exp_expr
#line 81 "grammar/syntax.y"
                 {
  yylhs.value.as < Node* > () = new UnaryOperationNode(UnaryOperation::REV, yystack_[0].value.as < Node* > ());
}
#line 869 "grammar/build/syntax.tab.cc"
    break;

  case 12: // unary_expr: NOT exp_expr
#line 83 "grammar/syntax.y"
                 {
  yylhs.value.as < Node* > () = new UnaryOperationNode(UnaryOperation::NOT, yystack_[0].value.as < Node* > ());
}
#line 877 "grammar/build/syntax.tab.cc"
    break;

  case 13: // unary_expr: REF exp_expr
#line 85 "grammar/syntax.y"
                 {
  yylhs.value.as < Node* > () = new UnaryOperationNode(UnaryOperation::REF, yystack_[0].value.as < Node* > ());
}
#line 885 "grammar/build/syntax.tab.cc"
    break;

  case 14: // unary_expr: INCREMENT exp_expr
#line 87 "grammar/syntax.y"
                       {
  yylhs.value.as < Node* > () = new UnaryOperationNode(UnaryOperation::INCREMENT, yystack_[0].value.as < Node* > ());
}
#line 893 "grammar/build/syntax.tab.cc"
    break;

  case 15: // unary_expr: DECREMENT exp_expr
#line 89 "grammar/syntax.y"
                       {
  yylhs.value.as < Node* > () = new UnaryOperationNode(UnaryOperation::DECREMENT, yystack_[0].value.as < Node* > ());
}
#line 901 "grammar/build/syntax.tab.cc"
    break;

  case 16: // unary_expr: exp_expr
#line 91 "grammar/syntax.y"
             {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 909 "grammar/build/syntax.tab.cc"
    break;

  case 17: // exp_expr: postfix_expr EXP exp_expr
#line 95 "grammar/syntax.y"
                                    {
  yylhs.value.as < Node* > () = new BinaryOperationNode(BinaryOperation::EXP, yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > ());
}
#line 917 "grammar/build/syntax.tab.cc"
    break;

  case 18: // exp_expr: postfix_expr
#line 97 "grammar/syntax.y"
                 {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 925 "grammar/build/syntax.tab.cc"
    break;

  case 19: // postfix_expr: term INCREMENT
#line 101 "grammar/syntax.y"
                             {
  yylhs.value.as < Node* > () = new UnaryOperationNode(true, UnaryOperation::INCREMENT, yystack_[1].value.as < Node* > ());
}
#line 933 "grammar/build/syntax.tab.cc"
    break;

  case 20: // postfix_expr: term DECREMENT
#line 103 "grammar/syntax.y"
                   {
  yylhs.value.as < Node* > () = new UnaryOperationNode(true, UnaryOperation::DECREMENT, yystack_[1].value.as < Node* > ());
}
#line 941 "grammar/build/syntax.tab.cc"
    break;

  case 21: // postfix_expr: term
#line 105 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > ();
}
#line 949 "grammar/build/syntax.tab.cc"
    break;

  case 22: // term: INT
#line 109 "grammar/syntax.y"
          {
  yylhs.value.as < Node* > () = new IntNode(context.line, yystack_[0].value.as < int32_t > ());
}
#line 957 "grammar/build/syntax.tab.cc"
    break;

  case 23: // term: LONG
#line 111 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = new LongNode(context.line, yystack_[0].value.as < int64_t > ());
}
#line 965 "grammar/build/syntax.tab.cc"
    break;

  case 24: // term: FLOAT
#line 113 "grammar/syntax.y"
          {
  yylhs.value.as < Node* > () = new FloatNode(context.line, yystack_[0].value.as < float > ());
}
#line 973 "grammar/build/syntax.tab.cc"
    break;

  case 25: // term: DOUBLE
#line 115 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = new DoubleNode(context.line, yystack_[0].value.as < double > ());
}
#line 981 "grammar/build/syntax.tab.cc"
    break;

  case 26: // term: BYTE
#line 117 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = new ByteNode(context.line, yystack_[0].value.as < uint8_t > ());
}
#line 989 "grammar/build/syntax.tab.cc"
    break;

  case 27: // term: BOOL
#line 119 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = new BoolNode(context.line, yystack_[0].value.as < bool > ());
}
#line 997 "grammar/build/syntax.tab.cc"
    break;

  case 28: // term: STRING
#line 121 "grammar/syntax.y"
           {
  yylhs.value.as < Node* > () = new StringNode(context.line, yystack_[0].value.as < std::string > ());
}
#line 1005 "grammar/build/syntax.tab.cc"
    break;

  case 29: // term: CHAR
#line 123 "grammar/syntax.y"
         {
  yylhs.value.as < Node* > () = new CharNode(context.line, yystack_[0].value.as < char > ());
}
#line 1013 "grammar/build/syntax.tab.cc"
    break;


#line 1017 "grammar/build/syntax.tab.cc"

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
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
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

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -37;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      -3,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,    20,
      20,    20,    20,    20,    20,    37,   -36,   -21,   -37,   -37,
      13,    -5,   -37,   -37,   -37,   -37,   -37,   -37,   -37,    -3,
      -3,    -3,    -3,    -3,    20,   -37,   -37,   -21,   -21,   -37,
     -37,   -37,   -37
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    26,    22,    23,    24,    25,    27,    28,    29,     0,
       0,     0,     0,     0,     0,     0,     2,     5,     9,    16,
      18,    21,    15,    14,    13,    12,    11,    10,     1,     0,
       0,     0,     0,     0,     0,    20,    19,     4,     3,     8,
       6,     7,    17
  };

  const signed char
  parser::yypgoto_[] =
  {
     -37,   -37,   -37,     1,   -25,     2,   -37,   -37
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,    15,    16,    17,    18,    19,    20,    21
  };

  const signed char
  parser::yytable_[] =
  {
       1,     2,     3,     4,     5,     6,    39,    40,    41,     7,
       8,    22,    23,    24,    25,    26,    27,    29,    30,    35,
      36,     9,    10,     1,     2,     3,     4,     5,     6,    31,
      37,    38,     7,     8,    32,    33,    42,    28,    11,    34,
       0,     0,     0,     0,     0,    12,    13,     0,     0,     0,
      14
  };

  const signed char
  parser::yycheck_[] =
  {
       3,     4,     5,     6,     7,     8,    31,    32,    33,    12,
      13,     9,    10,    11,    12,    13,    14,    53,    54,    24,
      25,    24,    25,     3,     4,     5,     6,     7,     8,    50,
      29,    30,    12,    13,    55,    56,    34,     0,    41,    26,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,
      53
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,    12,    13,    24,
      25,    41,    48,    49,    53,   107,   108,   109,   110,   111,
     112,   113,   111,   111,   111,   111,   111,   111,     0,    53,
      54,    50,    55,    56,    26,    24,    25,   109,   109,   110,
     110,   110,   111
  };

  const signed char
  parser::yyr1_[] =
  {
       0,   106,   107,   108,   108,   108,   109,   109,   109,   109,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   112,
     112,   112,   113,   113,   113,   113,   113,   113,   113,   113
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "BYTE", "INT", "LONG",
  "FLOAT", "DOUBLE", "BOOL", "ID", "NAME", "CONST_NAME", "STRING", "CHAR",
  "TYPE_BYTE", "TYPE_INT", "TYPE_LONG", "TYPE_FLOAT", "TYPE_DOUBLE",
  "TYPE_BOOL", "TYPE_STRING", "TYPE_CHAR", "TYPE_POINTER", "TYPE_OPTION",
  "DECREMENT", "INCREMENT", "EXP", "EQ", "AND_ATTR", "OR_ATTR",
  "LAZY_AND_ATTR", "LAZY_OR_ATTR", "MOD_ATTR", "XOR_ATTR", "PLUS_ATTR",
  "CONCAT_ATTR", "MINUS_ATTR", "MULT_ATTR", "DIV_ATTR", "AND", "OR", "REF",
  "BAR", "NOT_EQ", "LT_EQ", "GT_EQ", "LT", "GT", "NOT", "REV", "MOD",
  "XOR", "ATTR", "MINUS", "PLUS", "MULT", "DIV", "NEW", "VAR", "CONST",
  "RANGE", "DOT", "COMMA", "COLON", "DOUBLE_COLON", "SEMICOLON",
  "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET",
  "LEFT_BRACE", "RIGHT_BRACE", "IF", "END_IF", "THEN", "ELIF", "ELSE",
  "FOR", "WHILE", "END_WHILE", "REPEAT", "UNTIL", "END_FOR", "BREAK",
  "CONTINUE", "SWITCH", "CASE", "DEFAULT", "END_SWITCH", "IN", "SOME",
  "NONE", "FUNCTION", "END_FUNCTION", "PROCEDURE", "END_PROCEDURE", "ENUM",
  "END_ENUM", "STRUCT", "END_STRUCT", "SELF", "IMPL", "END_IMPL", "TRAIT",
  "END_TRAIT", "RETURN", "$accept", "program", "sum_expr", "mult_expr",
  "unary_expr", "exp_expr", "postfix_expr", "term", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const signed char
  parser::yyrline_[] =
  {
       0,    57,    57,    61,    63,    65,    69,    71,    73,    75,
      79,    81,    83,    85,    87,    89,    91,    95,    97,   101,
     103,   105,   109,   111,   113,   115,   117,   119,   121,   123
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
#line 1357 "grammar/build/syntax.tab.cc"

#line 126 "grammar/syntax.y"
