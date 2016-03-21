#ifndef SUDOKUS_HPP
#define SUDOKUS_HPP

#include "Generation.hpp"

#include "Sudoku.hpp"

class Sudokus: public Generation{
    private:
        int tailleGen;
        void shuffle();
    public:
        Sudokus(int k, int tc, int tm);
        Sudokus(const Sudokus& oldGen);
        void insert(Sudoku sud);
        void evoluer();
        void selection();
};
#endif
