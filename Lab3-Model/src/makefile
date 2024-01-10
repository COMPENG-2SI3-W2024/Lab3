CC = g++
CFLAGS = -I. -I../inc -g
OBJTBC = objPos.o objPosArrayList.o objPosStack.o DLinkedList.o cmdQueue.o GameMechs.o MacUILib.o Player.o ItemBin.o ScreenDrawer.o MainGame.o 
OBJ = objPos.o objPosArrayList.o ../obj/objPosDLinkedList.o objPosStack.o DLinkedList.o cmdQueue.o GameMechs.o MacUILib.o Player.o ItemBin.o ScreenDrawer.o MainGame.o  
DEPS = *.h
#POSTLINKER = -lncurses   ## uncomment this if on Linux
EXEC = Project

%.o: %.cpp $(DEPENDS)
	$(CC) -c -o $@ $< $(CFLAGS)

${EXEC} : $(OBJTBC)
	$(CC) -o $@ ${OBJ} $(CFLAGS) ${POSTLINKER}

clean :
	rm -rf ${OBJTBC} ${EXEC} ${EXEC}.exe

