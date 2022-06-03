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
#line 1 "parser.y"

#include <iostream>
#include <fstream>
#include <string>
#include "symbol_table.hpp"
#include "lex.yy.cpp"
using namespace std;
#define Trace(t)        cout<<t<<endl;

SymbolTableStack symbolTableStack =  SymbolTableStack();
fstream jasm_file;
#define jasm(t)        jasm_file<<t;


// a=a+b segmentation fault

int yylex();


void yyerror(string s)
{
    cout<<"Error : " << s <<endl;
    exit(-1);
}


#line 98 "y.tab.cpp"

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
  YYSYMBOL_type_define = 69,               /* type_define  */
  YYSYMBOL_va_declaration = 70,            /* va_declaration  */
  YYSYMBOL_const_declaration = 71,         /* const_declaration  */
  YYSYMBOL_var_declaration = 72,           /* var_declaration  */
  YYSYMBOL_array_declaration = 73,         /* array_declaration  */
  YYSYMBOL_fun_declaration = 74,           /* fun_declaration  */
  YYSYMBOL_75_1 = 75,                      /* $@1  */
  YYSYMBOL_proc_declaration = 76,          /* proc_declaration  */
  YYSYMBOL_formal_argument_list = 77,      /* formal_argument_list  */
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
  YYSYMBOL_var_refer = 91,                 /* var_refer  */
  YYSYMBOL_arr_refer = 92,                 /* arr_refer  */
  YYSYMBOL_block = 93,                     /* block  */
  YYSYMBOL_block_begin = 94,               /* block_begin  */
  YYSYMBOL_block_end = 95,                 /* block_end  */
  YYSYMBOL_block_contents = 96,            /* block_contents  */
  YYSYMBOL_block_content = 97,             /* block_content  */
  YYSYMBOL_condition_statement = 98,       /* condition_statement  */
  YYSYMBOL_loop_statement = 99,            /* loop_statement  */
  YYSYMBOL_block_or_simple_statement = 100, /* block_or_simple_statement  */
  YYSYMBOL_fun_invoc = 101,                /* fun_invoc  */
  YYSYMBOL_proc_invoc = 102,               /* proc_invoc  */
  YYSYMBOL_comma_separated_expressions = 103, /* comma_separated_expressions  */
  YYSYMBOL_num = 104                       /* num  */
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
#define YYLAST   301

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

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
       0,    75,    75,    80,    91,    95,    96,   100,   101,   102,
     106,   110,   114,   118,   125,   126,   127,   130,   139,   155,
     164,   173,   187,   198,   211,   210,   226,   237,   249,   260,
     261,   264,   276,   277,   278,   279,   282,   296,   310,   311,
     312,   313,   314,   315,   316,   320,   326,   332,   338,   342,
     346,   350,   357,   364,   371,   377,   378,   379,   380,   383,
     384,   385,   386,   387,   388,   391,   392,   393,   397,   401,
     405,   409,   415,   421,   427,   433,   441,   442,   445,   456,
     471,   477,   483,   486,   487,   490,   491,   495,   496,   500,
     501,   504,   505,   509,   512,   515,   516,   520
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
  "program_end", "program_contents", "program_content", "type_define",
  "va_declaration", "const_declaration", "var_declaration",
  "array_declaration", "fun_declaration", "$@1", "proc_declaration",
  "formal_argument_list", "formal_argument", "statement",
  "simple_statement", "const_expression", "int_expression",
  "bool_expression", "expression", "math_operator", "logic_operator",
  "bit_operator", "components", "literal_constant", "c_bool", "var_refer",
  "arr_refer", "block", "block_begin", "block_end", "block_contents",
  "block_content", "condition_statement", "loop_statement",
  "block_or_simple_statement", "fun_invoc", "proc_invoc",
  "comma_separated_expressions", "num", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-140)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,    15,    25,    98,    22,  -140,    50,    53,    58,    45,
      98,  -140,  -140,  -140,  -140,  -140,  -140,  -140,    60,    -4,
      -1,  -140,  -140,  -140,    10,    36,   134,    36,   134,    69,
       3,    71,    94,  -140,  -140,  -140,  -140,    81,    92,  -140,
    -140,  -140,  -140,  -140,   134,   134,   134,  -140,   258,  -140,
    -140,  -140,  -140,  -140,  -140,    19,  -140,    36,    36,  -140,
    -140,    52,     4,   103,   134,   134,   134,   206,   267,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,   134,   134,   134,   113,   134,  -140,   102,
      -5,   106,   108,   140,   172,   178,   109,  -140,  -140,  -140,
     110,    52,  -140,  -140,  -140,    36,  -140,  -140,  -140,   187,
     117,   131,   258,  -140,   258,   258,   258,  -140,   132,  -140,
    -140,   134,   134,   134,   123,   134,   134,   258,   134,   258,
       9,   258,   134,  -140,  -140,  -140,  -140,   134,  -140,  -140,
    -140,   137,   141,   258,   113,   138,   258,   225,   244,   144,
     102,  -140,  -140,   122,   115,    16,    40,    74,    16,  -140,
     134,   149,    29,  -140,  -140,   116,  -140,   258,   113,    16,
     150,  -140,    16,  -140
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       6,     7,    14,    15,    16,     8,     9,     3,     0,     0,
      19,     4,     2,     5,     0,     0,     0,     0,     0,     0,
       0,     0,    30,    13,    11,    10,    12,     0,    78,    74,
      72,    76,    77,    73,     0,     0,     0,    17,    45,    54,
      68,    75,    69,    71,    70,    20,    22,     0,     0,    81,
      28,    84,     0,     0,     0,     0,     0,     0,    49,    50,
      57,    58,    55,    56,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,    43,     0,    85,    86,    32,
       0,    84,    33,    34,    35,     0,    27,    29,    18,    96,
       0,     0,    46,    48,    51,    52,    53,    97,     0,    21,
      26,     0,     0,     0,     0,     0,     0,    39,     0,    41,
      78,    44,     0,    82,    80,    83,    24,     0,    93,    79,
      23,     0,     0,    36,     0,     0,    47,     0,     0,     0,
       0,    95,    94,     0,     0,     0,    48,    48,     0,    25,
       0,     0,     0,    92,    91,    87,    89,    37,     0,     0,
       0,    88,     0,    90
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,  -140,  -140,   155,  -140,   -21,   -57,  -140,  -140,
    -140,  -140,  -140,  -140,   104,  -140,  -140,   -54,   -19,    47,
      38,   -43,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
     -30,  -140,  -140,    70,  -140,  -140,  -140,  -123,  -140,  -140,
     -22,  -139
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    22,     9,    10,    37,    11,    12,    13,
      14,    15,   150,    16,    31,    32,    98,   163,    47,   111,
     145,    48,    83,    84,    85,    49,    50,    51,    52,    53,
     164,    61,   134,   100,   101,   102,   103,   165,    54,   104,
     110,   118
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    67,    68,    69,    97,   154,    55,    99,    25,    56,
     121,    27,   -42,    29,   122,    58,   105,     1,     4,   162,
      59,    59,   109,   112,    65,     5,    30,   -42,    66,   170,
     123,    26,   106,    59,    28,   166,    88,    89,    86,    17,
     114,   115,   116,   -38,    97,   108,   171,    99,   122,   173,
     127,   129,   131,    18,    87,    90,    19,   -42,   -38,   120,
     -42,    20,   -42,    21,   123,   -42,   -42,   -42,   119,   -42,
     -42,   -42,    93,    94,    95,    24,    33,   -40,   109,   112,
     143,    57,   146,   147,   136,   148,    34,    62,   -38,   146,
      35,   -38,   -40,   -38,   109,    36,   -38,   -38,   -38,   141,
     -38,   -38,   -38,    91,    63,    92,    29,    65,    93,    94,
      95,    66,     7,     8,    96,   151,    64,   167,   117,    59,
     159,   124,   -40,   125,   132,   -40,   144,   -40,   133,   161,
     -40,   -40,   -40,   138,   -40,   -40,   -40,    38,    39,    40,
      41,    42,    43,    38,    39,    40,    41,    42,    43,    44,
       6,   139,   140,   152,   155,   126,    45,   160,     7,     8,
     158,   153,    45,   168,   169,    23,   172,   107,    46,   142,
     149,   135,     0,     0,    46,    38,    39,    40,    41,    42,
      43,   130,    39,    40,    41,    42,    43,   128,     0,     0,
       0,     0,     0,    44,    45,     0,     0,   137,     0,     0,
      45,     0,     0,     0,     0,     0,    46,     0,    70,    71,
      72,    73,    46,    74,    75,    76,    77,    78,    79,    80,
      81,    82,   113,     0,     0,     0,     0,    70,    71,    72,
      73,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,   156,     0,     0,     0,     0,    70,    71,    72,    73,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     157,     0,     0,     0,     0,    70,    71,    72,    73,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    70,
      71,    72,    73,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    74,    75,    76,    77,    78,    79,    80,
      81,    82
};

