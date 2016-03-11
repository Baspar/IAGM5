#include "LigneAgent.hpp"

int LigneAgent::getNumero(){
    return numero;
}
        
Sudoku* LigneAgent::getSudoku(){
    return sudoku;
}

void LigneAgent::setNumero(int n){
    numero=n;
}

void LigneAgent::setSudoku(Sudoku* s){
    sudoku=s;
}

LigneAgent::LigneAgent(Sudoku* s, int n){
    sudoku=s;
    numero=n;
}

LigneAgent::LigneAgent(){
    numero=-1;
    sudoku=NULL;
}

vector<EcoAgent*> LigneAgent::trouverGeneur(){
    vector<EcoAgent*> v;
    return v;
}
