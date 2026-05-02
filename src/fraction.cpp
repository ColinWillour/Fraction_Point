#include "fraction.h"
#include <iostream>
#include <stdexcept>

Fraction::Fraction()
{
    std::cout << "I am in the default constructor" << std::endl;
    n_ = new int(0);
    d_ = new int(1);
}

Fraction::Fraction(int n, int d)
{
    std::cout << "I am in the custom constructor" << std::endl;
    if (d == 0) throw std::runtime_error("Can't divide by zero!");
    n_ = new int(n);
    d_ = new int(d);
}

Fraction::Fraction(const Fraction& o)
{
    std::cout << "I am in the copy constructor" << std::endl;
    if (o.n_ == nullptr || o.d_ == nullptr)
        throw std::runtime_error("can't dereference null pointers");
    n_ = new int(*o.n_);
    d_ = new int(*o.d_);
}

Fraction::Fraction(Fraction&& o)
{
    std::cout << "I am in the move constructor" << std::endl;
    if (o.n_ == nullptr || o.d_ == nullptr)
        throw std::runtime_error("can't dereference null pointers");
    n_ = o.n_;
    d_ = o.d_;
    o.n_ = nullptr;
    o.d_ = nullptr;
}

Fraction& Fraction::operator=(const Fraction& o)
{
    std::cout << "I am in the assignment operator (lvalue)" << std::endl;
    if (this == &o) return *this;
    if (o.n_ == nullptr || o.d_ == nullptr)
        throw std::runtime_error("can't dereference null pointers");
    delete n_;
    delete d_;
    n_ = new int(*o.n_);
    d_ = new int(*o.d_);
    return *this;
}

Fraction& Fraction::operator=(Fraction&& o)
{
    std::cout << "I am in the assignment operator (rvalue)" << std::endl;
    if (this == &o) return *this;
    if (o.n_ == nullptr || o.d_ == nullptr)
        throw std::runtime_error("can't dereference null pointers");
    delete n_;
    delete d_;
    n_ = o.n_;
    d_ = o.d_;
    o.n_ = nullptr;
    o.d_ = nullptr;
    return *this;
}

Fraction::~Fraction()
{
    std::cout << "I am in the destructor" << std::endl;
    delete n_;
    delete d_;
    n_ = nullptr;
    d_ = nullptr;
}

Fraction operator+(const Fraction& a, const Fraction& b)
{
    std::cout << "I am in the plus operator" << std::endl;
    if (a.n_ == nullptr || a.d_ == nullptr || b.n_ == nullptr || b.d_ == nullptr)
        throw std::runtime_error("can't dereference null pointers");
    int n = (*a.n_) * (*b.d_) + (*a.d_) * (*b.n_);
    int d = (*a.d_) * (*b.d_);
    return Fraction(n, d);
}

Fraction operator*(const Fraction& a, const Fraction& b)
{
    std::cout << "I am in the multiplication operator" << std::endl;
    if (a.n_ == nullptr || a.d_ == nullptr || b.n_ == nullptr || b.d_ == nullptr)
        throw std::runtime_error("can't dereference null pointers");
    int n = (*a.n_) * (*b.n_);
    int d = (*a.d_) * (*b.d_);
    return Fraction(n, d);
}

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
    std::cout << "I am in the << operator" << std::endl;
    if (f.n_ == nullptr || f.d_ == nullptr)
        throw std::runtime_error("can't dereference null pointers");
    os << *f.n_ << "/" << *f.d_;
    return os;
}

double Fraction::convertToDecimal() const
{
    std::cout << "I am in the convertToDecimal" << std::endl;
    if (n_ == nullptr || d_ == nullptr)
        throw std::runtime_error("can't dereference null pointers");
    return static_cast<double>(*n_) / static_cast<double>(*d_);
}
