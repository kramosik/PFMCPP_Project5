#pragma once

#include <string>
#include <cassert>
#include "LeakedObjectDetector.h"

struct Screen
{
    Screen();
    Screen(int height, int width, const std::string& manufacturer);
    ~Screen();

    int getNumofPixels();
    bool coordInBound(int x, int y);

    void memberFunc();

    int height = 0;
    int width = 0;
    std::string manufacturer;

    JUCE_LEAK_DETECTOR(Screen)
};
