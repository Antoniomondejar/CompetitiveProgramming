#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long n;
    cin >> n;
    long long comparisons = (n*n - (n*(n+1)/2))/2;
    long long last_printed_number = 1;
    while(comparisons > 0){
        comparisons = comparisons - (n-last_printed_number);
        ++last_printed_number;
    }
    cout << (last_printed_number-1) << endl;
}