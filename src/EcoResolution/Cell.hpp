#ifndef CELL_HPP
#define CELL_HPP

class Cell;

#include "LigneAgent.hpp"
#include "ColonneAgent.hpp"
#include "Number.hpp"
#include "EcoAgent.hpp"
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Cell: public EcoAgent{
    private:
        Number number;
        int x,y;
        Sudoku* sudoku;
    public:
        Sudoku* getSudoku();
        Cell();
        Cell(Number number);
        Cell(int x, int y, Sudoku* sud);
        Cell(const Cell& cell);
        void setNumber(const Number& num);
        Number getNumber() const;
        CellType getType() const;
        void setValue(int val);
        int getValue() const;
        vector<EcoAgent*> trouverGeneur();
        void faireSatisfaction();
        void agresser(EcoAgent* e);
        EcoAgent* trouverPlacePourFuir(EcoAgent* e);
        void faireFuite(EcoAgent* e); 
};
#endif
