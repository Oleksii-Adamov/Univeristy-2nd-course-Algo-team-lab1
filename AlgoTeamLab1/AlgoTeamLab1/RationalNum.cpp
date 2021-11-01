#include "RationalNum.h"
#include<numeric>

RationalNum::RationalNum() :
	m_numerator(0), m_denominator(1) 
{

}

RationalNum::RationalNum(long long numerator, long long denominator) {
	if (denominator == 0) {
		throw "Denominator cannot be equal to zero!";
	}
	m_numerator = numerator;
	m_denominator = denominator;
	if (m_denominator < 0) {
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	simlify();
}

long long RationalNum::get_numerator() {
	return m_numerator;
}

long long RationalNum::get_denominator() {
	return m_denominator;
}

// Euclidean algorithm
long long RationalNum::gcd(long long a, long long b) {
	while (b != 0) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}

// diving numerator and denominator by their gcd.
void RationalNum::simlify() {
	if (m_numerator == 0) {
		m_denominator = 1;
		return;
	}
	long long n_d_gcd = gcd(m_numerator, m_denominator);
	m_numerator /= n_d_gcd;
	m_denominator /= n_d_gcd;
	if (m_denominator < 0) {
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
}

// because of operating with irreducible fractions, checking equality of numerators and denominators
bool operator==(const RationalNum& left, const RationalNum& right) {
	return left.m_numerator == right.m_numerator && left.m_denominator == right.m_denominator;
}

bool operator!=(const RationalNum& left, const RationalNum& right) {
	return !(left == right);
}

// Addition of two fractions using formula: a/b + c/d = (ad + bc)/(bd), and simlifying the result.
RationalNum operator+(const RationalNum& left, const RationalNum& right) {
	RationalNum res(left.m_numerator * right.m_denominator + left.m_denominator * right.m_numerator, left.m_denominator* right.m_denominator);
	res.simlify();
	return res;
}

// Subtraction of  two fractions using formula: a/b - c/d = (ad - bc)/(bd), and simlifying the result.
RationalNum operator-(const RationalNum& left, const RationalNum& right) {
	RationalNum res(left.m_numerator * right.m_denominator - left.m_denominator * right.m_numerator, left.m_denominator * right.m_denominator);
	res.simlify();
	return res;
}

// Multiplication of  two fractions using formula: (a/b) * (c/d) = (ac)/(bd), and simlifying the result.
RationalNum operator*(const RationalNum& left, const RationalNum& right) {
	RationalNum res(left.m_numerator * right.m_numerator, left.m_denominator * right.m_denominator);
	res.simlify();
	return res;
}

// Division of  two fractions using formula: (a/b) / (c/d) = (ad)/(bc), and simlifying the result.
RationalNum operator/(const RationalNum& left, const RationalNum& right) {
	if (right.m_numerator == 0) {
		throw "Division by zero!";
	}
	RationalNum res(left.m_numerator * right.m_denominator, left.m_denominator * right.m_numerator);
	res.simlify();
	return res;
}