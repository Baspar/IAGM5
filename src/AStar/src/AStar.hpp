#ifndef ASTAR_HPP
#define ASTAR_HPP

#include <iostream>
#include <vector>
#include "Sudoku.hpp"

using namespace std;

class AStar{
	private:
	       	Sudoku current;
		set<Sudoku> closeList;
		set<Sudoku> openList;
		
		bool developSudoku();
		Sudoku FindLowestScore();
		void CreateNeighboor(Sudoku parent);
}

