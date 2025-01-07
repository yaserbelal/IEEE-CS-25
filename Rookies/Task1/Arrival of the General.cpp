#include <iostream>
using namespace std;
int main() {
    int size;
    int counter = 0;   
    cin >> size;
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }
    for (int i = maxIndex; i > 0; --i) {
        swap(array[i], array[i - 1]);
        counter++;
    }

    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (array[i] <= array[minIndex]) {
            minIndex = i;
        }
    }

    for (int i = minIndex; i < size - 1; ++i) {
        swap(array[i], array[i + 1]);
        counter++;
    }

    cout << counter << endl;

    return 0;
}
