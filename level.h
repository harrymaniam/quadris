#ifndef __LEVEL_H__
#define __LEVEL_H__
#include "block.h"


class Level{
    int level;
    int maxLevel;//level 0,1,2,3
    int numBlocks;
    int seqIndex;
    std::string sequence;
    char getBlockType();//used to generate a char that corresponds to random block
public:
    Level(int n,int seed,std::string sequence);//where n is the level passed by command line
    Block *genBlock();
    void levelUp();
    void levelDown();
    void setLevel(int level);
    void setMaxLevel();
};

#endif
