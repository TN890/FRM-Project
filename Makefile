CC = g++
CFLAGS = -Wall -ggdb3 -std=c++11

OptionPricer: OptionPricer.o BinomialTreeModel.o Option.o
	$(CC) $(CFLAGS) -o OptionPricer OptionPricer.o BinomialTreeModel.o Option.o

OptionPricer.o: OptionPricer.cpp BinomialTreeModel.h Option.h
	$(CC) $(CFLAGS) -c OptionPricer.cpp

Option.o: BinomialTreeModel.h Option.h Option.cpp
	$(CC) $(CFLAGS) -c Option.cpp
	
BinomialTreeModel.o: BinomialTreeModel.h BinomialTreeModel.cpp
	$(CC) $(CFLAGS) -c BinomialTreeModel.cpp
	
clean:
	rm -rf OptionPricer *.o



