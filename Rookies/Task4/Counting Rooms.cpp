#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<queue> 
#include<algorithm>
#define ll long long 
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
const int dirX[] = { -1, 1, 0, 0 };
const int dirY[] = { 0, 0, -1, 1 };

void BFS(int startX, int startY, vector<vector<char>>& map, vector<vector<bool>>& visited) {
	queue<pair<int, int>> q;
	q.push({ startX, startY });
	visited[startX][startY] = true;

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = x + dirX[i], newY = y + dirY[i];
			if (newX >= 0 && newX < map.size() && newY >= 0 && newY < map[0].size() &&
				map[newX][newY] == '.' && !visited[newX][newY]) {
				visited[newX][newY] = true;
				q.push({ newX, newY });
			}
		}
	}
}

int countRooms(vector<vector<char>>& map) {
	int n = map.size();
	int m = map[0].size();
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	int counter = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '.' && !visited[i][j]) {
				counter++;
				BFS(i, j, map, visited);
			}
		}
	}
	return counter;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;

	vector<vector<char>> map(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	cout << countRooms(map);

	return 0;
}
