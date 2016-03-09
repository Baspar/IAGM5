#include "Sudoku.hpp"

#include <iostream>
#include <set>
#include <time.h>

using namespace std;

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
Sudoku::Sudoku(const Sudoku& sudoku, const bool& copyGuess){//DONE
    grid.resize(9);
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++){
            const Cell cellTmp=sudoku.getCell(i, j);
            if(copyGuess){
                grid[i].push_back(Cell(cellTmp));
            } else {
                if(cellTmp.getType()==CellType::GIVEN)
                    grid[i].push_back(Cell(cellTmp));
                else
                    grid[i].push_back(Cell());
            }
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
void Sudoku::remplir(){//DONE
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
    int Sudoku::fitness(){//DONE
        int fitness=0;
        //fitness Lignes
        for(int i=0; i<9; i++){
            set<int> chiffreMis;
            for(int j=0; j<9; j++)
                chiffreMis.insert(grid[i][j].getValue());
            fitness += chiffreMis.size();
        }
        //fitness Colonne
        for(int i=0; i<9; i++){
            set<int> chiffreMis;
            for(int j=0; j<9; j++)
                chiffreMis.insert(grid[j][i].getValue());
            fitness += chiffreMis.size();
        }
        //fitness Bloc
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                set<int> chiffreMis;
                for(int di=0; di<3; di++)
                    for(int dj=0; dj<3; dj++)
                        chiffreMis.insert(grid[i*3+di][j*3+dj].getValue());
                fitness += chiffreMis.size();
            }
        }

        return fitness;
    }
    int Sudoku::scoreLignes(int i) const{//DONE
        int out=0;
        for(int di=0; di<3; di++)
            out+=scoreLigne(i*3+di);
        return out;
    }
    int Sudoku::scoreLigne(int i)const{//DONE
        set<int> chiffreMis;
        for(int j=0; j<9; j++)
            if(grid[i][j].getValue()!=0)
                chiffreMis.insert(grid[i][j].getValue());
        return chiffreMis.size();
    }
    int Sudoku::scoreCols(int i)const{//DONE
        int out=0;
        for(int di=0; di<3; di++)
            out+=scoreCol(i*3+di);
        return out;
    }
    int Sudoku::scoreCol(int i)const{//DONE
        set<int> chiffreMis;
        for(int j=0; j<9; j++)
            if(grid[j][i].getValue()!=0)
                chiffreMis.insert(grid[j][i].getValue());
        return chiffreMis.size();
    }
    pair<Sudoku,Sudoku> Sudoku::operator*(const Sudoku& sudo) const{//DONE
        Sudoku maxLine(sudo, false);
        Sudoku maxCol(sudo, false);

        //Creation maxCol
        for(int j=0; j<3; j++){
            int score1 = sudo.scoreLignes(j);
            int score2 = scoreLignes(j);
            const Sudoku* goodSud=nullptr;
            if(score1>score2){
                goodSud=&sudo;
            } else {
                goodSud=this;
            }

            for(int dj=0; dj<3; dj++)
                for(int i=0; i<9; i++)
                    if(maxCol.getCell(i,j*3+dj).getType()==CellType::GUESS){
                        maxCol.setValue(i, j*3+dj, goodSud->getCell(i, j*3+dj).getValue());
                    }
        }

        //Creation maxLigne
        for(int i=0; i<3; i++){
            int score1 = sudo.scoreLignes(i);
            int score2 = scoreLignes(i);
            const Sudoku* goodSud=nullptr;
            if(score1>score2){
                goodSud=&sudo;
            } else {
                goodSud=this;
            }

            for(int di=0; di<3; di++)
                for(int j=0; j<9; j++)
                    if(maxLine.getCell(i*3+di, j).getType()==CellType::GUESS)
                        maxLine.setValue(i*3+di, j,goodSud->getCell(i*3+di, j).getValue());
        }

        return make_pair(maxLine, maxCol);
    }
    void Sudoku::afficher() const{//DONE
        for(int i=0; i<9; i++){
            if(i%3==0){
                cout << "+";
                for(int j=0; j<9; j++){
                    cout << "---";
                    if(j%3==2)
                        cout << "+";
                    else
                        cout << "-";
                }
                cout << "--" << endl;
            }
            cout << "|";
            for(int j=0; j<9; j++){
                int val=getCell(i, j).getNumber().getValue();
                char type=(getCell(i, j).getType()==CellType::GIVEN?'-':' ');
                if(val!=0)
                    cout << type << val << type;
                else
                    cout <<"   ";
                if(j%3==2)
                    cout << "|";
                else
                    cout << " ";
            }
            cout << " " << scoreLigne(i);
            cout << endl;
        }
        cout << "+";
        for(int j=0; j<9; j++){
            cout << "---";
            if(j%3==2)
                cout << "+";
            else
                cout << "-";
        }
        cout << "--" << endl;
        cout << "|";
        for(int j=0; j<9; j++){
            cout << " " << scoreCol(j) << " ";
            if(j%3==2)
                cout << "|";
            else
                cout << " ";
        }
        cout << endl<< endl;
    }
