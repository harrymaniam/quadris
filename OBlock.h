#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include <iostream>
#include "block.h"

class OBlock : public Block {
public:
    OBlock(int ID);
    void generate();
    bool canGenerate();
    void rotateCW();
    void rotateCCW();
};

#endif
