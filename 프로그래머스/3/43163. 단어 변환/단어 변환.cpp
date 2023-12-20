#include <string>
#include <vector>

bool visited[50] = {false};
int answer = 100;
using namespace std;

void dfs(string begin, string target, int cnt, vector<string> words){
    if(begin == target) {
        answer = min(answer, cnt);
        return;
    }
    for(int i=0; i< words.size(); i++){
        if(visited[i]==true) continue;
        int wrong = 0;
        for(int j=0; j<begin.size(); j++){
            if(words[i][j] != begin[j]) wrong++;
        }
        if(wrong == 1){
            visited[i] = true;
            dfs(words[i], target, cnt+1, words);
            visited[i]= false;        
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    
    dfs(begin, target, 0, words);
    if(answer == 100) answer = 0;
    return answer;
}