#include <bits/stdc++.h>
using namespace std;

int main(void){
    string word, crib;
    cin >> word >> crib;
    int word_length = word.length();
    int crib_length = crib.length();
    int ones_qty = 0;
    int test_configurations[word_length-crib_length+1];
    for(int i = 0; i < word_length-crib_length+1; ++i){
        test_configurations[i] = 0;
    }
    for(int i = 0; i < word_length-crib_length+1; ++i){
        for(int j = 0; j < crib_length; ++j){
            if(word[i+j] == crib[j]){
                test_configurations[i] = 1;
                ++ones_qty;
                break;
            }
        }
    }
    cout << word_length-crib_length-ones_qty+1 << endl;
    return 0;
}