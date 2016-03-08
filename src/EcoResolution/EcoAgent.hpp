#ifndef ECOAGENT_HPP
#define ECOAGENT_HPP

#include <vector>
#include "Etat.hpp"

using namespace std;

class EcoAgent{
    private:
        vector<EcoAgent*> but;
        Etat etat;
        bool agresse;
        bool gene;
    public:
        bool getAgresse();
        bool getGene();
        Etat getEtat();
        vector<EcoAgent*> getBut();
        void setAgresse(bool b);
        void setGene(bool b);
        void setEtat(Etat e);
        void setbut(vector<EcoAgent*> v);
        void essayerSatisfaire(); 
        virtual vector<EcoAgent*> trouverGeneur()=0; ///////REDEFINIE ligne
        virtual void faireSatisfaction()=0;   //////////REDEFINIE cellule
        virtual void agresser(EcoAgent* e)=0;    /////REDEFINIE ????????????
        void fuir(EcoAgent* e);      
        virtual EcoAgent* trouverPlacePourFuir()=0;         ////////////REDEFINIE cellule
        virtual void faireFuite(EcoAgent* e)=0;             ////////REFEINIE cellule
};
#endif
