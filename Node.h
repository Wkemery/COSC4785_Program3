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

class Node
{
protected:
  vector<Node*> _subNodes;
  const string _value;
  const string _type;
  const int _kind;
  Node(string value, string type, int kind);
public:
  virtual ~Node();
  virtual void print(ostream *out) = 0;
  virtual string getVal(void) const;
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
  Name(string value);
  Name(Node* name, string value);
  Name(Node* name, Node* expression);
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
  NewExpression(string simpletype, Node* arglist);
  NewExpression(string simpletype, Node* type2 , Node* brackexp);
  void print(ostream* out);
};


class VarDec: public Node
{
private:
  string _type;
public:
  VarDec(Node* type, string id);
  VarDec(string type, string id);
  VarDec(string type, string id, Node* bracks);
  string getID(void) const;
  void print(ostream* out);
};

class Type: public Node
{
private:
  bool _array;
public:
  Type(Node* simpletype, bool array);
  Type();
  string getVal(void) const;
  bool getArray();
  void print(ostream* out);
};

class SimpleType: public Node
{
public:
  SimpleType(string value);
  void print(ostream* out);
};

#endif