#include<iostream>

using namespace std;
typedef long long ll;

ll num;

int main() {

	
	while (cin >> num) {

		ll cnt = 1;
		ll ret = 1;
		while (true) {
		if (cnt % num == 0) {
			cout << ret << "\n";
			break;
		}
		else {
			cnt = cnt * 10 + 1;
			cnt %= num;
			ret++;
		}

		}
	}

	return 0;
}