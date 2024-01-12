#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
queue<pair<int,int>>q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int visited[510][510] = {0};
int n, m =0;
int index = 1;
int result[501];
vector<vector<int>> maps;

void bfs(int x, int y){
    int cnt = 0;
    set<int>tmp;
    q.push({x,y});
    visited[x][y] = index;
    tmp.insert(y);
    while(!q.empty()){
        int first = q.front().first;
        int second = q.front().second;
        cnt++;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = first + dx[i];
            int ny = second + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m || maps[nx][ny] == 0 || visited[nx][ny]) continue;
            q.push({nx,ny});
            visited[nx][ny] = index;
            tmp.insert(ny);
        }
    }
    for(auto ss : tmp) result[ss] += cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size();
    m = land[0].size();
    maps = land;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(land[i][j] == 1 && visited[i][j]==0) {
                bfs(i, j);
            }
        }
    }
    for(int i=0; i<m; i++) answer = max(answer, result[i]);
    return answer;
}