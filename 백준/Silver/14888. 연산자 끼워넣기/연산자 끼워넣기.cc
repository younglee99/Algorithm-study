#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;
int a[15];
int cal[4];
int max_result = -1000000000;
int min_result = 1000000000;

int fnc(int x, int num, int cnt) {
	if (x == 0) return num + a[cnt];
	if (x == 1) return num - a[cnt];
	if (x == 2) return num * a[cnt];
	if (x == 3) return num / a[cnt];
}

void dfs(int cnt, int num) {
	if (cnt == n) {
		max_result = max(max_result, num);
		min_result = min(min_result, num);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (cal[i] == 0) continue;
		cal[i]--;
		dfs(cnt + 1, fnc(i, num, cnt));
		cal[i]++;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < 4; i++) cin >> cal[i];

	dfs(1, a[0]);

	cout << max_result << "\n" << min_result;
}