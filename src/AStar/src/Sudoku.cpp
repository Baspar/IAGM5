#include "Sudoku.hpp"

bool Sudoku::operator<(const Sudoku b) {
    return(this->getG()+this->getH() >= b.getG()+ b.getH());
}
bool Sudoku::egal(const Sudoku b) {
    for(int i=0; i<9; i++) {	
	for(int j=0; j<9; j++) {
		if(grid[i][j]->getValue() != b.grid[i][j]->getValue()) { return false; }
	}
    }
    return true;
}
Sudoku::Sudoku(string filename){//DONE
    grid.resize(9);
    for(int i=0; i<9; i++)
	for(int j=0;j<9;j++)
	       grid[i].push_back(new Cell());
		

    ifstream fichier(filename, ios::in); // on ouvre en lecture
    if(fichier) // si l'ouverture a fonctionné
    {
        for(int i=0; i<9; i++){
            string contenu;
            getline(fichier, contenu);
            for(int j=0; j<9;j++){
                int test=(int) (contenu[j]-48);
                Number n;
                if(test==0)
                    n=Number(test, CellType::GUESS);
                else
                    n=Number(test, CellType::GIVEN);
                grid[i][j]->setNumber(n);
            }
        }
        fichier.close();
    }
    computeArcConsistency();

}


Sudoku::Sudoku(){//DONE
    grid.resize(9);
    for(int i=0; i<9; i++)
        grid[i].resize(9);
   computeArcConsistency();
}
Sudoku::Sudoku(const Sudoku& sudoku){//DONE
    grid.resize(9);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
		grid[i].push_back(new Cell());
           	Number n = Number(sudoku.getCell(i,j)->getValue());
		
		grid[i][j]->setNumber(n);
		grid[i][j]->setRemaining(sudoku.getCell(i,j)->getRemaining());	
	}
        }
    computeArcConsistency();
    
    G = sudoku.getG();
    H = sudoku.getH();
}
void Sudoku::setValue(int x, int y, int val){//DONE
    grid[x][y]->setValue(val);
}
int Sudoku::getValue(int x, int y) const{//DONE
    return grid[x][y]->getValue();
}
Cell* Sudoku::getCell(int x, int y) const{//DONE
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
            grid[x][y]->setAdjacentCells(cells);
        }
}
void Sudoku::addLineWhereIs(int x, int y, set<Cell*>& cells){//DONE
    for(int i=0; i<9;i++)
        if(i!=x)
            cells.insert((grid[i][y]));
}
void Sudoku::addColumnWhereIs(int x, int y, set<Cell*>& cells){//DONE
    for(int i=0; i<9;i++)
        if(i!=y)
            cells.insert((grid[x][i]));
}
void Sudoku::addBlockWhereIs(int x, int y, set<Cell*>& cells){//DONE
    int xBlock=x/3;
    int yBlock=y/3;
    for(int xCell=xBlock*3; xCell<(xBlock+1)*3; xCell++)
        for(int yCell=yBlock*3; yCell<(yBlock+1)*3; yCell++)
            if(xCell!=x && yCell!=y)
                cells.insert((grid[xCell][yCell]));
}
void Sudoku::updateRemaining() {
	for(int i=0;i<9;i++) {
		for(int j =0; j<9;j++) {
			if(grid[i][j]->getValue()==0){
				grid[i][j]->updateRemaining();
			}
		}
	}	
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
			if(grid[i][j]->getValue()!=0){
				setG(getG()+1);
			} else {
				setH(getH()+grid[i][j]->getRemaining().size());
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
set<Sudoku> Sudoku::getNeighboor() const {//DONE
	return enfants;
}
void Sudoku::setNeighboor(set<Sudoku> list){//DONE
	enfants=set<Sudoku>(list);
}

bool Sudoku::checkDouble(){//TODO
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
		    if(grid[i][j]->getValue()!=0){
	                for(Cell* cell : grid[i][j]->getAdjacentCells()){
        	            if(grid[i][j]->getValue()==cell->getValue()){
				return true;
			    }
			}
		    }
		}
	}
	return false;
}
bool Sudoku::checkComplete(){//TODO
	for(int i=0; i <9; i++){
		for(int j=0; j<9; j++){
			if(grid[i][j]->getValue()==0) {
				 return false;
			}
		}
	}
	return true;
}
void Sudoku::afficher(){
    int val;

    for(int i=0; i<9; i++){
        if(i%3==0){
            cout<< "+";
            for(int j=0; j<9; j++){
                cout << "-";
                if(j%3==2)
                    cout << "+";
                else
                    cout << "-";
            }
            cout << endl;
        }
        cout << "|";
        for(int j=0; j<9; j++){
          val=grid[i][ j]->getNumber().getValue();
            cout << val;
            if(j%3==2)
                cout << "|";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << "+";
    for(int j=0; j<9; j++){
        cout << "-";
        if(j%3==2)
            cout << "+";
        else
            cout << "-";
    }
    cout << endl;



}

