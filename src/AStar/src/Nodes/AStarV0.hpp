#ifndef ASTAR_HPP
#define ASTAR_HPP

#include <iostream>
#include <queue>
#include "Graphe.hpp"
#include "Node.hpp"

using namespace std;

class AStar{
	public:
		Graphe* graphe;
		Node* current;
        //Pour que ça soit generique il te faut un noeud depart, le noeud courant


        AStar(Graphe* grap );
		set<Node*> FindShortestWay(Node* a, Node* b);//A quoi correspond le boolean ?
};


#endif

