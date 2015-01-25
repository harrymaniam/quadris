#include <iostream>
#include "SBlock.h"
using namespace std;

void SBlock::generate(){
    rotateState=0;
    board->grid[3][1]->setCell('S', this->ID);
    board->grid[3][2]->setCell('S', this->ID);
    board->grid[4][0]->setCell('S', this->ID);
    board->grid[4][1]->setCell('S', this->ID);
    int tempArr[8] = {4,0,3,1,3,2,4,1};
    for (int i=0; i<8; ++i){
        posArr[i]=tempArr[i];
    }
}

bool SBlock::canGenerate(){
    bool b1,b2,b3,b4;
    b1 = board->grid[3][1]->isEmpty();
    b2 = board->grid[3][2]->isEmpty();
    b3 = board->grid[4][0]->isEmpty();
    b4 = board->grid[4][1]->isEmpty();
    if (b1 && b2 && b3 && b4){
        return true;
    } else {
        return false;
    }
}

SBlock::SBlock(int ID){
    board=Board::getInstance();
    this->ID = ID;
    this->symbol = 'S';
}

void SBlock::rotateCW(){
    int fixedRow, fixedCol;
    fixedRow=posArr[0];
    fixedCol=posArr[1];
    if ((rotateState == 0) || (rotateState == 2)){
        int tempArr[8]={fixedRow-1,fixedCol, fixedRow-2,fixedCol};
        if (canRotate(tempArr)){
            board->grid[fixedRow][fixedCol]->clearCell();
            board->grid[fixedRow-1][fixedCol+2]->clearCell();
            board->grid[fixedRow-1][fixedCol]->setCell('S', this->ID);
            board->grid[fixedRow-2][fixedCol]->setCell('S', this->ID);
            int tempArr[8]={fixedRow,fixedCol+1,fixedRow-1,fixedCol,fixedRow-1,fixedCol+1,fixedRow-2,fixedCol};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState++;
        }
    } else if ((rotateState == 1) || (rotateState == 3)){
        fixedCol--;
        int tempArr[8] = {fixedRow,fixedCol,fixedRow-1,fixedCol+2};
        if (canRotate(tempArr)){
            board->grid[fixedRow-2][fixedCol]->clearCell();
            board->grid[fixedRow-1][fixedCol]->clearCell();
            board->grid[fixedRow][fixedCol]->setCell('S', this->ID);
            board->grid[fixedRow-1][fixedCol+2]->setCell('S', this->ID);
            int tempArr[8]={fixedRow,fixedCol,fixedRow,fixedCol+2,fixedRow-1,fixedCol+1,fixedRow-1,fixedCol+2};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            if (rotateState == 3){
                rotateState = 0;
            } else {
                rotateState++;
            }
        }
    }
}

void SBlock::rotateCCW(){
    rotateCW();
}
