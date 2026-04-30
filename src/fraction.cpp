#include "fraction.h"
#include <iostream>
#include <stdexcept>

// Default constructor
Fraction::Fraction() {
    std::cout << "I am in the default constructor" << std::endl;
    numer_ = new int(0);
    denom_ = new int(1);
}

Fraction::Fraction(int numer, int denom) {
    std::cout << "I am in the custom constructor" << std::endl;
    if (denom == 0) {
        throw std::runtime_error("Can't divide by zero!");
    }
    numer_ = new int(numer);
    denom_ = new int(denom);
}

Fraction::Fraction(const Fraction& other) {
    std::cout << "I am in the copy constructor" << std::endl;
    if (other.numer_ == nullptr || other.denom_ == nullptr) {
        throw std::runtime_error("can't dereference null pointers");
    }
    numer_ = new int(*other.numer_);
    denom_ = new int(*other.denom_);
}

Fraction::Fraction(Fraction&& other) {
    std::cout << "I am in the move constructor" << std::endl;
    if (other.numer_ == nullptr || other.denom_ == nullptr) {
        throw std::runtime_error("can't dereference null pointers");
    }
    numer_ = other.numer_;
    denom_ = other.denom_;
    other.numer_ = nullptr;
    other.denom_ = nullptr;
}

Fraction& Fraction::operator=(const Fraction& other) {
    std::cout << "I am in the assignment operator (lvalue)" << std::endl;
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

Fraction& Fraction::operator=(Fraction&& other) {
    std::cout << "I am in the assignment operator (rvalue)" << std::endl;
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

Fraction::~Fraction() {
    std::cout << "I am in the destructor" << std::endl;
    delete numer_;
    delete denom_;
    numer_ = nullptr;
    denom_ = nullptr;
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    std::cout << "I am in the plus operator" << std::endl;
    if (lhs.numer_ == nullptr || lhs.denom_ == nullptr ||
        rhs.numer_ == nullptr || rhs.denom_ == nullptr) {
        throw std::runtime_error("can't dereference null pointers");
    }
    
    int new_numer = (*lhs.numer_) * (*rhs.denom_) + (*lhs.denom_) * (*rhs.numer_);
    int new_denom = (*lhs.denom_) * (*rhs.denom_);
    return Fraction(new_numer, new_denom);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    std::cout << "I am in the multiplication operator" << std::endl;
    if (lhs.numer_ == nullptr || lhs.denom_ == nullptr ||
        rhs.numer_ == nullptr || rhs.denom_ == nullptr) {
        throw std::runtime_error("can't dereference null pointers");
    }
    int new_numer = (*lhs.numer_) * (*rhs.numer_);
    int new_denom = (*lhs.denom_) * (*rhs.denom_);
    return Fraction(new_numer, new_denom);
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    std::cout << "I am in the << operator" << std::endl;
    if (f.numer_ == nullptr || f.denom_ == nullptr) {
        throw std::runtime_error("can't dereference null pointers");
    }++
    os << *f.numer_ << "/" << *f.denom_;
    return os;
}

double Fraction::convertToDecimal() const {
    std::cout << "I am in the convertToDecimal" << std::endl;
    if (numer_ == nullptr || denom_ == nullptr) {
        throw std::runtime_error("can't dereference null pointers");
    }
    return static_cast<double>(*numer_) / static_cast<double>(*denom_);
}
