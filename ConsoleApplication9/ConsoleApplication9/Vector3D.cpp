#include "Vector3D.h"
#include <stdexcept>
using namespace std;

int Vector3D::schetchik = 0;

// Конструкторы
Vector3D::Vector3D(double x, double y, double z) {
    koord[0] = x;
    koord[1] = y;
    koord[2] = z;
    schetchik++;
}

Vector3D::Vector3D(const Vector3D& other) {
    for (int i = 0; i < 3; i++) {
        koord[i] = other.koord[i];
    }
    schetchik++;
}

Vector3D::~Vector3D() {
    schetchik--;
}

// Сложение векторов (покомпонентно)
Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(
        koord[0] + other.koord[0],
        koord[1] + other.koord[1],
        koord[2] + other.koord[2]
    );
}

// Вычитание векторов
Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(
        koord[0] - other.koord[0],
        koord[1] - other.koord[1],
        koord[2] - other.koord[2]
    );
}

// Скалярное произведение: x1*x2 + y1*y2 + z1*z2
double Vector3D::operator*(const Vector3D& other) const {
    return koord[0] * other.koord[0] +
        koord[1] * other.koord[1] +
        koord[2] * other.koord[2];
}

// Умножение на скаляр
Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(
        koord[0] * scalar,
        koord[1] * scalar,
        koord[2] * scalar
    );
}

// Умножение скаляра на вектор
Vector3D operator*(double scalar, const Vector3D& v) {
    return v * scalar;
}

// Префиксный инкремент: увеличивает все координаты на 1
Vector3D& Vector3D::operator++() {
    for (int i = 0; i < 3; i++) {
        koord[i] += 1;
    }
    return *this;
}

// Постфиксный инкремент: возвращает старое значение
Vector3D Vector3D::operator++(int) {
    Vector3D temp = *this;
    ++(*this);
    return temp;
}

// Доступ по индексу
double& Vector3D::operator[](int index) {
    if (index < 0 || index >= 3) {
        throw out_of_range("Индекс вне диапазона");
    }
    return koord[index];
}

const double& Vector3D::operator[](int index) const {
    if (index < 0 || index >= 3) {
        throw out_of_range("Индекс вне диапазона");
    }
    return koord[index];
}

// Составные операторы
Vector3D& Vector3D::operator+=(const Vector3D& other) {
    for (int i = 0; i < 3; i++) {
        koord[i] += other.koord[i];
    }
    return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& other) {
    for (int i = 0; i < 3; i++) {
        koord[i] -= other.koord[i];
    }
    return *this;
}

Vector3D& Vector3D::operator*=(double scalar) {
    for (int i = 0; i < 3; i++) {
        koord[i] *= scalar;
    }
    return *this;
}

int Vector3D::getCount() {
    return schetchik;
}

void Vector3D::vyvod() const {
    cout << "(" << koord[0] << ", " << koord[1] << ", " << koord[2] << ")";
}