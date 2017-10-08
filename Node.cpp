/*
 * Node.cpp
 * Author: Wyatt Emery
 * Date: OCT 6, 2017
 *
 * COSC 4785, Homework3
 *
 */


#include"Node.h"

Identifier::Identifier(string val = ""): _value(val)
{}

Identifier::getVal(void)
{
  return _value;
}