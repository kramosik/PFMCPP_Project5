#include "Metronome.h"
#include <iostream>
#include <sstream>

Metronome::Metronome() {}
Metronome::Metronome(float mTempo, int mBeatsPerMeasure, bool mStarted)
    : tempo(mTempo), beatsPerMeasure(mBeatsPerMeasure), started(mStarted) {}
Metronome::~Metronome() {}

std::string Metronome::getStatus()
{
    std::ostringstream os;
    if (started)
    {
        for (int i = 0; i < tempo; i += 1)
        {
            if (i % beatsPerMeasure == 0)
            {
                os << 'x';
            }
            else
            {
                os << '.';
            }
        }
    }
    else
    {
        os << "metronome not started\n";
    }
    return os.str();
}
void Metronome::toggle() { started = !started; }

void Metronome::memberFunc()
{
    std::cout << "Metronome getStatus(): " << this->getStatus()
              << "\nMetronome tempo: " << this->tempo << '\n';
}
