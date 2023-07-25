
#include<iostream>
#include<string>
using namespace std;

string s;
string res;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	getline(cin, s);
	int sz = s.length();

	for (int i = 0; i < sz; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			if (s[i] + 13 > 'Z') {
				res += ((s[i] + 13)-26);
			}
			else {
				res += (s[i] + 13);
			}
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			if (s[i] + 13 > 'z') {
				res += ((s[i] + 13) - 26);
			}
			else {
				res += (s[i] + 13);
			}
		}
		else {
			res += s[i];
		}
	}
	cout << res;

	return 0;
}