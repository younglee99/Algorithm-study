#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    bool check[30] = {false};
    int answer = n - lost.size();
    for(int i=0; i<lost.size(); i++)
        for(int j=0; j<reserve.size(); j++){
            if(lost[i]==reserve[j]) {
                check[i]=true;
                reserve[j] = -2;
            }
        }
    for(int i=0; i<lost.size(); i++){
        if(check[i]==true) answer++;
    }
    
    for(int i=0; i< lost.size(); i++){
        if(check[i]==true) continue;
        for(int j=-1; j<2; j++){
            auto it = find(reserve.begin(), reserve.end(), lost[i]+j);
            if(it != reserve.end()){
                reserve.erase(it);
                answer++;
                break;
            }
        }
    }

    return answer;
}