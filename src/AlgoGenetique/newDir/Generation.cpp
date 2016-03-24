#include "Generation.hpp"

int Generation::getTailleGeneration() const{
    return tailleGeneration;
}
double Generation::bestFitness() const{
    double max = -1;
    for(Genome* gen : generation)
        if(gen->fitness() > max)
            max = gen->fitness();
    return max;
}
double Generation::avgFitness() const{
    double tot = 0;
    for(Genome* gen : generation)
        tot += gen->fitness();
    return tot/generation.size();
}
double Generation::worstFitness() const{
    double min = -1;
    for(Genome* gen : generation)
        if(gen->fitness() > min || min == -1)
            min = gen->fitness();
    return min;
}
Genome* Generation::getConstIndividu(int i)const{
    return generation[i];
}
Genome* Generation::getIndividu(int i){
    return generation[i];
}
double Generation::getTauxCroisement() const{
    return tauxCroisement;
}
double Generation::getTauxMutation() const{
    return tauxMutation;
}
int Generation::getNombreGenerations(){
    return nombreGenerations;
}
//Generation::~Generation(){
//}
