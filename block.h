#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <iostream>
#include "cell.h"
#include "board.h"

class Block {
protected:
    Board *board;
    int ID; // unique ID of every single block.
    char symbol; // symbol of the Block, either I,J,L,O,S,Z, or T.
    int rotateState; // denoted by 0,1,2,3 to represent the 4 rotation states of a block.
    int posArr[8]; // in the array: even numbers and 0 are row positions, odd numbers are column positions. (e.g. posArr[0], posArr[1] is the position of the first cell of a block).
    //int level;//current level is need for when the block was spawned to calculate score
public:
    Block();
    virtual void generate()=0; // pure virtual generate function to generate different types of blocks.
    virtual bool canGenerate() = 0;
    //int getLevel(); // returns the current level. do we even need this? not in uml.
    bool canRotate(int *arr); // returns a boolean to determine whether the block can rotate.
    virtual void rotateCW() = 0; // pure virtual function to rotate clockwise.
    virtual void rotateCCW() = 0;// pure virtual function to rotate counter-clockwise.
    char getSymbol();
    void down(); // function that shifts the block down by one unit. Does nothing if the block cannot shift.
    void left(); // function that shifts the block left by one unit.Does nothing if the block cannot shift.
    void right(); // function that shifts the block right by one unit.Does nothing if the block cannot shift.
};


#endif

