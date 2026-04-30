// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file grammar/build/syntax.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_GRAMMAR_BUILD_SYNTAX_TAB_HH_INCLUDED
# define YY_YY_GRAMMAR_BUILD_SYNTAX_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 3 "grammar/syntax.y"

  #include <string>
  #include <cstdint>
  #include "../src/syntax/main.h"
  #include "../src/context.h"

#line 56 "grammar/build/syntax.tab.hh"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif

#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

namespace yy {
#line 196 "grammar/build/syntax.tab.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // program
      // sum_expr
      // mult_expr
      // unary_expr
      // exp_expr
      // postfix_expr
      // term
      char dummy1[sizeof (Node*)];

      // TYPE_BYTE
      // TYPE_INT
      // TYPE_LONG
      // TYPE_FLOAT
      // TYPE_DOUBLE
      // TYPE_BOOL
      // TYPE_STRING
      // TYPE_CHAR
      // TYPE_POINTER
      // TYPE_OPTION
      char dummy2[sizeof (NodeType)];

      // BOOL
      char dummy3[sizeof (bool)];

      // CHAR
      char dummy4[sizeof (char)];

      // DOUBLE
      char dummy5[sizeof (double)];

      // FLOAT
      char dummy6[sizeof (float)];

      // INT
      char dummy7[sizeof (int32_t)];

      // LONG
      char dummy8[sizeof (int64_t)];

      // ID
      // NAME
      // CONST_NAME
      // STRING
      char dummy9[sizeof (std::string)];

