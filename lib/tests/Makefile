CC = gcc
CFLAG = -Wall -Wextra -Werror
CFLAGS_COVERAGE = -fprofile-arcs -ftest-coverage --coverage
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

OPEN_CMD = xdg-open
GCOVR = ~/.local/bin/gcovr

# you need to specify the source files
test: SOURCE += $(DIR_SET)*.cpp 
test: obj-file
	$(CC) $(OBJ-FILE) $(CFLAG) $(TESTFLAG) -o test_exe

run: test
	./test_exe

gr: CFLAG += $(CFLAGS_COVERAGE)
gr: clean run
	@mkdir -p OBJ_gcov
	$(GCOVR) -r  ../ --html-details -o ./OBJ_gcov/coverage_report.html
	make grp

grp:
	$(OPEN_CMD) ./OBJ_gcov/coverage_report.html

obj-file: $(SOURCE)
	$(CC) -c $(SOURCE) $(CFLAG) $(TESTFLAG) 
	


clean_gcov:
	rm -rf *.gcno *.gcda *.gcov coverage_report.html *.html *.css OBJ_gcov


clean: clean_gcov
	rm -rf *.o test_exe 
	clear