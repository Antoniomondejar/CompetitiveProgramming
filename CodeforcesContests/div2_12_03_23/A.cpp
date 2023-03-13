#include <bits/stdc++.h>
using namespace std;

int abs(int x){
    if (x>=0)
        return x;
    return -x;
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        a = abs(a);
        b = abs(b);
        int min_consecutive_steps = min(a, b);
        int minimum_seconds = 2*min_consecutive_steps;
        a = a-min_consecutive_steps;
        b = b-min_consecutive_steps;
        if (a>0){
            ++minimum_seconds;
            --a;
            minimum_seconds = minimum_seconds + 2*a; 
        } else if (b>0) {
            ++minimum_seconds;
            --b;
            minimum_seconds = minimum_seconds + 2*b;
        }
        cout << minimum_seconds << endl;
    }
}