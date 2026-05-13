#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

// Класс для работы с матрицами
class Matrix {
private:
    int** dannye;   // Данные матрицы
    int stroki;     // Количество строк
    int stolbcy;    // Количество столбцов

    void vydelit();     // Выделить память
    void osvobodit();   // Освободить память
    void skopirovat(const Matrix& other);  // Скопировать

public:
    Matrix(int r = 0, int c = 0);
    Matrix(const Matrix& other);
    ~Matrix();

    // Операторы
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(int scalar) const;

    int& operator()(int i, int j);
    const int& operator()(int i, int j) const;

    Matrix operator!() const;  // Транспонирование

    Matrix& operator=(const Matrix& other);

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    void vyvod() const;
    int getStroki() const { return stroki; }
    int getStolbcy() const { return stolbcy; }
};

#endif