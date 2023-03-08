#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        long long a1, a2, a3, a4, jokes_told;
        cin >> a1 >> a2 >> a3 >> a4;
        if (a1 == 0 && (a2>0 || a3 > 0 || a4 > 0)){
            cout << 1 << endl;
            continue;
        }
        long long alices_mood = a1;
        long long jokes_to_tell = 0;
        long long bobs_mood = a1;
        jokes_told = a1 + 2*min(a2,a3);
        if (a2<a3) {
            a2 = 0;
            a3 = a3-a2;
            jokes_to_tell = min(alices_mood + 1, a3);
            jokes_told = jokes_told + jokes_to_tell;
            bobs_mood = bobs_mood + jokes_to_tell;
            alices_mood = alices_mood - jokes_to_tell;
        } else if (a3 < a2) {
            a3 = 0;
            a2 = a2-a3;
            jokes_to_tell = min(bobs_mood + 1, a2);
            jokes_told = jokes_told + jokes_to_tell;
            bobs_mood = bobs_mood - jokes_to_tell;
            alices_mood = alices_mood + jokes_to_tell;
        } else {
            a2 = 0;
            a3 = 0;
        }
        if (alices_mood >= 0 && bobs_mood >= 0 && a2 == 0 && a3 == 0){
            jokes_told = jokes_told + min({alices_mood+1, bobs_mood+1, a4});
        }
        cout << jokes_told << endl;
    }
}