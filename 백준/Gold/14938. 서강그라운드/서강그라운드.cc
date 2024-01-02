#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, r;
	int item[101];
	int degree[101][101];
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) degree[i][j] = 0;
			else degree[i][j] = 1000000000;
		}
	}
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		degree[a][b] = l;
		degree[b][a] = l;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (degree[i][k] + degree[k][j] < degree[i][j])
					degree[i][j] = degree[i][k] + degree[k][j];
			}
	int cnt = 0;
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt = item[i];
		for (int j = 1; j <= n; j++)
		{

			if (i != j && degree[i][j] <= m) cnt += item[j];
		}
		result = max(result, cnt);
	}
	cout << result;
}