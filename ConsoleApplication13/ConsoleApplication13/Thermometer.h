#pragma once

// Термометр — перегрузка конструкторов (3 варианта)
class Thermometer {
private:
    double celsius;
    char* location;

public:
    Thermometer();                           // По умолчанию: 0°C, "Неизвестно"
    Thermometer(double tempCelsius);         // Только температура
    Thermometer(const char* place, double tempCelsius); // Всё вместе

    ~Thermometer();

    double getCelsius();
    double getFahrenheit();  // C → F
    void printInfo();
};