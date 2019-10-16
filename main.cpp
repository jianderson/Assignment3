
#include "SyntaxCheck.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    bool keepRunning = true;
    //assign the command line arguement to the filename
    string fileName = argv[1];

cout << endl;
while(keepRunning)
{
    keepRunning = false;
    //create syntax check object
    SyntaxCheck sc = SyntaxCheck(fileName);
    //call check the syntax method on the object
    bool answer = sc.checkTheSyntax(sc.stringCode);

    if (answer == false)
        keepRunning = sc.FinalResults();
//check if the user wants to input another value
        if(keepRunning == true)
        {
            cout << "Would you like to input another file (Y or N): " << endl;
            bool yesOrNo;
            string yorn;
            cin >> yorn;
            if(yorn == "Y" || yorn == "y" || yorn == "yes" || yorn == "Yes")
            {
                //if so ask for file name an assign it to fileName
                cout << "Ok. What is the name of the file you would like to analyze: " << endl;
                cin >> fileName;
                keepRunning = true;
                continue;
            }
            else
            {
                //if not end the program
                cout << "Okay, goodbye!" << endl;
                keepRunning = false;
            }

        }

    cout << endl;
}

}
