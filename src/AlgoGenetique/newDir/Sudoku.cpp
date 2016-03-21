#include "Sudoku.hpp"

#include "Number.hpp"
#include "CellType.hpp"

#include <algorithm>
#include <set>
#include <math.h>
#include <iostream>
#include <fstream>

int Sudoku::scoreCols(int i){//DONE
    int out=0;
    for(int di=0; di<sqrtTaille; di++)
        out += scoreCol(i*sqrtTaille+di);
    return out;
}
int Sudoku::scoreLignes(int i){//DONE
    int out=0;
    for(int di=0; di<sqrtTaille; di++)
        out += scoreLigne(i*sqrtTaille+di);
    return out;
}
int Sudoku::scoreLigne(int i){//DONE
    set<int> chiffreMis;
    for(int j=0; j<taille; j++)
        if(grid[i][j].getValue()!=0)
            chiffreMis.insert(grid[i][j].getValue());
    return chiffreMis.size();
}
int Sudoku::scoreCol(int i){//DONE
    set<int> chiffreMis;
    for(int j=0; j<taille; j++)
        if(grid[j][i].getValue()!=0)
            chiffreMis.insert(grid[j][i].getValue());
    return chiffreMis.size();
}
Sudoku::Sudoku(){//DONE
    ifstream fichier("test.txt", ios::in); // on ouvre en lecture

    if(fichier) // si l'ouverture a fonctionné
    {
        string contenu;

        getline(fichier, contenu);
        taille = contenu[0]-48;

        sqrtTaille = sqrt(taille);

        grid.resize(taille);
        for(int i=0; i<taille; i++)
            grid[i].resize(taille, Cell());

        for(int i=0; i<taille; i++){
            getline(fichier, contenu);
            for(int j=0; j<taille;j++){
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
void Sudoku::afficher(){//DONE
    for(int i=0; i<taille; i++){
        if(i%sqrtTaille==0){
            cout << "+";
            for(int j=0; j<taille; j++){
                cout << "---";
                if(j%sqrtTaille==sqrtTaille-1)
                    cout << "+";
                else
                    cout << "-";
            }
            cout << "--" << endl;
        }
        cout << "|";
        for(int j=0; j<taille; j++){
            int val=getCell(i, j).getNumber().getValue();
            char type=(getCell(i, j).getType()==CellType::GIVEN?'-':' ');
            if(val!=0)
                cout << type << val << type;
            else
                cout <<"   ";
            if(j%sqrtTaille==sqrtTaille-1)
                cout << "|";
            else
                cout << " ";
        }
        cout << " " << (int)scoreLigne(i);
        cout << endl;
    }
    cout << "+";
    for(int j=0; j<taille; j++){
        cout << "---";
        if(j%sqrtTaille==sqrtTaille-1)
            cout << "+";
        else
            cout << "-";
    }
    cout << "--" << endl;
    cout << "|";
    for(int j=0; j<taille; j++){
        cout << " " << (int)scoreCol(j) << " ";
        if(j%sqrtTaille==sqrtTaille-1)
            cout << "|";
        else
            cout << " ";
    }
    cout << " " << (int)fitness() << endl<< endl;
}
Genome* Sudoku::mutate(){//DONE
    Sudoku* out = new Sudoku(this);

    int i = rand()%sqrtTaille;
    int j = rand()%sqrtTaille;

    //On list chaque case "mutable"
    vector<pair<int, int>> guesses;
    for(int di=0; di<sqrtTaille; di++)
        for(int dj=0; dj<sqrtTaille; dj++)
            if(grid[i*sqrtTaille+di][j*sqrtTaille+dj].getType() == CellType::GUESS)
                guesses.push_back(make_pair(i*sqrtTaille+di, j*sqrtTaille+dj));

    // Si on a au moins 2 possibilité d'échange
    if(guesses.size()>2){
        random_shuffle(guesses.begin(), guesses.end());
        int val0 = getValue(guesses[0].first, guesses[0].second);
        int val1 = getValue(guesses[1].first, guesses[1].second);

        out->setValue(guesses[0].first, guesses[0].second, val1);
        out->setValue(guesses[1].first, guesses[1].second, val0);
    }

    return out;
}
double Sudoku::fitness(){//DONE
        double fitness=0;

        for(int i=0; i<sqrtTaille; i++){
            //fitness Lignes
            fitness += scoreLignes(i);
            //fitness Colonne
            fitness += scoreCols(i);
        }

        return fitness;
}
pair<Genome*, Genome*> Sudoku::croisement(Genome* genome){//DONE
    Sudoku* child1 = new Sudoku((Sudoku*)genome, false);
    Sudoku* child2 = new Sudoku((Sudoku*)genome, false);

    int nbSeparateurs=3;

    set<int> separateurs;
    separateurs.insert(taille*taille*2);
    while(separateurs.size() != nbSeparateurs)
        separateurs.insert(1+rand()%(taille*taille*2-1));


    bool mode=rand()%2==1;
    int old=0;
    for(int separateur : separateurs){
        mode = !mode;
        for(int i=old; i<separateur; i++){
            int x=i/taille;
            int y=i%taille;
            if(grid[x][y].getType() == CellType::GUESS){
                if(mode){
                    child1->setValue(x, y, grid[x][y].getValue());
                    child2->setValue(x, y, ((Sudoku*)genome)->getValue(x, y));
                } else {
                    child1->setValue(x, y, ((Sudoku*)genome)->getValue(x, y));
                    child2->setValue(x, y, grid[x][y].getValue());
                }
            }
        }
        old=separateur;
    }
    return make_pair(child1, child2);
}
void Sudoku::remplir(){//DONE
    for(int i=0; i<sqrtTaille;i++){
        for(int j=0;j<sqrtTaille;j++){
            set<int> valeurs;
            for(int l=1; l<taille+1; l++)
                valeurs.insert(l);
            for(int k=0;k<sqrtTaille;k++){
                for(int m=0; m<sqrtTaille;m++){
                    if(grid[i*sqrtTaille+k][j*sqrtTaille+m].getValue() != 0){
                        int nb=grid[i*sqrtTaille+k][j*sqrtTaille+m].getValue();
                        valeurs.erase(nb);
                    }
                }
            }
            for(int k=0;k<sqrtTaille;k++){
                for(int m=0; m<sqrtTaille;m++){
                    if(grid[i*sqrtTaille+k][j*sqrtTaille+m].getValue() == 0){
                        int alea=rand() %(valeurs.size());
                        set<int>::const_iterator it=valeurs.begin();
                        for(int l=0; l<alea; l++)
                            it++;
                        int nb=*it;
                        valeurs.erase(nb);
                        grid[i*sqrtTaille+k][j*sqrtTaille+m].setValue(nb);
                    }
                }
            }
        }
    }
}
void Sudoku::setValue(int x, int y, int val){//DONE
    grid[x][y].setValue(val);
}
int Sudoku::getValue(int x, int y){//DONE
    return grid[x][y].getNumber().getValue();
}
Cell Sudoku::getCell(int x, int y){//DONE
    return grid[x][y];
}
Sudoku::Sudoku(Sudoku* sudoku){//DONE
    taille = sudoku->getTaille();
    sqrtTaille = sudoku->getSqrtTaille();

    grid.resize(taille);
    for(int i=0; i<taille; i++)
        for(int j=0; j<taille; j++){
            Cell cellTmp=sudoku->getCell(i, j);
            grid[i].push_back(Cell(cellTmp));
        }
}
Sudoku::Sudoku(Sudoku* sudoku, bool copyGuess){//DONE
    taille = sudoku->getTaille();
    sqrtTaille = sudoku->getSqrtTaille();

    grid.resize(taille);
    for(int i=0; i<taille; i++)
        for(int j=0; j<taille; j++){
            Cell cellTmp=sudoku->getCell(i, j);
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
int Sudoku::getSqrtTaille(){//DONE
    return sqrtTaille;
}
int Sudoku::getTaille(){//DONE
    return taille;
}
