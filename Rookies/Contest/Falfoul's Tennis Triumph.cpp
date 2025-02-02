#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<limits.h>
#include<climits>
#define ll long long
using namespace std;
//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int scr = 0;
	int n;
	cin >> n;
	int* arr = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] == 1)
		{
			scr++;
		}
		else
		{
			scr--;
		}
	}
	for (size_t i = 2; i < n; i++)
	{
		if (arr[i] == 1 && arr[i - 1] == 1 && arr[i - 2] == 1)
			scr++;
	}
	cout << scr << endl;
	return 0;
}