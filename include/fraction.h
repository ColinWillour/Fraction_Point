#ifndef FRACTION_H
#define FRACTION_H

#include "abstract_decimal.h"
#include <iostream>
#include <stdexcept>

class Fraction : public Decimal {
public:
    // Default constructor
    Fraction();

    // Custom constructor
    Fraction(int numer, int denom);

    // Copy constructor
    Fraction(const Fraction& other);

    // Move constructor
    Fraction(Fraction&& other);

    // Assignment operator (lvalue)
    Fraction& operator=(const Fraction& other);

    // Assignment operator (rvalue)
    Fraction& operator=(Fraction&& other);

    // Destructor
    ~Fraction();

    // Plus operator (friend)
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);

    // Multiplication operator (friend)
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);

    // Stream output operator (friend)
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);

    // Convert to decimal (override from Decimal)
    double convertToDecimal() const override;

private:
    int* numer_;
    int* denom_;
};

#endif
