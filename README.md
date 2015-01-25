# quadris
Created by Harry Sivasubramaniam and Jimmy Guo

Quadris is a non-real-time version of Tetris developed in C++. 
It is made to be played in the command line but also supports graphical display using XWindows

<h1>Compiling and Running this Project</h1>
1) You must be on a linux based operating system with X11 library and a C++ compiler installed (I used g++)
2) Navigate to the main directory on the terminal "/quadris" and run the "make" command to compile the project
3) To play the game, run "./quadris" on the terminal

Gameplay is done via the terminal
The player must input the below commands to control the peices and toggle game settings
1) "left" moves peice 1 unit left
2) "right" moves peice 1 unit right
3) "down" moves peice 1 unit down
4) "clockwise" rotates peice clockwise
5) "counterclockwise" rotates peice counterclockwise
6) "drop" moves peice to the very bottom
7) "levelup" increases the level which makes more difficult combinations of tetraminoes appear
8) "leveldown" decreases current level
9) "restart" resets score and level to 0 and initializes a new board

To make the game more simpler for the player, the first few letters that correspond to a unique command may be inputted
ex. you may enter "lef" instead of "left" however you may not input "le" as there is also "levelup".
Also, you may shove on multiplier onto the front of a command.
ex. you can input "5ri" to move the peice 5 units right

Command-line Interface
The following command may be inputted when running quadris on the terminal to modify gameplay
1) "-text" allows the game to be run in text-only mode
2) "-seed ###" allows you to set the seed for the psuedo random number generator(PRNG) used to generate the next peice
3) "-scriptfile xxx" allows you to load a sequence of peices from a text file rather than using random peice generation
4) "-startlevel n" allows you to set the start level before playing rather than using the "levelup" command during the game
ex. on the terminal run "./quadris -text -seed 314159" to play text only mode and also set the PRNG's seed to 314159
