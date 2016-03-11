#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iostream>
#include <vector>
#include "Cell.hpp"

using namespace std;

class Sudoku{
    private:
<<<<<<< HEAD
=======
        vector<vector<Cell>> grid;
>>>>>>> 18d90f0ff97db2e63e0044b7290b915da53af5be
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

        int getG();
        void setG(int value);
        int getH();
        void setH(int value);
        void updateGH();
<<<<<<< HEAD
	bool comp(Sudoku* a, Sudoku* b);
        Sudoku* getParent();
        void setParent(Sudoku* par);
        set<Sudoku> getNeighboor();
        void setNeighboor(set<Sudoku> list);

=======

        Sudoku* getParent();
        void setParent(Sudoku* par);
        set<Sudoku> getNeighboor();
        void setNeighboor(set<Sudoku> list);

>>>>>>> 18d90f0ff97db2e63e0044b7290b915da53af5be
        bool checkDouble();
        bool checkComplete();
};
#endif
