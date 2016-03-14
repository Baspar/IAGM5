#include "ColonneAgent.hpp"
#include <set>

int ColonneAgent::getNumero(){
    return numero;
}
        
Sudoku* ColonneAgent::getSudoku(){
    return sudoku;
}

void ColonneAgent::setNumero(int n){
    numero=n;
}

void ColonneAgent::setSudoku(Sudoku* s){
    sudoku=s;
}

ColonneAgent::ColonneAgent(Sudoku* s, int n){
    sudoku=s;
    numero=n;
    agresse=false;
    gene=false;
    etat=Etat::RECHERCHE_SATISFACTION;
    for(int i=0; i<9;i++){
        ajouterBut(sudoku->getpCell(i,numero));
        sudoku->getpCell(i,numero)->ajouterBut(this);
    }    
}

ColonneAgent::ColonneAgent(){
    numero=-1;
    sudoku=NULL;
}

vector<EcoAgent*> ColonneAgent::trouverGeneur(){
    vector<EcoAgent*> v;
    set<EcoAgent*> cellules;
    for(int i=0; i<9;i++){
        for(int j=i+1; j<9;j++){
            if (sudoku->getValue(i, numero)==sudoku->getValue(j,numero)){
                cellules.insert(sudoku->getpCell(i,numero));
                cellules.insert(sudoku->getpCell(j,numero));
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


void ColonneAgent::faireSatisfaction(){
    etat=Etat::SATISFACTION;
}


void ColonneAgent::agresser(EcoAgent* e){
    e->fuir(this);
}

EcoAgent* ColonneAgent::trouverPlacePourFuir(EcoAgent* e){
    return this;
}

void ColonneAgent::faireFuite(EcoAgent* e){

}
