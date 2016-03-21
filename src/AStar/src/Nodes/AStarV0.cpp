#include "AStarV0.hpp"

bool AStar::FindShortestWay(Node a, Node b){

cout << "Find Shortest Way";
cout << endl;
int c = 0;
	set<Node> closeList;
	std::priority_queue<Node> openList;

	openList.push(a);

	while(!openList.empty()){
c++;
cout << "Choix current    ";
cout << c;
cout << endl;
		current = openList.top();
		openList.pop();


cout << "Test Distance";
cout << endl;
		if(graphe.Distance(current,b) == 0){
			return true;
		} else {
cout << "Voisins()";
cout << endl;
			for(Node n : current.getVoisins()) {
				if(closeList.find(n) == closeList.end()) {
					n.updateGH();
					openList.push(n);
				}	
			}
			closeList.insert(current);
		}
	}

	return false;
}
