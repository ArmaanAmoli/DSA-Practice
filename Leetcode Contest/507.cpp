#include<bits/stdc++.h>
using namespace std;

// unordered_map<char, pair<int,int> > m;

// int dist(pair<int,int>& newPosition){
//     return abs(newPosition.first) + abs(newPosition.second);
// }

// int solve(string & moves , int idx , int currDist , pair<int,int>cod , pair<int,int> prev){

//     if(idx == moves.size()){
//         return currDist;
//     }

//     if(moves[idx] != '_'){
//         pair<int,int>  newPosition = cod;

//         while(idx<moves.size() && moves[idx]!='_'){
//             pair<int,int> move = m[moves[idx]];
//             newPosition  = {move.first + newPosition.first , move.second + newPosition.second};
//             idx++;
//         }
        
//         int newDist = abs(newPosition.first) + abs(newPosition.second);
//         return solve(moves , idx+1 , newDist, newPosition , cod);
//     }

//     int ans = INT_MIN;
//     for(auto&p : m){
//         pair<int,int> move = p.second;
//         pair<int,int> newPos = { move.first + cod.first , move.second + cod.second};
//         // if(dist(newPos) <= currDist) continue;
//         if(prev.first==newPos.first && prev.second == newPos.second)continue;
//         ans = max(ans , solve(moves , idx+1 , dist(newPos) , newPos ,cod));
//     }


//     return ans;
// }




int maxDistance(string moves) {
    int horizontal = 0;
    int vertical = 0;
    int result = 0;
    for(char & c : moves ){
        if(c == 'L'){
            horizontal -=1;
        }
        else if(c == 'R'){
            horizontal += 1;
        }
        else if(c == 'U'){
            vertical +=1;
        }
        else if(c == 'D'){
            vertical -= 1;
        }
        else{
            result ++;
        }

    }

    return result + abs(horizontal) + abs(vertical);
}

int main(){
    cout<<maxDistance("_R")<<endl;
}