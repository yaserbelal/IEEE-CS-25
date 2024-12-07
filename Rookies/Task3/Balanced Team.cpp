#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std;
ll balancedTeam(ll n, ll array[]) {
    sort(array,array+n); 

    ll left = 0;       
    ll maxTeamSize = 0;

    for (ll right = 0; right < n; right++) {
        while (array[right] - array[left] > 5) {
            left++;
        }
        maxTeamSize = max(maxTeamSize, right - left + 1);
    }

    return maxTeamSize;
}

int main() {
    ll size;
    cin >> size;
    ll* array = new ll[size];
    
    for (ll i = 0; i < size; i++) {
        cin >> array[i];
    }

    cout << balancedTeam(size, array) << endl; 

    return 0;
}
