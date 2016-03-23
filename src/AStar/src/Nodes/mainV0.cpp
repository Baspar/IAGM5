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

	AStar as = AStar(g);	
	as.graphe = g;

	set<Node*> res = as.FindShortestWay(&sud,&sud);
	for(Node* n : res) {
		if(n->getG()==81){
		n->afficher();
		cout << n->getG();
		cout <<endl;
		cout << n->getH();
	cout <<endl;
		}
	}

}

