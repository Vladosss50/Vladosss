#include "Product.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Product::print() {
    cout << "Товар: " << name << endl;
    cout << "Количество: " << quantity << " шт." << endl;
    cout << "Цена: " << fixed << setprecision(2) << price << " руб." << endl;
}

double Product::getTotalCost() {
    return quantity * price;
}