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
ll dirX[] = { 1, -1, 0, 0 };
ll dirY[] = { 0, 0, 1, -1 };
string dir_map = "DURL";

bool isBoundary(ll x, ll y, ll n, ll m) {
	return x == 0 || y == 0 || x == n - 1 || y == m - 1;
}

bool DFS(ll x, ll y, ll n, ll m, const vector<string>& labyrinth, const vector<vector<ll>>& time_map, vector<vector<bool>>& visited, string& path) {
	if (isBoundary(x, y, n, m)) {
		return true;
	}

	visited[x][y] = true;

	for (ll i = 0; i < 4; i++) {
		ll newX = x + dirX[i];
		ll newY = y + dirY[i];

		if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] &&
			labyrinth[newX][newY] == '.' && (path.length() + 1 < time_map[newX][newY])) {
			path += dir_map[i];
			if (DFS(newX, newY, n, m, labyrinth, time_map, visited, path)) {
				return true;
			}
			path.pop_back();
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;

	vector<string> labyrinth(n);
	pair<ll, ll> start;
	vector<pair<ll, ll>> monsters;

	for (ll i = 0; i < n; i++) {
		cin >> labyrinth[i];
		for (ll j = 0; j < m; j++) {
			if (labyrinth[i][j] == 'A') {
				start = { i, j };
				labyrinth[i][j] = '.';
			}
			else if (labyrinth[i][j] == 'M') {
				monsters.push_back({ i, j });
			}
		}
	}

	vector<vector<ll>> time_map(n, vector<ll>(m, 2147483647));
	vector<pair<ll, ll>> queue = monsters;
	vector<vector<bool>> visited_monsters(n, vector<bool>(m, false));
	ll time = 0;

	while (!queue.empty()) {
		vector<pair<ll, ll>> next_queue;
		for (auto [x, y] : queue) {
			if (visited_monsters[x][y]) continue;
			visited_monsters[x][y] = true;
			time_map[x][y] = time;
			for (ll i = 0; i < 4; i++) {
				ll newX = x + dirX[i], newY = y + dirY[i];
				if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
					labyrinth[newX][newY] == '.' && !visited_monsters[newX][newY]) {
					next_queue.push_back({ newX, newY });
				}
			}
		}
		queue = next_queue;
		time++;
	}

	vector<vector<bool>> visited_player(n, vector<bool>(m, false));
	string path;

	if (DFS(start.first, start.second, n, m, labyrinth, time_map, visited_player, path)) {
		cout << "YES" << endl
			<< path.length() << endl
			<< path << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}