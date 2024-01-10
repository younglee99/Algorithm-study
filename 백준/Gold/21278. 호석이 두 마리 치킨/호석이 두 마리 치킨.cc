#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define INF 1000000000;
int dp[101][101] = { 0 };
int n, m;
int x, y, z = INF;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        dp[a][b] = 1;
        dp[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int num = 0;
            for (int k = 1; k <= n; k++) {
                num += min(dp[k][i] * 2, dp[k][j] * 2);
            }
            if (z > num) {
                x = i;
                y = j;
                z = num;
            }
        }
    }

    cout << x << " " << y << " " << z;
}