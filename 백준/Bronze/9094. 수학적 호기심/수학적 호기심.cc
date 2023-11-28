#include <iostream>

using namespace std;
int final[10000] = { 0 };

int t, n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;

		for (int a = 1; a < n; a++) {
			for (int b = a+1; b < n; b++) {
				if ((a * a + b * b + m) % (a * b) == 0) final[i]++;
			}
		}

	}
	for (int i = 0; i < t; i++) {
		cout << final[i] << "\n";
	}
}