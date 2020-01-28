#pragma once

#include <string>
#include <cassert>
#include "LeakedObjectDetector.h"

struct Metronome
{
    Metronome();
    Metronome(float tempo, int beatsPerMeasure, bool started);
    ~Metronome();

    std::string getStatus();
    void toggle();

    void memberFunc();

    float tempo = 120;
    int beatsPerMeasure = 4;
    bool started = false;

    JUCE_LEAK_DETECTOR(Metronome)
};
