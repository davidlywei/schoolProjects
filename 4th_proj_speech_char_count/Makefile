CC=gcc
CPC=g++

CFLAGS=-g -Wall -Wextra -std=c++11

TREE=tree.cpp tree.h treeNode.h
VALUE=value.cpp value.h
VALUEFUNCTOR=valueFunctor.h

lab5: $(TREE) value.o $(VALUEFUNCTOR) 
	$(CPC) $(CFLAGS) lab5.cpp value.o -o lab5

value.o: $(VALUE)
	$(CPC) $(CFLAGS) -c value.cpp -o value.o 


clean:
	rm *.o lab5 &> /dev/null
