#include "Sudokus.hpp"

#include <algorithm>
#include <math.h>
#include <time.h>

void Sudokus::evoluer(){//DONE
    Sudokus oldGen(*this);
    oldGen.shuffle();

    for(Genome* gen: generation)
        delete gen;

    generation.clear();
    nombreGenerations++;

    for(int i=0; i<tailleGeneration/2-1; i++){
        Sudoku* indiv1 = (Sudoku*) oldGen.getIndividu(i);
        Sudoku* indiv2 = (Sudoku*) oldGen.getIndividu(i+1);
        if(((double)rand())/RAND_MAX<tauxCroisement){
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
    if(((double)rand())/RAND_MAX<tauxCroisement){
        pair<Genome*, Genome*> children = indiv1->croisement(indiv2);
        insert((Sudoku*)children.first);
        insert((Sudoku*)children.second);
    }else{
        insert(indiv1);
        insert(indiv2);
    }

    //for(Genome* gen : generation)
    for(vector<Genome*>::iterator it=generation.begin(); it != generation.end(); it++)
        if(((double)rand())/RAND_MAX<tauxMutation){
            Genome* tmp = (*it)->mutate();
            generation.erase(it);
            insert((Sudoku*)tmp);
        }
}
void Sudokus::selection(){//DONE
    for(Genome* gen:generation)
        cout << gen->fitness() << ", ";
    cout << endl;

    int tailleInit = generation.size();
    while(generation.size() > tailleInit/2){
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
            generation.insert(it,new Sudoku(sudoku));
            break;
        }
        it++;
    }
    if(it==generation.end())
        generation.insert(it, new Sudoku(sudoku));
}
int Sudokus::getTaille(){
    return ((Sudoku*)generation[0])->getTaille();
}

int main(){
    srand(time(nullptr));
    Sudokus myGen(50, 0.9, 0.4);
    cout << 2*myGen.getTaille()*myGen.getTaille() << endl;
    int bestFit = 0;
    while(myGen.bestFitness() < 2*myGen.getTaille()*myGen.getTaille()){
        myGen.selection();
        myGen.evoluer();
	if(bestFit < myGen.bestFitness()){
		bestFit = myGen.bestFitness();
		myGen.getIndividu(49)->afficher();
	}
    }
    cout << "Atteint en " << myGen.getNombreGenerations() << " generations" << endl; 
    myGen.getIndividu(49)->afficher();
}
