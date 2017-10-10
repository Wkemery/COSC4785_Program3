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
/* Some helpful Macros*/

#define IDNODE 1000
#define VARDECNODE 1001
#define TYPENODE 1002
#define SIMPLETYPENODE 1003
#define EXPRESSIONNODE 1004
#define NAMENODE 1005

class Node
{
protected:
  vector<Node*> _subNodes;
  int _nodeType;
  string _value;
  Node(int nodeType, string value);
public:
  virtual void print(ostream *out) = 0;
  int getType(void) const;
  virtual Node* getChild(unsigned int index) const;
  virtual string getVal(void) const;
};

class Name : public Node
{
private:
public:
  Name(string value);
  Name(Node* name, string value);
  Name(Node* name, Node* expression);
  void print(ostream* out);
};

class Expression : public Node
{
public:
  Expression(Node* name);
  Expression(string value);
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
//   VarDec(Node* vardec);
  string getID(void) const;
  void print(ostream* out);
};

class Type: public Node
{
private:
  bool _array;
public:
  Type(Node* simpletype, bool array);
//   Type(Node* type);
  string getVal(void) const;
  bool getArray();
  void print(ostream* out);
};

class SimpleType: public Node
{
public:
  SimpleType(string value);
//   SimpleType(Node* simpletype);
  void print(ostream* out);
  Node* getChild(unsigned int index) const;
};

#endif