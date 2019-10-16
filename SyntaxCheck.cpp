#include <iostream>
#include <fstream>
#include "SyntaxCheck.h"

using namespace std;
//constructor to declare the file and line count
SyntaxCheck::SyntaxCheck(string userFile)
{
    lineCount = 0;

    this->userFile = userFile;
    ReadFile(userFile);

}

SyntaxCheck::~SyntaxCheck()
{
    //delete this;
}
//method to read in the file
void SyntaxCheck::ReadFile(string userFile)
{
    string line;
    ifstream myfile;
    //open file
    myfile.open(userFile);
    if (myfile)
    {
        ////iterate through the lines
        string tempLineNumVariable = "";
        while ( getline (myfile,line) )
        {
            //through each iteration, increment the line count
            lineCount++;
            //make sure the line is not a comment
            if(line.substr(0, 2) == "//")
                continue;

            int totalCharCountinLine = 0;
            int totalCharDELCOUNT = 0;



            //iterate through each letter
            for(int i = 0; i < line.length(); ++i)
            {

                int quoteOpenIndex = -1;
                int quoteCloseIndex = -1;
                //check for delimeters inside of quotes
                if(line[i] == '\"' || line[i] == '\'')
                {
                    quoteOpenIndex = i;
                    //find second quot3e
                    for(int j = i+1; j < line.length(); ++j)
                    {
                        if(line[j] == '\"' || line[j] == '\'')
                        {
                            quoteCloseIndex = j;
                        }
                    }
                }
                //if its in quotes break out of for loop
            if(i >= quoteOpenIndex && i <= quoteCloseIndex)
            {
                break;
            }
            else
            {
                //if not add the delimeter to the stringcode
                if(line[i] == '{' || line[i] == '[' || line[i] == '(' || line[i] == '}' || line[i] == ']' || line[i] == ')')
                {
                    stringCode += line[i];
                }
            }

            }

//iterate through the line
            for(int i = 0; i < line.length(); ++i)
            {
                int quoteOpenIndex = -1;
                int quoteCloseIndex = -1;
//again look for quotes
                if(line[i] == '\"' || line[i] == '\'')
                {
                    quoteOpenIndex = i;
                    for(int j = i+1; j < line.length(); ++j)
                    {
                        //look for end quotes
                        if(line[j] == '\"' || line[j] == '\'')
                        {
                            quoteCloseIndex = j;
                        }
                    }
                }
//if its in quotes break
            if(i >= quoteOpenIndex && i <= quoteCloseIndex)
            {
                break;
            }
            else
            {
                //if its not in quotes add to the total char line
                if(line[i] == '{' || line[i] == '[' || line[i] == '(')
                    totalCharCountinLine++;
            }

            }
//push the amount of chars for each line into the stack
            for(int i = 0; i < totalCharCountinLine; ++i)
            {
            lineNum.push(lineCount);
            }


//do the same thing as above but for the closed side of the delimeters
            for(int i = 0; i < line.length(); ++i)
            {
                int quoteOpenIndex = -1;
                int quoteCloseIndex = -1;

                if(line[i] == '\"' || line[i] == '\'')
                {
                    quoteOpenIndex = i;
                    for(int j = i+1; j < line.length(); ++j)
                    {
                        if(line[j] == '\"' || line[j] == '\'')
                        {
                            quoteCloseIndex = j;
                        }
                    }
                }
            if(i >= quoteOpenIndex && i <= quoteCloseIndex)
            {
                break;
            }
            else
            {
                if(line[i] == '}' || line[i] == ']' || line[i] == ')')
                    totalCharDELCOUNT++;
            }

            }

            for(int i = 0; i < totalCharDELCOUNT; ++i)
            {
                lineNumBackDLim.push(lineCount);

            }

        }

//flip the information in the stack
        GenStack<int> tempNums = GenStack<int>();

        while(lineNum.isEmpty() == false)
        {
            int temp = lineNum.pop();

            tempNums.push(temp);
        }
        lineNum = tempNums;
//flip the information in the stack
        GenStack<int> tempBack = GenStack<int>();
        while(lineNumBackDLim.isEmpty() == false)
        {
            int temp = lineNumBackDLim.pop();
            tempBack.push(temp);

        }

        lineNumBackDLim = tempBack;
//close the file
        myfile.close();

    }
//if you cant open the file through a runtime error
    else
    {
        throw runtime_error ("The file was not able to be opened.");
    }

}

