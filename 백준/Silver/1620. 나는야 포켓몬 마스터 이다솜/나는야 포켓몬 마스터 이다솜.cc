#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int cnt, t;
string name;
string q;
unordered_map<int, string> mp1;
unordered_map<string, int> mp2;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> cnt >> t;

    for (int i = 0; i < cnt; i++) {
        cin >> name;
        mp1[i + 1] = name;
        mp2[name] = i + 1;
    }
    
    for (int i = 0; i < t; i++) {
        cin >> q;
        if (!atoi(q.c_str())) {
            cout << mp2[q] << "\n";
        }
        else {
            cout << mp1[atoi(q.c_str())] << '\n';
        }
    }
    
    return 0;
}