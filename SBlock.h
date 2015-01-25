#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include <iostream>
#include "block.h"

class SBlock : public Block {
public:
    SBlock(int ID);
    bool canGenerate();
    void generate();
    void rotateCW();
    void rotateCCW();
};

#endif