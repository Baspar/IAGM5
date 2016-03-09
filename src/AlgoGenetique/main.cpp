#include <iostream>
#include <time.h>
#include "Sudoku.hpp"
#include "Cell.hpp"


using namespace std;

int main(){
    srand(time(nullptr));
    Sudoku sud;
    Sudoku sudd;

    sud.remplir();
    sudd.remplir();


    sud.afficher();
    cout << endl << sud.fitness() <<endl;
    sudd.afficher();
    cout << endl << sudd.fitness() <<endl;

    pair<Sudoku, Sudoku> sudddd = sud*sudd;
    sudddd.first.afficher();
    sudddd.second.afficher();
}
