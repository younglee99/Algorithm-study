#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int dp[110][110][2] = { 0 };
	int t, n, k;
	cin >> t;
	
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;

	for (int i = 2; i < 101; i++) {
		for (int j = 0; j < i; j++) {
			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
			dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j - 1][1];
		}
	}

	
	for (int i = 0; i < t; i++) {
		cin >> n >> k;

		cout << dp[n][k][0] + dp[n][k][1] << "\n";
	}
	return 0;
	
}

