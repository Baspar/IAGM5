GPP=g++ --std=c++11 -fpermissive
all: Cell.o Sudoku.o Number.o AStar.o
	$(GPP) main.cpp $^ -o main

%.o: %.cpp
	$(GPP) -c $<

clean:
	rm -f *.o main
