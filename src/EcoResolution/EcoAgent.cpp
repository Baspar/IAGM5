#include "EcoAgent.hpp"
#include <iostream>

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
    //cout << "test1" << endl;
    if(etat!=Etat::SATISFACTION){
        //cout << "test2" << endl;
        vector<EcoAgent*> geneur=trouverGeneur();
            //cout << "test3" << endl;
        while(geneur.size()!=0){
            //cout << "test4" << endl;
            for(int i=0; i<geneur.size(); i++){
                //cout << "test5" << endl;
                agresser(geneur[i]);
                //cout << "test6" << endl;
            }
        }
        faireSatisfaction();
    }
 }


 void EcoAgent::fuir(EcoAgent* e){//WIP
    //cout << "testFuir2" << endl;
    if(etat==Etat::SATISFACTION)
        etat=Etat::RECHERCHE_FUITE;
    //cout << "testFuir3"<< endl;
    EcoAgent* f=trouverPlacePourFuir(e);
    //cout << "testFuir4"<< endl;
    if(f==NULL)
        cout << "pas de place pour fuire" << endl;
    else {
        //MANQUE PEUT ETRE UNE BOUCLE
        faireFuite(f);
    }
    //cout << "testFuir5"<< endl;
 }



