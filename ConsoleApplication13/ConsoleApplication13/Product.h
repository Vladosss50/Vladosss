#pragma once

// Товар на складе — простой класс с публичными полями
class Product {
public:
    char name[50];      // Название
    int quantity;       // Кол-во
    double price;       // Цена за штуку

    void print();           // Показать информацию
    double getTotalCost();  // Итоговая стоимость
};