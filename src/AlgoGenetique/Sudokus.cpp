#include "Sudokus.hpp"

#include "CellType.hpp"

Sudokus::Sudokus(int k, int tc, int tm){//DONE
    tailleGen=k;
    tauxCroisement=tc;
    tauxMutation=tm;
    for(int i=0; i<tailleGen; i++){
        Sudoku sud(tm);
        sud.remplir();
        insert(sud);
    }
}
Sudokus::Sudokus(const Sudokus& oldGen){//DONE
    tauxMutation=oldGen.getTauxMutation();
    tauxCroisement=oldGen.getTauxCroisement();
    tailleGen = oldGen.getTailleGen();
    for(int i=0; i<tailleGen/2-1; i++){
        Sudoku indiv1 = oldGen.getIndividu(i);
        Sudoku indiv2 = oldGen.getIndividu(i+1);
        if(rand()%100<tauxCroisement){
            pair<Sudoku, Sudoku> children = indiv1*indiv2;
            insert(children.first);
            insert(children.second);
        }else{
            insert(indiv1);
            insert(indiv2);
        }
    }

    Sudoku indiv1 = oldGen.getIndividu(0);
    Sudoku indiv2 = oldGen.getIndividu(tailleGen/2-1);
    pair<Sudoku, Sudoku> children = indiv1*indiv2;
    insert(children.first);
    insert(children.second);
}
int Sudokus::getTauxMutation()const{//DONE
    return tauxMutation;
}
int Sudokus::getTauxCroisement()const{//DONE
    return tauxCroisement;
}
int Sudokus::getTrueTailleGen()const{//DONE
    return generation.size();
}
int Sudokus::getTailleGen()const{//DONE
    return tailleGen;
}
void Sudokus::selection(){//DONE
    for(int i=0; i<tailleGen/2; i++)
        generation.erase(generation.begin());
}
void Sudokus::shuffle(){//DONE
    random_shuffle(generation.begin(), generation.end());
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
int Sudokus::bestFitness()const{//DONE
    return (generation.end()-1)->fitness();
}
int Sudokus::worstFitness()const{//DONE
    return generation.begin()->fitness();
}
double Sudokus::avgFitness()const{//DONE
    double out=0;
    for(Sudoku sud : generation)
        out += sud.fitness();
    return out/tailleGen;
}
void Sudokus::mutate(){//DONE
    for(Sudoku sud : generation)
        sud.mutate();
}
