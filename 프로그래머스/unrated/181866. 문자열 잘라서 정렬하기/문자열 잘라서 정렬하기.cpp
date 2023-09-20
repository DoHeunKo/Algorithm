#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;

    istringstream ss(myString);
    string buffer;
    while (getline(ss, buffer, 'x')) {
        if(buffer!=""){
            answer.push_back(buffer);
        }
        
    }

    sort(answer.begin(), answer.end());

    return answer;

}