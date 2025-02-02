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
	int times = 0;
	cin >> times;
	int arr[6] = {6,9,66,69,96,99};
	while (times--)
	{
		int num = 0;
		cin >> num;
		for (size_t i = 0; i < 6; i++)
		{
			int x = arr[i] - num;
			if (x>=0)
			{
				cout << arr[i] << endl;
				break;
			}
		}
	}
	return 0;
}