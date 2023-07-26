#include<bits/stdc++.h>

using namespace std;
vector<int> v;
int n, m, num;
int cnt = 0;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
        
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (v[i]+v[j]==m) {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}