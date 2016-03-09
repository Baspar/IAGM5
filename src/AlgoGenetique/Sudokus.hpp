#ifndef SUDOKUS_HPP
#define SUDOKUS_HPP

#include <vector>
#include "Sudoku.hpp"

class Sudokus{
    private:
        int tailleGen;
        vector<Sudoku> generation;
    public:
        int getTailleGen() const;
        Sudoku getIndividu(int i) const;
        Sudokus(int k);
        Sudokus(const Sudokus& oldGen);
        void selection();
        void shuffle();
        void insert(Sudoku sud);
};
#endif
