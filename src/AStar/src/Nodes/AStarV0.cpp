#include "AStarV0.hpp"

bool AStar::FindShortestWay(Node a, Node b){

	set<Node> closeList;
	std::priority_queue<Node> openList;
	set<Node> searchList;

	openList.push(a);
	searchList.insert(a);

	while(!openList.enpty()){
		current = openList.top();
		openList.pop();
		searchList.earse(current);

		if(graphe.distance(current,b) == 0){
			return true;
		} else {
			for(Node n : current.getEnfants()) {
				if(searchList.find(n) == searchList.end()) {
					n.updateGH();
					openList.push(n);
					searchList.insert(n);
				}	
			}
			closeList.insert(current);
		}
	}

	return false;
}
