#include "Number.hpp"

Number::Number(){//TODO
    value=0;
    cellType=CellType::GUESS;
}
Number::Number(const Number& number){
    value=number.getValue();
    cellType=number.getCellType();
}
Number::Number(int val, CellType c){//TODO
    value=val;
    cellType=c;
}
int Number::getValue() const{//TODO
    return value;
}
void Number::setValue(int val){//TODO
    value=val;
}
CellType Number::getCellType() const{//TODO
    return cellType;
}
