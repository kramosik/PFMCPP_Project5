#include "Wrappers.h"
#include "Page.h"
#include "Lamp.h"
#include "Metronome.h"
#include "Screen.h"
#include "File.h"

PageWrapper::PageWrapper(Page* ptr) : ptrToPage(ptr) {}
PageWrapper::~PageWrapper() { delete ptrToPage; }

LampWrapper::LampWrapper(Lamp* ptr) : ptrToLamp(ptr) {}
LampWrapper::~LampWrapper() { delete ptrToLamp; }

MetronomeWrapper::MetronomeWrapper(Metronome* ptr) : ptrToMetronome(ptr) {}
MetronomeWrapper::~MetronomeWrapper() { delete ptrToMetronome; }

ScreenWrapper::ScreenWrapper(Screen* ptr) : ptrToScreen(ptr) {}
ScreenWrapper::~ScreenWrapper() { delete ptrToScreen; }

FileWrapper::FileWrapper(File* ptr) : ptrToFile(ptr) {}
FileWrapper::~FileWrapper() { delete ptrToFile; }
