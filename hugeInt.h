#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>
using namespace std;
class HugeInt
{
	friend istream & operator >> (istream &, HugeInt &);
	friend ostream & operator << (ostream &,const HugeInt &);

	public:
	HugeInt(int = 0);
	HugeInt(string);
	const HugeInt & operator = (const HugeInt &);
	HugeInt & operator + (const HugeInt &);
	HugeInt & operator - (const HugeInt &);
	int bits[32];
};

#endif // HUGEINT_H

