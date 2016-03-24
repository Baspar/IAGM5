GPP=g++ --std=c++11 -fpermissive

all:V0

V%:   Compare.o Node.o Graphe.o Cell.o SudokuV%.o Number.o Sudokus.o AStarV%.o
	$(GPP) main$@.cpp $^ -o main

%.o: %.cpp
	$(GPP) -c $<

clean:
	rm -f *.o main
