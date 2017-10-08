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

class Node
{
protected:
  vector<Node*> _subNodes;
public:
  virtual void print(ostream *out) = 0;
  virtual Node* getChild(unsigned int index) const;
};

class Identifier: public Node
{
private:
  string _value;
public:
  Identifier(string value);
  void print(ostream* out);
  string getVal(void);
};

class VarDec: public Node
{
private:
  string _id;
public:
  VarDec(Node* type, string id);
  void print(ostream* out);
};

class Type: public Node
{
private:
  bool _array;
public:
  Type(Node* SimpleType, bool array);
  void print(ostream* out);
};

class SimpleType: public Node
{
private:
  string _value;
public:
  SimpleType(string val);
  void print(ostream* out);
  Node* getChild(unsigned int index) const;
};

#endif