#include "Cell.hpp"

Cell::Cell():number(){//DONE



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
void Cell::setNumber(Number num){//DONE
    number=num;
}
set<Cell*> Cell::getAdjacentCells() const{//DONE
    return adjacentCells;
}
void Cell::setAdjacentCells(const set<Cell*> cells){//DONE
    adjacentCells=cells;
}
void Cell::setValue(int val){
    number.setValue(val);
}
int Cell::getValue() const{
    return number.getValue();
}
set<Cell*> Cell::getRemaining(){
	return remainingVal;
}
void Cell::setRemaining(set<Cell*> poss){
	remainingVal=poss;
}
void Cell::updateRemaining(){//TODO
	for(int i=0; i<getAdjacentCells().size(); i++){
		if(remainingVal.find(getAdjacentCells()[i].getValue())!=remainingVal::end){
			remainingVal.erase(remainingVal.find(getAdjacentCelss()[i].getValue()));
		}
	}
}
