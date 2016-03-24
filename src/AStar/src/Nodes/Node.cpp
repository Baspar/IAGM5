#include "Node.hpp"

// Constructeurs

Node::Node(){
	G=0;
	H=0;
}
Node::Node(int g, int h){
	G=g;
	H=h;
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
string Node::getNodeID() const{
 	return nodeID;
}
void Node::setNodeID(string id) {
	nodeID = id;
}

void Node::updateGH(){

}
bool Node::operator<(Node* b){
	if(this->getG()+this->getH()< b->getG()+b->getH()){
		if(this->getG()<b->getG()){
			return true;
		} else {
			return false;
		}
	}
	return false;

//	return(this->getG()+this->getH() <= b->getG()+b->getH());
	//Il y a pas une deuxième condition pour trier les distance, genre quand le g est egal tu renvois le plus petit h ? S
}
set<Node*> Node::getVoisins(){
cout << "node getvoisins";
cout << endl;
}
