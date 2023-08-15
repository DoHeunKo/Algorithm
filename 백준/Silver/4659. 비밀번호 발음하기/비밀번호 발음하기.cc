#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string str;

bool isV(char alp) {
    return alp == 'a' || alp == 'e' || alp == 'i' || alp == 'o' || alp == 'u';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> str) {
        if (str == "end") {
            break;
        }
        bool inc_v = false;
        bool flag = false;
        int zcnt = 0;
        int mcnt = 0;
        char prev ='0';

        for (int i = 0; i < str.size(); i++) {
            if (isV(str[i])) {
                inc_v = true;
                mcnt++;
                zcnt = 0;
            }
            else {
                mcnt = 0;
                zcnt++;
            }
            if (mcnt == 3 || zcnt == 3) {
                flag = true;
            }
            
            if (i >= 1 && prev == str[i] && (str[i] != 'o' && str[i] != 'e')) {
                flag=true;
            }
            
            prev = str[i];
        }

        if (!inc_v)flag = true;
        if(flag)cout << "<" << str << ">" << " is not acceptable.\n";
        else cout << "<" << str << ">" << " is acceptable.\n";
    }

    return 0;
}