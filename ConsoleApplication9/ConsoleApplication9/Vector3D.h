#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
using namespace std;

// Класс для работы с 3D векторами
class Vector3D {
private:
    double koord[3];        // Координаты x, y, z
    static int schetchik;   // Счётчик созданных векторов

public:
    Vector3D(double x = 0, double y = 0, double z = 0);
    Vector3D(const Vector3D& other);
    ~Vector3D();

    // Операторы
    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    double operator*(const Vector3D& other) const;  // Скалярное произведение
    Vector3D operator*(double scalar) const;        // Умножение на скаляр

    Vector3D& operator++();      // Префиксный ++
    Vector3D operator++(int);    // Постфиксный ++

    double& operator[](int index);
    const double& operator[](int index) const;

    Vector3D& operator+=(const Vector3D& other);
    Vector3D& operator-=(const Vector3D& other);
    Vector3D& operator*=(double scalar);

    static int getCount();
    void vyvod() const;

    friend Vector3D operator*(double scalar, const Vector3D& v);
};

#endif