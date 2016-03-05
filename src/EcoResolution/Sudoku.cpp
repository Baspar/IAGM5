#include "Sudoku.hpp"

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



