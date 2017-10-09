/*
 * program3.y
 * Author: Wyatt Emery
 * Date: OCT 6, 2017
 * 
 * COSC 4785, Homework3
 *
 */

%{


#include <iostream>
#include <FlexLexer.h>
#include "Node.h"
#include "Lexeme.h"

//using namespace std;
using std::cerr;
using std::cout;
using std::endl;

/*
 * These are declared in "main" so that we can pass values between
 * the two portions of the program.
 */

extern Node* tree;
extern yyFlexLexer scanner;

/* 
 * Need to do this define, an "acceptable" hack to interface
 * the C++ scanner with the C parser. 
 */

#define yylex() scanner.yylex()

// need the function prototype for the parser.

void yyerror(const char *);



%}

%union {
  Node* ttype;
  Lexeme* token;

}

/* 
 * Bison declarations.  All the 'names' here will be put into an enum
 * in the *.tab.h file. Include that in the .l/.lpp file and then "return NUM;"
 * passes back the value. 
 *
 * To assign pass the parser a value, say for NUM, you must use 
 * yylval.ttype in the scanner. You could have a number of things in the union
 * but do not get cute. pointers, char, int, double. DO NOT use a class or 
 * struct. 
 *
 * The "exp" is only used here in this file but must be given a type if 
 *(in this case) it is ever assigned a value. See the rules.
 */

%token UNARYOP 
%token RELATIONOP
%token SUMOP 
%token PRODUCTOP
%token CLASS 
%token THIS 
%token IF 
%token ELSE 
%token WHILE 
%token RETURN
%token PRINT
%token READ
%token VOID
%token NEW
%token NULLKEYWORD
%token INT 
%token NUM

%token ASSIGNOP 
%token DOTOP 
%token COMMA 

%token LPAREN
%token RPAREN
%token LBRACK
%token RBRACK
%token LBRACE
%token RBRACE



%token<token>IDENTIFIER
%token SEMICO



%type<ttype> type
%type<ttype> simpletype

%type<ttype> exp

%% /* The grammar follows.  */
input:  %empty
        | exp {
              /* 
              * We have reached the end of the input and
              * now we are passing the results to the main function.
              */
              tree=$1;
/*               cerr << "tree:" << tree << endl; */
            }
;

exp:  type IDENTIFIER SEMICO  {
                    $$ = new VarDec($1, $2->value);
                    //delete $1;
                    delete $2;
/*                     cerr << "value: " << $2->value << endl; */
                  }
;

type: simpletype  {
                    $$ = new Type($1, false); 
                  }
      | type LBRACK RBRACK  {
                    $$ = new Type($1, true);
                  }
;

simpletype: INT {
                  $$ = new SimpleType("int");
                }
            | IDENTIFIER  {
                  $$ = new SimpleType($1->value);
                }
;
%%
