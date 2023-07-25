#include<iostream>

using namespace std;

string s;
int sz;

int main() {
	cin >> s;
	sz = s.size();
	int res = 1;
	for (int i = 0; i < sz / 2; i++) {
		if (s[i] != s[sz - 1 - i]) {
			res = 0;
			break;
		}
	}
	cout << res << "\n";

	

	return 0;
}