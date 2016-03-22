#include "SudokuV0.hpp"


Sudoku::Sudoku(string filename, int t) : Node (){//DONE

taille = t;
    grid.resize(t);
    for(int i=0; i<t; i++)
	for(int j=0;j<t;j++)
	       grid[i].push_back(new Cell());
		
    ifstream fichier(filename, ios::in); // on ouvre en lecture
    if(fichier) // si l'ouverture a fonctionné
    {
        for(int i=0; i<t; i++){
            string contenu;
            getline(fichier, contenu);
            for(int j=0; j<t;j++){
                int test=(int) (contenu[j]-48);
                Number n;
                if(test==0)
                    n=Number(test, CellType::GUESS);
                else
                    n=Number(test, CellType::GIVEN);
                grid[i][j]->setNumber(n);
//		grid[i][j]->setValue(test);
            }
        }
        fichier.close();
    }
    computeArcConsistency();
    updateRemaining();
    updateGH();
}


Sudoku::Sudoku(int t) : Node() {
    grid.resize(t);
    for(int i=0; i<t; i++)
        grid[i].push_back(new Cell());
   computeArcConsistency();
}
Sudoku::Sudoku(const Sudoku& sudoku) : Node(sudoku){//DONE

    taille = sudoku.taille;
    grid.resize(taille);
    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
           	Number n = Number(sudoku.getValue(i,j));
		Cell tmp = Cell(n);
		Cell* p = &tmp;
		grid[i].push_back(new Cell(n));
//		grid[i][j]->setRemaining(sudoku->getCell(i,j)->getRemaining());	
	}
        }
    computeArcConsistency();
}
void Sudoku::setValue(int x, int y, int val){//DONE
    grid[x][y]->setValue(val);
}
int Sudoku::getValue(int x, int y)const  {//DONE
    return grid[x][y]->getNumber().getValue();
}
Cell* Sudoku::getCell(int x, int y) {//DONE
    return grid[x][y];
}
void Sudoku::setCell(int x, int y, Cell* cell){
	grid[x][y]=cell;
}
bool Sudoku::naiveIsCorrect(){//DONE
    return true;
}
void Sudoku::computeArcConsistency(){//DONE
    for(int x=0; x<taille; x++)
        for(int y=0; y<taille; y++){
            set<Cell*> cells;
            addLineWhereIs(x, y, cells);
            addColumnWhereIs(x, y, cells);
            addBlockWhereIs(x, y, cells);
            grid[x][y]->setAdjacentCells(cells);
        }
}
void Sudoku::addLineWhereIs(int x, int y, set<Cell*>& cells){//DONE
    for(int i=0; i<taille;i++)
        if(i!=x)
            cells.insert((grid[i][y]));
}
void Sudoku::addColumnWhereIs(int x, int y, set<Cell*>& cells){//DONE
    for(int i=0; i<taille;i++)
        if(i!=y)
            cells.insert((grid[x][i]));
}
void Sudoku::addBlockWhereIs(int x, int y, set<Cell*>& cells){//DONE
    int xBlock=x/sqrt(taille);
    int yBlock=y/sqrt(taille);
    for(int xCell=xBlock*sqrt(taille); xCell<(xBlock+1)*sqrt(taille); xCell++)
        for(int yCell=yBlock*sqrt(taille); yCell<(yBlock+1)*sqrt(taille); yCell++)
            if(xCell!=x && yCell!=y)
                cells.insert((grid[xCell][yCell]));
}
void Sudoku::updateRemaining() {
	for(int i=0;i<taille;i++) {
		for(int j =0; j<taille;j++) {
			if(grid[i][j]->getValue()==0){
				grid[i][j]->updateRemaining();
			}
		}
	}	
}
void Sudoku::updateGH(){ //TODO
	setG(0);
	setH(0);
	for(int i=0; i<taille; i++){
		for(int j=0; j<taille; j++){
			if(grid[i][j]->getValue()!=0){
				setG(getG()+1);
			} else {
				setH(getH()+grid[i][j]->getRemaining().size());
			}
		}
	}
}
set<Node*> Sudoku::getVoisins()  {
cout << "sudoku::getVoisins()	";
cout << endl;

	set<Node*> voisins;
        for(int i=0; i<taille; i++){
                for(int j=0; j<taille; j++){
			if(getValue(i,j) == 0) {
				getCell(i,j)->updateRemaining();
				for(int k : getCell(i,j)->getRemaining()){
					Sudoku tmp = Sudoku(*this);
					tmp.setValue(i,j,k);

					// Doublons ?
					if(!tmp.checkDouble()){	
						bool test = true;
						for(Cell* cell : tmp.getCell(i,j)->getAdjacentCells()){
							if(cell->getValue()==0){
								cell->updateRemaining();
								if(cell->getRemaining().size() == 0){
									test = false;
								}
							}
						}	
						if(test) {
							tmp.updateRemaining();

							voisins.insert(&tmp);
						}
					}
				}
			}
		}
	}
	return voisins;
}
bool Sudoku::checkDouble(){//TODO
	for(int i=0; i<taille; i++){
		for(int j=0; j<taille; j++){
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
void Sudoku::afficher(){
    int val;

    for(int i=0; i<taille; i++){
        if(i%((int)sqrt(taille))==0){
            cout<< "+";
            for(int j=0; j<taille; j++){
                cout << "-";
                if(j%((int)sqrt(taille))==2)
                    cout << "+";
                else
                    cout << "-";
            }
            cout << endl;
        }
        cout << "|";
        for(int j=0; j<taille; j++){
          val=grid[i][ j]->getNumber().getValue();
            cout << val;
            if(j%((int)sqrt(taille))==2)
                cout << "|";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << "+";
    for(int j=0; j<taille; j++){
        cout << "-";
        if(j%((int)sqrt(taille))==2)
            cout << "+";
        else
            cout << "-";
    }
    cout << endl;
}

