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
  
Error handling:
  I added some basic error handling rules. Many of them are something along the
  lines, missing a right parenthesis or missing a semicolon. However, some 
  account for errors in the middle of a production. For example, 
  simpletype error SEMI
  this allows for some more detailed error messaged. I hope to expand these once
  we have the full grammar. 
  
  The biggest decision I made when choosing how to handle errors, is I chose, if
  given enough information to construct a node, I construct it, in it's 
  entirety. However, I mark it as an error node and I mark all of its children 
  as error nodes. This made continuing parsing a bit easier. And having more 
  information about what the original input looked like seemed like a good idea
  to me. However, I currently do not print "dirty" error node trees, nor do I 
  even add them to the final parse tree. However, this can be changed for needs
  in the future. ALso the memory of a bad node tree is freed before it is lost.
