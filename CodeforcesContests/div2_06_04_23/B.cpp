#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    if(a==0)
        return b;
    return gcd(b%a, a);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long a,b, min_divisor = -1;
        long long length = 1; long long steps = 0;
        cin >> a >> b;
        long long min_number = min(a,b);
        long long max_number = max(a,b);
        long long raiz = sqrt(min_number)+1;
        for(int i = 2; i < raiz; ++i){
            if(min_number%i==0){
                min_divisor = i;
                break;
            }
        }
        if(min_divisor!=-1){
            steps = a/min_divisor + min_divisor;
            length = min_divisor;
        } else {
            steps = a;
        }
        min_divisor = -1;
        raiz = sqrt(max_number) + 1;
        for(int i = (length==1?2:length); i < raiz; ++i){
            if(max_number%i==0){
                min_divisor = i;
                break;
            }
        }
        if(min_divisor != -1){
            steps += min(max_number/min_divisor+(min_divisor-length),max_number-length+1); 
        } else {
            steps += max_number-length+1;
        }
        long long mcd = gcd(a,b);
        cout << min(steps, mcd-1+a/mcd+b/mcd) << "\n";
    }
    return 0;
}