#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int map[1010][1010];
int visited[3000][3000] = { 0 };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int cnt = 0;

void dfs(int x, int y) {
	visited[x][y] = 1;
	int nx = x + dx[map[x][y]];
	int ny = y + dy[map[x][y]];
	if (visited[nx][ny] == 0) dfs(nx, ny);
	else if (visited[nx][ny] == 1) cnt++;
	visited[x][y] = 2;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char a;
			cin >> a;
			if (a == 'U') map[i][j] = 0;
			else if (a == 'D') map[i][j] = 1;
			else if (a == 'L') map[i][j] = 2;
			else map[i][j] = 3;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0) dfs(i, j);
		}
	}
	cout << cnt;
	return 0;
}

