#include "Page.h"
#include <iostream>

Page::Page() : chapter(""), content("") {}
Page::Page(int mPageNumber, const std::string& mChapter,
           const std::string& mContent)
    : pageNumber(mPageNumber), chapter(mChapter), content(mContent) {}
Page::~Page() {}

std::string Page::getText()
{
    return chapter + '\n' + content + '\n' + getPageNumber() + '\n';
}

std::string Page::getPageNumber() { return std::to_string(pageNumber); }

void Page::memberFunc()
{
    std::cout << "Page getText(): " << this->getText()
              << "Page pageNumber: " << this->pageNumber << '\n';
}
