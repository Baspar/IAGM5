#include "AStar.hpp"
Sudoku AStar::developSudoku(Sudoku gridIni){//WIK
        std::priority_queue <Sudoku> openList;
	set<Sudoku> searchList;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(gridIni.getCell(i,j).getValue()==0) gridIni.getCell(i,j).updateRemaining();
		}
	}
	openList.push(gridIni);
	searchList.insert(gridIni);
	while(openList.empty()!=true){
//cout << "open          ";
//cout << openList.size();
//cout << endl;
//cout << "close         ";
//cout << closeList.size();
//cout << endl;
		current = openList.top();
		openList.pop();
		if(current.checkComplete()){
			return current;
		} else {
			for(Sudoku n : CreateNeighboor(current)){
				if(searchList.find(n)== searchList.end()){
					for(int i=0; i<9; i++){
						for(int j=0; j<9; j++) {
							if(n.grid[i][j].getValue()==0){
								n.grid[i][j].updateRemaining();
							}
						}
					}
					n.updateGH();
					openList.push(n);
					searchList.insert(n);
				}
			}
			closeList.insert(current);
//cout << "close         ";
//cout << closeList.size();
//cout << endl;


		}
	}
	return gridIni;
}

set<Sudoku> AStar::CreateNeighboor(Sudoku p){//TODO
	set<Sudoku> list;
	Sudoku tmp;
	// on parcourt les cases vides
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(p.grid[i][j].getValue()==0){
				p.grid[i][j].updateRemaining();
			// pour toutes les valeurs encore disponibles
				for(int k : p.grid[i][j].getRemaining()) {


//				for(int k = 0; k<parent.grid[i][j].getRemaining().size(); k++){
					//Créer nouveau sudoku
					tmp = Sudoku(p);
					tmp.setValue(i,j,k);
					if(!tmp.checkDouble()   ){
						list.insert(tmp);
					}
				}
			}
		}
	}
	p.setNeighboor(list);
//	p.enfants = set<Sudoku>(list);
	return list;
}



