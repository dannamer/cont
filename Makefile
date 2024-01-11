CC = gcc
CFLAGS = -std=c++17 -Wall -Werror -Wextra -Ilib/stack/ -Ilib/queue/ -Ilib/ContainerBase/

SRCS := $(wildcard tests/*.cpp)
OBJS := $(patsubst tests/%.cpp,OBJ/%.o,$(SRCS))
OBJ_DIR = OBJ
all: s21_matrix_oop.a

s21_matrix_oop.a: $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: tests/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clang:
	clang-format -i *.cpp *.h
	clang-format -n *.cpp *.h

test: clean
	gcc  --coverage -Ilib/stack/ -Ilib/queue/ -Ilib/ContainerBase/ tests/*.cpp -o test -lgtest -lstdc++ -lm
	./test
	~/.local/bin/gcovr -r . --html --html-details -o test.html
	xdg-open test.html
clean:
	rm -rf $(OBJ_DIR) *.a test *.gcda *gcno *css *html

valgrind: clean
	gcc  --coverage -I. ./tests/main.cpp lib/*.cpp -o test -lgtest -lstdc++ -lm
	valgrind --leak-check=full ./test
