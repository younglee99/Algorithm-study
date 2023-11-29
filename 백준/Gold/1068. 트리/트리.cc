#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int root;
int del;
int num = 0;
vector<int>tree[100];

void dfs(int root) {
	if (root == del) return;
	bool check = true;
	for (int i = 0; i < tree[root].size(); i++) {
		if (tree[root][i] == del) continue;
		else {
			check = false;
			dfs(tree[root][i]);
		}
	}
	if (check)num++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == -1) root = i;
		else tree[num].push_back(i);
	}
	cin >> del;
	dfs(root);

	cout << num;

}