#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string t;
        cin >> t;
        char minimal_char = t[0];
        int minimal_position = 0;
        for(int i = 0; i < n; ++i){
            if (t[i]<=minimal_char || t[i] == 'a'){
                minimal_char = t[i];
                minimal_position = i;
            }
        }
        string result = minimal_char + t.substr(0,minimal_position) + t.substr(minimal_position+1,n-minimal_position-1);
        cout << result << endl;
    }
    return 0;
}