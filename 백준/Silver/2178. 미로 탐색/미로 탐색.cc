#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n, m;
int tmp[102][102];
int degree[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>>q;
void bfs(int r, int c) {
	q.push({ r,c });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > 0 && nx < n + 1 && ny > 0 && ny < m + 1 && degree[nx][ny] == 0 && tmp[nx][ny] == 1) {
				degree[nx][ny] = degree[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a[102];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char b = a[i][j - 1];
			tmp[i][j] = b-'0';
		}
	}
	degree[1][1] = 1;
	bfs(1, 1);
	cout << degree[n][m];
}