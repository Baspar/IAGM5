#include "AStarV0.hpp"

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
							if(n.getCell(i,j)->getNumber().getValue()==0){
								n.getCell(i,j)->updateRemaining();
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
				for(int k : p.getCell(i,j)->getRemaining()) {
					Sudoku tmp = Sudoku(p);
					tmp.setValue(i,j,k);
				if(!tmp.checkDouble()){
					bool test = true;
				for(Cell* cell : tmp.getCell(i,j)->getAdjacentCells()){
						if(cell->getNumber().getValue() == 0 ){
							cell->updateRemaining();
							if(cell->getRemaining().size()==0){
								test = false;
							}
						}
					}
					tmp.updateGH();
//					if(test){
						list.insert(tmp);
//					}
					
				}
			}
		}
	}
	}
	p.setNeighboor(list);
//	p.enfants = set<Sudoku>(list);
	return list;

}






void AStar::test(Sudoku s) {



Cell c = Cell(s.getCell(3,0));
Cell* p = &c;
p->setValue(1);

cout << "c ";
cout << p->getValue();
cout << endl;


Sudoku t = Sudoku(s);
t.setValue(3,0,1);
t.afficher();

for(int i=0;i<9;i++){
for(int j=0;j<9;j++){

if(t.getCell(i,j)->getValue()==0){
cout << i;
cout << j;
cout <<"       ";
cout << t.getCell(i,j)->getNumber().getValue();
cout <<  "       ";
cout << t.getCell(i,j)->getAdjacentCells().size();
cout << endl;

}
}
}

}
