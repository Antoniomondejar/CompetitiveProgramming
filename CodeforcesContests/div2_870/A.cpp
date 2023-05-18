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
    while (t--){
        ll n, c_l, c_t; cin >> n;
        vector<ll> l(n);
        fore(i,0,n) cin >> l[i];
        bool p = false;
        fore(i,0,n+1){
            c_l = 0, c_t = 0;
            fore(j,0,n){
                if(l[j]>i){
                    ++c_l;
                } else {
                    ++c_t;
                }
            }
            p = c_l == i;
            if(p) break;
        }
        if(p) cout << c_l << "\n";
        else cout << "-1\n";
    }
    return 0;
}