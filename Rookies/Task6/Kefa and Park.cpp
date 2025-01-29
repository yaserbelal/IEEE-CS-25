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
//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MAX_N = 1000000;
vector<int> tree[MAX_N];
int cats[MAX_N];
bool visited[MAX_N];
int n, m, result = 0;

void dfs(int node, int consecutive) {
    if (consecutive > m) return; 

    visited[node] = true;
    bool isLeaf = true;

    for (int neighbor : tree[node]) {
        if (!visited[neighbor]) {
            isLeaf = false;
            dfs(neighbor, cats[neighbor] ? consecutive + 1 : 0);
        }
    }

    if (isLeaf) result++; 
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, cats[1]); 

    cout << result;
    return 0;
}
