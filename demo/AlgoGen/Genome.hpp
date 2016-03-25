#ifndef GENOME_HPP
#define GENOME_HPP

#include <tuple>

using namespace std;

class Genome{
    public:
        virtual void afficher()=0;
        virtual Genome* mutate()=0;
        virtual double fitness()=0;
        virtual pair<Genome*, Genome*> croisement(Genome* genome)=0;
};
#endif
