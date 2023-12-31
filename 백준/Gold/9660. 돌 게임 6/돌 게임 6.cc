#include <iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	long long n;
	string result;
	cin >> n;
	if (n % 7 == 0 || n % 7 == 2) {
		cout << "CY" << endl;
	}
	else {
		cout << "SK" << endl;
	}

}