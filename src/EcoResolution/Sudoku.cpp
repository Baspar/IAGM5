#include "Sudoku.hpp"
#include <time.h>

Sudoku::Sudoku(){//DONE
    grid.resize(9);
    for(int i=0; i<9; i++)
        grid[i].resize(9, Cell());
    ifstream fichier("test.txt", ios::in); // on ouvre en lecture
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
                grid[i][j].setNumber(n);
            }
        }
        fichier.close();
    }
}
Sudoku::Sudoku(const Sudoku& sudoku){//DONE
    grid.resize(9);
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++){
            const Cell cellTmp=sudoku.getCell(i, j);
            grid[i].push_back(Cell(cellTmp));
        }
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
void Sudoku::remplir(){
    srand (time(NULL));
    for(int i=0; i<3;i++){
        for(int j=0;j<3;j++){
            set<int> valeurs;
            for(int l=1; l<10; l++)
                valeurs.insert(l);
            for(int k=0;k<3;k++){
                for(int m=0; m<3;m++){
                    if(grid[i*3+k][j*3+m].getValue() != 0){
                        int nb=grid[i*3+k][j*3+m].getValue();
                        valeurs.erase(nb);
                    }
                }
            }
            for(int k=0;k<3;k++){
                for(int m=0; m<3;m++){
                    if(grid[i*3+k][j*3+m].getValue() == 0){
                        int alea=rand() %(valeurs.size());
                        set<int>::const_iterator it=valeurs.begin();
                        for(int l=0; l<alea; l++)
                            it++;
                        int nb=*it;
                        valeurs.erase(nb);
                        grid[i*3+k][j*3+m].setValue(nb);
                    }
                }
            }
        }
    }
}


