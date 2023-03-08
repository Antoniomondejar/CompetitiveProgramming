#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    string encrypted_word;
    cin >> encrypted_word;
    string decrypted_word = "";
    decrypted_word = encrypted_word[0];
    int offset = 0; int i = 1;
    while(offset+i < n){
        decrypted_word = decrypted_word + encrypted_word[i+offset];
        offset = offset + i;
        ++i;
    }
    cout << decrypted_word << endl;
    return 0;
}