#include<iostream>

using namespace std;

int arr[104];
int from, to;
int a, b, c;
int ret=0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;

	for (int i = 0; i < 3; i++) {
		cin >> from >> to;
		for (int j = from; j < to; j++) {
			arr[j]++;
		}
	}

	for (int i = 0; i < 104; i++) {
		if (arr[i] == 1) {
			ret += a;
		}
		else if (arr[i] == 2) {
			ret +=  2*b;
		}
		else if (arr[i] == 3) {
			ret += 3*c;
		}
		else {
			continue;
		}
	}
	cout << ret << "\n";
	return 0;
}