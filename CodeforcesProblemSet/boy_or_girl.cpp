#include <bits/stdc++.h>
using namespace std;

int main(void){
    string N;
    cin >> N;
    set<char> letters;
    for(int i = 0; i < N.length(); ++i)
        letters.insert(N[i]);
    if(letters.size()%2==0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;
    return 0;
}