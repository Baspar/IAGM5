#include "AStar.hpp"
bool AStar::developSudoku(){//TODO
	std::priority_queue<Sudoku,std::vector<Sudoku>,Sudoku::comp> openList;
	while(openList.empty()!=true){
		current = FindLowestScore();

		if(current.checkComplete()){	
			return true;
		} else {
			CreateNeighboor(current);
			for(int k=0; k<current.getNeighboor().size(); k++){
			//	if(openList.Find(current.getNeighboor()[k])!=current.getNeightboor()::end){
					for(int i=0; i<9; i++){
					for(int j=0; j<9; j++) {
							if(current.getNeighboor()[k].grid[i][j].getValue()==0){
								current.getNeighboor()[k].grid[i][j].updateRemaining();
							}
						}
					}
					current.getNeighboor()[k].updateGH();
					openList.insert(current.getNeighboor()[k]);	
			//	}
			}
			closeList.insert(current);
			openList.erase(openList.Find(current));
		}

	}
	return false;
}

Sudoku AStar::FindLowestScore(){//TODO vérif
	Sudoku tmp=openList[0];
	int test=tmp.getG() + tmp.getH();
	for(int i=1; i<openList.size(); i++){
		if(openList[i].getG()+openList.getH()<test){
			tmp = openList[i];
			test = tmp.getG()+tmp.getH();
		}
	}
	return tmp:
}
void AStar::CreateNeighboor(Sudoku parent){//TODO
	set<Sudoku> list;
	Sudoku tmp;
	// on parcourt les cases vides
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(parent.grid[i]{j].getValue()==0){
				// pour toutes les valeurs encore disponibles
				for(int k = 0; k<parent.grid[i][j].getRemaining().size()){
					//Créer nouveau sudoku
					tmp = Sudoku(parent);
					tmp.setValue(i,j,parent.getRemaining()[k]);
					if(!tmp.checkDouble){
						list.insert(tmp);
					}
				}
			}
		}
	}
	parent.setNeighboor(list);
}
};
