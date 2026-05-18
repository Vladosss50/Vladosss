#include <iostream>
#include <cstring>
#include <iomanip>
#include <windows.h>

#include "Product.h"
#include "LightBulb.h"
#include "WebLink.h"
#include "BankAccount.h"
#include "Thermometer.h"

using namespace std;

// Разделитель задач
void sep(const char* title) {
    cout << "\n" << string(45, '-') << endl;
    cout << "[ЗАДАЧА] " << title << endl;
    cout << string(45, '-') << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // ========== 1. Товар ==========
    sep("Товар на складе");

    Product p;
    strcpy_s(p.name, 50, "Ноутбук");
    p.quantity = 8;
    p.price = 45000.0;

    p.print();
    cout << "Общая цена: " << fixed << setprecision(2) << p.getTotalCost() << " руб.\n";

    // ========== 2. Лампочка ==========
    sep("Лампочка");

    LightBulb bulb;
    bulb.turnOn();
    cout << "Сейчас: " << bulb.getState() << endl;

    bulb.toggle();
    cout << "Сейчас: " << bulb.getState() << endl;

    bulb.turnOff();
    cout << "Сейчас: " << bulb.getState() << endl;

    // ========== 3. Веб-ссылка ==========
    sep("Веб-ссылка");

    WebLink link("https://google.com", "Поисковик Google");
    link.print();

    // ========== 4. Банковский счёт ==========
    sep("Банковский счёт");

    BankAccount acc("Сидоров А.А.", 123456, 5000);
    acc.printInfo();

    acc.deposit(2500);
    cout << "Баланс: " << acc.getBalance() << " руб.\n";

    acc.withdraw(1000);
    cout << "Баланс: " << acc.getBalance() << " руб.\n";

    cout << "\nПробуем снять 10000 руб.\n";
    acc.withdraw(10000);

    // ========== 5. Термометр ==========
    sep("Термометр");

    Thermometer t1;
    Thermometer t2(30.5);
    Thermometer t3("Кухня", 22.0);

    cout << "t1: ";
    t1.printInfo();
    cout << "t2: ";
    t2.printInfo();
    cout << "t3: ";
    t3.printInfo();

    cout << "\n" << string(45, '-') << endl;
    cout << "[ГОТОВО] Программа завершена.\n";
    cout << string(45, '-') << endl;

    return 0;
}