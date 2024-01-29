#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int tmp[30][30];
int visited[30];
int result = 1000000000;
void dfs(int cnt, int num) {
	if (cnt == n / 2) {
		int start = 0;
		int link = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (visited[i] == 1 && visited[j] == 1) start += tmp[i][j];
				if (visited[i] == 0 && visited[j] == 0) link += tmp[i][j];
			}
		}
		int final = abs(start - link);
		result = min(result, final);
	}
	for (int i = num; i <= n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(cnt + 1, i+1);
			visited[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> tmp[i][j];

	dfs(0, 1);
	cout << result;
}