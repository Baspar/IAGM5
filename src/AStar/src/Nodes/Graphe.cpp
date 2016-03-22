#include "Graphe.hpp"

Graphe::Graphe(Node a) {
	graph.insert(a);
}
Graphe::Graphe(set<Node> sa) {
	graph = sa;
}
Graphe::Graphe(){
}
set<Node> Graphe::getGraph() const {
	return graph;
}
void Graphe::setGraph(set<Node> g) {
	graph = g;
}
int Graphe::Distance(Node a, Node  b) {
//	return	(b.getG()+b.getH() - a.getG() - a.getH());
}
