#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long

ll pairs(ll* a, ll n, ll k) {
    ll count = 0;
    sort(a, a + n); 

    for (ll i = 0; i < n - 1; ++i) {
        ll low = i + 1, high = n - 1;
        bool found = false;
        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (a[mid] == a[i] - k) {
                found = true;
                break;
            }
            else if (a[mid] < a[i] - k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        if (found) {
            count++;
        }
    }

    return count;
}

int main() {
    ll size, key;
    cin >> size >> key;

    ll* array = new ll[size];
    for (ll i = 0; i < size; ++i) {
        cin >> array[i];
    }

    cout << pairs(array, size, key) << endl;

    delete[] array;
    return 0;
}
