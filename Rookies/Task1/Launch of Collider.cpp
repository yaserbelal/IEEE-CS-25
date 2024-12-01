#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    char *directions = new char[size];
    int *pos = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> directions[i];
    }

    for (int i = 0; i < size; i++)
    {
        cin >> pos[i];
    }

    int minTime = -1;

    for (int i = 0; i < size - 1; i++)
    {
        if (directions[i] == 'R' && directions[i + 1] == 'L')
        {
            int time = (pos[i + 1] - pos[i]) / 2;
            if (minTime == -1 || time < minTime)
            {
                minTime = time;
            }
        }
    }

    cout << minTime;

    return 0;
}
