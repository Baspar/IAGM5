#include <iostream>
#include "Sudoku.hpp"
#include "Cell.hpp"

using namespace std;

int main(){
    Sudoku sud;
    sud.setValue(1, 1, 4);
    sud.setValue(7, 7, 5);

    set<int> vals;
    for(int i=0; i<9; i++){
        if(i%3==0){
            cout << "+";
            for(int j=0; j<9; j++){
                cout << "-";
                if(j%3==2)
                    cout << "+";
                else
                    cout << "-";
            }
            cout << endl;
        }
        cout << "|";
        for(int j=0; j<9; j++){
            vals=sud.getCell(i, j).getRemainingVal();
            cout << vals.size();
            if(j%3==2)
                cout << "|";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << "+";
    for(int j=0; j<9; j++){
        cout << "-";
        if(j%3==2)
            cout << "+";
        else
            cout << "-";
    }
    cout << endl;


}
