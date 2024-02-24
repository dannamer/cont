test:
	gcc -c *.cpp ./test_list/*.cpp -lgtest -lstdc++ -lm -lgtest_main -pthread && gcc *.o -o test_exe -lgtest -lstdc++ -lm -lgtest_main -pthread
	./test_exe


clean:
	rm -rf *.o test_exe 
