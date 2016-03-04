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
        Cell();
        Cell(Number number);
        Cell(const Cell& cell);
        void setNumber(Number num);
        Number getNumber() const;
        CellType getType() const;
        void setAdjacentCells(const set<Cell*> cells);
        set<Cell*> getAdjacentCells() const;
        void setValue(int val);
        int getValue() const;
	set<Cell*> getRemaining();
	void setRemaining(set<Cell*> poss);
	void updateRemaining();
};
#endif
