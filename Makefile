a.exe: main.o
	gcc -o a.exe main.o -lstdc++ -std=c++11

main.o : main.cpp BloomFilter.hpp
	gcc -c main.cpp -lstdc++ -std=c++11

run: a.exe
	a.exe