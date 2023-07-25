#include<iostream>

using namespace std;

int a[26];
string s;
int main() {
	cin >> s;

	int sz = s.size();

	for (int i = 0; i < sz; i++) {
		a[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << a[i] << ' ';
	}
	return 0;
}