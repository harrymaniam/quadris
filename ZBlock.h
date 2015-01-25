#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__
#include <iostream>
#include "block.h"

class ZBlock : public Block {
public:
    ZBlock(int ID);
    bool canGenerate();
    void generate();
    void rotateCW();
    void rotateCCW();
};

#endif