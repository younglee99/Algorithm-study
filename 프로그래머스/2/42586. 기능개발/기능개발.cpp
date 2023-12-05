#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    for(int i=0; i<progresses.size(); i++){
        double num = (double)(100-progresses[i])/speeds[i];
        days.push_back(ceil(num));
    }
    answer.push_back(1);
    int cnt=0;
    for(int i=1; i<days.size(); i++){
        if(days[i]>days[cnt]) {
            answer.push_back(1);
            cnt = i;
        }
        else answer[answer.size()-1] +=1;
    }
    return answer;
}