CC=g++
CFLAGS=-I. -lm -g
DEPS = *.h
OBJ = objPos.o objPosDLinkedList.o objPosStack.o DLinkedList.o cmdQueue.o Test.o  

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Lab3: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

test:	testLab3
testLab3:
	./run.sh

.PHONY: clean

clean:
	$(RM) *.o *.exe *.xml Lab3
