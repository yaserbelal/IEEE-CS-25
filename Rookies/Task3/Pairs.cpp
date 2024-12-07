#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll pairs(ll k, ll array[], ll n) {
	ll counter = 0;

	sort(array, array + n);

	for (ll i = 0; i < n; i++) {
		ll target = array[i] + k; 
		ll low = i + 1, high = n - 1;

		while (low <= high) {
			ll mid = low + (high - low) / 2;

			if (array[mid] == target) {
				counter++; 
				break;   
			}
			else if (array[mid] < target) {
				low = mid + 1; 
			}
			else {
				high = mid - 1; 
			}
		}
	}

	return counter;
}

int main() {
	ll size, key;
	cin >> size >> key; 

	ll* array = new ll[size];
	for (ll i = 0; i < size; i++) {
		cin >> array[i];
	}

	cout << pairs(key, array, size) << endl; 
	return 0;
}
