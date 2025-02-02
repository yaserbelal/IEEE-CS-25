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

    int n;
    cin >> n;

    vector<int> sum(n);  
    cin >> sum[0];  

    for (int i = 1; i < n; i++) {
        int piles;
        cin >> piles;
        sum[i] = sum[i - 1] + piles;
    }

    int m;
    cin >> m;

    while (m--) {
        int q;
        cin >> q;

        int index = lower_bound(sum.begin(), sum.end(), q) - sum.begin();

        cout << (index + 1) << endl;
    }

    return 0;
}