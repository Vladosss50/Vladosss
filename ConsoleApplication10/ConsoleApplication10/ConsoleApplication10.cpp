#include <iostream>
#include <iomanip>
#include "Shape.h"
#include "Employee.h"

using namespace std;

void separator(const string& title) {
    cout << "\n============================================================" << endl;
    cout << "  " << title << endl;
    cout << "============================================================" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // ========== ЗАДАНИЕ 2.1: Фигуры ==========
    separator("ЗАДАНИЕ 2.1: Геометрические фигуры");

    // Полиморфизм - указатели базового класса на объекты производных
    Shape* figury[] = {
        new Circle(5),
        new Rectangle(3, 4),
        new Triangle(3, 4, 5)
    };

    cout << "Созданные фигуры:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  ";
        figury[i]->vyvod();
    }

    cout << "\nВсего создано фигур: " << Shape::getCount() << endl;

    // Очистка памяти
    for (int i = 0; i < 3; i++) {
        delete figury[i];
    }

    // ========== ЗАДАНИЕ 2.2: Сотрудники ==========
    separator("ЗАДАНИЕ 2.2: Иерархия сотрудников");

    Department dept("IT Департамент");

    // Добавляем сотрудников
    dept.addEmployee(new Manager("Алиса", 1, 50000, 20, 5));
    dept.addEmployee(new Developer("Боб", 2, 40000, "C++", 3));
    dept.addEmployee(new Developer("Чарли", 3, 45000, "Python", 4));
    dept.addEmployee(new Intern("Диана", 4, 30000, true));
    dept.addEmployee(new Intern("Евгений", 5, 28000, false));

    dept.printAll();

    // Сотрудник с максимальной зарплатой
    Employee* maxSalary = dept.getMaxSalaryEmployee();
    if (maxSalary) {
        cout << "\nСотрудник с максимальной зарплатой:" << endl;
        cout << "  ";
        maxSalary->getInfo();
        cout << endl;
    }

    // Сортировка по зарплате
    cout << "\nСортировка по убыванию зарплаты:" << endl;
    dept.sortBySalary();
    dept.printAll();

    // Удаление сотрудника
    cout << "\nУдаление сотрудника с ID 2 (Боб)..." << endl;
    dept.removeEmployee(2);
    dept.printAll();

    cout << "\n============================================================" << endl;
    cout << "  Проект 2 завершён!" << endl;
    cout << "============================================================" << endl;

    return 0;
}