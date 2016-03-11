#include <iostream>
#include <time.h>
#include "Sudokus.hpp"
#include "Sudoku.hpp"
#include "Cell.hpp"


using namespace std;

int main(){
    srand(time(nullptr));

    Sudokus oldGen(100, 100, 10);
    int cpt = 0;
    int mem = oldGen.bestFitness();

    while(oldGen.bestFitness() < 648){
        int bestFit = oldGen.bestFitness();
        oldGen.selection();
        oldGen.shuffle();

        Sudokus newGen(oldGen);
        newGen.mutate();
        if(newGen.bestFitness() > bestFit){
            oldGen=newGen;
            oldGen.getIndividu(99).afficher();
        }
        cout << cpt << "> ["<< oldGen.getTrueTailleGen() << "]" << oldGen.worstFitness() << " < " << oldGen.avgFitness() << " < " << oldGen.bestFitness() << endl;
    }

    oldGen.getIndividu(99).afficher();
}
