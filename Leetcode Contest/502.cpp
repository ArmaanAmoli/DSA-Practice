#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isAdjacentDiffAtMostTwo(string s) {
        for(int i = 0 ; i<s.size()-1 ; i++){
            int c1 = s[i] - '0';
            int c2 = s[i+1] - '0';
            int diff = abs(c1-c2);
            if(diff>2)return false;
        }
        return true;
    }


int countKthRoots(int l, int r, int k) {

    int count = 0;
    ll current = 0;
    int i = l==0 ? 0 : pow(l, 1.0/k);
    while(true){
        current = pow(i , k);
        if(current > r)break;
        if(current <=r && current >=l) count++;
        i++;
    }
    return count;
        
}

int main(){
    cout<<countKthRoots(0 , 26 , 2);
    return 0;
}