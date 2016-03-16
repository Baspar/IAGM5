#include "LigneAgent.hpp"
#include <set>

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
    for(int i=0; i<9;i++){
        ajouterBut(sudoku->getCell(numero,i));
        sudoku->getCell(numero,i)->ajouterBut(this);
    }
}

LigneAgent::LigneAgent(int n){
    sudoku=nullptr;
    cout << "HERE" << sudoku << endl;
    numero=n;
    agresse=false;
    gene=false;
    etat=Etat::RECHERCHE_SATISFACTION;
}

LigneAgent::LigneAgent(){
    numero=-1;
    sudoku=NULL;
}

vector<EcoAgent*> LigneAgent::trouverGeneur(){
    vector<EcoAgent*> v;
    set<EcoAgent*> cellules;
    for(int i=0; i<9;i++){
        for(int j=i+1; j<9;j++){
            if (sudoku->getValue(numero,i)==sudoku->getValue(numero,j)){
                cellules.insert(sudoku->getCell(numero,i));
                cellules.insert(sudoku->getCell(numero,j));
            }
        }
    }
    set<EcoAgent*>::const_iterator it=cellules.begin();
    for(int l=0; l<cellules.size(); l++){
        v.push_back(*it);
        it++;
    }
    return v;
}


void LigneAgent::faireSatisfaction(){
    etat=Etat::SATISFACTION;
}


void LigneAgent::agresser(EcoAgent* e){
    //cout << "testFuir" << endl;
    e->fuir(this);
    //cout << "rate ? " << endl;
}

EcoAgent* LigneAgent::trouverPlacePourFuir(EcoAgent* e){
    return this;
}

void LigneAgent::faireFuite(EcoAgent* e){

}
