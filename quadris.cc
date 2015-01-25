#include <string>
#include "quadris.h"
#include "board.h"
#include "block.h"
#include "graphicdisplay.h"
#include "level.h"
#include <locale>
#include <sstream>
using namespace std;

Quadris::Quadris(int seed, int level, bool useGraphics, string sequence){
  this->board = new Board();
  this->currentLevel=level;
  this->levelPtr = new Level(level,seed,sequence);
  this->useGraphics=useGraphics; 
  display = new GraphicDisplay(useGraphics);
  currentBlock = levelPtr->genBlock();
  nextBlock = levelPtr->genBlock();
  currentBlock->generate();
  display->setGrid(board->returnGrid());
  score=0;
  hscore=0;
  currentBlock->generate();//adds the current block onto grid
  display->setLevel(level);
  display->setScore(0);
  display->setHScore(0);
  display->setNextBlock(nextBlock->getSymbol());//sends a char that reps the next block
  display->setGrid(board->returnGrid());//converst grid from cells to char and updated Display
  display->printDisplay();//updates text diplay as well as graphics if enabled
  read();
}

Quadris::~Quadris(){
  delete currentBlock;
  delete nextBlock;
  delete levelPtr;
  delete display;
}

void Quadris::restart(){
  levelPtr->setLevel(0);
  delete currentBlock;
  delete nextBlock;
  board->clear();//sets all cells to empty cell
  currentLevel=0;
  currentBlock = levelPtr->genBlock();
  currentBlock->generate();//adds the current block onto grid
  nextBlock = levelPtr->genBlock();
  score=0;
  display->setScore(0);
  display->setNextBlock(nextBlock->getSymbol());//sends a char that reps the next block
  display->setGrid(board->returnGrid());//converst grid from cells to char and updated Display
  display->setLevel(currentLevel);
  display->printDisplay();//updates text diplay as well as graphics if enabled    
}

int getMultiplier(string input){
    int strlen=input.length();
    int multi=0;
    int digits=0;//used to count how many digits the multiplier is ex "32right" would give digits==2
    char temp;
    for(int i=0; i<strlen;i++){//loops through string and gets multiplier
        temp=input[i];
        if(48<=temp && temp<=57){ //if character is a digit
            multi=multi*10+(temp-48);
            digits++;
        }
        else{  //when we reach a non integer input we stop
            break;
        }
    }
    if(digits==0){multi = 1;}
    return multi;
}

string getCommand(string input){//takes the input and determines which command it is
    string command;
    int strlen=input.length();
    char temp2;//used to append letters to find what command is
    for(int i=0; i<strlen; i++){
        char a = input[i];
        if (isdigit(a)){ // skips integers.
            continue;
        }         
        else {
            command += input[i];
            if(command=="lef") {return "left";}
            else if(command=="ri") {return "right";}
            else if(command=="do") {return "down"; }
            else if(command=="cl") {return "clockwise";}
            else if(command=="co") {return "counterclockwise";}
            else if(command=="dr") {return "drop";}
            else if(command=="levelu") {return "levelup";}
            else if(command=="leveld") {return "leveldown";}
            else if(command=="re") {return "restart";}
        }
    }
    return "invalid";
}


void Quadris::read(){
  int multi;//multiplier to support things such as 3right which is right right right
  string input;
  while(1){
    cin>>input;
    multi=getMultiplier(input);
    string command=getCommand(input); 
    if(cin.fail()){return;}
    else if(command=="invalid"){//when an invalid command is inputted
      cout<<"INVALID INPUT!!"<<endl<<"Did you even pass the ELPE?"<<endl;
    }
    else if(command=="restart"){//restart should not be multiplied
      restart();
    }
    else{//runs command the multi number of times
      while(multi>0){
        if(command=="left"){
         // cout << "i get here 1" << endl;
          currentBlock->left();
         // cout << "I get here 2" << endl;
        }else if(command=="right"){
          // cout << "in the right" << endl;
          currentBlock->right();
        } else if(command=="down"){
          currentBlock->down();
        } else if(command=="clockwise"){
          currentBlock->rotateCW();
        } else if (command == "counterclockwise"){
            currentBlock->rotateCCW();
        } else if(command=="drop"){//update score,set the new next block and current block
            for(int i=0;i<=15;i++){ 
              currentBlock->down();
            }
            int numRowsCleared = board->clearFullRows();
            if(numRowsCleared>0){
              score += ((currentLevel + numRowsCleared) * (currentLevel + numRowsCleared));
            }
            if(score>=hscore){
              hscore=score;
              display->setHScore(hscore);
            }
  	    display->setScore(score);
            display->setLevel(currentLevel);
            delete currentBlock;
            currentBlock=nextBlock;
            nextBlock=levelPtr->genBlock();
            display->setNextBlock(nextBlock->getSymbol());//sends a char that reps the next block
            if (currentBlock->canGenerate()){
              currentBlock->generate();//displays next block in top left corner
            }
            else{
              restart();
              break;   
            }//if top left block cannot generate we restart
        }  
        else if(command=="levelup"){
          levelPtr->levelUp();
          if(currentLevel<3){currentLevel++;}
          display->setLevel(currentLevel);
        }
        else if(command=="leveldown"){
          levelPtr->levelDown();
          if(currentLevel>0){currentLevel--;}
          display->setLevel(currentLevel);
        }
        display->setGrid(board->returnGrid());//converst grid from cells to char and updated Display
        display->printDisplay();
        multi--;
      }
    }
  }
}
















