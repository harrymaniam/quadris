#include <iostream>
#include "JBlock.h"
using namespace std;

void JBlock::generate(){
    rotateState=0;
    board->grid[3][0]->setCell('J', this->ID);
    board->grid[4][0]->setCell('J', this->ID);
    board->grid[4][1]->setCell('J', this->ID);
    board->grid[4][2]->setCell('J', this->ID);
    int tempArr[8] = {4,0,3,0,4,1,4,2};
    for (int i=0; i<8; ++i){
        posArr[i]=tempArr[i];
    }
}

bool JBlock::canGenerate(){
    bool b1,b2,b3,b4;
    b1 = board->grid[3][0]->isEmpty();
    b2 = board->grid[4][0]->isEmpty();
    b3 = board->grid[4][1]->isEmpty();
    b4 = board->grid[4][2]->isEmpty();
    if (b1 && b2 && b3 && b4){
        return true;
    } else {
        return false;
    }
}

JBlock::JBlock(int ID){
    board=Board::getInstance();
    this->ID = ID;
    this->symbol = 'J';
}

void JBlock::rotateCW(){
    int fixedRow, fixedCol;
    fixedRow=posArr[0];
    fixedCol=posArr[1];
    if (rotateState == 0){
       int tempArr[8] = {fixedRow-2,fixedCol, fixedRow-2,fixedCol+1};
        if (canRotate(tempArr)){
            board->grid[fixedRow][fixedCol+1]->clearCell();
            board->grid[fixedRow][fixedCol+2]->clearCell();
            board->grid[fixedRow-2][fixedCol]->setCell('J', this->ID);
            board->grid[fixedRow-2][fixedCol+1]->setCell('J', this->ID);
            int tempArr[8]={fixedRow,fixedCol,fixedRow-1,fixedCol,fixedRow-2,fixedCol,fixedRow-2,fixedCol+1};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState++;
        }
    } else if (rotateState == 1){
        int tempArr[8] = {fixedRow-1,fixedCol+1,fixedRow-1,fixedCol+2,fixedRow,fixedCol+2};
        if (canRotate(tempArr)){
            board->grid[fixedRow][fixedCol]->clearCell();
            board->grid[fixedRow-2][fixedCol]->clearCell();
            board->grid[fixedRow-2][fixedCol+1]->clearCell();
            board->grid[fixedRow-1][fixedCol+1]->setCell('J', this->ID);
            board->grid[fixedRow-1][fixedCol+2]->setCell('J', this->ID);
            board->grid[fixedRow][fixedCol+2]->setCell('J', this->ID);
            int tempArr[8]={fixedRow-1,fixedCol, fixedRow-1,fixedCol+1,fixedRow-1,fixedCol+2,fixedRow,fixedCol+2};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState++;
        }
    } else if (rotateState == 2){
        fixedRow++;
        int tempArr[8] = {fixedRow,fixedCol,fixedRow,fixedCol+1,fixedRow-2,fixedCol+1};
        if (canRotate(tempArr)){
            board->grid[fixedRow-1][fixedCol]->clearCell();
            board->grid[fixedRow-1][fixedCol+2]->clearCell();
            board->grid[fixedRow][fixedCol+2]->clearCell();
            board->grid[fixedRow][fixedCol]->setCell('J', this->ID);
            board->grid[fixedRow][fixedCol+1]->setCell('J', this->ID);
            board->grid[fixedRow-2][fixedCol+1]->setCell('J', this->ID);
            int tempArr[8]={fixedRow,fixedCol,fixedRow,fixedCol+1,fixedRow-1,fixedCol+1,fixedRow-2,fixedCol+1};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState++;
        }
    } else {
        int tempArr[8] = {fixedRow-1,fixedCol,fixedRow,fixedCol+2};
        if (canRotate(tempArr)){
            board->grid[fixedRow-2][fixedCol+1]->clearCell();
            board->grid[fixedRow-1][fixedCol+1]->clearCell();
            board->grid[fixedRow-1][fixedCol]->setCell('J', this->ID);
            board->grid[fixedRow][fixedCol+2]->setCell('J', this->ID);
            int tempArr[8]={fixedRow,fixedCol,fixedRow-1,fixedCol,fixedRow,fixedCol+1,fixedRow,fixedCol+2};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState=0;
        }
    }
}

void JBlock::rotateCCW(){
    int fixedRow, fixedCol;
    fixedRow=posArr[0];
    fixedCol=posArr[1];
    if (rotateState == 0){
        int tempArr[8] = {fixedRow-1,fixedCol+1,fixedRow-2,fixedCol+1};
        if (canRotate(tempArr)){
            board->grid[fixedRow-1][fixedCol]->clearCell();
            board->grid[fixedRow][fixedCol+2]->clearCell();
            board->grid[fixedRow-1][fixedCol+1]->setCell('J', this->ID);
            board->grid[fixedRow-2][fixedCol+1]->setCell('J', this->ID);
            int tempArr[8]={fixedRow,fixedCol,fixedRow,fixedCol+1,fixedRow-1,fixedCol+1,fixedRow-2,fixedCol+1};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState=3;
        }
    } else if (rotateState == 1){
        int tempArr[8] = {fixedRow,fixedCol+1,fixedRow,fixedCol+2};
        if (canRotate(tempArr)){
            board->grid[fixedRow-2][fixedCol]->clearCell();
            board->grid[fixedRow-2][fixedCol+1]->clearCell();
            board->grid[fixedRow][fixedCol+1]->setCell('J', this->ID);
            board->grid[fixedRow][fixedCol+2]->setCell('J', this->ID);
            int tempArr[8]={fixedRow,fixedCol,fixedRow-1,fixedCol,fixedRow,fixedCol+1,fixedRow,fixedCol+2};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState--;
        }
    } else if (rotateState == 2){
        fixedRow++;
        int tempArr[8] = {fixedRow-2,fixedCol, fixedRow-2,fixedCol+1,fixedRow,fixedCol};
        if (canRotate(tempArr)){
            board->grid[fixedRow-1][fixedCol+1]->clearCell();
            board->grid[fixedRow-1][fixedCol+2]->clearCell();
            board->grid[fixedRow][fixedCol+2]->clearCell();
            board->grid[fixedRow][fixedCol]->setCell('J', this->ID);
            board->grid[fixedRow-2][fixedCol]->setCell('J', this->ID);
            board->grid[fixedRow-2][fixedCol+1]->setCell('J', this->ID);
            int tempArr[8]={fixedRow,fixedCol,fixedRow-1,fixedCol,fixedRow-2,fixedCol,fixedRow-2,fixedCol+1};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }            rotateState--;
        }
    } else {
        int tempArr[8] = {fixedRow-1,fixedCol,fixedRow-1,fixedCol+2,fixedRow,fixedCol+2};
        if (canRotate(tempArr)){
            board->grid[fixedRow][fixedCol]->clearCell();
            board->grid[fixedRow][fixedCol+1]->clearCell();
            board->grid[fixedRow-2][fixedCol+1]->clearCell();
            board->grid[fixedRow-1][fixedCol]->setCell('J', this->ID);
            board->grid[fixedRow-1][fixedCol+2]->setCell('J', this->ID);
            board->grid[fixedRow][fixedCol+2]->setCell('J', this->ID);
            int tempArr[8]={fixedRow-1,fixedCol, fixedRow-1,fixedCol+1,fixedRow-1,fixedCol+2,fixedRow,fixedCol+2};
            for (int i=0; i<8; ++i){
                posArr[i]=tempArr[i];
            }
            rotateState--;
        }
    }
}
