#ifndef LIGNEAGENT_HPP
#define LIGNEAGENT_HPP

class LigneAgent;

#include "EcoAgent.hpp"
#include "Sudoku.hpp"
#include "Cell.hpp"
#include <vector>

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
        LigneAgent(int n);
        LigneAgent();
        vector<EcoAgent*> trouverGeneur();
        void faireSatisfaction();
        void agresser(EcoAgent* e, EcoAgent* c);
        EcoAgent* trouverPlacePourFuir(EcoAgent* e, EcoAgent* c);
        void faireFuite(EcoAgent* e);
        int nombreOccurence(int number, int place);
};
#endif
