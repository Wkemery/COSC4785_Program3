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

Node::Node(string value = "", string type = "", int kind = 0):_value(value), _type(type), _kind(kind)
{}
Node::~Node()
{
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    delete _subNodes[i];
  }
}

string Node::getType(void) const
{
  return _type;
}


/******************************************************************************/

UnaryOp::UnaryOp(string value):Node(value, "UnaryOp")
{}
void UnaryOp::print(ostream* out)
{
  *out << "<UnaryOp> --> " << _value << endl;
}


/******************************************************************************/

RelationOp::RelationOp(string value):Node(value, "RelationOp")
{}
void RelationOp::print(ostream* out)
{
  *out << "<RelationOp> --> " << _value << endl;
}

/******************************************************************************/

ProductOp::ProductOp(string value):Node(value, "ProductOp")
{}
void ProductOp::print(ostream* out)
{
  *out << "<ProductOp> --> " << _value << endl;
}

/******************************************************************************/

SumOp::SumOp(string value):Node(value, "SumOp")
{}
void SumOp::print(ostream* out)
{
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

Expression::Expression(Node* unaryop, Node* expression, int kind):Node("", "Expression", kind)
{
  _subNodes.push_back(unaryop);
  if(expression != 0 ) _subNodes.push_back(expression);
}

Expression::Expression(Node* expression1, Node* op, Node* expression2, int kind)
:Node("", "Expression", kind)
{
    _subNodes.push_back(expression1);
    _subNodes.push_back(op);
    _subNodes.push_back(expression2);

}
void Expression::print(ostream* out)
{
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
    
//       case 1:
//       {
//         if(_kind == EXPRESSN) *out << "(<Expression>)" << endl;
//         else if (_kind == NEWEX ) *out << "<NewExpression>" << endl;
//         else *out << "<Name>" << endl;
//         _subNodes[0]->print(out);
//         
//         break;
//       }
//       case 2:
//       {
//         if(_kind == UNARYEX) *out << "<UnaryOp> <Expression>" << endl;
//         else *out << "<Name> (<ArgList>)" << endl;
//         _subNodes[0]->print(out);
//         _subNodes[1]->print(out);
//         break;
//       }
//       case 3:
//       {
//         *out << "<Expression> <" << _subNodes[1]->getType() << 
//         "> <Expression>" << endl;
//         _subNodes[0]->print(out);
//         _subNodes[1]->print(out);
//         _subNodes[2]->print(out);
//         break;
//       }
//       default:
//         *out << _value << endl;
  
}

/******************************************************************************/

BrackExpression::BrackExpression(Node* expression1, Node* expression2):Node("", "BrackExpression")
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
  *out << "<ArgList> --> <Expression>";
  if(_subNodes.size() > 1) *out << " <ArgList>";
  *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
  }
}
/******************************************************************************/

NewExpression::NewExpression(string simpletype, Node* arglist):Node(simpletype, "NewExpression")
{
  //   _subNodes.push_back(simpletype);
  
  if (arglist!=0 ) _subNodes.push_back(arglist);
}
NewExpression::NewExpression(string simpletype, Node* type2, Node* brackexp):Node(simpletype, "NewExpression")
{
//   _subNodes.push_back(simpletype);
  if (type2!=0 ) _subNodes.push_back(type2);
  if(brackexp != 0) _subNodes.push_back(brackexp);
}
void NewExpression::print(ostream* out)
{
  *out << "<NewExpression> --> new " << _value << " ";
  if(_subNodes.size() > 0 ) 
  {  
    if(_subNodes[0]->getType() == "BrackExpression") 
    {
      *out << "[<BracketedExpression>]";
    }
    else if(_subNodes[0]->getType() == "ArgList")
    {
      *out << "<ArgList>";
    }
    if(_subNodes[0]->getType() == "OptBracket") *out << " <ArrayBrackets>";
  }
  if(_subNodes.size() == 2 )*out << " <ArrayBrackets>";
  *out << endl;
  //   *out << _subNodes[0]->getType() << "that";
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
    
  }
}


/******************************************************************************/

VarDec::VarDec(Node* type, string id):Node(id)
{
  _subNodes.push_back(type);
}

VarDec::VarDec(string type, string id, Node* bracks):Node(id)
{
  _type = type;
  _subNodes.push_back(bracks);
}

VarDec::VarDec(string type, string id): Node(id)
{
  _type = type;
}
void VarDec::print(ostream* out)
{
  *out << "<Variable Declaration> --> ";
  if(_subNodes.size() > 0) 
  {
    *out << "<Multibracks> " << _value << ";"<< endl;
    _subNodes[0]->print(out);
  }
  else
  {
    *out << _type << " " << _value << ";";
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
  *out << "<Multibracks> --> ";
  if(_subNodes.size() > 0) *out << "<Multibracks>[]";
  else *out << "[]";
  *out << endl;
  if(_subNodes.size() > 0) _subNodes[0]->print(out);
}

/******************************************************************************/


SimpleType::SimpleType(string value):Node(value)
{}
void SimpleType::print(ostream* out)
{
  *out << "<SimpleType> --> " << _value << endl;
}


/******************************************************************************/
