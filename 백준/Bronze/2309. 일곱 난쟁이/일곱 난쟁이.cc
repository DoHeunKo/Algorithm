#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n = 9;
pair<int, int> p;
int a[9];
int height;
int sum;
vector<int> res;
int main() {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == sum - 100) {
				p.first = a[i];
				p.second = a[j];
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (a[i] == p.first || a[i] == p.second) {
			continue;
		}
		res.push_back(a[i]);
	}
	sort(res.begin(), res.end());
	for (int ele : res) {
		cout << ele << '\n';

	}
	return 0;
}