static const yytype_int16 yycheck[] =
{
      30,    44,    45,    46,    61,   144,    27,    61,    12,    28,
      15,    12,     3,     3,    19,    12,    12,    44,     3,     3,
      17,    17,    65,    66,    15,     0,    16,    18,    19,   168,
      35,    35,    62,    17,    35,   158,    57,    58,    19,    17,
      83,    84,    85,     3,   101,    64,   169,   101,    19,   172,
      93,    94,    95,     3,    35,     3,     3,    48,    18,    89,
      51,     3,    53,    18,    35,    56,    57,    58,    87,    60,
      61,    62,    56,    57,    58,    15,    40,     3,   121,   122,
     123,    12,   125,   126,   105,   128,    50,    16,    48,   132,
      54,    51,    18,    53,   137,    59,    56,    57,    58,   121,
      60,    61,    62,    51,    10,    53,     3,    15,    56,    57,
      58,    19,    60,    61,    62,   137,    35,   160,     5,    17,
     150,    15,    48,    15,    15,    51,     3,    53,    18,    14,
      56,    57,    58,    16,    60,    61,    62,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,    15,
      52,    20,    20,    16,    16,    15,    22,    35,    60,    61,
      16,    20,    22,    14,    48,    10,    16,    63,    34,   122,
     132,   101,    -1,    -1,    34,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,    15,    -1,    -1,
      -1,    -1,    -1,    15,    22,    -1,    -1,    10,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    34,    -1,    21,    22,
      23,    24,    34,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    16,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    21,
      22,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    26,    27,    28,    29,    30,    31,    32,
      33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    64,    65,     3,     0,    52,    60,    61,    67,
      68,    70,    71,    72,    73,    74,    76,    17,     3,     3,
       3,    18,    66,    67,    15,    12,    35,    12,    35,     3,
      16,    77,    78,    40,    50,    54,    59,    69,     3,     4,
       5,     6,     7,     8,    15,    22,    34,    81,    84,    88,
      89,    90,    91,    92,   101,    69,    81,    12,    12,    17,
      93,    94,    16,    10,    35,    15,    19,    84,    84,    84,
      21,    22,    23,    24,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    85,    86,    87,    19,    35,    69,    69,
       3,    51,    53,    56,    57,    58,    62,    70,    79,    80,
      96,    97,    98,    99,   102,    12,    93,    77,    81,    84,
     103,    82,    84,    16,    84,    84,    84,     5,   104,    81,
      93,    15,    19,    35,    15,    15,    15,    84,    15,    84,
       3,    84,    15,    18,    95,    96,    69,    10,    16,    20,
      20,   103,    82,    84,     3,    83,    84,    84,    84,    83,
      75,   103,    16,    20,   104,    16,    16,    16,    16,    93,
      35,    14,     3,    80,    93,   100,   100,    84,    14,    48,
     104,   100,    16,   100
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    66,    67,    67,    68,    68,    68,
      69,    69,    69,    69,    70,    70,    70,    71,    71,    72,
      72,    72,    72,    73,    75,    74,    74,    76,    76,    77,
      77,    78,    79,    79,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    81,    82,    83,    84,    84,
      84,    84,    84,    84,    84,    85,    85,    85,    85,    86,
      86,    86,    86,    86,    86,    87,    87,    87,    88,    88,
      88,    88,    89,    89,    89,    89,    90,    90,    91,    92,
      93,    94,    95,    96,    96,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   102,   103,   103,   104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     6,     2,
       4,     6,     4,     7,     0,     9,     7,     6,     5,     3,
       1,     3,     1,     1,     1,     1,     3,     6,     4,     2,
       4,     2,     2,     1,     2,     1,     1,     1,     3,     2,
       2,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     1,     1,     2,     0,     1,     1,     5,     7,     5,
       9,     1,     1,     4,     4,     3,     1,     1
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
  case 2: /* program: program_begin program_contents program_end  */
#line 76 "parser.y"
                {
                        symbolTableStack.pop();
                }
#line 1346 "y.tab.cpp"
    break;

  case 3: /* program_begin: CLASS ID LCB  */
#line 81 "parser.y"
{
    symbolTableStack.push(*(yyvsp[-1].str_value));

    Symbol* symbol = new Symbol();
    symbol->name = *(yyvsp[-1].str_value);
    symbol->id_type = ID_PROGRAM;
    symbolTableStack.insert(symbol);

}
#line 1360 "y.tab.cpp"
    break;

  case 10: /* type_define: INT  */
#line 107 "parser.y"
        {
                (yyval.id_type) = VALUE_INT;
        }
#line 1368 "y.tab.cpp"
    break;

  case 11: /* type_define: FLOAT  */
#line 111 "parser.y"
        {
                (yyval.id_type) = VALUE_FLOAT;
        }
#line 1376 "y.tab.cpp"
    break;

  case 12: /* type_define: STRING  */
#line 115 "parser.y"
        {
                (yyval.id_type) = VALUE_STR;
        }
#line 1384 "y.tab.cpp"
    break;

  case 13: /* type_define: BOOL  */
#line 119 "parser.y"
        {
                (yyval.id_type) = VALUE_BOOL;
        }
#line 1392 "y.tab.cpp"
    break;

  case 17: /* const_declaration: VAL ID ASIGN const_expression  */
#line 131 "parser.y"
                        {
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_CONST;
                                symbol->name = *(yyvsp[-2].str_value);
                                symbol->value = (yyvsp[0].value);

                                symbolTableStack.insert(symbol);
                        }
#line 1405 "y.tab.cpp"
    break;

  case 18: /* const_declaration: VAL ID MO type_define ASIGN const_expression  */
#line 140 "parser.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_CONST;
                                symbol->name = *(yyvsp[-4].str_value);    
                                symbol->value= (yyvsp[0].value);

                                if(symbol->value->value_type==(yyvsp[-2].id_type)){
                                        
                                        symbolTableStack.insert(symbol);
                                }else{
                                        yyerror("Type error");
                                }
                        }
