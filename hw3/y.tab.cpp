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

// a=a+b segmentation fault

const string MAX_STACK = "15";
const string MAX_LOCALS = "15";

int yylex();

void yyerror(string s)
{
    cout<<"ERROR LINE<"+to_string(linenum)+">: " << s <<endl;
    exit(-1);
}

void TypeError(int a,int b){
        yyerror("Type Error: "+ValueTypeToString(a)+" <-> "+ ValueTypeToString(b));
}

SymbolTableStack symbolTableStack =  SymbolTableStack();



#line 103 "y.tab.cpp"

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
  YYSYMBOL_76_2 = 76,                      /* $@2  */
  YYSYMBOL_proc_declaration = 77,          /* proc_declaration  */
  YYSYMBOL_78_3 = 78,                      /* $@3  */
  YYSYMBOL_79_4 = 79,                      /* $@4  */
  YYSYMBOL_formal_argument_list = 80,      /* formal_argument_list  */
  YYSYMBOL_formal_argument = 81,           /* formal_argument  */
  YYSYMBOL_statement = 82,                 /* statement  */
  YYSYMBOL_simple_statement = 83,          /* simple_statement  */
  YYSYMBOL_84_5 = 84,                      /* $@5  */
  YYSYMBOL_85_6 = 85,                      /* $@6  */
  YYSYMBOL_const_expression = 86,          /* const_expression  */
  YYSYMBOL_int_expression = 87,            /* int_expression  */
  YYSYMBOL_bool_expression = 88,           /* bool_expression  */
  YYSYMBOL_expression = 89,                /* expression  */
  YYSYMBOL_math_operator = 90,             /* math_operator  */
  YYSYMBOL_logic_operator = 91,            /* logic_operator  */
  YYSYMBOL_bit_operator = 92,              /* bit_operator  */
  YYSYMBOL_components = 93,                /* components  */
  YYSYMBOL_literal_constant = 94,          /* literal_constant  */
  YYSYMBOL_literal_constant_bool = 95,     /* literal_constant_bool  */
  YYSYMBOL_var_refer = 96,                 /* var_refer  */
  YYSYMBOL_arr_refer = 97,                 /* arr_refer  */
  YYSYMBOL_block = 98,                     /* block  */
  YYSYMBOL_99_7 = 99,                      /* $@7  */
  YYSYMBOL_100_8 = 100,                    /* $@8  */
  YYSYMBOL_block_contents = 101,           /* block_contents  */
  YYSYMBOL_block_content = 102,            /* block_content  */
  YYSYMBOL_condition_statement = 103,      /* condition_statement  */
  YYSYMBOL_104_9 = 104,                    /* $@9  */
  YYSYMBOL_105_10 = 105,                   /* $@10  */
  YYSYMBOL_else_statement = 106,           /* else_statement  */
  YYSYMBOL_loop_statement = 107,           /* loop_statement  */
  YYSYMBOL_108_11 = 108,                   /* $@11  */
  YYSYMBOL_109_12 = 109,                   /* $@12  */
  YYSYMBOL_110_13 = 110,                   /* $@13  */
  YYSYMBOL_block_or_simple_statement = 111, /* block_or_simple_statement  */
  YYSYMBOL_112_14 = 112,                   /* $@14  */
  YYSYMBOL_fun_invoc = 113,                /* fun_invoc  */
  YYSYMBOL_proc_invoc = 114,               /* proc_invoc  */
  YYSYMBOL_comma_separated_expressions = 115, /* comma_separated_expressions  */
  YYSYMBOL_116_15 = 116,                   /* $@15  */
  YYSYMBOL_num = 117                       /* num  */
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
#define YYLAST   220

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

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
       0,    75,    75,    80,    95,   102,   103,   107,   108,   109,
     113,   117,   121,   125,   132,   133,   134,   137,   147,   164,
     173,   182,   196,   208,   221,   220,   262,   261,   293,   292,
     340,   339,   377,   378,   381,   393,   394,   395,   396,   399,
     414,   429,   428,   436,   435,   442,   461,   473,   487,   491,
     498,   508,   514,   523,   527,   546,   562,   566,   574,   585,
     593,   599,   604,   609,   614,   619,   626,   631,   636,   641,
     646,   651,   658,   663,   668,   676,   697,   701,   705,   711,
     718,   725,   732,   734,   741,   750,   771,   787,   791,   786,
     797,   798,   801,   802,   807,   810,   806,   817,   823,   831,
     836,   830,   844,   843,   869,   869,   876,   880,   914,   950,
     949,   953,   960
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
  "array_declaration", "fun_declaration", "$@1", "$@2", "proc_declaration",
  "$@3", "$@4", "formal_argument_list", "formal_argument", "statement",
  "simple_statement", "$@5", "$@6", "const_expression", "int_expression",
  "bool_expression", "expression", "math_operator", "logic_operator",
  "bit_operator", "components", "literal_constant",
  "literal_constant_bool", "var_refer", "arr_refer", "block", "$@7", "$@8",
  "block_contents", "block_content", "condition_statement", "$@9", "$@10",
  "else_statement", "loop_statement", "$@11", "$@12", "$@13",
  "block_or_simple_statement", "$@14", "fun_invoc", "proc_invoc",
  "comma_separated_expressions", "$@15", "num", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-132)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-112)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -34,    36,    41,    38,    62,  -132,    43,    77,    80,    67,
      38,  -132,  -132,  -132,  -132,  -132,  -132,  -132,    78,    -5,
      -1,  -132,  -132,  -132,    34,    28,   137,    28,   137,    83,
      89,    86,    94,  -132,  -132,  -132,  -132,    87,  -132,  -132,
    -132,  -132,  -132,   137,   137,   190,  -132,  -132,    16,   190,
      28,    28,   108,   111,   129,   137,   140,  -132,  -132,  -132,
    -132,  -132,  -132,   137,   128,   137,  -132,  -132,  -132,  -132,
      28,   108,  -132,   190,  -132,   190,  -132,   119,   190,   108,
       5,  -132,  -132,  -132,  -132,    10,   120,   136,  -132,  -132,
     106,  -132,  -132,  -132,  -132,   122,  -132,     5,  -132,  -132,
    -132,   108,   112,   112,   112,   155,   112,   112,   112,   165,
     112,   112,   112,   190,  -132,  -132,  -132,  -132,  -132,   145,
     112,   163,  -132,  -132,    21,   175,   166,   172,   190,   190,
     128,   115,   148,   121,   190,   190,   112,   185,  -132,  -132,
     112,   112,   190,  -132,   173,  -132,  -132,   171,  -132,  -132,
    -132,  -132,   112,  -132,  -132,  -132,  -132,  -132,  -132,   112,
     177,  -132,   190,   134,   112,   180,    18,   -20,   190,  -132,
    -132,  -132,   128,    25,  -132,  -132,   108,    18,   179,   154,
    -132,  -132,  -132,    18,  -132,    18,  -132,  -132
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       6,     7,    14,    15,    16,     8,     9,     3,     0,     0,
      19,     4,     2,     5,     0,     0,     0,     0,     0,     0,
      30,     0,    33,    13,    11,    10,    12,     0,    81,    79,
      83,    84,    80,     0,     0,    17,    51,    82,    20,    22,
       0,     0,     0,    28,     0,     0,     0,    49,    63,    64,
      61,    62,    65,     0,     0,     0,    34,    26,    87,    31,
       0,     0,    32,    18,    48,    50,   112,     0,    21,     0,
      91,    24,    29,    23,    27,     0,     0,     0,    41,    43,
      46,    99,    92,    93,    35,     0,    88,    91,    36,    37,
      38,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,     0,     0,    47,    60,    75,    76,    78,    77,     0,
       0,     0,    90,    25,    85,   109,     0,     0,    52,    39,
       0,     0,     0,    82,    42,    44,     0,     0,    57,    59,
       0,     0,    40,    89,     0,   108,    86,     0,    94,    72,
      73,    74,     0,    67,    66,    68,    69,    70,    71,     0,
       0,    56,    58,     0,     0,     0,   104,    55,    54,   107,
     100,   110,     0,     0,   106,    95,     0,   104,     0,    98,
     105,   101,   102,   104,    96,   104,    97,   103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,  -132,   193,  -132,   -23,   -54,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,   150,  -132,  -132,
     -38,  -132,  -132,    26,  -132,   -64,   -88,    51,  -132,  -132,
    -132,    29,  -103,  -132,   -80,   -70,  -132,  -132,   123,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,   -47,  -132,
    -132,  -132,  -131,  -132,  -124
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    22,     9,    10,    37,    11,    12,    13,
      14,    15,   101,    79,    16,    71,    52,    31,    32,    93,
     174,   107,   108,    45,   127,   131,   125,   140,   159,   152,
     114,   115,    47,   116,   117,    69,    80,   121,    96,    97,
      98,   166,   179,   184,    99,   119,   177,   185,   175,   176,
     118,   100,   126,   144,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,    82,   113,   133,    48,   160,   147,    25,    85,    84,
       1,    27,   149,   150,   151,   128,   129,    95,   132,   134,
     135,   173,   137,   138,   139,   102,    92,    66,    67,   103,
      26,   123,   142,   171,    28,    64,   136,    29,   133,     4,
     103,     5,    94,    92,   103,   104,    18,    81,   178,   133,
      30,    65,   162,   132,    49,    46,    86,    46,    87,    94,
     104,    88,    89,    90,   132,     7,     8,    91,    33,    56,
      57,   168,    46,    46,    88,    89,    90,   163,    34,    17,
      19,    73,    35,    20,    46,    21,    95,    36,   167,    75,
       6,    78,    46,    24,    46,    50,    63,    95,     7,     8,
      63,    51,    53,    95,    54,    95,   180,    63,    63,   109,
      38,    39,    40,    41,    42,   124,    38,    39,    40,    41,
      42,   110,    55,    70,    63,    68,    63,   110,   111,    63,
     181,   148,    29,    76,   111,   105,   186,   -53,   187,    83,
     112,    38,    39,    40,    41,    42,   112,   149,   150,   151,
     170,   106,    43,   -53,   -53,   -53,    74,   120,   130,    44,
     141,    58,    59,    60,    61,    62,   149,   150,   151,    58,
      59,    60,    61,    62,   153,   154,   155,   156,   157,   158,
     136,   143,   145,   164,   103,   165,   -85,   -85,   -85,   -85,
     -85,  -111,   146,   169,   172,   182,    58,    59,    60,    61,
      62,   161,   183,    23,    72,     0,    58,    59,    60,    61,
      62,    58,    59,    60,    61,    62,     0,     0,     0,     0,
     122
};

