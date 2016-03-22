#include "Sudokus.hpp"

#include <algorithm>
#include <math.h>
#include <time.h>

void Sudokus::evoluer(){//DONE
    Sudokus oldGen(*this);
    oldGen.shuffle();

    generation.clear();
    nombreGenerations++;

    for(int i=0; i<tailleGeneration/2-1; i++){
        Sudoku* indiv1 = (Sudoku*) oldGen.getIndividu(i);
        Sudoku* indiv2 = (Sudoku*) oldGen.getIndividu(i+1);
        if(rand()%100<tauxCroisement){
            pair<Genome*, Genome*> children = indiv1->croisement(indiv2);
            insert((Sudoku*)children.first);
            insert((Sudoku*)children.second);
        }else{
            insert(indiv1);
            insert(indiv2);
        }
    }

    Sudoku* indiv1 = (Sudoku*) oldGen.getIndividu(0);
    Sudoku* indiv2 = (Sudoku*) oldGen.getIndividu(tailleGeneration/2-1);
    if(rand()%100<tauxCroisement){
        pair<Genome*, Genome*> children = indiv1->croisement(indiv2);
        insert((Sudoku*)children.first);
        insert((Sudoku*)children.second);
    }else{
        insert(indiv1);
        insert(indiv2);
    }
}
void Sudokus::selection(){//DONE
    int tailleInit = generation.size();
    while(generation.size() > tailleInit){
        int myRand = rand()%(generation.size()*(1+generation.size())/2);
        int indice = generation.size() - floor( (-1+sqrt(1+8*myRand))/2 ) - 1;
        generation.erase(generation.begin()+indice);
    }
}
void Sudokus::shuffle(){//DONE
    random_shuffle(generation.begin(), generation.end());
}
Sudokus::Sudokus(int tailleGen, double tc, double tm){//DONE
    tailleGeneration = tailleGen;
    tauxCroisement = tc;
    tauxMutation = tm;
    for(int i=0; i<tailleGen; i++){
        Sudoku* sudoku = new Sudoku();
        sudoku->remplir();
        insert(sudoku);
    }
}
Sudokus::Sudokus(const Sudokus& sudoku){
    tailleGeneration = sudoku.getTailleGeneration();
    tauxCroisement = sudoku.getTauxCroisement();
    tauxMutation = sudoku.getTauxMutation();

    for(int i=0; i<tailleGeneration; i++)
        generation.push_back(new Sudoku( (Sudoku*)sudoku.getConstIndividu(i)));
}
void Sudokus::insert(Sudoku* sudoku){
    int fitness = sudoku->fitness();
    vector<Genome*>::iterator it = generation.begin();
    while(it < generation.end()){
        if((*it)->fitness() >= fitness){
            generation.insert(it, sudoku);
            break;
        }
        it++;
    }
    if(it==generation.end())
        generation.insert(it, sudoku);
}

int main(){
    srand(time(nullptr));
    Sudokus myGen(50, 0.5, 0.5);
    myGen.getIndividu(49)->afficher();
    myGen.evoluer();
    myGen.getIndividu(49)->afficher();
}
