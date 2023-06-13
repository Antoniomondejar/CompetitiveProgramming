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
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

int main(){FIN;
    ll n; cin >> n;
    vector<ll> ns(n);
    ll maxx = 0;
    vector<ll>ot_div;
    fore(i,0,n)cin>>ns[i], maxx = max(maxx,ns[i]);
    ll max_2 = 0;
    set<ll> max_div;
    sort(ALL(ns));
    fore(i,0,n){
        if(maxx%ns[i] || max_div.count(ns[i])){
            ot_div.pb(ns[i]);
        } else {
            max_div.insert(ns[i]);
        }
    }
    sort(ALL(ot_div));
    cout << maxx << " " << ot_div[SZ(ot_div)-1] << '\n';
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/