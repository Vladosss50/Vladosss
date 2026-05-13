#include "Employee.h"
#include <iomanip>

// ==================== Employee ====================
Employee::Employee(const string& n, int i, double salary)
    : name(n), id(i), baseSalary(salary) {
}

Employee::~Employee() {}

double Employee::calculateSalary() const {
    return baseSalary;
}

void Employee::getInfo() const {
    cout << "Сотрудник: " << name << ", ID: " << id
        << ", Зарплата: " << fixed << setprecision(0) << calculateSalary() << " руб.";
}

// ==================== Manager ====================
Manager::Manager(const string& n, int i, double salary, double bonus, int subs)
    : Employee(n, i, salary), bonusPercent(bonus), subordinates(subs) {
}

Manager::~Manager() {}

// Базовая + бонус% + 100 за каждого подчинённого
double Manager::calculateSalary() const {
    return baseSalary + (bonusPercent / 100.0) * baseSalary + subordinates * 100;
}

void Manager::getInfo() const {
    cout << "Менеджер: " << name << ", ID: " << id
        << ", Подчинённых: " << subordinates
        << ", Зарплата: " << fixed << setprecision(0) << calculateSalary() << " руб.";
}

// ==================== Developer ====================
Developer::Developer(const string& n, int i, double salary, const string& lang, int exp)
    : Employee(n, i, salary), language(lang), experience(exp) {
}

Developer::~Developer() {}

// Базовая + опыт * 5000
double Developer::calculateSalary() const {
    return baseSalary + experience * 5000;
}

void Developer::getInfo() const {
    cout << "Разработчик: " << name << ", ID: " << id
        << ", Язык: " << language << ", Опыт: " << experience << " лет"
        << ", Зарплата: " << fixed << setprecision(0) << calculateSalary() << " руб.";
}

// ==================== Intern ====================
Intern::Intern(const string& n, int i, double salary, bool mentor)
    : Employee(n, i, salary), hasMentor(mentor) {
}

Intern::~Intern() {}

// 70% от базовой
double Intern::calculateSalary() const {
    return baseSalary * 0.7;
}

void Intern::getInfo() const {
    cout << "Стажёр: " << name << ", ID: " << id
        << ", Наставник: " << (hasMentor ? "Есть" : "Нет")
        << ", Зарплата: " << fixed << setprecision(0) << calculateSalary() << " руб.";
}

// ==================== Department ====================
Department::Department(const string& deptName) : name(deptName) {}

Department::~Department() {
    for (Employee* emp : employees) {
        delete emp;
    }
}

void Department::addEmployee(Employee* emp) {
    employees.push_back(emp);
}

void Department::removeEmployee(int id) {
    auto it = remove_if(employees.begin(), employees.end(),
        [id](Employee* emp) { return emp->getId() == id; });

    for (auto it2 = it; it2 != employees.end(); ++it2) {
        delete* it2;
    }
    employees.erase(it, employees.end());
}

double Department::getTotalSalary() const {
    double total = 0;
    for (Employee* emp : employees) {
        total += emp->calculateSalary();
    }
    return total;
}

Employee* Department::getMaxSalaryEmployee() const {
    if (employees.empty()) return nullptr;

    return *max_element(employees.begin(), employees.end(),
        [](Employee* a, Employee* b) {
            return a->calculateSalary() < b->calculateSalary();
        });
}

void Department::sortBySalary() {
    sort(employees.begin(), employees.end(),
        [](Employee* a, Employee* b) {
            return a->calculateSalary() > b->calculateSalary();
        });
}

void Department::printAll() const {
    cout << "\n=== Департамент: " << name << " ===" << endl;
    cout << "Общая зарплата: " << fixed << setprecision(0) << getTotalSalary() << " руб." << endl;
    cout << string(50, '-') << endl;
    for (Employee* emp : employees) {
        cout << "  ";
        emp->getInfo();
        cout << endl;
    }
}