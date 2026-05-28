#include<bits/stdc++.h>
using namespace std;

bool is_vowel(char c){
    if(c=='a' || c=='e' ||c=='i' ||c=='o' ||c=='u') return true;
    return false;
}

string trimTrailingVowels(string s)
{
    int last = s.size()-1;
    while(last>=0 && is_vowel(char(s[last]))) {
        last--;
        s.pop_back();
    }
    cout<<s<<endl;
    return s;
}

int minCost(int n) {
    if(n == 1)return 0;
    if(n==2) return 1;
    int a = n/2;
    int b = n - a;
    return (a*b) + minCost(a) + minCost(b);
}

int main(){
    // string s = "idea";
    // cout<<s<<endl;
    // cout<<trimTrailingVowels(s);
    cout<<minCost(4);
    return 0;
}