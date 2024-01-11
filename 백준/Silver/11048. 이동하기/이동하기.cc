#include <iostream>

using namespace std;
int n, m;
int tmp[1001][1001];
int visited[1001][1001];
int max_num = 0;
int dx[3] = { 1,0,1 };
int dy[3] = { 0,1,1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> tmp[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			tmp[i][j] += max(tmp[i - 1][j], tmp[i][j - 1]);
		}
	}

	cout << tmp[n][m];
}