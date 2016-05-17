#include "hugeInt.h"

HugeInt::HugeInt(int x)
{
	for(int i=0;i<32;i++)
	{
		bits[i] = x%10;
		x = x/10;
	}
}

HugeInt::HugeInt(string str)
{
	while(str.size() != 32)
		str = "0" + str;
	for(int i=0;i<32;i++)
		bits[i] = str[31-i] - '0';
}

const HugeInt & HugeInt::operator = (const HugeInt &rhs)
{
	if(&rhs != this)
		for(int i=0;i<32;i++)
			this->bits[i] = rhs.bits[i];
	return *this;
}

istream & operator >> (istream &in,HugeInt &rhs)
{
	string input;
	in>>input;
	HugeInt Str(input);
	rhs = Str;
	return in;
}

ostream & operator << (ostream &out,const HugeInt &rhs)
{
	for(int i=31;i>=0 && rhs.bits[i]!=0;i--)
		out<<rhs.bits[i];
	return out;
}

HugeInt & HugeInt::operator + (const HugeInt &rhs)
{
	HugeInt Sum;
	for(int i=0;i<32;i++)
	{
		Sum.bits[i] = bits[i] + rhs.bits[i];
		if(Sum.bits[i]>=10 && i < 31)
		{
			Sum.bits[i+1] = Sum.bits[i+1] + Sum.bits[i]/10;
			Sum.bits[i] = Sum.bits[i] % 10;
		}
	}

	return Sum;

}

HugeInt & HugeInt::operator - (const HugeInt &rhs)
{
	HugeInt Sub;
	for(int i=0;i<32;i++)
	{
		Sub.bits[i] = bits[i] - rhs.bits[i];
		if(Sub.bits[i] < 0 && i < 31)
		{
			Sub.bits[i] = Sub.bits[i] + 10;
			Sub.bits[i+1] = Sub.bits[i+1] - 1;
		}
	}

	return Sub;

}

