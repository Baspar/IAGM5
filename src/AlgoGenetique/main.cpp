#include <iostream>
#include <time.h>
#include "Sudokus.hpp"
#include "Sudoku.hpp"
#include "Cell.hpp"


using namespace std;

int main(){
    srand(time(nullptr));

    Sudokus gen(10);
    for(int i=0; i<gen.getTailleGen(); i++)
        gen.getIndividu(i).afficher();
}
