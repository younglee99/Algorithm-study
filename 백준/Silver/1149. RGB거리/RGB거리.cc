#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	int rgb[1001][3];
	int var[3];

	bool used[3] = { false };
	cin >> n;
	rgb[0][0] = 0;
	rgb[0][1] = 0;
	rgb[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> var[0] >> var[1] >> var[2];
		rgb[i][0] = min(rgb[i - 1][1], rgb[i - 1][2]) + var[0];
		rgb[i][1] = min(rgb[i - 1][0], rgb[i - 1][2]) + var[1];
		rgb[i][2] = min(rgb[i - 1][0], rgb[i - 1][1]) + var[2];
	}
	int result = 0;
	result = min({ rgb[n][0],rgb[n][1] ,rgb[n][2] });
	cout << result;


}