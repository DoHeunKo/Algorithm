#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

map<string, int> mp;
string k1, k2;
int t;
int n;
int kind;

int main() {
    cin >> t;
    while(t--){
        mp.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> k1 >> k2;
            mp[k2]++;
            
        }
        int ret = 1;
        for (auto ele : mp) {
            ret *= (ele.second + 1);
        }
        ret--;

        cout << ret << '\n';
        
    }

}