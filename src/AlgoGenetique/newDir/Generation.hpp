#ifndef GENERATION_HPP
#define GENERATION_HPP

#include <vector>

#include "Genome.hpp"

class Generation{
    private:
        vector<Genome*> generation;
        int nombreGenerations;
        double tauxCroisement;
        double tauxMutation;

    public:
        virtual void evoluer()=0;
        virtual void selection()=0;

        double getTauxCroisement();
        double getTauxMutation();
        double bestFitness();
        double avgFitness();
        double worstFitness();
        Genome* getIndividu(int i);
};
#endif
