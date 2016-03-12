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
    vector<Sudoku> newGen;

    int sizeTournament=3;

    while(newGen.size() != generation.size()){
        shuffle();
        vector<Sudoku> tournament;

        for(int i=0; i<sizeTournament; i++){
            int fitness = generation[i].fitness();
            vector<Sudoku>::iterator it = tournament.begin();
            while(it < tournament.end()){
                if(it->fitness() >= fitness){
                    tournament.insert(it, generation[i]);
                    break;
                }
                it++;
            }
            if(it==tournament.end())
                tournament.insert(it, generation[i]);
        }

        if(rand()%100 < tauxCroisement){
            pair<Sudoku, Sudoku> children = tournament[sizeTournament-1]*tournament[sizeTournament-2];
            int fitness = children.first.fitness();
            vector<Sudoku>::iterator it = newGen.begin();
            while(it < newGen.end()){
                if(it->fitness() >= fitness){
                    newGen.insert(it, children.first);
                    break;
                }
                it++;
            }
            if(it==newGen.end())
                newGen.insert(it, children.first);

            fitness = children.second.fitness();
            it = newGen.begin();
            while(it < newGen.end()){
                if(it->fitness() >= fitness){
                    newGen.insert(it, children.second);
                    break;
                }
                it++;
            }
            if(it==newGen.end())
                newGen.insert(it, children.second);
        }else{
            if(rand()%100 < tauxMutation)
                tournament[sizeTournament-1].mutate();

            int fitness = tournament[sizeTournament-1].fitness();
            vector<Sudoku>::iterator it = newGen.begin();
            while(it < newGen.end()){
                if(it->fitness() >= fitness){
                    newGen.insert(it, tournament[sizeTournament-1]);
                    break;
                }
                it++;
            }
            if(it==newGen.end())
                newGen.insert(it, tournament[sizeTournament-1]);
        }
    }

    generation.clear();
    for(Sudoku sud : newGen)
        insert(sud);
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
    for(vector<Sudoku>::iterator it=generation.begin(); it != generation.end(); it++)
        it->mutate();
}
