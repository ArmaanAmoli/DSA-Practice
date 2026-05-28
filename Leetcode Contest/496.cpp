#include<bits/stdc++.h>
#include<set>
using namespace std;

char getmirrorChar(char c){
    int assci = int(c);
    if(assci<=57){
        int idx = assci-48;
        int mirr_idx = 9-idx;
        int mirr_char_assci = 48+mirr_idx;
        return char(mirr_char_assci);
    }else{
        int idx = assci-97;
        int mirr_idx = 25-idx;
        int mirr_char_assci = 97+mirr_idx;
        return char(mirr_char_assci);
    }
}
int mirrorFrequency(string s)
{
    unordered_map<char , int> m;
    set<char>st;
    for(int i=0 ; i<s.size() ; i++){
        m[s[i]]+=1;
    }
    int ans = 0;

    for(char &c : s){
        if(st.count(c))continue;
        char mir = getmirrorChar(c);
        int freq_mirr = m.count(mir) ? m[mir] : 0;
        int diff = abs(m[c]-freq_mirr);
        ans+=diff;
        st.insert(c);
        st.insert(mir);
        
    }
    return ans;
}



int main(){
    string s = "55te323dnwfke";
    cout<<mirrorFrequency(s);
}