/*
 Chapter 3 Part 1 - Continuation of previous Task
 The 'this' keyword.
 The purpose of this task is to demonstrate the difference between using member
variables in member functions, vs. using member variables in free functions.

1) write 5 UDTs.
    a) declare and implement:
        default constructors,
        destructors,
        2+ member functions with an arbitrary number of parameters, and
        3+ member variables, initialized in-class
    b) the previous tasks required you to write std::cout statements in main()
that accessed the member variables, or printed out the results from calling
member functions. write 2 std::cout statements in main() that do this for each
UDT.

 2) For any std::cout statements you had in main() that accessed member
variables of your types or printed out the results of your member function
calls, a) write a member function that prints the same thing out, but uses the
proper techniques inside the member functions to access the same member
variables/functions. b) be explicit with your use of 'this->' in those member
functions so we see how you're accessing/calling those member variables and
functions *inside* c) call those member functions after your std::cout
statements in main().  see the example below as to what I'm expecting you to
write.

 3) if you didn't have any std::cout statements in main() that accessed member
variables: write some. then do 2a) 2b) 2c)

 4) After you finish, click the [run] button.  Clear up any errors or warnings
as best you can.

 Commit your changes by clicking on the Source Control panel on the left,
entering a message, and click [Commit and push].

 Wait for my code review.
 */

/*
 example:
 */
#include <iostream>
namespace example
{
struct MyFoo
{
    MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
    void memberFunc()
    {
        std::cout << "MyFoo returnValue(): " << this->returnValue()
                  << " and MyFoo memberVariable: " << this->memberVariable
                  << std::endl;
    } // 2a)
    int returnValue() { return 3; }
    float memberVariable = 3.14f;
};
int main()
{
    MyFoo mf;
    std::cout << "mf returnValue(): " << mf.returnValue()
              << " and mf memberVariable: " << mf.memberVariable
              << std::endl; // 1b)
    mf.memberFunc();        // 2c)
    return 0;
}
} // namespace example

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
};

#include <iostream>
int main()
{
    example::main();

    // UDT 1:
    Page page {1, "Chapter 1", "Some random text"};
    std::cout << "page getText(): " << page.getText()
              << "page pageNumber: " << page.pageNumber << '\n';
    page.memberFunc();

    // UDT 2:
    Lamp lamp {20, 50, "red"};
    std::cout << "lamp getLight(): " << lamp.getLight()
              << "\nlamp battery: " << lamp.battery << '\n';
    lamp.memberFunc();

    // UDT 3:
    Metronome metronome {120, 4, true};
    std::cout << "metronome getStatus(): " << metronome.getStatus()
              << "\nmetronome tempo: " << metronome.tempo << '\n';
    metronome.memberFunc();

    // UDT 4:
    Screen screen {300, 1000, "ASUS"};
    std::cout << "screen coordInBound(): " << screen.coordInBound(29, 309)
              << "\nscreen manufacturer: " << screen.manufacturer << '\n';
    screen.memberFunc();

    // UDT 5:
    File file {"main.cpp", "/home", 10000};
    std::cout << "file getPath(): " << file.getPath()
              << "\nfile sizeInBytes: " << file.sizeInBytes << '\n';
    file.memberFunc();

    return 0;
}