#line 1423 "y.tab.cpp"
    break;

  case 19: /* var_declaration: VAR ID  */
#line 156 "parser.y"
                        {
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_VAR;
                                symbol->name = *(yyvsp[0].str_value);          
                                symbol->value->value_type=VALUE_INT;

                                symbolTableStack.insert(symbol);
                        }
#line 1436 "y.tab.cpp"
    break;

  case 20: /* var_declaration: VAR ID MO type_define  */
#line 165 "parser.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_VAR;
                                symbol->name = *(yyvsp[-2].str_value);   
                                symbol->value->value_type= (yyvsp[0].id_type);
 
                                symbolTableStack.insert(symbol);
                        }
#line 1449 "y.tab.cpp"
    break;

  case 21: /* var_declaration: VAR ID MO type_define ASIGN const_expression  */
#line 174 "parser.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_VAR;
                                symbol->name = *(yyvsp[-4].str_value);    
                                symbol->value= (yyvsp[0].value);

                                if(symbol->value->value_type==(yyvsp[-2].id_type)){
                                        symbolTableStack.insert(symbol);
                                }else{
                                        yyerror("Type error");
                                }

                        }
#line 1467 "y.tab.cpp"
    break;

  case 22: /* var_declaration: VAR ID ASIGN const_expression  */
