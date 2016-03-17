#ifndef ASTAR_HPP
#define ASTAR_HPP

#include <iostream>
#include <queue>
#include <vector>
#include "Sudoku.hpp"

using namespace std;

class AStar{
	private:
	       	Sudoku current;
	public:
		set<Sudoku> closeList;
//		set<Sudoku> searchList;
		Sudoku developSudoku(Sudoku gridIni);
        //Sudoku FindLowestScore();
		set<Sudoku> CreateNeighboor(Sudoku parent);
};


#endif

