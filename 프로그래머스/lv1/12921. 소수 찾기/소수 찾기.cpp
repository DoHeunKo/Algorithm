#include <string>
#include <vector>
#include<iostream>
using namespace std;
vector<int> result;
bool isPrime(int number){
    if(number<=1)return false;
    if(number==2)return true;;
    if(number%2==0)return false;
    for(int j=2;j*j<=number;j++){
        if(number%j==0)return false;
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    for(int i=1;i<=n;i++){
        if(isPrime(i)){
            answer++;
        };
    }
    
    
    return answer;
}