static const yytype_int16 yycheck[] =
{
      80,    71,    90,   106,    27,   136,   130,    12,     3,    79,
      44,    12,    32,    33,    34,   103,   104,    97,   106,   107,
     108,     3,   110,   111,   112,    15,    80,    50,    51,    19,
      35,   101,   120,   164,    35,    19,    15,     3,   141,     3,
      19,     0,    80,    97,    19,    35,     3,    70,   172,   152,
      16,    35,   140,   141,    28,    26,    51,    28,    53,    97,
      35,    56,    57,    58,   152,    60,    61,    62,    40,    43,
      44,   159,    43,    44,    56,    57,    58,   141,    50,    17,
       3,    55,    54,     3,    55,    18,   166,    59,   152,    63,
      52,    65,    63,    15,    65,    12,    45,   177,    60,    61,
      49,    12,    16,   183,    10,   185,   176,    56,    57,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,    15,    35,    12,    73,    17,    75,    15,    22,    78,
     177,    16,     3,     5,    22,    15,   183,    16,   185,    20,
      34,     4,     5,     6,     7,     8,    34,    32,    33,    34,
      16,    15,    15,    32,    33,    34,    16,    35,     3,    22,
      15,    21,    22,    23,    24,    25,    32,    33,    34,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      15,    18,    16,    10,    19,    14,    21,    22,    23,    24,
      25,    16,    20,    16,    14,    16,    21,    22,    23,    24,
      25,    16,    48,    10,    54,    -1,    21,    22,    23,    24,
      25,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      97
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    64,    65,     3,     0,    52,    60,    61,    67,
      68,    70,    71,    72,    73,    74,    77,    17,     3,     3,
       3,    18,    66,    67,    15,    12,    35,    12,    35,     3,
      16,    80,    81,    40,    50,    54,    59,    69,     4,     5,
       6,     7,     8,    15,    22,    86,    94,    95,    69,    86,
      12,    12,    79,    16,    10,    35,    86,    86,    21,    22,
      23,    24,    25,    90,    19,    35,    69,    69,    17,    98,
      12,    78,    80,    86,    16,    86,     5,   117,    86,    76,
      99,    69,    98,    20,    98,     3,    51,    53,    56,    57,
      58,    62,    70,    82,    83,    97,   101,   102,   103,   107,
     114,    75,    15,    19,    35,    15,    15,    84,    85,     3,
      15,    22,    34,    89,    93,    94,    96,    97,   113,   108,
      35,   100,   101,    98,     3,    89,   115,    87,    89,    89,
       3,    88,    89,    95,    89,    89,    15,    89,    89,    89,
      90,    15,    89,    18,   116,    16,    20,   117,    16,    32,
      33,    34,    92,    26,    27,    28,    29,    30,    31,    91,
     115,    16,    89,    88,    10,    14,   104,    88,    89,    16,
      16,   115,    14,     3,    83,   111,   112,   109,   117,   105,
      98,   111,    16,    48,   106,   110,   111,   111
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    66,    67,    67,    68,    68,    68,
      69,    69,    69,    69,    70,    70,    70,    71,    71,    72,
      72,    72,    72,    73,    75,    74,    76,    74,    78,    77,
      79,    77,    80,    80,    81,    82,    82,    82,    82,    83,
      83,    84,    83,    85,    83,    83,    83,    83,    86,    86,
      86,    86,    87,    88,    88,    88,    89,    89,    89,    89,
      89,    90,    90,    90,    90,    90,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    93,    93,    93,    93,    94,
      94,    94,    94,    95,    95,    96,    97,    99,   100,    98,
     101,   101,   102,   102,   104,   105,   103,   106,   106,   108,
     109,   107,   110,   107,   112,   111,   111,   113,   114,   116,
     115,   115,   117
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     6,     2,
       4,     6,     4,     7,     0,     9,     0,     8,     0,     7,
       0,     6,     3,     1,     3,     1,     1,     1,     1,     3,
       3,     0,     3,     0,     3,     2,     1,     2,     3,     2,
       3,     1,     1,     1,     3,     3,     3,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     0,     0,     5,
       2,     0,     1,     1,     0,     0,     8,     2,     0,     0,
       0,     7,     0,    10,     0,     2,     1,     4,     4,     0,
       4,     1,     1
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
#line 1360 "y.tab.cpp"
    break;

  case 3: /* program_begin: CLASS ID LCB  */
#line 81 "parser.y"
                {
                symbolTableStack.push(*(yyvsp[-1].str_value));

                Symbol* symbol = new Symbol();
                symbol->name = *(yyvsp[-1].str_value);
                symbol->id_type = ID_PROGRAM;
                symbolTableStack.insert(symbol);
                symbolTableStack.program_name=*(yyvsp[-1].str_value);

                jasm("class "+*(yyvsp[-1].str_value));
                jasm("{");

                }
#line 1378 "y.tab.cpp"
    break;

  case 4: /* program_end: RCB  */
#line 96 "parser.y"
                {
                        jasm("}");
                }
#line 1386 "y.tab.cpp"
    break;

  case 10: /* type_define: INT  */
#line 114 "parser.y"
        {
                (yyval.id_type) = VALUE_INT;
        }
#line 1394 "y.tab.cpp"
    break;

  case 11: /* type_define: FLOAT  */
#line 118 "parser.y"
        {
                (yyval.id_type) = VALUE_FLOAT;
        }
#line 1402 "y.tab.cpp"
    break;

  case 12: /* type_define: STRING  */
#line 122 "parser.y"
        {
                (yyval.id_type) = VALUE_STR;
        }
#line 1410 "y.tab.cpp"
    break;

  case 13: /* type_define: BOOL  */
#line 126 "parser.y"
        {
                (yyval.id_type) = VALUE_BOOL;
        }
#line 1418 "y.tab.cpp"
    break;

  case 17: /* const_declaration: VAL ID ASIGN const_expression  */
#line 138 "parser.y"
                        {
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_CONST;
                                symbol->name = *(yyvsp[-2].str_value);
                                symbol->value = (yyvsp[0].value);
                                symbol->init=true;

                                symbolTableStack.insert(symbol);
                        }
#line 1432 "y.tab.cpp"
    break;

  case 18: /* const_declaration: VAL ID MO type_define ASIGN const_expression  */
#line 148 "parser.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_CONST;
                                symbol->name = *(yyvsp[-4].str_value);    
                                symbol->value= (yyvsp[0].value);
                                symbol->init=true;

                                if(symbol->value->value_type==(yyvsp[-2].id_type)){
                                        
                                        symbolTableStack.insert(symbol);
                                }else{
                                        TypeError(symbol->value->value_type,(yyvsp[-2].id_type));
                                }
                        }
