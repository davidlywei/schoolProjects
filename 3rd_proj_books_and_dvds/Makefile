CC=gcc
CPC=g++

CFLAGS=-g -Wall -Wextra

BOOK=book.cpp book.h
DOUBLYLLN=doublylln.cpp doublylln.h
DVD=dvd.cpp dvd.h
ITEM=item.cpp item.h
LINKEDLIST=linkedlist.cpp linkedlist.h
SINGLYLLN=singlylln.cpp singlylln.h
COUNTER=counter.h

lab2: book.o $(DOUBLYLLN) dvd.o item.o $(LINKEDLIST) $(SINGLYLLN)
	$(CPC) $(CFLAGS) lab2.cpp book.o dvd.o item.o -o lab2

book.o: $(BOOK) $(ITEM) $(DVD)
	$(CPC) $(CFLAGS) -c book.cpp -o book.o 

dvd.o: $(DVD) $(ITEM) $(BOOK)
	$(CPC) $(CFLAGS) -c dvd.cpp -o dvd.o 

item.o: $(ITEM)
	$(CPC) $(CFLAGS) -c item.cpp -o item.o 


clean:
	rm *.o lab2 &> /dev/null
