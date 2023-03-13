#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n, s, r;
        cin >> n >> s >> r;
        int maximum_value = s-r;
        int dices_remaining = n-1;
        cout << maximum_value << " ";
        // cout << r << endl;
        while(dices_remaining<r){
            if (r>=dices_remaining-1+maximum_value){
                r = r - maximum_value;
                --dices_remaining;
                cout << maximum_value << " ";
            } else if (r>=dices_remaining-1+maximum_value-1){
                r = r - maximum_value+1;
                --dices_remaining;
                cout << maximum_value-1 << " ";
            } else if (r>=dices_remaining-1+maximum_value-2){
                r = r - maximum_value+2;
                --dices_remaining;
                cout << maximum_value-2 << " ";
            } else if (r>=dices_remaining-1+maximum_value-3){
                r = r - maximum_value+3;
                --dices_remaining;
                cout << maximum_value-3 << " ";
            } else if (r>=dices_remaining-1+maximum_value-4){
                r = r - maximum_value+4;
                --dices_remaining;
                cout << maximum_value-4 << " ";
            } else if (r>=dices_remaining-1+maximum_value-5){
                r = r - maximum_value+5;
                --dices_remaining;
                cout << maximum_value-5 << " ";
            }
        }
        while(r>0){
            cout << 1 << " ";
            --r;
        }
        cout << endl;
    }
}