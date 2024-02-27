CC = gcc
CFLAG = -Wall -Wextra -Werror
TESTFLAG = -lgtest -lstdc++ -lm -lgtest_main -pthread

SRC = ./
DIR_LIST = $(SRC)test_list/
DIR_QUEUE = $(SRC)test_queue/
DIR_STACK = $(SRC)test_stack/
DIR_VECTOR = $(SRC)test_vector/
DIR_SET = $(SRC)test_set/
DIR_MAP = $(SRC)test_map/
SOURCE = *.cpp
# SOURCE = $(DIR_MAP)*.cpp $(DIR_LIST)*.cpp $(DIR_QUEUE)*.cpp $(DIR_STACK)*.cpp $(DIR_VECTOR)*.cpp $(DIR_SET)*.cpp *.cpp
OBJ-FILE = *.o

test: SOURCE += $(DIR_SET)*.cpp 
test: obj-file
	$(CC) $(OBJ-FILE) $(CFLAG) $(TESTFLAG) -o test_exe

run: test
	./test_exe

obj-file: $(SOURCE)
	$(CC) -c $(SOURCE) $(CFLAG) $(TESTFLAG) 

clean:
	rm -rf *.o test_exe 
	clear