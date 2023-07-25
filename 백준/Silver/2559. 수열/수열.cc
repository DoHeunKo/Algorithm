#include<iostream>

using namespace std;

int n, k;
int temp;
int psum[100004];
int max_n =-1000000;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> temp;
		psum[i] = psum[i - 1] + temp;
	}
	
	for (int i =k; i <=n; i++) {
		max_n = max(max_n, psum[i] - psum[i - k]);
	}
	cout << max_n << '\n';

	return 0;
}