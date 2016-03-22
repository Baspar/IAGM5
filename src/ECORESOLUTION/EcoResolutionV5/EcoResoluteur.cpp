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
        EcoAgent* e=choixEcoAgent();
        e->essayerSatisfaire();
        cout << endl<< "=============================================" << endl << endl;
        string c;
        cin >> c;
    }
    cout << "FINIIIIIIII" << endl;
}
