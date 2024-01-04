#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int result = 0;
bool fnc(int n) {
	bool check = true;
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return 0;
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		vector<int>num;
		int n = i;
		for (int j = 2; j * j <= n; j++) {
			while (n % j == 0) {
				num.push_back(j);
				n /= j;
			}
		}
		if (n > 1 && n<i) num.push_back(n);
		if (fnc(num.size())) result++;
	}
	cout << result;
}