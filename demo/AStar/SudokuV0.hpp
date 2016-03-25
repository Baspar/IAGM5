#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iostream>
#include "Node.hpp"
#include "Cell.hpp"
#include <vector>
#include <fstream>
#include <math.h>

#include <sstream>
#include<string>

using namespace std;

class Sudoku : public Node {

    private:
        vector<vector<Cell*>> grid;
    public:
   	int taille;
	Sudoku(int t);
        Sudoku(string filename, int t);
        Sudoku(const Sudoku& sudoku);

        void setValue(int x, int y, int val);
        int getValue(int x, int y) const;
        Cell* getCell(int x, int y);
	void setCell(int x, int y, Cell* cell);

        bool naiveIsCorrect();
        void computeArcConsistency();
        void addLineWhereIs(int x, int y, set<Cell*>& cells);
        void addColumnWhereIs(int x, int y, set<Cell*>& cells);
        void addBlockWhereIs(int x, int y, set<Cell*>& cells);

        void updateRemaining();
	void updateRegion(int i, int j);
	void CaptainObvious();

        bool checkDouble();
	bool checkEmptyRemaining();
//        bool checkComplete();
        void afficher();
 	string  getID();
	    void updateGH();
	    set<Node*> getVoisins() ;
};
#endif

