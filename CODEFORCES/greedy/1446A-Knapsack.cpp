#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& weights , int n , long long W){
    long long currW = 0;
    long long target = (W + 1) / 2;

    unordered_map<int,vector<int>>m;
    for(int i = 0 ; i<weights.size() ; i++){
        if(weights[i]<=W &&  weights[i] >= target){
            return {i+1};
        }
        m[weights[i]].push_back(i+1);
    }

    sort(weights.begin() , weights.end());
    int i = n-1;

    vector<int> idx;

    while(i>=0 && currW < target){
        int weight = weights[i];
        if(!(weight > W || (weight + currW) > W)){
            currW = currW + weight;

            //finding index of weight;
            int iw = m[weight].back();
            idx.push_back(iw);
            m[weight].pop_back();
        }
        i--;
    }
    if(currW < target)return {};
    return idx;
}

int main(){

    int N;
    cin>>N;
    vector<vector<int>> result;
    for(int i=0 ; i<N ; i++){
        int n ; long long W;
        cin>>n;
        cin>>W;

        vector<int> weights(n);

        for(int & i : weights){
            cin>>i;
        }

        vector<int> idx = solve(weights , n , W);
        result.push_back(idx);
    }

    for(auto &v : result){
        if(v.empty()){
            cout<< -1<<endl;
        }
        else{
            cout<< v.size()<<endl;
            for(int i= v.size()-1 ; i>=0 ; i--){
                cout<< v[i]<<" ";
            }
            cout<<endl;
        }
    }

}