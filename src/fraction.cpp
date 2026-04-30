#include "fraction.h"
#include <iostream>
#include <stdexcept>

// Default constructor
Fraction::Fraction() {
    std::cout << "I am in the Default constructor" << std::endl;
    numer_ = new int(0);
    denom_ = new int(1);
}

// Custom constructor
Fraction::Fraction(int numer, int denom) {
    std::cout << "I am in the Custom constructor" << std::endl;
    if (denom == 0) {
        throw std::runtime_error("Can't divide by zero!");
    }
    numer_ = new int(numer);
    denom_ = new int(denom);
}

// Copy constructor
Fraction::Fraction(const Fraction& other) {
    std::cout << "I am in the Copy constructor" << std::endl;
    if (other.numer_ == nullptr || other.denom_ == nullptr) {
        throw std::runtime_error("can't dereference null pointers");
    }
    numer_ = new int(*other.numer_);
    denom_ = new int(*other.denom_);
}

// Move constructor
Fraction::Fraction(Fraction&& other) {
    std::cout << "I am in the Move constructor" << std::endl;
    if (other.numer_ == nullptr || other.denom_ == nullptr) {
        throw std::runtime_error("can't dereference null pointers");
    }
    numer_ = other.numer_;
    denom_ = other.denom_;
    other.numer_ = nullptr;
    other.denom_ = nullptr;
}

// Assignment operator (lvalue)
Fraction& Fraction::operator=(const Fraction& other) {
    std::cout << "I am in the Assignment operator (lvalue)" << std::endl;
    if (this == &other) {
        return *this;
    }
    if (other.numer_ == nullptr || other.denom_ == nullptr) {
        throw std::runtime_error("can't dereference null pointers");
    }
    delete numer_;
    delete denom_;
    numer_ = new int(*other.numer_);
    denom_ = new int(*other.denom_);
    return *this;
}

// Assignment operator (rvalue)
Fraction& Fraction::operator=(Fraction&& other) {
    std::cout << "I am in the Assignment operator (rvalue)" << std::endl;
    if (this == &other) {
        return *this;
    }
    if (other.numer_ == nullptr || other.denom_ == nullptr) {
        throw std::runtime_error("can't dereference null pointers");
    }
    delete numer_;
    delete denom_;
    numer_ = other.numer_;
    denom_ = other.denom_;
    other.numer_ = nullptr;
    other.denom_ = nullptr;
    return *this;
}

// Destructor
Fraction::~Fraction() {
    std::cout << "I am in the Destructor" << std::endl;
    delete numer_;
    delete denom_;
    numer_ = nullptr;
    denom_ = nullptr;
}

// Plus operator (friend)
Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    std::cout << "I am in the Plus operator" << std::endl;
    if (lhs.numer_ == nullptr || lhs.denom_ == nullptr ||
        rhs.numer_ == nullptr || rhs.denom_ == nullptr) {
        throw std::runtime_error("can't dereference null pointers");
    }
    // a/b + c/d = (a*d + b*c) / (b*d)
    int new_numer = (*lhs.numer_) * (*rhs.denom_) + (*lhs.denom_) * (*rhs.numer_);
    int new_denom = (*lhs.denom_) * (*rhs.denom_);
    return Fraction(new_numer, new_denom);
}

// Multiplication operator (friend)
Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    std::cout << "I am in the Multiplication operator" << std::endl;
    if (lhs.numer_ == nullptr || lhs.denom_ == nullptr ||
        rhs.numer_ == nullptr || rhs.denom_ == nullptr) {
        throw std::runtime_error("can't dereference null pointers");
    }
    int new_numer = (*lhs.numer_) * (*rhs.numer_);
    int new_denom = (*lhs.denom_) * (*rhs.denom_);
    return Fraction(new_numer, new_denom);
}

// Stream output operator (friend)
std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    std::cout << "I am in the << operator" << std::endl;
    if (f.numer_ == nullptr || f.denom_ == nullptr) {
        throw std::runtime_error("can't dereference null pointers");
    }
    os << *f.numer_ << "/" << *f.denom_;
    return os;
}

// convertToDecimal
double Fraction::convertToDecimal() const {
    std::cout << "I am in the convertToDecimal" << std::endl;
    if (numer_ == nullptr || denom_ == nullptr) {
        throw std::runtime_error("can't dereference null pointers");
    }
    return static_cast<double>(*numer_) / static_cast<double>(*denom_);
}
