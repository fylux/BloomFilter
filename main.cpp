#include <iostream>
#include <string>
#include "BloomFilter.hpp"

#define SIZE 4

using namespace std;

int main(){
	BloomFilter<std::string> filter(SIZE);
	filter.insert("have");
	filter.insert("you");
	filter.insert("rain");

	//Those are for sure
	cout << "'have' can be in the set? : " << filter.contains("have") << endl;
	cout << "'you' can be in the set? : " << filter.contains("you") << endl;
	cout << "'rain' can be in the set? : " << filter.contains("rain") << endl << endl;

	//Those are not
	cout << "False positives probability: " << filter.getFalseRate() << endl;
	cout <<"'ever' can be in the set? : " << filter.contains("ever") << endl;
	cout <<"'seen' can be in the set? : " << filter.contains("seen") << endl << endl;

	//Let's resize to reduce false positives
	filter.resize(15);
	cout << "False positives probability: " << filter.getFalseRate() << endl;
	cout <<"'ever' can be in the set? : " << filter.contains("ever") << endl;
	cout <<"'seen' can be in the set? : " << filter.contains("seen") << endl;

	return 0;
}