#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; 
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        if (n%2LL==0 || n%k==0)
            cout << "YES\n";
        else {
            if(k%2==1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}