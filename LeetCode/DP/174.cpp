#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int m;   // rows
    int n;  // cols
    int solve(vector<vector<int>> &dungeon, int i, int j)
    {
        if(i == m-1 && j == n-1) return dungeon[i][j]<0 ? (-1*dungeon[i][j]) + 1 : 1;
        int minHealth = INT_MAX;

        if(j+1 < n){
            int sum = 0;
            int right = solve(dungeon , i , j+1);
            if(dungeon[i][j] < 0){
                sum = right + (-1*dungeon[i][j]);
            }
            else{
                sum = right - dungeon[i][j];
            }

            if(sum<=0) sum = 1;

            minHealth = min(sum , minHealth);
        }// right

        if(i+1 < m){
            int sum = 0;
            int down = solve(dungeon , i+1 , j);
            if(dungeon[i][j] < 0){
                sum = down + (-1*dungeon[i][j]);
            }
            else{
                sum = down - dungeon[i][j];
            }

            if(sum<=0) sum = 1;

            minHealth = min(sum , minHealth);
        }

        return minHealth;
        
    }
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        m = dungeon.size();
        n = dungeon[0].size();

        return solve(dungeon , 0 , 0);
    }
};

int main()
{
}