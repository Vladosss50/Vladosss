#include "Fraction.h"
#include <stdexcept>
#include <cmath>
using namespace std;

// НОД через алгоритм Евклида
int Fraction::nod(int a, int b) const {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Приведение к нормальному виду (знаменатель > 0, дробь сокращена)
void Fraction::sokrati() {
    if (znamenatel < 0) {
        chislitel = -chislitel;
        znamenatel = -znamenatel;
    }
    int g = nod(chislitel, znamenatel);
    chislitel /= g;
    znamenatel /= g;
}

// Конструктор
Fraction::Fraction(int num, int den) : chislitel(num), znamenatel(den) {
    if (znamenatel == 0) {
        throw invalid_argument("Знаменатель не может быть 0");
    }
    sokrati();
}

// Конструктор копирования
Fraction::Fraction(const Fraction& other)
    : chislitel(other.chislitel), znamenatel(other.znamenatel) {
}

// Сложение: a/b + c/d = (a*d + c*b) / (b*d)
Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(
        chislitel * other.znamenatel + other.chislitel * znamenatel,
        znamenatel * other.znamenatel
    );
}

// Вычитание: a/b - c/d = (a*d - c*b) / (b*d)
Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(
        chislitel * other.znamenatel - other.chislitel * znamenatel,
        znamenatel * other.znamenatel
    );
}

// Умножение: a/b * c/d = (a*c) / (b*d)
Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(
        chislitel * other.chislitel,
        znamenatel * other.znamenatel
    );
}

// Деление: a/b / c/d = (a*d) / (b*c)
Fraction Fraction::operator/(const Fraction& other) const {
    if (other.chislitel == 0) {
        throw invalid_argument("Деление на ноль");
    }
    return Fraction(
        chislitel * other.znamenatel,
        znamenatel * other.chislitel
    );
}

// Сравнение
bool Fraction::operator==(const Fraction& other) const {
    return chislitel == other.chislitel && znamenatel == other.znamenatel;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    return chislitel * other.znamenatel < other.chislitel * znamenatel;
}

bool Fraction::operator>(const Fraction& other) const {
    return other < *this;
}

// Вывод
ostream& operator<<(ostream& os, const Fraction& f) {
    os << f.chislitel << "/" << f.znamenatel;
    return os;
}

// Ввод
istream& operator>>(istream& is, Fraction& f) {
    int num, den;
    char slash;
    is >> num >> slash >> den;
    f = Fraction(num, den);
    return is;
}