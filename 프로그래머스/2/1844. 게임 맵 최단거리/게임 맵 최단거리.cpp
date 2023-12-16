#include<vector>
#include<iostream>
#include<queue>
using namespace std;
int answer = 0;
int visited[1000][1000];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int degree[1000][1000];
queue<pair<int,int>>q;

int solution(vector<vector<int> > maps)
{
    q.push({0,0});
    visited[0][0] = true;
    degree[0][0]=1;
    int M = maps[0].size();
    int N = maps.size();
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M || visited[nx][ny]==1 || maps[nx][ny]==0) continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
            degree[nx][ny] = degree[x][y] +1;
        }
    }
    int answer = 0;
    if(degree[N-1][M-1]==0) answer = -1;
    else answer = degree[N-1][M-1];
    return answer;
}