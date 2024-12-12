#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;

vector<string> wall;
vector<vector<bool>>visit;
vector<vector<ll>> dist;
vector<vector<ll>> dir2;

const ll dirX[] = { -1, 1, 0, 0 };
const ll dirY[] = { 0, 0, -1, 1 };
const char dir[] = { 'U', 'D', 'L', 'R' };

ll n, m;

bool is_Valid(ll x, ll y)
{
	return x >= 0 && x < n && y >= 0 && y < m && !visit[x][y] && wall[x][y] != '#';
}
void bfs(ll X1, ll Y1)
{
	queue<pair<ll, ll>> q;
	q.push({ X1, Y1 });
	visit[X1][Y1] = true;
	dist[X1][Y1] = 0;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (ll i = 0; i < 4; i++)
		{
			ll nx = x + dirX[i], ny = y + dirY[i];
			if (is_Valid(nx, ny))
			{
				visit[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
				dir2[nx][ny] = i;
				q.push({ nx, ny });
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	wall.resize(n);
	visit.assign(n, vector<bool>(m, false));
	dist.assign(n, vector<ll>(m, -1));
	dir2.assign(n, vector<ll>(m, -1));
	ll X1, Y1, X2, Y2;
	for (ll i = 0; i < n; ++i)
	{
		cin >> wall[i];
		for (ll j = 0; j < m; ++j)
		{
			if (wall[i][j] == 'A')
			{
				X1 = i;
				Y1 = j;
			}
			else if (wall[i][j] == 'B')
			{
				X2 = i;
				Y2 = j;
			}
		}
	}
	bfs(X1, Y1);
	if (dist[X2][Y2] == -1)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
		cout << dist[X2][Y2] << endl;
		string path;
		ll x = X2, y = Y2;
		while (x != X1 || y != Y1)
		{
			ll p = dir2[x][y];
			path += dir[p];
			x -= dirX[p];
			y -= dirY[p];
		}
		reverse(path.begin(), path.end());
		cout << path << endl;
	}
	return 0;
}
