#include<iostream>

using namespace std;

int n, m,cnt;
int idx;
int a[14];
int l, r;
int ret;
int main() {
    cin >> n >> m >> cnt;
    l = 1;
    for (int i = 0; i < cnt; i++) {
        cin >> idx;
        r = l + m - 1;
        if (idx >= l && idx <= r) {
            continue;
        }
        if (idx < l) {
            ret += l - idx;
            l = idx;
        }
        if (idx > r) {
            ret += idx - r;
            l += idx - r;
        }
    }
    cout << ret << "\n";
    return 0;
}