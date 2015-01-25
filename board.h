#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include "graphicdisplay.h"
#include "cell.h"

class Board {
/*
    friend class Block;
    friend class IBlock;
    friend class JBlock;
    friend class SBlock;
    friend class ZBlock;
    friend class TBlock;
    friend class OBlock;
    friend class LBlock;

*/
public:
    static Cell ***grid;
    int gridHeight;
    int gridWidth;
    int level;
public:
    
    static Board *instance;
    static Board *getInstance();
    
    Board(); // generates a grid of dimensions of gridHeight and gridWidth.
    ~Board(); // destructor

    // Board getInstance(/*display?*/ int gridHeight, int gridWidth);
    
    bool isRowFull(int rowNum); // boolean function that checks if a row on the grid is full.
    int clearFullRows(); // clears full rows on the grid, moves blocks above down by 1 unit, and returns the number of rows cleared.

    // void printBoard();
    
    void clear(); // clears the entire grid, by setting every cell to the default symbol '_'.
    Cell ***returnGrid();
    //bool lost();
};



#endif
