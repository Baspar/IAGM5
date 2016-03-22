#ifndef ASTAR_HPP
#define ASTAR_HPP

#include <iostream>
#include <queue>
#include "Graphe.hpp"
#include "Node.hpp"

using namespace std;

class AStar{
	public:
		Graphe graphe;
		Node current;

		AStar();
		bool FindShortestWay(Node a, Node b);
};


#endif

