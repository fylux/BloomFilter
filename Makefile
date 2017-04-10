a.out : main.o
	g++ -o a.out main.o -lstdc++ -std=c++11

main.o : main.cpp BloomFilter.hpp
	g++ -c main.cpp -lstdc++ -std=c++11

run : a.out
	./a.out
