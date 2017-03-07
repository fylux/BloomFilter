#include "BloomFilter.hpp"

template<class T>
BloomFilter<T>::BloomFilter(unsigned int size) {
	nElements = 0;
	array.reserve(size);
	array.assign(size,false);
	this->size = size;
}

template<class T>
BloomFilter<T>::~BloomFilter() {

}

template<class T>
unsigned int BloomFilter<T>::getSize(){
	return size;
}

template<class T>
float BloomFilter<T>::getFalseRate(){
	//k = 2; m = size; n = nElements;
	return std::pow(1-std::exp(-2 * ((float)nElements)/((float)size)),2);
}

template<class T>
bool BloomFilter<T>::contains(T value){
	return array[hashFunction1(value)] && array[hashFunction2(value)];
}

template<class T>
void BloomFilter<T>::insert(T value){
	array[hashFunction1(value)] = true;
	array[hashFunction2(value)] = true;
	nElements++;
}

//djb2
template<class T>
unsigned int BloomFilter<T>::hashFunction1(T value){
	unsigned long hash = 5381;
    for (auto c : value) {
        hash = (hash << 5) + hash + c; /* hash * 33 + c */
    }
    return hash % size;
}

//STL Hash
template<class T>
unsigned int BloomFilter<T>::hashFunction2(T value){
    return std::hash<T>{}(value) % size;
}

template<class T>
void BloomFilter<T>::resize(unsigned int size){
	array.reserve(size);
	array.assign(size,false);
	this->size = size;
}

template<class T>
void BloomFilter<T>::clear(unsigned int size){
	array.clear();
	nElements = 0;
}


//Add the types that you need
template class BloomFilter<std::string>;