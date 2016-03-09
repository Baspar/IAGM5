#include "Sudokus.hpp"

Sudokus::Sudokus(int k){//DONE
    tailleGen=k;
    for(int i=0; i<tailleGen; i++){
        Sudoku sud;
        sud.remplir();
        insert(sud);
    }
}
Sudokus::Sudokus(const Sudokus& oldGen){//DONE
    tailleGen = oldGen.getTailleGen()*2;
    for(int i=0; i<tailleGen; i+=2){
        Sudoku indiv1 = oldGen.getIndividu(i);
        Sudoku indiv2 = oldGen.getIndividu(i+1);
        pair<Sudoku, Sudoku> children = indiv1*indiv2;
        insert(children.first);
        insert(children.second);
    }
}
int Sudokus::getTailleGen()const{//DONE
    return tailleGen;
}
void Sudokus::selection(){//TODO
}
void Sudokus::shuffle(){//TODO
}
void Sudokus::insert(Sudoku sud){//DONE
    int fitness = sud.fitness();
    vector<Sudoku>::iterator it = generation.begin();
    while(it < generation.end()){
        if(it->fitness() >= fitness){
            generation.insert(it, sud);
            break;
        }
        it++;
    }
    if(it==generation.end())
        generation.insert(it, sud);
}
Sudoku Sudokus::getIndividu(int i) const{//DONE
    return generation[i];
}
