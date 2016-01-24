#include "Cell.hpp"

Cell::Cell(){//DONE
    val=0;
    type=CellType::GUESS;
    for(int i=1; i<10; i++)
        remainingVal.insert(i);
}
Cell::Cell(int value):Cell(){//DONE
    val=value;
    type=CellType::GIVEN;
}
Cell::Cell(const Cell& cell){//DONE
    //We do not copy the adjacent cells, they will be recomputed
    val=cell.getValue();
    type=cell.getType();
    remainingVal=cell.getRemainingVal();
}
int Cell::getValue() const{//DONE
    return val;
}
CellType Cell::getType() const{//DONE
    return type;
}
void Cell::setValue(int value){//DONE
    val=value;
    remainingVal.clear();
    for(Cell* cell:adjacentCells)
        cell->removeRemainingValue(value);
}
set<Cell*> Cell::getAdjacentCells() const{//DONE
    return adjacentCells;
}
void Cell::setAdjacentCells(const set<Cell*> cells){//DONE
    adjacentCells=cells;
}
void Cell::removeRemainingValue(int value){//DONE
    remainingVal.erase(value);
}
set<int> Cell::getRemainingVal() const{//DONE
    return remainingVal;
}
