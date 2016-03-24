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
cout << "open	";
cout << openList.size();
cout << endl;
		current = openList.top();
		openList.pop();


current->afficher();
cout << current->getNodeID();
cout << endl;
cout << "G   ";
cout <<current->getG();
cout<<"		H    ";
cout<< current->getH();
cout << endl;
		if(graphe->Distance(current,b) == 0){
cout << "Victory";
cout << endl;
current->afficher();
			closeList.insert(current);
			return closeList;
		} else {

			set<Node*> d = current->getVoisins();
			for(Node* n : d) {
				if(!FindInList(n, closeList)){
//				if(!FindInQ(n, openList)){
n->afficher();
					n->updateGH();
cout << "G    ";
cout << n->getG();
cout << "    H    ";
cout << n->getH();
cout << endl;
					openList.push(n);
//				}
				}
				
			}
			closeList.insert(current);
		}
	}
	set<Node*> res;
	res.insert(a);
cout << "You dled";
cout << endl;
	return res;

}

bool AStar::FindInList(Node* n, set<Node*> list){
	for(Node* a : list){
		if(n->getNodeID()==a->getNodeID()){
			return true;
		}
	}
	return false;
}
bool AStar:: FindInQ(Node* n, priority_queue<Node*> q){
	priority_queue<Node*> tmp = q;
	while(!tmp.empty()){
		if(n->getNodeID() == tmp.top()->getNodeID()){
			return true;
		}
		tmp.pop();
	}
	return false;
}
