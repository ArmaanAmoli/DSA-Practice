#include<bits/stdc++.h>
using namespace std;

int digitRange(int num){
    int maxd = INT_MIN;
    int mind = INT_MAX;
    while(num >0){
        int digit = num%10;
        maxd = max(digit , maxd);
        mind = min(digit , mind);
        num = num/10;
    }
    return maxd-mind;
}

int maxDigitRange(vector<int>& nums) {
    int maxR = INT_MIN;
    unordered_map<int , int>m;
    for(auto&n:nums){
        int digitR = digitRange(n);
        m[digitR]+=n;
        maxR = max(maxR , digitR);
    }
    return m[maxR];
}

bool canBeFormed(string & s , string p){
    int i = 0 ;
    bool replaced = false;
    while(i<s.size()){
        if(s[i] != p[i]){
            if(replaced)return false;
            replaced = true;
        }
        i++;
    }
    return true;
}

void createSubSequence(string &t , int idx , string sub , set<string>&st , int&n){
    if(sub.size() == n){
        st.insert(sub);
        return;
    }
    if(idx>=t.size() || sub.size() + (t.size() - idx) < n)return;
    //pick
    createSubSequence(t , idx+1 , sub , st , n);
    sub.push_back(t[idx]);
    createSubSequence(t , idx+1 , sub , st , n);
    return;
}

bool canMakeSubsequence(string s, string t) {
    int n = s.size();
    int m = t.size();
    if(n > m)return false;
    // if(n = m) return s == t;

    set<string>st;
    int i = 0;
    int j = n-1;

    createSubSequence(t , 0 , "" , st , n);

    for(auto & sub : st){
        // cout<<sub<<endl;
        bool ans = canBeFormed(s , sub);
        if(ans)return true;
    }
    return false;
}



int main(){
    // vector<int>nums = {90,900};
    // cout<<maxDigitRange(nums)<<endl;
    cout<<canMakeSubsequence("zya" , "yzbbyz")<<endl;

}