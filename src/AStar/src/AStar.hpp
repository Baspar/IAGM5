#ifndef ASTAR_HPP
#define ASTAR_HPP

#include <iostream>
#include <queue>
#include <vector>
#include "Sudoku.hpp"

using namespace std;

class AStar{
	public:
		Sudoku current;
		set<Sudoku> closeList;
//		set<Sudoku> searchList;
		Sudoku developSudoku(Sudoku gridIni);
        //Sudoku FindLowestScore();
		set<Sudoku> CreateNeighboor(Sudoku parent);
		void test(Sudoku s);
};


#endif

