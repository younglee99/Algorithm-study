#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = { 1,0,-1,0 };           // 2667 단지번호붙이기 
int dy[4] = { 0,1,0,-1 };
string town[30];
int visited[30][30] = { 0 };
queue<pair<int, int>>q;
vector<int>num;
int n;
int cnt = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> town[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (town[i][j] == '1' && visited[i][j] == 0) {
				cnt++;
				q.push({ i,j });
				visited[i][j] = 1;
				while (!q.empty()) {
					int front = q.front().first;
					int back = q.front().second;
					q.pop();
					for (int p = 0; p < 4; p++) {
						if (front + dx[p] >= 0 && front + dx[p] < n && back + dy[p] >= 0 && back + dy[p] < n && town[front + dx[p]][back + dy[p]] == '1' && visited[front + dx[p]][back + dy[p]] == 0) {
							visited[front + dx[p]][back + dy[p]] = 1;
							q.push({ front + dx[p] ,back + dy[p] });
							cnt++;
						}
					}
				}
				num.push_back(cnt);
				cnt = 0;
			}

		}
	}
	sort(num.begin(), num.end());
	cout << num.size() << "\n";
	for (int i = 0; i < num.size(); i++) cout << num[i] << "\n";

}