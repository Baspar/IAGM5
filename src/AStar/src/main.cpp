#include <iostream>
#include "Sudoku.hpp"
#include "Cell.hpp"
#include "AStar.hpp"

using namespace std;

int main(){

    cout << "Grille initiale";
    cout << endl;
    Sudoku sud = Sudoku("test4.txt"); 
    
	sud.afficher();



    cout << "Résultat";
    cout << endl;

AStar* as;
bool ASTAR = true;


sud.updateRemaining();

if(!ASTAR){
Sudoku a =  as->developSudoku(sud);
} else {
set<Sudoku> closeList;
//set<Sudoku>  searchList;
std::priority_queue<Sudoku> openList;
Sudoku current=sud;



openList.push(sud);
//searchList.insert(sud);


while(openList.empty() != true && !current.checkComplete()){
current = openList.top();
openList.pop();


if(current.checkComplete()){
current.afficher();
return 1;
} else {

	for(Sudoku n : as->CreateNeighboor(current)) {
//		if(searchList.find(n)==searchList.end()){
			for(int i=0; i<9;i++){
			for(int j=0;j<9;j++){
				if(n.getCell(i,j)->getValue()==0) {
				n.getCell(i,j)->updateRemaining();
				}
			}
			}
			n.updateGH();
			openList.push(n);
//			searchList.insert(n);
//		}
	}
//	closeList.insert(current);
}

}

}

}
