#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#define ll long long
using namespace std;
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

ll dirX[] = { 0, 0, -1, 1 };
ll dirY[] = { -1, 1, 0, 0 };

ll DFS(ll x, ll y, vector<vector<ll>>& Map, vector<vector<bool>>& visited, ll n, ll m) {
	visited[x][y] = true;
	ll volume = Map[x][y];

	for (ll dir = 0; dir <= 3; dir++) {
		ll newX = x + dirX[dir];
		ll newY = y + dirY[dir];

		if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && Map[newX][newY] > 0) {
			volume += DFS(newX, newY, Map, visited, n, m);
		}
	}

	return volume;
}

int main() {
	ll times;
	cin >> times; 

	while (times--) {
		ll n, m;
		cin >> n >> m; 

		vector<vector<ll>> Map(n, vector<ll>(m));
		vector<vector<bool>> visited(n, vector<bool>(m, false));

		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				cin >> Map[i][j];
			}
		}

		ll maxVolume = 0;

		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				if (!visited[i][j] && Map[i][j] > 0) {
					ll currentVolume = DFS(i, j, Map, visited, n, m);
					maxVolume = max(maxVolume, currentVolume);
				}
			}
		}

		cout << maxVolume << endl;
	}

	return 0;
}
