CXX=g++
XXFLAGS=-Wall -MMD
EXEC=quadris
OBJECTS=main.o quadris.o graphicdisplay.o level.o board.o cell.o block.o IBlock.o JBlock.o LBlock.o SBlock.o ZBlock.o TBlock.o OBlock.o
DEPENDS=${OBJECTS:.o=.d}
${EXEC}: ${OBJECTS}
	g++ -L/usr/X11R6/lib *.cc -lX11 -o quadris
-include ${DEPENDS}
clean:
	rm ${OBJECTS} ${EXEC}
