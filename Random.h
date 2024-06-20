#pragma once
#include <iostream>
using namespace std;
class Random
{
	long long int max_, min_,guess_;
	short int tries_;
public:
	Random();
	Random(long long int max);
	Random(long long int min, long long int max);
	Random(long long int min, long long int max, short int tries);

	long long int get_guess() const;
	void set_guess(long long int g);
	void print() const;
};

