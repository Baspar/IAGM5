#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
#include <set>
#include "CellType.hpp"

using namespace std;

class Cell{
    private:
        int val;
        CellType type;
        set<int> remainingVal;
        set<Cell*> adjacentCells;
    public:
        Cell();
        Cell(int value);
        Cell(const Cell& cell);
        void setValue(int value);
        int getValue() const;
        CellType getType() const;
        void setAdjacentCells(const set<Cell*> cells);
        set<Cell*> getAdjacentCells() const;
        void removeRemainingValue(int value);
        set<int> getRemainingVal() const;
};
#endif