//check the syntx with this method
bool SyntaxCheck::checkTheSyntax(string fullCodeString)
{

    bool answer = false;
//start iterating through the code and create delimeter objects
    for(int i = 0; i < fullCodeString.size(); ++i)
    {
        if(fullCodeString[i] == '{')
        {

            DelimeterCheck* del = new DelimeterCheck('{', lineNum.pop());
            delCheckStack.push(del);


        }
        else if(fullCodeString[i]== '[')
        {
            DelimeterCheck* del = new DelimeterCheck('[', lineNum.pop());
            delCheckStack.push(del);


        }
        else if(fullCodeString[i] == '(')
        {


            DelimeterCheck* del = new DelimeterCheck('(', lineNum.pop());
            delCheckStack.push(del);

        }
//check for closed bracks and thenm iterate through the stack of objects and find the closest one that pairs to match
        else if(fullCodeString[i] == '}')
        {
            bool foundMatch = false;

            for(int i = delCheckStack.top; i >= 0; --i)
            {
                if(delCheckStack.myArray[i]->openDel == '{')
                {
                    if(delCheckStack.myArray[i]->isClosed == false)
                    {
                        //change the boolean to matched
                        delCheckStack.myArray[i]->ChangeClosedTrue();
                        lineNumBackDLim.pop();
                        foundMatch = true;
                        break;
                    }
                }

            }
            //if its not matched that means it is an unmatched closed
            if(foundMatch == false)
            {
            cout << "There is an unmatched Delimeter!" << endl;
            cout << "The unmatched delimeter is } at line " << lineNumBackDLim.pop() << endl;
            answer = true;
            }


        }
        //look for match
        else if(fullCodeString[i] == ']')
        {
            bool foundMatch = false;
            for(int i = delCheckStack.top; i >= 0; --i)
            {
                if(delCheckStack.myArray[i]->openDel == '[')
                {
                    if(delCheckStack.myArray[i]->isClosed == false)
                    {
                        delCheckStack.myArray[i]->ChangeClosedTrue();
                        lineNumBackDLim.pop();
                        foundMatch = true;
                        break;
                    }
                }
            }
            if(foundMatch == false)
            {
//if it is not matched it is an unmatched closed
                cout << "There is an unmatched Delimeter!" << endl;
                cout << "The unmatched delimeter is ] at line " << lineNumBackDLim.pop();
                answer = true;
            }


        }
        //look for match
        else if(fullCodeString[i] == ')')
        {

            bool foundMatch = false;
            for(int i = delCheckStack.top; i >= 0; --i)
            {
                if(delCheckStack.myArray[i]->openDel == '(')
                {
                    if(delCheckStack.myArray[i]->isClosed == false)
                    {
                        delCheckStack.myArray[i]->ChangeClosedTrue();
                        lineNumBackDLim.pop();
                        foundMatch = true;
                        break;
                    }



                }
            }
//if it is not matched then it is an unmatched closed
            if(foundMatch == false)
            {
                cout << "There is an unmatched Delimeter!" << endl;
                cout << "The unmatched delimeter is ) at line " << lineNumBackDLim.pop() << endl;
                answer = true;
            }


        }

    }
    return answer;

}
//final results method to check for an objects with a false boolean match
bool SyntaxCheck::FinalResults()
{
    bool tryAgain = false;

    for(int i = 0; i <= delCheckStack.top; ++i)
    {

        DelimeterCheck* temp = delCheckStack.myArray[i];

        if (temp->isClosed == false)
        {
            cout << "There was an unmatched delimter! " << endl;
            cout << "The unmatched Delimeter was " << temp->openDel << " at line " << temp->lineNumOfOpen << "." << endl;
            return tryAgain;
        }


    }
//if there is no unmatched than the suntax is correct
    cout << "The syntax was all correct!" << endl;
    tryAgain = true;
    return tryAgain;

}
