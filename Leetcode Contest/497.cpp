#include<bits/stdc++.h>
using namespace std;

int longestBalanced(string s){
    int one = 0;
    int zero = 0;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i]=='1')one++;
        else zero++;
    }
    if(one == zero)return s.size();
    if(one==0 || zero==0) return 0;

    int ans = 0;
    
    int windowSize = min(one , zero)*2;
    while(windowSize>1){
        for(int i=0 ; i<= s.size()-windowSize ; i++){
            int j = i + windowSize - 1;
            
        }
    }
}

// vector<int> findDegrees(vector<vector<int>>& matrix) {
//     vector<int>ans(matrix.size());
//         for(int i =0 ; i<matrix.size() ; i++){
//             int degree = 0;
//             for(int j=0 ; j<matrix[0].size() ; j++){
//                 if(matrix[i][j]==1){
//                     degree++;
//                 }
//             }
//             ans[i]=degree;
//         }
//         return ans;
//     }

int main(){
    
}