#include <bits/stdc++.h>
using namespace std;
#include <math.h>
int main(void){
    int t;
    cin >> t;
    while(t--){
        int n, x, p, k;
        cin >> n >> x >> p;
        int p_sqrt = sqrt(p);
        p_sqrt = p_sqrt*2 + 1;
        bool printed = false;
        for(int i = 1; i < p_sqrt; ++i){
            int integer_sqrt = sqrt(1+8*(i*n-x));
            if ((integer_sqrt * integer_sqrt) != (1+8*(i*n-x))){
                if ((-1+integer_sqrt)/2 <= p)
                    continue;
                cout << "No" << endl;
                printed = true;
                break;
            } else if ((-1+integer_sqrt)/2 <= p){
                cout << "Yes" << endl;
                printed = true;
                break;
            } else {
                cout << "No" << endl;
                printed = true;
                break;
            }
        }
        if (!printed)
            cout << "No" << endl;
    }
    return 0;
}