#line 1451 "y.tab.cpp"
    break;

  case 19: /* var_declaration: VAR ID  */
#line 165 "parser.y"
                        {
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_VAR;
                                symbol->name = *(yyvsp[0].str_value);          
                                symbol->value->value_type=VALUE_INT;

                                symbolTableStack.insert(symbol);
                        }
#line 1464 "y.tab.cpp"
    break;

  case 20: /* var_declaration: VAR ID MO type_define  */
#line 174 "parser.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_VAR;
                                symbol->name = *(yyvsp[-2].str_value);   
                                symbol->value->value_type= (yyvsp[0].id_type);
 
                                symbolTableStack.insert(symbol);
                        }
#line 1477 "y.tab.cpp"
    break;

  case 21: /* var_declaration: VAR ID MO type_define ASIGN const_expression  */
#line 183 "parser.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_VAR;
                                symbol->name = *(yyvsp[-4].str_value);    
                                symbol->value= (yyvsp[0].value);
                                symbol->init=true;

                                if(symbol->value->value_type==(yyvsp[-2].id_type)){
                                        symbolTableStack.insert(symbol);
                                }else{
                                        TypeError(symbol->value->value_type,(yyvsp[-2].id_type));
                                }
                        }
#line 1495 "y.tab.cpp"
    break;

  case 22: /* var_declaration: VAR ID ASIGN const_expression  */
