#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long m;
	long long num;
	long long d;
	vector<long long>tree;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		tree.push_back(num);
	}
	sort(tree.begin(), tree.end());
	long long low = 0, high = 1000000000;
	while (low <= high) {
		long long result = 0;
		long long mid = (low + high) / 2;
		for (int i = 0; i < n; i++) {
			if (tree[i] - mid > 0) result += tree[i] - mid;
		}
		if (result >= m) {
			d = mid;
			low = mid + 1;
		}
		else if (result < m) {
			high = mid - 1;
		}
	}
	cout << d;
}