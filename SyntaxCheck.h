#include <iostream>
#include "GenStack.h"
#include "DelimeterCheck.h"
using namespace std;

class SyntaxCheck
{
public:
    //constuctors
    SyntaxCheck(string userFile);
    ~SyntaxCheck();
//methods
    void ReadFile(string userFile);

    string getStringLine();
    bool checkTheSyntax(string fullCode);
    bool FinalResults();
//string to hold code
    string fullCode;

//declare all the stacks to be used
    GenStack<int> lineNumReverser;
    GenStack<DelimeterCheck*> delCheckStack;
    GenStack<int> lineNum;
    GenStack<int> lineNumBackDLimReverse;
    GenStack<int> lineNumBackDLim;

//declare all vaiables
    int lineCount;
    string userFile;
    string stringCode;
    string stringLine;
};
