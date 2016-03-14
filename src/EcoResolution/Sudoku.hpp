#ifndef SUDOKU_HPP
#define SUDOKU_HPP

class Sudoku;

#include "Cell.hpp"
#include "EcoAgent.hpp"
#include <fstream>
#include <iostream>
#include <vector>


using namespace std;

class Sudoku{
    private:
        vector<vector<Cell>> grid;
        vector<EcoAgent*> ecoAgents;
    public:
        Sudoku();
        Sudoku(const Sudoku& sudoku);
        void setValue(int x, int y, int val);
        int getValue(int x, int y) const;
        Cell getCell(int x, int y) const;
        Cell* getpCell(int x, int y);
        void remplir();
        void afficher() const;
};
#endif
