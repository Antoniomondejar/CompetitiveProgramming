#include <bits/stdc++.h>
using namespace std;

string reverse(string s, int length){
    char result[length];
    for(int i = length-1; i >= 0; --i){
        result[i] = s[length-1-i];
    }
    return result;
}

int main(void){
    string s, substring, reversed_substring;
    cin >> s;
    bool palindrome_odd_length = true; 
    int string_length = s.length();
    for(int i = 0; i < string_length && palindrome_odd_length; ++i){
        for(int j = i+1; j < string_length && palindrome_odd_length; ++j){
            if ((j+1-i)%2 == 0){
                substring = s.substr(i,j+1-i);
                reversed_substring = reverse(substring,j+1-i);
                if (substring == reversed_substring)
                    palindrome_odd_length = false;
            }
        }
    }
    if (palindrome_odd_length)
        cout << "Odd." << endl;
    else
        cout << "Or not." << endl;
    return 0;
}
