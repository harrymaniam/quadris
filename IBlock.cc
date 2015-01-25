#include <iostream>
#include "IBlock.h"
#include "board.h"
using namespace std;

void IBlock::generate(){
    //fixed cell
    board->grid[3][0]->setCell('I', this->ID);
    //cout<<"IBlock:generate: i Get here 2"<<endl;
    board->grid[3][1]->setCell('I', this->ID);
    board->grid[3][2]->setCell('I', this->ID);
    board->grid[3][3]->setCell('I', this->ID);
    rotateState=0;
    int tempArr[8]={3,0,3,1,3,2,3,3}; // first two coordinates are fixed
    for (int i=0; i<8; ++i){
        posArr[i]=tempArr[i];
    }
}

bool IBlock::canGenerate(){
    bool b1,b2,b3,b4;
    b1 = board->grid[3][0]->isEmpty();
    b2 = board->grid[3][1]->isEmpty();
    b3 = board->grid[3][2]->isEmpty();
    b4 = board->grid[3][3]->isEmpty();
    if (b1 && b2 && b3 && b4){
        return true;
    } else {
        return false;
    }
}

IBlock::IBlock(int ID){
    board=Board::getInstance();
    this->ID = ID;
    symbol='I';
}

void IBlock::rotateCW(){
    int rowInd,colInd;
    int fixedRow=posArr[0];
    int fixedCol=posArr[1];
    if (rotateState==0){
        // clears the symbols and ID's of cells:
        for (int i=2; i<8; i+=2){
            rowInd=i;
            colInd=i+1;
            board->grid[posArr[rowInd]][posArr[colInd]]->clearCell();
        }
        // changes the symbols and ID's of new cells;
        board->grid[fixedRow-1][fixedCol]->setCell('I', this->ID);
        board->grid[fixedRow-2][fixedCol]->setCell('I', this->ID);
        board->grid[fixedRow-3][fixedCol]->setCell('I', this->ID);
        int tempArr[8]={fixedRow,fixedCol,fixedRow-1,fixedCol,fixedRow-2,fixedCol,fixedRow-3,fixedCol};
        for (int i=0; i<8; ++i){
            posArr[i]=tempArr[i];
        }
        rotateState++;
    } else {
        for (int i=2; i<8; i+=2){
            rowInd=i;
            colInd=i+1;
            board->grid[posArr[rowInd]][posArr[colInd]]->clearCell();
        }
        board->grid[fixedRow][fixedCol+1]->setCell('I', this->ID);
        board->grid[fixedRow][fixedCol+2]->setCell('I', this->ID);
        board->grid[fixedRow][fixedCol+3]->setCell('I', this->ID);
        int tempArr[8]={fixedRow,fixedCol,fixedRow,fixedCol+1,fixedRow,fixedCol+2,fixedRow,fixedCol+3};
        for (int i=0; i<8; ++i){
            posArr[i]=tempArr[i];
        }
        rotateState--;
    }
}

void IBlock::rotateCCW(){
    rotateCW();
}
