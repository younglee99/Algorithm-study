#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int town[101][101] = { 0 };
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1;j <= n; j++) {
			if (i == j) town[i][j] = 0;
			else town[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		town[a][b] = min(town[a][b], c);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				town[i][j] = min(town[i][j], town[i][k] + town[k][j]);
			}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (town[i][j] == INF) {
				cout << '0' << " ";
				continue;
			}
			cout << town[i][j] << " ";
		}
		cout << '\n';
	}
}