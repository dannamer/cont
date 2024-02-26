CC = gcc
CFLAG = -Wall -Wextra -Werror
TESTFLAG = -lgtest -lstdc++ -lm -lgtest_main -pthread

SRC = ./
DIR_LIST = $(SRC)test_list/
DIR_QUEUE = $(SRC)test_queue/
DIR_STACK = $(SRC)test_stack/

SOURCE = $(DIR_LIST)*.cpp $(DIR_QUEUE)*.cpp $(DIR_STACK)*.cpp *.cpp
OBJ-FILE = *.o

test: obj-file
	$(CC) $(OBJ-FILE) $(CFLAG) $(TESTFLAG) -o test_exe

run: test
	./test_exe

obj-file: $(SOURCE)
	$(CC) -c $(SOURCE) $(CFLAG) $(TESTFLAG) 

clean:
	rm -rf *.o test_exe 
	clear