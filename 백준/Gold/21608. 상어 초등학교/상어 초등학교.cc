#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int student[401];
int like[411][5];
int map[21][21];
int tmp[21][21] = { -1 };
int tmp2[21][21] = { -1 };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool check1 = false;
bool check2 = false;
int aa = 0;
int bb = 0;

void fnc1(int num) {
	int result = -1;
	int t = 0;
	int r, c = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cnt = 0;
			if (map[i][j] > 0) continue;
			for (int t = 0; t < 4; t++) {
				int nx = i + dx[t];
				int ny = j + dy[t];
				if (nx<1 || nx>n || ny<1 || ny>n || map[nx][ny] == 0) continue;
				for (int p = 0; p < 4; p++) if (map[nx][ny] == like[num][p]) cnt++;
			}
			
			tmp[i][j] = cnt;
			if (result < cnt) {
				result = cnt;
				t = 1;
				r = i;
				c = j;
			}
			else if (result == cnt) t++;
		}
	}

	aa = result;
	if (t == 1) map[r][c] = num;
	if (t > 1)check1 = true;
}

void fnc2(int num, int index) {
	int result = -1;
	int t = 0;
	int r, c = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cnt = 0;
			if (map[i][j] > 0) continue;
			if (tmp[i][j] == index) {
				for (int t = 0; t < 4; t++) {
					int nx = i + dx[t];
					int ny = j + dy[t];
					if (nx>0 && nx<n+1 && ny>0 && ny<n+1 && map[nx][ny] == 0) cnt++;
				}
				tmp2[i][j] = cnt;
			}
			if (result < cnt) {
				result = cnt;
				t = 1;
				r = i;
				c = j;
			}
			else if (result == cnt) t++;
		}
	}
	
	bb = result;
	if (t == 1) map[r][c] = num;
	if (t > 1)check2 = true;
}

void fnc3(int num, int index) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] > 0) continue;
			if (tmp2[i][j] == index) {
				map[i][j] = num;
				return;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> student[i];
		for (int j = 0; j < 4; j++) cin >> like[student[i]][j];
	}

	for (int i = 0; i < n * n; i++) {
		check1 = false;
		check2 = false;
		for (int p = 1; p <= n; p++) {
			for (int j = 1; j <= n; j++) {
				tmp[p][j] = -1;
				tmp2[p][j] = -1;
			}
		}
		fnc1(student[i]);
	
		if (check1) fnc2(student[i], aa);
		if (check2) fnc3(student[i], bb);

	}

	int final = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cl = map[i][j];
			int cnt = 0;
			for (int t = 0; t < 4; t++) {
				int nx = i + dx[t];
				int ny = j + dy[t];
				if (nx<1 || nx>n || ny<1 || ny>n) continue;
				for (int p = 0; p < 4; p++) if (map[nx][ny] == like[cl][p]) cnt++;
			}

			if (cnt == 1) final += 1;
			if (cnt == 2) final += 10;
			if (cnt == 3) final += 100;
			if (cnt == 4) final += 1000;
		}
	}

	cout << final;
}

