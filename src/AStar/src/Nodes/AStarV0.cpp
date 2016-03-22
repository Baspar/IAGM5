#include "AStarV0.hpp"

AStar::AStar()  {
	graphe = Graphe();
}

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
cout<<"H    ";
cout<< current.getH();
cout << endl;
		if(graphe.Distance(current,b) == 0){
cout << "Victory";
cout << endl;
			return true;
		} else {
cout << "Voisins()           ";
cout << current.getVoisins().size();
cout << endl;

Node & tmp = current;
set<Node*> d = tmp.getVoisins();
cout << d.size();
cout <<endl;
cout << "boucle";
cout << endl;
//			for(Node n : d) {

cout << "close test";
cout << endl;
//				if(closeList.find(n) == closeList.end()) {
//					n.updateGH();
//					openList.push(n);
//				}	
//			}
			closeList.insert(current);
		}
	}

	return false;
}
