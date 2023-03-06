#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int powers_of_ten[6] = {1,10,100,1000,10000,100000};
    ++n;
    int remainding_digits = n;
    for(int i = 0; i < 6; ++i){
        if (remainding_digits < 10)
            break;
        if (remainding_digits % 10 == 0){
            n = n + powers_of_ten[i];
        }
        remainding_digits = remainding_digits/10;
    }
    cout << n << endl;
    return 0;
}