#include <iostream>

using namespace std;

int n, m;
int map[51][51];
int robot[3];
int clean[51][51];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int result = 0;

void fnc(int x, int y, int d) {
	bool check = false;
	if (clean[x][y] == 0) {
		clean[x][y] = 1;
		result++;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > -1 && nx<n && ny>-1 && ny < m && clean[nx][ny] == 0 && map[nx][ny] == 0) {
			check = true;
			break;
		}
	}
	if (check) {
		while (1) {
			if (d == 0)d = 3;
			else d--;
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (map[nx][ny] == 0 && clean[nx][ny] == 0) {
				fnc(nx, ny, d);
				break;
			}
		}
	}
	else {
		int di = (d + 2) % 4;
		int nx = x + dx[di];
		int ny = y + dy[di];
		if (map[nx][ny] == 0) fnc(nx, ny, d);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> robot[0] >> robot[1] >> robot[2];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	fnc(robot[0], robot[1], robot[2]);
	cout << result;
}