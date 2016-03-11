GPP=g++ --std=c++11 -fpermissive

v2: Cell.o Sudokuv2.o Number.o Sudokusv2.o
	$(GPP) mainv2.cpp $^ -o main

v1: Cell.o Sudokuv1.o Number.o Sudokusv1.o
	$(GPP) mainv1.cpp $^ -o main

%.o: %.cpp
	$(GPP) -c $<

clean:
	rm -f *.o main
