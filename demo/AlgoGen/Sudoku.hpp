#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <vector>

#include "Genome.hpp"
#include "Cell.hpp"

using namespace std;

class Sudoku : public Genome{
    private:
        //Param
        vector<vector<Cell>> grid;
        int sqrtTaille;
        int taille;

        //Methodes
        int scoreLigne(int i); //DONE
        int scoreCol(int i); //DONE

    public:
        //Constructeurs
        Sudoku(); //DONE
        Sudoku(Sudoku* sudoku); //DONE
        Sudoku(Sudoku* sudoku, bool copyGuess); //DONE

        //Getter
        int getValue(int x, int y);//DONE
        Cell getCell(int x, int y);//DONE

        //Setter
        void setValue(int x, int y, int val);//DONE

        //Methodes
        int getTaille(); //DONE
        int getSqrtTaille(); //DONE
        void remplir(); //DONE
        int scoreLignes(int i); //DONE
        int scoreCols(int i); //DONE

        //Override
        void afficher(); //DONE
        Genome* mutate(); //DONE
        double fitness(); //DONE
        pair<Genome*, Genome*> croisement(Genome* genome); //DONE
};
#endif
