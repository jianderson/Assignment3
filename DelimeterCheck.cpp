#include "DelimeterCheck.h"
#include <iostream>

using namespace std;
//constructor for a Delimeter check object
DelimeterCheck::DelimeterCheck(char openDel, int lineNumOfOpen)
{
    this->openDel = openDel;
    isClosed = false;
    this->lineNumOfOpen = lineNumOfOpen;
}

DelimeterCheck::~DelimeterCheck()
{
    //delete this;
}
//method to change the boolean value to true
void DelimeterCheck::ChangeClosedTrue()
{
    this->isClosed = true;
}
