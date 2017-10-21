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
#include<cstdlib>

Node::Node(string value = "", string type = "", int kind = 0)
:_value(value), _type(type), _kind(kind)
{}
Node::~Node()
{
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    delete _subNodes[i];
  }
}
void Node::setErr() {
  _err = true;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->setErr();
  }
}
bool Node::getErr() {return _err;}
string Node::getType(void) const
{
  return _type;
}


/******************************************************************************/

UnaryOp::UnaryOp(string value):Node(value, "UnaryOp")
{}
void UnaryOp::print(ostream* out)
{
  if(_err) return;
  *out << "<UnaryOp> --> " << _value << endl;
}


/******************************************************************************/

RelationOp::RelationOp(string value):Node(value, "RelationOp")
{}
void RelationOp::print(ostream* out)
{
  if(_err) return;
  *out << "<RelationOp> --> " << _value << endl;
}

/******************************************************************************/

ProductOp::ProductOp(string value):Node(value, "ProductOp")
{}
void ProductOp::print(ostream* out)
{
  if(_err) return;
  *out << "<ProductOp> --> " << _value << endl;
}

/******************************************************************************/

SumOp::SumOp(string value):Node(value, "SumOp")
{}
void SumOp::print(ostream* out)
{
  if(_err) return;
  *out << "<SumOp> --> " << _value << endl;
}

/******************************************************************************/
Name::Name(string value, int kind):Node(value, "Name", kind)
{}
Name::Name(Node* name, string value, int kind):Node(value, "Name", kind)
{
  _subNodes.push_back(name);
}

Name::Name(Node* name, Node* expression, int kind):Node("", "Name", kind)
{
  _subNodes.push_back(name);
  _subNodes.push_back(expression);
}

void Name::print(ostream* out)
{
  if(_err) return;
  *out << "<Name> --> ";
  switch(_kind)
  {  
    case NAMETHIS:
    {
      *out << _value;
      break;
    }
    case NAMEID:
    {
      *out << _value;
      break;
    }
    case NAMEDOTID:
    {
      *out << "<Name>." << _value;
      break;
    }
    case NAMEEXP:
    {
      *out << "<Name> [<Expression>]";
      break;
    }
    case NAMEIDEXP:
    {
      *out << _value << " [<Expression>]";
      break;
    }
    default:
    {
      cerr << "FATAL ERROR!! NAME" << endl;
      exit(1);
    }
  }
  *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
  }
  
}
/******************************************************************************/

Expression::Expression(Node* next, int kind):Node("", "Expression", kind)
{
  _subNodes.push_back(next);
}

Expression::Expression(string value, int kind):Node(value, "Expression", kind)
{}

Expression::Expression(Node* unaryop, Node* expression, int kind)
:Node("", "Expression", kind)
{
  _subNodes.push_back(unaryop);
  if(expression != 0 ) _subNodes.push_back(expression);
}

Expression::Expression(Node* expression1, Node* op, Node* expression2, int kind)
:Node("", "Expression", kind)
{
  if (expression1 != 0) _subNodes.push_back(expression1);
  _subNodes.push_back(op);
  if (expression2 != 0) _subNodes.push_back(expression2);
  
}
void Expression::print(ostream* out)
{
  if(_err) return;
  *out << "<Expression> --> ";
  switch(_kind)
  {
    case EXPNUM:
    {
      *out << _value;
      break;
    }
    case EXPNULL:
    {
      *out << _value;
      break;
    }
    case EXPREAD:
    {
      *out << _value;
      break;
    }
    case EXPUNARY:
    {
      *out << "<UnaryOp> <Expression>";
      break;
    }
    case EXPRELATION:
    {
      *out << "<Expression> <RelationOp> <Expression>";
      break;
    }
    case EXPPRODUCT:
    {
      *out << "<Expression> <ProductOp> <Expression>";
      break;
    }
    case EXPSUMOP:
    {
      *out << "<Expression <SumOp> <Expression>";
      break;
    }
    case EXPPAREN:
    {
      *out << "(<Expression>)";
      break;
    }
    case EXPNEW:
    {
      *out << "<NewExpression>";
      break;
    }
    case EXPNAME:
    {
      *out << "<Name>";
      break;
    }
    case EXPNAMEARG:
    {
      *out << "<Name>(<ArgList>)";
      break;
    }
    default:
      cerr << "FATAL ERROR!!" << endl;
      exit(1);
  }
  *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
  }
}

/******************************************************************************/

BrackExpression::BrackExpression(Node* expression1, Node* expression2)
:Node("", "BrackExpression")
{
  if(expression1 != 0)_subNodes.push_back(expression1);
  if(expression2 != 0) _subNodes.push_back(expression2); 
}
void BrackExpression::reverse()
{
  stack<Node*> expressions;
  if(_subNodes.size() > 0) expressions.push(_subNodes[0]);
  if(_subNodes.size() > 1) ((BrackExpression*)_subNodes[1])->recReverse(expressions);
  if(_subNodes.size() > 0) 
  {
    _subNodes[0] = expressions.top();
    expressions.pop();
  }
  if(_subNodes.size() > 1) ((BrackExpression*)_subNodes[1])->recAdd(expressions);
}

