#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>
#include <string>
using namespace std;

int a, b;

bool check1(int num) {  // 소수 판별
    if (num < 2) return false;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }

    return true;
}

bool check2(string z) {  // 인팰린드롬 판별
    string x, y;
    
    x = z;
    reverse(z.begin(), z.end());
    y = z;

    if(x == y) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    for (int i = a; i <= 10000000; i++) {  // 1000만 부터는 인팰린드롬  X
        if (i > b)break;
        if (!check2(to_string(i))) {
            continue;
        }
        if (check1(i)) {
            cout << i << "\n";
        }
    }
    cout << "-1";
}