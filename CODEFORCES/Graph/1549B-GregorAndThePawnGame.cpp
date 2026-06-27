#include<bits/stdc++.h>
using namespace std;

int solve(string &georg , string &enemy){
    int count = 0;
    for(int i =0 ; i<(int)georg.size() ; i++){
        if(georg[i]=='1'){
            if(enemy[i]=='0'){
                count++;
                enemy[i] = '2';
            }
            else{
                if(i-1 >=0 && enemy[i-1] == '1'){
                    enemy[i-1]='2';
                    count++;
                }
                else if( i+1 < (int)enemy.size() && enemy[i+1] == '1'){
                    enemy[i+1]='2';
                    count++;
                }
            }
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    cin.ignore();
    vector<int> result(t);
    for(int i = 0 ; i<t ; i++){
        int n;
        cin >> n;
        cin.ignore();
        string georg , enemy;
        getline(cin , enemy);
        getline(cin , georg);
        result[i]=solve(georg , enemy);
    }
    for(int&i:result){
        cout<<i<<endl;
    }
}