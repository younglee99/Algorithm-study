#include <string>
#include <vector>
#include <queue>

using namespace std;
int lx[4] = {0,1,0,-1};
int ly[4] = {1,0,-1,0};
int map[1000][1000] = {0};
int visited[1000][1000] = {0};
int degree[1000][1000] = {0};
int answer = 0;
queue<pair<int,int>>q;


void course(int dx, int dy, int ux, int uy){
    for(int i=dx; i<=ux; i++){
        for(int j=dy; j<=uy; j++){
            if(map[i][j]==2)continue;
            if(i==dx || i == ux || j==dy || j==uy) map[i][j] = 1;
            else map[i][j] = 2;
        }
    }
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for(int i=0; i<rectangle.size(); i++){
        course(rectangle[i][0]*2,rectangle[i][1]*2,rectangle[i][2]*2,rectangle[i][3]*2);
    }
    visited[characterX*2][characterY*2] = 1;
    q.push({characterX*2, characterY*2});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        if(x == itemX*2 && y == itemY*2) break;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x+lx[i];
            int ny = y+ly[i];
            if(nx<0 || nx>=102 || ny<0 || ny>=102) continue;
            if(visited[nx][ny]==0 && map[nx][ny]==1){
                visited[nx][ny] = 1;
                q.push({nx, ny});
                degree[nx][ny] = degree[x][y] +1;
            }
        }
    }
    answer = degree[itemX*2][itemY*2]/2;
    return answer;
}