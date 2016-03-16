#include <iostream>
#include <time.h>
#include "Sudokus.hpp"
#include "Sudoku.hpp"
#include "Cell.hpp"


using namespace std;

int main(){
    srand(time(nullptr));

    Sudokus oldGen(100, 90, 10);
    int cpt = 0;
    int mem = oldGen.bestFitness();
    Sudoku bestSud = oldGen.getIndividu(99);

    int i=0;
    while(oldGen.bestFitness() < 162){
        i++;
        int bestFit = oldGen.bestFitness();
        if(bestFit <= mem){
            cpt++;
            if(cpt>500){
                cpt=0;
                bestSud.afficher();
                //oldGen=Sudokus(100, 90, 10);
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
        oldGen.shuffle();

        oldGen = Sudokus(oldGen);
        oldGen.mutate();
        cout << cpt << "> " << oldGen.worstFitness() << " < " << oldGen.avgFitness() << " < " << oldGen.bestFitness() << "[" << bestSud.fitness() << "]"<< endl;
    }

    oldGen.getIndividu(99).afficher();
    cout << "Solution atteinte en " << i << " generations" << endl;
}