#line 188 "parser.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_VAR;
                                symbol->name = *(yyvsp[-2].str_value);  
                                symbol->value= (yyvsp[0].value);

                                symbolTableStack.insert(symbol);
                        }
#line 1480 "y.tab.cpp"
    break;

  case 23: /* array_declaration: VAR ID MO type_define LSB num RSB  */
#line 199 "parser.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_ARR;
                                symbol->name = *(yyvsp[-5].str_value);   
                                symbol->value->value_type= (yyvsp[-3].id_type);
 
                                symbolTableStack.insert(symbol);
                        }
#line 1493 "y.tab.cpp"
    break;

  case 24: /* $@1: %empty  */
#line 211 "parser.y"
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_FUNC;
                        symbol->name = *(yyvsp[-5].str_value);   
                        symbol->value->value_type= (yyvsp[0].id_type);
 
                        symbolTableStack.insert(symbol);

                        symbol->arguments=symbolTableStack.argumentStack;

                        for(int i=0;i<symbolTableStack.argumentStack.size();i++){
                            symbolTableStack.insert(symbolTableStack.argumentStack[i]); 
                        }
                        symbolTableStack.argumentStack.clear();
                }
#line 1513 "y.tab.cpp"
    break;

  case 26: /* fun_declaration: FUN ID LB RB MO type_define block  */
