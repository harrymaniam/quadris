#include <iostream>
#include "TBlock.h"
using namespace std;

void TBlock::generate(){
    rotateState=0;
    board->grid[3][0]->setCell('T', this->ID);
    board->grid[3][1]->setCell('T', this->ID);
    board->grid[3][2]->setCell('T', this->ID);
    board->grid[4][1]->setCell('T', this->ID);
    int tempArr[8] = {3,0,3,1,3,2,4,1};
    for (int i=0; i<8; ++i){
        posArr[i]=tempArr[i];
    }
}

bool TBlock::canGenerate(){
    bool b1,b2,b3,b4;
    b1 = board->grid[3][1]->isEmpty();
    b2 = board->grid[4][0]->isEmpty();
    b3 = board->grid[4][1]->isEmpty();
    b4 = board->grid[4][2]->isEmpty();
    if (b1 && b2 && b3 && b4){
        return true;
    } else {
        return false;
    }
}
TBlock::TBlock(int ID){
    board=Board::getInstance();
    this->ID = ID;
    this->symbol = 'T';
}

void TBlock::rotateCW(){
    int fixedRow, fixedCol;
    fixedRow=posArr[0];
    fixedCol=posArr[1];
    if (rotateState==0){
        ++fixedRow;
        int tempArr[8]={fixedRow-2,fixedCol+1};
        if (canRotate(tempArr)){
            board->grid[fixedRow-1][fixedCol+2]->clearCell();
            board->grid[fixedRow-2][fixedCol+1]->setCell('T', this->ID);
            int tempArr[8] = {fixedRow-1,fixedCol,fixedRow-1,fixedCol+1,fixedRow-2,fixedCol+1,fixedRow,fixedCol+1};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState++;
        }
    } else if (rotateState==1){
        ++fixedRow;
        int tempArr[8]={fixedRow,fixedCol,fixedRow,fixedCol+2};
        if (canRotate(tempArr)){
            board->grid[fixedRow-1][fixedCol]->clearCell();
            board->grid[fixedRow-2][fixedCol+1]->clearCell();
            board->grid[fixedRow][fixedCol]->setCell('T', this->ID);
            board->grid[fixedRow][fixedCol+2]->setCell('T', this->ID);
            int tempArr[8] = {fixedRow,fixedCol,fixedRow,fixedCol+1,fixedRow,fixedCol+2,fixedRow-1,fixedCol+1};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState++;
        }
    } else if (rotateState==2){
        int tempArr[8]={fixedRow-1,fixedCol,fixedRow-2,fixedCol};
        if (canRotate(tempArr)){
            board->grid[fixedRow][fixedCol+2]->clearCell();
            board->grid[fixedRow][fixedCol+1]->clearCell();
            board->grid[fixedRow-1][fixedCol]->setCell('T', this->ID);
            board->grid[fixedRow-2][fixedCol]->setCell('T', this->ID);;
            int tempArr[8] = {fixedRow,fixedCol,fixedRow-1,fixedCol,fixedRow-1,fixedCol+1,fixedRow-2,fixedCol};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState++;
        }
    } else {
        int tempArr[8]={fixedRow-1,fixedCol+2,fixedRow,fixedCol+1};
        if (canRotate(tempArr)){
            board->grid[fixedRow][fixedCol]->clearCell();
            board->grid[fixedRow-2][fixedCol]->clearCell();
            board->grid[fixedRow-1][fixedCol+2]->setCell('T', this->ID);
            board->grid[fixedRow][fixedCol+1]->setCell('T', this->ID);
            int tempArr[8] = {fixedRow-1,fixedCol,fixedRow-1,fixedCol+1,fixedRow-1,fixedCol+2,fixedRow,fixedCol+1};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState=0;
        }
    }
}

void TBlock::rotateCCW(){
    int fixedRow, fixedCol;
    fixedRow=posArr[0];
    fixedCol=posArr[1];
    if (rotateState==0){
        ++fixedRow;
        int tempArr[8]={fixedRow,fixedCol,fixedRow-2,fixedCol};
        if (canRotate(tempArr)){
            board->grid[fixedRow-1][fixedCol+2]->clearCell();
            board->grid[fixedRow][fixedCol+1]->clearCell();
            board->grid[fixedRow-2][fixedCol]->setCell('T', this->ID);
            board->grid[fixedRow][fixedCol]->setCell('T', this->ID);
            int tempArr[8] = {fixedRow,fixedCol,fixedRow-1,fixedCol,fixedRow-1,fixedCol+1,fixedRow-2,fixedCol};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState=3;
        }
    } else if (rotateState==1){
        fixedRow++;
        int tempArr[8]={fixedRow-1,fixedCol+2};
        if (canRotate(tempArr)){
            board->grid[fixedRow-2][fixedCol+1]->clearCell();
            board->grid[fixedRow-1][fixedCol+2]->setCell('T', this->ID);
            int tempArr[8] = {fixedRow-1,fixedCol,fixedRow-1,fixedCol+1,fixedRow-1,fixedCol+2,fixedRow,fixedCol+1};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState--;
        }
    } else if (rotateState==2){
        int tempArr[8]={fixedRow-1,fixedCol,fixedRow-2,fixedCol+1};
        if (canRotate(tempArr)){
            board->grid[fixedRow][fixedCol]->clearCell();
            board->grid[fixedRow][fixedCol+2]->clearCell();
            board->grid[fixedRow-1][fixedCol]->setCell('T', this->ID);
            board->grid[fixedRow-2][fixedCol+1]->setCell('T', this->ID);
            int tempArr[8] = {fixedRow-1,fixedCol,fixedRow-1,fixedCol+1,fixedRow-2,fixedCol+1,fixedRow,fixedCol+1};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState--;
        }
    } else {
        int tempArr[8]={fixedRow,fixedCol+1,fixedRow,fixedCol+2};
        if (canRotate(tempArr)){
            board->grid[fixedRow-1][fixedCol]->clearCell();
            board->grid[fixedRow-2][fixedCol]->clearCell();
            board->grid[fixedRow][fixedCol+1]->setCell('T', this->ID);
            board->grid[fixedRow][fixedCol+2]->setCell('T', this->ID);
            int tempArr[8] = {fixedRow,fixedCol,fixedRow,fixedCol+1,fixedRow,fixedCol+2,fixedRow-1,fixedCol+1};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState--;
        } 
    }
}
