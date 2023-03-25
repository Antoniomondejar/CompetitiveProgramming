#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        set<char> letters;
        int number_of_days = 0;
        for(int i = 0; i < s.length(); ++i){
            letters.insert(s[i]);
            if(letters.size()>3){
                ++number_of_days;
                set<char> new_letters;
                letters = new_letters;
                letters.insert(s[i]);
            }
        }
        ++number_of_days;
        cout << number_of_days << endl;
    }
    return 0;
}