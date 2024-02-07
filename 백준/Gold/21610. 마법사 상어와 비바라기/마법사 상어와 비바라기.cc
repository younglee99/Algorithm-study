#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int map[550][550];
vector<int> d;
vector<int> s;
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int fx[4] = { -1, -1, 1, 1 };
int fy[4] = { -1, 1, -1, 1 };
vector<pair<int, int>> cloud;
int visited[550][550];

void move(int di, int num) {
    for (int i = 0; i < cloud.size(); i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        int nx = x + (dx[di] * (num % n));
        int ny = y + (dy[di] * (num % n));

        if (nx < 1) nx += n;
        if (ny < 1) ny += n;
        if (nx > n) nx %= n;
        if (ny > n) ny %= n;
        cloud[i].first = nx;
        cloud[i].second = ny;
        visited[nx][ny] = 1;
        map[nx][ny]++;
    }
}

void dup() {
    for (int i = 0; i < cloud.size(); i++) {
        int nx = cloud[i].first;
        int ny = cloud[i].second;
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            int mx = nx + fx[j];
            int my = ny + fy[j];
            if (mx < 1 || mx > n || my < 1 || my > n) continue;
            if (map[mx][my] > 0) cnt++;
        }
        map[nx][ny] += cnt;
    }
}

void create() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (visited[i][j] == 0 && map[i][j] > 1) {
                map[i][j] -= 2;
                cloud.push_back({ i, j });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    d.resize(m);
    s.resize(m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> map[i][j];
    for (int i = 0; i < m; i++) cin >> d[i] >> s[i];
    cloud.push_back({ n - 1, 1 });
    cloud.push_back({ n - 1, 2 });
    cloud.push_back({ n, 1 });
    cloud.push_back({ n, 2 });

    for (int i = 0; i < m; i++) {
        for (int p = 1; p <= n; p++)
            for (int j = 1; j <= n; j++) visited[p][j] = 0;

        move(d[i] - 1, s[i]);
        dup();
        cloud.clear();
        create();
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) result += map[i][j];

    cout << result;
}