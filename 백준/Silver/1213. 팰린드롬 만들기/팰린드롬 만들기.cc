#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
string str;
int a[26];
string result;
map<char, int> mp;
int main() {

    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        mp[str[i]]++;
    }
    /*for (int i = 0; i < 26; i++) {
        cout << a[i] << '\n';
    }*/
    
    pair<char, int>odd;
    
    for (auto ele : mp) {
        if (ele.second % 2 != 0) {
            odd.first = ele.first;
            odd.second++;
        }
    }
    if (odd.second >= 2) {
        cout << "I'm Sorry Hansoo" << '\n';
    }
    else {
        //홀수 1개일때
        //cout <<odd.first<< ' ' << odd.second;
        
        if (odd.second != 0) {
            
            result += odd.first;
            mp[odd.first]--;
            
            for (int i = 'Z'; i >= 'A'; i--) {
                if (mp[i] % 2 == 0) {
                    while (mp[i] > 0) {
                        result.insert(0, 1, i);
                        mp[i]--;
                        result += i;
                        mp[i]--;
                    }
                }
            }
        }
        //홀수 0개일때
        else {
            for (int i = 'Z'; i >= 'A'; i--) {
                if (mp[i] % 2 == 0) {
                    while (mp[i] > 0) {
                        result.insert(0, 1, i);
                        mp[i]--;
                        result += i;
                        mp[i]--;
                    }
                }
                
               
            }
        }
         
        
        
    }
    cout << result << "\n";
    return 0;
}