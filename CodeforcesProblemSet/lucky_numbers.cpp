#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        string aux;
        int max_suma_lucky = 0;
        char min_digit_char, max_digit_char;
        string luckiest_number;
        for(int i = 0; i < r-l+1; ++i){
            aux = to_string(l+i);
            max_digit_char = '0';
            min_digit_char = '9';
            for(int j = 0; j < aux.length(); ++j){
                min_digit_char = min(min_digit_char, aux[j]);
                max_digit_char = max(max_digit_char, aux[j]);
                if(min_digit_char == '0' && max_digit_char == '9')
                    break;
            }
            if(max_suma_lucky<=(max_digit_char-min_digit_char)){
                max_suma_lucky = max_digit_char-min_digit_char;
                luckiest_number = aux;
                if(max_suma_lucky == 9)
                    break;
            }
        }
        cout << luckiest_number << "\n";
    }
    return 0;
}