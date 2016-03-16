#include "EcoResoluteur.hpp"

vector<EcoAgent*> EcoResoluteur::getEcoAgents(){//DONE
    return ecoAgents;
}
        
void EcoResoluteur::setEcoAgents(vector<EcoAgent*> eco){//DONE
    ecoAgents=eco;
}


void EcoResoluteur::ajouterEcoAgent(EcoAgent* eco){//DONE
    ecoAgents.push_back(eco);

}

void EcoResoluteur::resolution(){
    while (!estFini()) {
        EcoAgent* e=choixEcoAgent();
        e->essayerSatisfaire();    
    }
}
