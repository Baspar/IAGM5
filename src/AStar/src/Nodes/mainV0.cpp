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

	Sudokus g = Sudokus(sud);

	cout << "G   ";
	cout << sud.getG();
	cout << endl;
	cout << "H   ";
	cout << sud.getH();
	cout <<endl;

	cout << endl;


	cout << "Resultat";
	cout << endl;

	AStar as = AStar();	
	as.graphe = g;
	bool res = as.FindShortestWay(sud,sud);

	cout << res;
//	set<Node> sn = sud.getVoisins();
//	cout << sn.size();
//	cout << endl;

//for(Node n : sn){
//n.updateGH();
//}
}

