#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "quadris.h"

using namespace std;

int main(int args, char *argv[]){ 
   int seed=6900;
   int level=0;
   bool useGraphics=true;
   string scriptFile="sequence.txt";
   int i=0;
   while(i != args){
        string input = argv[i];
        if (input == "-text"){
            useGraphics = false;
        } else if (input == "-seed"){
            stringstream ss(argv[i+1]);
            if(ss >> seed){
                ++i;
            } else {
                seed=6900; //default seed
            }
        } else if (input == "-scriptfile"){
            string txt = argv[i+1];
            if (txt[0] == '-'){
                scriptFile = "sequence.txt";
            } else {
                ++i;
                scriptFile = argv[i];
            }
            
        } else if (input == "-startlevel"){
            stringstream ss(argv[i+1]);
            if (ss >> level){
                ++i;
            } else {
                level = 0; // default level
            }
        }
        ++i;
    }
    string sequence = "";
    ifstream file(scriptFile.c_str());
    if (file.fail()){
        ifstream file("sequence.txt");
    }
    string s;
    while (file >> s){
        //cout<<s<<endl;
        sequence =sequence+s;
    }
    Quadris(seed, level, useGraphics, sequence);

}
