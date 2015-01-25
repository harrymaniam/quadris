#include <iostream>
#include "block.h"
using namespace std;

Block::Block(){}


char Block::getSymbol(){
    return this->symbol;
}

bool Block::canRotate(int *arr){
    for (int i=0; i<8; i+=2){
        if(!(board->grid[arr[i]][arr[i+1]]->isEmpty())){
            return false;
        }
        //consider extreme right hand corner.
    }
    return true;
}

void Block::left(){
    bool canShift=true;
    int rowInd,colInd,leftID;
    for (int i=0; i<8; i+=2){
        rowInd=i;
        colInd=i+1;
        if ((posArr[colInd]-1 <0)){
            canShift=false;
            break;
        } else {
            leftID = board->grid[posArr[rowInd]][posArr[colInd]-1]->getID();
            if ((board->grid[posArr[rowInd]][posArr[colInd]-1]->isOccupied()) && (leftID != ID)) {
                canShift=false; //can't shift left if the cell on the left of current cell is not empty, or if the cell on the left of the current cell is outside the left border of the grid.
                break;
            }
        }
    }
    if (canShift){
        for (int i=0; i<8; i+=2){
            rowInd=i;
            colInd=i+1;
            board->grid[posArr[rowInd]][posArr[colInd]]->clearCell(); // clears the current cell: sets the symbol to default '_', sets ID to default ID 0.
        }
        for (int i=0; i<8; i+=2){
            rowInd=i;
            colInd=i+1;
            board->grid[posArr[rowInd]][posArr[colInd]-1]->setCell(symbol, ID); // sets the symbol and ID of the cell to the right of the current cell to the symbol and ID of the current cell.
            posArr[colInd]--;
        }
    }
    
}

void Block::right(){
    bool canShift=true;
    int rowInd,colInd, rightID;
    for (int i=0; i<8; i+=2){
        rowInd = i;
        colInd = i+1;
        if ((posArr[colInd]+1 >= 10)){
            canShift=false;
            break;
        } else {
            rightID = board->grid[posArr[rowInd]][posArr[colInd]+1]->getID();
            if ((board->grid[posArr[rowInd]][posArr[colInd]+1]->isOccupied()) && (rightID != ID)){
                canShift=false; //can't shift right if the cell on the right of current cell is not empty, or if the cell on the right of the current cell is outside the right border of the grid.
                break;
            }
        }
    }
    if (canShift){
        for (int i=0; i<8; i+=2){
            rowInd=i;
            colInd=i+1;
            board->grid[posArr[rowInd]][posArr[colInd]]->clearCell(); // clears the current cell: sets the symbol to default '_', sets ID to default ID 0.
        }
        for (int i=0; i<8; i+=2){
            cout << "shifting right" << endl;
            rowInd=i;
            colInd=i+1;
            board->grid[posArr[rowInd]][posArr[colInd]+1]->setCell(symbol, ID); // sets the symbol and ID of the cell to the right of the current cell to the symbol and ID of the current cell.
            posArr[colInd]++;
        }
    }
        
}

void Block::down(){
    bool canShift=true;
    int rowInd,colInd, downID;
    for (int i=0; i<8; i+=2){
        rowInd=i;
        colInd=i+1;
        if (posArr[rowInd]+1 >=18){
            canShift = false;
            break;
        } else {
            downID = board->grid[posArr[rowInd]+1][posArr[colInd]]->getID();
            if ((board->grid[posArr[rowInd]+1][posArr[colInd]]->isOccupied()) && (downID != ID)){

            canShift = false;
            break;
            }
        }
    }
    if (canShift){
        for (int i=0; i<8; i+=2){
            rowInd=i;
            colInd=i+1;
            board->grid[posArr[rowInd]][posArr[colInd]]->clearCell(); // clears the current cell: sets the symbol to default '_', sets ID to default ID 0.
        }
        for (int i=0; i<8; i+=2){
          //  cout << "down for loop" << endl;
            rowInd=i;
            colInd=i+1;
            board->grid[posArr[rowInd]+1][posArr[colInd]]->setCell(symbol, ID); // sets the symbol and ID of the cell below the current cell to the symbol and ID of the current cell.
           // cout << posArr[rowInd]+1 << " " << posArr[colInd] << endl;
            posArr[rowInd]++;
        }
    }
}


