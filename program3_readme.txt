# COSC4785_Program3
Valid input:
  Currently the only standalone input that my program will accept is an
  expression or a variable declaration. All other parts of the grammar must be 
  a smaller part of one of those.
  
  A note: I did implement arglist before instructed not to and i chose to take 
  it out. However, since it can be empty, it should create no problems with your
  testing.
  
Changes in the Grammar:
  The biggest change I made was in how a variable is declared.
  First off, I made a production called multibracks. it is used in the var
  declaration rules. When we have the full grammar, I plan to change it to be 
  more consistent with the actual grammar.
  
How I print things out:
  Everything should be printing as described in the instructions except for
  some expressions.  For example given 2+2. my program will print out
  <Expression> --> <Expression> <SumOp> <Expression>
  <Expression> --> 2
  <SumOp> --> +
  <Expression> --> 2
  
  I did this because sum op could be a number of things and so I made it a node
  in my tree. Mine does not print:
  <Expression> --> <Expression> + <Expression>
  <Expression> --> 2
  <Expression> --> 2
  
