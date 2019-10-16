#include <iostream>

using namespace std;

class DelimeterCheck
{
public:
//decalre constructors and methods
    DelimeterCheck(char openDel, int lineNumOfOpen);
    ~DelimeterCheck();
    void ChangeClosedTrue();
//declare variables
    char openDel;
    bool isClosed;
    int lineNumOfOpen;

};
