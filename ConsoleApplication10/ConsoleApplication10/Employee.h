#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Базовый класс Сотрудник
class Employee {
protected:
    string name;
    int id;
    double baseSalary;

public:
    Employee(const string& n, int i, double salary);
    virtual ~Employee();

    virtual double calculateSalary() const;
    virtual void getInfo() const;

    int getId() const { return id; }
};

// Менеджер
class Manager : public Employee {
private:
    double bonusPercent;   // Бонус в процентах
    int subordinates;      // Количество подчинённых

public:
    Manager(const string& n, int i, double salary, double bonus, int subs);
    ~Manager();

    double calculateSalary() const override;
    void getInfo() const override;
};

// Разработчик
class Developer : public Employee {
private:
    string language;
    int experience;  // Опыт в годах

public:
    Developer(const string& n, int i, double salary, const string& lang, int exp);
    ~Developer();

    double calculateSalary() const override;
    void getInfo() const override;
};

// Стажёр
class Intern : public Employee {
private:
    bool hasMentor;

public:
    Intern(const string& n, int i, double salary, bool mentor);
    ~Intern();

    double calculateSalary() const override;
    void getInfo() const override;
};

// Департамент
class Department {
private:
    vector<Employee*> employees;
    string name;

public:
    Department(const string& deptName);
    ~Department();

    void addEmployee(Employee* emp);
    void removeEmployee(int id);
    double getTotalSalary() const;
    Employee* getMaxSalaryEmployee() const;
    void sortBySalary();
    void printAll() const;
};

#endif