void BrackExpression::recReverse(stack<Node*> & expressions)
{
  expressions.push(_subNodes[0]);
  if(_subNodes.size() > 1) ((BrackExpression*)_subNodes[1])->recReverse(expressions);
}
void BrackExpression::recAdd(stack<Node*> & expressions)
{
  _subNodes[0] = expressions.top();
  expressions.pop();
  if(_subNodes.size() > 1) ((BrackExpression*)_subNodes[1])->recAdd(expressions);
}
void BrackExpression::print(ostream* out)
{
  if(_err) return;
  *out << "<BracketedExpression> --> ";
  if(_subNodes.size() > 1) *out << "<Expression> [<BracketedExpression>]";
  else *out << "<Expression>";
  *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
  }
}
/******************************************************************************/

OptBracket::OptBracket(Node* expression):Node("", "OptBracket")
{
  if(expression != 0 )_subNodes.push_back(expression);
}
void OptBracket::print(ostream* out)
{
  if(_err) return;
  *out << "<ArrayBrackets> --> ";
  if(_subNodes.size() > 0) *out << "<ArrayBrackets>[]";
  else *out << "[]";
  *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
  }
}
/******************************************************************************/


ArgList::ArgList(Node* expression1, Node* expression2):Node("", "ArgList")
{
  _subNodes.push_back(expression1);
  if(expression2 != 0) _subNodes.push_back(expression2); 
}

bool ArgList::getEmpty() const {return _empty;}

void ArgList::print(ostream* out)
{
  if(_err) return;
  *out << "<ArgList> --> <Expression>";
  if(_subNodes.size() > 1) *out << " <ArgList>";
  *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
  }
}
/******************************************************************************/

NewExpression::NewExpression(string simpletype, Node* arglist, int kind)
:Node(simpletype, "NewExpression", kind)
{
  if (arglist!=0 ) _subNodes.push_back(arglist);
}
NewExpression::NewExpression(string simpletype, Node* type2, Node* brackexp, int kind)
:Node(simpletype, "NewExpression", kind)
{
  if (type2!=0 ) _subNodes.push_back(type2);
  if(brackexp != 0) _subNodes.push_back(brackexp);
}
void NewExpression::print(ostream* out)
{
  if(_err) return;
  *out << "<NewExpression> --> new " << _value << " ";
  
  switch(_kind)
  {
    case NEWEXPARG:
    {
      *out << "(<ArgList>)";
      break;
    }
    case NEWEXPBRACK:
    {
      *out << "<[Expression]>";
      break;
    }
    case NEWEXPBRACKMULTI:
    {
      *out << "[<BracketedExpression>] <Multibracks>";
      break;
    }
    case NEWEXPMULTI:
    {
      *out << "<Multibracks>";
      break;
    }
    case NEWEXP:
    {
      break;
    }
    default:
    {
      cerr << "FATAL ERROR!!! NewExpression" << endl;
      exit(1);
    }
  }
  *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
    
  }
}


/******************************************************************************/

VarDec::VarDec(string type, string id, Node* bracks):Node(id)
{
  _type = type;
  _subNodes.push_back(bracks);
}

VarDec::VarDec(string type, string id): Node(id)
{
  _type = type;
}
VarDec::VarDec(Node* type, string id, Node* bracks):Node(id)
{
  _subNodes.push_back(type);
  _subNodes.push_back(bracks);
  
}
void VarDec::print(ostream* out)
{
  if(_err) return;
  *out << "<Variable Declaration> --> ";
  if(_subNodes.size() > 0) 
  {
    *out << "<Multibracks> " << _value << ";"<< endl;
    _subNodes[0]->print(out);
  }
  else
  {
    *out << _type << " " << _value << ";" << endl;
  }
}

/******************************************************************************/


Multibracks::Multibracks(Node* simpletype):Node("")
{
  _subNodes.push_back(simpletype);
}

Multibracks::Multibracks():Node("")
{}

void Multibracks::print(ostream* out)
{
  if(_err) return;
  *out << "<Multibracks> --> ";
  if(_subNodes.size() > 0) *out << "<Multibracks>[]";
  else *out << " []";
  *out << endl;
  if(_subNodes.size() > 0) _subNodes[0]->print(out);
}

/******************************************************************************/


SimpleType::SimpleType(string value):Node(value)
{}
void SimpleType::print(ostream* out)
{
  if(_err) return;
  *out << "<SimpleType> --> " << _value << endl;
}


/******************************************************************************/
