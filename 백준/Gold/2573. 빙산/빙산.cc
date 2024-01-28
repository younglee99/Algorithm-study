#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n, m;
int ice[302][302];
int clone[302][302];
int visited[302][302];
int year = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void dfs(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (nx > -1 && nx < n && ny > -1 && ny < m && ice[nx][ny] > 0 && visited[nx][ny] == 0) {
			visited[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ice[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			clone[i][j] = ice[i][j];
		}
	}

	while (1) {
		int num = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) visited[i][j] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ice[i][j] == 0 || visited[i][j] == 1) continue;
				visited[i][j] = 1;
				dfs(i, j);
				num++;
			}
		}
		if (num == 0) {
			year = 0;
			break;
		}
		if (num > 1) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int cnt = 0;
				if (ice[i][j] == 0) continue;
				for (int t = 0; t < 4; t++) {
					int nx = i + dx[t];
					int ny = j + dy[t];
					if (nx > -1 && nx < n && ny > -1 && ny < m && ice[nx][ny] == 0) cnt++;
				}
				clone[i][j] -= cnt;
				if (clone[i][j] < 0) clone[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ice[i][j] = clone[i][j];
			}
		}
		year++;
	}

	cout << year;
}