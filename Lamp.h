#pragma once

#include <string>
#include <cassert>
#include "LeakedObjectDetector.h"

struct Lamp
{
    Lamp();
    Lamp(float brightness, float battery, const std::string& color);
    ~Lamp();

    std::string getLight();
    void toggle();

    void memberFunc();

    float brightness = 0;
    float battery = 100;
    std::string color;

    JUCE_LEAK_DETECTOR(Lamp)
};
