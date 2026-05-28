#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// vector<int> findValidElements(vector<int>& nums) {
//     int n = nums.size();
//     if (n==1) return nums;
//     vector<int> maxv(n,INT_MIN);
//     vector<int> maxv2(n,INT_MIN);

//     int m = nums[0];
//     for(int i = 0 ; i<n ; i++){
//         if(m<nums[i]){
//             m = nums[i];
//         }
//         maxv[i] = m;
//     }

//     m = nums[n-1];
//     for(int i = n-1 ; i>=0 ; i--){
//         if(m<nums[i]){
//             m = nums[i];
//         }
//         maxv2[i] = m;
//     }

//     vector<int> ans;
//     ans.push_back(nums[0]);
//     for(int i=1 ; i<n-1 ; i++){
//         int num = nums[i];
//         bool c1 = num>maxv[i-1];
//         bool c2 = num>maxv2[i+1];

//         if(c1 || c2) ans.push_back(num);
//     }
//     ans.push_back(nums[n-1]);
//     return ans;
// }

bool is_vowel(char c){
    if(c=='a' || c=='e' ||c=='i' ||c=='o' ||c=='u' ) return true;
    return false;
}
string sortVowels(string s) {

    string finalStr = "";
    vector<int> vowelIdx;
    unordered_map<char , int> m;

    for(int i = 0 ; i<s.size() ; i++){
        if(is_vowel(s[i])){
            vowelIdx.push_back(i);
            m[s[i]]+=1;
        }
    }

    unordered_set<char> sets;
    vector<char> priority = {};

    for(auto & i : vowelIdx){
        char c = s[i];
        if(sets.find(c) == sets.end()){
            sets.insert(c);
            priority.push_back(c);
        }
    }
    
    stable_sort(priority.begin(), priority.end(), [&](char a, char b){
        return m[a] > m[b];
    });

    for (char c : priority) {
        string vow(m[c], c);
        finalStr+= vow;
    }

    string ans = "";
    int j = 0;
    for(int i=0 ; i<s.size() ; i++){
        if(is_vowel(s[i])){
            ans.push_back(finalStr[j]);
            j++;
        }
        else{
            ans.push_back(s[i]);
        }
    }
    return ans;
}


int main(){

    // vector<int> nums = {1,2,4,2,3,2};
    // vector<int> ans = findValidElements(nums);
    // for(auto & i : ans){
    //     cout<<i<<" ";
    // }
    string s = "baeiou";
    cout<<sortVowels(s)<<endl;

}