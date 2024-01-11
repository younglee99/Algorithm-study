#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	int dp[1001] = { 0 };
	int list[1001] = { 0 };
	int result = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> list[i];
	
	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (int j = 0; j < i; j++) {
			if (list[i] > list[j]) {
				mx = max(mx, dp[j]);
			}
		}
		dp[i] = mx + 1;
	}
	for (int i = 1; i <= n; i++) {
		result = max(result, dp[i]);
	}
	cout <<result;
}