#include "Sudoku.hpp"

bool AStar::developSudoku(){//TODO

	while(openList.empty()!=true){
		current = openList.top();
		openList.pop();
		if(current.checkComplete()){	
			return true;
		} else {
			//Création 
			CreateNeighboor(current);

			for(int k=0; k<current.getNeighboor().size(); k++){
				for(int i=0; i<9; i++){
					for(int j=0; j<9; j++) {
						if(current.getNeighboor()[k].grid[i][j].getValue()==0){
							current.getNeighboor()[k].grid[i][j].updateRemaining();
						}
					}
				}
				current.getNeighboor()[k].updateGH();
				openList.push(current.getNeighboor()[k]);	
			}
		}
		closeList.insert(current);
			
	}
	return false
}


Sudoku AStar::compare(Sudoku a, Sudoku b){ //TODO verif
	if(a.getG()+a.getH() <= b.getG()+b.getH()) {
		return a;
	} else {
		return b;
	}
}


/*Sudoku AStar::FindLowestScore(){//TODO vérif
	Sudoku tmp=openList[0];
	int test=tmp.getG() + tmp.getH();
	for(int i=1; i<openList.size(); i++){
		if(openList[i].getG()+openList.getH()<test){
			tmp = openList[i];
			test = tmp.getG()+tmp.getH();
		}
	}
	return tmp:
}*/
void AStar::CreateNeighboor(Sudoku parent){//TODO
	set<Sudoku> list;
	Sudoku tmp;
	
	// on cherche une case vide (sens de lecture habituel)
	int i=0, j=0;
	while(parent.grid[i,j].getValue()!=0){
		if(i!=8){i++}
		else{
		if(j!=8){i=0; j++}
		}
	}
	
		
		
	// pour toutes les valeurs encore disponibles
	for(int k = 0; k<parent.grid[i][j].getRemaining().size()){
		//Créer nouveau sudoku
		tmp = Sudoku(parent);
		tmp.setValue(i,j,parent.getRemaining()[k]);
		//Vérifier les doublons
		if(!tmp.checkDouble()){
			//Mettre à jour les tableaux de cases voisines
			tmp.ComputeArcConsistency();
			//Ajout à la liste des voisins
			list.insert(tmp);
		}
	}
	parent.setNeighboor(list);
}
};
