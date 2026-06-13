#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int solve(vector<int> &fence , int &k){
    int j = k - 1;

    if(k > fence.size()){
        return -1;
    }

    int ans = 0;
    int minSum = 0;
    
    int sum = 0;

    for(int k =0 ; k<=j ; k++){
        sum+= fence[k];
    }

    minSum = sum;

    for(int i=1 ; i<=(fence.size()-k) ; i++){
        sum -= fence[i-1];
        sum += fence[i+k-1];
        if(sum < minSum){
            minSum = sum;
            ans = i;
        }
    }

    return ans+1;
    
}

int main(){
    int n , k;
    cin>>n;
    cin>>k;
    vector<int> fence(n);
    for(auto & i : fence){
        cin>>i;
    }

    int ans = solve(fence , k);
    cout<<(ans);

}