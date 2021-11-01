#pragma once
#include<iostream>
class RationalNum
{
private:
	long long m_numerator;
	long long m_denominator;
	static long long gcd(long long a, long long b);
	void simlify();
public:
	RationalNum();
	RationalNum(long long numerator, long long denominator);
	long long get_numerator();
	long long get_denominator();
	friend bool operator==(const RationalNum& left, const RationalNum& right);
	friend bool operator!=(const RationalNum& left, const RationalNum& right);
	friend RationalNum operator+(const RationalNum& left, const RationalNum& right);
	/*friend RationalNum operator-(const RationalNum& left, const RationalNum& right);
	friend RationalNum operator*(const RationalNum& left, const RationalNum& right);
	friend RationalNum operator/(const RationalNum& left, const RationalNum& right);
	friend std::ostream& operator<<(std::ostream& out, const RationalNum& num);*/
};

