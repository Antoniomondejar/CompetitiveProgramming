#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int b[n];
        bool is_possible = true;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i){
            cin >> b[i];
        }
        for(int i = 0; i < n-1; ++i){
            if(a[i]>b[n-1] && a[i]>a[n-1]){
                is_possible = false;
                break;
            }
            if(b[i]>b[n-1] && b[i]>a[n-1]){
                is_possible = false;
                break;
            }
            if((b[i]>a[n-1] && a[i]>a[n-1]) || (b[i]>b[n-1] && a[i]>b[n-1])){
                is_possible = false;
                break;
            }
        }
        if(is_possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}