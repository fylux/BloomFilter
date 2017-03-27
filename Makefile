a.exe: main.o
	g++ -o a.exe main.o -lstdc++ -std=c++11

main.o : main.cpp BloomFilter.hpp
	g++ -c main.cpp -lstdc++ -std=c++11

run: a.exe
	a.exe
