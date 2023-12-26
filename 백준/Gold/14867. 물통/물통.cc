#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
int a, b, f_a, f_b;
queue<pair<int, int>>q;
map<pair<int, int>, int> check;

int bfs(int x, int y) {
	q.push(make_pair(0, 0));
	check[make_pair(0, 0)] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int cnt = check[make_pair(x, y)];
		q.pop();
		if (x == f_a && y == f_b) {
			return cnt;
		}
		//F(x)
		if (check[make_pair(a, y)] == 0) {
			check[make_pair(a, y)] = cnt + 1;
			q.push(make_pair(a, y));
		}
		if (check[make_pair(x, b)] == 0) {
			check[make_pair(x, b)] = cnt + 1;
			q.push(make_pair(x, b));
		}
		//E(x)
		if (check[make_pair(x, 0)] == 0) {
			check[make_pair(x, 0)] = cnt + 1;
			q.push(make_pair(x, 0));
		}
		if (check[make_pair(0, y)] == 0) {
			check[make_pair(0, y)] = cnt + 1;
			q.push(make_pair(0, y));
		}
		//M(x,y)
		if (x <= b - y) {
			if (check[make_pair(0, y+x)] == 0) {
				check[make_pair(0, y+x)] = cnt + 1;
				q.push(make_pair(0, y+x));
			}
		}
		else {

			if (check[make_pair(x - b + y, b)] == 0) {
				check[make_pair(x - b + y, b)] = cnt + 1;
				q.push(make_pair(x - b + y, b));
			}
		}
		if (y <= a - x) {
			if (check[make_pair(x + y, 0)] == 0) {
				check[make_pair(x + y, 0)] = cnt + 1;
				q.push(make_pair(x + y, 0));
			}
		}
		else {
			if (check[make_pair(a, y - a + x)] == 0) {
				check[make_pair(a, y - a + x)] = cnt + 1;
				q.push(make_pair(a, y - a + x));
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> f_a >> f_b;
	int result = bfs(0, 0);
	cout << result;
}