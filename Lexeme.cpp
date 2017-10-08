/*
 * Lexeme.cpp
 * Author: Wyatt Emery
 * Date: SEP 27, 2017
 *
 * COSC 4785, Homework3
 *
 */


#include"Lexeme.h"
#include"program3_bison.h"
void setToken(char* yytext, int lineno, int column)
{
  
  if(yytext != NULL) yylval.token->value = yytext;
  else yylval.token->value = "";
  yylval.token->line = lineno;
  yylval.token->column = column;
}