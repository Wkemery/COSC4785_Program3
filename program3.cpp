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
#include<iomanip>
#include"Lexeme.h"
#include"program3_bison.hpp"
using namespace std;


int main()
{
  //for printing stuff out for now
  map<int, string> pTable;
  pTable.insert(std::pair<int, string>(UNARYOP, "UNARYOP"));
  pTable.insert(std::pair<int, string>(RELATIONOP, "RELATOP"));
  pTable.insert(std::pair<int, string>(SUMOP, "SUMOP"));
  pTable.insert(std::pair<int, string>(PRODUCTOP, "PRODOP"));
  pTable.insert(std::pair<int, string>(ASSIGNOP, "ASSIGOP"));
  
  pTable.insert(std::pair<int, string>(CLASS, "CLASS"));
  pTable.insert(std::pair<int, string>(THIS, "THIS"));
  pTable.insert(std::pair<int, string>(IF, "IF"));
  pTable.insert(std::pair<int, string>(ELSE, "ELSE"));
  pTable.insert(std::pair<int, string>(WHILE, "WHILE"));
  pTable.insert(std::pair<int, string>(RETURN, "RETURN"));
  pTable.insert(std::pair<int, string>(PRINT, "PRINT"));
  pTable.insert(std::pair<int, string>(PRINT, "READ"));
  pTable.insert(std::pair<int, string>(VOID, "VOID"));
  pTable.insert(std::pair<int, string>(NEW, "NEW"));
  pTable.insert(std::pair<int, string>(NULLKEYWORD, "NULL"));
  pTable.insert(std::pair<int, string>(INT, "INT"));
    
  pTable.insert(std::pair<int, string>(DOTOP, "DOTOP"));
  pTable.insert(std::pair<int, string>(COMMA, "COMMA"));
  pTable.insert(std::pair<int, string>(SEMICO, "SEMICO"));
  pTable.insert(std::pair<int, string>(LPAREN, "LPAREN"));
  pTable.insert(std::pair<int, string>(RPAREN, "RPAREN"));  
  pTable.insert(std::pair<int, string>(LBRACK, "LBRACK"));
  pTable.insert(std::pair<int, string>(RBRACK, "RBRACK"));
  pTable.insert(std::pair<int, string>(LBRACE, "LBRACE"));
  pTable.insert(std::pair<int, string>(RBRACE, "RBRACE"));
          
  pTable.insert(std::pair<int, string>(IDENTIFIER, "ID"));
  pTable.insert(std::pair<int, string>(ERR, "ERR"));
  pTable.insert(std::pair<int, string>(NUM, "NUM"));
  /****************************************************************************/
  
    yyFlexLexer myScanner;
    int rtn = 0;
    int errCount = 0;
    bool firstScan = true;
    
    
    while((rtn=myScanner.yylex()) != 0)
    {
      if(firstScan)
      {
        firstScan = false;
        cout << setw(10) << "Line" << setw(10) << "Column" << setw(20)  << "Token" 
        << setw(20) << "Value" << endl;
      }
      if(rtn == ERR)
      {
        if(rtn == ERR) errCount++;
        
        cout << setw(10) << token.line;
        cout << setw(10) << token.column << " " ;
        cout << setw(20) << token.value;
        if(errCount > 20)
        {
          cout << setw(20) << " Too many Errors, exiting program" << endl;
          exit(1);
        }
        if(token.value.length() == 1) cout << setw(20) << "Single Char Err";
        else cout << setw(20) << "Multi Char Err";
        cout << endl;
      }
      else if((rtn!= SPACE) && (rtn!= IGNORE))
      {
        cout << setw(10) << token.line;
        cout << setw(10) << token.column;
        cout << setw(20) << pTable[rtn];
        if((rtn < 100) || (rtn > 150)) cout << setw(20) << token.value;
        cout << endl;   
      } 
        
    }
  
    return 0;
  
}
