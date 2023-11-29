#include <iostream>
#include <algorithm>

using namespace std;

int h, y;
int dp[11];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> h >> y;
	
	dp[0] = h;
	dp[1] = h * 1.05;
	dp[2] = dp[1] * 1.05;
	dp[3] = max(dp[2] * 1.05, dp[0] * 1.2);
	dp[4] = max(dp[3] * 1.05, dp[1] * 1.2);
	
	for (int i = 5; i <= 10; i++) {
		dp[i] = max(max(dp[i - 1] * 1.05, dp[i - 3] * 1.2), dp[i - 5] * 1.35);
	}
	cout << dp[y];
}