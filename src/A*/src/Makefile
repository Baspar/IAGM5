GPP=g++ --std=c++11
all: Cell.o Sudoku.o Number.o
	$(GPP) main.cpp $^ -o main

%.o: %.cpp
	$(GPP) -c $<

clean:
	rm -f *.o main
