#include<bits/stdc++.h>
using namespace std;

vector<int> concatWithReverse(vector<int>& nums) {
        int size = nums.size();
        vector<int> nums2(2*size , 0);

        for(int i = 0 ; i<=size-1 ; i++){
            nums2[i] = nums[i];
        }
        int j = size;
        for(int i = size-1 ; i>=0 ; i--){
            nums2[j] = nums[i];
            j++;
        }
        return nums2;
}

// 97 - 122
bool isValidHyphen(int idx , string& combined){
    int n = combined.size();
    if(idx==0 || idx == n-1 || idx<0 || idx>=n) return false;
    int left = int(combined[idx-1]);
    int right = int(combined[idx+1]);

    if(left >= 97 && right>= 97 && left <= 122 && right <=122){
        return true;
    }
    return false;
}

vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
    string combined;
    int totalLen = 0;
    for(auto& s : chunks) totalLen += s.length();
    combined.reserve(totalLen);
    
    for(auto & str : chunks){
        combined += str;
    }
    string selvadrik = combined;
    unordered_map<string , int> m;

    string currentWord = "";
    for(int i = 0 ; i < combined.size() ; i++){
        int key = int (combined[i]);
        char c = combined[i];
        if((key >= 97 && key <= 122)){
            currentWord.push_back(c);
        }
        else{
            if(c == '-' && isValidHyphen(i , combined) ){
                currentWord.push_back(c);
                continue; 
            }
            if(currentWord!= ""){
                m[currentWord] +=1;
            }
            currentWord = "";
        }
    }
    
    if(currentWord != ""){
        m[currentWord] += 1;
    }

    vector<int> ans;
    for(auto & word : queries){
        ans.push_back(m[word]);
    }

    return ans;
}

int main(){
    // Test Example 1
    cout << "Example 1: ";
    vector<string> chunks1 = {"hello wor","ld hello"};
    vector<string> queries1 = {"hello","world","wor"};
    vector<int> ans1 = countWordOccurrences(chunks1, queries1);
    for(auto i : ans1) cout << i << " ";
    cout << endl;

    // Test Example 2
    cout << "Example 2: ";
    vector<string> chunks2 = {"a--b a-","-c"};
    vector<string> queries2 = {"a","b","c"};
    vector<int> ans2 = countWordOccurrences(chunks2, queries2);
    for(auto i : ans2) cout << i << " ";
    cout << endl;

    // Test Example 3
    cout << "Example 3: ";
    vector<string> chunks3 = {"hello"};
    vector<string> queries3 = {"hello","ell"};
    vector<int> ans3 = countWordOccurrences(chunks3, queries3);
    for(auto i : ans3) cout << i << " ";
    cout << endl;

    return 0;
}