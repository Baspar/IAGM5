#include <iostream>
#include "Sudoku.hpp"
#include "Cell.hpp"
#include "AStar.hpp"

using namespace std;

int main(){
    bool captainObvious = true;

    cout << "Grille initiale";
    cout << endl;
    Sudoku sud = Sudoku("test3.txt"); 
    
	sud.afficher();



    cout << "Résultat";
    cout << endl;

AStar* as;
bool ASTAR = true;


sud.updateRemaining();
sud.updateGH();

cout<< "iniG         ";
cout << sud.getG();
cout << endl;
cout << "ini h          ";
cout << sud.getH();
cout << endl;

if(!ASTAR){
//Sudoku a =  as->developSudoku(sud);

//as->test(sud);
bool test = false;
while(!test){
test = true;
for(int i=0;i<9;i++){
	for(int j=0;j<9;j++){
		if(sud.getCell(i,j)->getValue()==0 && sud.getCell(i,j)->getRemaining().size()==1) {
		sud.setValue(i,j,*sud.getCell(i,j)->getRemaining().begin());
cout << sud.getCell(i,j)->getValue();
cout << endl;
		test = false;
		}
	}
}
sud.updateRemaining();
}
sud.afficher();

} else {
set<Sudoku> closeList;
//set<Sudoku>  searchList;
std::priority_queue<Sudoku> openList;
Sudoku current = sud;


openList.push(current);
//searchList.insert(sud);
bool complete;
int a=0;
while(openList.empty() != true && !complete){
a++;
cout << "Top Pop   ";
cout << a;
cout << endl;
cout << endl;
current = openList.top();
openList.pop();

cout <<"/////////////////////";
cout << endl;
current.afficher();

cout <<"......................";
cout << endl;

if(captainObvious){
bool test = false;
while(!test){
test=true;
for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
                if(current.getCell(i,j)->getValue()==0 && current.getCell(i,j)->getRemaining().size()==1) {
                current.setValue(i,j,*current.getCell(i,j)->getRemaining().begin());
		test = false;
                }
        }
}
}
current.updateRemaining();

current.afficher();
}
cout << endl;
cout << as->CreateNeighboor(current).size();
cout <<endl;

if(current.checkComplete()){
complete = true;
return 1;
}

int b=0;
	for(Sudoku n :  as->CreateNeighboor(current)) {
if(n.checkComplete()){
complete = true;
n.afficher();
return 1;
}
//		if(searchList.find(n)==searchList.end()){
b++;
cout << "	voisin ";
cout << b;
cout << endl;


cout << "	G ";
cout << n.getG();
cout << endl;
cout << "	H ";
cout << n.getH();
cout << endl;
			openList.push(n);
//			searchList.insert(n);
//		}
	}
//	closeList.insert(current);
cout << "open	";
cout << openList.size();
cout << endl;
}
}
}

