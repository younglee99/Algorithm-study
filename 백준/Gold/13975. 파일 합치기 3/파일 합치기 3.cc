#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	int k, num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		
		priority_queue<long long, vector<long long>, greater<long long> > q;
		long long result = 0;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> num;
			q.push(num);
		}
		while (q.size() > 1) {
			long long hap = q.top();
			q.pop();
			hap += q.top();
			q.pop();
			result += hap;
			q.push(hap);
		}
		
		cout << result << "\n";
	}
	return 0;
}