#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<string>s;
	string a;
	cin >> a;

		for (int i = 1; i <= a.size();i++) {
			for (int j = 0; j <= a.size()-i; j++) {
				string tmp = a.substr(j, i);
				s.push_back(tmp);
			}
		}
		sort(s.begin(), s.end());
		s.erase(unique(s.begin(), s.end()), s.end());
		cout << s.size();

}