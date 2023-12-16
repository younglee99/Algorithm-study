#include <string>
#include <vector>

using namespace std;
int answer = 0;
bool visited[200] = {false};
void dfs(int current, int n, vector<vector<int>> computers){
    visited[current] = true;
    for(int i=0; i<n; i++){
        if(visited[i]==false && computers[current][i]==1){
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    for(int i=0; i<n; i++){
        if(visited[i]==false) {
            dfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}