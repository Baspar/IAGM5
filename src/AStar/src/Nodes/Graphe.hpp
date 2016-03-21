#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iostream>
#include "Node.hpp"

using namespace std;

class Graphe{
    private:
	set<Node> graph;
	
    public:
	Graphe(Node a);
	Graphe(set<Node> sa);
	set<Node> getGraph()const;
	void setGraph(set<Node> g);
	void AddNodes(set<Node> l);
	int Distance(Node a, Node b);
};
#endif
