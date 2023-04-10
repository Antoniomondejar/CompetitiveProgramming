#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n, k; long long ops = 0;
        cin >> n >> k;
        int grid[n][n];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> grid[i][j];
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != grid[n-1-i][n-1-j]){
                    ++ops;
                }
            }
        }
        ops /= 2;
        k-=ops;
        if(k<0 || (n%2==0 && k%2!=0))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}