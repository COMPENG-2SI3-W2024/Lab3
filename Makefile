CC=g++
CFLAGS=-I. -lm -g -std=c++11
DEPS = *.h
OBJ = objPos.o objPosStack.o DLinkedList.o cmdQueue.o Test.o  
OBJTBC = objPos.o objPosDLinkedList.o objPosStack.o DLinkedList.o cmdQueue.o Test.o  

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Lab3: $(OBJ)
	$(CC) -o $@ ${OBJTBC} $(CFLAGS)

test:	testLab3
testLab3:
	./run.sh

.PHONY: clean

clean:
	$(RM) ${OBJ} *.exe *.xml Lab3
