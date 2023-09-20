#include <string>
#include <vector>
#include <map>
#include<iostream>
#include<algorithm>
using namespace std;
map<string,char>mp;
int N;
bool cmp(const pair<string,char> a,const pair<string,char>b){
    if(a.first[N]==b.first[N])return a.first<b.first;
    return a.second<b.second;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    N=n;
    for(int i=0;i<strings.size();i++){
        char alp=strings[i][n];
        mp[strings[i]]=alp;
    }
    
    vector<pair<string,char>> v;
    for(auto ele : mp){
        v.push_back({ele.first,ele.second});
    }
    
    sort(v.begin(),v.end(),cmp);
    for(auto ele : v){
        answer.push_back(ele.first);
    }
    
    return answer;
}