#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>>q;
int visited[1000][1000] = { 0 };
int s;
int display, clip;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	q.push({ 1,0 });
	visited[1][0] = 1;
	while (!q.empty()) {
		display = q.front().first;
		clip = q.front().second;
		q.pop();
		if (display == s) {
			break;
		}
		if (visited[display][display] == 0) {
			visited[display][display] = visited[display][clip] + 1;
			q.push({ display, display });
		}
		if (clip+display <= s && visited[display + clip][clip] == 0) {
			visited[display+clip][clip] = visited[display][clip] + 1;
			q.push({ display + clip, clip });
		}
		if (display > 0 && visited[display - 1][clip] == 0) {
			visited[display - 1][clip] = visited[display][clip] + 1;
			q.push({ display - 1, clip });
		}

	}
	cout << visited[display][clip]-1;
}