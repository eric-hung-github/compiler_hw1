/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.y"

#define Trace(t)        printf(t)
#include <iostream>
#include <fstream>
#include <string>
#include "symbol_table.hpp"
#include "lex.yy.cpp"
using namespace std;
SymbolTableStack symbolTableStack =  SymbolTableStack();


int yylex();


void yyerror(string s)
{
    cout<<"Error : " << s <<endl;
    exit(-1);
}

int symbolTableSize = -1;
int returnType;
int local_base = 0;
int label_no = 0;
vector<Value* > arguments;
bool programIsDeclare = false;
bool blockIsDeclare =false;

#line 100 "y.tab.cpp"

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

#include "y.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_C_STR = 4,                      /* C_STR  */
  YYSYMBOL_C_INT = 5,                      /* C_INT  */
  YYSYMBOL_TRUE = 6,                       /* TRUE  */
  YYSYMBOL_FALSE = 7,                      /* FALSE  */
  YYSYMBOL_C_FLOAT = 8,                    /* C_FLOAT  */
  YYSYMBOL_SEMICOLON = 9,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 10,                     /* COMMA  */
  YYSYMBOL_FAN = 11,                       /* FAN  */
  YYSYMBOL_MO = 12,                        /* MO  */
  YYSYMBOL_ARROW = 13,                     /* ARROW  */
  YYSYMBOL_DOT = 14,                       /* DOT  */
  YYSYMBOL_LB = 15,                        /* LB  */
  YYSYMBOL_RB = 16,                        /* RB  */
  YYSYMBOL_LCB = 17,                       /* LCB  */
  YYSYMBOL_RCB = 18,                       /* RCB  */
  YYSYMBOL_LSB = 19,                       /* LSB  */
  YYSYMBOL_RSB = 20,                       /* RSB  */
  YYSYMBOL_ADD = 21,                       /* ADD  */
  YYSYMBOL_SUB = 22,                       /* SUB  */
  YYSYMBOL_MUL = 23,                       /* MUL  */
  YYSYMBOL_DIV = 24,                       /* DIV  */
  YYSYMBOL_MOD = 25,                       /* MOD  */
  YYSYMBOL_BT = 26,                        /* BT  */
  YYSYMBOL_ST = 27,                        /* ST  */
  YYSYMBOL_SET = 28,                       /* SET  */
  YYSYMBOL_BET = 29,                       /* BET  */
  YYSYMBOL_EQL = 30,                       /* EQL  */
  YYSYMBOL_NEQ = 31,                       /* NEQ  */
  YYSYMBOL_AND = 32,                       /* AND  */
  YYSYMBOL_OR = 33,                        /* OR  */
  YYSYMBOL_NOT = 34,                       /* NOT  */
  YYSYMBOL_ASIGN = 35,                     /* ASIGN  */
  YYSYMBOL_ADDASIGN = 36,                  /* ADDASIGN  */
  YYSYMBOL_SUBASIGN = 37,                  /* SUBASIGN  */
  YYSYMBOL_MULASIGN = 38,                  /* MULASIGN  */
  YYSYMBOL_DIVASIGN = 39,                  /* DIVASIGN  */
  YYSYMBOL_BOOL = 40,                      /* BOOL  */
  YYSYMBOL_BREAK = 41,                     /* BREAK  */
  YYSYMBOL_CHAR = 42,                      /* CHAR  */
  YYSYMBOL_CASE = 43,                      /* CASE  */
  YYSYMBOL_CLASS = 44,                     /* CLASS  */
  YYSYMBOL_CONTINUE = 45,                  /* CONTINUE  */
  YYSYMBOL_DECLARE = 46,                   /* DECLARE  */
  YYSYMBOL_DO = 47,                        /* DO  */
  YYSYMBOL_ELSE = 48,                      /* ELSE  */
  YYSYMBOL_EXIT = 49,                      /* EXIT  */
  YYSYMBOL_FLOAT = 50,                     /* FLOAT  */
  YYSYMBOL_FOR = 51,                       /* FOR  */
  YYSYMBOL_FUN = 52,                       /* FUN  */
  YYSYMBOL_IF = 53,                        /* IF  */
  YYSYMBOL_INT = 54,                       /* INT  */
  YYSYMBOL_LOOP = 55,                      /* LOOP  */
  YYSYMBOL_PRINT = 56,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 57,                   /* PRINTLN  */
  YYSYMBOL_RETURN = 58,                    /* RETURN  */
  YYSYMBOL_STRING = 59,                    /* STRING  */
  YYSYMBOL_VAL = 60,                       /* VAL  */
  YYSYMBOL_VAR = 61,                       /* VAR  */
  YYSYMBOL_WHILE = 62,                     /* WHILE  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_program = 64,                   /* program  */
  YYSYMBOL_program_begin = 65,             /* program_begin  */
  YYSYMBOL_program_end = 66,               /* program_end  */
  YYSYMBOL_program_contents = 67,          /* program_contents  */
  YYSYMBOL_program_content = 68,           /* program_content  */
  YYSYMBOL_type = 69,                      /* type  */
  YYSYMBOL_va_declaration = 70,            /* va_declaration  */
  YYSYMBOL_const_declaration = 71,         /* const_declaration  */
  YYSYMBOL_var_declaration = 72,           /* var_declaration  */
  YYSYMBOL_array_declaration = 73,         /* array_declaration  */
  YYSYMBOL_fun_declaration = 74,           /* fun_declaration  */
  YYSYMBOL_proc_declaration = 75,          /* proc_declaration  */
  YYSYMBOL_formal_argument_list = 76,      /* formal_argument_list  */
  YYSYMBOL_formal_arguments = 77,          /* formal_arguments  */
  YYSYMBOL_formal_argument = 78,           /* formal_argument  */
  YYSYMBOL_statement = 79,                 /* statement  */
  YYSYMBOL_simple_statement = 80,          /* simple_statement  */
  YYSYMBOL_const_expression = 81,          /* const_expression  */
  YYSYMBOL_int_expression = 82,            /* int_expression  */
  YYSYMBOL_bool_expression = 83,           /* bool_expression  */
  YYSYMBOL_expression = 84,                /* expression  */
  YYSYMBOL_math_operator = 85,             /* math_operator  */
  YYSYMBOL_logic_operator = 86,            /* logic_operator  */
  YYSYMBOL_bit_operator = 87,              /* bit_operator  */
  YYSYMBOL_components = 88,                /* components  */
  YYSYMBOL_literal_constant = 89,          /* literal_constant  */
  YYSYMBOL_c_bool = 90,                    /* c_bool  */
  YYSYMBOL_var_name = 91,                  /* var_name  */
  YYSYMBOL_array_refer = 92,               /* array_refer  */
  YYSYMBOL_block = 93,                     /* block  */
  YYSYMBOL_block_contents = 94,            /* block_contents  */
  YYSYMBOL_block_content = 95,             /* block_content  */
  YYSYMBOL_condition_statement = 96,       /* condition_statement  */
  YYSYMBOL_loop_statement = 97,            /* loop_statement  */
  YYSYMBOL_block_or_simple_statement = 98, /* block_or_simple_statement  */
  YYSYMBOL_fun_invoc = 99,                 /* fun_invoc  */
  YYSYMBOL_proc_invoc = 100,               /* proc_invoc  */
  YYSYMBOL_comma_separated_expressions = 101, /* comma_separated_expressions  */
  YYSYMBOL_num = 102                       /* num  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   226

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    75,    75,    78,    92,    99,   100,   104,   105,   106,
     110,   114,   118,   122,   130,   131,   132,   135,   144,   160,
     167,   176,   190,   201,   205,   208,   211,   212,   213,   217,
     218,   221,   225,   226,   227,   228,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   243,   249,   255,   261,   265,
     269,   273,   277,   288,   289,   290,   291,   294,   295,   296,
     297,   298,   299,   302,   303,   304,   308,   312,   316,   320,
     326,   332,   338,   344,   352,   353,   356,   359,   363,   366,
     367,   368,   371,   372,   376,   377,   381,   382,   385,   386,
     390,   393,   396,   397,   401
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "C_STR", "C_INT",
  "TRUE", "FALSE", "C_FLOAT", "SEMICOLON", "COMMA", "FAN", "MO", "ARROW",
  "DOT", "LB", "RB", "LCB", "RCB", "LSB", "RSB", "ADD", "SUB", "MUL",
  "DIV", "MOD", "BT", "ST", "SET", "BET", "EQL", "NEQ", "AND", "OR", "NOT",
  "ASIGN", "ADDASIGN", "SUBASIGN", "MULASIGN", "DIVASIGN", "BOOL", "BREAK",
  "CHAR", "CASE", "CLASS", "CONTINUE", "DECLARE", "DO", "ELSE", "EXIT",
  "FLOAT", "FOR", "FUN", "IF", "INT", "LOOP", "PRINT", "PRINTLN", "RETURN",
  "STRING", "VAL", "VAR", "WHILE", "$accept", "program", "program_begin",
  "program_end", "program_contents", "program_content", "type",
  "va_declaration", "const_declaration", "var_declaration",
  "array_declaration", "fun_declaration", "proc_declaration",
  "formal_argument_list", "formal_arguments", "formal_argument",
  "statement", "simple_statement", "const_expression", "int_expression",
  "bool_expression", "expression", "math_operator", "logic_operator",
  "bit_operator", "components", "literal_constant", "c_bool", "var_name",
  "array_refer", "block", "block_contents", "block_content",
  "condition_statement", "loop_statement", "block_or_simple_statement",
  "fun_invoc", "proc_invoc", "comma_separated_expressions", "num", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -34,     8,    13,   -11,     4,  -122,    20,    33,    34,    26,
     -11,  -122,  -122,  -122,  -122,  -122,  -122,  -122,    30,    -9,
      -6,  -122,  -122,  -122,    49,   -32,   147,   -32,   147,    41,
      50,  -122,    55,  -122,  -122,  -122,  -122,    39,    90,  -122,
    -122,  -122,  -122,  -122,   147,  -122,   183,  -122,  -122,  -122,
    -122,  -122,  -122,   -10,  -122,   -32,    31,    49,   147,   147,
     147,   192,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,   147,   147,   147,    76,   147,
    -122,   -32,    11,  -122,  -122,    73,  -122,    89,    79,    83,
     183,   183,   183,   183,  -122,    84,  -122,    91,     5,    99,
     122,   121,   127,   153,   123,  -122,  -122,  -122,    88,    11,
    -122,  -122,  -122,    49,   147,  -122,  -122,  -122,  -122,   147,
     147,   147,   136,   147,   147,   183,   147,   183,    36,   183,
     147,  -122,  -122,  -122,  -122,   124,   125,   183,    76,   128,
     183,   150,   169,   130,  -122,   106,   133,    44,  -122,  -122,
      44,   147,   134,     0,  -122,  -122,   114,  -122,   183,    76,
      44,   148,  -122,    44,  -122
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       6,     7,    14,    15,    16,     8,     9,     3,     0,     0,
      19,     4,     2,     5,    28,     0,     0,     0,     0,     0,
       0,    27,    30,    13,    11,    10,    12,     0,    76,    72,
      70,    74,    75,    71,     0,    17,    45,    52,    66,    73,
      67,    69,    68,    20,    22,     0,     0,     0,     0,     0,
       0,    48,    55,    56,    53,    54,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,     0,
      31,     0,    81,    25,    26,    30,    18,    93,     0,     0,
      46,    49,    50,    51,    94,     0,    21,     0,     0,     0,
       0,     0,     0,    43,     0,    82,    83,    32,     0,    80,
      33,    34,    35,     0,     0,    90,    77,    23,    24,     0,
       0,     0,     0,     0,     0,    39,     0,    41,    76,    44,
       0,    78,    79,    29,    92,     0,     0,    36,     0,     0,
      47,     0,     0,     0,    91,     0,     0,     0,    38,    40,
       0,     0,     0,     0,    89,    88,    84,    86,    37,     0,
       0,     0,    85,     0,    87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,  -122,  -122,   155,  -122,   -25,   -81,  -122,  -122,
    -122,  -122,  -122,  -122,   -53,   139,  -122,   -75,   -16,    47,
      38,   -44,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
     -51,    61,  -122,  -122,  -122,   -72,  -122,  -122,   -29,  -121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    22,     9,    10,    37,    11,    12,    13,
      14,    15,    16,    30,    31,    85,   106,   154,    45,    89,
     139,    46,    75,    76,    77,    47,    48,    49,    50,    51,
     155,   108,   109,   110,   111,   156,    52,   112,    88,    95
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,   105,    53,    25,    84,    83,    27,   107,    33,    78,
       1,     4,    54,     5,    98,    87,    90,   146,    34,   120,
     119,    17,    35,    18,   120,    79,    26,    36,   105,    28,
      80,    91,    92,    93,   107,   121,    19,    20,   161,   -42,
     121,     6,    86,    81,    21,    24,   118,   153,    82,     7,
       8,    59,    29,    55,   -42,    60,    97,   125,   127,   129,
     133,    82,    99,    96,   100,    57,    56,   101,   102,   103,
      87,     7,     8,   104,    58,    87,    90,   137,   157,   140,
     141,    94,   142,   113,   -42,   134,   140,   -42,   162,   -42,
     135,   164,   -42,   -42,   -42,   115,   -42,   -42,   -42,   114,
     101,   102,   103,   116,   117,    59,   131,   158,    82,    60,
      62,    63,    64,    65,   122,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    38,    39,    40,    41,    42,    43,
      38,    39,    40,    41,    42,    43,   124,   123,   130,   138,
     144,   151,   126,    44,   147,   145,   150,   152,   159,    44,
      38,    39,    40,    41,    42,    43,   128,    39,    40,    41,
      42,    43,   160,    32,   163,    23,   148,   136,   143,    44,
     132,    62,    63,    64,    65,    44,    66,    67,    68,    69,
      70,    71,    72,    73,    74,   149,     0,     0,     0,     0,
      62,    63,    64,    65,     0,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    62,    63,    64,    65,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    66,    67,
      68,    69,    70,    71,    72,    73,    74
};

static const yytype_int16 yycheck[] =
{
      44,    82,    27,    12,    57,    56,    12,    82,    40,    19,
      44,     3,    28,     0,     3,    59,    60,   138,    50,    19,
      15,    17,    54,     3,    19,    35,    35,    59,   109,    35,
      55,    75,    76,    77,   109,    35,     3,     3,   159,     3,
      35,    52,    58,    12,    18,    15,    97,     3,    17,    60,
      61,    15,     3,    12,    18,    19,    81,   101,   102,   103,
     113,    17,    51,    79,    53,    10,    16,    56,    57,    58,
     114,    60,    61,    62,    35,   119,   120,   121,   150,   123,
     124,     5,   126,    10,    48,   114,   130,    51,   160,    53,
     119,   163,    56,    57,    58,    16,    60,    61,    62,    10,
      56,    57,    58,    20,    20,    15,    18,   151,    17,    19,
      21,    22,    23,    24,    15,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,    15,    15,    15,     3,
      16,    35,    15,    22,    16,    20,    16,    14,    14,    22,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,    48,    24,    16,    10,    16,   120,   130,    22,
     109,    21,    22,    23,    24,    22,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    16,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    26,    27,
      28,    29,    30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    64,    65,     3,     0,    52,    60,    61,    67,
      68,    70,    71,    72,    73,    74,    75,    17,     3,     3,
       3,    18,    66,    67,    15,    12,    35,    12,    35,     3,
      76,    77,    78,    40,    50,    54,    59,    69,     3,     4,
       5,     6,     7,     8,    22,    81,    84,    88,    89,    90,
      91,    92,    99,    69,    81,    12,    16,    10,    35,    15,
      19,    84,    21,    22,    23,    24,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    85,    86,    87,    19,    35,
      69,    12,    17,    93,    77,    78,    81,    84,   101,    82,
      84,    84,    84,    84,     5,   102,    81,    69,     3,    51,
      53,    56,    57,    58,    62,    70,    79,    80,    94,    95,
      96,    97,   100,    10,    10,    16,    20,    20,    93,    15,
      19,    35,    15,    15,    15,    84,    15,    84,     3,    84,
      15,    18,    94,    77,   101,   101,    82,    84,     3,    83,
      84,    84,    84,    83,    16,    20,   102,    16,    16,    16,
      16,    35,    14,     3,    80,    93,    98,    98,    84,    14,
      48,   102,    98,    16,    98
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    66,    67,    67,    68,    68,    68,
      69,    69,    69,    69,    70,    70,    70,    71,    71,    72,
      72,    72,    72,    73,    74,    75,    76,    76,    76,    77,
      77,    78,    79,    79,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    81,    82,    83,    84,    84,
      84,    84,    84,    85,    85,    85,    85,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    88,    88,    88,    88,
      89,    89,    89,    89,    90,    90,    91,    92,    93,    94,
      94,    94,    95,    95,    96,    96,    97,    97,    98,    98,
      99,   100,   101,   101,   102
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     6,     2,
       4,     6,     4,     7,     8,     6,     3,     1,     0,     3,
       1,     3,     1,     1,     1,     1,     3,     6,     4,     2,
       4,     2,     2,     1,     2,     1,     1,     1,     2,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     2,
       1,     0,     1,     1,     5,     7,     5,     9,     1,     1,
       4,     4,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* program_begin: CLASS ID LCB  */