#line 197 "parser.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_VAR;
                                symbol->name = *(yyvsp[-2].str_value);  
                                symbol->value= (yyvsp[0].value);
                                symbol->init=true;

                                symbolTableStack.insert(symbol);
                        }
#line 1509 "y.tab.cpp"
    break;

  case 23: /* array_declaration: VAR ID MO type_define LSB num RSB  */
#line 209 "parser.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_ARR;
                                symbol->name = *(yyvsp[-5].str_value);   
                                symbol->value->value_type= (yyvsp[-3].id_type);
 
                                symbolTableStack.insert(symbol);
                        }
#line 1522 "y.tab.cpp"
    break;

  case 24: /* $@1: %empty  */
#line 221 "parser.y"
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_FUNC;
                        symbol->name = *(yyvsp[-5].str_value);   
                        symbol->value->value_type= (yyvsp[0].id_type);
 
                        symbolTableStack.insert(symbol);

                        symbol->arguments=symbolTableStack.argumentStack;

                        symbolTableStack.push(*(yyvsp[-5].str_value));
                        for(int i=0;i<symbolTableStack.argumentStack.size();i++){
                            symbolTableStack.insert(symbolTableStack.argumentStack[i]); 
                        }

                        symbolTableStack.argumentStack.clear();

                        symbolTableStack.fun_ptr=symbol;

                        // javaa                        
                        string arguments="";
                        for(int i=0;i<symbol->arguments.size();i++){
                                if(i!=0){
                                        arguments+=", ";
                                }
                                arguments+=ValueTypeToString(symbol->arguments[i]->value->value_type);
                        }
                        jasm("method public static "+ValueTypeToString(symbol->value->value_type)+" "+symbol->name+"("+arguments+")");
                        jasm("max_stack "+MAX_STACK);
                        jasm("max_locals "+MAX_LOCALS);
                        jasm("{");

                }
#line 1560 "y.tab.cpp"
    break;

  case 25: /* fun_declaration: FUN ID LB formal_argument_list RB MO type_define $@1 block  */
#line 253 "parser.y"
                       {
                        symbolTableStack.pop();
                        symbolTableStack.fun_ptr=nullptr;

                        // javaa
                        jasm("}");

                }
#line 1573 "y.tab.cpp"
    break;

  case 26: /* $@2: %empty  */
#line 262 "parser.y"
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_FUNC;
                        symbol->name = *(yyvsp[-4].str_value);   
 
                        symbolTableStack.insert(symbol);

                        symbolTableStack.push(*(yyvsp[-4].str_value));

                        symbolTableStack.fun_ptr=symbol;

                        symbolTableStack.fun_ptr=symbol;
                        
                        // javaa
                        jasm("method public static "+ValueTypeToString(symbol->value->value_type)+" "+symbol->name+"()");
                        jasm("max_stack "+MAX_STACK);
                        jasm("max_locals "+MAX_LOCALS);
                        jasm("{");

                }
#line 1598 "y.tab.cpp"
    break;

  case 27: /* fun_declaration: FUN ID LB RB MO type_define $@2 block  */
#line 281 "parser.y"
                       {
                        symbolTableStack.pop();

                        symbolTableStack.fun_ptr=nullptr;

                        // javaa
                        jasm("}");

                }
#line 1612 "y.tab.cpp"
    break;

  case 28: /* $@3: %empty  */
#line 293 "parser.y"
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_PROCEDURE;
                        symbol->name = *(yyvsp[-3].str_value);   
 
                        symbol->value->value_type= VALUE_VOID;

                        symbolTableStack.insert(symbol);

                        symbol->arguments=symbolTableStack.argumentStack;

                        symbolTableStack.push(*(yyvsp[-3].str_value));
                        for(int i=0;i<symbolTableStack.argumentStack.size();i++){
                            symbolTableStack.insert(symbolTableStack.argumentStack[i]); 
                        }

                        symbolTableStack.argumentStack.clear();

                        symbolTableStack.fun_ptr=symbol;

                        // javaa                        
                        string arguments="";
                        for(int i=0;i<symbol->arguments.size();i++){
                                if(i!=0){
                                        arguments+=", ";
                                }
                                arguments+=ValueTypeToString(symbol->arguments[i]->value->value_type);
                        }
                        
                        jasm("method public static "+ValueTypeToString(symbol->value->value_type)+" "+symbol->name+"("+arguments+")");
                        jasm("max_stack "+MAX_STACK);
                        jasm("max_locals "+MAX_LOCALS);
                        jasm("{");


                }
#line 1653 "y.tab.cpp"
    break;

  case 29: /* proc_declaration: FUN ID LB formal_argument_list RB $@3 block  */
#line 328 "parser.y"
                       {
                        symbolTableStack.pop();

                        symbolTableStack.fun_ptr=nullptr;

                        // javaa
                        jasm("return");
                        
                        jasm("}");

                }
#line 1669 "y.tab.cpp"
    break;

  case 30: /* $@4: %empty  */
#line 340 "parser.y"
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_PROCEDURE;
                        symbol->name = *(yyvsp[-2].str_value);   
 
                        symbol->value->value_type= VALUE_VOID;
 
                        symbolTableStack.insert(symbol);


                        symbolTableStack.push(*(yyvsp[-2].str_value));

                        symbolTableStack.argumentStack.clear();

                        symbolTableStack.fun_ptr=symbol;

                        if(symbol->name=="main"){
                                jasm("method public static void main(java.lang.String[])"); 
                        }else{
                                jasm("method public static "+ValueTypeToString(symbol->value->value_type)+" "+symbol->name+"()");
                        }
                        jasm("max_stack "+MAX_STACK);
                        jasm("max_locals "+MAX_LOCALS);
                        jasm("{");

                }
