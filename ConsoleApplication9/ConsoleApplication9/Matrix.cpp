#include "Matrix.h"
#include <stdexcept>
using namespace std;

// Выделение памяти
void Matrix::vydelit() {
    dannye = new int* [stroki];
    for (int i = 0; i < stroki; i++) {
        dannye[i] = new int[stolbcy]();
    }
}

// Освобождение памяти
void Matrix::osvobodit() {
    if (dannye) {
        for (int i = 0; i < stroki; i++) {
            delete[] dannye[i];
        }
        delete[] dannye;
        dannye = nullptr;
    }
}

// Копирование данных
void Matrix::skopirovat(const Matrix& other) {
    stroki = other.stroki;
    stolbcy = other.stolbcy;
    vydelit();
    for (int i = 0; i < stroki; i++) {
        for (int j = 0; j < stolbcy; j++) {
            dannye[i][j] = other.dannye[i][j];
        }
    }
}

// Конструкторы
Matrix::Matrix(int r, int c) : stroki(r), stolbcy(c), dannye(nullptr) {
    if (stroki > 0 && stolbcy > 0) {
        vydelit();
    }
}

Matrix::Matrix(const Matrix& other) : stroki(0), stolbcy(0), dannye(nullptr) {
    skopirovat(other);
}

// Деструктор
Matrix::~Matrix() {
    osvobodit();
}

// Сложение матриц
Matrix Matrix::operator+(const Matrix& other) const {
    if (stroki != other.stroki || stolbcy != other.stolbcy) {
        throw invalid_argument("Размеры матриц должны совпадать");
    }
    Matrix result(stroki, stolbcy);
    for (int i = 0; i < stroki; i++) {
        for (int j = 0; j < stolbcy; j++) {
            result.dannye[i][j] = dannye[i][j] + other.dannye[i][j];
        }
    }
    return result;
}

// Вычитание матриц
Matrix Matrix::operator-(const Matrix& other) const {
    if (stroki != other.stroki || stolbcy != other.stolbcy) {
        throw invalid_argument("Размеры матриц должны совпадать");
    }
    Matrix result(stroki, stolbcy);
    for (int i = 0; i < stroki; i++) {
        for (int j = 0; j < stolbcy; j++) {
            result.dannye[i][j] = dannye[i][j] - other.dannye[i][j];
        }
    }
    return result;
}

// Умножение матриц
Matrix Matrix::operator*(const Matrix& other) const {
    if (stolbcy != other.stroki) {
        throw invalid_argument("Неверные размеры для умножения");
    }
    Matrix result(stroki, other.stolbcy);
    for (int i = 0; i < stroki; i++) {
        for (int j = 0; j < other.stolbcy; j++) {
            result.dannye[i][j] = 0;
            for (int k = 0; k < stolbcy; k++) {
                result.dannye[i][j] += dannye[i][k] * other.dannye[k][j];
            }
        }
    }
    return result;
}

// Умножение на скаляр
Matrix Matrix::operator*(int scalar) const {
    Matrix result(stroki, stolbcy);
    for (int i = 0; i < stroki; i++) {
        for (int j = 0; j < stolbcy; j++) {
            result.dannye[i][j] = dannye[i][j] * scalar;
        }
    }
    return result;
}

// Доступ к элементу
int& Matrix::operator()(int i, int j) {
    if (i < 0 || i >= stroki || j < 0 || j >= stolbcy) {
        throw out_of_range("Индекс вне диапазона");
    }
    return dannye[i][j];
}

const int& Matrix::operator()(int i, int j) const {
    if (i < 0 || i >= stroki || j < 0 || j >= stolbcy) {
        throw out_of_range("Индекс вне диапазона");
    }
    return dannye[i][j];
}

// Транспонирование
Matrix Matrix::operator!() const {
    Matrix result(stolbcy, stroki);
    for (int i = 0; i < stroki; i++) {
        for (int j = 0; j < stolbcy; j++) {
            result.dannye[j][i] = dannye[i][j];
        }
    }
    return result;
}

// Оператор присваивания
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        osvobodit();
        skopirovat(other);
    }
    return *this;
}

// Сравнение
bool Matrix::operator==(const Matrix& other) const {
    if (stroki != other.stroki || stolbcy != other.stolbcy) {
        return false;
    }
    for (int i = 0; i < stroki; i++) {
        for (int j = 0; j < stolbcy; j++) {
            if (dannye[i][j] != other.dannye[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

// Вывод матрицы
void Matrix::vyvod() const {
    for (int i = 0; i < stroki; i++) {
        for (int j = 0; j < stolbcy; j++) {
            cout << dannye[i][j] << " ";
        }
        cout << endl;
    }
}