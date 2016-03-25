#include "SudokuV0.hpp"


Sudoku::Sudoku(string filename, int t) : Node (){//DONE
    string contenu;
    ifstream fichier(filename, ios::in);
    getline(fichier, contenu);
    taille = (int) (contenu[0]-48);
    grid.resize(t);
    for(int i=0; i<t; i++)
	for(int j=0;j<t;j++)
	       grid[i].push_back(new Cell(t));
		
     // on ouvre en lecture
    if(fichier) // si l'ouverture a fonctionné
    {
        for(int i=0; i<t; i++){
            getline(fichier, contenu);
            for(int j=0; j<t;j++){
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
    updateRemaining();
    updateGH();

    setNodeID(getID());
}


Sudoku::Sudoku(int t) : Node() {
    grid.resize(t);
    for(int i=0; i<t; i++)
        grid[i].push_back(new Cell(t));
   computeArcConsistency();
}
Sudoku::Sudoku(const Sudoku& sudoku) : Node(sudoku){//DONE

    taille = sudoku.taille;
    grid.resize(taille);
    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
           	Number n = Number(sudoku.getValue(i,j));
		grid[i].push_back(new Cell(n,taille));
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
void Sudoku::updateRegion(int i, int j){
	for(Cell* cell : getCell(i,j)->getAdjacentCells()){
		if(cell->getValue()==0){
			grid[i][j]->updateRemaining();
		}
	}
}
string Sudoku::getID(){
	string id;
	for(int i=0; i<taille;i++){
		for(int j=0;j<taille;j++){
			id += std::to_string(getValue(i,j));
			id+=" # ";
		}
	}
	return id;
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
void Sudoku::CaptainObvious(){
               for(int i=0;i<taille;i++){
                        for(int j=0;j<taille;j++){
                                if(getValue(i,j) == 0){
                                        if(getCell(i,j)->getRemaining().size()==1){
                                                for(int k : getCell(i,j)->getRemaining()) setValue(i,j,k);
                                        }
                                }
                        }
                }
                updateRemaining();
		updateGH();
		setNodeID(getID());
}

set<Node*> Sudoku::getVoisins()  {
cout << "sudoku::getVoisins()	";
cout << endl;
	set<Node*> voisins;


bool captainObvious = true;

	if(captainObvious){
		CaptainObvious();

cout << "Captain";
cout << endl;

afficher();
	}

        for(int i=0; i<taille; i++){
                for(int j=0; j<taille; j++){
			if(getValue(i,j) == 0) {
				for(int k : getCell(i,j)->getRemaining()){
					Sudoku* tmp = new Sudoku(*this);
					tmp->setValue(i,j,k);
					// Doublons ?
						tmp->updateRemaining();
						if(tmp->checkEmptyRemaining()){
							tmp->setNodeID(tmp->getID());
							voisins.insert(tmp);
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
				return false;
			    }
			}
		    }
		}
	}
	return true;
}
bool Sudoku::checkEmptyRemaining() {
         for(int i =0;i<taille;i++){
		for(int j=0;j<taille;j++){
     	          if(getValue(i,j)==0){
                     if(getCell(i,j)->getRemaining().size() == 0){
                            return false;
                     }
                  }
        	}   
	}
	return true;
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
