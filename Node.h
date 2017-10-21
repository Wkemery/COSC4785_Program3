/*
 * Node.h
 * Author: Wyatt Emery
 * Date: OCT 6, 2017
 *
 * COSC 4785, Homework3
 *
 */

#include<vector>
#include<string>
#include<stack>
using namespace std;
#ifndef NODE_H
#define NODE_H

/* These are all for finding out the kind of node. It helps with printing*/
#define PLAIN 1000
#define EXPNUM 1001 /*Expression ->  */
#define EXPNULL 1002 /*Expression ->  */
#define EXPREAD 1003 /*Expression ->  */
#define EXPUNARY 1004 /*Expression ->  */
#define EXPRELATION 1005 /*Expression -> */
#define EXPPRODUCT 1006 /*Expression -> */
#define EXPSUMOP 1007 /* Expression ->  */
#define EXPPAREN 1008 /* Expression -> */
#define EXPNEW 1009 /* Expression -> */
#define EXPNAME 1010 /* Expression -> */
#define EXPNAMEARG 1011 /* Expression -> */

#define NAMETHIS 2001 /* Name -> */
#define NAMEID 2002 /* Name -> */
#define NAMEDOTID 2003 /* Name -> */
#define NAMEEXP 2004 /* Name -> */
#define NAMEIDEXP 2005 /* Name -> */

#define NEWEXPARG 3001 /* NewExpression -> */
#define NEWEXPBRACK 3002 /* NewExpression -> */
#define NEWEXPBRACKMULTI 3003 /* NewExpression -> */
#define NEWEXPMULTI 3004 /* NewExpression -> */
#define NEWEXP 3005 /* NewExpression -> */

class Node
{
protected:
  vector<Node*> _subNodes;
  const string _value;
  const string _type;
  const int _kind;
  bool _err;
  Node(string value, string type, int kind);
public:
  virtual ~Node();
  virtual void print(ostream *out) = 0;
  void setErr();
  bool getErr();
  string getType(void) const;
};

class UnaryOp : public Node
{
public:
  UnaryOp(string value);
  void print(ostream* out);
};

class RelationOp : public Node
{
public:
  RelationOp(string value);
  void print(ostream* out);
};

class ProductOp : public Node
{
public:
  ProductOp(string value);
  void print(ostream* out);
};

class SumOp : public Node
{
public:
  SumOp(string value);
  void print(ostream* out);
};

class Name : public Node
{
public:
  Name(string value, int kind);
  Name(Node* name, string value, int kind);
  Name(Node* name, Node* expression, int kind);
  void print(ostream* out);
};

class Expression : public Node
{
public:
  Expression(Node* next, int kind);
  Expression(string value, int kind);
  Expression(Node* unaryop, Node* expression, int kind);
  Expression(Node* expression1, Node* op, Node* expression2, int kind);
  void print(ostream* out);
};

class BrackExpression : public Node
{
private:
  bool _array;
  void recAdd(stack<Node*> & expressions);
  void recReverse(stack<Node*> & expressions);
public:
  BrackExpression(Node* expression1, Node* expression2);
  void reverse();
  void print(ostream* out);
};

class OptBracket : public Node
{
private:
  bool _array;
public:
  OptBracket(Node* expression);
  void print(ostream* out);
};

class ArgList : public Node
{
private: 
  bool _empty;
public:
  ArgList(Node* expression1, Node* expression2);
  bool getEmpty() const ;
  void print(ostream* out);
};

class NewExpression : public Node
{
public:
  NewExpression(string simpletype, Node* arglist, int kind);
  NewExpression(string simpletype, Node* type2 , Node* brackexp, int kind);
  void print(ostream* out);
};


class VarDec: public Node
{
private:
  string _type;
public:
  VarDec(string type, string id);
  VarDec(string type, string id, Node* bracks);
  VarDec(Node* type, string id, Node* bracks);
  string getID(void) const;
  void print(ostream* out);
};

class Multibracks: public Node
{
public:
  Multibracks(Node* simpletype);
  Multibracks();
  void print(ostream* out);
};

class SimpleType: public Node
{
public:
  SimpleType(string value);
  void print(ostream* out);
};

#endif