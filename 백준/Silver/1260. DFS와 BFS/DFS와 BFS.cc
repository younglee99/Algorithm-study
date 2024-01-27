#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m, v;
vector<int>num[1001];
vector<int>b;
vector<int>d;
int visited[1001];
int check[1001];
queue<int>q;

void dfs(int x) {
	d.push_back(x);
	for (int i = 0; i < num[x].size(); i++) {
		if (visited[num[x][i]] == 0) {
			visited[num[x][i]] = 1;
			dfs(num[x][i]);
		}
	}
}
void bfs(int x) {
	q.push(x);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		b.push_back(tmp);
		for (int i = 0; i < num[tmp].size(); i++) {
			if (check[num[tmp][i]] == 0) {
				check[num[tmp][i]] = 1;
				q.push(num[tmp][i]);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		num[a].push_back(b);
		num[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(num[i].begin(), num[i].end());
	}
	visited[v] = 1;
	check[v] = 1;
	dfs(v);
	bfs(v);
	for (int i = 0; i < d.size(); i++) cout << d[i] << " ";
	cout << "\n";
	for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
}