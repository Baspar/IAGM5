#include <iostream>
#include "Sudoku.hpp"
#include "Cell.hpp"
#include "AStar.hpp"

using namespace std;

int main(){

    cout << "Grille initiale";
    cout << endl;
    Sudoku sud = Sudoku("test3.txt"); 
    
    int val;
    for(int i=0; i<9; i++){
        if(i%3==0){
            cout << "+";
            for(int j=0; j<9; j++){
                cout << "-";
                if(j%3==2)
                    cout << "+";
                else
                    cout << "-";
            }
            cout << endl;
        }
        cout << "|";
        for(int j=0; j<9; j++){
            val=sud.getCell(i, j).getNumber().getValue();
            cout << val;
            if(j%3==2)
                cout << "|";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << "+";
    for(int j=0; j<9; j++){
        cout << "-";
        if(j%3==2)
            cout << "+";
        else
            cout << "-";
    }
    cout << endl;






    cout << "Résultat";
    cout << endl;
    AStar as;


    for(int i=0;i<9;i++){
	for( int j=0; j<9;j++) {
		if(sud.grid[i][j].getValue()==0){
		sud.grid[i][j].updateRemaining();
		}
	}
    }


	Sudoku s = as.developSudoku(sud);

    for(int i=0; i<9; i++){
        if(i%3==0){
            cout<< "+";
            for(int j=0; j<9; j++){
                cout << "-";
                if(j%3==2)
                    cout << "+";
                else
                    cout << "-";
            }
            cout << endl;
        }
        cout << "|";
        for(int j=0; j<9; j++){
            val=s.getCell(i, j).getNumber().getValue();
            cout << val;
            if(j%3==2)
                cout << "|";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << "+";
    for(int j=0; j<9; j++){
        cout << "-";
        if(j%3==2)
            cout << "+";
        else
            cout << "-";
    }
    cout << endl;
}
