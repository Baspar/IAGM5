#include "Sudoku.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <time.h>

using namespace std;

Sudoku::Sudoku(int tm){//DONE
    tauxMutation=tm;
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
    tauxMutation=sudoku.getTauxMutation();
    grid.resize(9);
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++){
            const Cell cellTmp=sudoku.getCell(i, j);
            grid[i].push_back(Cell(cellTmp));
        }
}
int Sudoku::getTauxMutation()const{//DONE
    return tauxMutation;
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
    for(int i=0; i<9;i++)
        for(int j=0;j<9;j++)
            if(grid[i][j].getType() == CellType::GUESS)
                grid[i][j].setValue(1+rand()%9);

}
    int Sudoku::fitness()const{//DONE
        int fitness=0;
        //fitness Lignes
        for(int i=0; i<3; i++)
            fitness+=scoreLignes(i);

        //fitness Colonne
        for(int i=0; i<3; i++)
            fitness+=scoreCols(i);

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
        //if(chiffreMis.size() < 5)
            //return chiffreMis.size();
        //else if (chiffreMis.size() < 7)
            //return 2*chiffreMis.size();
        //else if (chiffreMis.size() < 9)
            //return 3*chiffreMis.size();
        //else
            //return 4*chiffreMis.size();
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
        Sudoku child1(sudo, false);
        Sudoku child2(sudo, false);

        int nbSep=3;
        set<int> sep;
        sep.insert(81);
        while(sep.size() != nbSep)
            sep.insert(1+rand()%80);


        bool mode=rand()%2==1;
        int old=0;
        for(int s : sep){
            mode = !mode;
            for(int i=old; i<s; i++){
                int x=i/9;
                int y=i%9;
                if(grid[x][y].getType() == CellType::GUESS){
                    if(mode){
                        child1.setValue(x, y, grid[x][y].getValue());
                        child2.setValue(x, y, sudo.getValue(x, y));
                    } else {
                        child1.setValue(x, y, sudo.getValue(x, y));
                        child2.setValue(x, y, grid[x][y].getValue());
                    }
                }
            }
            old=s;
        }
        return make_pair(child1, child2);
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
        cout << " " << fitness() << endl<< endl;
    }
void Sudoku::mutate(){//DONE
    if(rand()%100 < tauxMutation){
        //List every guess cell
        vector<pair<int, int>> guesses;
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                if(grid[i][j].getType() == CellType::GUESS)
                    guesses.push_back(make_pair(i, j));

        //If we can swap at least 2 guesses
        random_shuffle(guesses.begin(), guesses.end());
        setValue(guesses[0].first, guesses[0].second, 1+rand()%9);
    }
}
