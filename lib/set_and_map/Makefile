test: clean
	gcc --coverage map_test.cpp -o test -lgtest -lstdc++ -lm
	./test
	# make clean
	# ~/.local/bin/gcovr -r . --exclude-throw-branches --html --html-details -o test.html
	# xdg-open test.html
clean:
	rm -rf *gcno *gcna test* *html 