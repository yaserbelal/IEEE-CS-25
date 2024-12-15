#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
void weird(ll num)
{
	if (num == 1) {
		cout << num << " ";
		return;
	}

	cout << num << " ";
	if (num % 2 == 0) {
		weird(num / 2);
	}
	else {
		weird(3 * num + 1);
	}
}
int main()
{
	ll n;
	cin >> n;

	weird(n);

	return 0;
}
