/*
 * Lexeme.cpp
 * Author: Wyatt Emery
 * Date: SEP 27, 2017
 *
 * COSC 4785, Homework3
 *
 */

#include<iostream>
using namespace std;
#include"Lexeme.h"
#include"Node.h"
#include"program3_bison.h"
void setToken(char* yytext, int lineno, int column)
{
  
  if(yytext != NULL) yylval.token->value = yytext;
  else yylval.token->value = "";
//   cerr << "yylval.token->value = " << yylval.token->value << endl;;
  
  yylval.token->line = lineno;
  yylval.token->column = column;
}