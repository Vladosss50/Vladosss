#include "Shape.h"
#include <iomanip>

int Shape::schetchikFigur = 0;

// Shape
Shape::Shape() {
    schetchikFigur++;
}

Shape::~Shape() {
    schetchikFigur--;
}

int Shape::getCount() {
    return schetchikFigur;
}

// Circle
Circle::Circle(double r) : radius(r) {}
Circle::~Circle() {}

double Circle::ploshad() const {
    return M_PI * radius * radius;
}

double Circle::perimetr() const {
    return 2 * M_PI * radius;
}

void Circle::vyvod() const {
    cout << "Круг: радиус=" << radius
        << ", площадь=" << ploshad()
        << ", периметр=" << perimetr() << endl;
}

// Rectangle
Rectangle::Rectangle(double w, double h) : width(w), height(h) {}
Rectangle::~Rectangle() {}

double Rectangle::ploshad() const {
    return width * height;
}

double Rectangle::perimetr() const {
    return 2 * (width + height);
}

void Rectangle::vyvod() const {
    cout << "Прямоугольник: " << width << "x" << height
        << ", площадь=" << ploshad()
        << ", периметр=" << perimetr() << endl;
}

// Triangle
Triangle::Triangle(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {}
Triangle::~Triangle() {}

double Triangle::perimetr() const {
    return a + b + c;
}

double Triangle::ploshad() const {
    double p = perimetr() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::vyvod() const {
    cout << "Треугольник: стороны=" << a << "," << b << "," << c
        << ", площадь=" << ploshad()
        << ", периметр=" << perimetr() << endl;
}