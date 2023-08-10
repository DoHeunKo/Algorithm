#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define prev dh

using namespace std;

int t, team;
string scoreT;
int A, B;
int Ascore, Bscore;
string prev;

string print(int result) {
    string mm = "00" + to_string(result / 60);
    string ss = "00" + to_string(result % 60);
    return mm.substr(mm.size() - 2, 2) + ":" + ss.substr(ss.size() - 2, 2);
}

int changeToInt(string toSecond) {

    return atoi(toSecond.substr(0, 2).c_str()) * 60 + atoi(toSecond.substr(3, 2).c_str());
}

void go(int& score, string scoreT) {
    score += (changeToInt(scoreT) - changeToInt(prev));
}

int main() {

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> team >> scoreT;
        if (A > B)go(Ascore, scoreT);
        else if (B > A)go(Bscore, scoreT);
        team == 1 ? A++ : B++;
        prev = scoreT;
    }
    if (A > B)go(Ascore, "48:00");
    else if (A < B)go(Bscore, "48:00");


    cout << print(Ascore) << '\n';
    cout << print(Bscore) << '\n';

    return 0;
}