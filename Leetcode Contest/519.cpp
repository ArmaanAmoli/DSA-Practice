#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
    for(int i =0 ; i<n ; i++){
        int shift = rowShift[i];
        int buffer = grid[i][0];
        int j = 0;
        int count =0;
        while(count<n){
            int newIdx = (j - shift + n)%n;
            int temp = grid[i][newIdx];
            grid[i][newIdx] = buffer;
            buffer=temp;
            j=(newIdx - shift + n)%n ;
            count++;
        }
    }
    for(int i =0 ; i<n ; i++){
        int shift = colShift[i];
        int buffer = grid[0][i];
        int j = 0;
        int count =0;
        while(count<n){
            int newIdx = (j - shift + n)%n;
            int temp = grid[newIdx][i];
            grid[newIdx][i] = buffer;
            buffer=temp;
            j=(newIdx - shift + n)%n ;
            count++;
        }
    }
    return grid;
}

int main(){
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> rowShift = {1,2,0} , colShift = {2,2,1};
    int n = 3;
    cyclicShift(n , grid , rowShift , colShift);
    for(int i = 0 ; i<n ; i++){
        for(int j =0 ; j<n ; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}