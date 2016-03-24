#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Node{
    private:
	string nodeID;
	int G;
	int H;
	set<Node*> parents;
	set<Node*> enfants;

    public:
	Node();
	Node(int g, int h);
	Node(const Node& node);
	
	int getG() const;
	void setG(int g);
	int getH() const;
	void setH(int h);

	set<Node*> getParents() const;
	void setParents(set<Node*> sp);
	set<Node*> getEnfants() const;
	void setEnfants(set<Node*> se);

	string getNodeID() const;
	void setNodeID(string id);
	         
	bool operator<(Node* b);


	virtual string  getID()=0;

	virtual void afficher()=0;

	virtual void updateGH()=0;

	virtual set<Node*> getVoisins()=0;


};
#endif
