#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1; i< yellow; i++){
        if(yellow % i ==0){
            int num = yellow/i;
            if((i+num)*2+4 == brown){
                if(i>num){
                    answer.push_back(i+2);
                    answer.push_back(num+2);
                }
                else{
                    answer.push_back(num+2);
                    answer.push_back(i+2);
                }
                return answer;
            }
        }
    }
    
}