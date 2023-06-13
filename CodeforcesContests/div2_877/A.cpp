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
        ll n; cin >> n;
        vector<ll> a;
        set<ll> ns;
        fore(i,0,n){
            ll inp; cin >> inp;
            if(ns.count(inp))continue;
            a.pb(inp); ns.insert(inp);
        }
        sort(ALL(a));
        if(a[0]<0)cout << a[0] << "\n";
        else cout << a[SZ(a)-1] << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/