GPP=g++ --std=c++11 -fpermissive

v2: Cell.o Sudoku.o Number.o Sudokusv2.o
	$(GPP) main.cpp $^ -o main

v1: Cell.o Sudoku.o Number.o Sudokusv1.o
	$(GPP) main.cpp $^ -o main

%.o: %.cpp
	$(GPP) -c $<

clean:
	rm -f *.o main
