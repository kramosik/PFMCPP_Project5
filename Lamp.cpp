#include "Lamp.h"
#include <iostream>

Lamp::Lamp() : color("white") {}
Lamp::Lamp(float mBrightness, float mBattery, const std::string& mColor)
    : brightness(mBrightness), battery(mBattery), color(mColor)
{
}
Lamp::~Lamp() {}

std::string Lamp::getLight()
{
    return color + ": " + std::to_string(brightness);
}
void Lamp::toggle()
{
    // brightness must be positive
    if (brightness <= 1e-7f)
    {
        brightness = 100;
    }
    else
    {
        brightness = 0;
    }
}

void Lamp::memberFunc()
{
    std::cout << "Lamp getLight(): " << this->getLight()
              << "\nLamp battery: " << this->battery << '\n';
}
