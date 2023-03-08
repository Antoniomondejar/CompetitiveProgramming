#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, input; int wins = 0;
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> input;
        if (input != 1)
            ++wins;
    }
    cout << wins << endl;
    return 0;
}