/*
 * Lexeme.h
 * Author: Wyatt Emery
 * Date: SEP 27, 2017
 *
 * COSC 4785, Homework3
 *
 */


#include<string>



#define SPACE 10

#define ERR 666 
#define IGNORE 987




#ifndef LEXEME_H
#define LEXEME_H

typedef struct lexeme Lexeme;

struct lexeme
{
  std::string value;
  int column;
  int line;
};

extern void setToken(char* yytext, int yylineno, int column);
#endif
