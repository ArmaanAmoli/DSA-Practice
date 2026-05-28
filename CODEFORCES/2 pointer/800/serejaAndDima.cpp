#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i<n ; i++){
        cin>>v[i];
    }

    int l=0 , r=n-1;
    int sereja = 0;
    int dima = 0;
    int sereja_turn = 1;
    while(l <=r){
        int score = v[l] > v[r] ? v[l] : v[r];
        if(sereja_turn)sereja+=score;
        else dima += score;
        sereja_turn = !sereja_turn;
        if(v[l] > v[r]){
            l++;
        }
        else r--;
    }

    cout << sereja << " " << dima;
}