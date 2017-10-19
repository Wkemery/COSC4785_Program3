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
#define NAMEEX 1001 /*Expression -> Name */
#define NEWEX 1002 /*Expression -> NewExpression*/
#define EXPRESSN 1003 /*Expression -> (Expression)*/
#define UNARYEX 1004 /* Expression -> UnaryOp Expression*/
#define NAMEARG 1005 /* Expression -> Name(ArgList)*/
#define RELEX 1006 /* Expression -> Expression RelationOp Expression*/
#define SUMEX 1007 /* Expression -> Expression SumOp Expression*/
#define PRODEX 1008 /* Expression -> Expression ProductOp Expression*/

class Node
{
protected:
  vector<Node*> _subNodes;
  string _value;
  const string _type;
  Node(string value, string type);
public:
  virtual ~Node();
  virtual void print(ostream *out) = 0;
  virtual Node* getChild(unsigned int index) const;
  virtual string getVal(void) const;
  string getType(void) const;
};

class UnaryOp : public Node
{
public:
  UnaryOp(string value);
  ~UnaryOp();
  void print(ostream* out);
  Node* getChild(unsigned int index) const;
};

class RelationOp : public Node
{
public:
  RelationOp(string value);
  ~RelationOp();
  void print(ostream* out);
  Node* getChild(unsigned int index) const;
};

class ProductOp : public Node
{
public:
  ProductOp(string value);
  ~ProductOp();
  void print(ostream* out);
  Node* getChild(unsigned int index) const;
};

class SumOp : public Node
{
public:
  SumOp(string value);
  ~SumOp();
  void print(ostream* out);
  Node* getChild(unsigned int index) const;
};

class Name : public Node
{
public:
  Name(string value);
  Name(Node* name, string value);
  Name(Node* name, Node* expression);
  ~Name();
  void print(ostream* out);
};

class Expression : public Node
{
private:
  int _kind;
public:
  Expression(Node* next);
  Expression(string value);
  Expression(Node* unaryop, Node* expression);
  Expression(Node* expression1, Node* op, Node* expression2);
  ~Expression();
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
  ~BrackExpression();
  void reverse();
  void print(ostream* out);
};

class OptBracket : public Node
{
private:
  bool _array;
public:
  OptBracket(Node* expression);
  ~OptBracket();
  void print(ostream* out);
};

class ArgList : public Node
{
private: 
  bool _empty;
public:
  ArgList(Node* expression1, Node* expression2);
  ~ArgList();
  bool getEmpty() const ;
  void print(ostream* out);
};

class NewExpression : public Node
{
public:
  NewExpression(string simpletype, Node* arglist);
  NewExpression(string simpletype, Node* type2 , Node* brackexp);
  ~NewExpression();
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
  ~VarDec();
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
  ~Type();
  string getVal(void) const;
  bool getArray();
  void print(ostream* out);
};

class SimpleType: public Node
{
public:
  SimpleType(string value);
  ~SimpleType();
  void print(ostream* out);
  Node* getChild(unsigned int index) const;
};

#endif