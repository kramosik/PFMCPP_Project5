/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */
#include <cassert>
#include "LeakedObjectDetector.h"
#include <iostream>

/*
 UDT 1:
 */
#include <string>
struct Page
{
    Page() : chapter(""), content("") {}
    Page(int mPageNumber, std::string mChapter, std::string mContent)
        : pageNumber(mPageNumber), chapter(mChapter), content(mContent)
    {
    }
    ~Page() {}

    std::string getText()
    {
        return chapter + '\n' + content + '\n' + getPageNumber() + '\n';
    }
    std::string getPageNumber() { return std::to_string(pageNumber); }

    void memberFunc()
    {
        std::cout << "Page getText(): " << this->getText()
                  << "Page pageNumber: " << this->pageNumber << '\n';
    }

    int pageNumber = 0;
    std::string chapter;
    std::string content;

    JUCE_LEAK_DETECTOR(Page)
};

struct PageWrapper
{
    PageWrapper(Page* ptr) : ptrToPage(ptr) {}
    ~PageWrapper() { delete ptrToPage; }

    Page* ptrToPage = nullptr;
};

/*
 UDT 2:
 */
struct Lamp
{
    Lamp() : color("white") {}
    Lamp(float mBrightness, float mBattery, std::string mColor)
        : brightness(mBrightness), battery(mBattery), color(mColor)
    {
    }
    ~Lamp() {}

    std::string getLight() { return color + ": " + std::to_string(brightness); }
    void toggle()
    {
        // brightness must be positive
        if (brightness <= static_cast<float>(1e-7))
        {
            brightness = 100;
        }
        else
        {
            brightness = 0;
        }
    }

    void memberFunc()
    {
        std::cout << "Lamp getLight(): " << this->getLight()
                  << "\nLamp battery: " << this->battery << '\n';
    }

    float brightness = 0;
    float battery = 100;
    std::string color;

    JUCE_LEAK_DETECTOR(Lamp)
};

struct LampWrapper
{
    LampWrapper(Lamp* ptr) : ptrToLamp(ptr) {}
    ~LampWrapper() { delete ptrToLamp; }

    Lamp* ptrToLamp = nullptr;
};

/*
 UDT 3:
 */
#include <sstream>
struct Metronome
{
    Metronome() {}
    Metronome(float mTempo, int mBeatsPerMeasure, bool mStarted)
        : tempo(mTempo), beatsPerMeasure(mBeatsPerMeasure), started(mStarted)
    {
    }
    ~Metronome() {}

    std::string getStatus()
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
    void toggle() { started = !started; }

    void memberFunc()
    {
        std::cout << "Metronome getStatus(): " << this->getStatus()
                  << "\nMetronome tempo: " << this->tempo << '\n';
    }

    float tempo = 120;
    int beatsPerMeasure = 4;
    bool started = false;

    JUCE_LEAK_DETECTOR(Metronome)
};

struct MetronomeWrapper
{
    MetronomeWrapper(Metronome* ptr) : ptrToMetronome(ptr) {}
    ~MetronomeWrapper() { delete ptrToMetronome; }

    Metronome* ptrToMetronome = nullptr;
};

/*
 UDT 4:
 */
struct Screen
{
    Screen() : manufacturer("") {}
    Screen(int mHeight, int mWidth, std::string mManufacturer)
        : height(mHeight), width(mWidth), manufacturer(mManufacturer)
    {
    }
    ~Screen() {}

    int getNumofPixels() { return height * width; }
    bool coordInBound(int x, int y)
    {
        return (x > 0 && x < width) && (y > 0 && y < height);
    }

    void memberFunc()
    {
        std::cout << "Screen coordInBound(): " << this->coordInBound(29, 309)
                  << "\nScreen manufacturer: " << this->manufacturer << '\n';
    }

    int height = 0;
    int width = 0;
    std::string manufacturer;

    JUCE_LEAK_DETECTOR(Screen)
};

struct ScreenWrapper
{
    ScreenWrapper(Screen* ptr) : ptrToScreen(ptr) {}
    ~ScreenWrapper() { delete ptrToScreen; }

    Screen* ptrToScreen = nullptr;
};

/*
 UDT 5:
 */
struct File
{
    File() : filename(""), directory("") {}
    File(std::string mFilename, std::string mDirectory, long mSizeInBytes)
        : filename(mFilename), directory(mDirectory), sizeInBytes(mSizeInBytes)
    {
    }
    ~File() {}

    std::string getPath() { return directory + "/" + filename; }
    double sizeInKB() { return sizeInBytes / 1024.0; }

    void memberFunc()
    {
        std::cout << "File getPath(): " << this->getPath()
                  << "\nFile sizeInBytes: " << this->sizeInBytes << '\n';
    }

    std::string filename;
    std::string directory;
    double sizeInBytes = 0;

    JUCE_LEAK_DETECTOR(File)
};

struct FileWrapper
{
    FileWrapper(File* ptr) : ptrToFile(ptr) {}
    ~FileWrapper() { delete ptrToFile; }

    File* ptrToFile = nullptr;
};

#include <iostream>
int main()
{
    // UDT 1:
    PageWrapper page {new Page(1, "Chapter 1", "Some random text")};
    std::cout << "page getText(): " << page.ptrToPage->getText()
              << "page pageNumber: " << page.ptrToPage->pageNumber << '\n';
    page.ptrToPage->memberFunc();

    // UDT 2:
    LampWrapper lamp {new Lamp(20, 50, "red")};
    std::cout << "lamp getLight(): " << lamp.ptrToLamp->getLight()
              << "\nlamp battery: " << lamp.ptrToLamp->battery << '\n';
    lamp.ptrToLamp->memberFunc();

    // UDT 3:
    MetronomeWrapper metronome {new Metronome(120, 4, true)};
    std::cout << "metronome getStatus(): "
              << metronome.ptrToMetronome->getStatus()
              << "\nmetronome tempo: " << metronome.ptrToMetronome->tempo
              << '\n';
    metronome.ptrToMetronome->memberFunc();

    // UDT 4:
    ScreenWrapper screen {new Screen(300, 1000, "ASUS")};
    std::cout << "screen coordInBound(): "
              << screen.ptrToScreen->coordInBound(29, 309)
              << "\nscreen manufacturer: " << screen.ptrToScreen->manufacturer
              << '\n';
    screen.ptrToScreen->memberFunc();

    // UDT 5:
    FileWrapper file {new File("main.cpp", "/home", 10000)};
    std::cout << "file getPath(): " << file.ptrToFile->getPath()
              << "\nfile sizeInBytes: " << file.ptrToFile->sizeInBytes << '\n';
    file.ptrToFile->memberFunc();

    return 0;
}
