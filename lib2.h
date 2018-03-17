#ifndef LIB2_H
#define LIB2_H


#include <iostream>
using namespace std;

#define complex Complex

class Complex         // класс "Комплексное число"
{
private:
  double re, im;      // действительная и мнимая части

public:
  // конструкторы
  Complex (double r);
  Complex (double r, double i);
  Complex (const Complex &c);   // конструктор копирования

  // деструктор
  ~Complex ();

  // остальные функции
  // Модуль комплексного числа
  double abs () const;
  double arg() const;

  // оператор присваивания
  Complex& operator = (Complex &c);

  // оператор +=
  Complex& operator += (Complex &c);

  // оператор сложения
  Complex operator + (const Complex &c)const;

  // оператор вычитания
  Complex operator - (const Complex &c)const;

  // оператор умножения
  Complex operator * (const Complex &c)const;
  Complex divby(double i)const;
  // оператор деления
  Complex operator / (const Complex &c)const;

  // !!!
  Complex operator ^(Complex &c)const;

  Complex conj()const ;

  friend Complex operator+(double i,const Complex &);
  friend Complex operator-(double i,const Complex &);
  friend Complex operator*(double i,const Complex &);
  friend Complex operator/(double i,const Complex &);
  friend Complex operator^(double i,const Complex &);
  friend Complex ln(const Complex &c);
  friend Complex exp(const Complex& c);


  // укажем дружественные операторы, которым мы разрешаем доступ
  // к личным (private) данным
  friend ostream & operator<< (ostream &, const Complex &);
  friend istream & operator>> (istream &, Complex &);

};

const Complex i(0,1);

#endif // LIB2_H
