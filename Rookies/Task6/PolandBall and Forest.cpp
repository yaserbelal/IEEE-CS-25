#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<climits>
#define ll long long
using namespace std;
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
vector<vector<int>> adj;
vector<bool> visited;
int n;
void DFS(int node) {
	visited[node] = true;
	for (int neighbor : adj[node]) {
		if (!visited[neighbor]) {
			DFS(neighbor);
		}
	}
}

int countTrees() {
	int Counter = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			Counter++;
			DFS(i);
		}
	}
	return Counter;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	adj.resize(n + 1);
	visited.resize(n + 1, false);

	vector<int> PolandBall(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> PolandBall[i];
		if (PolandBall[i] != i) {
			adj[i].push_back(PolandBall[i]);
			adj[PolandBall[i]].push_back(i);
		}
	}

	cout << countTrees();
	return 0;
}
