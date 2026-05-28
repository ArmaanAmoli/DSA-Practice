#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isEven(int i){
    return i%2==0;
}

vector<int> countOppositeParity(vector<int>& nums) {
    int n = nums.size();
    if(n==1)return {0};
    vector<int> result(n);
    int even = 0 ;
    int odd = 0;
    for(int i = 0 ; i<n ; i++){
        int num = nums[i];
        if(isEven(num)) even++;
        else odd++;
    }
    for(int i = 0 ; i<n ; i++){
        int num = nums[i];
        if(isEven(num)){
            result[i] = odd;
            even--;
        }
        else{
            result[i] = even;
            odd--;
        }
    }
    return result;

}

int main(){

    vector<int> nums = {1,2,3,4};
    vector<int>result = countOppositeParity(nums);
    for(auto& i : result){
        cout<<i<<" ";
    }

}