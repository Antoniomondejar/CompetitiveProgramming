#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t, left, right;
    cin >> t;
    string s, a, b, c;
    bool condition = false;
    while (t--) {
        cin >> s;
        for (int left = 1; left <= s.length() - 2; ++left) {
            for (int right = s.length() - 2; right >= left; --right) {
                a = s.substr(0, left);
                b = s.substr(left, right);
                c = s.substr(right+1, s.length());
                if ((a<=b && c<=b)||(a>=b && c>=b)) {
                    condition = true;
                    break;
                }
            }
            if (condition)
                break;
        }
        if (condition)
            cout << a << " " << b << " " << c << endl;
        else
            cout << ":(" << endl;
        condition = false;
    }
}