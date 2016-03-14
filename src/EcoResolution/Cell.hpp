#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
#include <set>
#include "Number.hpp"
#include "EcoAgent.hpp"
#include <vector>

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
        vector<EcoAgent*> trouverGeneur();
        void faireSatisfaction();
        void agresser(EcoAgent* e);
        EcoAgent* trouverPlacePourFuir(EcoAgent* e);
        void faireFuite(EcoAgent* e); 
};
#endif
