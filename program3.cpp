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
  
//     int rtn = 0;
//     int errCount = 0;
//     bool firstScan = true;
//     
    
//     while((rtn=myScanner.yylex()) != 0)
//     {
//       if(firstScan)
//       {
//         firstScan = false;
//         cout << setw(10) << "Line" << setw(10) << "Column" << setw(20)  << "Token" 
//         << setw(20) << "Value" << endl;
//       }
//       if(rtn == ERR)
//       {
//         if(rtn == ERR) errCount++;
//         
//         cout << setw(10) << token.line;
//         cout << setw(10) << token.column << " " ;
//         cout << setw(20) << token.value;
//         if(errCount > 20)
//         {
//           cout << setw(20) << " Too many Errors, exiting program" << endl;
//           exit(1);
//         }
//         if(token.value.length() == 1) cout << setw(20) << "Single Char Err";
//         else cout << setw(20) << "Multi Char Err";
//         cout << endl;
//       }
//       else if((rtn!= SPACE) && (rtn!= IGNORE))
//       {
//         cout << setw(10) << token.line;
//         cout << setw(10) << token.column;
//         cout << setw(20) << pTable[rtn];
//         if((rtn < 100) || (rtn > 150)) cout << setw(20) << token.value;
//         cout << endl;   
//       } 
//         
//     }
  
  return 0;
  
}
