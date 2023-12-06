#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    vector<int>check;
    queue<int>q;
    int cnt=0;

    for(int i=0; i<priorities.size(); i++){
        q.push(priorities[i]);
        if(i==location) check.push_back(1);
        else check.push_back(0);
    }
    while(!q.empty()){
        int max_n = priorities[0];
        int a = q.front();
        q.pop();
        for(int i=1; i<priorities.size(); i++){
            if(priorities[i]>max_n) max_n =priorities[i];
        }
        if(a<max_n){
            q.push(a);
            int x = check[0];
            int y = priorities[0];
            check.erase(check.begin());
            check.push_back(x);
            priorities.erase(priorities.begin());
            priorities.push_back(y);
        }
        else{
            cnt++;
            if(check[0]==1) return cnt;
            check.erase(check.begin());
            priorities.erase(priorities.begin());
        }

       
    }

    
    
    return cnt;
}