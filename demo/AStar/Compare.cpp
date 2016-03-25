#include "Compare.hpp"

bool Compare::operator()(Node* a, Node* b){

if(true){
	if(a->getG() <= b->getG()){
	if(a->getG()+a->getH() > b->getG()+b->getH()){
	        return true;
         } else {
                return false;
          }
        }
        return false;
} else {
      return(a->getG()+a->getH() > b->getG()+b->getH());
        //Il y a pas une deuxième condition pour trier les distance, genre quand le g est egal tu renvois le plus petit h ? S
}
}