      // BYTE
      char dummy10[sizeof (uint8_t)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;


    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    BYTE = 258,                    // BYTE
    INT = 259,                     // INT
    LONG = 260,                    // LONG
    FLOAT = 261,                   // FLOAT
    DOUBLE = 262,                  // DOUBLE
    BOOL = 263,                    // BOOL
    ID = 264,                      // ID
    NAME = 265,                    // NAME
    CONST_NAME = 266,              // CONST_NAME
    STRING = 267,                  // STRING
    CHAR = 268,                    // CHAR
    TYPE_BYTE = 269,               // TYPE_BYTE
    TYPE_INT = 270,                // TYPE_INT
    TYPE_LONG = 271,               // TYPE_LONG
    TYPE_FLOAT = 272,              // TYPE_FLOAT
    TYPE_DOUBLE = 273,             // TYPE_DOUBLE
    TYPE_BOOL = 274,               // TYPE_BOOL
    TYPE_STRING = 275,             // TYPE_STRING
    TYPE_CHAR = 276,               // TYPE_CHAR
    TYPE_POINTER = 277,            // TYPE_POINTER
    TYPE_OPTION = 278,             // TYPE_OPTION
    DECREMENT = 279,               // DECREMENT
    INCREMENT = 280,               // INCREMENT
    EXP = 281,                     // EXP
    EQ = 282,                      // EQ
    AND_ATTR = 283,                // AND_ATTR
    OR_ATTR = 284,                 // OR_ATTR
    LAZY_AND_ATTR = 285,           // LAZY_AND_ATTR
    LAZY_OR_ATTR = 286,            // LAZY_OR_ATTR
    MOD_ATTR = 287,                // MOD_ATTR
    XOR_ATTR = 288,                // XOR_ATTR
    PLUS_ATTR = 289,               // PLUS_ATTR
    CONCAT_ATTR = 290,             // CONCAT_ATTR
    MINUS_ATTR = 291,              // MINUS_ATTR
    MULT_ATTR = 292,               // MULT_ATTR
    DIV_ATTR = 293,                // DIV_ATTR
    AND = 294,                     // AND
    OR = 295,                      // OR
    REF = 296,                     // REF
    BAR = 297,                     // BAR
    NOT_EQ = 298,                  // NOT_EQ
    LT_EQ = 299,                   // LT_EQ
    GT_EQ = 300,                   // GT_EQ
    LT = 301,                      // LT
    GT = 302,                      // GT
    NOT = 303,                     // NOT
    REV = 304,                     // REV
    MOD = 305,                     // MOD
    XOR = 306,                     // XOR
    ATTR = 307,                    // ATTR
    MINUS = 308,                   // MINUS
    PLUS = 309,                    // PLUS
    MULT = 310,                    // MULT
    DIV = 311,                     // DIV
    NEW = 312,                     // NEW
    VAR = 313,                     // VAR
    CONST = 314,                   // CONST
    RANGE = 315,                   // RANGE
    DOT = 316,                     // DOT
    COMMA = 317,                   // COMMA
    COLON = 318,                   // COLON
    DOUBLE_COLON = 319,            // DOUBLE_COLON
    SEMICOLON = 320,               // SEMICOLON
    LEFT_PAREN = 321,              // LEFT_PAREN
    RIGHT_PAREN = 322,             // RIGHT_PAREN
    LEFT_BRACKET = 323,            // LEFT_BRACKET
    RIGHT_BRACKET = 324,           // RIGHT_BRACKET
    LEFT_BRACE = 325,              // LEFT_BRACE
    RIGHT_BRACE = 326,             // RIGHT_BRACE
    IF = 327,                      // IF
    END_IF = 328,                  // END_IF
    THEN = 329,                    // THEN
    ELIF = 330,                    // ELIF
    ELSE = 331,                    // ELSE
    FOR = 332,                     // FOR
    WHILE = 333,                   // WHILE
    END_WHILE = 334,               // END_WHILE
    REPEAT = 335,                  // REPEAT
    UNTIL = 336,                   // UNTIL
    END_FOR = 337,                 // END_FOR
    BREAK = 338,                   // BREAK
    CONTINUE = 339,                // CONTINUE
    SWITCH = 340,                  // SWITCH
    CASE = 341,                    // CASE
    DEFAULT = 342,                 // DEFAULT
    END_SWITCH = 343,              // END_SWITCH
    IN = 344,                      // IN
    SOME = 345,                    // SOME
    NONE = 346,                    // NONE
    FUNCTION = 347,                // FUNCTION
    END_FUNCTION = 348,            // END_FUNCTION
    PROCEDURE = 349,               // PROCEDURE
    END_PROCEDURE = 350,           // END_PROCEDURE
    ENUM = 351,                    // ENUM
    END_ENUM = 352,                // END_ENUM
    STRUCT = 353,                  // STRUCT
    END_STRUCT = 354,              // END_STRUCT
    SELF = 355,                    // SELF
    IMPL = 356,                    // IMPL
    END_IMPL = 357,                // END_IMPL
    TRAIT = 358,                   // TRAIT
    END_TRAIT = 359,               // END_TRAIT
    RETURN = 360                   // RETURN
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 106, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_BYTE = 3,                              // BYTE
        S_INT = 4,                               // INT
        S_LONG = 5,                              // LONG
        S_FLOAT = 6,                             // FLOAT
        S_DOUBLE = 7,                            // DOUBLE
        S_BOOL = 8,                              // BOOL
        S_ID = 9,                                // ID
        S_NAME = 10,                             // NAME
        S_CONST_NAME = 11,                       // CONST_NAME
        S_STRING = 12,                           // STRING
        S_CHAR = 13,                             // CHAR
        S_TYPE_BYTE = 14,                        // TYPE_BYTE
        S_TYPE_INT = 15,                         // TYPE_INT
        S_TYPE_LONG = 16,                        // TYPE_LONG
        S_TYPE_FLOAT = 17,                       // TYPE_FLOAT
        S_TYPE_DOUBLE = 18,                      // TYPE_DOUBLE
        S_TYPE_BOOL = 19,                        // TYPE_BOOL
        S_TYPE_STRING = 20,                      // TYPE_STRING
        S_TYPE_CHAR = 21,                        // TYPE_CHAR
        S_TYPE_POINTER = 22,                     // TYPE_POINTER
        S_TYPE_OPTION = 23,                      // TYPE_OPTION
        S_DECREMENT = 24,                        // DECREMENT
        S_INCREMENT = 25,                        // INCREMENT
        S_EXP = 26,                              // EXP
        S_EQ = 27,                               // EQ
        S_AND_ATTR = 28,                         // AND_ATTR
        S_OR_ATTR = 29,                          // OR_ATTR
        S_LAZY_AND_ATTR = 30,                    // LAZY_AND_ATTR
        S_LAZY_OR_ATTR = 31,                     // LAZY_OR_ATTR
        S_MOD_ATTR = 32,                         // MOD_ATTR
        S_XOR_ATTR = 33,                         // XOR_ATTR
        S_PLUS_ATTR = 34,                        // PLUS_ATTR
        S_CONCAT_ATTR = 35,                      // CONCAT_ATTR
        S_MINUS_ATTR = 36,                       // MINUS_ATTR
        S_MULT_ATTR = 37,                        // MULT_ATTR
        S_DIV_ATTR = 38,                         // DIV_ATTR
        S_AND = 39,                              // AND
        S_OR = 40,                               // OR
        S_REF = 41,                              // REF
        S_BAR = 42,                              // BAR
        S_NOT_EQ = 43,                           // NOT_EQ
        S_LT_EQ = 44,                            // LT_EQ
        S_GT_EQ = 45,                            // GT_EQ
        S_LT = 46,                               // LT
        S_GT = 47,                               // GT
        S_NOT = 48,                              // NOT
        S_REV = 49,                              // REV
        S_MOD = 50,                              // MOD
        S_XOR = 51,                              // XOR
        S_ATTR = 52,                             // ATTR
        S_MINUS = 53,                            // MINUS
        S_PLUS = 54,                             // PLUS
        S_MULT = 55,                             // MULT
        S_DIV = 56,                              // DIV
        S_NEW = 57,                              // NEW
        S_VAR = 58,                              // VAR
        S_CONST = 59,                            // CONST
        S_RANGE = 60,                            // RANGE
        S_DOT = 61,                              // DOT
        S_COMMA = 62,                            // COMMA
        S_COLON = 63,                            // COLON
        S_DOUBLE_COLON = 64,                     // DOUBLE_COLON
        S_SEMICOLON = 65,                        // SEMICOLON
        S_LEFT_PAREN = 66,                       // LEFT_PAREN
        S_RIGHT_PAREN = 67,                      // RIGHT_PAREN
        S_LEFT_BRACKET = 68,                     // LEFT_BRACKET
        S_RIGHT_BRACKET = 69,                    // RIGHT_BRACKET
        S_LEFT_BRACE = 70,                       // LEFT_BRACE
        S_RIGHT_BRACE = 71,                      // RIGHT_BRACE
        S_IF = 72,                               // IF
        S_END_IF = 73,                           // END_IF
        S_THEN = 74,                             // THEN
        S_ELIF = 75,                             // ELIF
        S_ELSE = 76,                             // ELSE
        S_FOR = 77,                              // FOR
        S_WHILE = 78,                            // WHILE
        S_END_WHILE = 79,                        // END_WHILE
        S_REPEAT = 80,                           // REPEAT
        S_UNTIL = 81,                            // UNTIL
        S_END_FOR = 82,                          // END_FOR
        S_BREAK = 83,                            // BREAK
        S_CONTINUE = 84,                         // CONTINUE
        S_SWITCH = 85,                           // SWITCH
        S_CASE = 86,                             // CASE
        S_DEFAULT = 87,                          // DEFAULT
        S_END_SWITCH = 88,                       // END_SWITCH
        S_IN = 89,                               // IN
        S_SOME = 90,                             // SOME
        S_NONE = 91,                             // NONE
        S_FUNCTION = 92,                         // FUNCTION
        S_END_FUNCTION = 93,                     // END_FUNCTION
        S_PROCEDURE = 94,                        // PROCEDURE
        S_END_PROCEDURE = 95,                    // END_PROCEDURE
        S_ENUM = 96,                             // ENUM
        S_END_ENUM = 97,                         // END_ENUM
        S_STRUCT = 98,                           // STRUCT
        S_END_STRUCT = 99,                       // END_STRUCT
        S_SELF = 100,                            // SELF
        S_IMPL = 101,                            // IMPL
        S_END_IMPL = 102,                        // END_IMPL
        S_TRAIT = 103,                           // TRAIT
        S_END_TRAIT = 104,                       // END_TRAIT
        S_RETURN = 105,                          // RETURN
        S_YYACCEPT = 106,                        // $accept
        S_program = 107,                         // program
        S_sum_expr = 108,                        // sum_expr
        S_mult_expr = 109,                       // mult_expr
        S_unary_expr = 110,                      // unary_expr
        S_exp_expr = 111,                        // exp_expr
        S_postfix_expr = 112,                    // postfix_expr
        S_term = 113                             // term
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
      {
        switch (this->kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_sum_expr: // sum_expr
      case symbol_kind::S_mult_expr: // mult_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_exp_expr: // exp_expr
      case symbol_kind::S_postfix_expr: // postfix_expr
      case symbol_kind::S_term: // term
        value.move< Node* > (std::move (that.value));
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
        value.move< NodeType > (std::move (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (std::move (that.value));
        break;

      case symbol_kind::S_CHAR: // CHAR
        value.move< char > (std::move (that.value));
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.move< double > (std::move (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< float > (std::move (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int32_t > (std::move (that.value));
        break;

      case symbol_kind::S_LONG: // LONG
        value.move< int64_t > (std::move (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_CONST_NAME: // CONST_NAME
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_BYTE: // BYTE
        value.move< uint8_t > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Node*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Node*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NodeType&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NodeType& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, char&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const char& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, double&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const double& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, float&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const float& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int32_t&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int32_t& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int64_t&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int64_t& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, uint8_t&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const uint8_t& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_sum_expr: // sum_expr
      case symbol_kind::S_mult_expr: // mult_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_exp_expr: // exp_expr
      case symbol_kind::S_postfix_expr: // postfix_expr
      case symbol_kind::S_term: // term
        value.template destroy< Node* > ();
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
        value.template destroy< NodeType > ();
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.template destroy< bool > ();
        break;

      case symbol_kind::S_CHAR: // CHAR
        value.template destroy< char > ();
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.template destroy< double > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.template destroy< float > ();
        break;

      case symbol_kind::S_INT: // INT
        value.template destroy< int32_t > ();
        break;

      case symbol_kind::S_LONG: // LONG
        value.template destroy< int64_t > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_CONST_NAME: // CONST_NAME
      case symbol_kind::S_STRING: // STRING
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_BYTE: // BYTE
        value.template destroy< uint8_t > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#else
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::YYEOF
                   || (token::YYerror <= tok && tok <= token::YYUNDEF)
                   || (token::DECREMENT <= tok && tok <= token::RETURN));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, NodeType v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const NodeType& v)
        : super_type (token_kind_type (tok), v)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::TYPE_BYTE <= tok && tok <= token::TYPE_OPTION));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, bool v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const bool& v)
        : super_type (token_kind_type (tok), v)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::BOOL);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, char v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const char& v)
        : super_type (token_kind_type (tok), v)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::CHAR);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, double v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const double& v)
        : super_type (token_kind_type (tok), v)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::DOUBLE);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, float v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const float& v)
        : super_type (token_kind_type (tok), v)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::FLOAT);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int32_t v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const int32_t& v)
        : super_type (token_kind_type (tok), v)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::INT);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int64_t v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const int64_t& v)
        : super_type (token_kind_type (tok), v)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::LONG);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const std::string& v)
        : super_type (token_kind_type (tok), v)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::ID <= tok && tok <= token::STRING));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, uint8_t v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const uint8_t& v)
        : super_type (token_kind_type (tok), v)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::BYTE);
