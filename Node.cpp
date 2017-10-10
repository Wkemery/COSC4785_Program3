/*
 * Node.cpp
 * Author: Wyatt Emery
 * Date: OCT 6, 2017
 *
 * COSC 4785, Homework3
 *
 */

#include<iostream>
using namespace std;
#include"Node.h"


Node::Node(int nodeType, string value):_nodeType(nodeType), _value(value)
{}

int Node::getType(void) const
{ return _nodeType;}

Node* Node::getChild(unsigned int index) const
{
  if((index < (_subNodes.size())) && (index >= 0)) return _subNodes[index];
  else cerr << "Node:: Invalid index" << endl;
  return 0;
}

string Node::getVal(void) const {return _value;}
/******************************************************************************/

Name::Name(string value):Node(NAMENODE, value)
{}

Name::Name(Node* name, string value):Node(NAMENODE, value)
{
  _subNodes.push_back(name);
}

Name::Name(Node* name, Node* expression):Node(NAMENODE, "")
{
  _subNodes.push_back(name);
  _subNodes.push_back(expression);
}

void Name::print(ostream* out)
{
  return;
}
/******************************************************************************/

Expression::Expression(Node* name):Node(EXPRESSIONNODE, "")
{
  _subNodes.push_back(name);
}

Expression::Expression(string value):Node(EXPRESSIONNODE, value)
{}

void Expression::print(ostream* out)
{
  return;
}
/******************************************************************************/

Identifier::Identifier(string value = ""): Node(IDNODE, value)
{}

void Identifier::print(ostream *out)
{
  *out << _value << endl;
}

/******************************************************************************/

VarDec::VarDec(Node* type, string id):Node(VARDECNODE, id)
{
//   Type* temp = new Type((Type*)type);
//   _subNodes.push_back(temp);
  _subNodes.push_back(type);
}

// VarDec::VarDec(Node* vardec)
// {
//   Type* temp = new Type((vardec->getChild(0)));
//   _subNodes.push_back(temp);
//   _id = ((VarDec*) vardec)->getVal();
// }

void VarDec::print(ostream* out)
{
  *out << "<Variable Declaration> --> <type> " << _value << ";" << endl;
  _subNodes[0]->print(out);
}

/******************************************************************************/


Type::Type(Node* simpletype, bool array):Node(TYPENODE, "")
{
  if(array) _array = true;
  _subNodes.push_back(simpletype);
  
//   SimpleType* temp = new SimpleType(simpletype);
//   _subNodes.push_back(temp);
}

// Type::Type(Node* type)
// {
//   _array = ((Type*)type)->getArray();
//   Node* temp;
//   if(_array) temp = new Type(type->getChild(0));
//   else temp = new SimpleType(type->getChild(0));
//   _subNodes.push_back(temp);
// }

string Type::getVal(void) const
{
  cerr << "no _value on Type" << endl;
  return ""; 
}

bool Type::getArray()
{
  return _array;
}

void Type::print(ostream* out)
{
  *out << "<Type> --> ";
  if(_array) *out << "<Type>[]";
  else *out << "<SimpleType>";
  *out << endl;
  _subNodes[0]->print(out);
}


/******************************************************************************/


SimpleType::SimpleType(string value):Node(SIMPLETYPENODE, value)
{}


// SimpleType::SimpleType(Node* simpletype)
// {
//   _value = ((SimpleType*)simpletype)->getVal();
// }

void SimpleType::print(ostream* out)
{
  *out << "<SimpleType> --> " << _value << endl;
}

Node* SimpleType::getChild(unsigned int index) const
{
  cerr << "tried to get child on a SimpleType!" << endl;
  return 0;
}

/******************************************************************************/
