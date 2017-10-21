/*
 * program3.y
 * Author: Wyatt Emery
 * Date: OCT 6, 2017
 * COSC 4785, Homework3
 */

%{


#include <iostream>
#include <FlexLexer.h>
#include "Node.h"
#include "Lexeme.h"

using namespace std;

extern vector<Node*> forest;
extern yyFlexLexer scanner;

#define yylex() scanner.yylex()

// need the function prototype for the parser.

void yyerror(const char *);

%}

%union {
  Node* ttype;
  Lexeme* token;

}

/* In many of the code blocks when matching productions, I have various to see 
 * if I'm building a "dirty" node tree. There are a few instances where I 
 * $$ = 0; I do this when I cannot create a full node based off of the 
 * information at hand. I've kept track of those instances and will have more 
 * checks for that in the future.
 */



%token<token> CLASS THIS IF ELSE WHILE RETURN PRINT READ VOID NEW NULLKEYWORD 

%token<token> INT ASSIGNOP DOTOP COMMA LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE

%token<token>PLUS MINUS NOT

%token<token>DOUBEQ NOTEQ LESSEQ GREATEQ LESS GREAT

%token<token>TIMES DIVIDE MOD DOUBAND DOUBBAR

%token<token>IDENTIFIER SEMICO NUM

%type<ttype> expression name multibracks simpletype unaryop relationop productop
%type<ttype> sumop arglist optExprBrack newexpression exp

%destructor {delete($$);} CLASS THIS IF ELSE WHILE RETURN PRINT READ VOID NEW 
%destructor {delete($$);} NULLKEYWORD INT ASSIGNOP DOTOP COMMA LPAREN RPAREN 
%destructor {delete($$);} LBRACK RBRACK LBRACE RBRACE PLUS MINUS NOT DOUBEQ 
%destructor {delete($$);} NOTEQ LESSEQ GREATEQ LESS GREAT TIMES DIVIDE MOD 
%destructor {delete($$);} DOUBAND DOUBBAR IDENTIFIER SEMICO NUM

%destructor {delete($$);} expression name multibracks simpletype unaryop 
%destructor {delete($$);} relationop productop sumop arglist optExprBrack 
%destructor {delete($$);} newexpression exp


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
        | input exp { 
          if($2!=0) 
          {
            if(!$2->getErr()) forest.push_back($2);
            else delete $2;
          }
        }
        | error{
          cerr << "Got no idea Around " << yylval.token->line << ":" 
          << yylval.token->column <<endl << endl; 
          yyclearin;
          yyerrok;
          
        }
;

