#include <bits/stdc++.h>
using namespace std;

int main(void){
    string pi = "314159265358979323846264338327";
    int t, number_of_digits;
    cin >> t;
    string input;
    while(t--){
        cin >> input;
        number_of_digits = 0;
        for(int i = 0; i < input.length(); ++i){
            if (input[i] == pi[i])
                ++number_of_digits;
            else
                break;
        }
        cout << number_of_digits << endl;
    }
    return 0;
}