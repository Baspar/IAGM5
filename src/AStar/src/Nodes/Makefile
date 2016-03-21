GPP=g++ --std=c++11 -fpermissive

all:V0

V%:   Node.o Graphe.o AStarV%.o
	$(GPP) main$@.cpp $^ -o main

%.o: %.cpp
	$(GPP) -c $<

clean:
	rm -f *.o main
