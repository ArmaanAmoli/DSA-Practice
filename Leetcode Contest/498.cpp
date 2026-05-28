#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// int firstStableIndex(vector<int>& nums, int k)
// {   int n = nums.size();
//     vector<int> maxv(n);
//     vector<int> minv(n);
//     vector<int> maxvr(n);
//     vector<int> minvr(n);
    
//     int max = INT_MIN;

//     int minr = INT_MAX;

//     for(int i=0 ; i<n ; i++){
//         if(nums[i]>max){
//             max = nums[i];
//         }
//         maxv[i] = max;

//         int j = n-1-i;
//         if(nums[j] < minr){
//             minr = nums[j];
//         }
//         minvr[j] = minr;
//     }

//     for(int i = 0 ; i<n ; i++){
//         int instability_score = maxv[i] - minvr[i];
//         if(instability_score<=k){
//             // cout<<instability_score<<endl;
//             return i;}
//     }
//     return -1;
// }

vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources)
{
    vector<vector<int>>adj (n , vector<int>(m,0));
    priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>>pq;
    for(auto &it:sources){
        int r = it[0];
        int c = it[1];
        int color = it[2];
        adj[r][c]=color;
        pq.push({color , {r , c}});
    }

    vector<int>a = {1, -1 , 0 , 0}; // rows
    vector<int>b = {0 , 0 , 1 , -1}; // cols

    while(!pq.empty()){
        vector<pair<int,pair<int,int>>> points;
        while(!pq.empty()){
            points.push_back(pq.top());
            pq.pop();
        }
        for(auto &point:points){
            int row = point.second.first;
            int column = point.second.second;
            int color = point.first;
            for(int i=0 ; i<4 ; i++){
                int new_row = row + a[i];
                int new_column = column + b[i];

                if(new_row<n && new_column<m && new_row>=0 && new_column>=0 && adj[new_row][new_column]==0){
                    adj[new_row][new_column] = color;
                    pq.push({color , {new_row , new_column}});
                }
            }
        }
    }
    return adj;
}
int main(){
    vector<vector<int>> nums = {{0,0,1} , {2,2,2}};
    vector<vector<int>> o = colorGrid(3,3,nums);
    for(int i = 0 ; i<3 ; i++){
        for(int j= 0 ; j<3 ; j++){
            cout<<o[i][j]<<" ";
        }
        cout<<endl;
    }
}