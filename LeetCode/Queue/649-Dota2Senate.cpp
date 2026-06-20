#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>r;
        queue<int>d;
        int n = senate.size();

        for(int i = 0; i < senate.size() ; i ++ ){
            if(senate[i] == 'R'){
                r.push(i);
            }
            else{
                d.push(i);
            }
        }

        while( !r.empty() && !d.empty() ){
            int rt = r.front();
            int dt = d.front();
            if(rt<dt){
                r.push(rt + n);
                r.pop();
                d.pop();
            }
            else{
                d.push(dt + n);
                d.pop();
                r.pop();
            }
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};

int main(){

}