#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, n;

	cin >> t;
	for (int i = 0; i < t; i++) {
		vector<pair<int, int>>num;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int a, b;
			cin >> a >> b;
			num.push_back({ a,b });
		}
		sort(num.begin(), num.end());
		int cnt = 1;
		int index = 0;
		for (int j = 1; j < n; j++) {
			if (num[j].second < num[index].second) {
				cnt++;
				index = j;
			}
		}
		cout << cnt << "\n";
	}
}