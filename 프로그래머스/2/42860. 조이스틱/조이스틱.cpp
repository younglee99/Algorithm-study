#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    vector<char> al = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    int answer = 0;
    for(int i=0; i<name.size(); i++){
        for(int j=0; j<al.size(); j++){
            if(name[i]==al[j]) {
                if(j>13) answer += 26-j;
                else answer += j;
            }
        }
    }
    int len = name.size();
    int move = len - 1;
    int next;
    for(int i=0; i< len; i++){
        next = i+1;
        while(next < len && name[next]== 'A') next++;
        move = min(move, i+(len-next)+min(i, len - next));
    }
    answer += move;
    return answer;
}