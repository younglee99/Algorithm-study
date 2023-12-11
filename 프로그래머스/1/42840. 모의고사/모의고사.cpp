#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> one = {1,2,3,4,5};
    vector<int> two = {2,1,2,3,2,4,2,5};
    vector<int> three = {3,3,1,1,2,2,4,4,5,5};
    vector<int> person = {0,0,0};
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    
    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == one[num1]) person[0] += 1;
        if(answers[i] == two[num2]) person[1] += 1;
        if(answers[i] == three[num3]) person[2] += 1;
        
        num1++;
        num2++;
        num3++;
        
        if(num1 >= 5) num1 = 0;
        if(num2 >= 8) num2 = 0;
        if(num3 >= 10) num3 = 0;
    }
    cout << person[0] << " " << person[1] << " " << person[2] << " ";
    int max_c = max({person[0],person[1],person[2]});
    vector<int> answer;
    for(int i=0; i<3; i++){
        if(person[i]==max_c) answer.push_back(i+1);
    }
    return answer;
}