#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool is_even(int num){return (num%2==0);}

bool uniformArray(vector<int>& nums1) {
    vector<int>even;
    vector<int> odd;
    bool ans = false;
    for(int i=0 ; i<nums1.size() ; i++){
        if(nums1[i]%2==0)even.push_back(nums1[i]);
        else odd.push_back(nums1[i]);
    }
    if(odd.empty() || even.empty())return true;

    sort(odd.begin() , odd.end());
    sort(even.begin() , even.end());

    vector<int> nums2_even(nums1.size() , -1);
    bool even_possible = true;
    for(int i = 0 ; i<nums2_even.size() ; i++){
        if(is_even(nums1[i])){
            nums2_even[i] = nums1[i];
        }
        else{
            bool exist = false;
            for(int j=0 ; j<odd.size() ; j++){
                if(odd[j]!= nums1[i] && odd[j]< nums1[i]){
                    exist = true;
                    break;
                }
            }
            if(exist == false){
                even_possible = false;
                break;}
        }
    }

    vector<int> nums2_odd(nums1.size() , -1);
    bool odd_possible = true;
    for(int i = 0 ; i<nums2_odd.size() ; i++){
        if(!is_even(nums1[i])){
            nums2_odd[i] = nums1[i];
        }
        else{
            bool exist = false;
            for(int j=0 ; j<odd.size() ; j++){
                if(odd[j]< nums1[i]){
                    exist = true;
                    break;
                }
            }
            if(exist == false){
                odd_possible=false;
                break;}
        }
    }
    return (odd_possible||even_possible);
}

int main()
{  
    vector<int> v = {1,4,7};
    cout<<uniformArray(v);

}