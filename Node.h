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
private:
  vector<Node*> _subNodes;
public:
  virtual void print(ostream *out = 0);
};

class Identifier: public Node
{
private:
  string _value;
public:
  string getVal(void);
  Identifier(string value);
};

#endif