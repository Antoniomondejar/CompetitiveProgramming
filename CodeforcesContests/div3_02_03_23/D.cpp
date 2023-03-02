#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string word;
        cin >> word;
        set<string> words;
        for(int i = 0; i < n-1; ++i)
            words.insert(word.substr(0,i) + word.substr(i+2,n-(i+2)));
        cout << words.size() << endl;
    }
    return 0;
}