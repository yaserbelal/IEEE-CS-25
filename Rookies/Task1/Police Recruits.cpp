#include <iostream>
using namespace std;
int main()
{
    int size;
    cin >> size;
    int officers = 0;
    int crimes = 0;

    int *array = new int[size];
    for (int i = 0; i < size; ++i)
    {
        cin >> array[i];
    }

    for (int i = 0; i < size; ++i)
    {
        if (array[i] == -1)
        { 
            if (officers > 0)
            {
                officers--; 
            }
            else
            {
                crimes++; 
            }
        }
        else
        { 
            officers += array[i];
        }
    }

    cout << crimes;
    return 0;
}
