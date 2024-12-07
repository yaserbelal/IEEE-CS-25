#include <iostream>
using namespace std;
#define ll long long 
void Bars(ll arr[], ll n, ll& A, ll& B) {
	ll left = 0, right = n - 1;
	ll timeAlice = 0, timeBob = 0;
	A = 0;
	B = 0;

	while (left <= right) {
		if (timeAlice <= timeBob) {
			timeAlice += arr[left];
			A++;
			left++;
		}
		else {
			timeBob += arr[right];
			B++;
			right--;
		}
	}
}

int main() {
	ll size;
	cin >> size;

	ll* chocolates = new ll[size];

	for (ll i = 0; i < size; i++) {
		cin >> chocolates[i];
	}

	ll barsAlice, barsBob;
	Bars(chocolates, size, barsAlice, barsBob);

	cout << barsAlice << " " << barsBob;

	return 0;
}
