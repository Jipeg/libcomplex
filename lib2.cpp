#include "lib2.h"


#include "complex.h"
#include <cmath>

// конструкторы
Complex::Complex (double r)
{
  re = r;
  im = 0;
}

Complex::Complex (double r, double i)
{
  re = r;
  im = i;
}

Complex::Complex (const Complex &c)   // конструктор копирования
{
  re = c.re;
  im = c.im;
}

// деструктор
Complex::~Complex ()
{
}
// модуль
double Complex::abs () const
{
  return sqrt (re * re + im * im);
}
// аргумент
double Complex::arg() const
{
    double phi = acos(re / abs());
    phi = im > 0 ? phi : -phi;
    return phi;
}
// оператор присваивания
Complex& Complex::operator = (Complex &c)
{
  re = c.re;
  im = c.im;
  return (*this);
}
// оператор +=
Complex& Complex::operator += (Complex &c)
{
  re += c.re;
  im += c.im;
  return *this;
}

// оператор сложения
Complex Complex::operator + (const Complex &c) const
{
  return Complex (re + c.re, im + c.im);
}

// оператор вычитания
Complex Complex::operator - (const Complex &c) const
{
  return Complex(re - c.re, im - c.im);
}

// оператор умножения
Complex Complex::operator * (const Complex &c) const
{
  return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
}

// делит обе части на число
Complex Complex::divby(double i)const
{
    return Complex(re/i, im/i);
}

// оператор деления
Complex Complex::operator / (const Complex &c) const
{
  Complex tmp = (*this * c.conj()).divby(c.abs() * c.abs());
  return tmp;
}

// сопряженное
Complex Complex::conj()const
{
    return Complex(re, -im);
}

// !!!
Complex Complex::operator ^(Complex &c)const
{
    return exp(ln(*this) * c);
}


// перегрузка оператора <<
ostream& operator<< (ostream &out, const Complex &c)
{
  out << "(" << c.re << ", " << c.im << ")";
  return out;
}

// перегрузка оператора >>
istream& operator>> (istream &in, Complex &c)
{
  in >> c.re >> c.im;
  return in;
}


// перегрузка вещественных операторов

Complex operator+(double i,const Complex &c)
{
    return Complex(c.re + i, c.im);
}

Complex operator -(double i,const Complex &c)
{
    return Complex(c.re - i, c.im);
}

Complex operator *(double i,const Complex &c)
{
    return Complex(c.re * i, c.im * i);
}

Complex operator /(double i,const Complex &c)
{
    Complex tmp(i,0);
    return tmp / c;
}

Complex operator ^(double i,Complex &c)
{
    return(exp(log(i) * c));
}

// Ln & Exp
Complex ln(const Complex &c){
    return Complex(log(c.abs()), c.arg());
}

Complex exp(const Complex& c){
    return Complex(exp(c.re)*cos(c.im), exp(c.re)* sin(c.im));
}