#endif
      }
    };

    /// Build a parser object.
    parser (Context& context_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#else
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#else
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#else
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BYTE (uint8_t v)
      {
        return symbol_type (token::BYTE, std::move (v));
      }
#else
      static
      symbol_type
      make_BYTE (const uint8_t& v)
      {
        return symbol_type (token::BYTE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (int32_t v)
      {
        return symbol_type (token::INT, std::move (v));
      }
#else
      static
      symbol_type
      make_INT (const int32_t& v)
      {
        return symbol_type (token::INT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LONG (int64_t v)
      {
        return symbol_type (token::LONG, std::move (v));
      }
#else
      static
      symbol_type
      make_LONG (const int64_t& v)
      {
        return symbol_type (token::LONG, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (float v)
      {
        return symbol_type (token::FLOAT, std::move (v));
      }
#else
      static
      symbol_type
      make_FLOAT (const float& v)
      {
        return symbol_type (token::FLOAT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE (double v)
      {
        return symbol_type (token::DOUBLE, std::move (v));
      }
#else
      static
      symbol_type
      make_DOUBLE (const double& v)
      {
        return symbol_type (token::DOUBLE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL (bool v)
      {
        return symbol_type (token::BOOL, std::move (v));
      }
#else
      static
      symbol_type
      make_BOOL (const bool& v)
      {
        return symbol_type (token::BOOL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (std::string v)
      {
        return symbol_type (token::ID, std::move (v));
      }
#else
      static
      symbol_type
      make_ID (const std::string& v)
      {
        return symbol_type (token::ID, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NAME (std::string v)
      {
        return symbol_type (token::NAME, std::move (v));
      }
#else
      static
      symbol_type
      make_NAME (const std::string& v)
      {
        return symbol_type (token::NAME, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONST_NAME (std::string v)
      {
        return symbol_type (token::CONST_NAME, std::move (v));
      }
#else
      static
      symbol_type
      make_CONST_NAME (const std::string& v)
      {
        return symbol_type (token::CONST_NAME, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v)
      {
        return symbol_type (token::STRING, std::move (v));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v)
      {
        return symbol_type (token::STRING, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHAR (char v)
      {
        return symbol_type (token::CHAR, std::move (v));
      }
#else
      static
      symbol_type
      make_CHAR (const char& v)
      {
        return symbol_type (token::CHAR, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_BYTE (NodeType v)
      {
        return symbol_type (token::TYPE_BYTE, std::move (v));
      }
#else
      static
      symbol_type
      make_TYPE_BYTE (const NodeType& v)
      {
        return symbol_type (token::TYPE_BYTE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_INT (NodeType v)
      {
        return symbol_type (token::TYPE_INT, std::move (v));
      }
#else
      static
      symbol_type
      make_TYPE_INT (const NodeType& v)
      {
        return symbol_type (token::TYPE_INT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_LONG (NodeType v)
      {
        return symbol_type (token::TYPE_LONG, std::move (v));
      }
#else
      static
      symbol_type
      make_TYPE_LONG (const NodeType& v)
      {
        return symbol_type (token::TYPE_LONG, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_FLOAT (NodeType v)
      {
        return symbol_type (token::TYPE_FLOAT, std::move (v));
      }
#else
      static
      symbol_type
      make_TYPE_FLOAT (const NodeType& v)
      {
        return symbol_type (token::TYPE_FLOAT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_DOUBLE (NodeType v)
      {
        return symbol_type (token::TYPE_DOUBLE, std::move (v));
      }
#else
      static
      symbol_type
      make_TYPE_DOUBLE (const NodeType& v)
      {
        return symbol_type (token::TYPE_DOUBLE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_BOOL (NodeType v)
      {
        return symbol_type (token::TYPE_BOOL, std::move (v));
      }
#else
      static
      symbol_type
      make_TYPE_BOOL (const NodeType& v)
      {
        return symbol_type (token::TYPE_BOOL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_STRING (NodeType v)
      {
        return symbol_type (token::TYPE_STRING, std::move (v));
      }
#else
      static
      symbol_type
      make_TYPE_STRING (const NodeType& v)
      {
        return symbol_type (token::TYPE_STRING, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_CHAR (NodeType v)
      {
        return symbol_type (token::TYPE_CHAR, std::move (v));
      }
#else
      static
      symbol_type
      make_TYPE_CHAR (const NodeType& v)
      {
        return symbol_type (token::TYPE_CHAR, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_POINTER (NodeType v)
      {
        return symbol_type (token::TYPE_POINTER, std::move (v));
      }
#else
      static
      symbol_type
      make_TYPE_POINTER (const NodeType& v)
      {
        return symbol_type (token::TYPE_POINTER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_OPTION (NodeType v)
      {
        return symbol_type (token::TYPE_OPTION, std::move (v));
      }
#else
      static
      symbol_type
      make_TYPE_OPTION (const NodeType& v)
      {
        return symbol_type (token::TYPE_OPTION, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DECREMENT ()
      {
        return symbol_type (token::DECREMENT);
      }
#else
      static
      symbol_type
      make_DECREMENT ()
      {
        return symbol_type (token::DECREMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INCREMENT ()
      {
        return symbol_type (token::INCREMENT);
      }
#else
      static
      symbol_type
      make_INCREMENT ()
      {
        return symbol_type (token::INCREMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXP ()
      {
        return symbol_type (token::EXP);
      }
#else
      static
      symbol_type
      make_EXP ()
      {
        return symbol_type (token::EXP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ ()
      {
        return symbol_type (token::EQ);
      }
#else
      static
      symbol_type
      make_EQ ()
      {
        return symbol_type (token::EQ);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND_ATTR ()
      {
        return symbol_type (token::AND_ATTR);
      }
#else
      static
      symbol_type
      make_AND_ATTR ()
      {
        return symbol_type (token::AND_ATTR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR_ATTR ()
      {
        return symbol_type (token::OR_ATTR);
      }
#else
      static
      symbol_type
      make_OR_ATTR ()
      {
        return symbol_type (token::OR_ATTR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LAZY_AND_ATTR ()
      {
        return symbol_type (token::LAZY_AND_ATTR);
      }
#else
      static
      symbol_type
      make_LAZY_AND_ATTR ()
      {
        return symbol_type (token::LAZY_AND_ATTR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LAZY_OR_ATTR ()
      {
        return symbol_type (token::LAZY_OR_ATTR);
      }
#else
      static
      symbol_type
      make_LAZY_OR_ATTR ()
      {
        return symbol_type (token::LAZY_OR_ATTR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD_ATTR ()
      {
        return symbol_type (token::MOD_ATTR);
      }
#else
      static
      symbol_type
      make_MOD_ATTR ()
      {
        return symbol_type (token::MOD_ATTR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XOR_ATTR ()
      {
        return symbol_type (token::XOR_ATTR);
      }
#else
      static
      symbol_type
      make_XOR_ATTR ()
      {
        return symbol_type (token::XOR_ATTR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS_ATTR ()
      {
        return symbol_type (token::PLUS_ATTR);
      }
#else
      static
      symbol_type
      make_PLUS_ATTR ()
      {
        return symbol_type (token::PLUS_ATTR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONCAT_ATTR ()
      {
        return symbol_type (token::CONCAT_ATTR);
      }
#else
      static
      symbol_type
      make_CONCAT_ATTR ()
      {
        return symbol_type (token::CONCAT_ATTR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS_ATTR ()
      {
        return symbol_type (token::MINUS_ATTR);
      }
#else
      static
      symbol_type
      make_MINUS_ATTR ()
      {
        return symbol_type (token::MINUS_ATTR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULT_ATTR ()
      {
        return symbol_type (token::MULT_ATTR);
      }
#else
      static
      symbol_type
      make_MULT_ATTR ()
      {
        return symbol_type (token::MULT_ATTR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV_ATTR ()
      {
        return symbol_type (token::DIV_ATTR);
      }
#else
      static
      symbol_type
      make_DIV_ATTR ()
      {
        return symbol_type (token::DIV_ATTR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND ()
      {
        return symbol_type (token::AND);
      }
#else
      static
      symbol_type
      make_AND ()
      {
        return symbol_type (token::AND);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR ()
      {
        return symbol_type (token::OR);
      }
#else
      static
      symbol_type
      make_OR ()
      {
        return symbol_type (token::OR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REF ()
      {
        return symbol_type (token::REF);
      }
#else
      static
      symbol_type
      make_REF ()
      {
        return symbol_type (token::REF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BAR ()
      {
        return symbol_type (token::BAR);
      }
#else
      static
      symbol_type
      make_BAR ()
      {
        return symbol_type (token::BAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT_EQ ()
      {
        return symbol_type (token::NOT_EQ);
      }
#else
      static
      symbol_type
      make_NOT_EQ ()
      {
        return symbol_type (token::NOT_EQ);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT_EQ ()
      {
        return symbol_type (token::LT_EQ);
      }
#else
      static
      symbol_type
      make_LT_EQ ()
      {
        return symbol_type (token::LT_EQ);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT_EQ ()
      {
        return symbol_type (token::GT_EQ);
      }
#else
      static
      symbol_type
      make_GT_EQ ()
      {
        return symbol_type (token::GT_EQ);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT ()
      {
        return symbol_type (token::LT);
      }
#else
      static
      symbol_type
      make_LT ()
      {
        return symbol_type (token::LT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT ()
      {
        return symbol_type (token::GT);
      }
#else
      static
      symbol_type
      make_GT ()
      {
        return symbol_type (token::GT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT ()
      {
        return symbol_type (token::NOT);
      }
#else
      static
      symbol_type
      make_NOT ()
      {
        return symbol_type (token::NOT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REV ()
      {
        return symbol_type (token::REV);
      }
#else
      static
      symbol_type
      make_REV ()
      {
        return symbol_type (token::REV);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD ()
      {
        return symbol_type (token::MOD);
      }
#else
      static
      symbol_type
      make_MOD ()
      {
        return symbol_type (token::MOD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XOR ()
      {
        return symbol_type (token::XOR);
      }
#else
      static
      symbol_type
      make_XOR ()
      {
        return symbol_type (token::XOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ATTR ()
      {
        return symbol_type (token::ATTR);
      }
#else
      static
      symbol_type
      make_ATTR ()
      {
        return symbol_type (token::ATTR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS ()
      {
        return symbol_type (token::MINUS);
      }
#else
      static
      symbol_type
      make_MINUS ()
      {
        return symbol_type (token::MINUS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS ()
      {
        return symbol_type (token::PLUS);
      }
#else
      static
      symbol_type
      make_PLUS ()
      {
        return symbol_type (token::PLUS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULT ()
      {
        return symbol_type (token::MULT);
      }
#else
      static
      symbol_type
      make_MULT ()
      {
        return symbol_type (token::MULT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV ()
      {
        return symbol_type (token::DIV);
      }
#else
      static
      symbol_type
      make_DIV ()
      {
        return symbol_type (token::DIV);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEW ()
      {
        return symbol_type (token::NEW);
      }
#else
      static
      symbol_type
      make_NEW ()
      {
        return symbol_type (token::NEW);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR ()
      {
        return symbol_type (token::VAR);
      }
#else
      static
      symbol_type
      make_VAR ()
      {
        return symbol_type (token::VAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONST ()
      {
        return symbol_type (token::CONST);
      }
#else
      static
      symbol_type
      make_CONST ()
      {
        return symbol_type (token::CONST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RANGE ()
      {
        return symbol_type (token::RANGE);
      }
#else
      static
      symbol_type
      make_RANGE ()
      {
        return symbol_type (token::RANGE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT ()
      {
        return symbol_type (token::DOT);
      }
#else
      static
      symbol_type
      make_DOT ()
      {
        return symbol_type (token::DOT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA ()
      {
        return symbol_type (token::COMMA);
      }
#else
      static
      symbol_type
      make_COMMA ()
      {
        return symbol_type (token::COMMA);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON ()
      {
        return symbol_type (token::COLON);
      }
#else
      static
      symbol_type
      make_COLON ()
      {
        return symbol_type (token::COLON);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE_COLON ()
      {
        return symbol_type (token::DOUBLE_COLON);
      }
#else
      static
      symbol_type
      make_DOUBLE_COLON ()
      {
        return symbol_type (token::DOUBLE_COLON);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON ()
      {
        return symbol_type (token::SEMICOLON);
      }
#else
      static
      symbol_type
      make_SEMICOLON ()
      {
        return symbol_type (token::SEMICOLON);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_PAREN ()
      {
        return symbol_type (token::LEFT_PAREN);
      }
#else
      static
      symbol_type
      make_LEFT_PAREN ()
      {
        return symbol_type (token::LEFT_PAREN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_PAREN ()
      {
        return symbol_type (token::RIGHT_PAREN);
      }
#else
      static
      symbol_type
      make_RIGHT_PAREN ()
      {
        return symbol_type (token::RIGHT_PAREN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_BRACKET ()
      {
        return symbol_type (token::LEFT_BRACKET);
      }
#else
      static
      symbol_type
      make_LEFT_BRACKET ()
      {
        return symbol_type (token::LEFT_BRACKET);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_BRACKET ()
      {
        return symbol_type (token::RIGHT_BRACKET);
      }
#else
      static
      symbol_type
      make_RIGHT_BRACKET ()
      {
        return symbol_type (token::RIGHT_BRACKET);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_BRACE ()
      {
        return symbol_type (token::LEFT_BRACE);
      }
#else
      static
      symbol_type
      make_LEFT_BRACE ()
      {
        return symbol_type (token::LEFT_BRACE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_BRACE ()
      {
        return symbol_type (token::RIGHT_BRACE);
      }
#else
      static
      symbol_type
      make_RIGHT_BRACE ()
      {
        return symbol_type (token::RIGHT_BRACE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF ()
      {
        return symbol_type (token::IF);
      }
#else
      static
      symbol_type
      make_IF ()
      {
        return symbol_type (token::IF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_IF ()
      {
        return symbol_type (token::END_IF);
      }
#else
      static
      symbol_type
      make_END_IF ()
      {
        return symbol_type (token::END_IF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THEN ()
      {
        return symbol_type (token::THEN);
      }
#else
      static
      symbol_type
      make_THEN ()
      {
        return symbol_type (token::THEN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELIF ()
      {
        return symbol_type (token::ELIF);
      }
#else
      static
      symbol_type
      make_ELIF ()
      {
        return symbol_type (token::ELIF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE ()
      {
        return symbol_type (token::ELSE);
      }
#else
      static
      symbol_type
      make_ELSE ()
      {
        return symbol_type (token::ELSE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR ()
      {
        return symbol_type (token::FOR);
      }
#else
      static
      symbol_type
      make_FOR ()
      {
        return symbol_type (token::FOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE ()
      {
        return symbol_type (token::WHILE);
      }
#else
      static
      symbol_type
      make_WHILE ()
      {
        return symbol_type (token::WHILE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_WHILE ()
      {
        return symbol_type (token::END_WHILE);
      }
#else
      static
      symbol_type
      make_END_WHILE ()
      {
        return symbol_type (token::END_WHILE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REPEAT ()
      {
        return symbol_type (token::REPEAT);
      }
#else
      static
      symbol_type
      make_REPEAT ()
      {
        return symbol_type (token::REPEAT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNTIL ()
      {
        return symbol_type (token::UNTIL);
      }
#else
      static
      symbol_type
      make_UNTIL ()
      {
        return symbol_type (token::UNTIL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_FOR ()
      {
        return symbol_type (token::END_FOR);
      }
#else
      static
      symbol_type
      make_END_FOR ()
      {
        return symbol_type (token::END_FOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK ()
      {
        return symbol_type (token::BREAK);
      }
#else
      static
      symbol_type
      make_BREAK ()
      {
        return symbol_type (token::BREAK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTINUE ()
      {
        return symbol_type (token::CONTINUE);
      }
#else
      static
      symbol_type
      make_CONTINUE ()
      {
        return symbol_type (token::CONTINUE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SWITCH ()
      {
        return symbol_type (token::SWITCH);
      }
#else
      static
      symbol_type
      make_SWITCH ()
      {
        return symbol_type (token::SWITCH);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CASE ()
      {
        return symbol_type (token::CASE);
      }
#else
      static
      symbol_type
      make_CASE ()
      {
        return symbol_type (token::CASE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFAULT ()
      {
        return symbol_type (token::DEFAULT);
      }
#else
      static
      symbol_type
      make_DEFAULT ()
      {
        return symbol_type (token::DEFAULT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_SWITCH ()
      {
        return symbol_type (token::END_SWITCH);
      }
#else
      static
      symbol_type
      make_END_SWITCH ()
      {
        return symbol_type (token::END_SWITCH);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IN ()
      {
        return symbol_type (token::IN);
      }
#else
      static
      symbol_type
      make_IN ()
      {
        return symbol_type (token::IN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SOME ()
      {
        return symbol_type (token::SOME);
      }
#else
      static
      symbol_type
      make_SOME ()
      {
        return symbol_type (token::SOME);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NONE ()
      {
        return symbol_type (token::NONE);
      }
#else
      static
      symbol_type
      make_NONE ()
      {
        return symbol_type (token::NONE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNCTION ()
      {
        return symbol_type (token::FUNCTION);
      }
#else
      static
      symbol_type
      make_FUNCTION ()
      {
        return symbol_type (token::FUNCTION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_FUNCTION ()
      {
        return symbol_type (token::END_FUNCTION);
      }
#else
      static
      symbol_type
      make_END_FUNCTION ()
      {
        return symbol_type (token::END_FUNCTION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PROCEDURE ()
      {
        return symbol_type (token::PROCEDURE);
      }
#else
      static
      symbol_type
      make_PROCEDURE ()
      {
        return symbol_type (token::PROCEDURE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_PROCEDURE ()
      {
        return symbol_type (token::END_PROCEDURE);
      }
#else
      static
      symbol_type
      make_END_PROCEDURE ()
      {
        return symbol_type (token::END_PROCEDURE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENUM ()
      {
        return symbol_type (token::ENUM);
      }
#else
      static
      symbol_type
      make_ENUM ()
      {
        return symbol_type (token::ENUM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_ENUM ()
      {
        return symbol_type (token::END_ENUM);
      }
#else
      static
      symbol_type
      make_END_ENUM ()
      {
        return symbol_type (token::END_ENUM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRUCT ()
      {
        return symbol_type (token::STRUCT);
      }
#else
      static
      symbol_type
      make_STRUCT ()
      {
        return symbol_type (token::STRUCT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_STRUCT ()
      {
        return symbol_type (token::END_STRUCT);
      }
#else
      static
      symbol_type
      make_END_STRUCT ()
      {
        return symbol_type (token::END_STRUCT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SELF ()
      {
        return symbol_type (token::SELF);
      }
#else
      static
      symbol_type
      make_SELF ()
      {
        return symbol_type (token::SELF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IMPL ()
      {
        return symbol_type (token::IMPL);
      }
#else
      static
      symbol_type
      make_IMPL ()
      {
        return symbol_type (token::IMPL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_IMPL ()
      {
        return symbol_type (token::END_IMPL);
      }
#else
      static
      symbol_type
      make_END_IMPL ()
      {
        return symbol_type (token::END_IMPL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRAIT ()
      {
        return symbol_type (token::TRAIT);
      }
#else
      static
      symbol_type
      make_TRAIT ()
      {
        return symbol_type (token::TRAIT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_TRAIT ()
      {
        return symbol_type (token::END_TRAIT);
      }
#else
      static
      symbol_type
      make_END_TRAIT ()
      {
        return symbol_type (token::END_TRAIT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN ()
      {
        return symbol_type (token::RETURN);
      }
#else
      static
      symbol_type
      make_RETURN ()
      {
        return symbol_type (token::RETURN);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const signed char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 50,     ///< Last index in yytable_.
      yynnts_ = 8,  ///< Number of nonterminal symbols.
      yyfinal_ = 28 ///< Termination state number.
    };


    // User arguments.
    Context& context;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105
    };
    // Last valid token kind.
    const int code_max = 360;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_sum_expr: // sum_expr
      case symbol_kind::S_mult_expr: // mult_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_exp_expr: // exp_expr
      case symbol_kind::S_postfix_expr: // postfix_expr
      case symbol_kind::S_term: // term
        value.copy< Node* > (YY_MOVE (that.value));
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
        value.copy< NodeType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR: // CHAR
        value.copy< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.copy< int32_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LONG: // LONG
        value.copy< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_CONST_NAME: // CONST_NAME
      case symbol_kind::S_STRING: // STRING
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BYTE: // BYTE
        value.copy< uint8_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_sum_expr: // sum_expr
      case symbol_kind::S_mult_expr: // mult_expr
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_exp_expr: // exp_expr
      case symbol_kind::S_postfix_expr: // postfix_expr
      case symbol_kind::S_term: // term
        value.move< Node* > (YY_MOVE (s.value));
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
        value.move< NodeType > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_CHAR: // CHAR
        value.move< char > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< float > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int32_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_LONG: // LONG
        value.move< int64_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_CONST_NAME: // CONST_NAME
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_BYTE: // BYTE
        value.move< uint8_t > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  inline
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


} // yy
#line 3502 "grammar/build/syntax.tab.hh"




#endif // !YY_YY_GRAMMAR_BUILD_SYNTAX_TAB_HH_INCLUDED
