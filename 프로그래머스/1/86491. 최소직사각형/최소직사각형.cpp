#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    vector<int>w;
    vector<int>h;
    int num = sizes.size()-1;
    for(int i=0; i<sizes.size(); i++){
        if(sizes[i][0]>sizes[i][1]) {
            w.push_back(sizes[i][0]);
            h.push_back(sizes[i][1]);
            }
        else {
            w.push_back(sizes[i][1]);
            h.push_back(sizes[i][0]);
        }
    }
    sort(w.begin(), w.end());
    sort(h.begin(), h.end());
    int answer =w[num]*h[num];
    return answer;
}