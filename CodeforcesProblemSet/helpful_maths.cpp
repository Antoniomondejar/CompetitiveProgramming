#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    char numbers[s.length()];
    int position = 0;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] != '+'){
            numbers[position] = s[i];
            ++position;
        }
    }
    sort(numbers, numbers+position);
    for(int i = 0; i < position-1; ++i){
        cout << numbers[i] << "+";
    }
    cout << numbers[position-1] << "\n";
    return 0;
}