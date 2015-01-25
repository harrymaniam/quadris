#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include <iostream>
#include "block.h"

class TBlock : public Block {
public:
    TBlock(int ID);
    void generate();
    bool canGenerate();
    void rotateCW();
    void rotateCCW();
};

#endif