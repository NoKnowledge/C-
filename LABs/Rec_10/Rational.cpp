/*
Jimmy Lauchoy
CS1124
Rec 10
*/

#include "Rational.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace CS1124 {
	Rational::Rational() {}
	Rational::Rational(const int& number) : numerator(number), denominator(1) {}
	int Rational::getNumerator() const {
		return numerator;
	}
	int Rational::getDenominator() const {
		return denominator;
	}
	void Rational::setNumerator(int number) {
		numerator = number;
	}
	void Rational::setDenominator(int number) {
		denominator = number;
	}
	int greatestCommonDivisor(int x, int y) {
		while (y != 0) {
			int temp = x % y;
			x = y;
			y = temp;
		}
		//cout << "GCD:" << x;
		return x;
	}
	void Rational::normalize() {
		int divisor = greatestCommonDivisor(numerator, denominator);
		Rational::setNumerator(numerator / divisor);
		Rational::setDenominator(denominator / divisor);
		if (denominator < 0 && numerator > 0) {
			numerator *= -1;
			denominator *= -1;
		}
	}
	Rational& Rational::operator += (const Rational& rhs) {
		int multiplier = rhs.getDenominator();
		Rational::setNumerator((Rational::getNumerator() * rhs.getDenominator()) + (rhs.getNumerator() * Rational::getDenominator()));
		Rational::setDenominator(multiplier * Rational::getDenominator());
		Rational::normalize();
		return *this;
	}
	bool Rational::operator == (Rational& rhs) {
		rhs.normalize();
		Rational::normalize();
		if (Rational::getNumerator() == rhs.getNumerator() && Rational::getDenominator() == rhs.getDenominator()) {
			return true;
		}
	}
	Rational& Rational::operator ++ () {
		Rational::setNumerator(numerator + denominator);
		return *this;
	}
	Rational Rational::operator ++ (int) {
		Rational* answer = new Rational();
		answer->setNumerator(numerator);
		answer->setDenominator(denominator);
		Rational::setNumerator(numerator + denominator);
		return *answer;
	}
	istream& operator >> (istream& is, Rational& number) {
		int num, den;
		char slash;
		is >> num >> slash >> den;
		number.setNumerator(num); number.setDenominator(den);
		return is;
	}
	ostream& operator << (ostream& os, const Rational& number) {
		int gcd = greatestCommonDivisor(number.getNumerator(), number.getDenominator());
		if (number.getDenominator() /gcd== 1) {
			os << number.getNumerator()/gcd;
		}
		else {
			if (number.getNumerator() > 0 && number.getDenominator() < 0) {
				os << ((number.getNumerator()/gcd)*-1) << '/' << ((number.getDenominator()/gcd)*-1);
			}
			else {
				os << number.getNumerator() / gcd << "/" << number.getDenominator() / gcd;
			}
		}
		return os;
	}
	const Rational operator + (Rational& lhs, Rational& rhs) {
		Rational* ans = new Rational();
		ans->setNumerator(lhs.getNumerator());
		ans->setDenominator(lhs.getDenominator());
		*ans += rhs;
		return *ans;
	}
	bool operator == (int i, Rational& rhs) {
		if (rhs.getDenominator() == 1 && rhs.getNumerator() == i) {
			return true;
		}
		return false;
	}
	bool operator != (Rational& lhs, Rational& rhs) {
		return !(lhs == rhs);
	}
	Rational& operator -- (Rational& rNum) {
		rNum.setNumerator(rNum.getNumerator() - rNum.getDenominator());
		return rNum;
	}
	Rational& operator -- (Rational& rNum, int) {
		Rational* answer = new Rational();
		answer->setNumerator(rNum.getNumerator());
		answer->setDenominator(rNum.getDenominator());
		rNum.setNumerator(rNum.getNumerator() - rNum.getDenominator());
		return *answer;
	}


}