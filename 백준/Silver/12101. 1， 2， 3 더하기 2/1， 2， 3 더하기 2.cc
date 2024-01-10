#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<string>num[1000];
int n, k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    num[1].push_back("1");
    num[2].push_back("11");
    num[2].push_back("2");
    num[3].push_back("111");
    num[3].push_back("12");
    num[3].push_back("21");
    num[3].push_back("3");
    for (int i = 4; i < 11; i++) {
        for (int j = 1; j < 4; j++) {
            for (int p = 0; p < num[i - j].size(); p++) {
                string a = to_string(j);
                string b = num[i - j][p] + a;
                num[i].push_back(b);
            }
        }
    }
    sort(num[n].begin(), num[n].end());
    if (num[n].size() < k) {
        cout << "-1";
        return 0;
    }
    for (int i = 0; i < num[n][k-1].size(); i++) {
        cout << num[n][k-1][i];
        if (i < num[n][k-1].size()-1) cout << "+";
    }
}