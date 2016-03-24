#include <iostream>
#include <queue>
#include <set>
#include "Node.hpp"
#include "Graphe.hpp"
#include "AStarV0.hpp"
#include "SudokuV0.hpp"
#include "Cell.hpp"
#include "Sudokus.hpp"

using namespace std;

int main(){

	cout << "Grille initiale";
	cout << endl;

	Sudoku sud = Sudoku("test.txt",9);

//	sud.CaptainObvious();

	sud.afficher();

	Sudokus* g = new Sudokus(&sud);

	cout << "G   ";
	cout << sud.getG();
	cout << endl;
	cout << "H   ";
	cout << sud.getH();
	cout <<endl;
	cout << sud.getNodeID();
	cout << endl;


	cout << "Resultat";
	cout << endl;


priority_queue<Node*> openL;

set<Node*> tmp = sud.getVoisins();

for(Node* n : tmp){
	n->updateGH();

//n->afficher();
//cout << n->getG()+n->getH();
//cout <<endl;
	openL.emplace(n);
}

while(!openL.empty()){
//n->afficher();
Node* n = openL.top();
openL.pop();
cout << n->getG()+n->getH();
cout << endl;
}


Node* r = openL.top();

r->afficher();

cout << "g ";
cout<< r->getG();
cout << "    h ";
cout << r->getH();
cout << endl;

cout << "f   ";
cout << r->getG() + r->getH();
cout << endl;	

	if(!true){
	AStar as = AStar(g);	
	as.graphe = g;

	set<Node*> res = as.FindShortestWay(&sud,&sud);
//	for(Node* n : res) {
//		if(n->getG()==81){
//		n->afficher();
//		cout << n->getG();
//		cout <<endl;
//		cout << n->getH();
	cout <<endl;
//		}
//	}
	}

}
