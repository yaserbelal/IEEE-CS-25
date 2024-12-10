#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<queue> 
#include<algorithm>
#define ll long long 
using namespace std;
int minMoves(string& start, string& destination) {
	vector<vector<int>> directions = {
		{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
		{-2, -1}, {-1, -2}, {1, -2}, {2, -1}
	};

	int startX = start[0] - 'a', startY = start[1] - '1';
	int destX = destination[0] - 'a', destY = destination[1] - '1';

	vector<vector<bool>> visited(8, vector<bool>(8, false));
	queue<pair<pair<int, int>, int>> q;

	q.push({ {startX, startY}, 0 });
	visited[startX][startY] = true;

	while (!q.empty()) {
		auto [pos, steps] = q.front();
		q.pop();

		int x = pos.first, y = pos.second;
		if (x == destX && y == destY) return steps;

		for (auto dir : directions) {
			int newX = x + dir[0], newY = y + dir[1];
			if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8 && !visited[newX][newY]) {
				visited[newX][newY] = true;
				q.push({ {newX, newY}, steps + 1 });
			}
		}
	}

	return -1;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int times;
	cin >> times;
	while (times--) {
		string start, destination;
		cin >> start >> destination;
		cout << minMoves(start, destination) << endl;
	}

	return 0;
}