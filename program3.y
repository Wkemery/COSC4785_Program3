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
%token<token>THIS 
%token IF 
%token ELSE 
%token WHILE 
%token RETURN
%token<token>PRINT
%token<token>READ
%token VOID
%token<token>NEW
%token<token>NULLKEYWORD

%token<token>INT 

%token ASSIGNOP 
%token<token>DOTOP 

%token<token>COMMA 

%token<token>LPAREN
%token<token>RPAREN
%token<token>LBRACK
%token<token>RBRACK
%token<token>LBRACE
%token<token>RBRACE

%token<token>PLUS
%token<token>MINUS
%token<token>NOT

%token<token>DOUBEQ
%token<token>NOTEQ
%token<token>LESSEQ
%token<token>GREATEQ
%token<token>LESS
%token<token>GREAT

%token<token>TIMES
%token<token>DIVIDE
%token<token>MOD
%token<token>DOUBAND

%token<token>DOUBBAR
%token<token>EMPTYBRACKS

%token<token>IDENTIFIER
%token<token>SEMICO
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
/* %precedence LBRACK */
/* %precedence RBRACK */
%precedence IDENTIFIER
%precedence LPAREN



%% 
input:  %empty
        | input exp { forest.push_back($2); }
        /*error{yyerror("Language Error"); yyerrok;}*/
;

exp: IDENTIFIER IDENTIFIER SEMICO {
            $$ = new VarDec($1->value, $2->value);
            delete $1;
            delete $2;
            delete $3;
}
      | IDENTIFIER multibracks IDENTIFIER SEMICO {$$ = new VarDec($1->value, $3->value, $2);
            delete $1;
            delete $3;
            delete $4;
      }
      | simpletype IDENTIFIER SEMICO {
            $$ = new VarDec("int", $2->value);
            delete $2;
            delete $3;
      }
      | simpletype multibracks IDENTIFIER SEMICO {
            $$ = new VarDec("int", $3->value, $2);
            delete $3;
            delete $4;
      }
      | expression %prec EXP { $$ = $1; }

      | IDENTIFIER IDENTIFIER error {
                                  $$ = new VarDec($1->value, $2->value);
                                  delete $1;
                                  delete $2;
                                  yyerror("Expected Semicolon");
                                  yyerrok;}
      | simpletype IDENTIFIER error {
                                $$ = new VarDec("int", $2->value);
                                delete $2;
                                yyerror("Expected Semicolon");
                                yyerrok; }
;
       
expression: NUM { 
                $$ = new Expression($1->value);
                delete $1;
}
            | NULLKEYWORD { 
                $$ = new Expression("null"); 
                delete $1;
            }
            | READ LPAREN RPAREN { 
                $$ = new Expression("read"); 
                delete $1;
                delete $2;
                delete $3;
            }
            | READ LPAREN error  {
                      $$ = new Expression("read"); 
                      yyerror("Expected Right Parenthesis");
                      yyerrok;
                      delete $1;
                      delete $2;
                     }
            | unaryop expression %prec NEG { $$ = new Expression($1, $2);}
            | expression relationop expression %prec RE{ 
                    $$ = new Expression($1, $2, $3); }
            | expression productop expression %prec PRO{
                    $$ = new Expression($1, $2, $3); }
            | expression sumop expression %prec BIN {
                    $$ = new Expression($1, $2, $3); }
            | LPAREN expression RPAREN { 
                  $$ = new Expression($2);
                  delete $1;
                  delete $3;
            }
            | LPAREN expression error { 
                    $$ = new Expression($2);
                    yyerror("Expected Right Parenthesis");
                    yyerrok;
                    delete $1;
            }
            | newexpression { $$ = new Expression($1);}
            | name %prec NAME{$$ = new Expression($1);}
            | name LPAREN arglist RPAREN {
                  $$ = new Expression($1, $3);
                  delete $2;
                  delete $4;
            }
            | name LPAREN arglist error {
                    $$ = new Expression($1, $3);
                    yyerror("Expected Right Parenthesis");
                    yyerrok;
                    delete $2;
            }
            
