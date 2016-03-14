#ifndef COLONNEAGENT_HPP
#define COLONNEAGENT_HPP

class ColonneAgent;

#include "EcoAgent.hpp"
#include "Sudoku.hpp"
#include "Cell.hpp"
#include <vector>

using namespace std;

class ColonneAgent : public EcoAgent{
    private:
        int numero;
        Sudoku* sudoku;
    public:
        int getNumero();
        Sudoku* getSudoku();
        void setNumero(int n);
        void setSudoku(Sudoku* s);
        ColonneAgent(Sudoku* s, int n);
        ColonneAgent();
        vector<EcoAgent*> trouverGeneur();
        void faireSatisfaction();
        void agresser(EcoAgent* e);
        EcoAgent* trouverPlacePourFuir(EcoAgent* e);
        void faireFuite(EcoAgent* e); 
};
#endif
