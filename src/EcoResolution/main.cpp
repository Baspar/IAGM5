#include <iostream>
#include "Sudoku.hpp"
#include "Cell.hpp"

using namespace std;

int main(){
    cout << "Grille de numero" << endl;
    Sudoku sud;

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
            val=sud.getCell(i, j)->getNumber().getValue();
            if(val!=0)
            cout << val;
            else
            cout <<" ";
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

    cout << "Grille si num donnee" <<endl;
    CellType cel;
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
            cel=sud.getCell(i, j)->getNumber().getCellType();
            if(cel!=CellType::GUESS)
            cout << "0";
            else
            cout <<" ";
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

    sud.remplir();
    
    
     cout << "Grille de numero" << endl;

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
            val=sud.getCell(i, j)->getNumber().getValue();
            if(val!=0)
            cout << val;
            else
            cout <<" ";
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

    cout << "Grille si num donnee" <<endl;
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
            cel=sud.getCell(i, j)->getNumber().getCellType();
            if(cel!=CellType::GUESS)
            cout << "0";
            else
            cout <<" ";
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
    
    sud.resolution();
}
