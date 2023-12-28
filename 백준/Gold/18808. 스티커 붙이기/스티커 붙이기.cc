#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int tmp[50][50];
int stk[12][12];
int N, M, K;
int r,c;


bool func(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (tmp[x + i][y + j] == 1 && stk[i][j] == 1)
				return false;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (stk[i][j] == 1){
				tmp[x + i][y + j] = 1;
			}
				
		}
	}
	return true;
}

void rotate() {
	int clone[12][12];
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			clone[i][j] = stk[i][j];
		}
	
	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++) {
			stk[i][j] = clone[r-1-j][i];
		}
	swap(r, c);
}

int main() {
	cin >> N >> M >> K;
	
	while (K--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				cin >> stk[i][j];
			}
		
		for (int p = 0; p < 4; p++) {
			bool possible = false;
			for (int i = 0; i <= N - r; i++) {
				if (possible) break;
				for (int j = 0; j <= M-c; j++) {
					possible = func(i,j);
					if (possible) break;
				}
			}
			if (possible) break;
			rotate();
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 1) cnt++;
		}
	cout << cnt;

}