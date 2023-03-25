#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    map<char,int> alphabet;
    alphabet['a'] = 1;
    alphabet['b'] = 2;
    alphabet['c'] = 3;
    alphabet['d'] = 4;
    alphabet['e'] = 5;
    alphabet['f'] = 6;
    alphabet['g'] = 7;
    alphabet['h'] = 8;
    alphabet['i'] = 9;
    alphabet['j'] = 10;
    alphabet['k'] = 11;
    alphabet['l'] = 12;
    alphabet['m'] = 13;
    alphabet['n'] = 14;
    alphabet['o'] = 15;
    alphabet['p'] = 16;
    alphabet['q'] = 17;
    alphabet['r'] = 18;
    alphabet['s'] = 19;
    alphabet['t'] = 20;
    alphabet['u'] = 21;
    alphabet['v'] = 22;
    alphabet['w'] = 23;
    alphabet['x'] = 24;
    alphabet['y'] = 25;
    alphabet['z'] = 26;
    while(t--){
        string w;
        int p;
        cin >> w >> p;
        int w_length = w.length();
        int string_price = 0;
        char w_letters[w_length];
        for(int i = 0; i < w_length; ++i){
            w_letters[i] = w[i];
            string_price = string_price + alphabet[w[i]];
        }
        sort(w_letters, w_letters+w_length);
        int current_letter = w_length-1;
        map<char,int> letters_to_remove;
        while(string_price>p){
            string_price = string_price - alphabet[w_letters[current_letter]];
            if (letters_to_remove.find(w_letters[current_letter]) != letters_to_remove.end())
                ++letters_to_remove[w_letters[current_letter]];
            else
                letters_to_remove.insert(make_pair(w_letters[current_letter], 1));
            --current_letter;
        }
        string result = ""; current_letter = 0;
        while(current_letter < w_length){
            if (!letters_to_remove.size() || letters_to_remove.find(w[current_letter]) == letters_to_remove.end())
                result = result+w[current_letter];
            else if(letters_to_remove[w[current_letter]] == 1)
                letters_to_remove.erase(w[current_letter]);
            else
                --letters_to_remove[w[current_letter]];
            ++current_letter;
        }
        cout << result << endl;
    }
    return 0;
}