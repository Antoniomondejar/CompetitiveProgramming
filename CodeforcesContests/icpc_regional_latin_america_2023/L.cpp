#include <bits/stdc++.h>
using namespace std;

int main(void){
    string T, current;
    int D, number_of_words;
    cin >> T >> D;
    current = T.substr(0,D);
    number_of_words = 1;
    for(int i = D; i < T.length(); ++i){
        if (current[i%D] == T[i])
            continue;
        else {
            ++number_of_words;
            if(i+(D-1)>=T.length()-1){
                break;
            } else {
                current = T.substr(i,D);
                i = i + D-1;
            }
        }
    }
    cout << number_of_words << endl;
    return 0;
}