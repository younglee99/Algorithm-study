#include <iostream>
#include <vector>

using namespace std;
int t, n;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int p = 0; p < t; p++) {
		int parent[100001] = { 0 };
		cin >> n;
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			parent[y] = x;
		}

		int a, b;
		cin >> a >> b;
		int num1 = a;
		int num2 = b;
		vector<int>f;
		vector<int>s;
		f.push_back(a);
		s.push_back(b);
		while (1) {
			if (parent[num1] == 0) break;
			f.push_back(parent[num1]);
			num1 = parent[num1];
		}
		while (1) {
			if (parent[num2] == 0) break;
			s.push_back(parent[num2]);
			num2 = parent[num2];
		}
		bool check = false;
		for (int i = 0; i < f.size(); i++) {
			if (check)break;
			for (int j = 0; j < s.size(); j++) {
				if (f[i] == s[j]) {
					check = true;
					cout << f[i] << "\n";
					break;
				}
			}
		}

	}
}