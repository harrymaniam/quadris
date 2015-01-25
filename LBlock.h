#ifndef __LBLOCK_H__
#define __LBLOCK_H__

#include <iostream>
#include "block.h"

class LBlock : public Block {
public:
    LBlock(int ID);
    bool canGenerate();
    void generate();
    void rotateCW();
    void rotateCCW();
};

#endif /* defined(____LBlock__) */
