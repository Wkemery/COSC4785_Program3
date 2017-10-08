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

Node* Node::getChild(unsigned int index) const
{
  if((index < (_subNodes.size() - 1)) && (index >= 0)) return _subNodes[index];
  else cerr << "Node:: Invalid index" << endl;
  return 0;
}

/******************************************************************************/

Identifier::Identifier(string value = ""): _value(value)
{}

string Identifier::getVal(void)
{
  return _value;
}

void Identifier::print(ostream *out)
{
  *out << _value << endl;
}

/******************************************************************************/

VarDec::VarDec(Node* type, string id)
{
  _subNodes.push_back(type);
  _id = id;
}

void VarDec::print(ostream* out)
{
  *out << "var dec printing" << endl;
  _subNodes[0]->print(out);
  _subNodes[1]->print(out);
}

/******************************************************************************/


Type::Type(Node* SimpleType, bool array)
{
  if(array) _array = true;
  _subNodes.push_back(SimpleType);
}
void Type::print(ostream* out)
{
  *out << "Type printing" << endl;
  _subNodes[0]->print(out);
}


/******************************************************************************/


SimpleType::SimpleType(string val): _value(val)
{}
void SimpleType::print(ostream* out)
{
  *out << "SimpleType printing" << endl;
  *out << _value << endl;
}
Node* SimpleType::getChild(unsigned int index) const
{
  cerr << "tried to get child on a SimpleType!" << endl;
  return 0;
}

/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

