#include <iostream>

using namespace std;
int n;
char tree[30][2];
//전위순회
void preorder(char cur) {
    if (cur == '.')
        return;

    cout << cur;
    preorder(tree[cur - 'A'][0]);
    preorder(tree[cur - 'A'][1]);
}
//중위순회
void inorder(char cur) {
    if (cur == '.')
        return;

    inorder(tree[cur - 'A'][0]);
    cout << cur;
    inorder(tree[cur - 'A'][1]);
}
//후위순회
void postorder(char cur) {
    if (cur == '.')
        return;

    postorder(tree[cur - 'A'][0]);
    postorder(tree[cur - 'A'][1]);
    cout << cur;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		tree[a-'A'][0] = b;
		tree[a-'A'][1] = c;
	}
    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
	
}