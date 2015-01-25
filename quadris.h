#ifndef __QUADRIS_H__
#define __QUADRIS_H__
#include <string>
#include "board.h"
#include "block.h"
#include "graphicdisplay.h"
#include "level.h"

class Quadris {
        int hscore;
        int score;
        int currentLevel;
        bool useGraphics;//graphics enabled by default
        Board *board;
        Block *currentBlock;
        Block *nextBlock;
        Level *levelPtr;
        GraphicDisplay *display;//contains both graphics and text option
        std::string scriptFile;
        void restart();
        void read(); //gets arguments from user and process it accordingly
    public:
        Quadris(int seed, int level, bool useGraphics, std::string sequence);
        ~Quadris();
};

#endif
