CC = gcc
CFLAG = -Wall -Wextra -Werror
TESTFLAG = -lgtest -lstdc++ -lm -lgtest_main -pthread

SRC = ./
DIR_LIST = $(src)test_list/
DIR_QUEUE = $(src)test_queue/

SOURCE = $(DIR_LIST)*.cpp $(DIR_QUEUE)*.cpp *.cpp
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