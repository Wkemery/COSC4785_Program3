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
vector<Node*> forest;

int main()
{
  
  
  yyparse();
  if(forest.size() > 0) cout << "PRINTING TREE\n" << endl;

  for(int i = 0; i < forest.size(); i++)
  {
    forest[i]->print(&cout);
    cout << endl;
  }
  
  
  return 0;
  
}
