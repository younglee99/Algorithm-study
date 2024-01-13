#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

char tmp[12][6];
int visited[12][6];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool check = true;
int result = 0;
void init() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			visited[i][j] = 0;
		}
	}
}
void bfs(int x, int y) {
	queue<pair<int, int>>q;
	vector<pair<int, int>>list;
	int cnt = 0;
	q.push({ x,y });
	list.push_back({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		cnt++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx < 0 || nx>11 || ny < 0 || ny>5 || visited[nx][ny]) continue;
			if (tmp[x][y] == tmp[nx][ny]) {
				q.push({ nx,ny });
				list.push_back({ nx,ny });
				visited[nx][ny] = 1;
			}
		}
	}
	if (cnt >= 4) {
		check = true;
		for (int i = 0; i < cnt; i++) {
			int a = list[i].first;
			int b = list[i].second;
			tmp[a][b] = '.';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> tmp[i][j];
		}
	}
	while (1) {
		init();
		check = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (tmp[i][j] == '.' || visited[i][j]) continue;
				bfs(i, j);
			}
		}
		for (int i = 0; i < 6; i++) {
			for (int j = 11; j >= 0; j--) {
				if (tmp[j][i] == '.') {
					for (int p = j - 1; p >= 0; p--) {
						if (tmp[p][i] != '.') {
							tmp[j][i] = tmp[p][i];
							tmp[p][i] = '.';
							break;
						}
					}
				}
			}
		}
		if (check == false) break;
		result++;
	}
	cout << result;
}