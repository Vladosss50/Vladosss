#include <iostream>
#include "Fraction.h"
#include "Vector3D.h"
#include "Matrix.h"

using namespace std;

void separator(const string& title) {
    cout << "\n============================================================" << endl;
    cout << "  " << title << endl;
    cout << "============================================================" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // ========== ЗАДАНИЕ 1.1: Fraction ==========
    separator("ЗАДАНИЕ 1.1: Дроби (Fraction)");
    try {
        Fraction a(1, 2);
        Fraction b(3, 4);

        cout << "a = " << a << ", b = " << b << endl;
        cout << "a + b = " << a + b << endl;
        cout << "a - b = " << a - b << endl;
        cout << "a * b = " << a * b << endl;
        cout << "a / b = " << a / b << endl;
        cout << "a == b? " << (a == b ? "true" : "false") << endl;
        cout << "a < b? " << (a < b ? "true" : "false") << endl;
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    // ========== ЗАДАНИЕ 1.2: Vector3D ==========
    separator("ЗАДАНИЕ 1.2: 3D Векторы (Vector3D)");
    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 6);

    cout << "v1 = "; v1.vyvod(); cout << endl;
    cout << "v2 = "; v2.vyvod(); cout << endl;
    cout << "v1 + v2 = "; (v1 + v2).vyvod(); cout << endl;
    cout << "v1 * v2 (скалярное) = " << (v1 * v2) << endl;
    cout << "v1 * 2 = "; (v1 * 2).vyvod(); cout << endl;

    v1[0] = 10;
    cout << "После v1[0]=10: "; v1.vyvod(); cout << endl;

    ++v1;
    cout << "После ++v1: "; v1.vyvod(); cout << endl;

    cout << "Всего векторов создано: " << Vector3D::getCount() << endl;

    // ========== ЗАДАНИЕ 1.3: Matrix ==========
    separator("ЗАДАНИЕ 1.3: Матрицы (Matrix)");

    Matrix A(2, 2);
    A(0, 0) = 1; A(0, 1) = 2;
    A(1, 0) = 3; A(1, 1) = 4;

    Matrix B(2, 2);
    B(0, 0) = 5; B(0, 1) = 6;
    B(1, 0) = 7; B(1, 1) = 8;

    cout << "Матрица A:" << endl;
    A.vyvod();
    cout << "\nМатрица B:" << endl;
    B.vyvod();

    cout << "\nA + B:" << endl;
    (A + B).vyvod();

    cout << "\nA * 2:" << endl;
    (A * 2).vyvod();

    cout << "\n!A (транспонирование):" << endl;
    (!A).vyvod();

    cout << "\nA == B? " << (A == B ? "true" : "false") << endl;

    // Проверка умножения матриц разных размеров
    Matrix C(2, 3);
    C(0, 0) = 1; C(0, 1) = 2; C(0, 2) = 3;
    C(1, 0) = 4; C(1, 1) = 5; C(1, 2) = 6;

    Matrix D(3, 2);
    D(0, 0) = 7; D(0, 1) = 8;
    D(1, 0) = 9; D(1, 1) = 10;
    D(2, 0) = 11; D(2, 1) = 12;

    cout << "\nC * D (2x3 * 3x2 = 2x2):" << endl;
    (C * D).vyvod();

    cout << "\n============================================================" << endl;
    cout << "  Проект 1 завершён!" << endl;
    cout << "============================================================" << endl;

    return 0;
}