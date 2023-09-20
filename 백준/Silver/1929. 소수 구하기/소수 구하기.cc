#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int from, to;
vector<int> result;

bool isPrime(int n) {
    if (n <= 1)return false;
    if (n == 2)return true;
    if (n % 2 == 0)return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> from >> to;

    for (int i = from; i <= to; i++) {
        if (isPrime(i)) {
            result.push_back(i);
        }
    }
    for (auto ele : result) {
        cout << ele << "\n";
    }
    return 0;
}