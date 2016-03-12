#include <iostream>
#include <time.h>
#include "Sudokus.hpp"
#include "Sudoku.hpp"
#include "Cell.hpp"


using namespace std;

int main(){
    srand(time(nullptr));

    Sudokus oldGen(100, 50, 70);
    oldGen.getIndividu(0).afficher();
    return 0;

    int cpt = 0;
    int mem = oldGen.bestFitness();
    Sudoku bestSud = oldGen.getIndividu(99);

    while(oldGen.bestFitness() < 162){
        int bestFit = oldGen.bestFitness();
        if(bestFit <= mem){
            cpt++;
            if(cpt>200){
                cpt=0;
                bestSud.afficher();
                oldGen=Sudokus(100, 50, 70);
                bestSud = oldGen.getIndividu(99);
                mem = oldGen.bestFitness();
                cout << endl << "RESET" << endl << endl;
            }
        } else {
            cpt=0;
            mem=bestFit;
            bestSud = oldGen.getIndividu(99);
        }
        oldGen.selection();
        cout << cpt << "> " << oldGen.worstFitness() << " < " << oldGen.avgFitness() << " < " << oldGen.bestFitness() << "[" << bestSud.fitness() << "]"<< endl;
    }

    oldGen.getIndividu(99).afficher();
}
