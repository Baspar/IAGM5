#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iostream>
#include <vector>
#include "Cell.hpp"

using namespace std;

class Sudoku{
    private:
        int G;
        int H;
        Sudoku* parent;
        set<Sudoku> enfants;
    public:
        vector<vector<Cell>> grid;
        Sudoku();
        Sudoku(const Sudoku& sudoku);
        void setValue(int x, int y, int val);
        int getValue(int x, int y) const;
        Cell getCell(int x, int y) const;
        bool naiveIsCorrect();
        void computeArcConsistency();
        void addLineWhereIs(int x, int y, set<Cell*>& cells);
        void addColumnWhereIs(int x, int y, set<Cell*>& cells);
        void addBlockWhereIs(int x, int y, set<Cell*>& cells);

        int getG()const;
        void setG(int value);
        int getH()const;
        void setH(int value);
        void updateGH();
        Sudoku* getParent();
        void setParent(Sudoku* par);
        set<Sudoku> getNeighboor();
        void setNeighboor(set<Sudoku> list);

        bool operator<(const Sudoku b);

        bool checkDouble();
        bool checkComplete();
};
#endif
