#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "fraction_20hgww.h"

using namespace std;

Fraction::Fraction() : num(0), denom(1) { }

Fraction::Fraction(int numerator) : num(numerator), denom(1) { }
Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw FractionException("Division by zero");
    }
    if (numerator == 0) {
      num = 0;
      denom = 1;
      return;
    }
    const int sign = !(numerator < 0 && denominator < 0) && (numerator < 0 || denominator < 0) ? -1 : 1;
    numerator = abs(numerator);
    denominator = abs(denominator);
    int gcd = Fraction::GCD(numerator, denominator);
    num = sign * numerator/gcd;
    denom = denominator/gcd;
}

int Fraction::LCM(const int n, const int m) {
    return abs(n * m)/Fraction::GCD(n, m);
}

int Fraction::GCD(const int n, const int m) {
    if (n == 0 || m == 0) return 0;
    if (n < m) return GCD(m, n);
    else if (n % m == 0) return m;
    else return Fraction::GCD(m, n%m);
}

int Fraction::numerator() const {
  return num;
}

int Fraction::denominator() const {
  return denom;
}

/*
 * Operator overloading
 */

Fraction Fraction::operator-() const {
    return {this->numerator() * -1, this->denominator()};
}

Fraction Fraction::operator++(int)  {
    Fraction old(*this);
    operator++();
    return old;
}

Fraction& Fraction::operator++() {
    *this = *this + 1;
    return *this;
}

Fraction& Fraction::operator+=(const Fraction& rhs) {
    *this = *this + rhs;
    return *this;
}

Fraction operator*(const Fraction& multiplicand, const Fraction& multiplier) {
  return {
      multiplicand.numerator() * multiplier.numerator(),
      multiplicand.denominator() * multiplier.denominator()
  };
}

Fraction operator/(const Fraction& dividend, const Fraction& divisor) {
  return {
      dividend.numerator() * divisor.denominator(),
      dividend.denominator() * divisor.numerator()
  };
}

Fraction operator+(const Fraction& addend1, const Fraction& addend2) {
  int lcm = Fraction::LCM(addend1.denominator(), addend2.denominator());
  int sumNumerator = addend1.numerator() * lcm / addend1.denominator() + addend2.numerator() * lcm / addend2.denominator();
  return {sumNumerator, lcm};
}

Fraction operator-(const Fraction& minuend, const Fraction& subtrahend) {
  int lcm = Fraction::LCM(minuend.denominator(), subtrahend.denominator());
  int minuendNumerator = minuend.numerator() * lcm / minuend.denominator();
  int subtrahendNumerator = subtrahend.numerator() * lcm / subtrahend.denominator();
  return {minuendNumerator - subtrahendNumerator, lcm};
}

bool operator==(const Fraction& left, const Fraction& right) {
  return left.numerator() == right.numerator() && left.denominator() == right.denominator();
}

bool operator!=(const Fraction& left, const Fraction& right) {
  return !(left == right);
}

bool operator<(const Fraction& left, const Fraction& right) {
  return (left - right).numerator() < 0;
}

bool operator>(const Fraction& left, const Fraction& right) {
  return (left - right).numerator() > 0;
}

bool operator<=(const Fraction& left, const Fraction& right) {
  return left < right || left == right;
}

bool operator>=(const Fraction& left, const Fraction& right) {
  return left > right || left == right;
}

ostream& operator<<(ostream& out, const Fraction& fraction) {
  out << fraction.numerator() << "/" << fraction.denominator();
  return out;
}
istream& operator>>(istream& in, Fraction& fraction) {
    string input;
    in>>input;
    stringstream inputStream(input);
    vector<string> fracNums;

    //isolate numerator and denominator
    while (getline(inputStream,input,'/')){
        fracNums.push_back(input);
    }
    //ensure size one for int or 2 for frac
    if (fracNums.size() > 2 || fracNums.empty()) throw FractionException("Invalid Input");


    //check for non-numeric chars and negatives
    for (string& num : fracNums) {
        if (num.find_first_not_of("-0123456789") != string::npos || num.find('-',1) != string::npos){
            throw FractionException("Invalid Input");
        }
    }
    if (fracNums.size() == 1) {
        fraction.num = stoi(fracNums.at(0));
        fraction.denom = 1;
    } else {
        // done to automatically reduce input/validate input
        Fraction frac(stoi(fracNums.at(0)), stoi(fracNums.at(1)));
        fraction.num = frac.numerator();
        fraction.denom = frac.denominator();
    }
    return in;
}

FractionException::FractionException(string  message) : message(std::move(message)) {}
string& FractionException::what() {
    return message;
}
