#include "EcoResoluteur.hpp"
#include <iostream>

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
   // cout << "test"<< endl;
    while (!estFini()) {
     //   cout << "test" << endl;
        EcoAgent* e=choixEcoAgent();
     //   cout << "test" << e << endl;
        e->essayerSatisfaire(); 
     //   cout << "test" << endl;   
    }
}
