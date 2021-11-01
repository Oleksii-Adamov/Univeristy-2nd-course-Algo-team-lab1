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
	void set(long long numerator, long long denominator);
	RationalNum(long long numerator, long long denominator);
	long long get_numerator();
	long long get_denominator();
	friend bool operator==(const RationalNum& left, const RationalNum& right);
	friend bool operator!=(const RationalNum& left, const RationalNum& right);
	friend RationalNum operator+(const RationalNum& left, const RationalNum& right);
	friend RationalNum operator-(const RationalNum& left, const RationalNum& right);
	friend RationalNum operator*(const RationalNum& left, const RationalNum& right);
	friend RationalNum operator/(const RationalNum& left, const RationalNum& right);
	RationalNum(const RationalNum& other);
	RationalNum& operator=(const RationalNum& other);
	RationalNum to_pow(long long exponent);
	friend std::ostream& operator<<(std::ostream& out, const RationalNum& num);
	friend std::istream& operator>>(std::istream& in, RationalNum& num);
	friend bool operator<(const RationalNum& left, const RationalNum& right);
	friend bool operator<=(const RationalNum& left, const RationalNum& right);
	friend bool operator>(const RationalNum& left, const RationalNum& right);
	friend bool operator>=(const RationalNum& left, const RationalNum& right);
	RationalNum& operator+=(const RationalNum& other);
	RationalNum& operator-=(const RationalNum& other);
	RationalNum& operator*=(const RationalNum& other);
	RationalNum& operator/=(const RationalNum& other);
};

