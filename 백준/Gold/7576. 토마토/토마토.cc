#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;
int cnt = 0;
int n, m;
int tomato[1000][1000];
int visited[1000][1000] = { 0 };
vector<pair<int, int>>a;
queue<pair<int, int>>q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs() {
	while (!q.empty()) {
		int ls = q.front().first;
		int ly = q.front().second;
		q.pop();
		for (int p = 0; p < 4; p++) {
			int front = ls + dx[p];
			int back = ly + dy[p];
			if (front >= 0 && front < n && back >= 0 && back < m && tomato[front][back] == 0) {
				tomato[front][back] = tomato[ls][ly] + 1;
				q.push({ front ,back });
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}
	bfs();
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result = max(result, tomato[i][j]);
			if (tomato[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}
	cout << result-1;
}