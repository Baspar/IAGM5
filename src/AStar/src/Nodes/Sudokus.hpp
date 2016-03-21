#ifndef SUDOKUS_HPP
#define SUDOKUS_HPP

#include <iostream>
#include "Graphe.hpp"

using namespace std;

class Sudokus : public Graphe {
	public:
		Sudokus(Node n);
		virtual int Distance(Node a, Node b);

};
#endif

