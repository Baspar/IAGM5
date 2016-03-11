#include <iostream>
#include <time.h>
#include "Sudokus.hpp"
#include "Sudoku.hpp"
#include "Cell.hpp"


using namespace std;

int main(){
    srand(time(nullptr));

    Sudokus oldGen(100, 100, 0);
    int cpt = 0;
    int mem = oldGen.bestFitness();

    while(oldGen.bestFitness() < 162){
        int bestFit = oldGen.bestFitness();
        if(bestFit == mem){
            cpt++;
            if(cpt>150){
                cpt=0;
                oldGen.getIndividu(99).afficher();
                oldGen=Sudokus(100, 100, 0);
                cout << endl << "RESET" << endl << endl;
            }
        } else {
            cpt=0;
            mem=bestFit;
        }
        cout << cpt << "> ["<< oldGen.getTrueTailleGen() << "]" << oldGen.worstFitness() << " < " << oldGen.avgFitness() << " < " << oldGen.bestFitness() << endl;
        oldGen.selection();
        oldGen.mutate();
        oldGen.shuffle();

        Sudokus newGen(oldGen);
        oldGen=newGen;
    }

    oldGen.getIndividu(99).afficher();
}
