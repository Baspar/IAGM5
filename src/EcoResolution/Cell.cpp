#include "Cell.hpp"
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

void Cell::agresser(EcoAgent* e){//WIP
    e->fuir(this);
}


EcoAgent* Cell::trouverPlacePourFuir(EcoAgent* e){//WIP
    //cout << "trouver1"<< endl;
    //cout << sudoku << endl;
    int blocLigne=x/3;
    int blocColonne=y/3;
    bool b=false;
    int nvx;
    int nvy;
    while (!b){
        int alea=rand() %3;
        //cout << "alea " << alea << endl;
        int alea2=rand() %3;
        //cout << "alea2 " << alea2 << endl;
        nvx=3*blocLigne+alea;
        //cout << "nvx " << nvx << endl;
        nvy=3*blocColonne+alea2;
        //cout << "nvy " << nvy << endl;
        if ((!( ((nvx) ==x) && ((nvy)==y))) && sudoku->getCell(nvx,nvy)->getType()!=CellType::GIVEN )
            b=true;
        //cout << "test" << endl;
    }
    sudoku->afficher(x, y, nvx, nvy);
    return sudoku->getCell(nvx,nvy);
}


void Cell::faireFuite(EcoAgent* e){//WIP
    cout <<"Je suis iciiiiiii" << endl;
    int n = ((Cell*)e)->getValue();
    int n2 = this->getValue();
    ((Cell*)e)->setValue(n2);
    this->setValue(n);
}
