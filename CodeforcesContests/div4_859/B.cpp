#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n, input;
        int mihai_candies = 0; int bianca_candies = 0;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> input;
            if(input % 2 == 0)
                mihai_candies = mihai_candies + input;
            else
                bianca_candies = bianca_candies + input;
        }
        if (mihai_candies>bianca_candies)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
