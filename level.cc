#include <iostream>
#include "block.h"
#include "level.h"
#include <cstdlib>
#include "IBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "OBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "TBlock.h"
using namespace std;

void Level::setMaxLevel(){
    this->maxLevel=3;
}

void Level::setLevel(int level){
    this->level=level;
}

char Level::getBlockType(){
    int randNum=rand();
    char blockChar;
    if(level==0){
        int seqLen=sequence.length();//we need to get rid of whitespaces in sequence first do in main fn
        if(seqIndex==(seqLen-1)){
            seqIndex=0;
        }
        blockChar = sequence[seqIndex];
        seqIndex++;
    }
    else if(level==1){
        char arr1[]={'I','J','L','O','S','Z','T','I','J','L','O','T'}; // used to be: *arr1[]
        randNum=(randNum%12)+1;
        blockChar=arr1[randNum];
    }
    else if(level==2){
        char arr2[]={'I','J','L','O','S','Z','T'};
        randNum=(randNum%7)+1;
        blockChar=arr2[randNum];
    }
    else{
        char arr3[]={'I','J','L','O','S','Z','T','S','Z'};
        randNum=(randNum%9)+1;
        blockChar=arr3[randNum];
    }
    return blockChar;
}

Block * Level::genBlock(){
    numBlocks++;
    char blockType=getBlockType();
    Block *newBlock;
    if(blockType=='I'){newBlock = new IBlock(numBlocks); }
    else if(blockType=='J'){newBlock = new JBlock(numBlocks);}
    else if(blockType=='L'){newBlock = new LBlock(numBlocks);}
    else if(blockType=='O'){newBlock = new OBlock(numBlocks);}
    else if(blockType=='S'){newBlock = new SBlock(numBlocks);}
    else if(blockType=='Z'){newBlock = new ZBlock(numBlocks);}
    else if(blockType=='T'){newBlock = new TBlock(numBlocks);}
    numBlocks++;
    return newBlock;
}
Level::Level(int n,int seed,string sequence){
    srand(seed);
    level=n;
    this->sequence=sequence; //.?
}

void Level::levelUp(){
    if(level<maxLevel){
        level++;
    }
}
void Level::levelDown(){
    if(level>0){
        level--;
    }
}

