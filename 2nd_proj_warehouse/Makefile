CC=gcc
CPC=g++

CFLAGS=-g -Wall -Wextra

LINKEDLIST=linkedList.cpp linkedList.h
LINKEDLISTNODE=linkedListNode.cpp linkedListNode.h
WAREHOUSE=warehouse.cpp warehouse.h

ass7: linkedList.o linkedListNode.o warehouse.o 
	$(CPC) $(CFLAGS) ass7.cpp linkedList.o linkedListNode.o warehouse.o -o ass7

linkedList.o: $(LINKEDLIST) $(LINKEDLISTNODE)
	$(CPC) $(CFLAGS) -c linkedList.cpp -o linkedList.o 

linkedListNode.o: $(LINKEDLISTNODE)
	$(CPC) $(CFLAGS) -c linkedListNode.cpp -o linkedListNode.o 

warehouse.o: $(WAREHOUSE) $(LINKEDLIST)
	$(CPC) $(CFLAGS) -c warehouse.cpp -o warehouse.o 


clean:
	rm *.o ass7 &> /dev/null
