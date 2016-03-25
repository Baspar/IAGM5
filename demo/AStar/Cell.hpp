#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
#include <set>
#include "Number.hpp"

using namespace std;

class Cell{
    private:
        Number number;
        set<int> remainingVal;
        set<Cell*> adjacentCells;
    public:
        Cell(int taille);
        Cell(Number number, int taille);
        Cell(const Cell& cell);
	Cell(Cell* cell);
        void setNumber(const Number& num);
        Number getNumber() const;
        CellType getType() const;
        void setAdjacentCells(const set<Cell*> cells);
        set<Cell*> getAdjacentCells() const;
        void setValue(int val);
        int getValue() const;
        set<int> getRemaining();
        void setRemaining(set<int> poss);
        void updateRemaining();
};
#endif
