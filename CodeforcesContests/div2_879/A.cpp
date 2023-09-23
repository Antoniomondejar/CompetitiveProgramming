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
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n; ll ba = 0; ll cant_m1 = 0;
        vector<ll> a(n); fore(i,0,n){
            cin >> a[i];
            if(a[i]==1) ++ba;
            else {
                --ba;
                cant_m1++;
            }
        }
        ll res = 0;
        if(ba<0){
            ba = -ba;
            res = (ba/2) + (ba&1);
            cant_m1 -= res;
        }
        if(cant_m1&1){
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/