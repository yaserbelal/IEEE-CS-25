#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <long long> cities(n), towers(m);
	for (int i = 0; i < n; ++i) {
		cin >> cities[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> towers[i];
	}
	long long  t = 0, result = INT_MIN;
	for (int i = 0; i < n; i++) {
		while (abs(cities[i] - towers[t]) >= abs(cities[i] - towers[t + 1]))
		{
			t++;
		}
		result = max(result, abs(cities[i] - towers[t]));
	}
	cout << result;


	return 0;
}
