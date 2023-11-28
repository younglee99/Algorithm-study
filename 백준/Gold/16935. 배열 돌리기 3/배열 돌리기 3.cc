#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, r;
int cal[1000];
int a[100][100];
int clone[100][100];

void zero() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            a[i][j] = 0;
        }
    }
}

void turn(int x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            clone[i][j] =  a[i][j];
        }
    }

    if (x == 1) {
        zero();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = clone[n -1- i][j];
            }
        }
    }

    if (x == 2) {
        zero();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = clone[i][m-1-j];
            }
        }
    }

    if (x == 3) {
        zero();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[j][n - 1 - i] = clone[i][j];
            }
        }
        
        int tmp = n;
        n = m;
        m = tmp;
    }

    if (x == 4) {
        zero();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[m-1-j][i] = clone[i][j];
            }
        }

        int tmp = n;
        n = m;
        m = tmp;
    }

    if (x == 5) {
        zero();
        int p = n / 2;
        int q = m / 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i < p && j < q) a[i][j + q] = clone[i][j];
                if (i < p && j >= q) a[i+p][j] = clone[i][j];
                if (i >= p && j < q) a[i-p][j] = clone[i][j];
                if (i >= p && j >= q) a[i][j -q] = clone[i][j];
            }
        }

    }
    if (x == 6) {
        zero();
        int p = n / 2;
        int q = m / 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i < p && j < q) a[i+p][j] = clone[i][j];
                if (i < p && j >= q) a[i][j-q] = clone[i][j];
                if (i >= p && j < q) a[i][j+q] = clone[i][j];
                if (i >= p && j >= q) a[i-p][j] = clone[i][j];
            }
        }

    }

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r; i++) cin >> cal[i];
    
    for (int i = 0; i < r; i++) turn(cal[i]);
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

}