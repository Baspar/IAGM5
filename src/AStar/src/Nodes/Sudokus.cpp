#include "Sudokus.hpp"
Sudokus::Sudokus(Node* n): Graphe(n) {
	
}
int Sudokus::Distance(Node* a, Node* b) {
	return a->getH();
}