#line 1700 "y.tab.cpp"
    break;

  case 31: /* proc_declaration: FUN ID LB RB $@4 block  */
#line 365 "parser.y"
                       {
                        symbolTableStack.pop();

                        symbolTableStack.fun_ptr=nullptr;

                        // javaa
                        jasm("return");
                        jasm("}");

                }
#line 1715 "y.tab.cpp"
    break;

  case 34: /* formal_argument: ID MO type_define  */
#line 382 "parser.y"
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_VAR;
                                symbol->name = *(yyvsp[-2].str_value);   
                                symbol->value->value_type= (yyvsp[0].id_type);

                                symbolTableStack.argumentStack.push_back(symbol);
                        }
#line 1728 "y.tab.cpp"
    break;

  case 39: /* simple_statement: ID ASIGN expression  */
#line 400 "parser.y"
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
                                TypeError(symbol->value->value_type,(yyvsp[0].value)->value_type);
                        }
                        symbolTableStack.update_value(symbol);
                }
#line 1747 "y.tab.cpp"
    break;

  case 40: /* simple_statement: arr_refer ASIGN expression  */
#line 415 "parser.y"
                {
                        Symbol* symbol = (yyvsp[-2].symbol);
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }else if (symbol->id_type!=ID_ARR)
                        {
                                yyerror("ID is not array");
                        }else if (symbol->value->value_type!=(yyvsp[0].value)->value_type)
                        {       
                                TypeError(symbol->value->value_type,(yyvsp[0].value)->value_type);
                        }
                }
#line 1765 "y.tab.cpp"
    break;

  case 41: /* $@5: %empty  */
#line 429 "parser.y"
                {
                        jasm("getstatic java.io.PrintStream java.lang.System.out");
                }
#line 1773 "y.tab.cpp"
    break;

  case 42: /* simple_statement: PRINT $@5 expression  */
#line 432 "parser.y"
                {
                        // symbolTableStack.print($2,false);
                }
#line 1781 "y.tab.cpp"
    break;

  case 43: /* $@6: %empty  */
#line 436 "parser.y"
                {
                        jasm("getstatic java.io.PrintStream java.lang.System.out");
                }
#line 1789 "y.tab.cpp"
    break;

  case 44: /* simple_statement: PRINTLN $@6 expression  */
#line 439 "parser.y"
                {
                        // symbolTableStack.print($2,true);
                }
#line 1797 "y.tab.cpp"
    break;

  case 45: /* simple_statement: RETURN ID  */
#line 443 "parser.y"
                {
                        if(!symbolTableStack.fun_ptr){
                                yyerror("Not in function");
                        }else{
                                Symbol* symbol = symbolTableStack.lookup(*(yyvsp[0].str_value));
                                if (!symbol)
                                {
                                        yyerror("ID not found");
                                }else if (symbol->value->value_type!=symbolTableStack.fun_ptr->value->value_type)
                                {       
                                        TypeError(symbol->value->value_type,symbolTableStack.fun_ptr->value->value_type);
                                }
                                // javaa
                                jasm("ireturn");
                        }

                        
                }
#line 1820 "y.tab.cpp"
    break;

  case 46: /* simple_statement: RETURN  */
#line 462 "parser.y"
                {
                        if(!symbolTableStack.fun_ptr){
                                yyerror("Not in function");
                        }else if (symbolTableStack.fun_ptr->value->value_type!=VALUE_VOID)
                        {       
                                TypeError(symbolTableStack.fun_ptr->value->value_type,VALUE_VOID);
                        }
                        // javaa
                        jasm("return");
                        
                }
#line 1836 "y.tab.cpp"
    break;

  case 47: /* simple_statement: RETURN expression  */
#line 474 "parser.y"
                {
                        if(!symbolTableStack.fun_ptr){
                                yyerror("Not in function");
                        }else if ((yyvsp[0].value)->value_type!=symbolTableStack.fun_ptr->value->value_type)
                        {       
                                TypeError((yyvsp[0].value)->value_type,symbolTableStack.fun_ptr->value->value_type);
                        }
                        // javaa
                        jasm("ireturn");
                }
#line 1851 "y.tab.cpp"
    break;

  case 48: /* const_expression: LB const_expression RB  */
#line 488 "parser.y"
                        {
                                (yyval.value)=(yyvsp[-1].value);
                        }
#line 1859 "y.tab.cpp"
    break;

  case 49: /* const_expression: SUB const_expression  */
#line 492 "parser.y"
                        {
                                if((yyvsp[0].value)->value_type!=VALUE_INT&&(yyvsp[0].value)->value_type!=VALUE_FLOAT){
                                        TypeError((yyvsp[0].value)->value_type,(yyvsp[0].value)->value_type);
                                }
                                (yyval.value)=(yyvsp[0].value);
                        }
#line 1870 "y.tab.cpp"
    break;

  case 50: /* const_expression: const_expression math_operator const_expression  */
#line 499 "parser.y"
                        {
                                if((yyvsp[-2].value)->value_type!=(yyvsp[0].value)->value_type){
                                        TypeError((yyvsp[-2].value)->value_type,(yyvsp[0].value)->value_type);
                                }
                                if((yyvsp[-2].value)->value_type!=VALUE_INT&&(yyvsp[-2].value)->value_type!=VALUE_FLOAT){
                                TypeError((yyvsp[-2].value)->value_type,(yyvsp[0].value)->value_type);
                        }
                                (yyval.value)=(yyvsp[-2].value);
                        }
#line 1884 "y.tab.cpp"
    break;

  case 51: /* const_expression: literal_constant  */
#line 509 "parser.y"
                        {
                                (yyval.value)=(yyvsp[0].value);
                        }
#line 1892 "y.tab.cpp"
    break;

  case 52: /* int_expression: expression  */
