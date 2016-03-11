#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iostream>
#include <vector>
#include "Cell.hpp"
#include <fstream>

using namespace std;

class Sudoku{
    private:
        int tauxMutation;
        vector<vector<Cell>> grid;
        int scoreLigne(int i) const;
        int scoreCol(int i) const;
    public:
        Sudoku(int tm);
        Sudoku(const Sudoku& sudoku);
        Sudoku(const Sudoku& sudoku, const bool& copyGuess);
        int getTauxMutation()const;
        void setValue(int x, int y, int val);
        int getValue(int x, int y) const;
        Cell getCell(int x, int y) const;
        void remplir();
        int fitness()const;
        pair<Sudoku, Sudoku> operator*(const Sudoku& sudo) const;
        void afficher() const;
        int scoreLignes(int i) const;
        int scoreCols(int i) const;
        void mutate();
};
#endif
