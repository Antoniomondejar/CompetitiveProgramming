#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n, input;
        cin >> n;
        bool is_possible = false;
        for(int i = 0; i < n; ++i){
            cin >> input;
            is_possible = is_possible || (i+1)>=input;
        }
        if(is_possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}