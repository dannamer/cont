test: clean
	gcc --coverage set_test.cpp -o test1 -lgtest -lstdc++ -lm
	gcc --coverage map_test.cpp -o test2 -lgtest -lstdc++ -lm
	./test1
	./test2
	# make clean
	# ~/.local/bin/gcovr -r . --exclude-throw-branches --html --html-details -o test.html
	# xdg-open test.html

valgrind: test
	valgrind --leak-check=full ./test1
	valgrind --leak-check=full ./test2
clean:
	rm -rf *gcno *gcna test* *html


