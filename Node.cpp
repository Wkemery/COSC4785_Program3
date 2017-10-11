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

SumOp::SumOp(string value):Node(value, "SumOp")
{}
void SumOp::print(ostream* out)
{
  *out << "<SumOp> --> " << _value << endl;
}
Node* SumOp::getChild(unsigned int index) const
{
  cerr << "tried to get child on a SumOp!" << endl;
  return 0;
}

/******************************************************************************/
Name::Name(string value):Node(value, "Name")
{}

Name::Name(Node* name, string value):Node(value, "Name")
{
  _subNodes.push_back(name);
}

Name::Name(Node* name, Node* expression):Node("", "Name")
{
  _subNodes.push_back(name);
  _subNodes.push_back(expression);
}

void Name::print(ostream* out)
{
  return;
}
/******************************************************************************/

Expression::Expression(Node* next):Node("", "Expression")
{
  _subNodes.push_back(next);
  /*Could be a name, newexpression, expression*/
  if(_subNodes[0]->getType() == "Name") _kind = NAMEEX;
  
  else if(_subNodes[0]->getType() == "NewExpression") _kind = NEWEX;
  
  else _kind = EXPRESSN;
}

Expression::Expression(string value):Node(value, "Expression"), _kind(PLAIN)
{}

Expression::Expression(Node* unaryop, Node* expression):Node("", "Expression")
{
  /*Could be unaryop exp, name arglist*/
  _subNodes.push_back(unaryop);
  if(expression != 0 ) _subNodes.push_back(expression);
  if(_subNodes[0]->getType() == "UnaryOp") _kind = UNARYEX;
  else _kind = NAMEARG;
}

Expression::Expression(Node* expression1, Node* op, Node* expression2)
:Node("", "Expression")
{
  /*Could be a relationop, sumop, productop*/
    _subNodes.push_back(expression1);
    _subNodes.push_back(op);
    _subNodes.push_back(expression2);
    if(_subNodes[1]->getType() == "RelationOp") _kind = RELEX;
    else if(_subNodes[1]->getType() == "SumOp") _kind = SUMEX;
    else _kind = PRODEX;
}

void Expression::print(ostream* out)
{
  *out << "<Expression> --> ";
  switch(_subNodes.size())
  {
      case 1:
      {
        if(_kind == EXPRESSN) *out << "(<Expression>)" << endl;
        else if (_kind == NEWEX ) *out << "<NewExpression>" << endl;
        else *out << "<Name> ()" << endl;
        _subNodes[0]->print(out);
        
        break;
      }
      case 2:
      {
        if(_kind == UNARYEX) *out << "<UnaryOp> <Expression>" << endl;
        else *out << "<Name> (<ArgList>)" << endl;
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

ArgList::ArgList(Node* expression1, Node* expression2)
{
  _subNodes.push_back(expression1);
  if(expression2 != 0) _subNodes.push_back(expression2); 
}
void ArgList::print(ostream* out)
{
  *out << "<ArgList> --> Expression";
  if(_subNodes.size() > 1) *out << " Expression";
  *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
  }
}
/******************************************************************************/

NewExpression::NewExpression(Node* simpletype, Node* arglist)
{
  _subNodes.push_back(simpletype);
  if (arglist!=0 ) _subNodes.push_back(arglist);
}
void NewExpression::print(ostream* out)
{
  //TODO: add fucntionality for second way a new expression can be declared
  *out << "<NewExpression> --> new <SimpleType>";
  if(_subNodes.size() > 1 ) *out << "(<ArgList>)";
  else *out << " ()";
  *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
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