#line 79 "yacc.y"
{
    programIsDeclare = true;
    symbolTableStack.push();
    symbolTableSize++;
    symbolTableStack.tableStack[symbolTableSize].name = *(yyvsp[-1].str_value);

    Symbol* symbol = new Symbol();
    symbol->name = *(yyvsp[-1].str_value);
    symbol->type = ID_program;
    symbolTableStack.tableStack[symbolTableSize].insert(symbol);

}
#line 1333 "y.tab.cpp"
    break;

  case 4: /* program_end: RCB  */
#line 93 "yacc.y"
{
    programIsDeclare = false;
    symbolTableStack.pop();
    symbolTableSize--;
}
#line 1343 "y.tab.cpp"
    break;

  case 10: /* type: INT  */
#line 111 "yacc.y"
        {
                (yyval.type) = Value_int;
        }
#line 1351 "y.tab.cpp"
    break;

  case 11: /* type: FLOAT  */
#line 115 "yacc.y"
        {
                (yyval.type) = Value_float;
        }
#line 1359 "y.tab.cpp"
    break;

  case 12: /* type: STRING  */
#line 119 "yacc.y"
        {
                (yyval.type) = Value_string;
        }
#line 1367 "y.tab.cpp"
    break;

  case 13: /* type: BOOL  */
