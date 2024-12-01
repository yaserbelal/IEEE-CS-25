#include <iostream>
#include <string>
using namespace std;

int main()
{
    char direction;
    string message;

    cin >> direction >> message;

    string row1 = "qwertyuiop";
    string row2 = "asdfghjkl;";
    string row3 = "zxcvbnm,./";

    string correctedMessage = "";

    for (char ch : message)
    {
        size_t pos;
        if ((pos = row1.find(ch)) != string::npos)
        {
            if (direction == 'R')
            {
                correctedMessage += row1[pos - 1];
            }
            else
            {
                correctedMessage += row1[pos + 1];
            }
        }
        else if ((pos = row2.find(ch)) != string::npos)
        {
            if (direction == 'R')
            {
                correctedMessage += row2[pos - 1];
            }
            else
            {
                correctedMessage += row2[pos + 1];
            }
        }
        else if ((pos = row3.find(ch)) != string::npos)
        {
            if (direction == 'R')
            {
                correctedMessage += row3[pos - 1];
            }
            else
            {
                correctedMessage += row3[pos + 1];
            }
        }
    }
    cout << correctedMessage;

    return 0;
}
