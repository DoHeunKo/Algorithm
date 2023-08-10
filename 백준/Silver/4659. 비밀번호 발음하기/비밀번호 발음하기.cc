#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string inp;

//모음인 경우
bool isVow(char str) {
    return str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u';
}


int main() {

    while (cin >> inp) {
        if (inp == "end") {
            break;
        }
        bool include_v = false;
        int gcnt = 0;
        int mcnt = 0;
        char prev = '0';
        bool flag = false;
        for (int i = 0; i < inp.size(); i++) {
            if (isVow(inp[i])) {
                mcnt++;
                gcnt = 0;
                include_v = true;
            }
            else {
                gcnt++;
                mcnt = 0;
            }
            if (gcnt == 3 || mcnt == 3) {
                flag = true;
            }
            //두글자 이상 , 이전의 값과 같을 때, e나 o가 아닐때
            if (i >= 1 && prev == inp[i] && (inp[i] != 'e' && inp[i] != 'o')) {
                flag = true;
            }
            prev = inp[i];
        }

        if (include_v == 0) flag = 1;
        if (flag) cout << "<" << inp << ">" << " is not acceptable.\n";
        else cout << "<" << inp << ">" << " is acceptable.\n";
        
    }

    return 0;
}