#include <iostream>
#include <algorithm>
using namespace std;
int n;
int visited[30];
int cnt = 0;
void queen(int x) {
	if (x == n) {
		cnt++;
	}
	else {
		for (int i = 0; i < n; i++) {
			bool check = true;
			visited[x] = i;
			for (int j = 0; j < x; j++) {
				if (visited[j] == visited[x] || abs(visited[x] - visited[j]) == x - j) {
					check = false;
					break;
				}
			}
			if (check) queen(x + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	queen(0);
	cout << cnt;
}