#include "graphicdisplay.h"
#include <iostream>
#include "window.h"
#include <string>
#include "board.h"
#include "cell.h"
#include <sstream>
using namespace std;
GraphicDisplay::GraphicDisplay(bool useGraphics){
  score=0;
  highscore=0;
  this->useGraphics=useGraphics;
  if(useGraphics){
    window1 = new Xwindow(250,500); 
  }  
}

GraphicDisplay::~GraphicDisplay(){
  //deletes Xwindow object
  delete window1;
}

void GraphicDisplay::setLevel(int n){
    level=n;
}
void GraphicDisplay::setScore(int s){
    score=s;
}
void GraphicDisplay::setHScore(int h){
    highscore=h;
}
void GraphicDisplay::setNextBlock(char n){
    nextBlock=n;
}
void GraphicDisplay::setGrid(Cell ***grid){ //removed const and 1 *
    for(int row=0;row<18;row++){
        for(int col=0;col<10;col++){
             CharGrid[row][col]=grid[row][col]->getSymbol();//copys all the characters from cells to char grid
        }
    }
}
void GraphicDisplay::printDisplay(){
    cout<<"Level:      "<<level<<endl;
    cout<<"Score:      "<<score<<endl;
    cout<<"High Score: "<<highscore<<endl;
    cout<<"__________"<<endl;
    for(int row=0;row<18;row++){
        for(int col=0;col<10;col++){
            cout<<CharGrid[row][col];//prints the character for each cell
        }
        cout<<endl;//prints a new line for each row
    }
    cout<<"__________"<<endl;
    if(nextBlock=='I'){
        cout<<"    "<<endl;
        cout<<"IIII"<<endl;
    }
    else if(nextBlock=='J'){
        cout<<"JJJ"<<endl;
        cout<<"  J"<<endl;
    }
    else if(nextBlock=='L'){
        cout<<"  L"<<endl;
        cout<<"LLL"<<endl;
    }
    else if(nextBlock=='O'){
        cout<<"OO"<<endl;
        cout<<"OO"<<endl;
    }
    else if(nextBlock=='S'){
        cout<<" SS"<<endl;
        cout<<"SS"<<endl;
    }
    else if(nextBlock=='Z'){
        cout<<"ZZ "<<endl;
        cout<<" ZZ"<<endl;
    }
    else if(nextBlock=='T'){
        cout<<"TTT"<<endl;
        cout<<" T "<<endl;
    }
  if(useGraphics){displayGraphics();}
}

void GraphicDisplay::displayGraphics(){
  //sets the boards background to cyan colour
  window1->fillRectangle(0, 0, 250, 500, Xwindow::Cyan);
  //set the board grid colour to while
  window1->fillRectangle(25, 100, 200, 360, Xwindow::White);
  //resets the strings value each time a piece is dropped
  window1->drawString(25, 25,levelinfo, Xwindow::Cyan);
  window1->drawString(25, 50,scoreinfo, Xwindow::Cyan);
  window1->drawString(25, 75,hscoreinfo, Xwindow::Cyan);

  //sets level for graphic window
  string levelinfo;
  stringstream ss1;
  ss1<<level;
  string temp1;
  ss1>>temp1;
  levelinfo="Level:   "+temp1;
  //sets score for graphic window
  string scoreinfo;
  stringstream ss2;
  ss2<<score;
  string temp2;
  ss2>>temp2;
  scoreinfo="Score:   "+temp2;
  //sets highscore for graphic window
  string hscoreinfo;
  stringstream ss3;
  ss3<<highscore;
  string temp3;
  ss3>>temp3;
  hscoreinfo="High Score:   "+temp3;
  
  //prints various info to graphics window
  window1->drawString(25, 25,levelinfo, Xwindow::Blue);
  window1->drawString(25, 50,scoreinfo, Xwindow::Blue);
  window1->drawString(25, 75,hscoreinfo, Xwindow::Blue);
  window1->drawString(150,25,"Next Block:",Xwindow::Blue);
  

  int b11,b12,b13,b21,b22,b23,b24;//where bij is the i,j coordinates of a default block
  //prints the next block
  if(nextBlock=='I'){b11=5;b12=5;b13=5;b21=1;b22=1;b23=1;b24=1;}
  else if(nextBlock=='J'){b11=2;b12=5;b13=5;b21=2;b22=2;b23=2;b24=5;}
  else if(nextBlock=='L'){b11=5;b12=5;b13=3;b21=3;b22=3;b23=3;b24=5;}
  else if(nextBlock=='O'){b11=4;b12=4;b13=5;b21=4;b22=4;b23=5;b24=5;}
  else if(nextBlock=='S'){b11=5;b12=6;b13=6;b21=6;b22=6;b23=5;b24=5;} 
  else if(nextBlock=='Z'){b11=7;b12=7;b13=5;b21=5;b22=7;b23=7;b24=5;}
  else if(nextBlock=='T'){b11=8;b12=8;b13=8;b21=5;b22=8;b23=5;b24=5;}
  else {b11=5;b12=5;b13=5;b21=5;b22=5;b23=5;b24=5;}
  window1->fillRectangle(140, 50, 20, 20, b11);
  window1->fillRectangle(160, 50, 20, 20, b12);
  window1->fillRectangle(180, 50, 20, 20, b13);
  window1->fillRectangle(140, 70, 20, 20, b21);
  window1->fillRectangle(160, 70, 20, 20, b22);
  window1->fillRectangle(180, 70, 20, 20, b23);
  window1->fillRectangle(200, 70, 20, 20, b24);

  int i=0; //where i represents a colour see window.h for more info
  //prints the grid out
  for(int row=0; row<18; row++) {
    for(int col=0; col<10; col++) {
      if(CharGrid[row][col]=='I'){i=1;} 
      else if(CharGrid[row][col]=='J'){i=2;}
      else if(CharGrid[row][col]=='L'){i=3;}
      else if(CharGrid[row][col]=='O'){i=4;}
      else if(CharGrid[row][col]=='S'){i=6;}
      else if(CharGrid[row][col]=='Z'){i=7;}
      else if(CharGrid[row][col]=='T'){i=8;}
      else if(CharGrid[row][col]==' '){i=0;}
      window1->fillRectangle(25+(col*20),100+(row*20) , 20, 20, i);
    }
  }
}
