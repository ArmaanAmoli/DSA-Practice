#include<bits/stdc++.h>
using namespace std;


bool checkGoodInteger(int n) {
    int sumSquare = 0;
    int sum = 0;
    while(n!=0){
        int digit = n%10;
        sum += digit;
        sumSquare += (digit*digit);
        n=n/10;
    }
    int diff = sumSquare - sum;
    if(diff>=50)return true;
    return false;
}

int getLength(vector<int>& nums) {
    unordered_map<int,int> freq;
    bool allSame = true;
    int maxFreq = 0;
    for(int i = 0 ; i<nums.size() ; i++){

        freq[nums[i]]+=1;
        maxFreq= max(maxFreq , freq[nums[i]]);
        if(i!= nums.size()-1 && nums[i]!=nums[i+1])allSame=false;

    }
    if(maxFreq == 1) return 1;

    if(allSame)return nums.size();

    vector<int> subarr;
    for(auto& p : freq){
        if( p.second == maxFreq){
            subarr.push_back(p.first);
            subarr.push_back(p.first);
        }
        else{
            subarr.push_back(p.first);
        }
    }

    return subarr.size();
    
}

int main(){
    vector<int> v = {1,2,3,4};
    cout<<getLength(v);
}