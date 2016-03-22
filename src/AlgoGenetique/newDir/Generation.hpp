#ifndef GENERATION_HPP
#define GENERATION_HPP

#include <vector>

#include "Genome.hpp"

class Generation{
    protected:
        vector<Genome*> generation;
        int nombreGenerations;
        double tauxCroisement;
        double tauxMutation;
        int tailleGeneration;

    public:
        virtual void evoluer()=0;
        virtual void selection()=0;

        double getTauxCroisement() const;
        double getTauxMutation() const;
        int getTailleGeneration() const;
        double bestFitness() const;
        double avgFitness() const;
        double worstFitness() const;
        Genome* getIndividu(int i);
        Genome* getConstIndividu(int i)const;
};
#endif
