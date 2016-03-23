#include "EcoAgent.hpp"
#include <iostream>

TypeEcoAgent EcoAgent::getType(){
    return type;
}

void EcoAgent::checkSatisfaction(){
    if(trouverGeneur().size() > 0)
        setEtat(Etat::RECHERCHE_SATISFACTION);
    else
        setEtat(Etat::SATISFACTION);
}

bool EcoAgent::getAgresse(){//DONE
    return agresse;
}

bool EcoAgent::getGene(){//DONE
    return gene;
}

Etat EcoAgent::getEtat(){//DONE
    return etat;
}

void EcoAgent::ajouterBut(EcoAgent* e){
    but.push_back(e);
}

vector<EcoAgent*> EcoAgent::getBut(){//DONE
    return but;
}

void EcoAgent::setAgresse(bool b){//DONE
    agresse=b;
}

void EcoAgent::setGene(bool b){//DONE
    gene=b;
}

void EcoAgent::setEtat(Etat e){//DONE
    etat=e;
}

void EcoAgent::setbut(vector<EcoAgent*> v){//DONE
    but=v;
}

void EcoAgent::essayerSatisfaire(){//WIP
    if(etat!=Etat::SATISFACTION){
        vector<EcoAgent*> geneur=trouverGeneur();
        while(geneur.size()!=0){
            int alea=rand() %(geneur.size());
            for(int i=0; i<geneur.size(); i++){
                agresser(geneur[i],this);
            }
            geneur=trouverGeneur();
        }
        faireSatisfaction();
    }
}


void EcoAgent::fuir(EcoAgent* e, EcoAgent* c){//WIP
    if(etat==Etat::SATISFACTION)
        etat=Etat::RECHERCHE_FUITE;
    EcoAgent* f=trouverPlacePourFuir(e,c);
    if(f==NULL)
        cout << "pas de place pour fuire" << endl;
    else {
        faireFuite(f);
        for(int i=0;i<f->getBut().size();i++)
            f->getBut()[i]->checkSatisfaction();
        f->checkSatisfaction();
        for(int i=0;i<this->getBut().size();i++)
            this->getBut()[i]->checkSatisfaction();
        this->checkSatisfaction();
    }

}


void EcoAgent::agresser(EcoAgent* e, EcoAgent* c){//WIP
    e->fuir(this, c);
}
