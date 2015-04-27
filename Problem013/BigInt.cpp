#include "BigInt.h"

#include <iostream>

BigInt::BigInt(const std::string &Num)
{
	int BucketNum = Num.size() / BucketSize;
	if (Num.size() % BucketSize != 0)
		++BucketNum;
	Buckets.resize(BucketNum);
	std::fill(Buckets.begin(), Buckets.end(), 0);

	int Start = Num.size();
	int CopySize = BucketSize;
	int Index = 0;
	while (Start != 0)
	{
		if (Start - CopySize >= 0)
		{
			Start -= CopySize;
		}
		else
		{
			CopySize = Start;
			Start = 0;
		}
		Buckets[Index] = std::stoll(Num.substr(Start, CopySize));
		++Index;
	}
}

BigInt::~BigInt()
{
}

std::string BigInt::ToString()
{
	std::stringstream ss;
	for (int i = Buckets.size() - 1; i >= 0; --i)
	{
		if (i < Buckets.size() - 1)
			ss << std::setw(BucketSize) << std::setfill('0');
		ss << Buckets[i];
	}
	return ss.str();
}

BigInt BigInt::operator+(const BigInt &Other)
{
	return *this;
}

BigInt BigInt::operator=(const BigInt &Other)
{
	return *this;
}

BigInt BigInt::operator+=(BigInt &Other)
{
	bool ThisBigger = this->Buckets.size() >= Other.Buckets.size();
	BigInt *Bigger = ThisBigger ? this : &Other;
	BigInt *Smaller = ThisBigger ? &Other : this;

	for (int i = 0; i < Bigger->Buckets.size(); ++i)
	{
		if (i < Smaller->Buckets.size())
			Bigger->Buckets[i] += Smaller->Buckets[i];
		if (Bigger->Buckets[i] >= static_cast<int>(std::pow(BucketSize + 1, 10)))
		{
			if (Bigger->Buckets.size() - 1 == i)
			{
				Bigger->Buckets.push_back(0);
			}
			Bigger->Buckets[i + i] += 1;
			Bigger->Buckets[i] -= static_cast<int>(std::pow(BucketSize + 1, 10));
		}
	}
	return *Bigger;
}

std::ostream & operator<<(std::ostream &Stream, BigInt &Object)
{
	return Stream << Object.ToString();
}