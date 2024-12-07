#include <iostream>
#include <algorithm>

using namespace std;
#define ll   long long
ll countPairs(ll* a, ll n, ll l, ll r) {
    ll count = 0;
    sort(a, a + n);

    for (ll i = 0; i < n - 1; ++i) {
        ll low = i + 1, high = n - 1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (a[i] + a[mid] >= l) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        ll left = low;

        low = i + 1, high = n - 1;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (a[i] + a[mid] <= r) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        ll right = high;

        if (left <= right) {
            count += (right - left + 1);
        }
    }

    return count;
}

int main() {
    ll times;
    cin >> times;

    while (times--) {
        ll  n, l, r;
        cin >> n >> l >> r;

        ll* array = new ll[n];
        for (ll i = 0; i < n; ++i) {
            cin >> array[i];
        }

        cout << countPairs(array, n, l, r) << endl;
        delete[] array;
    }

    return 0;
}
