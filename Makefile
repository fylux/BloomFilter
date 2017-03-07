a.exe: main.o BloomFilter.o
	gcc -o a.exe main.o BloomFilter.o -lstdc++ -std=c++11

main.o : main.cpp BloomFilter.hpp
	gcc -c main.cpp -lstdc++ -std=c++11

BloomFilter.o : BloomFilter.cpp BloomFilter.hpp
	gcc -c BloomFilter.cpp -lstdc++ -std=c++11

run: a.exe
	a.exe