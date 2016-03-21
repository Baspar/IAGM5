#include "Generation.hpp"

double Generation::bestFitness(){
    double max = -1;
    for(Genome* gen : generation)
        if(gen->fitness() > max)
            max = gen->fitness();
    return max;
}
double Generation::avgFitness(){
    double tot = 0;
    for(Genome* gen : generation)
        tot += gen->fitness();
    return tot/generation.size();
}
double Generation::worstFitness(){
    double min = -1;
    for(Genome* gen : generation)
        if(gen->fitness() > min || min == -1)
            min = gen->fitness();
    return min;
}
Genome* Generation::getIndividu(int i){
    return generation[i];
}
double Generation::getTauxCroisement(){
    return tauxCroisement;
}
double Generation::getTauxMutation(){
    return tauxMutation;
}
