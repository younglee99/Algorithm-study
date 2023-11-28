#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>
#include <string>
using namespace std;

int t;
string a[1000];
string b[1000];
string result[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < t; i++) {
        string c;
        if (a[i].size() > b[i].size()) {
            for (int j = 0; j < a[i].size() - b[i].size(); j++) {
                c += '0';
            }
            b[i] = c + b[i];
        }
        if (a[i].size() < b[i].size()) {
            for (int j = 0; j < b[i].size() - a[i].size(); j++) {
                c += '0';
            }
            a[i] = c + a[i];
        }
        int carry = 0;
        result[i].resize(a[i].size() + 1);
        for (int j = a[i].size() - 1; j >= 0; j--) {
            int x = a[i][j] - '0' + b[i][j] - '0' + carry;
            if (x > 1) carry = 1;
            else carry = 0;
            result[i][j + 1] = x % 2 + '0';
        }
        result[i][0] = carry + '0';

        // 앞에 붙은 0 제거
        result[i].erase(0, result[i].find_first_not_of('0'));

        // 불필요한 0이 모두 제거되었다면 결과가 빈 문자열이 되므로 "0"으로 설정
        if (result[i].empty()) {
            result[i] = "0";
        }
    }
    for (int i = 0; i < t; i++) cout << result[i] << "\n";
}