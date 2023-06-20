//
// Created by henry on 2022-10-19.
//

#ifndef FRACTION_20HGWW_H
#define FRACTION_20HGWW_H

#include <iostream>
#include <string>

using namespace std;

class Fraction {
public:
    /* default fraction 0/1 */
    Fraction();

    /* initializes fraction to num/1 */
    Fraction(int num);

    /* initializes fraction to num/den */
    Fraction(int num, int den);

    /* calculates GCD */
    static int GCD(int n, int m);

    /* calculates LCM */
    static int LCM(int n, int m);

    /* public access to numerator and denominator*/
    int numerator() const;
    int denominator() const;

    /* public overrides for increments and negation */
    Fraction operator-() const;
    Fraction operator++(int);
    Fraction& operator++();
    Fraction& operator+=(const Fraction& rhs);
private:
    /* private numerator and denominator fields */
    int num;
    int denom;

    /* >> operator needs access to private fields */
    friend istream& operator>>(istream& in, Fraction& fraction);
};

Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& dividend, const Fraction& divisor);
Fraction operator+(const Fraction& addend1, const Fraction& addend2);
Fraction operator-(const Fraction& minuend, const Fraction& subtrahend);
bool operator==(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator<(const Fraction& left, const Fraction& right);
bool operator>(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);
ostream& operator<<(ostream& out, const Fraction& fraction);


class FractionException {
public:
    explicit FractionException(string  message);
    string& what();
private:
    string message;
};

#endif