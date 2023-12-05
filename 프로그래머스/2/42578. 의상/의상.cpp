#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int solution(vector<vector<string>> clothes) {
    vector<string>type;
    for(int i=0; i< clothes.size(); i++) type.push_back(clothes[i][1]);
    int num=1;
    
    set<string>set_type(type.begin(),type.end());
    for(const string &str : set_type){
        int cnt=1;
        for(int i=0; i< clothes.size(); i++){
            if(str==clothes[i][1]) cnt++;
        }
        num = num*cnt;
    }
 
    
    int answer = num-1;
    return answer;
}