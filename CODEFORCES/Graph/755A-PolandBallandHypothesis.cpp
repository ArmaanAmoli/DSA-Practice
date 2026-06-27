#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

bool checkPrime(int k){
    int j = pow(k , .5);
    for(int i = 2 ; i<=j ; i++){
        if(k%i == 0) return false;
    }
    return true;

}

int solve(int i){
    for(int m = 1 ; m<=1000 ; m++){
        int n = m*i + 1;
        bool isPrime = checkPrime(n);
        if(!isPrime) return m;
    }
    return 0;
}

int main(){

    int i;
    cin>>i;
    cout<<solve(i)<<endl;

}