#line 515 "parser.y"
                        {
                                if((yyvsp[0].value)->value_type!=VALUE_INT){
                                        TypeError((yyvsp[0].value)->value_type,VALUE_INT);
                                }
                                (yyval.value)=(yyvsp[0].value);
                        }
#line 1903 "y.tab.cpp"
    break;

  case 53: /* bool_expression: literal_constant_bool  */
#line 524 "parser.y"
                        {
                                (yyval.value)=(yyvsp[0].value);
                        }
#line 1911 "y.tab.cpp"
    break;

  case 54: /* bool_expression: expression logic_operator expression  */
#line 528 "parser.y"
                        {
                                if((yyvsp[-2].value)->value_type!=(yyvsp[0].value)->value_type){
                                        TypeError((yyvsp[-2].value)->value_type,(yyvsp[0].value)->value_type);
                                }
                                Value *ret=new Value();
                                ret->value_type=VALUE_BOOL;
                                (yyval.value)=ret;

                                // javaa
                                jasm("isub");
                                jasm(*(yyvsp[-1].str_value)+" L"+to_string(symbolTableStack.tag));
                                jasm("iconst_0");
                                jasm("goto L"+to_string(symbolTableStack.tag+1));
                                jasm("L"+to_string(symbolTableStack.tag)+":");
                                jasm("iconst_1");
                                jasm("L"+to_string(symbolTableStack.tag+1)+": ");
                                symbolTableStack.tag+=2;
                        }
#line 1934 "y.tab.cpp"
    break;

  case 55: /* bool_expression: bool_expression bit_operator bool_expression  */
#line 547 "parser.y"
                        {
                                if((yyvsp[-2].value)->value_type!=(yyvsp[0].value)->value_type){
                                        TypeError((yyvsp[-2].value)->value_type,(yyvsp[0].value)->value_type);
                                }
                                if((yyvsp[-2].value)->value_type!=VALUE_BOOL){
                                        TypeError((yyvsp[-2].value)->value_type,VALUE_BOOL);
                                }

                                (yyval.value)=(yyvsp[-2].value);

                                // javaa
                                jasm(*(yyvsp[-1].str_value));
                        }
#line 1952 "y.tab.cpp"
    break;

  case 56: /* expression: LB expression RB  */
#line 563 "parser.y"
                {
                        (yyval.value)=(yyvsp[-1].value);
                }
#line 1960 "y.tab.cpp"
    break;

  case 57: /* expression: SUB expression  */
#line 567 "parser.y"
                {
                        if((yyvsp[0].value)->value_type!=VALUE_INT&&(yyvsp[0].value)->value_type!=VALUE_FLOAT){
                                TypeError((yyvsp[0].value)->value_type,(yyvsp[0].value)->value_type);
                        }
                        jasm("ineg");
                        (yyval.value)=(yyvsp[0].value);
                }
#line 1972 "y.tab.cpp"
    break;

  case 58: /* expression: expression math_operator expression  */
#line 575 "parser.y"
                {
                        if((yyvsp[-2].value)->value_type!=(yyvsp[0].value)->value_type){
                                TypeError((yyvsp[-2].value)->value_type,(yyvsp[0].value)->value_type);
                        }
                        if((yyvsp[-2].value)->value_type!=VALUE_INT&&(yyvsp[-2].value)->value_type!=VALUE_FLOAT){
                                TypeError((yyvsp[-2].value)->value_type,(yyvsp[0].value)->value_type);
                        }
                        jasm(*(yyvsp[-1].str_value));
                        (yyval.value)=(yyvsp[-2].value);
                }
#line 1987 "y.tab.cpp"
    break;

  case 59: /* expression: NOT expression  */
#line 586 "parser.y"
                {
                        if((yyvsp[0].value)->value_type!=VALUE_BOOL){
                                TypeError((yyvsp[0].value)->value_type,VALUE_BOOL);
                        }
                        jasm("ixor");
                        (yyval.value)=(yyvsp[0].value);
                }
#line 1999 "y.tab.cpp"
    break;

  case 60: /* expression: components  */
#line 594 "parser.y"
                {
                        (yyval.value)=(yyvsp[0].value);
                }
#line 2007 "y.tab.cpp"
    break;

  case 61: /* math_operator: MUL  */
#line 600 "parser.y"
                {
                        string *op=new string("imul");
                        (yyval.str_value)=op;
                }
#line 2016 "y.tab.cpp"
    break;

  case 62: /* math_operator: DIV  */
#line 605 "parser.y"
                {
                        string *op=new string("idiv");
                        (yyval.str_value)=op;
                }
#line 2025 "y.tab.cpp"
    break;

  case 63: /* math_operator: ADD  */
#line 610 "parser.y"
                {
                        string *op=new string("iadd");
                        (yyval.str_value)=op;
                }
#line 2034 "y.tab.cpp"
    break;

  case 64: /* math_operator: SUB  */
#line 615 "parser.y"
                {
                        string *op=new string("isub");
                        (yyval.str_value)=op;
                }
#line 2043 "y.tab.cpp"
    break;

  case 65: /* math_operator: MOD  */
#line 620 "parser.y"
                {
                        string *op=new string("irem");
                        (yyval.str_value)=op;
                }
#line 2052 "y.tab.cpp"
    break;

  case 66: /* logic_operator: ST  */
#line 627 "parser.y"
                {
                        string *op=new string("iflt");
                        (yyval.str_value)=op;
                }
#line 2061 "y.tab.cpp"
    break;

  case 67: /* logic_operator: BT  */
#line 632 "parser.y"
                {
                        string *op=new string("ifgt");
                        (yyval.str_value)=op;
                }
#line 2070 "y.tab.cpp"
    break;

  case 68: /* logic_operator: SET  */
#line 637 "parser.y"
                {
                        string *op=new string("ifle");
                        (yyval.str_value)=op;
                }
#line 2079 "y.tab.cpp"
    break;

  case 69: /* logic_operator: BET  */
#line 642 "parser.y"
                {
                        string *op=new string("ifge");
                        (yyval.str_value)=op;
                }
