#include <iostream>
#include "cell.h"
using namespace std;


Cell::Cell(){
  ID=0;  
  symbol=' ';
}


void Cell::setCell(char newSymbol, int newID){
    symbol = newSymbol;
    ID = newID;
}

char Cell::getSymbol(){
    return this->symbol;
}

int Cell::getID() {
    return this->ID;
}


bool Cell::isEmpty(){
    if ((symbol == ' ') && (ID == 0)){
        return true;
    } else {
        return false;
    }
}

bool Cell::isOccupied(){
    if ((symbol != ' ') && (ID>0)){
        return true;
    } else {
        return false;
    }
}


void Cell::clearCell(){
    symbol = ' ';
    ID = 0;
}
