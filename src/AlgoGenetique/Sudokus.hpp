#ifndef SUDOKUS_HPP
#define SUDOKUS_HPP

#include <vector>
#include <algorithm>

#include "Sudoku.hpp"

class Sudokus{
    private:
        int tailleGen;
        int tauxCroisement;
        int tauxMutation;
        vector<Sudoku> generation;
    public:
        void mutate();
        int getTailleGen() const;
        int getTauxMutation()const;
        int getTauxCroisement()const;
        int getTrueTailleGen() const;
        Sudoku getIndividu(int i) const;
        Sudokus(int k, int tc, int tm);
        Sudokus(const Sudokus& oldGen);
        void selection();
        void shuffle();
        void insert(Sudoku sud);
        int bestFitness()const;
        int worstFitness()const;
        double avgFitness()const;
};
#endif
