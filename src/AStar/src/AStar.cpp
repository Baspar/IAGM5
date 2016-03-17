#include "AStar.hpp"

Sudoku AStar::developSudoku(Sudoku gridIni){//WIK
	gridIni.updateRemaining();
        std::priority_queue <Sudoku> openList;
//	set<Sudoku> searchList;
	openList.push(gridIni);
//	searchList.insert(gridIni);

	while(openList.empty()!=true){
		current = openList.top();
		openList.pop();
//		searchList.erase(current);

		if(current.checkComplete()){
			current.afficher();
			return current;
		} else {
			for(Sudoku n : CreateNeighboor(current)){
//				if(searchList.find(n)== searchList.end()){
					for(int i=0; i<9; i++){
						for(int j=0; j<9; j++) {
							if(n.grid[i][j]->getValue()==0){
								n.grid[i][j]->updateRemaining();
							}
						}
					}
					n.updateGH();
					openList.push(n);
//					searchList.insert(n);
//				}
			}
			closeList.insert(current);
		}
	}
	return gridIni;
}

set<Sudoku> AStar::CreateNeighboor(Sudoku p){//TODO

	set<Sudoku> list;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(p.getCell(i,j)->getValue()==0){
				p.getCell(i,j)->updateRemaining();
				for(int k : p.grid[i][j]->getRemaining()) {
					Sudoku tmp = Sudoku(p);
					tmp.setValue(i,j,k);
					if(!tmp.checkDouble()){
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



