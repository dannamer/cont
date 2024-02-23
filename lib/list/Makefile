

test: clean
	gcc --coverage list_test.cpp -o test -lgtest -lstdc++ -lm
	./test
	# make clean
	~/.local/bin/gcovr -r . --html --html-details -o test.html
	xdg-open test.html
clean:
	rm -rf *gcno *gcna test* *html 