#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

// Класс для работы с обыкновенными дробями
class Fraction {
private:
    int chislitel;     // Числитель
    int znamenatel;    // Знаменатель

    void sokrati();    // Сократить дробь
    int nod(int a, int b) const;  // НОД

public:
    Fraction(int num = 0, int den = 1);
    Fraction(const Fraction& other);

    // Арифметические операторы
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    // Операторы сравнения
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;

    // Ввод/вывод
    friend ostream& operator<<(ostream& os, const Fraction& f);
    friend istream& operator>>(istream& is, Fraction& f);
};

#endif