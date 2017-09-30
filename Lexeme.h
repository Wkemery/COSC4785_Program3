/*
 * Lexeme.h
 * Author: Wyatt Emery
 * Date: SEP 27, 2017
 *
 * COSC 4785, Homework3
 *
 */


#include<string>


#define UNARYOP 50
#define RELATIONOP 51
#define SUMOP 52
#define PRODUCTOP 53
#define CLASS 100
#define THIS 101
#define IF 102
#define ELSE 103
#define WHILE 104
#define RETURN 105
#define PRINT 106
#define READ 107
#define VOID 108
#define NEW 109
#define NULLKEYWORD 110
#define INT 111

#define ASSIGNOP 120 
#define DOTOP 121
#define COMMA 122
#define SEMICO 123
#define LPAREN 124
#define RPAREN 125
#define LBRACK 126
#define RBRACK 127
#define LBRACE 128
#define RBRACE 129

#define NUM 14
#define IDENTIFIER 17
#define SPACE 10

#define ERR 666 
#define IGNORE 987


typedef struct lexeme Lexeme;

#ifndef PROGRAM1_H
#define PROGRAM1_H

extern Lexeme token;

struct lexeme
{
  std::string value;
  int column;
  int line;
};

extern void setToken(char* yytext, int yylineno, int column);
#endif
