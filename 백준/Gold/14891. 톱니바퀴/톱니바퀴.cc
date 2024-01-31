#include <iostream>
#include <vector>
using namespace std;

int wheel[5][10];
int k;
int tmp[101][2];
int visited[5];

void fnc(int num, int s) {
    if (s == 1) {
        int x = wheel[num][7];
        for (int i = 6; i >= 0; i--) {
            wheel[num][i + 1] = wheel[num][i];
        }
        wheel[num][0] = x;
    }
    else {
        int x = wheel[num][0];
        for (int i = 0; i < 7; i++) {
            wheel[num][i] = wheel[num][i + 1];
        }
        wheel[num][7] = x;
    }
}
int v[5];
void spin(int num, int s) {
    v[num] = s;
    for (int i = num; i > 1; i--) {
        if (wheel[i][6] != wheel[i - 1][2]) {
            v[i - 1] = -v[i];
        }
    }
    for (int i = num; i < 4; i++) {
        if (wheel[i][2] != wheel[i + 1][6]) {
            v[i + 1] = -v[i];
        }
    }
    for (int i = 1; i <= 4; i++) {
        if (v[i] == 1 || v[i] == -1) fnc(i, v[i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 4; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < 8; j++)
            wheel[i][j] = a[j] - '0'; 
    }

    cin >> k;
    for (int i = 0; i < k; i++) cin >> tmp[i][0] >> tmp[i][1];
    for (int i = 0; i < k; i++) {
        spin(tmp[i][0], tmp[i][1]);
        for (int i = 0; i < 5; i++) v[i] = 0; 
    }
    int result = 0;
    if (wheel[1][0] == 1) result += 1;
    if (wheel[2][0] == 1) result += 2;
    if (wheel[3][0] == 1) result += 4;
    if (wheel[4][0] == 1) result += 8;

    cout << result;
}