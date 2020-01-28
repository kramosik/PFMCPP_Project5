#include "Screen.h"
#include <iostream>

Screen::Screen() : manufacturer("") {}

Screen::Screen(int mHeight, int mWidth, const std::string& mManufacturer)
    : height(mHeight), width(mWidth), manufacturer(mManufacturer)
{
}
Screen::~Screen() {}

int Screen::getNumofPixels() { return height * width; }
bool Screen::coordInBound(int x, int y)
{
    return (x > 0 && x < width) && (y > 0 && y < height);
}

void Screen::memberFunc()
{
    std::cout << "Screen coordInBound(): " << this->coordInBound(29, 309)
              << "\nScreen manufacturer: " << this->manufacturer << '\n';
}
