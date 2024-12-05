#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(int array[], int size, int target, int start) {
    int low = start;
    int high = size - 1;
    int counter = -1; 

    while (low <= high) {
        int mid = (low + high) / 2;
        if (array[mid] <= target) {
            counter = mid; 
            low = mid + 1; 
        }
        else {
            high = mid - 1;
        }
    }
    return counter;
}

long long countTriplets(int points[], int size, int d) {
    long long count = 0;

    for (int i = 0; i < size; ++i) {
        int maxIndex = binarySearch(points, size, points[i] + d, i);

        if (maxIndex - i >= 2) {
            int range = maxIndex - i;
            count += (long long)range * (range - 1) / 2;
        }
    }
    return count;
}

int main() {
    int size, d;
    cin >> size >> d;

    int* points = new int[size];

    for (int i = 0; i < size; ++i) {
        cin >> points[i];
    }

    cout << countTriplets(points, size, d);

    return 0;
}
