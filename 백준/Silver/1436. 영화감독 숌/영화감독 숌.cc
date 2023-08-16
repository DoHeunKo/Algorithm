#include<bits/stdc++.h>

using namespace std;

int n;
int ret;
int i = 666;
int main() {
    cin >> n;
    while (1) {
        if (to_string(i).find("666") != string::npos) {
            n--;
        }
        if (n == 0)break;
        i++;
    }
    cout << i << '\n';

    return 0;
}