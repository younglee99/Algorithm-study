#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int dp[11];
	int t;
	int a[10000];
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a[i];
	}
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	for (int i = 0; i < t; i++) {
		cout << dp[a[i]] << "\n";
	}
	
}