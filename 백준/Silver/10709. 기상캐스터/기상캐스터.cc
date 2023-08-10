#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int max_n = 104;
int h, w;
int a[max_n][max_n];
string inp;
int main() {

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> inp;
        for (int j = 0; j < inp.size(); j++) {
            if (inp[j] == 'c') {
                a[i][j] = 0;
            }
            else {
                a[i][j] = -1;
            }
        }
    }

    

    for (int i = 0; i < h; i++) {
        bool flag = false;
        int cnt = 0;
        for (int j = 0; j < w; j++) {
            
            if (a[i][j] == 0) {
                flag = true;  
                cnt = 1;
            }

            else if (a[i][j] != 0 && flag == true) {
                a[i][j] = cnt;
                cnt++;
            }
            else {
                cnt++;
            }

        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}