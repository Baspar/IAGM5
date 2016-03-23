#include "Cell.hpp"
#include <math.h>
void Cell::setSudoku(Sudoku* sud){
    sudoku = sud;
}
Cell::Cell( int xc, int yc){//DONE
    sudoku=nullptr;
    x=xc;
    y=yc;
    /* if(trouverGeneur().size()==0){
       gene=false;
       etat=Etat::SATISFACTION;
       }
       else {
       gene=true;
       etat=Etat::RECHERCHE_SATISFACTION;
       }*/
}
Sudoku* Cell::getSudoku(){
    return sudoku;
}
Cell::Cell(Number num):number(num){//DONE
    type=TypeEcoAgent::CELLULE;
}
Cell::Cell(const Cell& cell):number(cell.getNumber()){//DONE
    type=TypeEcoAgent::CELLULE;
}
Number Cell::getNumber() const{//DONE
    return number;
}
CellType Cell::getType() const{//DONE
    return number.getCellType();
}
void Cell::setNumber(const Number& num){//DONE
    number=num;
}
void Cell::setValue(int val){//DONE
    number.setValue(val);
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

void Cell::agresser(EcoAgent* e, EcoAgent* c){//WIP
    e->fuir(this, c);
}


EcoAgent* Cell::trouverPlacePourFuir(EcoAgent* e, EcoAgent* c){//WIP
    //cout << "trouver1"<< endl;
    //cout << sudoku << endl;
    int blocLigne=x/(int) sqrt(sudoku->getTaille());
    int blocColonne=y/(int) sqrt(sudoku->getTaille());
    bool b=false;
    int nvx;
    int nvy;
    set<pair<int,int> > casePossible;
    int min;
    for(int i=0; i<(int) sqrt(sudoku->getTaille());i++){
        for(int j=0; j<(int) sqrt(sudoku->getTaille());j++){
            nvx=(int) sqrt(sudoku->getTaille())*blocLigne+i;
            nvy=(int) sqrt(sudoku->getTaille())*blocColonne+j;
            if ((!( ((nvx) ==x) && ((nvy)==y))) && sudoku->getCell(nvx,nvy)->getType()!=CellType::GIVEN && sudoku->getCell(nvx,nvy)->getEtat()!=Etat::SATISFACTION){
                if(c->getType()==TypeEcoAgent::LIGNE){
                    if(((LigneAgent*)c)->getNumero()!=nvx){
                       if (((LigneAgent*)c)->nombreOccurence(sudoku->getValue(nvx,nvy),y)==min)
                            casePossible.insert(make_pair(nvx,nvy));
                       else if(((LigneAgent*)c)->nombreOccurence(sudoku->getValue(nvx,nvy),y)<min){
                            casePossible.clear();
                            casePossible.insert(make_pair(nvx,nvy));
                       }
                   }      
                }    
                if(c->getType()==TypeEcoAgent::COLONNE ){
                    if(((ColonneAgent*)c)->getNumero()!=nvy){
                        if (((ColonneAgent*)c)->nombreOccurence(sudoku->getValue(nvx,nvy),x)==min)
                            casePossible.insert(make_pair(nvx,nvy));
                       else if(((ColonneAgent*)c)->nombreOccurence(sudoku->getValue(nvx,nvy),x)<min){
                            casePossible.clear();
                            casePossible.insert(make_pair(nvx,nvy));
                        } 
                    }   
                }
            }    
        }
    }
    int chance=rand() %100;
    if(casePossible.size()==0 || chance >95){
        while (!b){
            int alea=rand() %(int) sqrt(sudoku->getTaille());
            //cout << "alea " << alea << endl;
            int alea2=rand() %(int) sqrt(sudoku->getTaille());
            //cout << "alea2 " << alea2 << endl;
            nvx=(int) sqrt(sudoku->getTaille())*blocLigne+alea;
            //cout << "nvx " << nvx << endl;
            nvy=(int) sqrt(sudoku->getTaille())*blocColonne+alea2;
            //cout << "nvy " << nvy << endl;
            if ((!( ((nvx) ==x) && ((nvy)==y))) && sudoku->getCell(nvx,nvy)->getType()!=CellType::GIVEN )
                b=true;
            //cout << "test" << endl;
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


void Cell::faireFuite(EcoAgent* e){//WIP
    int n = ((Cell*)e)->getValue();
    int n2 = this->getValue();
    ((Cell*)e)->setValue(n2);
    this->setValue(n);

}
