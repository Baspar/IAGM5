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
    for(int i=0; i<9;i++){
        set<int> valeurs;
        for(int j=1; j<10; j++)
            valeurs.insert(j);
        for(int j=0; j<9; j++){
            if(grid[i][j].getNumber().getValue() != 0){
                int nb= grid[i][j].getNumber().getValue();
                valeurs.erase(nb);
            }
        }
        for(int j=0; j<9; j++){
            if(grid[i][j].getNumber().getValue() == 0){
                int alea=rand() %(valeurs.size());
                set<int>::const_iterator it=valeurs.begin();
                for(int k=0; k<alea; k++)
                    it++;
                int nb=*it;
                valeurs.erase(nb);
                Number n=Number(nb, CellType::GUESS);
                grid[i][j].setNumber(n);
            }
        }
    }
}


