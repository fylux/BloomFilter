#ifndef __BLOOM_FILTER__
#define __BLOOM_FILTER__
#include <vector>
#include <cmath>
#include <functional>


template<class T>
class BloomFilter {
	private:
		std::vector<bool> array;
		unsigned int size;
		unsigned int nElements;
		unsigned int hashFunction1(T s);
		unsigned int hashFunction2(T s);
	public:
		BloomFilter(unsigned int size);
		~BloomFilter();
		unsigned int getSize();
		float getFalseRate();
		bool contains(T value);
		void insert(T value);
		void resize(unsigned int size);
		void clear(unsigned int size);

		//It would be nice to have a function to resize the filter to obtain the falseRate that we want
		//unsigned int getFalseRate(float rate); 
};
#endif