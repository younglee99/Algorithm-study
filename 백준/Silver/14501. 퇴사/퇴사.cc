#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int t[16];
int p[16];
int dp[20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = n; i > 0; i--) {
		int dead = i + t[i];
		if (dead > n + 1) dp[i] = dp[i + 1];
		else dp[i] = max(dp[i + 1], p[i] + dp[i + t[i]]);
	}

	cout << dp[1];
}
