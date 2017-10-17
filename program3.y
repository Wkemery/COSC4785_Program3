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

extern vector<Node*> forest;
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

%token ASSIGNOP 
%token DOTOP 
%token COMMA 

%token LPAREN
%token RPAREN
%token LBRACK
%token RBRACK
%token LBRACE
%token RBRACE

%token PLUS
%token MINUS
%token NOT

%token DOUBEQ
%token NOTEQ
%token LESSEQ
%token GREATEQ
%token LESS
%token GREAT

%token TIMES
%token DIVIDE
%token MOD
%token DOUBAND

%token DOUBBAR

%token<token>IDENTIFIER
%token SEMICO
%token<token>NUM

%type<ttype> expression
%type<ttype> name
/* %type<ttype> type */
%type<ttype> multibracks
%type<ttype> simpletype
%type<ttype> unaryop
%type<ttype> relationop
%type<ttype> productop
%type<ttype> sumop
%type<ttype> arglist
%type<ttype> optExprBrack
%type<ttype>optBrack

%type<ttype> newexpression

%type<ttype> exp

%precedence NAME
/* %precedence ARGL */
/* %precedence LBRACE */
%precedence EXP
%left DOUBEQ NOTEQ LESSEQ GREATEQ LESS GREAT RE
%left PLUS MINUS DOUBBAR BIN
%left TIMES DIVIDE MOD DOUBAND PRO
%precedence NEG
%precedence OPTEXP
%precedence LBRACK
/* %precedence RBRACK */
%precedence IDENTIFIER
%precedence LPAREN



%% 
input:  %empty
        | input exp { forest.push_back($2); }
       /* | error {yyerror("Error at end of Input");
                      yyclearin;
                      yyerrok;}*/
;

exp:  /*type IDENTIFIER SEMICO  {
                                  $$ = new VarDec($1, $2->value);
                                  delete $2;
                                }*/
      IDENTIFIER IDENTIFIER SEMICO {$$ = new VarDec($1->value, $2->value);}
      | IDENTIFIER multibracks IDENTIFIER SEMICO {$$ = new VarDec($1->value, $3->value, $2);}
      | simpletype IDENTIFIER SEMICO {$$ = new VarDec("int", $2->value);}
      | simpletype multibracks IDENTIFIER SEMICO {$$ = new VarDec("int", $3->value, $2);}
      | expression %prec EXP { $$ = $1; }

      | IDENTIFIER IDENTIFIER error {
                                  $$ = new VarDec($1->value, $2->value);
                                  delete $2;
                                  yyerror("Expected Semicolon");
                                  yyerrok;}
;
       
expression: NUM { $$ = new Expression($1->value);}
            | NULLKEYWORD { $$ = new Expression("null"); }
            | READ LPAREN RPAREN { $$ = new Expression("read"); }
            | READ LPAREN error  {
                      $$ = new Expression("read"); 
                      yyerror("Expected Right Parenthesis");
                      yyerrok;
                     }
            | unaryop expression %prec NEG { $$ = new Expression($1, $2);}
            | expression relationop expression %prec RE{ 
                    $$ = new Expression($1, $2, $3); }
            | expression productop expression %prec PRO{
                    $$ = new Expression($1, $2, $3); }
            | expression sumop expression %prec BIN {
                    $$ = new Expression($1, $2, $3); }
            | LPAREN expression RPAREN { $$ = new Expression($2);}
            | newexpression { $$ = new Expression($1);}
            | name %prec NAME{$$ = new Expression($1);}
            | name LPAREN arglist RPAREN {$$ = new Expression($1, $3);}
            
;
name: THIS { $$ = new Name("this"); }
      | IDENTIFIER %prec NAME { $$ = new Name($1->value);}
      | name DOTOP IDENTIFIER { $$ = new Name($1, $3->value); }
      | name LBRACK expression RBRACK { $$ = new Name($1, $3); cerr << "here";}
;
newexpression: NEW IDENTIFIER LPAREN arglist RPAREN {
                    $$ = new NewExpression($2->value, $4);}
              | NEW IDENTIFIER optExprBrack optBrack {
                    if($3 != 0) ((BrackExpression*)$3)->reverse();
                    $$=  new NewExpression($2->value, $3, $4);}
              | NEW simpletype LPAREN arglist RPAREN {
                    $$ = new NewExpression("int", $4);}
              | NEW simpletype optExprBrack optBrack {
                    if($3 != 0) ((BrackExpression*)$3)->reverse();
                    $$=  new NewExpression("int", $3, $4);}
                  

;
optExprBrack: %empty %prec OPTEXP{$$ = 0;}
              | optExprBrack LBRACK expression RBRACK %prec OPTEXP{
                    $$ = new BrackExpression($3, $1);}

;
optBrack:%empty %prec OPTEXP {$$ = 0;}
        | LBRACK RBRACK optBrack {$$ = new OptBracket($3);}
;

arglist: %empty {$$ = 0;}
          | expression COMMA arglist { $$ = new ArgList($1, $3);}
          | expression {$$ = new ArgList($1, 0);}
;
unaryop:  PLUS {$$ = new UnaryOp("+");}
          | MINUS {$$ = new UnaryOp("-");}
          | NOT {$$ = new UnaryOp("!");}

;

relationop: DOUBEQ {$$ = new RelationOp("==");}
            | NOTEQ {$$ = new RelationOp("!=");}
            | LESSEQ {$$ = new RelationOp("<=");}
            | GREATEQ {$$ = new RelationOp(">=");}
            | LESS {$$ = new RelationOp("<");}
            | GREAT {$$ = new RelationOp(">");}
;

productop:  TIMES {$$ = new ProductOp("*");}
            | DIVIDE {$$ = new ProductOp("/");}
            | MOD {$$ = new ProductOp("%");}
            | DOUBAND {$$ = new ProductOp("&&");}
;
sumop:  MINUS {$$ = new SumOp("-");}
        | PLUS {$$ = new SumOp("+");}
        | DOUBBAR {$$ = new SumOp("||");}
;
multibracks: LBRACK RBRACK {$$ = new Type();}
              | multibracks LBRACK RBRACK {$$ = new Type($1, true);}
;
/*type: simpletype  { $$ = new Type($1, false); }
      | type LBRACK RBRACK  {$$ = new Type($1, true); }
;*/

simpletype: INT {
                  $$ = new SimpleType("int");
                }
/*            | IDENTIFIER {
                  $$ = new SimpleType($1->value);
                }*/
;

%%
