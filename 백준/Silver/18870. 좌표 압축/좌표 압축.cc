
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, num;
	vector<int>var;
	vector<int>clone;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		clone.push_back(num);
		var.push_back(num);
	}
	sort(clone.begin(), clone.end());
	clone.erase(unique(clone.begin(), clone.end()), clone.end());

	for (int i = 0; i < n; i++) {
		cout << lower_bound(clone.begin(), clone.end(), var[i]) - clone.begin() << " ";
	}

}