#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll mul(ll x, ll y){
    return (x*y)%MOD;
}

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n),b(n);
        fore(i,0,n) cin >> a[i];
        fore(i,0,n) cin >> b[i];
        sort(ALL(a));sort(ALL(b));
        ll ma_c = 0;
        ll res = 1;
        bool p = true;
        fore(i,0,n){
            ll ma_aux = 0;
            fore(j,ma_c,n){
                if(a[i]<=b[j]) break;
                else ++ma_aux;
            }
            if(ma_aux == 0 && ma_c <= i){
                p = false; break;
            }
            ma_c += ma_aux;
            res = mul(res,ma_c-i);
        }
        if(p) cout << res << "\n";
        else cout << "0\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/