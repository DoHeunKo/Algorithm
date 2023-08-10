#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int t;
string str;
vector<string> v;

//숫자,알파벳 -> 아스키코드, 범위 (int형 or 문자열)?
//최대 100글자 ->문자열로 구현
//0에 대한 처리 ->문자열 함수로


//문자열 커스텀 정렬
bool cmp(string a, string b) {
    //2순위
    if (a.size() == b.size()) {
        return a < b;
    }

    return a.size() < b.size(); //숫자로된 문자열 길이(1순위)
}

//0처리 , vector추가
string go(string temp) {
    while (true) {
        if (temp.size() && temp.front() == '0') {
            temp.erase(temp.begin());
        }
        else {
            break;
        }
        
    }
    if (temp.size() == 0)temp = "0";

    v.push_back(temp);
    
    temp = "";
    return temp;
}

int main() {

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> str;
        string temp = "";
        for (int j = 0; j < str.size(); j++) {
            //숫자일경우 temp에 추가
            if (str[j] < 65) temp += str[j];
            //숫자가 여러개일 경우있기때문에 요소별로 처리 필요
            // else if라는 분기처리가 상당히 중요
            // 이유 : 숫자인경우 temp에 추가하는데 이어서 숫자
            //가 나오는 경우에는 0처리와 벡터추가에 대한 함수로 
            //들어가면 안되기 때문에!
            else if (!temp.empty())temp=go(temp);

        }
        //다 숫자일 경우
        if(!temp.empty())temp=go(temp);
    }

    sort(v.begin(), v.end(), cmp);

    for (auto ele : v) {
        cout << ele << '\n';
    }
    
    return 0;
}