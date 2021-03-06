#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iostream>
#include <vector>
#include "Cell.hpp"
#include <fstream>

using namespace std;

class Sudoku{
    private:
	vector<vector<Cell*>> grid;
        int G;
        int H;
        Sudoku* parent;
    public:
        set<Sudoku> enfants;
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
        int getG()const;
        void setG(int value);
        int getH()const;
        void setH(int value);
        void updateGH();
        Sudoku* getParent();
        void setParent(Sudoku* par);
        set<Sudoku> getNeighboor() const;
        void setNeighboor(set<Sudoku> list);

        bool operator<(const Sudoku b);
	bool egal(const Sudoku b);

        bool checkDouble();
        bool checkComplete();
	void afficher();
};
#endif
