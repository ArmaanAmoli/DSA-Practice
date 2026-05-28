#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 1000
// 1,000,000
// 1,000,000
//999,999 to 1000
// int countCommas(int n) {
//     if(n<1000)return 0;
//     else return (n-1000)+1;
// }
// (1000)^5
int commas(long long n)
{
    int count = 0;
    while (n >= 1000)
    {
        n = n / 1000;
        count++;
    }return count;
}
long long countCommas(long long n)
{
    if(n<1000)return 0;
    int c = commas(n);
    cout<<c<<endl;
    int ranger = pow(1000,c);
    int x = ((n-ranger)+1)*c;
    while(ranger>=1000){
        int old = ranger;
        ranger = ranger/1000;
        c = c - 1;
        x += c*(((old-1) - ranger)+1);
    }
    return x;
}

int main()
{
    cout<<countCommas(998);
}