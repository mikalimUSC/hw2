CXX=g++
CXXFLAGS=-g -Wall -std=c++11
# Uncomment for parser DEBUG
#DEFS=-DDEBUG

OBJS=amazon.o user.o db_parser.o product.o product_parser.o util.o mydatastore.o \
     book.o clothing.o movie.o 

all: amazon

amazon: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $^

amazon.o: amazon.cpp db_parser.h datastore.h product_parser.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -c $<

user.o: user.cpp user.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -c $<

db_parser.o: db_parser.cpp db_parser.h product.h product_parser.h user.h datastore.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -c $<

product.o: product.cpp product.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -c $<

product_parser.o: product_parser.cpp product_parser.h product.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -c $<

util.o: util.cpp util.h
	$(CXX) $(CXXFLAGS) $(DEFS) -c $<

mydatastore.o: mydatastore.cpp mydatastore.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -c $<

book.o: book.cpp book.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -c $<

clothing.o: clothing.cpp clothing.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -c $<

movie.o: movie.cpp movie.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -c $<

clean:
	rm -f *.o amazon
