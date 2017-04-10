a.out : main.o
	g++ -o a.out main.o -std=c++11

main.o : main.cpp BloomFilter.hpp
	g++ -c main.cpp -std=c++11

run : a.out
	./a.out
