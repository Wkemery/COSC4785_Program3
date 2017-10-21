##############################
# Makefile
# Author: Wyatt Emery
# Date: SEP 27, 2017
#
# COSC 4785, Homework 2
# 
# this will compile and generate an executable from program2.cpp program2.lpp
# Lexeme.cpp and the Bison file
##############################

CXX=g++
CXXFLAGS=-ggdb -Wall
FLEX=flex++
FLEXFLAGS=--warn
YACC=bison
YACCFLAGS=--report=state -W -d -v

.PHONY: clean tar

program3: program3.cpp program3_lex.cpp program3_bison.c program3_bison.h \
	Lexeme.cpp Node.cpp Lexeme.h Node.h
	${CXX} ${CXXFLAGS} program3.cpp program3_lex.cpp Lexeme.cpp program3_bison.c \
	Node.cpp -o program3

program3_lex.cpp: program3.lpp
	${FLEX} ${FLEXFLAGS} program3.lpp

program3_bison.c: program3.y
	${YACC} ${YACCFLAGS} -o program3_bison.c program3.y


tar: program3.cpp program3.lpp Lexeme.cpp Lexeme.h Makefile
	tar -cf wemery_HW3.tar program3.cpp program3.lpp Lexeme.cpp Lexeme.h \
	program3.y Node.h Node.cpp program3_readme.txt program3.pdf Makefile

clean: 
	/bin/rm -f *.o core.* *.output program3 program3_lex.cpp wemery_HW3.tar \
    program3_bison.c program3_bison.h

