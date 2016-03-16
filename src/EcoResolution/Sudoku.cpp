#include "Sudoku.hpp"
#include <time.h>
#include <set>


Sudoku::Sudoku(){//DONE
    cout << this << endl;
    grid.resize(9);
    for(int i=0; i<9; i++)
        for(int j=0;j<9;j++){
            grid[i].push_back(new Cell(i,j));
            grid[i][j]->setSudoku(this);
            cout << getCell(i, j)->getSudoku() << endl;
        }
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
                grid[i][j]->setNumber(n);
            }
        }
        fichier.close();
    }
    for(int i=0; i<9;i++){
        ecoAgents.push_back(new LigneAgent(i));
        ((LigneAgent*)ecoAgents[i])->setSudoku(this);
    }
    for(int i=0; i<9; i++){
        ecoAgents.push_back(new ColonneAgent(i));
        ((ColonneAgent*)ecoAgents[i+9])->setSudoku(this);
    }
}
void Sudoku::setValue(int x, int y, int val){//DONE
    grid[x][y]->setValue(val);
}
int Sudoku::getValue(int x, int y) const{//DONE
    return grid[x][y]->getNumber().getValue();
}
Cell* Sudoku::getCell(int x, int y){//DONE
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
                    if(grid[i*3+k][j*3+m]->getValue() != 0){
                        int nb=grid[i*3+k][j*3+m]->getValue();
                        valeurs.erase(nb);
                    }
                }
            }
            for(int k=0;k<3;k++){
                for(int m=0; m<3;m++){
                    if(grid[i*3+k][j*3+m]->getValue() == 0){
                        int alea=rand() %(valeurs.size());
                        set<int>::const_iterator it=valeurs.begin();
                        for(int l=0; l<alea; l++)
                            it++;
                        int nb=*it;
                        valeurs.erase(nb);
                        grid[i*3+k][j*3+m]->setValue(nb);
                    }
                }
            }
        }
    }
}
    void Sudoku::afficher(){//DONE
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
                int val=getCell(i, j)->getNumber().getValue();
                char type=(getCell(i, j)->getType()==CellType::GIVEN?'-':' ');
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
    void Sudoku::afficher(int xAtt, int yAtt, int xAgr, int yAgr) {//DONE
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
                int val=getCell(i, j)->getNumber().getValue();
                char type=(getCell(i, j)->getType()==CellType::GIVEN?'|':(i==xAtt && j==yAtt)?'+':(i==xAgr && j==yAgr)?'-':' ');
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

bool Sudoku::estFini(){
    //for(int i=0; i<ecoAgents.size();i++)
        //if(ecoAgents.at(i)->getEtat()!=Etat::SATISFACTION)
            //return false;
    //return true;
    return (fitness()==162);
}


EcoAgent* Sudoku::choixEcoAgent(){
    EcoAgent* e = nullptr;
    int scoreMin = 10;
    for(int i=0; i<9; i++){
        int score = scoreLigne( ((LigneAgent*)ecoAgents[i])->getNumero() );
        if(score < scoreMin){
            scoreMin = score;
            e = ecoAgents[i];
            cout << "  Ligne #" << i << ": " << score << endl;
        }
    }
    for(int i=9; i<18; i++){
        int score = scoreCol( ((ColonneAgent*)ecoAgents[i])->getNumero() );
        if(score < scoreMin){
            scoreMin = score;
            e = ecoAgents[i];
            cout << "  Colonne #" << (i-9) << ": " << score << endl;
        }
    }
    cout << e << endl;
    return e;
}
 int Sudoku::fitness(){//DONE
        int fitness=0;
        //fitness Lignes
        for(int i=0; i<3; i++)
            fitness+=scoreLignes(i);

        //fitness Colonne
        for(int i=0; i<3; i++)
            fitness+=scoreCols(i);

        return fitness;
    }
    int Sudoku::scoreLignes(int i){//DONE
        int out=0;
        for(int di=0; di<3; di++)
            out+=scoreLigne(i*3+di);
        return out;
    }
    int Sudoku::scoreLigne(int i){//DONE
        set<int> chiffreMis;
        for(int j=0; j<9; j++)
            if(grid[i][j]->getValue()!=0)
                chiffreMis.insert(grid[i][j]->getValue());
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
    int Sudoku::scoreCols(int i){//DONE
        int out=0;
        for(int di=0; di<3; di++)
            out+=scoreCol(i*3+di);
        return out;
    }
    int Sudoku::scoreCol(int i){//DONE
        set<int> chiffreMis;
        for(int j=0; j<9; j++)
            if(grid[j][i]->getValue()!=0)
                chiffreMis.insert(grid[j][i]->getValue());
        return chiffreMis.size();
    }
