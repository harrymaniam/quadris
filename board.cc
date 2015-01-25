#include <iostream>
#include "board.h"
#include "cell.h"
using namespace std;

Board *Board::instance = 0; // first thing, define static member, starts at NULL
Board *Board::getInstance() {
    if (!instance) { // if instance hasnt been created, then create it
        instance = new Board;
    }
    return instance;
}


Cell ***Board::grid;

Board::Board(){
  this->gridWidth = 10; 
  this->gridHeight = 18;
  grid=new Cell**[18];
  for(int row=0;row<18;row++){
    grid[row]= new Cell*[10];
    for(int col=0;col<10;col++){
      grid[row][col]=new Cell;
    }
  } 
}

Board::~Board(){
  for(int i = 0; i < 18; i++)
    {
      for(int j = 0; j < 10; j++)
        {
          delete grid[i][j];
        }
    }

  for(int i = 0; i < 18; i++)
    {
      delete [] grid[i];
    }

  delete [] grid;
}

bool Board::isRowFull(int rowNum){
    for (int i=0; i<gridWidth; ++i){
        if (grid[rowNum][i]->isEmpty()){ // or check if its occupied?
            return false;
        }
    }
    return true;
}

int Board::clearFullRows(){
    int numRowsCleared=0;
    for (int row=0; row<gridHeight; ++row){
        if (isRowFull(row)){
            for (int col=0; col<gridWidth; ++col){
                grid[row][col]->clearCell();
            }
            for (int i=row; i>0; i--){ // moves each row down by one.
                for (int col=0; col<gridWidth; ++col){
                    char sym = grid[i-1][col]->getSymbol();
                    int ID = grid[i-1][col]->getID();
                    grid[i][col]->setCell(sym, ID);
                }
            }
            numRowsCleared++;
        }
    }
    //int score = (level + numRowsCleared) * (level + numRowsCleared);
    return numRowsCleared;
}


void Board::clear(){
    for (int row=0; row<18; ++row){
        for (int col=0; col<10; ++col){
            grid[row][col]->clearCell();
        }
    }
}



Cell ***Board::returnGrid(){
    return grid;
}