exp: IDENTIFIER IDENTIFIER SEMICO {
            $$ = new VarDec($1->value, $2->value);
            delete $1;
            delete $2;
            delete $3;
}
      | IDENTIFIER error SEMICO {
            $$ = 0;
            cerr << "-> before ; at " << $3->line << ":" << $3->column << endl 
            << endl;
            yyerrok;
            delete $1;
            delete $3;
          }
      | IDENTIFIER multibracks IDENTIFIER SEMICO {
            $$ = new VarDec($1->value, $3->value, $2);
            delete $1;
            delete $3;
            delete $4;
      }
      | simpletype IDENTIFIER SEMICO {
            $$ = new VarDec("int", $2->value);
            delete $2;
            delete $3;
            delete $1;
      }
      | simpletype error SEMICO {
        $$ = 0;
        cerr << " -> before ; at " << $3->line << ":" << $3->column << endl << endl;
        yyerrok;
        delete $3;
        delete $1;
      }
      | simpletype multibracks IDENTIFIER SEMICO {
            $$ = new VarDec("int", $3->value, $2);
            delete $3;
            delete $4;
            delete $1;
      }
      | expression %prec EXP { $$ = $1; }

      | IDENTIFIER IDENTIFIER error {
                                  $$ = new VarDec($1->value, $2->value);
                                  $$->setErr();
                                  cerr << "Expected Semicolon At "<< $2->line 
                                  << ":" << $2->column+$2->value.length() 
                                  << endl << endl;
                                  yyerrok;
                                  delete $1;
                                  delete $2; 
}
      | simpletype IDENTIFIER error {
                            $$ = new VarDec("int", $2->value);
                            $$->setErr();
                              cerr << "Expected Semicolon At "<< $2->line << ":" 
                              << $2->column+$2->value.length() <<endl << endl;
                              yyerrok;
                            delete $2;
                            delete $1;
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
                      cerr << "Expected Right Parenthesis At "<< $2->line << ":" 
                      << $2->column <<endl << endl;
                      yyerrok;
                      delete $1;
                      delete $2;
                     }
            | unaryop expression %prec NEG { 
                    $$ = new Expression($1, $2, EXPUNARY); 
                    if($1->getErr()) $$->setErr();
                    if($2->getErr()) $$->setErr();}
            | unaryop error %prec NEG { 
                      $$ = new Expression($1, 0, EXPUNARY); 
                      $$->setErr();
                      cerr << "Expected expression after " << yylval.token->line 
                      << ":" << yylval.token->column << endl << endl;
                      yyerrok;
            }
            | expression relationop expression %prec RE{ 
                    $$ = new Expression($1, $2, $3, EXPRELATION);  
                    if($1->getErr()) $$->setErr();
                    if($2->getErr()) $$->setErr();
                    if($3->getErr()) $$->setErr();}
            | expression relationop error %prec RE{ 
                      $$ = new Expression($1, $2, 0, EXPRELATION);
                      $$->setErr();
                      cerr << "Expected expression after " << yylval.token->line 
                      << ":" << yylval.token->column << endl << endl;
                      yyerrok;
            }
            | expression productop expression %prec PRO{
                    $$ = new Expression($1, $2, $3, EXPPRODUCT); 
                    if($1->getErr()) $$->setErr();
                    if($2->getErr()) $$->setErr();
                    if($3->getErr()) $$->setErr();
            }
            | expression productop error %prec RE{ 
              $$ = new Expression($1, $2, 0, EXPPRODUCT);
              $$->setErr();
              cerr << "Expected expression after " << yylval.token->line 
              << ":" << yylval.token->column << endl << endl;
              yyerrok;
            }
            | expression sumop expression %prec BIN {
                    $$ = new Expression($1, $2, $3, EXPSUMOP); 
                    if($1->getErr()) $$->setErr();
                    if($2->getErr()) $$->setErr();
                    if($3->getErr()) $$->setErr();
            }
            | expression sumop error %prec RE{ 
              $$ = new Expression($1, $2, 0, EXPSUMOP);
              $$->setErr();
              cerr << "Expected expression after " << yylval.token->line 
              << ":" << yylval.token->column << endl << endl;
              yyerrok;
            }
            | LPAREN expression RPAREN { 
                  $$ = new Expression($2, EXPPAREN);
                  if($2->getErr()) $$->setErr();
                  delete $1;
                  delete $3;
            }
            | LPAREN expression error { 
                    $$ = new Expression($2, EXPPAREN);
                    $$->setErr();
                    cerr << "Expected Right Parenthesis At "
                    << yylval.token->line << ":" << yylval.token->column 
                    <<endl << endl;
                    yyerrok;
                    delete $1;
            }
            | newexpression { 
                            if($1!= 0) $$ = new Expression($1, EXPNEW); 
                            else $$ = 0;
                            if($1->getErr()) $$->setErr();
                            }
            | name %prec NAME{$$ = new Expression($1, EXPNAME);
                  if($1->getErr()) $$->setErr();}
            | name LPAREN arglist RPAREN {
                  $$ = new Expression($1, $3, EXPNAMEARG);
                  if($1->getErr()) $$->setErr();
                  if($3!= 0)
                  {
                    if($3->getErr()) $$->setErr();
                  }
                  delete $2;
                  delete $4;
            }
            | name LPAREN arglist error {
                    $$ = new Expression($1, $3, EXPNAMEARG);
                    $$->setErr();
                    cerr << "Expected Right Parenthesis At "
                    << yylval.token->line << ":" << yylval.token->column 
                    <<endl << endl;
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
            if($1->getErr()) $$->setErr();
            delete $3;
            delete $2;
      }
      | name LBRACK expression RBRACK { 
            $$ = new Name($1, $3, NAMEEXP);
            if($3->getErr()) $$->setErr();
            if($1->getErr()) $$->setErr();
            delete $2;
            delete $4;
      }
      | IDENTIFIER LBRACK expression RBRACK{
        $$ = new Name($3, $1->value, NAMEIDEXP);
        if($3->getErr()) $$->setErr();
        delete $1;
        delete $2;
        delete $4;
      }
      | IDENTIFIER LBRACK expression error{
        $$ = new Name($3, $1->value, NAMEIDEXP);
        $$->setErr();
        cerr << "Expected Right Bracket At " << yylval.token->line << ":" 
        << yylval.token->column << endl << endl;
        delete $2;
        delete $1;
      }
      | name LBRACK expression error { 
            $$ = new Name($1, $3, NAMEIDEXP);
            $$->setErr();
            cerr<< "Expected Right Bracket At " << yylval.token->line << ":"
            << yylval.token->column << endl << endl;
            yyerrok;
            delete $1;
            delete $2;
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
                cerr << "Expected Right Parenthesis At " << yylval.token->line 
                << ":" << yylval.token->column << endl << endl;
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
                    delete $2;
                    delete $3;
                    delete $5;
              }
              | NEW simpletype LPAREN arglist error {
                $$ = new NewExpression("int", $4, NEWEXPARG);
                $$->setErr();
                cerr << "Expected Right Parenthesis At " << yylval.token->line 
                << ":" << yylval.token->column <<endl << endl;
                      yyerrok;
                      delete $1;
                      delete $2;
                      delete $3;
              }
              | NEW simpletype optExprBrack {
                    if($3 != 0) ((BrackExpression*)$3)->reverse();
                    if($3 == 0) $$ =  new NewExpression("int", $3, 0,NEWEXP);
                    else $$=  new NewExpression("int", $3, 0,NEWEXPBRACK);
                    delete $1;
                    delete $2;
              }
              | NEW simpletype optExprBrack multibracks {
                if($3 != 0) ((BrackExpression*)$3)->reverse();
                if($3 == 0) $$=  new NewExpression("int", $3, $4, NEWEXPMULTI);
                else $$ =  new NewExpression("int", $3, $4, NEWEXPBRACKMULTI);
                delete $1;
                delete $2;
              }
             | NEW error{ $$ = 0;
                  cerr << " -> after new at " << $1->line << ":" << $1->column 
                  << endl << endl; 
                  yyerrok;}
                  
;
optExprBrack: %empty %prec OPTEXP{$$ = 0;}
              | optExprBrack LBRACK expression RBRACK %prec OPTEXP{
                    $$ = new BrackExpression($3, $1);
                    delete $2;
                    delete $4;
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

multibracks: LBRACK RBRACK {$$ = new Multibracks(); delete $1; delete $2;}
| multibracks LBRACK RBRACK {$$ = new Multibracks($1); delete $3;delete $2;}
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
