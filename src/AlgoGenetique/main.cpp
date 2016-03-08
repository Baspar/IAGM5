#include <iostream>
#include <time.h>
#include "Sudoku.hpp"
#include "Cell.hpp"

using namespace std;

int main(){
    Sudoku sud;
    Sudoku sudd;

    sud.remplir();
    sudd.remplir();


    sud.afficher();
    cout << endl << sud.fitness() <<endl;
    sudd.afficher();
    cout << endl << sudd.fitness() <<endl;
}
