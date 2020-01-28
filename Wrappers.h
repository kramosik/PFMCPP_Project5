#pragma once

struct Page;
struct Lamp;
struct Metronome;
struct Screen;
struct File;

struct PageWrapper
{
    PageWrapper(Page* ptr);
    ~PageWrapper();

    Page* ptrToPage = nullptr;
};

struct LampWrapper
{
    LampWrapper(Lamp* ptr);
    ~LampWrapper();

    Lamp* ptrToLamp = nullptr;
};


struct MetronomeWrapper
{
    MetronomeWrapper(Metronome* ptr);
    ~MetronomeWrapper();

    Metronome* ptrToMetronome = nullptr;
};

struct ScreenWrapper
{
    ScreenWrapper(Screen* ptr);
    ~ScreenWrapper();

    Screen* ptrToScreen = nullptr;
};

struct FileWrapper
{
    FileWrapper(File* ptr);
    ~FileWrapper();

    File* ptrToFile = nullptr;
};
