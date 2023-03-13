#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    string input;
    cin >> N;
    string words_array[N];
    bool exists_acronym = false;
    for(int i = 0; i < N; ++i){
        cin >> words_array[i];
    }
    for(int i = 0; i < N && !exists_acronym; ++i){
        for(int h = 0; h < words_array[i].length(); ++h){
            int j = 0;
            while(j < N && words_array[j][0]!=words_array[i][h])
                ++j;
            if (j==N){
                exists_acronym = false;
                break;
            } else {
                exists_acronym = true;
            }
        }        
    }
    if(exists_acronym)
        cout << "Y" << endl;
    else
        cout << "N" << endl;
    return 0;
}