#include <string>
#include <vector>
#include<iostream>
using namespace std;

string solution(string my_string, int s, int e) {
    string answer = "";
    string temp=my_string.substr(s,e-s+1);
    
    cout << temp <<'\n';
    string temp2="";
    for(int i=0;i<temp.size();i++){
        temp2+=temp[temp.size()-1-i];
    }
    
    cout << temp2<<'\n';
    my_string.replace(my_string.find(temp),temp.size(),temp2);
    cout << my_string<<'\n';
    answer=my_string;
    return answer;
}