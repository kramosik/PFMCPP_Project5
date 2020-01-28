#pragma once

#include <string>
#include <cassert>
#include "LeakedObjectDetector.h"

struct Page
{
    Page();
    Page(int pageNumber, const std::string& chapter, const std::string& content);
    ~Page();

    std::string getText();
    std::string getPageNumber();

    void memberFunc();

    int pageNumber = 0;
    std::string chapter;
    std::string content;

    JUCE_LEAK_DETECTOR(Page)
};
