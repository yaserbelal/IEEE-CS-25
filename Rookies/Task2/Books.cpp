#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size, t;
    cin >> size >> t;

    vector<int> books(size);
    for (int i = 0; i < size; ++i) {
        cin >> books[i];
    }

    int low = 0, high = 0, currentTime = 0, maxBook = 0;

    while (high < size ) {
        currentTime += books[high];

        while (currentTime > t) {
            currentTime -= books[low];
            low++;
        }

        maxBook = max(maxBook, high - low + 1);
        high++;
    }

    cout << maxBook;
    return 0;
}
