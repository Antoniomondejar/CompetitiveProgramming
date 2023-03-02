#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string sound;
        cin >> sound;
        bool cat = true;
        pair<char, char> letters[4];
        letters[0] = make_pair('m', 'M');
        letters[1] = make_pair('e', 'E');
        letters[2] = make_pair('o', 'O');
        letters[3] = make_pair('w', 'W');
        int letter_count[4]= {0,0,0,0};
        int current_letter = 0;
        for(int i = 0; i < n && current_letter < 4 && cat; ++i){
            cat = (sound[i] == letters[current_letter].first) || (sound[i] == letters[current_letter].second);            
            if (!cat){
                if (current_letter < 3 &&
                   (sound[i] == letters[current_letter+1].first || sound[i] == letters[current_letter+1].second) &&
                   letter_count[current_letter] > 0){
                        cat = true;
                        ++current_letter;
                        ++letter_count[current_letter];
                   }
            } else {
                ++letter_count[current_letter];
            }
        }
        for(int i = 0; i < 4; ++i){
            cat = cat && letter_count[i] > 0;
        }
        if (cat)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}