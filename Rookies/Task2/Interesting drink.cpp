#include <iostream>
#include <algorithm>
using namespace std;
int binarySearch(int array[], int size, int target) {
    int low = 0;
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
    return counter + 1; 
}

int main() {
    int size;
    cin >> size;

    int* prices = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> prices[i];
    }

    sort(prices, prices + size);

    int q;
    cin >> q;

    while (q--) {
        int hismoney;
        cin >> hismoney;
        cout << binarySearch(prices, size, hismoney) << endl;
    }

    return 0;
}
