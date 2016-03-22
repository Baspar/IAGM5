#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Node{
    private:
	int G;
	int H;
	set<Node*> parents;
	set<Node*> enfants;

    public:
	string name;
	Node();
	Node(string n, int g, int h);
	Node(const Node& node);

	int getG() const;
	void setG(int g);
	int getH() const;
	void setH(int h);

	set<Node*> getParents() const;
	void setParents(set<Node*> sp);
	set<Node*> getEnfants() const;
	void setEnfants(set<Node*> se);

	         
	bool operator<(const Node* b);

	//virtual void updateG();
	//virtual void updateH();
	virtual void afficher()=0;

	virtual void updateGH()=0;

	virtual set<Node*> getVoisins()=0;

};
#endif
