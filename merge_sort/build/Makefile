IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src
LDIR =../lib

LIBS=-lm

_OBJ = sorted_vector_t.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: divide_conquer

$(ODIR)/sorted_vector_t.o: $(ODIR)/sorted_vector_t.cpp  
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/sorted_vector_t.hpp
	$(CC) -c -o $@ $< $(CFLAGS)		

divide_conquer: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
