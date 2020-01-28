#pragma once

#include <string>
#include <cassert>
#include "LeakedObjectDetector.h"

struct File
{
    File();
    File(const std::string& filename, const std::string& directory, long sizeInBytes);
    ~File();

    std::string getPath();
    double sizeInKB();

    void memberFunc();

    std::string filename;
    std::string directory;
    double sizeInBytes = 0;

    JUCE_LEAK_DETECTOR(File)
};
