#ifndef ECORESOLUTEUR_HPP
#define ECORESOLUTEUR_HPP

#include <vector>
#include "EcoAgent.hpp"

using namespace std;

class EcoResoluteur{
    protected:
        vector<EcoAgent*> ecoAgents;
    public:
        virtual bool estFini()=0;
        virtual EcoAgent* choixEcoAgent()=0;
        vector<EcoAgent*> getEcoAgents();
        void setEcoAgents(vector<EcoAgent*> eco);
        void ajouterEcoAgent(EcoAgent* eco);
        void resolution();
};
#endif
