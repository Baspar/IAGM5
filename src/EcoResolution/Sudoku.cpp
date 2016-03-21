#include "Sudoku.hpp"
#include <time.h>
#include <set>
#include <math.h>


Sudoku::Sudoku(){//DONE
    ifstream fichier("test.txt", ios::in); // on ouvre en lecture
    if(fichier) // si l'ouverture a fonctionné
    {
        string contenu;
        getline(fichier, contenu);
        taille=(int) (contenu[0]-48);
        grid.resize(taille);
        for(int i=0; i<taille; i++)
            for(int j=0;j<taille;j++){
                grid[i].push_back(new Cell(i,j));
             grid[i][j]->setSudoku(this);
        }
        for(int i=0; i<taille; i++){
            getline(fichier, contenu);
            for(int j=0; j<taille;j++){
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
    for(int i=0; i<taille;i++){
        ecoAgents.push_back(new LigneAgent(i));
        ((LigneAgent*)ecoAgents[i])->setSudoku(this);
    }
    for(int i=0; i<taille; i++){
        ecoAgents.push_back(new ColonneAgent(i));
        ((ColonneAgent*)ecoAgents[i+taille])->setSudoku(this);
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
    for(int i=0; i<(int) sqrt(taille);i++){
        for(int j=0;j<(int) sqrt(taille);j++){
            set<int> valeurs;
            for(int l=1; l<taille+1; l++)
                valeurs.insert(l);
            for(int k=0;k<(int) sqrt(taille);k++){
                for(int m=0; m<(int) sqrt(taille);m++){
                    if(grid[i*(int) sqrt(taille)+k][j*(int) sqrt(taille)+m]->getValue() != 0){
                        int nb=grid[i*(int) sqrt(taille)+k][j*(int) sqrt(taille)+m]->getValue();
                        valeurs.erase(nb);
                    }
                }
            }
            for(int k=0;k<(int) sqrt(taille);k++){
                for(int m=0; m<(int) sqrt(taille);m++){
                    if(grid[i*(int) sqrt(taille)+k][j*(int) sqrt(taille)+m]->getValue() == 0){
                        int alea=rand() %(valeurs.size());
                        set<int>::const_iterator it=valeurs.begin();
                        for(int l=0; l<alea; l++)
                            it++;
                        int nb=*it;
                        valeurs.erase(nb);
                        grid[i*(int) sqrt(taille)+k][j*(int) sqrt(taille)+m]->setValue(nb);
                    }
                }
            }
        }
    }
    for(int i=0; i<2*taille; i++)
        ecoAgents[i]->checkSatisfaction();
}
void Sudoku::afficher(){//DONE
    for(int i=0; i<taille; i++){
        if(i%(int) sqrt(taille)==0){
            cout << "+";
            for(int j=0; j<taille; j++){
                cout << "---";
                if(j%(int) sqrt(taille)==(int) sqrt(taille)-1)
                    cout << "+";
                else
                    cout << "-";
            }
            cout << "--" << endl;
        }
        cout << "|";
        for(int j=0; j<taille; j++){
            int val=getCell(i, j)->getNumber().getValue();
            char type=(getCell(i, j)->getType()==CellType::GIVEN?'-':' ');
            if(val!=0)
                cout << type << val << type;
            else
                cout <<"   ";
            if(j%(int) sqrt(taille)==(int) sqrt(taille)-1)
                cout << "|";
            else
                cout << " ";
        }
        cout << " " << scoreLigne(i);
        cout << endl;
    }
    cout << "+";
    for(int j=0; j<taille; j++){
        cout << "---";
        if(j%(int) sqrt(taille)==(int) sqrt(taille)-1)
            cout << "+";
        else
            cout << "-";
    }
    cout << "--" << endl;
    cout << "|";
    for(int j=0; j<taille; j++){
        cout << " " << scoreCol(j) << " ";
        if(j%(int) sqrt(taille)==(int) sqrt(taille)-1)
            cout << "|";
        else
            cout << " ";
    }
    cout << " " << fitness() << endl<< endl;
}
void Sudoku::afficher(int xAtt, int yAtt, int xAgr, int yAgr) {//DONE
    for(int i=0; i<taille; i++){
        if(i%(int) sqrt(taille)==0){
            cout << "+";
            for(int j=0; j<taille; j++){
                cout << "---";
                if(j%(int) sqrt(taille)==(int) sqrt(taille)-1)
                    cout << "+";
                else
                    cout << "-";
            }
            cout << "--" << endl;
        }
        cout << "|";
        for(int j=0; j<taille; j++){
            int val=getCell(i, j)->getNumber().getValue();
            char type=(getCell(i, j)->getType()==CellType::GIVEN?'|':(i==xAtt && j==yAtt)?'+':(i==xAgr && j==yAgr)?'-':' ');
            if(val!=0)
                cout << type << val << type;
            else
                cout <<"   ";
            if(j%(int) sqrt(taille)==(int) sqrt(taille)-1)
                cout << "|";
            else
                cout << " ";
        }
        cout << " " << scoreLigne(i);
        cout << endl;
    }
    cout << "+";
    for(int j=0; j<taille; j++){
        cout << "---";
        if(j%(int) sqrt(taille)==(int) sqrt(taille)-1)
            cout << "+";
        else
            cout << "-";
    }
    cout << "--" << endl;
    cout << "|";
    for(int j=0; j<taille; j++){
        cout << " " << scoreCol(j) << " ";
        if(j%(int) sqrt(taille)==(int) sqrt(taille)-1)
            cout << "|";
        else
            cout << " ";
    }
    cout << " " << fitness() << endl<< endl;
}

bool Sudoku::estFini(){
    for(int i=0; i<ecoAgents.size();i++)
    if(ecoAgents.at(i)->getEtat()!=Etat::SATISFACTION)
        return false;
    afficher();    
    return true;
    //return (fitness()==taille*taille*2);
}


EcoAgent* Sudoku::choixEcoAgent(){
    EcoAgent* e = nullptr;
    set<int> valeurs;
    int scoreMin = taille+1;
   for(int i=0; i<taille; i++){
        int score = scoreLigne( ((LigneAgent*)ecoAgents[i])->getNumero() );
        if(score==scoreMin)
             valeurs.insert(i);
        if(score < scoreMin){
             scoreMin = score;
             valeurs.clear();
             valeurs.insert(i);
        }
    }
     for(int i=taille; i<2*taille; i++){
        int score = scoreCol( ((ColonneAgent*)ecoAgents[i])->getNumero() );
        if(score==scoreMin)
             valeurs.insert(i);
        if(score < scoreMin){
             scoreMin = score;
             valeurs.clear();
             valeurs.insert(i);
        }
     }   
   // cout << "score Min" << scoreMin << endl; 
    /*int scoreMax=0;
    for(int i=0; i<taille; i++){
        int score = scoreLigne( ((LigneAgent*)ecoAgents[i])->getNumero() );
        if(score!=taille){
            if(score==scoreMax)
                valeurs.insert(i);
            if(score > scoreMax){
                scoreMax = score;
                valeurs.clear();
                valeurs.insert(i);
            }
        }
    }
     for(int i=taille; i<2*taille; i++){
        int score = scoreCol( ((ColonneAgent*)ecoAgents[i])->getNumero() );
        if(score!=taille){
            if(score==scoreMax)
                valeurs.insert(i);
            if(score > scoreMax){
                scoreMax = score;
                valeurs.clear();
                valeurs.insert(i);
            }
        }
    }*/
    int alea=rand() %(valeurs.size());
    set<int>::const_iterator it=valeurs.begin();
    for(int l=0; l<alea; l++)
        it++;
    int nb=*it;
   // cout << nb << endl;
    return ecoAgents[nb];
}
int Sudoku::fitness(){//DONE
    int fitness=0;
    //fitness Lignes
    for(int i=0; i<(int) sqrt(taille); i++)
        fitness+=scoreLignes(i);

    //fitness Colonne
    for(int i=0; i<(int) sqrt(taille); i++)
        fitness+=scoreCols(i);

    return fitness;
}
int Sudoku::scoreLignes(int i){//DONE
    int out=0;
    for(int di=0; di<(int) sqrt(taille); di++)
        out+=scoreLigne(i*(int) sqrt(taille)+di);
    return out;
}
int Sudoku::scoreLigne(int i){//DONE
    set<int> chiffreMis;
    for(int j=0; j<taille; j++)
        if(grid[i][j]->getValue()!=0)
            chiffreMis.insert(grid[i][j]->getValue());
    return chiffreMis.size();
}
int Sudoku::scoreCols(int i){//DONE
    int out=0;
    for(int di=0; di<(int) sqrt(taille); di++)
        out+=scoreCol(i*(int) sqrt(taille)+di);
    return out;
}
int Sudoku::scoreCol(int i){//DONE
    set<int> chiffreMis;
    for(int j=0; j<taille; j++)
        if(grid[j][i]->getValue()!=0)
            chiffreMis.insert(grid[j][i]->getValue());
    return chiffreMis.size();
}
int Sudoku::getTaille(){
    return taille;
}

