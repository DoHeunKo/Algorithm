#include<iostream>

using namespace std;

typedef long long ll;
int T;
ll pos;
string comp;
string s,preffix,suffix;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	cin >> comp;

	int sz = comp.size();

	pos = comp.find('*');

	preffix = comp.substr(0, pos);
	suffix = comp.substr(pos + 1);

	ll pre = pos;
	ll suf = sz - (pos + 1);

	for (int i = 0; i < T; i++) {
		cin >> s;
		int ret = 1;
		if (pre + suf > s.size()) {
			ret = 0;
		}
		else {
			if (preffix != s.substr(0, pos) || suffix != s.substr(s.size() - suf)) {
				ret = 0;
			}

		}
		if (ret == 1) {
			cout << "DA" << "\n";
		}
		else {
			cout << "NE" << "\n";
		}
	}
	

	return 0;
}