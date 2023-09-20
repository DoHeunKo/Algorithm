#include <string>
#include <vector>
#include <iostream>
#include <map>
#include<algorithm>
using namespace std;

map<string,int> mp1;
map<int,string> mp2;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    for (int i = 0; i < players.size(); i++) {
        //cout << players[i] << '\n';
        mp1[players[i]] = i + 1;
        mp2[i + 1] = players[i];
    }
    

    for (int i = 0; i < callings.size(); i++) {
        string str = callings[i];
        int cur = mp1[str];//4
        int new_cur = cur - 1;
        string temp = mp2[cur];//kai
        string temp2 = mp2[new_cur];//poe
        mp1[temp]--;
        mp1[temp2]++;
        mp2[cur] = temp2;
        mp2[new_cur] = temp;
        
    }
    
    for (auto ele : mp2) {
        
        answer.push_back(ele.second);
    }
    
    return answer;
}