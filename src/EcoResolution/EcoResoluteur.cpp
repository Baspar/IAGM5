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
        cout << "Choix" << endl;
        for(int i=0; i<9; i++)
            cout << "  Ligne #" << i << ": " << (ecoAgents[i]->getEtat()==Etat::SATISFACTION?"OK":"NOK") << endl;

        for(int i=9; i<18; i++)
            cout << "  Colon #" << (i-9) << ": " << (ecoAgents[i]->getEtat()==Etat::SATISFACTION?"OK":"NOK") << endl;

        EcoAgent* e=choixEcoAgent();
        cout << "Satisfaire" << endl;
        e->essayerSatisfaire();
        cout << endl<< "=============================================" << endl << endl;
        string c;
        cin >> c;
    }
    cout << "FINIIIIIIII" << endl;
}
