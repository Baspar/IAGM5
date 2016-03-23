#include "Cell.hpp"
#include <math.h>
void Cell::setSudoku(Sudoku* sud){
    sudoku = sud;
}
Cell::Cell( int xc, int yc){//DONE
    sudoku=nullptr;
    x=xc;
    y=yc;
    tailleMemoire=3;
    memoire.resize(tailleMemoire);
}
Sudoku* Cell::getSudoku(){
    return sudoku;
}
Cell::Cell(Number num):number(num){//DONE
}
Cell::Cell(const Cell& cell):number(cell.getNumber()){//DONE
}
Number Cell::getNumber() const{//DONE
    return number;
}
CellType Cell::getType() const{//DONE
    return number.getCellType();
}
void Cell::setNumber(const Number& num){//DONE
    number=num;
    ajouterMemoire(num.getValue());
}
void Cell::setValue(int val){//DONE
    number.setValue(val);
    ajouterMemoire(val);
}
int Cell::getValue() const{//DONE
    return number.getValue();
}
vector<EcoAgent*> Cell::trouverGeneur(){//WIP
    vector<EcoAgent*> v=but[0]->trouverGeneur();
    for(int j=0;j<but[1]->trouverGeneur().size();j++)
        v.push_back(but[1]->trouverGeneur()[j]);
    return v;
}

void Cell::faireSatisfaction(){//WIP
    if( (but[0]->getEtat()==Etat::SATISFACTION) && (but[1]->getEtat()==Etat::SATISFACTION) )
        etat==Etat::SATISFACTION;
}

void Cell::agresser(EcoAgent* e){//WIP
    e->fuir(this);
}


EcoAgent* Cell::trouverPlacePourFuir(EcoAgent* e){//WIP
    int blocLigne=x/(int) sqrt(sudoku->getTaille());
    int blocColonne=y/(int) sqrt(sudoku->getTaille());
    bool b=false;
    int nvx;
    int nvy;
    set<pair<int,int> > casePossible;
    for(int i=0; i<(int) sqrt(sudoku->getTaille());i++){
        for(int j=0; j<(int) sqrt(sudoku->getTaille());j++){
            nvx=(int) sqrt(sudoku->getTaille())*blocLigne+i;
            nvy=(int) sqrt(sudoku->getTaille())*blocColonne+j;
            if ((!( ((nvx) ==x) && ((nvy)==y))) && sudoku->getCell(nvx,nvy)->getType()!=CellType::GIVEN && sudoku->getCell(nvx,nvy)->getEtat()!=Etat::SATISFACTION){
                bool b2=false;
                for(int i=0; i<memoire.size();i++){
                    if(memoire[i]==sudoku->getCell(nvx,nvy)->getValue()){
                        b2=true;
                    }
                }         
                if(!b2)        
                    casePossible.insert(make_pair(nvx,nvy));
            }    
        }
    }
    int chance=rand() %100;
    if(casePossible.size()==0 || chance >90){
        while (!b){
            int alea=rand() %(int) sqrt(sudoku->getTaille());
            int alea2=rand() %(int) sqrt(sudoku->getTaille());
            nvx=(int) sqrt(sudoku->getTaille())*blocLigne+alea;
            nvy=(int) sqrt(sudoku->getTaille())*blocColonne+alea2;
            if ((!( ((nvx) ==x) && ((nvy)==y))) && sudoku->getCell(nvx,nvy)->getType()!=CellType::GIVEN )
                b=true;
        }
    }
    else{
        int alea=rand() %(casePossible.size());
        set<pair<int,int> >::const_iterator it=casePossible.begin();
        for(int l=0; l<alea; l++)
            it++;
        nvx=it->first;
        nvy=it->second;
    }
    sudoku->afficher(x, y, nvx, nvy);
    return sudoku->getCell(nvx,nvy);
}
void Cell::ajouterMemoire(int i){
    if(memoire.size()==tailleMemoire){
        memoire.erase(memoire.begin());
    }
    memoire.push_back(i);
}
void Cell::faireFuite(EcoAgent* e){//WIP
    int n = ((Cell*)e)->getValue();
    int n2 = this->getValue();
    ((Cell*)e)->setValue(n2);
    this->setValue(n);

}
