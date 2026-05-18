#include <iostream>

class Fraction {
private:
    int numerator;      // числитель
    int denominator;    // знаменатель

    // Функция для нахождения НОД (алгоритм Евклида)
    int findGCD(int a, int b) const {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Метод для сокращения дроби
    void reduce() {
        if (denominator == 0) {
            std::cerr << "Ошибка: Знаменатель не может быть равен нулю!" << std::endl;
            denominator = 1;
        }

        int gcd = findGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        // Знаменатель всегда положительный
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Конструктор с параметрами (использует список инициализации)
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            std::cerr << "Ошибка: Знаменатель не может быть равен нулю! Установлено значение 1." << std::endl;
            denominator = 1;
        }
        reduce();
    }

    // Конструктор по умолчанию (делегирует конструктору с параметрами)
    Fraction() : Fraction(0, 1) {}

    // Вывод на экран
    void display() const {
        if (denominator == 1) {
            std::cout << numerator;
        }
        else if (numerator == 0) {
            std::cout << 0;
        }
        else {
            std::cout << numerator << "/" << denominator;
        }
    }

    // Сложение дроби с дробью
    Fraction* add(const Fraction& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator = denominator * other.denominator;
        reduce();
        return this;
    }

    // Вычитание дроби с дробью
    Fraction* subtract(const Fraction& other) {
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator = denominator * other.denominator;
        reduce();
        return this;
    }

    // Умножение дроби с дробью
    Fraction* multiply(const Fraction& other) {
        numerator = numerator * other.numerator;
        denominator = denominator * other.denominator;
        reduce();
        return this;
    }

    // Сложение дроби с целым числом
    Fraction* add(int integer) {
        numerator = numerator + integer * denominator;
        reduce();
        return this;
    }

    // Вычитание дроби с целым числом
    Fraction* subtract(int integer) {
        numerator = numerator - integer * denominator;
        reduce();
        return this;
    }

    // Умножение дроби с целым числом
    Fraction* multiply(int integer) {
        numerator = numerator * integer;
        reduce();
        return this;
    }

    // Геттеры для получения значений
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
};

// Пример использования
int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "=== Тестирование класса Дробь ===" << std::endl << std::endl;

    // Тестирование конструкторов
    Fraction f1(2, 4);
    Fraction f2(3, 6);
    Fraction f3;

    std::cout << "f1 = ";
    f1.display();
    std::cout << " (2/4 сократилась до 1/2)" << std::endl;

    std::cout << "f2 = ";
    f2.display();
    std::cout << " (3/6 сократилась до 1/2)" << std::endl;

    std::cout << "f3 = ";
    f3.display();
    std::cout << " (по умолчанию)" << std::endl << std::endl;

    // Тестирование цепочек вызовов с дробями
    Fraction f4(1, 3);
    Fraction f5(1, 6);

    std::cout << "f4 = ";
    f4.display();
    std::cout << ", f5 = ";
    f5.display();
    std::cout << std::endl;

    Fraction f4_original = f4;

    f4.add(f5)->subtract(f5)->multiply(f4_original);
    std::cout << "После цепочки: f4 + f5 - f5 * f4 = ";
    f4.display();
    std::cout << std::endl << std::endl;

    // Тестирование операций с целыми числами
    Fraction f6(2, 3);
    std::cout << "f6 = ";
    f6.display();
    std::cout << std::endl;

    f6.add(2)->subtract(1)->multiply(3);
    std::cout << "После цепочки: ((f6 + 2) - 1) * 3 = ";
    f6.display();
    std::cout << std::endl << std::endl;

    // Дополнительные тесты
    Fraction f7(4, 6);
    Fraction f8(5, 10);

    std::cout << "f7 = ";
    f7.display();
    std::cout << ", f8 = ";
    f8.display();
    std::cout << std::endl;

    f7.add(f8);
    std::cout << "f7 + f8 = ";
    f7.display();
    std::cout << std::endl;

    Fraction f9(2, 3);
    f9.multiply(3);
    std::cout << "2/3 * 3 = ";
    f9.display();
    std::cout << std::endl;

    Fraction f10(12, 18);
    std::cout << "\n12/18 сократилась = ";
    f10.display();
    std::cout << std::endl;

    return 0;
}