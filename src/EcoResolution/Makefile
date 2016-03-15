GPP=g++ --std=c++11 -fpermissive
all: Cell.o Sudoku.o Number.o EcoAgent.o LigneAgent.o ColonneAgent.o
	$(GPP) main.cpp $^ -o main

%.o: %.cpp
	$(GPP) -c $< 

clean:
	rm -f *.o main
