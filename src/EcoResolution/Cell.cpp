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
    vector<EcoAgent*> v;
    return v;
}

void Cell::faireSatisfaction(){

}
        
void Cell::agresser(EcoAgent* e){
    e->fuir(this);

}


EcoAgent* Cell::trouverPlacePourFuir(EcoAgent* e){
    return e;

}


void Cell::faireFuite(EcoAgent* e){
    

}
