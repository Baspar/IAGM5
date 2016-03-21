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
    for(int i=0; i<sudoku->getTaille();i++){
        ajouterBut(sudoku->getCell(i,numero));
        sudoku->getCell(i,numero)->ajouterBut(this);
    }
}

ColonneAgent::ColonneAgent(int n){
    sudoku=nullptr;
    numero=n;
    agresse=false;
    gene=false;
    etat=Etat::RECHERCHE_SATISFACTION;
    type=TypeEcoAgent::COLONNE;
}

ColonneAgent::ColonneAgent(){
    numero=-1;
    sudoku=NULL;
    type=TypeEcoAgent::COLONNE;
}

vector<EcoAgent*> ColonneAgent::trouverGeneur(){
    vector<EcoAgent*> v;
    set<EcoAgent*> cellules;
    for(int i=0; i<sudoku->getTaille();i++){
        for(int j=i+1; j<sudoku->getTaille();j++){
            if (sudoku->getValue(i, numero)==sudoku->getValue(j,numero)){
                if(sudoku->getCell(i, numero)->getType()==CellType::GUESS)
                    cellules.insert(sudoku->getCell(i,numero));
                if(sudoku->getCell(j, numero)->getType()==CellType::GUESS)
                    cellules.insert(sudoku->getCell(j,numero));
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
