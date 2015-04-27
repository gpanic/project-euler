#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <ostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <fstream>

class BigInt
{
public:
	BigInt(const std::string &Num);
	~BigInt();
public:
	const short BucketSize = 18;
	std::vector<unsigned long long> Buckets;
	
	std::string ToString();

	BigInt operator+(const BigInt &Other);
	BigInt operator=(const BigInt &Other);
	BigInt operator+=(BigInt &Other);
};

std::ostream & operator<<(std::ostream &Stream, BigInt &Object);

