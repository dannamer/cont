test: clean
	gcc  --coverage -I. ./tests/main.cpp lib/*.cpp -o test -lgtest -lstdc++ -lm
	./test
	~/.local/bin/gcovr -r . --html --html-details -o test.html
	xdg-open test.html