#ifndef __IBLOCK_H__
#define __IBLOCK_H__

#include <iostream>
#include "block.h"

class IBlock : public Block {
public:
    IBlock(int ID);
    void generate();
    bool canGenerate();
    void rotateCW();
    void rotateCCW();
};

#endif
