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
vector<vector<pair<int, int>>> adj;
int maxSum = 0;

void DFS(int u, int parent, int currentSum) {
	if (currentSum > maxSum) {
		maxSum = currentSum;
	}
	for (auto edge : adj[u]) {
		int v = edge.first;
		int cost = edge.second;
		if (v != parent) {
			DFS(v, u, currentSum + cost);
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	adj.resize(n);

	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}

	DFS(0, -1, 0);

	cout << maxSum;

	return 0;
}