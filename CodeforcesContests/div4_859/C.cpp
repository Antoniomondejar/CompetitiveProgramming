#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        char c;
        bool is_possible = true;
        cin >> n >> s;
        int current_number = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] != '0' && s[i]!= '1'){
                c = s[i];
                s[i] = (current_number)?'1':'0';
                for(int j = i+1; j < n; ++j){
                    if (s[j] == c)
                        s[j] = s[i];
                }
                current_number = (current_number+1)%2;
            } else {
                current_number = (s[i] == '1')?0:1;
            }
        }
        int numbers_of_1 = 0; int numbers_of_0 = 0;
        for(int i = 0; i < n && is_possible; ++i){
            if(s[i] == '1'){
                ++numbers_of_1;
                numbers_of_0 = 0;
            } else {
                ++numbers_of_0;
                numbers_of_1 = 0;
            }
            if (numbers_of_0 > 1 || numbers_of_1 > 1)
                is_possible = false;
        }
        if(is_possible){
            cout << "YES" << endl;
            continue;
        }
        is_possible = true;
        current_number = 1;
        for(int i = 0; i < n; ++i){
            if(s[i] != '0' && s[i]!= '1'){
                c = s[i];
                s[i] = (current_number)?'1':'0';
                for(int j = i+1; j < n; ++j){
                    if (s[j] == c)
                        s[j] = s[i];
                }
                current_number = (current_number+1)%2;
            } else {
                current_number = (s[i] == '1')?0:1;
            }
        }
        numbers_of_1 = 0; numbers_of_0 = 0;
        for(int i = 0; i < n && is_possible; ++i){
            if(s[i] == '1'){
                ++numbers_of_1;
                numbers_of_0 = 0;
            } else {
                ++numbers_of_0;
                numbers_of_1 = 0;
            }
            if (numbers_of_0 > 1 || numbers_of_1 > 1)
                is_possible = false;
        }
        if(is_possible){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}