#line 2088 "y.tab.cpp"
    break;

  case 70: /* logic_operator: EQL  */
#line 647 "parser.y"
                {
                        string *op=new string("ifeq");
                        (yyval.str_value)=op;
                }
#line 2097 "y.tab.cpp"
    break;

  case 71: /* logic_operator: NEQ  */
#line 652 "parser.y"
                {
                        string *op=new string("ifne");
                        (yyval.str_value)=op;
                }
#line 2106 "y.tab.cpp"
    break;

  case 72: /* bit_operator: AND  */
#line 659 "parser.y"
                {
                        string *op=new string("iand");
                        (yyval.str_value)=op;
                }
#line 2115 "y.tab.cpp"
    break;

  case 73: /* bit_operator: OR  */
#line 664 "parser.y"
                {
                        string *op=new string("ior");
                        (yyval.str_value)=op;
                }
#line 2124 "y.tab.cpp"
    break;

  case 74: /* bit_operator: NOT  */
#line 669 "parser.y"
                {
                        string *op=new string("ixor");
                        (yyval.str_value)=op;
                }
#line 2133 "y.tab.cpp"
    break;

  case 75: /* components: literal_constant  */
#line 677 "parser.y"
                {
                        switch ((yyvsp[0].value)->value_type)
                        {
                        case VALUE_INT:
                                jasm("sipush " + (yyvsp[0].value)->display());
                                break;
                        case VALUE_BOOL:
                                jasm("iconst_" + (yyvsp[0].value)->display());
                                break;
                        case VALUE_FLOAT:
                                jasm("sipush " + (yyvsp[0].value)->display());
                                break;
                        case VALUE_STR:
                                jasm("ldc \"" + (yyvsp[0].value)->display() + "\"");
                                break;
                        default:
                                break;
                        }
                        (yyval.value)=(yyvsp[0].value);
                }
#line 2158 "y.tab.cpp"
    break;

  case 76: /* components: var_refer  */
#line 698 "parser.y"
                {
                        (yyval.value)=(yyvsp[0].value);
                }
#line 2166 "y.tab.cpp"
    break;

  case 77: /* components: fun_invoc  */
#line 702 "parser.y"
                {
                        (yyval.value)=(yyvsp[0].value);
                }
#line 2174 "y.tab.cpp"
    break;

  case 78: /* components: arr_refer  */
#line 706 "parser.y"
                {
                        (yyval.value)=(yyvsp[0].symbol)->value;
                }
#line 2182 "y.tab.cpp"
    break;

  case 79: /* literal_constant: C_INT  */
#line 712 "parser.y"
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_INT;
                                value->int_value=(yyvsp[0].int_value);
                                (yyval.value)=value;
                        }
#line 2193 "y.tab.cpp"
    break;

  case 80: /* literal_constant: C_FLOAT  */
#line 719 "parser.y"
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_FLOAT;
                                value->float_value=(yyvsp[0].float_value);
                                (yyval.value)=value;
                        }
#line 2204 "y.tab.cpp"
    break;

  case 81: /* literal_constant: C_STR  */
#line 726 "parser.y"
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_STR;
                                value->string_value=*(yyvsp[0].str_value);
                                (yyval.value)=value;
                        }
#line 2215 "y.tab.cpp"
    break;

  case 83: /* literal_constant_bool: TRUE  */
#line 735 "parser.y"
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_BOOL;
                                value->bool_value=true;
                                (yyval.value)=value;
                        }
#line 2226 "y.tab.cpp"
    break;

  case 84: /* literal_constant_bool: FALSE  */
#line 742 "parser.y"
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_BOOL;
                                value->bool_value=false;
                                (yyval.value)=value;
                        }
#line 2237 "y.tab.cpp"
    break;

  case 85: /* var_refer: ID  */
#line 751 "parser.y"
                {
                        Symbol* symbol = symbolTableStack.lookup(*(yyvsp[0].str_value));
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }

                        if(symbol->id_type==ID_CONST){
                                symbolTableStack.load_value(symbol);
                        }else{ 
                                if(symbol->is_global){
                                        jasm("getstatic "+ValueTypeToString(symbol->value->value_type)+" "+symbolTableStack.program_name+"."+symbol->name);
                                }else{
                                        symbolTableStack.load_value(symbol);
                                }
                        }
                        (yyval.value) = symbol->value;
                }
#line 2260 "y.tab.cpp"
    break;

  case 86: /* arr_refer: ID LSB int_expression RSB  */
#line 772 "parser.y"
                {
                        Symbol* symbol = symbolTableStack.lookup(*(yyvsp[-3].str_value));
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }else if (symbol->id_type!=ID_ARR)
                        {
                                yyerror("ID is not array");
                        }
                        (yyval.symbol) = symbol;
                }
#line 2276 "y.tab.cpp"
    break;

  case 87: /* $@7: %empty  */
#line 787 "parser.y"
        {
                
        }
#line 2284 "y.tab.cpp"
    break;

  case 88: /* $@8: %empty  */
#line 791 "parser.y"
        {
                
        }
#line 2292 "y.tab.cpp"
    break;

  case 94: /* $@9: %empty  */
#line 807 "parser.y"
                        {
                                jasm("ifeq L"+to_string(symbolTableStack.tag));
                        }
#line 2300 "y.tab.cpp"
    break;

  case 95: /* $@10: %empty  */
#line 810 "parser.y"
                        {
                                jasm("goto L"+to_string(symbolTableStack.tag+1));
                                jasm("L"+to_string(symbolTableStack.tag)+":");
                                symbolTableStack.tag+=1;
                        }
#line 2310 "y.tab.cpp"
    break;

  case 97: /* else_statement: ELSE block_or_simple_statement  */
#line 818 "parser.y"
                        {
                                jasm("L"+to_string(symbolTableStack.tag)+":");
                                symbolTableStack.tag+=1;
                        }
#line 2319 "y.tab.cpp"
    break;

  case 98: /* else_statement: %empty  */
#line 823 "parser.y"
                        {
                                jasm("L"+to_string(symbolTableStack.tag)+":");
                                symbolTableStack.tag+=1;
                        }
