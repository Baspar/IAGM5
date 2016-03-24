#ifndef COMPARE_HPP
#define COMPARE_HPP

#include <iostream>
#include  "Node.hpp"

using namespace std;


class Compare{
	public:
		bool operator()(Node* a, Node* b);

};
#endif