#line 227 "parser.y"
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_FUNC;
                        symbol->name = *(yyvsp[-5].str_value);   
                        symbol->value->value_type= (yyvsp[-1].id_type);
 
                        symbolTableStack.insert(symbol);
                }
#line 1526 "y.tab.cpp"
    break;

  case 27: /* proc_declaration: FUN ID LB formal_argument_list RB block  */
#line 238 "parser.y"
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_PROCEDURE;
                        symbol->name = *(yyvsp[-4].str_value);   
                        symbol->value->value_type= VALUE_VOID;
 
                        symbolTableStack.insert(symbol);

                        symbol->arguments=symbolTableStack.argumentStack;
                        symbolTableStack.argumentStack.clear();
                }
#line 1542 "y.tab.cpp"
    break;

  case 28: /* proc_declaration: FUN ID LB RB block  */
#line 250 "parser.y"
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_PROCEDURE;
                        symbol->name = *(yyvsp[-3].str_value);   
                        symbol->value->value_type= VALUE_VOID;
 
                        symbolTableStack.insert(symbol);
                }
#line 1555 "y.tab.cpp"
    break;

  case 31: /* formal_argument: ID MO type_define  */
#line 265 "parser.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_ARG;
                                symbol->name = *(yyvsp[-2].str_value);   
                                symbol->value->value_type= (yyvsp[0].id_type);

                                symbolTableStack.argumentStack.push_back(symbol);
                        }
#line 1568 "y.tab.cpp"
    break;

  case 36: /* simple_statement: ID ASIGN expression  */
#line 283 "parser.y"
                {
                        Symbol* symbol = symbolTableStack.lookup(*(yyvsp[-2].str_value));
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }else if (symbol->id_type==ID_CONST)
                        {
                                yyerror("ID is const");
                        }else if (symbol->value->value_type!=(yyvsp[0].value)->value_type)
                        {       
                                yyerror("Type error");
                        }
                }
#line 1586 "y.tab.cpp"
    break;

  case 37: /* simple_statement: ID LSB int_expression RSB ASIGN expression  */
#line 297 "parser.y"
                {
                        Symbol* symbol = symbolTableStack.lookup(*(yyvsp[-5].str_value));
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }else if (symbol->id_type!=ID_ARR)
                        {
                                yyerror("ID is not array");
                        }else if (symbol->value->value_type!=(yyvsp[0].value)->value_type)
                        {       
                                yyerror("Type error");
                        }
                }
#line 1604 "y.tab.cpp"
    break;

  case 45: /* const_expression: expression  */
#line 321 "parser.y"
                        {
                                (yyval.value)=(yyvsp[0].value);
                        }
#line 1612 "y.tab.cpp"
    break;

  case 46: /* int_expression: expression  */
#line 327 "parser.y"
                        {
                                (yyval.value)=(yyvsp[0].value);
                        }
#line 1620 "y.tab.cpp"
    break;

  case 47: /* bool_expression: expression  */
#line 333 "parser.y"
                        {
                                (yyval.value)=(yyvsp[0].value);
                        }
#line 1628 "y.tab.cpp"
    break;

  case 48: /* expression: LB expression RB  */
#line 339 "parser.y"
                {
                        (yyval.value)=(yyvsp[-1].value);
                }
#line 1636 "y.tab.cpp"
    break;

  case 49: /* expression: SUB expression  */
#line 343 "parser.y"
                {
                        (yyval.value)=(yyvsp[0].value);
                }
#line 1644 "y.tab.cpp"
    break;

  case 50: /* expression: NOT expression  */
#line 347 "parser.y"
                {
                        (yyval.value)=(yyvsp[0].value);
                }
