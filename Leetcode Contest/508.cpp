#include<bits/stdc++.h>
using namespace std;

long long maxSum(vector<int>& nums, int k, int mul) {
    int n = nums.size();
    sort(nums.begin() , nums.end());
    int i = n-1;
    int e = 0;
    long long sum = 0;
    while(i>=0 && e<k){
        if(mul>0){
            sum+= 1LL *nums[i]*mul;
        }
        else{
            sum+=1LL *nums[i];
        }
        mul--;
        e++;
        i--;
    }
    return sum;
}

vector<int> mergeIntervals(vector<int> i1 , vector<int>i2){
    int x1,y1,x2,y2;
    x1 = i1[0];
    x2 = i2[0];
    y1 = i1[1];
    y2 = i2[1];
    if((x2 - y1 >1))return {};
    return {min(x1,x2) , max(y1 , y2)};
}

vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        stack<vector<int>>s;
        for(auto&p: occupiedIntervals){
            if(s.empty())s.push({p[0] , p[1]});
            else{
                vector<int> newT = {};
                if(!s.empty() && p[0] - s.top()[1] <=1){
                    newT = mergeIntervals(s.top() , p);
                    s.pop();
                }
                s.push(newT);
            }
        }
        vector<vector<int>> mergedIntervals = {};
        while(!s.empty()){
            mergedIntervals.push_back(s.top());
            s.pop();
        }

        reverse(mergedIntervals.begin() , mergedIntervals.end() );
        
        for(int i = 0 ; i<mergedIntervals.size() ; i++){
            // if we found free start the we start loop for the current i till we find free end
                // case 1 start and end are in same interval
                // case 2 they are in different interval
        }
        

    }

int main(){
    vector<int>nums = {4,4};
    cout<<maxSum(nums , 1,1);
}