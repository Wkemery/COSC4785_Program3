/*
 * program3.cpp
 * Author: Wyatt Emery
 * Date: SEP 27, 2017
 *
 * COSC 4785, Homework3
 *
 */

#include<iostream>
#include<FlexLexer.h>
#include<string>
#include<map>
#include<cstdlib>
#include"Lexeme.h"
#include"Node.h"
#include"program3_bison.h"
using namespace std;

yyFlexLexer scanner;
Node* tree;

int main()
{
  tree=0;
  
  
  yyparse();
  cout << "PRINTING TREE\n" << endl;
  tree->print(&cout);
  cout << endl;
  
  
  return 0;
  
}
