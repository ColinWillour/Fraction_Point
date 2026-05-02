#ifndef FRACTION_H
#define FRACTION_H

#include "abstract_decimal.h"
#include <iostream>
#include <stdexcept>

class Fraction : public Decimal {
public:
    Fraction();
    Fraction(int numer, int denom);
    Fraction(const Fraction& other);
    Fraction(Fraction&& other);
    Fraction& operator=(const Fraction& other);
    Fraction& operator=(Fraction&& other);
    ~Fraction();

    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    double convertToDecimal() const override;

private:
    int* numer_;
    int* denom_;
};

#endif
