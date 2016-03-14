#include "Cell.hpp"
Cell::Cell(){//DONE
}
Cell::Cell( int x, int y, Sudoku* sud){//DONE
sudoku=sud;
    this->x=x;
    this->y=y;
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
void Cell::setValue(int val){
    number.setValue(val);
}
int Cell::getValue() const{
    return number.getValue();
}

vector<EcoAgent*> Cell::trouverGeneur(){
    vector<EcoAgent*> v=but[0]->trouverGeneur();
    for(int j=0;j<but[1]->trouverGeneur().size();j++)
        v.push_back(but[1]->trouverGeneur()[j]);
    return v;
}

void Cell::faireSatisfaction(){
    if( (but[0]->getEtat()==Etat::SATISFACTION) && (but[1]->getEtat()==Etat::SATISFACTION) )
        etat==Etat::SATISFACTION;
}
        
void Cell::agresser(EcoAgent* e){
    e->fuir(this);
}


EcoAgent* Cell::trouverPlacePourFuir(EcoAgent* e){
    return e;
}


void Cell::faireFuite(EcoAgent* e){
    

}
