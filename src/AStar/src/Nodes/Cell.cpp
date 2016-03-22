#include "Cell.hpp"

Cell::Cell(int taille){//DONE
    // On remplit le vecteur de possiblités
    for(int i=1; i<taille+1; i++)
        remainingVal.insert(i);
}
Cell::Cell(Number num, int taille):number(num){//DONE
    for(int i=1; i<taille+1; i++)
        remainingVal.insert(i);

}
Cell::Cell(const Cell& cell):number(cell.getNumber()){//DONE
}
Cell::Cell(Cell* cell):number(cell->getNumber()){
}
Number Cell::getNumber() const{//DONE
    return number;
}
CellType Cell::getType() const{//DONE
    return number.getCellType();
}
void Cell::setNumber(const Number& num){//DONE
    number=num;
    for(Cell* cell : adjacentCells)
        remainingVal.erase(num.getValue());
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
set<int> Cell::getRemaining(){
	return remainingVal;
}
void Cell::setRemaining(set<int> poss){
	remainingVal=poss;
}
void Cell::updateRemaining(){//TODO
//	for(int i=0; i<getAdjacentCells().size(); i++){
//		if(remainingVal.find(getAdjacentCells()[i].getValue())!=remainingVal::end){
//			remainingVal.erase(remainingVal.find(getAdjacentCelss()[i].getValue()));
//		}
//	}
//        if(remainingVal.empty()) {
//		for(int i=1; i<10; i++) {
//			remainingVal.insert(i);
//		}

//        }
	for(Cell* c : getAdjacentCells()){
		if(c->getValue()!=0){
		if(remainingVal.find(c->getValue())!=remainingVal.end()){
			remainingVal.erase(c->getValue());
		}
		}
	}
    
}
