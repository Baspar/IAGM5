#ifndef ECOAGENT_HPP
#define ECOAGENT_HPP

#include <vector>
#include "Etat.hpp"

using namespace std;

class EcoAgent{
    private:
        vector<EcoAgent> but;
        Etat etat;
        bool agresse;
        bool gene;
    public:
        bool getAgresse();
        bool getGene();
        Etat getEtat;
        vector<EcoAgent> getBut();
        void setAgresse(bool b);
        void setGene(bool b);
        void setEtat(Etat e);
        void setbut(vector<EcoAgent> v);
        void essayerSatisfaire();
        vector<EcoAgent> trouverGeneur();
        void faireSatisfaction();
        void agresser(EcoAgent e);
        void fuir(EcoAgent e);
        EcoAgent trouverPlacePourFuir();
        void faireFuite(EcoAgent e);
};
#endif
