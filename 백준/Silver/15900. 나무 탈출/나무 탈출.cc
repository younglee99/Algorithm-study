#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int  n;
vector<int>tree[500001];
int visited[500001] = { 0 };
int result = 0;
void dfs(int s, int cnt) {
	if (tree[s].size() == 1 && s != 1) {
		result += cnt;
		return;
	}
	for (int i = 0; i < tree[s].size(); i++) {
		if (visited[tree[s][i]] == 0) {
			visited[tree[s][i]] = 1;
			dfs(tree[s][i], cnt + 1);
			visited[tree[s][i]] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	visited[1] = 1;
	dfs(1, 0);
	if (result % 2 == 1) cout << "Yes";
	else cout << "No";
	
}