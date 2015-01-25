#include <iostream>
#include "OBlock.h"
using namespace std;

void OBlock::generate(){
    board->grid[3][0]->setCell('O', this->ID);
    board->grid[3][1]->setCell('O', this->ID);
    board->grid[4][0]->setCell('O', this->ID);
    board->grid[4][1]->setCell('O', this->ID);
    rotateState=0;
    int tempArr[8]={3,0,3,1,4,0,4,1};
    for (int i=0; i<8; ++i){
        posArr[i]=tempArr[i];
    }
}

bool OBlock::canGenerate(){
    bool b1,b2,b3,b4;
    b1 = board->grid[3][0]->isEmpty();
    b2 = board->grid[3][1]->isEmpty();
    b3 = board->grid[4][0]->isEmpty();
    b4 = board->grid[4][1]->isEmpty();
    if (b1 && b2 && b3 && b4){
        return true;
    } else {
        return false;
    }
}

OBlock::OBlock(int ID){
    board=Board::getInstance();
    this->ID = ID;
    this->symbol = 'O';
}

void OBlock::rotateCW(){}

void OBlock::rotateCCW(){}
