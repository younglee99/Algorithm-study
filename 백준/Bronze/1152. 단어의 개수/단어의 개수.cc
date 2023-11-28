#include <iostream>
#include <string>
#include <vector>
using namespace std;

string a;         // 1152 단어의 개수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	getline(cin, a);
	
	int num = 0;
	int cnt = 1;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == ' ') num++;
		else break;
	}
	for (int i = a.size()-1; i >=0; i--) {
		if (a[i] == ' ') num++;
		else break;
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == ' ') cnt++;
	}
	if (a.empty()) cnt = 0;
	cout << cnt - num;
}