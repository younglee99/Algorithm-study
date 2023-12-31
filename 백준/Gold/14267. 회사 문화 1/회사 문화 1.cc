#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>>s;
int score[100001] = { 0 };

void dfs(int x) {
	for (int i = 0; i < s[x].size(); i++) {
		int next = s[x][i];
		score[next] += score[x];
		dfs(next);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	s.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if(a>0) s[a].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		score[a]+= b;
	}

	dfs(1);
	
	for (int i = 1; i <= n; i++) {
		cout << score[i] << " ";
	}

}