/*
Jimmy Lauchoy
CS1124
Rec 10
*/

#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>
#include <vector>
#include <iostream>

namespace CS1124 {
	class Rational {
	public:
		Rational();
		Rational(const int&);
		int getNumerator() const;
		int getDenominator() const;
		void setNumerator(int number);
		void setDenominator(int number);
		void normalize();
		Rational& operator += (const Rational& rhs);
		Rational& operator = (const int &number);
		bool operator == (Rational& rhs);
		Rational& operator ++ ();
		Rational operator ++ (int number);
	private:
		int numerator, denominator;
	};
	std::istream& operator >> (std::istream& is, Rational& number);
	std::ostream& operator << (std::ostream& os, const Rational& number);
	int greatestCommonDivisor(int x, int y);
	const Rational operator + (Rational& lhs, Rational& rhs);
	bool operator == (int i, Rational& rhs);
	bool operator != (Rational& lhs, Rational& rhs);
	Rational& operator -- (Rational& r);
	Rational& operator -- (Rational& r, int);
}
#endif