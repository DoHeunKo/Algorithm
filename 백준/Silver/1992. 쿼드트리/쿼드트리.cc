#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

const int max_n = 70;
int n;
string str;
int a[max_n][max_n];

string recur(int y, int x, int _sz) {
    if (_sz == 1) {
        return string(1, a[y][x]);
    }
    char cur = a[y][x];
    string temp = "";
    for (int i = y; i < y + _sz; i++) {
        for (int j = x; j < x + _sz; j++) {
            if (cur != a[i][j]) {
                temp += '(';
                temp += recur(y, x, _sz / 2);
                temp += recur(y, x + _sz / 2, _sz / 2);
                temp += recur(y + _sz/2, x, _sz / 2);
                temp += recur(y + _sz/2, x + _sz/2, _sz / 2);
                temp += ')';
                return temp;
            }
        }
    }
    return string(1, a[y][x]);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            a[i][j] = str[j];
        }
    }

    string result=recur(0, 0, n);
    cout << result << '\n';
    return 0;
}