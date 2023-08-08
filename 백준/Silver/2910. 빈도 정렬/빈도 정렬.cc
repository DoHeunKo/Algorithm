//2828
//custom operator 정리
// 1순위 count 2순위 같을떄 먼저나온것
// map의 특성완벽하게 알아야 풀수 있음
//

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int n, c;
map<int, int> mp;
map<int, int> mp2;
int num;
vector<pair<int, int>> v;

int cmp(pair<int,int>a, pair<int,int>b) {
    if (a.second == b.second) {
        return mp2[a.first] < mp2[b.first];
    }
    return a.second > b.second;
}

int main() {

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> num;
        mp[num]++;
        if (mp2[num] == 0) {
            mp2[num] = i + 1;
        }
    }

    for (auto ele : mp) {
        v.push_back({ ele.first,ele.second });
    }
    
    sort(v.begin(), v.end(), cmp);

    //v.first : 값 , v.second : cnt만큼 들어온순으로 정렬

    

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].second; j++) {
            cout << v[i].first << ' ';
        }
    }


    /*for (auto ele : mp) {
        cout << ele.first << ' ' << ele.second << '\n';
    }
    cout << "\n";   

    for (auto ele : mp2) {
        cout << ele.first << ' ' << ele.second << '\n';
    }*/

    return 0;
}