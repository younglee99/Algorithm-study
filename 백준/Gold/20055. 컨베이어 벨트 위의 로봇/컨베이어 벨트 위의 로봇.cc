#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n, k;
int c[210];
int robot[110];
int result = 0;

void spin() {
	int x = c[2 * n];
	for (int i = 2 * n; i > 1; i--) c[i] = c[i - 1];
	c[1] = x;
	for (int i = n; i > 1; i--) {
		robot[i] = robot[i - 1];
	}
	robot[1] = 0;
	if (robot[n] == 1) robot[n] = 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= 2 * n; i++) cin >> c[i];
	
	while (1) {
		int num = 0;
		result++;
		spin();
		for (int i = n-1; i > 1; i--) {
			if (robot[i] == 1) {
				if (robot[i + 1] == 0 && c[i + 1] > 0) {
					robot[i + 1] = robot[i];
					robot[i] = 0;
					c[i + 1]--;
				}
			}
		}
		if (robot[n] == 1)robot[n] = 0;
		if (c[1] > 0) {
			robot[1] = 1;
			c[1]--;
		}
		for (int i = 1; i <= 2 * n; i++) {
			if (c[i] == 0) num++;
		}
		if (num >= k) break;
	}
	cout << result;
}