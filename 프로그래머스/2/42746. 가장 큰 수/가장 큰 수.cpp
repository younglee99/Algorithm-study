#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    vector<string>number_str;
    for(int i=0; i<numbers.size(); i++){
        number_str.push_back(to_string(numbers[i]));
    }
    sort(number_str.begin(), number_str.end(), compare);
    string answer;
    for(int i=0; i<numbers.size(); i++){
        answer += number_str[i];
    }
    if(number_str[0]=="0") return "0";
    return answer;
}