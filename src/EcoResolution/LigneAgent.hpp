#ifndef LIGNEAGENT_HPP
#define LIGNEAGENT_HPP

#include <vector>
#include "EcoAgent.hpp"
#include "Sudoku.hpp"

using namespace std;

class LigneAgent : public EcoAgent{
    private:
        int numero;
        Sudoku* sudoku;
    public:
        int getNumero();
        Sudoku* getSudoku();
        void setNumero(int n);
        void setSudoku(Sudoku* s);
        LigneAgent(Sudoku* s, int n);
        LigneAgent();
        vector<EcoAgent*> trouverGeneur();
        void faireSatisfaction();
        void agresser(EcoAgent* e);
        EcoAgent* trouverPlacePourFuir(EcoAgent* e);
        void faireFuite(EcoAgent* e); 
};
#endif
