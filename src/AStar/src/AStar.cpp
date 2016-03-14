#include "AStar.hpp"
bool AStar::developSudoku(){//WIK
        std::priority_queue <Sudoku> openList;
	while(openList.empty()!=true){
	//	current = FindLowestScore();
		current = openList.top();
		openList.pop();
		if(current.checkComplete()){
			return true;
		} else {
			CreateNeighboor(current);
			for(Sudoku n : current.getNeighboor()){
			//	if(openList.Find(current.getNeighboor()[k])!=current.getNeightboor()::end){

// faire une méthode dans Sudoku pour la comparaison

					for(int i=0; i<9; i++){
					for(int j=0; j<9; j++) {
							if(n.grid[i][j].getValue()==0){
								n.grid[i][j].updateRemaining();
							}
						}
					}
					n.updateGH();
					openList.push(n);
			//	}
			}
			closeList.insert(current);
		}

	}
	return false;
}

void AStar::CreateNeighboor(Sudoku parent){//TODO
	set<Sudoku> list;
	Sudoku tmp;
	// on parcourt les cases vides
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(parent.grid[i][j].getValue()==0){
				// pour toutes les valeurs encore disponibles
				for(int k : parent.grid[i][j].getRemaining()) {
//				for(int k = 0; k<parent.grid[i][j].getRemaining().size(); k++){
					//Créer nouveau sudoku
					tmp = Sudoku(parent);
					tmp.setValue(i,j,k);
					if(!tmp.checkDouble()){
						list.insert(tmp);
					}
				}
			}
		}
	}
	parent.setNeighboor(list);
}

