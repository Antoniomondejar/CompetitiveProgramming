#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, s, input;
    cin >> n >> s;
    int max_time = 0;
    for(int i = 0; i < n; ++i){
        cin >> input;
        max_time = max(max_time, input);
    }
    max_time = max_time * s;
    cout << (max_time+1000-1)/1000 << endl; // Gives the ceil of the division max_time/1000.
    return 0;
}