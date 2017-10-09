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
  if((index < (_subNodes.size())) && (index >= 0)) return _subNodes[index];
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
  Type* temp = new Type((Type*)type);
  _subNodes.push_back(temp);
//   cerr << "id in vardec" << id << endl;
  _id = id;
}

VarDec::VarDec(Node* vardec)
{
  Type* temp = new Type((vardec->getChild(0)));
  _subNodes.push_back(temp);
  _id = ((VarDec*) vardec)->getID();
}

string VarDec::getID(void) const
{
  return _id;
}

void VarDec::print(ostream* out)
{
  *out << "<Variable Declaration> --> <type> " << _id << ";" << endl;
  _subNodes[0]->print(out);
}

/******************************************************************************/


Type::Type(Node* simpletype, bool array)
{
  if(array) _array = true;
  SimpleType* temp = new SimpleType(simpletype);
  _subNodes.push_back(temp);
}

Type::Type(Node* type)
{
  _array = ((Type*)type)->getArray();
  SimpleType* temp = new SimpleType(type->getChild(0));
  _subNodes.push_back(temp);
}

bool Type::getArray()
{
  return _array;
}

void Type::print(ostream* out)
{
  *out << "<Type> --> ";
  if(_array) *out << "type[]";
  else *out << "SimpleType";
  *out << endl;
  _subNodes[0]->print(out);
}


/******************************************************************************/


SimpleType::SimpleType(string val): _value(val) {}


SimpleType::SimpleType(Node* simpletype)
{
  _value = ((SimpleType*)simpletype)->getVal();
}

string SimpleType::getVal(void) const
{
  return _value;
}

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

/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

