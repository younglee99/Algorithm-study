#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int cnt = 0;
	bool visited[1000] = { false };
	queue<int>q;
	
	cin >> n >> m;
	vector<vector<int>>num(n+1);
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		num[a].push_back(b);
		num[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == true)continue;
		q.push(i);
		visited[i] = true;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int j = 0; j < num[x].size(); j++) {
				if (visited[num[x][j]] == false) {
					visited[num[x][j]] = true;
					q.push(num[x][j]);
				}
			}
		}
		cnt++;
	}
	cout << cnt;
}
