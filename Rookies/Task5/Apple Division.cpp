#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#define ll long long
using namespace std;
ll appleDivision(ll weights[], int n, int index, ll group1, ll totalW) {
	if (index == n) {
		ll group2 = totalW - group1;
		return abs(group1 - group2);
	}

	ll includeInGroup1 = appleDivision(weights, n, index + 1, group1 + weights[index], totalW);
	ll excludeFromGroup1 = appleDivision(weights, n, index + 1, group1, totalW);

	return min(includeInGroup1, excludeFromGroup1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int size;
	cin >> size;
	ll* weights = new ll[size];
	ll totalW = 0;
	for (size_t i = 0; i < size; i++)
	{
		cin >> weights[i];
		totalW += weights[i];
	}

	cout<< appleDivision(weights, size, 0, 0, totalW);
	return 0;
}

