#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int N;
        string n;
        char d;
        cin >> N >> d >> n;
        int position = n.length();
        for(int i = 0; i<n.length(); ++i){
            if(d>n[i]){
                position = i;
                break;
            }
        }
        cout << n.substr(0,position) << d << n.substr(position, n.length()-position) << endl;
    }
    return 0;
}