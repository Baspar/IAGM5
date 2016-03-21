#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iostream>
#include "Node.hpp"
#include "Cell.hpp"
#include <vector>
#include <fstream>
using namespace std;

class Sudoku : public Node {

    private:
        vector<vector<Cell*>> grid;
    public:
        Sudoku();
        Sudoku(string filename);
        Sudoku(const Sudoku& sudoku);
        void setValue(int x, int y, int val);
        int getValue(int x, int y) const;
        Cell* getCell(int x, int y) const;
        bool naiveIsCorrect();
        void computeArcConsistency();
        void addLineWhereIs(int x, int y, set<Cell*>& cells);
        void addColumnWhereIs(int x, int y, set<Cell*>& cells);
        void addBlockWhereIs(int x, int y, set<Cell*>& cells);

        void updateRemaining();

        bool checkDouble();
        bool checkComplete();
        void afficher();

	virtual void updateG();
	virtual void updateH();
	virtual void updateGH();
};
#endif

