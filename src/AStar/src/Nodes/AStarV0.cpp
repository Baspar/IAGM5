#include "AStarV0.hpp"

AStar::AStar(Graphe* grap )  {
    graphe=grap;
}

set<Node*> AStar::FindShortestWay(Node* a, Node* b){

cout << "Find Shortest Way";
cout << endl;
int c = 0;
	set<Node*> closeList;
	std::priority_queue<Node*> openList;

	openList.push(a);

	while(!openList.empty()){
c++;
cout << "Choix current    ";
cout << closeList.size();
cout << endl;
		current = openList.top();
		openList.pop();


cout<<"H    ";
cout<< current->getH();
cout << endl;
		if(graphe->Distance(current,b) == 0){
cout << "Victory";
cout << endl;
			closeList.insert(current);
			return closeList;
		} else {

			set<Node*> d = current->getVoisins();
			for(Node* n : d) {

				if(closeList.find(n) == closeList.end()) {
					n->updateGH();
					openList.push(n);
				}	
			}
			closeList.insert(current);
		}
	}
	set<Node*> res;
	res.insert(a);
	return res;
}
