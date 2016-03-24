#ifndef SUDOKUS_HPP
#define SUDOKUS_HPP

#include "Generation.hpp"

#include "Sudoku.hpp"

class Sudokus: public Generation{
    private:
        void shuffle();
        void insert(Sudoku* sud);

    public:
        Sudokus(int tailleGen, double tc, double tm);
        Sudokus(const Sudokus& sudoku);
        int getTaille();
        void evoluer();
        void selection();
};
#endif
