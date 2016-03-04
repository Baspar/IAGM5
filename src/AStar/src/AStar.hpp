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
		set<Sudoku> closeList;
		
		std::priority_queue<Sudoku,std::vector<int>, compare> openList;
	public:
		Sudoku compare(Suoku a, Sudoku b);
		bool developSudoku();
		//Sudoku FindLowestScore();
		void CreateNeighboor(Sudoku parent);
}

