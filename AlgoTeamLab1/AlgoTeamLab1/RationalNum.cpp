#include "RationalNum.h"
#include <numeric>
#include <math.h>
#include <string>
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

RationalNum::RationalNum(const RationalNum& other)
	: m_numerator(other.m_numerator), m_denominator(other.m_denominator) 
{

}

RationalNum& RationalNum::operator=(const RationalNum& other) {
	m_numerator = other.m_numerator;
	m_denominator = other.m_denominator;
	return *this;
}

// using std::pow because it uses assembly commands - so quicker
RationalNum RationalNum::to_pow(long long exponent) {
	if (exponent == 0) {
		return RationalNum(1, 1);
	}
	RationalNum res = *this;
	if (exponent < 0) {
		if (res.m_numerator == 0) {
			throw "Division by zero! (to_pow)";
		}
		std::swap(res.m_numerator, res.m_denominator);
		if (res.m_denominator < 0) {
			res.m_numerator = -res.m_numerator;
			res.m_denominator = -res.m_denominator;
		}
		exponent = -exponent;
	}
	res.m_numerator = (long long) std::pow(res.m_numerator, exponent);
	res.m_denominator = (long long)std::pow(res.m_denominator, exponent);
	return res;
}

// "numerator/denominator"
std::ostream& operator<<(std::ostream& out, const RationalNum& num) {
	out << num.m_numerator << "/" << num.m_denominator;
	return out;
}

// "numerator/denominator" non-decimal input handles std::stoll with his expecptions, I handle not full data
std::istream& operator>>(std::istream& in, RationalNum& num) {
	if (in.eof()) throw "RationalNum: Data in istream is not full!";
	char c;
	std::string numerator = "";
	while (in.get(c)) {
		if (c == '/') break;
		numerator += c;
	}
	if (numerator == "") throw "RationalNum: in istream numerator is missing";
	if (in.eof()) throw "RationalNum: Data in istream is not full!";
	num.m_numerator = std::stoll(numerator);
	std::string denominator = "";
	while (in.get(c)) {
		if (c == ' ' || c == '\n') break;
		denominator += c;
	}
	if (denominator == "") throw "RationalNum: in istream denominator is missing";
	num.m_denominator = std::stoll(denominator);
	num.simlify();
	return in;
}
// (a/b) < (c/d) if and only if ad < bc (considering canonical form)
bool operator<(const RationalNum& left, const RationalNum& right) {
	return left.m_numerator * right.m_denominator < left.m_denominator * right.m_numerator;
}

bool operator<=(const RationalNum& left, const RationalNum& right) {
	return left.m_numerator * right.m_denominator <= left.m_denominator* right.m_numerator;
}

bool operator>(const RationalNum& left, const RationalNum& right) {
	return left.m_numerator * right.m_denominator > left.m_denominator* right.m_numerator;
}

bool operator>=(const RationalNum& left, const RationalNum& right) {
	return left.m_numerator * right.m_denominator >= left.m_denominator * right.m_numerator;
}