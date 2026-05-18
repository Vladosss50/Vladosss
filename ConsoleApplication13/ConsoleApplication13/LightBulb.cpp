#include "LightBulb.h"
#include <iostream>
using namespace std;

void LightBulb::turnOn() {
    isOn = true;
    cout << "Лампочка -> ВКЛ" << endl;
}

void LightBulb::turnOff() {
    isOn = false;
    cout << "Лампочка -> ВЫКЛ" << endl;
}

void LightBulb::toggle() {
    isOn = !isOn;
    cout << "Лампочка переключена -> " << (isOn ? "ВКЛ" : "ВЫКЛ") << endl;
}

const char* LightBulb::getState() {
    return isOn ? "ON" : "OFF";
}