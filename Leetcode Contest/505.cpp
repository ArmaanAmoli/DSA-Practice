#include <bits/stdc++.h>
using namespace std;

// vector<string> result;
// int N;
// int K;
// void solve(int idx , int costRemaining , string str , bool lastWasOne){
//     if(idx == N){
//         result.push_back(str);
//         return;
//     }
//     // push zero
//     str.push_back('0');
//     solve(idx+1 , costRemaining , str , false);
//     str.pop_back();
//     //push one
//     if(costRemaining>=0 && costRemaining-idx >=0 && lastWasOne == false){
//         str.push_back('1');
//         solve(idx+1 , costRemaining-idx , str , true);
//         str.pop_back();
//     }
// }

// vector<string> generateValidStrings(int n, int k) {
//     result ={};
//     N=n;
//     K=k;
//     solve(0 , k , "" , false);
//     return result;
// }

// int sumOfGoodIntegers(int n, int k) {
//     int x = 1;
//     int sum = 0;
//     while(true){
//         int X = n+x;
//         int result = n & X;
//         if((abs(n-X)) > k){
//             break;
//         }
//         if( !result && ((abs(n-X)) <= k) ){
//             sum += X;
//         }
//         x++;
//     }
//     x = 1;
//     while(true){
//         int X = n-x;
//         if(X <= 0) break;
//         int result = n & X;
//         if((abs(n-X)) > k){
//             break;
//         }
//         if( !result && ((abs(n-X)) <= k) ){
//             sum += X;
//         }
//         x++;
//     }
//     return sum;

// }

vector<int> Nums;
int M;
int L, R;
int n;

long long solve(int idx, int currentSubArrayLength, long long currentSum, int currentNoOfSubarrays)
{
    if (idx == n)
    {
        return currentSum;
    }

    long long best = LLONG_MIN;

    long long startFromNext = INT_MIN;
    if(currentSubArrayLength == 0){ //
        startFromNext = (idx+1 , 0 , currentSum , currentNoOfSubarrays );
    }

    // break
    long long createNewSubarray = INT_MIN;
    if (currentSubArrayLength >= L && currentSubArrayLength <= R && currentNoOfSubarrays < M)
    {
        createNewSubarray = solve(idx, 0, currentSum, currentNoOfSubarrays+1);
    }
    // no break add and go
    long long continueSame = INT_MIN;
    if (currentSubArrayLength < R)
    {
        continueSame = solve(idx + 1, currentSubArrayLength + 1, currentSum + Nums[idx], currentNoOfSubarrays);
    }

    return max({continueSame, createNewSubarray , startFromNext});
}

// long long solve(int idx, int currentSubArrayLength, long long currentSum, int currentNoOfSubarrays)
// {
//     if (idx == n)
//         return currentSum;

//     long long best = INT_MIN;

//     // Option 1: skip this element (only valid when not mid-subarray)
//     if (currentSubArrayLength == 0)
//     {
//         best = max(best, solve(idx + 1, 0, currentSum, currentNoOfSubarrays));
//     }

//     // Option 2: end current subarray here, then decide what to do with idx
//     // (only valid if current subarray length is in [L, R] and we haven't hit M)
//     if (currentSubArrayLength >= L && currentSubArrayLength <= R && currentNoOfSubarrays < M)
//     {
//         // end here — idx is NOT consumed, recurse with length=0, count already incremented
//         best = max(best, solve(idx, 0, currentSum, currentNoOfSubarrays + 1));
//     }

//     // Option 3: extend current subarray to include Nums[idx]
//     if (currentSubArrayLength < R && currentNoOfSubarrays < M)
//     {
//         best = max(best, solve(idx + 1, currentSubArrayLength + 1,
//                                currentSum + Nums[idx], currentNoOfSubarrays));
//     }

//     return best;
// }

long long maximumSum(vector<int> &nums, int m, int l, int r)
{
    M = m;
    L = l;
    R = r;
    n = nums.size();
    Nums = nums;
    return solve(0, 0, 0, 0);
}

int main()
{
    // vector<string> v = generateValidStrings(1 , 0);
    // for(auto&s:v){
    //     cout<<s<<endl;
    // }
    vector<int> v = {4, 1, -5, 2};
    cout << maximumSum(v, 2, 1, 3);
}