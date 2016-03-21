#include "Cell.hpp"

Cell::Cell(){//DONE
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
