#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char>num;
    for (int i = 0; i < number.size(); i++) {
        while (!num.empty() && num.back() < number[i] && k > 0) {
            num.pop_back();
            k--;
        }
        num.push_back(number[i]);
    }

    if(k>0){
        for(int i=0; i<k; i++) num.pop_back();
    }
    for(int i=0; i<num.size(); i++) {
        answer += num[i];
    }
    return answer;
}