#line 2328 "y.tab.cpp"
    break;

  case 99: /* $@11: %empty  */
#line 831 "parser.y"
                {
                        jasm("L"+to_string(symbolTableStack.tag)+":");
                        symbolTableStack.temp_tag=symbolTableStack.tag;
                        symbolTableStack.tag+=1;
                }
#line 2338 "y.tab.cpp"
    break;

  case 100: /* $@12: %empty  */
#line 836 "parser.y"
                {
                        jasm("Lifeq L"+to_string(symbolTableStack.tag));
                }
#line 2346 "y.tab.cpp"
    break;

  case 101: /* loop_statement: WHILE $@11 LB bool_expression RB $@12 block_or_simple_statement  */
#line 839 "parser.y"
                {
                        jasm("goto L"+to_string(symbolTableStack.temp_tag));
                        jasm("L"+to_string(symbolTableStack.tag)+":");       
                }
#line 2355 "y.tab.cpp"
    break;

  case 102: /* $@13: %empty  */
#line 844 "parser.y"
                {
                        jasm("sipush "+(yyvsp[-4].value)->display());
                        jasm("istore 1");
                        jasm("L"+to_string(symbolTableStack.tag)+":");
                        jasm("iload 1");
                        jasm("sipush "+(yyvsp[-1].value)->display());
                        jasm("isub");
                        jasm("ifle L"+to_string(symbolTableStack.tag+1));
                        jasm("iconst_0");
                        jasm("goto L"+to_string(symbolTableStack.tag+2));

                        jasm("L"+to_string(symbolTableStack.tag+1));
                        jasm("iconst_1");

                        jasm("L"+to_string(symbolTableStack.tag+2));
                        jasm("Lifeq L"+to_string(symbolTableStack.tag+3));
                }
#line 2377 "y.tab.cpp"
    break;

  case 103: /* loop_statement: FOR LB ID num DOT DOT num RB $@13 block_or_simple_statement  */
#line 861 "parser.y"
                {
                        jasm("goto L"+to_string(symbolTableStack.tag));
                        jasm("L"+to_string(symbolTableStack.tag+3)+":");       
                        symbolTableStack.tag+=4;
                }
#line 2387 "y.tab.cpp"
    break;

  case 104: /* $@14: %empty  */
#line 869 "parser.y"
                                {       
                                        symbolTableStack.push("simple code block");

                                }
#line 2396 "y.tab.cpp"
    break;

  case 105: /* block_or_simple_statement: $@14 block  */
#line 873 "parser.y"
                                {
                                        symbolTableStack.pop();
                                }
#line 2404 "y.tab.cpp"
    break;

  case 107: /* fun_invoc: ID LB comma_separated_expressions RB  */
#line 881 "parser.y"
                {
                        Symbol* symbol = symbolTableStack.lookup(*(yyvsp[-3].str_value));
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }else if (symbol->id_type!=ID_FUNC)
                        {
                                yyerror("ID is not function");
                        }else{
                                for(int i=0;i<symbol->arguments.size();i++){
                                        if(symbolTableStack.parseStack[i]->value_type!=symbol->arguments[i]->value->value_type){
                                                TypeError(symbolTableStack.parseStack[i]->value_type,symbol->arguments[i]->value->value_type);
                                        }
                                }
                        }

                        symbolTableStack.parseStack.clear();


                        (yyval.value) = symbol->value;

                        // javaa                        
                        string arguments="";
                        for(int i=0;i<symbol->arguments.size();i++){
                                if(i!=0){
                                        arguments+=", ";
                                }
                                arguments+=ValueTypeToString(symbol->arguments[i]->value->value_type);
                        }
                        jasm("invokestatic "+ValueTypeToString(symbol->value->value_type)+" "+symbolTableStack.program_name+"."+symbol->name+"("+arguments+")");
                }
#line 2440 "y.tab.cpp"
    break;

  case 108: /* proc_invoc: ID LB comma_separated_expressions RB  */
#line 915 "parser.y"
                {
                        Symbol* symbol = symbolTableStack.lookup(*(yyvsp[-3].str_value));
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }else if (symbol->id_type!=ID_PROCEDURE)
                        {
                                yyerror("ID is not procedure");
                        }else{
                                for(int i=0;i<symbol->arguments.size();i++){
                                        if(symbolTableStack.parseStack[i]->value_type!=symbol->arguments[i]->value->value_type){
                                                TypeError(symbolTableStack.parseStack[i]->value_type,symbol->arguments[i]->value->value_type);
                                        }
                                }
                        }

                        symbolTableStack.parseStack.clear();


                        (yyval.value) = symbol->value;

                        // javaa                        
                        string arguments="";
                        for(int i=0;i<symbol->arguments.size();i++){
                                if(i!=0){
                                        arguments+=", ";
                                }
                                arguments+=ValueTypeToString(symbol->arguments[i]->value->value_type);
                        }
                        jasm("invokestatic "+ValueTypeToString(symbol->value->value_type)+" "+symbolTableStack.program_name+"."+symbol->name+"("+arguments+")");

                }
#line 2477 "y.tab.cpp"
    break;

  case 109: /* $@15: %empty  */
#line 950 "parser.y"
                                {
                                        symbolTableStack.parseStack.push_back((yyvsp[0].value));
                                }
#line 2485 "y.tab.cpp"
    break;

  case 111: /* comma_separated_expressions: expression  */
#line 954 "parser.y"
                                {
                                        symbolTableStack.parseStack.push_back((yyvsp[0].value));
                                }
#line 2493 "y.tab.cpp"
    break;

  case 112: /* num: C_INT  */
#line 961 "parser.y"
        {
                Value *value=new Value();
                value->value_type=VALUE_INT;
                value->int_value=(yyvsp[0].int_value);
                (yyval.value)=value;
        }
#line 2504 "y.tab.cpp"
    break;


#line 2508 "y.tab.cpp"

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

#line 969 "parser.y"


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

	yyin = fp;
	yyparse();

        jasm_file.close();

	fprintf( stdout, "\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	exit(0);
}
