#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{   
    int max_p=0;
    int pick = nums.size()/2;
    set<int>po(nums.begin(),nums.end());
    for(int i=0; i<po.size(); i++) max_p++;
    cout << max_p;
    if(pick>max_p) return max_p;
    else return pick;
    
}