#include <iostream>
#include "ZBlock.h"
using namespace std;

void ZBlock::generate(){
    rotateState=0;
    board->grid[3][0]->setCell('Z', this->ID);
    board->grid[3][1]->setCell('Z', this->ID);
    board->grid[4][1]->setCell('Z', this->ID);
    board->grid[4][2]->setCell('Z', this->ID);
    int tempArr[8] = {3,0,3,1,4,1,4,2};
    for (int i=0; i<8; ++i){
        posArr[i]=tempArr[i];
    }
}

bool ZBlock::canGenerate(){
    bool b1,b2,b3,b4;
    b1 = board->grid[3][0]->isEmpty();
    b2 = board->grid[3][1]->isEmpty();
    b3 = board->grid[4][1]->isEmpty();
    b4 = board->grid[4][2]->isEmpty();
    if (b1 && b2 && b3 && b4){
        return true;
    } else {
        return false;
    }
}
ZBlock::ZBlock(int ID){
    board=Board::getInstance();	
    this->ID = ID;
    this->symbol = 'Z';
}

void ZBlock::rotateCW(){
    int fixedRow, fixedCol;
    fixedRow=posArr[0];
    fixedCol=posArr[1];
    if ((rotateState==0)||(rotateState==2)){
        fixedRow++;
        int tempArr[8]={fixedRow,fixedCol,fixedRow-2,fixedCol+1};
        if (canRotate(tempArr)){
            board->grid[fixedRow][fixedCol+1]->clearCell();
            board->grid[fixedRow][fixedCol+2]->clearCell();
            board->grid[fixedRow][fixedCol]->setCell('Z', this->ID);
            board->grid[fixedRow-2][fixedCol+1]->setCell('Z', this->ID);
            int tempArr[8]={fixedRow,fixedCol,fixedRow-1,fixedCol,fixedRow-1,fixedCol+1,fixedRow-2,fixedCol+1};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState++;
        }
    } else{
        int tempArr[8]={fixedRow,fixedCol+1,fixedRow,fixedCol+2};
        if (canRotate(tempArr)){
            board->grid[fixedRow][fixedCol]->clearCell();
            board->grid[fixedRow-2][fixedCol+1]->clearCell();
            board->grid[fixedRow][fixedCol+1]->setCell('Z', this->ID);
            board->grid[fixedRow][fixedCol+2]->setCell('Z', this->ID);
            int tempArr[8]={fixedRow-1,fixedCol,fixedRow-1,fixedCol+1,fixedRow,fixedCol+1,fixedRow,fixedCol+2};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            if (rotateState==3){
                rotateState=0;
            } else {
                rotateState++;
            }
        }
    }
}

void ZBlock::rotateCCW(){
    rotateCW();
}

