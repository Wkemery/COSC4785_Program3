%{
  #include <iostream>
  #include<FlexLexer.h>
  using namespace std;
  /*
 * These are declared in "main" so that we can pass values between
 * the two portions of the program.
 */

//extern Node *tree;
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
  Node *ttype;
}

%token NUM

%%

input : /*empty*/
  | input line
;
line : '\n'
  |exp '\n' {
    //code
  }
;
exp : NUM {/*code*/}
;
%%
void yyerror(const char* s)
{
  cout << "error message" << endl;
}
