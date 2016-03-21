#include "Node.hpp"

// Constructeurs

Node::Node(){
	G=0;
	H=0;
}
Node::Node(string n, int g, int h){
	G=g;
	H=h;
	name=n;
}
Node::Node(const Node& node){
	G = node.getG();
	H = node.getH();
	parents = node.getParents();
	enfants = node.getEnfants();
}

//Get Set

int Node::getG()const{
	return G;
}
void Node::setG(int g){
	G=g;
}
int Node::getH()const{
	return H;
}
void Node::setH(int h){
	H=h;
}
set<Node*> Node::getParents()const{
	return parents;
}
void Node::setParents(set<Node*> sp){
	parents = sp;
}
set<Node*> Node::getEnfants()const{
	return enfants;
}
void Node::setEnfants(set<Node*> se){
	enfants = se;
}
void Node::updateGH(){

}
bool Node::operator<(const Node b){
	return(this->getG()+this->getH() >= b.getG()+b.getH());
}


