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


Node::Node(string value = "", string type = ""):_value(value), _type(type)
{}

Node* Node::getChild(unsigned int index) const
{
  if((index < (_subNodes.size())) && (index >= 0)) return _subNodes[index];
  else cerr << "Node:: Invalid index" << endl;
  return 0;
}

string Node::getType(void) const
{
  return _type;
}

string Node::getVal(void) const {return _value;}
/******************************************************************************/

UnaryOp::UnaryOp(string value):Node(value)
{}
void UnaryOp::print(ostream* out)
{
  *out << "<UnaryOp> --> " << _value << endl;
}
Node* UnaryOp::getChild(unsigned int index) const
{
  cerr << "tried to get child on a UnaryOp!" << endl;
  return 0;
}


/******************************************************************************/

RelationOp::RelationOp(string value):Node(value, "RelationOp")
{}
void RelationOp::print(ostream* out)
{
  *out << "<RelationOp> --> " << _value << endl;
}
Node* RelationOp::getChild(unsigned int index) const
{
  cerr << "tried to get child on a RelationOp!" << endl;
  return 0;
}

/******************************************************************************/

ProductOp::ProductOp(string value):Node(value, "ProductOp")
{}
void ProductOp::print(ostream* out)
{
  *out << "<ProductOp> --> " << _value << endl;
}
Node* ProductOp::getChild(unsigned int index) const
{
  cerr << "tried to get child on a ProductOp!" << endl;
  return 0;
}

/******************************************************************************/

Name::Name(string value):Node(value)
{}

Name::Name(Node* name, string value):Node(value)
{
  _subNodes.push_back(name);
}

Name::Name(Node* name, Node* expression)
{
  _subNodes.push_back(name);
  _subNodes.push_back(expression);
}

void Name::print(ostream* out)
{
  return;
}
/******************************************************************************/

Expression::Expression(Node* next)
{
  _subNodes.push_back(next);
}

Expression::Expression(string value):Node(value)
{}

Expression::Expression(Node* unaryop, Node* expression)
{
  _subNodes.push_back(unaryop);
  _subNodes.push_back(expression);
}

Expression::Expression(Node* expression1, Node* op, Node* expression2)
{
    _subNodes.push_back(expression1);
    _subNodes.push_back(op);
    _subNodes.push_back(expression2);
}

void Expression::print(ostream* out)
{
  *out << "<Expression> --> ";
  switch(_subNodes.size())
  {
      case 1:
      {
        *out << "(<Expression>)" << endl;
        _subNodes[0]->print(out);
        break;
      }
      case 2:
      {
        *out << "<UnaryOp> <Expression>" << endl;
        _subNodes[0]->print(out);
        _subNodes[1]->print(out);
        break;
      }
      case 3:
      {
        *out << "<Expression> <" << _subNodes[1]->getType() << 
        "> <Expression>" << endl;
        _subNodes[0]->print(out);
        _subNodes[1]->print(out);
        _subNodes[2]->print(out);
        break;
      }
      default:
        *out << _value << endl;
  }
}
/******************************************************************************/

Identifier::Identifier(string value = ""): Node(value)
{}

void Identifier::print(ostream *out)
{
  *out << _value << endl;
}

/******************************************************************************/

VarDec::VarDec(Node* type, string id):Node(id)
{
  _subNodes.push_back(type);
}

void VarDec::print(ostream* out)
{
  *out << "<Variable Declaration> --> <type> " << _value << ";" << endl;
  _subNodes[0]->print(out);
}

/******************************************************************************/


Type::Type(Node* simpletype, bool array):Node("")
{
  if(array) _array = true;
  _subNodes.push_back(simpletype);
}


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


SimpleType::SimpleType(string value):Node(value)
{}

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
