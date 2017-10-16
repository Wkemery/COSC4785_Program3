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
  virtual void print(ostream *out) = 0;
  virtual Node* getChild(unsigned int index) const;
  virtual string getVal(void) const;
  string getType(void) const;
};

class UnaryOp : public Node
{
public:
  UnaryOp(string value);
  void print(ostream* out);
  Node* getChild(unsigned int index) const;
};

class RelationOp : public Node
{
public:
  RelationOp(string value);
  void print(ostream* out);
  Node* getChild(unsigned int index) const;
};

class ProductOp : public Node
{
public:
  ProductOp(string value);
  void print(ostream* out);
  Node* getChild(unsigned int index) const;
};

class SumOp : public Node
{
public:
  SumOp(string value);
  void print(ostream* out);
  Node* getChild(unsigned int index) const;
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
private:
  int _kind;
public:
  Expression(Node* next);
  Expression(string value);
  Expression(Node* unaryop, Node* expression);
  Expression(Node* expression1, Node* op, Node* expression2);
  void print(ostream* out);
};

class BrackExpression : public Node
{
private:
  bool _array;
public:
  BrackExpression(Node* expression1, Node* expression2);
  BrackExpression(Node* expression);
  void print(ostream* out);
};

class ArgList : public Node
{
public:
  ArgList(Node* expression1, Node* expression2);
  void print(ostream* out);
};

class NewExpression : public Node
{
public:
  NewExpression(Node* simpletype, Node* arglist);
  NewExpression(Node* simpletype, Node* type2 , Node* brackexp);
  void print(ostream* out);
};

class Identifier: public Node
{
public:
  Identifier(string value);
  void print(ostream* out);
};

class VarDec: public Node
{
public:
  VarDec(Node* type, string id);
  string getID(void) const;
  void print(ostream* out);
};

class Type: public Node
{
private:
  bool _array;
public:
  Type(Node* simpletype, bool array);
  string getVal(void) const;
  bool getArray();
  void print(ostream* out);
};

class SimpleType: public Node
{
public:
  SimpleType(string value);
  void print(ostream* out);
  Node* getChild(unsigned int index) const;
};

#endif