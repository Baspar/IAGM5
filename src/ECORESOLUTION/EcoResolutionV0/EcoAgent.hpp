#ifndef ECOAGENT_HPP
#define ECOAGENT_HPP

#include <vector>
#include "Etat.hpp"

using namespace std;

class EcoAgent{
    protected:
        vector<EcoAgent*> but;
        Etat etat;
        bool agresse;
        bool gene;
    public:
        bool getAgresse();
        bool getGene();
        Etat getEtat();
        vector<EcoAgent*> getBut();
        void ajouterBut(EcoAgent* e);
        void setAgresse(bool b);
        void setGene(bool b);
        void setEtat(Etat e);
        void setbut(vector<EcoAgent*> v);
        void essayerSatisfaire();
        virtual vector<EcoAgent*> trouverGeneur()=0;
        virtual void faireSatisfaction()=0;
        void agresser(EcoAgent* e);
        void checkSatisfaction();
        void fuir(EcoAgent* e);
        virtual EcoAgent* trouverPlacePourFuir(EcoAgent* e)=0;
        virtual void faireFuite(EcoAgent* e)=0;
};
#endif
