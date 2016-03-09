#include <iostream>
#include <time.h>
#include "Sudokus.hpp"
#include "Sudoku.hpp"
#include "Cell.hpp"


using namespace std;

int main(){
    srand(time(nullptr));

    Sudokus oldGen(100, 100, 100);

    //while(true){
    for(int i=0; i<50; i++){
        cout << "["<< oldGen.getTrueTailleGen() << "]" << oldGen.worstFitness() << " < " << oldGen.avgFitness() << " < " << oldGen.bestFitness() << endl;
        oldGen.selection();
        oldGen.mutate();
        oldGen.shuffle();

        Sudokus newGen(oldGen);
        oldGen=newGen;
    }

    for(int i=0; i<oldGen.getTailleGen(); i++)
        oldGen.getIndividu(i).afficher();
}
