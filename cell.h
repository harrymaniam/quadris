#ifndef __CELL_H__
#define __CELL_H__

#include <iostream>

class Cell {
    int ID; // unique ID of block.
    char symbol; // symbol of the cell
public:
    Cell(); // Constructor
    void setCell(char newSymbol, int newID); // sets the cell to a new symbol and ID.
    char getSymbol(); // returns the symbol that occupies this cell.
    int getID(); // returns the unique block ID that occupies this cell.

    bool isEmpty(); // checks if the Cell is empty, which means if the cell symbol and ID is "_" and 0 respectively.
    bool isOccupied();
    void clearCell(); // clears the Cell, which sets the symbol and ID to default "_" and 0 respectively.
};


#endif
