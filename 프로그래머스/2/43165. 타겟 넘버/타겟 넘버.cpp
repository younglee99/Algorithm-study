#include <string>
#include <vector>

using namespace std;
int answer = 0;
void dfs(int cnt, int num, int target, vector<int> numbers){
    if(cnt == numbers.size()){
        if(num == target) answer++;
        return;
    }
    dfs(cnt+1, num+numbers[cnt], target, numbers);
    dfs(cnt+1, num-numbers[cnt], target, numbers);
}

int solution(vector<int> numbers, int target) {
    dfs(0, 0, target, numbers);
    return answer;
}