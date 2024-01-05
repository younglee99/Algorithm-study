#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isprime(int n) {
	bool check = true;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int upprime(int n) {
	while (1) {
		n++;
		if (isprime(n)) return n;
	}
}

int downprime(int n) {
	while (1) {
		n--;
		if (isprime(n)) return n;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	vector<int>result;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		if (isprime(a)) result.push_back(0);
		else {
			int x = upprime(a);
			int y = downprime(a);
			result.push_back(x - y);
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}