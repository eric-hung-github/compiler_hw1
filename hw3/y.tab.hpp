/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    C_STR = 259,                   /* C_STR  */
    C_INT = 260,                   /* C_INT  */
    TRUE = 261,                    /* TRUE  */
    FALSE = 262,                   /* FALSE  */
    C_FLOAT = 263,                 /* C_FLOAT  */
    SEMICOLON = 264,               /* SEMICOLON  */
    COMMA = 265,                   /* COMMA  */
    FAN = 266,                     /* FAN  */
    MO = 267,                      /* MO  */
    ARROW = 268,                   /* ARROW  */
    DOT = 269,                     /* DOT  */
    LB = 270,                      /* LB  */
    RB = 271,                      /* RB  */
    LCB = 272,                     /* LCB  */
    RCB = 273,                     /* RCB  */
    LSB = 274,                     /* LSB  */
    RSB = 275,                     /* RSB  */
    ADD = 276,                     /* ADD  */
    SUB = 277,                     /* SUB  */
    MUL = 278,                     /* MUL  */
    DIV = 279,                     /* DIV  */
    MOD = 280,                     /* MOD  */
    BT = 281,                      /* BT  */
    ST = 282,                      /* ST  */
    SET = 283,                     /* SET  */
    BET = 284,                     /* BET  */
    EQL = 285,                     /* EQL  */
    NEQ = 286,                     /* NEQ  */
    AND = 287,                     /* AND  */
    OR = 288,                      /* OR  */
    NOT = 289,                     /* NOT  */
    ASIGN = 290,                   /* ASIGN  */
    ADDASIGN = 291,                /* ADDASIGN  */
    SUBASIGN = 292,                /* SUBASIGN  */
    MULASIGN = 293,                /* MULASIGN  */
    DIVASIGN = 294,                /* DIVASIGN  */
    BOOL = 295,                    /* BOOL  */
    BREAK = 296,                   /* BREAK  */
    CHAR = 297,                    /* CHAR  */
    CASE = 298,                    /* CASE  */
    CLASS = 299,                   /* CLASS  */
    CONTINUE = 300,                /* CONTINUE  */
    DECLARE = 301,                 /* DECLARE  */
    DO = 302,                      /* DO  */
    ELSE = 303,                    /* ELSE  */
    EXIT = 304,                    /* EXIT  */
    FLOAT = 305,                   /* FLOAT  */
    FOR = 306,                     /* FOR  */
    FUN = 307,                     /* FUN  */
    IF = 308,                      /* IF  */
    INT = 309,                     /* INT  */
    LOOP = 310,                    /* LOOP  */
    PRINT = 311,                   /* PRINT  */
    PRINTLN = 312,                 /* PRINTLN  */
    RETURN = 313,                  /* RETURN  */
    STRING = 314,                  /* STRING  */
    VAL = 315,                     /* VAL  */
    VAR = 316,                     /* VAR  */
    WHILE = 317                    /* WHILE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define C_STR 259
#define C_INT 260
#define TRUE 261
#define FALSE 262
#define C_FLOAT 263
#define SEMICOLON 264
#define COMMA 265
#define FAN 266
#define MO 267
#define ARROW 268
#define DOT 269
#define LB 270
#define RB 271
#define LCB 272
#define RCB 273
#define LSB 274
#define RSB 275
#define ADD 276
#define SUB 277
#define MUL 278
#define DIV 279
#define MOD 280
#define BT 281
#define ST 282
#define SET 283
#define BET 284
#define EQL 285
#define NEQ 286
#define AND 287
#define OR 288
#define NOT 289
#define ASIGN 290
#define ADDASIGN 291
#define SUBASIGN 292
#define MULASIGN 293
#define DIVASIGN 294
#define BOOL 295
#define BREAK 296
#define CHAR 297
#define CASE 298
#define CLASS 299
#define CONTINUE 300
#define DECLARE 301
#define DO 302
#define ELSE 303
#define EXIT 304
#define FLOAT 305
#define FOR 306
#define FUN 307
#define IF 308
#define INT 309
#define LOOP 310
#define PRINT 311
#define PRINTLN 312
#define RETURN 313
#define STRING 314
#define VAL 315
#define VAR 316
#define WHILE 317

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "parser.y"

    int id_type;
    int int_value;
    float float_value;
    bool bool_value;
    string* str_value;
    Value* value;
    Symbol* symbol;
    vector<Symbol*>* symbol_vector;

#line 202 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
