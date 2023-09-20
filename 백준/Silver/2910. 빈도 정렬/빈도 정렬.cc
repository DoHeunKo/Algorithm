#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
int n, c, num;
map<int, int> mp1;//<숫자,빈도>
map<int, int> mp2;//<숫자,순서>

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (mp1[a.first] == mp1[b.first]) {
        return mp2[a.first] < mp2[b.first];
    }
    return mp1[a.first] > mp1[b.first];
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> num;
        mp1[num]++;
        if (mp2[num] == 0) {
            mp2[num] = i + 1;
        }
    }
    
    vector<pair<int, int>> v;
    for (auto ele : mp1) {
        v.push_back({ ele.first,ele.second });
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> result;
    for (auto ele : v) {
        for (int i = 0; i < ele.second; i++) {
            result.push_back(ele.first);
        }
    }
    for (auto ele : result) {
        cout << ele << ' ';
    }
    return 0;
}