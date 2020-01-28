/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4

 Don't #include what you don't use

 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and
 header files. Add files via the pane on the left.

 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )

 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )

 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need
 to move them to Wrappers.cpp

 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h

 6) for every .cpp file you have to make, insert it into the .replit file after
 'main.cpp'.  Don't forget the spaces between file names. If you need help with
 this step, send me a DM.

 7) click the [run] button.  Clear up any errors or warnings as best you can.

 Commit your changes by clicking on the Source Control panel on the left,
 entering a message, and click [Commit and push].

 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.

 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you
 shouldn't need to edit any of it. just split it up into source files and
 provide the appropriate #include directives.
 */
#include <iostream>
#include "Wrappers.h"
#include "Page.h"
#include "Lamp.h"
#include "Metronome.h"
#include "Screen.h"
#include "File.h"

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