;
name: THIS { 
            $$ = new Name("this"); 
            delete $1;
}
      | IDENTIFIER %prec NAME { 
            $$ = new Name($1->value);
            delete $1;
      }
      | name DOTOP IDENTIFIER { 
            $$ = new Name($1, $3->value); 
            delete $3;
            delete $2;
      }
      | name LBRACK expression RBRACK { 
            $$ = new Name($1, $3); cerr << "here";
            delete $2;
            delete $4;
      }
      | name LBRACK expression error { 
            $$ = new Name($1, $3); cerr << "here";
            yyerror("Expected Right Bracket");
            yyerrok;
            delete $1;
      }
;
newexpression: NEW IDENTIFIER LPAREN arglist RPAREN {
                    $$ = new NewExpression($2->value, $4);
                    delete $2;
                    delete $1;
                    delete $3;
                    delete $5;
}
              | NEW IDENTIFIER LPAREN arglist error {
                      yyerror("Expected Right Parenthesis");
                      yyerrok;
                      $$ = new NewExpression($2->value, $4);
                      delete $2;
                      delete $1;
                      delete $3;
              }
              | NEW IDENTIFIER optExprBrack optBrack {
                    if($3 != 0) ((BrackExpression*)$3)->reverse();
                    $$=  new NewExpression($2->value, $3, $4);
                    delete $2;
                    delete $1;
              }
              | NEW simpletype LPAREN arglist RPAREN {
                    $$ = new NewExpression("int", $4);
                    delete $1;
                    delete $3;
                    delete $5;
              }
              | NEW simpletype LPAREN arglist error {
                      $$ = new NewExpression("int", $4);
                      yyerror("Expected Right Parenthesis");
                      yyerrok;
                      delete $1;
                      delete $3;
              }
              | NEW simpletype optExprBrack optBrack {
                    if($3 != 0) ((BrackExpression*)$3)->reverse();
                    $$=  new NewExpression("int", $3, $4);
                    delete $1;
              }
              | NEW error{yyerror("Expected something after new declaration"); yyerrok;}
                  
;
optExprBrack: %empty %prec OPTEXP{$$ = 0;}
              | optExprBrack LBRACK expression RBRACK %prec OPTEXP{
                    $$ = new BrackExpression($3, $1);
                    delete $2;
                    delete $4;
              }
/*              | optExprBrack LBRACK expression error %prec OPTEXP{
                      $$ = new BrackExpression($3, $1);
                      delete $2;
              }*/

;
optBrack:%empty %prec OPTEXP {$$ = 0;}
        | LBRACK RBRACK optBrack {
          $$ = new OptBracket($3);
          delete $1;
          delete $2;
        }
;

arglist: %empty {$$ = 0;}
          | expression COMMA arglist { 
            $$ = new ArgList($1, $3);
            delete $2;
          }
          | expression {$$ = new ArgList($1, 0);}
;
unaryop:  PLUS {$$ = new UnaryOp("+"); delete $1;}
| MINUS {$$ = new UnaryOp("-"); delete $1;}
| NOT {$$ = new UnaryOp("!"); delete $1;}

;

relationop: DOUBEQ {$$ = new RelationOp("=="); delete $1;}
| NOTEQ {$$ = new RelationOp("!="); delete $1;}
| LESSEQ {$$ = new RelationOp("<="); delete $1;}
| GREATEQ {$$ = new RelationOp(">="); delete $1;}
| LESS {$$ = new RelationOp("<"); delete $1;}
| GREAT {$$ = new RelationOp(">"); delete $1;}
;

productop:  TIMES {$$ = new ProductOp("*"); delete $1;}
| DIVIDE {$$ = new ProductOp("/"); delete $1;}
| MOD {$$ = new ProductOp("%"); delete $1;}
| DOUBAND {$$ = new ProductOp("&&"); delete $1;}
;
sumop:  MINUS {$$ = new SumOp("-"); delete $1;}
| PLUS {$$ = new SumOp("+"); delete $1;}
| DOUBBAR {$$ = new SumOp("||"); delete $1;}
;
multibracks: EMPTYBRACKS {$$ = new Type(); delete $1;}
| multibracks EMPTYBRACKS {$$ = new Type($1, true); delete $2;}
;
/*type: simpletype  { $$ = new Type($1, false); }
      | type LBRACK RBRACK  {$$ = new Type($1, true); }
;*/

simpletype: INT {
                  $$ = new SimpleType("int");
                  delete $1;
                }
/*            | IDENTIFIER {
                  $$ = new SimpleType($1->value);
                }*/
;

%%
