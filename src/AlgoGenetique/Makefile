GPP=g++ --std=c++11 -fpermissive

all:v3

v%: Cell.o Sudokuv%.o Number.o Sudokusv%.o
	$(GPP) main$@.cpp $^ -o main

%.o: %.cpp
	$(GPP) -c $<

clean:
	rm -f *.o main