#line 1652 "y.tab.cpp"
    break;

  case 51: /* expression: expression math_operator expression  */
#line 351 "parser.y"
                {
                        if((yyvsp[-2].value)->value_type!=(yyvsp[0].value)->value_type){
                                yyerror("Type error");
                        }
                        (yyval.value)=(yyvsp[-2].value);
                }
#line 1663 "y.tab.cpp"
    break;

  case 52: /* expression: expression logic_operator expression  */
#line 358 "parser.y"
                {
                        if((yyvsp[-2].value)->value_type!=(yyvsp[0].value)->value_type){
                                yyerror("Type error");
                        }
                        (yyval.value)=(yyvsp[-2].value);
                }
#line 1674 "y.tab.cpp"
    break;

  case 53: /* expression: expression bit_operator expression  */
#line 365 "parser.y"
                {
                        if((yyvsp[-2].value)->value_type!=(yyvsp[0].value)->value_type){
                                yyerror("Type error");
                        }
                        (yyval.value)=(yyvsp[-2].value);
                }
#line 1685 "y.tab.cpp"
    break;

  case 54: /* expression: components  */
#line 372 "parser.y"
                {
                        (yyval.value)=(yyvsp[0].value);
                }
#line 1693 "y.tab.cpp"
    break;

  case 68: /* components: literal_constant  */
#line 398 "parser.y"
                {
                        (yyval.value)=(yyvsp[0].value);
                }
#line 1701 "y.tab.cpp"
    break;

  case 69: /* components: var_refer  */
#line 402 "parser.y"
                {
                        (yyval.value)=(yyvsp[0].value);
                }
#line 1709 "y.tab.cpp"
    break;

  case 70: /* components: fun_invoc  */
#line 406 "parser.y"
                {
                        // $$=$1;
                }
#line 1717 "y.tab.cpp"
    break;

  case 71: /* components: arr_refer  */
#line 410 "parser.y"
                {
                        (yyval.value)=(yyvsp[0].value);
                }
#line 1725 "y.tab.cpp"
    break;

  case 72: /* literal_constant: C_INT  */
#line 416 "parser.y"
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_INT;
                                (yyval.value)=value;
                        }
#line 1735 "y.tab.cpp"
    break;

  case 73: /* literal_constant: C_FLOAT  */
#line 422 "parser.y"
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_FLOAT;
                                (yyval.value)=value;
                        }
#line 1745 "y.tab.cpp"
    break;

  case 74: /* literal_constant: C_STR  */
#line 428 "parser.y"
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_STR;
                                (yyval.value)=value;
                        }
#line 1755 "y.tab.cpp"
    break;

  case 75: /* literal_constant: c_bool  */
#line 434 "parser.y"
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_BOOL;
                                (yyval.value)=value;
                        }
#line 1765 "y.tab.cpp"
    break;

  case 78: /* var_refer: ID  */
#line 446 "parser.y"
                {
                        Symbol* symbol = symbolTableStack.lookup(*(yyvsp[0].str_value));
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }
                        (yyval.value) = symbol->value;
                }
#line 1778 "y.tab.cpp"
    break;

  case 79: /* arr_refer: ID LSB int_expression RSB  */
#line 457 "parser.y"
                {
                        Symbol* symbol = symbolTableStack.lookup(*(yyvsp[-3].str_value));
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }else if (symbol->id_type!=ID_ARR)
                        {
                                yyerror("ID is not array");
                        }
                        (yyval.value) = symbol->value;
                }
#line 1794 "y.tab.cpp"
    break;

  case 80: /* block: block_begin block_contents block_end  */
#line 472 "parser.y"
        {
                symbolTableStack.pop();
        }
#line 1802 "y.tab.cpp"
    break;

  case 81: /* block_begin: LCB  */
#line 478 "parser.y"
                {
                        symbolTableStack.push("block");
                }
#line 1810 "y.tab.cpp"
    break;


#line 1814 "y.tab.cpp"

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

#line 523 "parser.y"


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

        string jasm_target_path = argv[1];
        jasm_target_path += ".jasm";
        jasm_file.open(jasm_target_path, ios::out | ios::trunc);
        /* if(yyparse() == 1){
        yyerror("parsing error");
                
        } */

	yyin = fp;
	yyparse();

	fprintf( stdout, "\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	exit(0);
}
