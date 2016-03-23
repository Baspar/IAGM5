#ifndef SUDOKU_HPP
#define SUDOKU_HPP

class Sudoku;

#include "Cell.hpp"
#include "EcoAgent.hpp"
#include "EcoResoluteur.hpp"
#include <fstream>
#include <iostream>
#include <vector>


using namespace std;

class Sudoku: public EcoResoluteur{
    private:
        int taille;
        vector<vector<Cell*>> grid;
        int scoreLigne(int i);
        int scoreCol(int i);
    public:
        Sudoku();
        Sudoku(const Sudoku& sudoku);
        void setValue(int x, int y, int val);
        int getValue(int x, int y) const;
        Cell* getCell(int x, int y);
        void remplir();
        void afficher();
        void afficher(int xAtt, int yAtt, int xAgr, int yAgr);
        bool estFini();
        EcoAgent* choixEcoAgent();
        int scoreLignes(int i);
        int scoreCols(int i);
        int fitness();
        int getTaille();
};
#endif
