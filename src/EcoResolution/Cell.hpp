#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
#include <set>
#include "Number.hpp"

using namespace std;

class Cell: public EcoAgent{
    private:
        Number number;
    public:
        Cell();
        Cell(Number number);
        Cell(const Cell& cell);
        void setNumber(const Number& num);
        Number getNumber() const;
        CellType getType() const;
        void setValue(int val);
        int getValue() const;
};
#endif
