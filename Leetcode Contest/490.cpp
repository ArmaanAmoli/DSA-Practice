#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int scoreDifference(vector<int> &nums)
{
    vector<int> scores = {0, 0};
    int curr_player = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 != 0 || (i + 1) % 6 == 0)
        {

            if (nums[i] % 2 != 0 && (i + 1) % 6 == 0)
            {
                curr_player = curr_player;
            }
            else
            {
                curr_player = !curr_player;
            }
        }
        
        scores[curr_player] += nums[i];
    }
    return scores[0] - scores[1];
}


long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

long long digitorial(int n){
    if(n>=0 && n<=9) return n;
    long long ans = 0;
    while(n != 0){
        ans += factorial(n%10);
        n = n/10;
    }
    return ans;
}
bool isDigitorialPermutation(int n) {
    if(n>=0 && n<=9) return true;
    long long digi = digitorial(n);
    string s1 = to_string(n);
    string s2 = to_string(digi);
    sort(s1.begin() , s1.end());
    sort(s2.begin() , s2.end());
    return s1 == s2;
}





int main()
{
    cout << isDigitorialPermutation(10) << endl;
}