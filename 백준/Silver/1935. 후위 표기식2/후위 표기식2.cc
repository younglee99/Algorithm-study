#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int n;
string a;
int var[30];
char en[30] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
               'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
stack<double>stk;
vector<int> cal;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> a;
    for (int i = 0; i < n; i++)
        cin >> var[i];

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == en[j]) {
                stk.push(var[j]);
            }
        }
        if (a[i] == '+') {
            double x = stk.top();
            stk.pop();
            double y = stk.top();
            stk.pop();
            stk.push(y + x);
        }
        if (a[i] == '-') {
            double x = stk.top();;
            stk.pop();
            double y = stk.top();
            stk.pop();
            stk.push(y - x);
        }
        if (a[i] == '*') {
            double x = stk.top();
            stk.pop();
            double y = stk.top();
            stk.pop();
            stk.push(y * x);
        }
        if (a[i] == '/') {
            double x = stk.top();
            stk.pop();
            double y = stk.top();
            stk.pop();
            stk.push(y / x);
        }

    }

    cout << fixed;
    cout.precision(2);
    cout << stk.top();
        
}