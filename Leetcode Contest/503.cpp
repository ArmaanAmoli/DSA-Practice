#include<bits/stdc++.h>
using namespace std;

vector<int> limitOccurrences(vector<int>& nums, int k) {
    unordered_map<int , int>m;
    vector<int> v;
    for(int i = 0 ; i<nums.size() ; i++){
        int freq = m[nums[i]];
        if(freq<k){
            m[nums[i]]++;
            v.push_back(nums[i]);
        }
    }
    return v;
}

int passwordStrength(string password) {
    unordered_map<int , int> m;
    int strength = 0;
    for(char &c : password){
        int k = c;
        if(m[k] == 0){
            m[k]++;
            if(k>=97 && k<=122){
                strength++;
            }
            else if(k>=65 && k<=90){
                strength += 2;
            }
            else if(k>=48 && k <= 57){
                strength += 3;
            }
            else{
                strength += 5;
            }
        }
    }
    return strength;
}

string sorted_s = "";

string right_rotate( string s){
    char l = s[s.size() - 1 ];
    s.insert(0, 1 , l);
    s.pop_back();
}

string reverse_str ( string s){
    reverse(s.begin() , s.end());
    return s;
}

int solve(string sorted_s , string s , int count){
    if(s == sorted_s){
        count;
    }

    int right
}

int minOperations(vector<int>& nums) {
    string s = "";
    for(auto &i : nums){
        char c = 48 + i;
        s.push_back(c);
    }
    sorted_s = s;
    sort(sorted_s.begin() , sorted_s.end());
    return solve(sorted_s , s ,0);
}


int main(){
    // vector<int> v = {1,2,3};
    // vector<int> v_new = limitOccurrences(v , 1);
    // for(auto & n : v_new){
    //     cout<<n<<endl;
    // }

    string s = "bbB11#";
    cout<<passwordStrength(s)<<endl;
}