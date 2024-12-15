#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
int fib(int num)
{
	if (num == 0) return 0;

	else if (num == 1) return 1;

	else
		return fib(num - 2) + fib(num - 1);
}
int main()
{
	int n;
	cin >> n;

	cout << fib(n);

	return 0;
}
