#pragma once

// Ћампочка Ч пример инкапсул€ции
class LightBulb {
private:
    bool isOn = false;   // —осто€ние (выкл по умолчанию)

public:
    void turnOn();       // ¬кл
    void turnOff();      // ¬ыкл
    void toggle();       // ѕереключить

    const char* getState();  // "ON" или "OFF"
};