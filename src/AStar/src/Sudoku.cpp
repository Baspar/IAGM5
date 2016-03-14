#include "Sudoku.hpp"

bool Sudoku::operator<(const Sudoku b) {
    return(this->getG()+this->getH() <= b.getG()+ b.getH());
}
Sudoku::Sudoku(){//DONE
    grid.resize(9);
    for(int i=0; i<9; i++)
        grid[i].resize(9, Cell());
    computeArcConsistency();
}
Sudoku::Sudoku(const Sudoku& sudoku){//DONE
    grid.resize(9);
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++){
            const Cell cellTmp=sudoku.getCell(i, j);
            grid[i].push_back(Cell(cellTmp));
        }
    computeArcConsistency();
}
void Sudoku::setValue(int x, int y, int val){//DONE
    grid[x][y].setValue(val);
}
int Sudoku::getValue(int x, int y) const{//DONE
    return grid[x][y].getNumber().getValue();
}
Cell Sudoku::getCell(int x, int y) const{//DONE
    return grid[x][y];
}
bool Sudoku::naiveIsCorrect(){//DONE
    return true;
}
void Sudoku::computeArcConsistency(){//DONE
    for(int x=0; x<9; x++)
        for(int y=0; y<9; y++){
            set<Cell*> cells;
            addLineWhereIs(x, y, cells);
            addColumnWhereIs(x, y, cells);
            addBlockWhereIs(x, y, cells);
            grid[x][y].setAdjacentCells(cells);
        }
}
void Sudoku::addLineWhereIs(int x, int y, set<Cell*>& cells){//DONE
    for(int i=0; i<9;i++)
        if(i!=x)
            cells.insert(&(grid[i][y]));
}
void Sudoku::addColumnWhereIs(int x, int y, set<Cell*>& cells){//DONE
    for(int i=0; i<9;i++)
        if(i!=x)
            cells.insert(&(grid[x][i]));
}
void Sudoku::addBlockWhereIs(int x, int y, set<Cell*>& cells){//DONE
    int xBlock=x/3;
    int yBlock=y/3;
    for(int xCell=xBlock*3; xCell<(xBlock+1)*3; xCell++)
        for(int yCell=yBlock*3; yCell<(yBlock+1)*3; yCell++)
            if(xCell!=x && yCell!=y)
                cells.insert(&(grid[xCell][yCell]));
}
int Sudoku::getG()const{//DONE
	return G;
}
void Sudoku::setG(int value){//DONE
	G = value;
}
int Sudoku::getH()const{//DONE
	return H;
}
void Sudoku::setH(int value){//DONE
	H = value;
}
void Sudoku::updateGH(){ //TODO
	setG(0);
	setH(0);
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(grid[i][j].getNumber().getValue()!=0){
				setG(getG()+1);
			} else {
				setH(getH()+grid[i][j].getRemaining().size());
			}
		}
	}
}
Sudoku* Sudoku::getParent(){//DONE
	return parent;
}
void Sudoku::setParent(Sudoku* par){//DONE
	parent=par;
}
set<Sudoku> Sudoku::getNeighboor(){//DONE
	return enfants;
}
void Sudoku::setNeighboor(set<Sudoku> list){//DONE
	enfants=list;
}

bool Sudoku::checkDouble(){//TODO
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(grid[i][j].getValue()!=0){
                for(Cell* cell : grid[i][j].getAdjacentCells())
                    if(grid[i][j].getValue()==cell->getValue())
						return true;
			}
		}
	}
	return false;
}
bool Sudoku::checkComplete(){//TODO
	bool tmp = true;
	for(int i=0; i <9; i++){
		for(int j=0; j<9; j++){
			if(grid[i][j].getValue()==0) {
				return false;
			}
		}
	}
	return true;
}
