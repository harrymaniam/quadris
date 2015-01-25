#ifndef __GRAPHICDISPLAY_H__
#define __GRAPHICDISPLAY_H__
#include <iostream>
#include "window.h"
#include <string>
#include "cell.h"

class GraphicDisplay {
    int level;
    int score;
    int highscore;
    char CharGrid[18][10];
    char nextBlock;
    bool useGraphics;
    Xwindow *window1;//pointer to an xwindow object used for main game window
    std::string levelinfo;
    std::string scoreinfo;
    std::string hscoreinfo;
public:
    GraphicDisplay(bool useGraphics);
    ~GraphicDisplay();
    void setLevel(int n);
    void setScore(int s);
    void setHScore(int h);
    void setGrid(Cell ***grid); 
    void setNextBlock(char n);
    void printDisplay();//prints text based output to terminal window
    void displayGraphics();//updates Xwindow object(s) if graphics is enabled
};


#endif

