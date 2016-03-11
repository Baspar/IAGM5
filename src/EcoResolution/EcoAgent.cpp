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
            for(int i=0; i<geneur.size(); i++){
                agresser(geneur[i]);
            }
        }
        faireSatisfaction();
    }
 }
 
 
 void EcoAgent::faireFuite(EcoAgent* e){//WIP
    if(etat==Etat::SATISFACTION)
        etat=Etat::RECHERCHE_FUITE;
    EcoAgent* f=trouverPlacePourFuir(e);  
    if(f==NULL)
        cout << "pas de place pour fuire" << endl;
    else {
        //MANQUE PEUT ETRE UNE BOUCLE
        faireFuite(f);
    }      
 }
 
 
 
