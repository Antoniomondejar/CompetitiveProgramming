#include "bits/stdc++.h"
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
// const ll NMAX = 2e5+10;
// const ll MOD = 1e9+7;


int main(){FIN;
    ll n,b; cin >> n >> b;
    map<ll,ll> pr;
    for(ll i = 2; i*i<=b; ++i){
        while(b%i==0){
            pr[i]++;
            b/=i;
        }
    }
    if(b>1){
        pr[b]++;
    }
    ll res = LLONG_MAX;
    for(auto i:pr){
        ll pri = i.fst; ll exp = i.snd;
        __int128_t aux = pri;
        ll count = 0;
        while(aux<=n){
            count += n/aux;
            aux *= pri;
        }
        res=min(res,count/exp);
    }
    cout << res << '\n';
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/