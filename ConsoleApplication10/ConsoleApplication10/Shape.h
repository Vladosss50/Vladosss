#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cmath>
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Базовый абстрактный класс
class Shape {
protected:
    static int schetchikFigur;  // Счётчик фигур

public:
    Shape();
    virtual ~Shape();

    virtual double ploshad() const = 0;     // Площадь
    virtual double perimetr() const = 0;    // Периметр
    virtual void vyvod() const = 0;         // Вывод

    static int getCount();
};

// Круг
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r);
    ~Circle();

    double ploshad() const override;
    double perimetr() const override;
    void vyvod() const override;
};

// Прямоугольник
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h);
    ~Rectangle();

    double ploshad() const override;
    double perimetr() const override;
    void vyvod() const override;
};

// Треугольник
class Triangle : public Shape {
private:
    double a, b, c;  // Стороны

public:
    Triangle(double s1, double s2, double s3);
    ~Triangle();

    double ploshad() const override;
    double perimetr() const override;
    void vyvod() const override;
};

#endif