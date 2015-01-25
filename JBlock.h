#ifndef __JBLOCK_H__
#define __JBLOCK_H__

#include <iostream>
#include "block.h"

class JBlock : public Block {
public:
    JBlock(int ID);
    bool canGenerate();
    void generate();
    void rotateCW();
    void rotateCCW();
};
#endif
