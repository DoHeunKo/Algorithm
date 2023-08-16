#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int t;
string inp;

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> inp;
        stack<char> st;
        for (int j = 0; j < inp.size(); j++) {
            if (inp[j] == '(')st.push(inp[j]);
            else {
                if (!st.empty())st.pop();
                else {
                    st.push(inp[j]);
                    break;
                }
            }
        }
        if (!st.empty())cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}