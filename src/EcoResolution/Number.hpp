#ifndef NUMBER_HPP
#define NUMBER_HPP
#include <iostream>
#include "CellType.hpp"

using namespace std;

class Number{
    private:
        int value;
        CellType cellType;
    public:
        Number();
        Number(const Number& number);
        Number(int val, CellType c);
        int getValue() const;
        void setValue(int val);
        CellType getCellType() const;
};
#endif
