#include "File.h"
#include <iostream>

File::File() : filename(""), directory("") {}
File::File(const std::string& mFilename, const std::string& mDirectory,
           long mSizeInBytes)
    : filename(mFilename), directory(mDirectory), sizeInBytes(mSizeInBytes)
{
}
File::~File() {}

std::string File::getPath() { return directory + "/" + filename; }
double File::sizeInKB() { return sizeInBytes / 1024.0; }

void File::memberFunc()
{
    std::cout << "File getPath(): " << this->getPath()
              << "\nFile sizeInBytes: " << this->sizeInBytes << '\n';
}
