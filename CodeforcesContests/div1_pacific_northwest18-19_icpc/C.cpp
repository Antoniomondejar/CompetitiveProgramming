#include <bits/stdc++.h>
using namespace std;

long long factorial(long long x){
    if(x==0 || x == 1)
        return 1;
    else
        return x*factorial(x-1);
}

int main(void){
    long long n, k;
    cin >> n >> k;
    long long problems[n];
    for(int i = 0; i < n; ++i){
        cin >> problems[i];
    }
    long long modulo = 998244353;
    long long all_possibilities = (factorial(n)/(factorial(k)*factorial(n-k)))%modulo;
    long long possibilities_to_substract; 
    sort(problems, problems+n);
    for(int i = 0; i<(n-1); ++i){
        if(problems[i] == problems[i+1]){
            possibilities_to_substract = (factorial(n-2)/(factorial(k-2)*factorial((n-2)-(k-2))))%modulo;
            all_possibilities = ((all_possibilities - possibilities_to_substract)+modulo)%modulo;
        }
    }
    cout << all_possibilities << endl;
}