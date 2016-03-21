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

	AStar* as;

	cout << "Grille initiale";
	cout << endl;

	Sudoku sud = Sudoku("test.txt",9);



	sud.afficher();

	Sudokus g = Sudokus(sud);

	cout << endl;
	cout << "Resultat";
	cout << endl;

	
//	as->graphe = g;

//	bool res = as->FindShortestWay(sud,sud);


	cout << endl;

}

