#ifndef GRAPHE_HPP
#define GRAPHE_HPP

#include <iostream>
#include "Node.hpp"

using namespace std;

class Graphe{
    private:
	set<Node*> graph;
	
    public:
	Graphe(Node* a);
	Graphe(set<Node*> sa);
	Graphe();

	set<Node*> getGraph()const;
	void setGraph(set<Node*> g);

	virtual int Distance(Node* a, Node* b)=0;
};
#endif
