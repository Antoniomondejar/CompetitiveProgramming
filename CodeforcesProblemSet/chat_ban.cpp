#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll k, x; cin >> k >> x;
        ll res = 0;
        if(x>=(k*(k+1)/2)){
            res = k;
            x -= k*(k+1)/2;
        } else {
            res = (sqrtl(2*x)-0.5);
            if(res*(res+1)/2 >= x)
                cout << res << "\n";
            else
                cout << (res+1) << "\n";
            continue;
        }
        // cout << "x: "<< x << "\n";
        if(x>=(k*(k-1)/2)){
            res = 2*k-1;
        } else {
            ll h = k*(k-1)/2;
            ll sqr = (sqrtl(2*(h-x))-0.5);
            if(h-((sqr+1)*(sqr+2)/2)>=x)
                res += (k-1)-(sqr+1);
            else
                res += (k-1)-sqr;
        }
        cout << res << "\n";
    }
    return 0;
}