#line 123 "yacc.y"
        {
                (yyval.type) = Value_boolean;
        }
#line 1375 "y.tab.cpp"
    break;

  case 17: /* const_declaration: VAL ID ASIGN const_expression  */
#line 136 "yacc.y"
                        {
                                Symbol* symbol = new Symbol();
                                symbol->value = (yyvsp[0].value);
                                symbol->type = ID_constant;
                                symbol->name = *(yyvsp[-2].str_value);        

                                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
#line 1388 "y.tab.cpp"
    break;

  case 18: /* const_declaration: VAL ID MO type ASIGN const_expression  */
#line 145 "yacc.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->value = (yyvsp[0].value);
                                symbol->type = ID_constant;
                                symbol->name = *(yyvsp[-4].str_value);    

                                if(symbol->value->valueType!=(yyvsp[-2].type)){
                                        printf("type error");
                                        exit(-1);
                                }

                                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
#line 1406 "y.tab.cpp"
    break;

  case 19: /* var_declaration: VAR ID  */
#line 161 "yacc.y"
                        {
                                Symbol* symbol = new Symbol();
                                symbol->name = *(yyvsp[0].str_value);        

                                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
#line 1417 "y.tab.cpp"
    break;

  case 20: /* var_declaration: VAR ID MO type  */
#line 168 "yacc.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->type = (yyvsp[0].type);
                                symbol->type = ID_constant;
                                symbol->name = *(yyvsp[-2].str_value);    

                                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
#line 1430 "y.tab.cpp"
    break;

  case 21: /* var_declaration: VAR ID MO type ASIGN const_expression  */
#line 177 "yacc.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->value = (yyvsp[0].value);
                                symbol->type = ID_constant;
                                symbol->name = *(yyvsp[-4].str_value);    

                                if(symbol->value->valueType!=(yyvsp[-2].type)){
                                        printf("type error");
                                        exit(-1);
                                }

                                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
#line 1448 "y.tab.cpp"
    break;

  case 22: /* var_declaration: VAR ID ASIGN const_expression  */
#line 191 "yacc.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->value = (yyvsp[0].value);
                                symbol->type = ID_constant;
                                symbol->name = *(yyvsp[-2].str_value);    

                                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
#line 1461 "y.tab.cpp"
    break;

  case 45: /* const_expression: expression  */
#line 244 "yacc.y"
                        {
                                (yyval.value)=(yyvsp[0].value);
                        }
#line 1469 "y.tab.cpp"
    break;

  case 46: /* int_expression: expression  */
#line 250 "yacc.y"
                        {
                                (yyval.value)=(yyvsp[0].value);
                        }
#line 1477 "y.tab.cpp"
    break;

  case 47: /* bool_expression: expression  */
#line 256 "yacc.y"
                        {
                                (yyval.value)=(yyvsp[0].value);
                        }
#line 1485 "y.tab.cpp"
    break;

  case 48: /* expression: SUB expression  */
#line 262 "yacc.y"
                {
                        (yyval.value)=(yyvsp[0].value);
                }
#line 1493 "y.tab.cpp"
    break;

  case 49: /* expression: expression math_operator expression  */
#line 266 "yacc.y"
                {
                        (yyval.value)=(yyvsp[-2].value);
                }
#line 1501 "y.tab.cpp"
    break;

  case 50: /* expression: expression logic_operator expression  */
#line 270 "yacc.y"
                {
                        (yyval.value)=(yyvsp[-2].value);
                }
#line 1509 "y.tab.cpp"
    break;

  case 51: /* expression: expression bit_operator expression  */
#line 274 "yacc.y"
                {
                        (yyval.value)=(yyvsp[-2].value);
                }
#line 1517 "y.tab.cpp"
    break;

  case 52: /* expression: components  */
#line 278 "yacc.y"
                {
                        (yyval.value)=(yyvsp[0].value);
                }
#line 1525 "y.tab.cpp"
    break;

  case 66: /* components: literal_constant  */
#line 309 "yacc.y"
                {
                        // $$=$1;
                }
#line 1533 "y.tab.cpp"
    break;

  case 67: /* components: var_name  */
#line 313 "yacc.y"
                {
                        // $$=$1;
                }
#line 1541 "y.tab.cpp"
    break;

  case 68: /* components: fun_invoc  */
#line 317 "yacc.y"
                {
                        // $$=$1;
                }
#line 1549 "y.tab.cpp"
    break;

  case 69: /* components: array_refer  */
#line 321 "yacc.y"
                {
                        // $$=$1;
                }
#line 1557 "y.tab.cpp"
    break;

  case 70: /* literal_constant: C_INT  */
#line 327 "yacc.y"
                        {
                                Value* value=new Value();
                                value->valueType = Value_int;
                                (yyval.value)=value;
                        }
#line 1567 "y.tab.cpp"
    break;

  case 71: /* literal_constant: C_FLOAT  */
#line 333 "yacc.y"
                        {
                                Value* value=new Value();
                                value->valueType = Value_float;
                                (yyval.value)=value;
                        }
#line 1577 "y.tab.cpp"
    break;

  case 72: /* literal_constant: C_STR  */
#line 339 "yacc.y"
                        {
                                Value* value=new Value();
                                value->valueType = Value_string;
                                (yyval.value)=value;
                        }
#line 1587 "y.tab.cpp"
    break;

  case 73: /* literal_constant: c_bool  */
#line 345 "yacc.y"
                        {
                                Value* value=new Value();
                                value->valueType = Value_boolean;
                                (yyval.value)=value;
                        }
#line 1597 "y.tab.cpp"
    break;


#line 1601 "y.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 404 "yacc.y"


int main( int argc, char **argv )
{
	if( argc != 2 ) {
		fprintf(  stdout,  "Usage:  ./parser  [filename]\n"  );
		exit(0);
	}

	FILE *fp = fopen( argv[1], "r" );

	if( fp == NULL )  {
		fprintf( stdout, "Open  file  error\n" );
		exit(-1);
	}

	yyin = fp;
	yyparse();

	fprintf( stdout, "\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	exit(0);
}
