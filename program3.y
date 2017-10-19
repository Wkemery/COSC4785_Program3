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

%token<token>IDENTIFIER
%token<token>SEMICO
%token<token>NUM

%type<ttype> expression
%type<ttype> name
%type<ttype> multibracks
%type<ttype> simpletype
%type<ttype> unaryop
%type<ttype> relationop
%type<ttype> productop
%type<ttype> sumop
%type<ttype> arglist
%type<ttype> optExprBrack

%type<ttype> newexpression

%type<ttype> exp

%precedence NAME
%precedence EXP
%left DOUBEQ NOTEQ LESSEQ GREATEQ LESS GREAT RE
%left PLUS MINUS DOUBBAR BIN
%left TIMES DIVIDE MOD DOUBAND PRO
%precedence NEG
%precedence OPTEXP
%precedence LBRACK
%precedence IDENTIFIER
%precedence LPAREN



%% 
input:  %empty
        | input exp { if($2!=0) forest.push_back($2); }
        /*error{yyerror("Language Error"); yyerrok;}*/
;

exp: IDENTIFIER IDENTIFIER SEMICO {
            $$ = new VarDec($1->value, $2->value);
            delete $1;
            delete $2;
            delete $3;
}
      | IDENTIFIER error SEMICO {
            $$ = 0;
            cerr << "Syntax Error before ; at " << $3->line << ":" << $3->column << endl << endl;
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
      | simpletype error SEMICO {
        $$ = 0;
        cerr << " -> before ; at " << $3->line << ":" << $3->column << endl << endl;
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
                                  $$->setErr();
                                  cerr << "Expected Semicolon " << " At "<< $2->line << ":" << $2->column <<endl << endl;
                                  yyerrok;
                                  delete $1;
                                  delete $2; 
}
      | simpletype IDENTIFIER error {
                                $$ = new VarDec("int", $2->value);
                                $$->setErr();
                                
                                  cerr << "Expected Semicolon " << " At "<< $2->line << ":" << $2->column <<endl << endl;
                                  yyerrok;
                                delete $2;
 }
;
       
expression: NUM { 
                $$ = new Expression($1->value, EXPNUM);
                delete $1;
}
            | NULLKEYWORD { 
                $$ = new Expression("null", EXPNULL); 
                delete $1;
            }
            | READ LPAREN RPAREN { 
                $$ = new Expression("read", EXPREAD); 
                delete $1;
                delete $2;
                delete $3;
            }
            | READ LPAREN error  {
                      $$ = new Expression("read", EXPREAD); 
                      $$->setErr();
                      
                      cerr << "Expected Right Parenthesis " << " At "<< $2->line << ":" << $2->column <<endl << endl;
                      yyerrok;
                      delete $1;
                      delete $2;
                     }
            | unaryop expression %prec NEG { $$ = new Expression($1, $2, EXPUNARY);}
            | expression relationop expression %prec RE{ 
                    $$ = new Expression($1, $2, $3, EXPRELATION); }
            | expression productop expression %prec PRO{
                    $$ = new Expression($1, $2, $3, EXPPRODUCT); }
            | expression sumop expression %prec BIN {
                    $$ = new Expression($1, $2, $3, EXPSUMOP); }
            | LPAREN expression RPAREN { 
                  $$ = new Expression($2, EXPPAREN);
                  delete $1;
                  delete $3;
            }
            | LPAREN expression error { 
                    $$ = new Expression($2, EXPPAREN);
                    $$->setErr();
                    cerr << "Expected Right Parenthesis " << " At "<< yylval.token->line << ":" << yylval.token->column <<endl << endl;
                    yyerrok;
                    delete $1;
            }
            | newexpression { if($1!= 0) $$ = new Expression($1, EXPNEW); else $$ = 0;}
            | name %prec NAME{$$ = new Expression($1, EXPNAME);}
            | name LPAREN arglist RPAREN {
                  $$ = new Expression($1, $3, EXPNAMEARG);
                  delete $2;
                  delete $4;
            }
            | name LPAREN arglist error {
                    $$ = new Expression($1, $3, EXPNAMEARG);
                    $$->setErr();
                    
                    cerr << "Expected Right Parenthesis " << " At "<< yylval.token->line << ":" << yylval.token->column <<endl << endl;
                    yyerrok;
                    delete $2;
            }
            
;
name: THIS { 
            $$ = new Name("this", NAMETHIS); 
            delete $1;
}
      | IDENTIFIER %prec NAME { 
            $$ = new Name($1->value, NAMEID);
            delete $1;
      }
      | name DOTOP IDENTIFIER { 
            $$ = new Name($1, $3->value, NAMEDOTID); 
            delete $3;
            delete $2;
      }
      | name LBRACK expression RBRACK { 
            $$ = new Name($1, $3, NAMEEXP);
            delete $2;
            delete $4;
      }
      | IDENTIFIER LBRACK expression RBRACK{
        $$ = new Name($3, $1->value, NAMEIDEXP);
        delete $2;
        delete $4;
      }
      | name LBRACK expression error { 
            $$ = new Name($1, $3, NAMEIDEXP);
            $$->setErr();
            yyerrok;
            delete $1;
      }
;
newexpression: NEW IDENTIFIER LPAREN arglist RPAREN {
                    $$ = new NewExpression($2->value, $4, NEWEXPARG);
                    delete $2;
                    delete $1;
                    delete $3;
                    delete $5;
}
              | NEW IDENTIFIER LPAREN arglist error {
                $$ = new NewExpression($2->value, $4, NEWEXPARG);
                $$->setErr();
                cerr << "Expected Right Parenthesis " << " At "<< $2->line << ":" << $2->column <<endl << endl;
                      yyerrok;
                      delete $2;
                      delete $1;
                      delete $3;
              }
              | NEW IDENTIFIER optExprBrack {
                if($3 != 0) ((BrackExpression*)$3)->reverse();
                if($3 == 0) $$ = new NewExpression($2->value, $3, 0, NEWEXP);
                else $$ = new NewExpression($2->value, $3, 0, NEWEXPBRACK);
                delete $2;
                delete $1;
              }
              | NEW IDENTIFIER optExprBrack multibracks {
                if($3 != 0) ((BrackExpression*)$3)->reverse();
                if($3 == 0) $$ = new NewExpression($2->value, $3, $4, NEWEXPMULTI);
                else $$ = new NewExpression($2->value, $3, $4, NEWEXPBRACKMULTI);
                delete $2;
                delete $1;
              }
              | NEW simpletype LPAREN arglist RPAREN {
                    $$ = new NewExpression("int", $4, NEWEXPARG);
                    delete $1;
                    delete $3;
                    delete $5;
              }
              | NEW simpletype LPAREN arglist error {
                $$ = new NewExpression("int", $4, NEWEXPARG);
                $$->setErr();
                cerr << "Expected Right Parenthesis " << " At "<< yylval.token->line << ":" << yylval.token->column <<endl << endl;
                      yyerrok;
                      delete $1;
                      delete $3;
              }
              | NEW simpletype optExprBrack {
                    if($3 != 0) ((BrackExpression*)$3)->reverse();
                    if($3 == 0) $$ =  new NewExpression("int", $3, 0,NEWEXP);
                    else $$=  new NewExpression("int", $3, 0,NEWEXPBRACK);
                    delete $1;
              }
              | NEW simpletype optExprBrack multibracks {
                if($3 != 0) ((BrackExpression*)$3)->reverse();
                if($3 == 0) $$=  new NewExpression("int", $3, $4, NEWEXPMULTI);
                else $$ =  new NewExpression("int", $3, $4, NEWEXPBRACKMULTI);
                delete $1;
              }
             | NEW error{ $$ = 0;
                  cerr << " -> after new at " << $1->line << ":" << $1->column << endl << endl; 
                  yyerrok;}
                  
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
/*optBrack:%empty %prec OPTEXP {$$ = 0;}
        | LBRACK RBRACK optBrack {
          $$ = new OptBracket($3);
          delete $1;
          delete $2;
        }
;*/

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

multibracks: LBRACK RBRACK {$$ = new Multibracks(); delete $1;}
| multibracks LBRACK RBRACK {$$ = new Multibracks($1); delete $2;}
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
