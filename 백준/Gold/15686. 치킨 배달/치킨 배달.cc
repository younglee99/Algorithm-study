#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int map[51][51];
int cnt = 0;
vector<int>v;
vector<pair<int, int>>chicken;
int dis = 0;
int result = 100000000;
void cal(int x, int y) {
	int num = 1000000000;
	int tmp = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 1) {
			tmp = abs(x - chicken[i].first) + abs(y - chicken[i].second);
			num = min(num, tmp);
		}
	}
	dis += num;

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				cnt++;
				chicken.push_back({ i,j });
			}
		}
	for (int i = 0; i < cnt; i++) {
		if (i < m) v.push_back(1);
		else v.push_back(0);
	}
	sort(v.begin(), v.end());
	do {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] == 1) {
					cal(i, j);
				}
			}
		}

		result = min(result, dis);
		dis = 0;
	} while (next_permutation(v.begin(), v.end()));


	cout << result;
	
}