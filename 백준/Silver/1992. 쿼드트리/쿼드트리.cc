#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int max_n = 70;

char a[max_n][max_n];
int t;
string str;
string result;

string go(int y, int x, int _sz) {
    
    if (_sz == 1) return string(1, a[y][x]);
    
    char temp = a[y][x];
    for (int i = y; i < y + _sz; i++) {
        for (int j = x; j < x + _sz; j++) {
            string ret = "";
            if (temp != a[i][j]) {
                ret += '(';
                ret += go(y, x, _sz / 2);
                ret += go(y, x + _sz / 2, _sz / 2);
                ret += go(y + _sz / 2, x, _sz / 2);
                ret += go(y + _sz / 2, x + _sz / 2, _sz / 2);
                ret += ')';
                return ret;
            }
        }
    }
    return string(1, a[y][x]);

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            a[i][j] = str[j];
        }
    }
    
    result=go(0, 0, t);

    cout << result << '\n';

    return 0;
}