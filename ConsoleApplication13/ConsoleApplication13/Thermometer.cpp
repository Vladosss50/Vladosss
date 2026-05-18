#include "Thermometer.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// Конструктор по умолчанию
Thermometer::Thermometer() {
    celsius = 0.0;
    location = new char[20];
    strcpy_s(location, 20, "Неизвестно");
}

// Только температура
Thermometer::Thermometer(double tempCelsius) {
    celsius = tempCelsius;
    location = new char[20];
    strcpy_s(location, 20, "Неизвестно");
}

// Полная версия
Thermometer::Thermometer(const char* place, double tempCelsius) {
    celsius = tempCelsius;
    size_t len = strlen(place);
    location = new char[len + 1];
    strcpy_s(location, len + 1, place);
}

Thermometer::~Thermometer() {
    delete[] location;
}

double Thermometer::getCelsius() {
    return celsius;
}

double Thermometer::getFahrenheit() {
    return celsius * 9.0 / 5.0 + 32;
}

void Thermometer::printInfo() {
    cout << "Место: " << location
        << " | Температура: " << fixed << setprecision(1)
        << celsius << "°C / " << getFahrenheit() << "°F" << endl;
}