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
    ll n;cin>>n;
    vector<vector<ll>> flav(n);
    fore(i,0,n){
        ll ind,s; cin>>ind>>s;--ind;
        flav[ind].pb(s);
    }
    fore(i,0,n){
        sort(ALL(flav[i]));
    }
    ll res = 0;
    vector<ll> ma;
    fore(i,0,n){
        if(SZ(flav[i])>=1)ma.pb(flav[i].back());
        if(SZ(flav[i])<2)continue;
        res = max(res, flav[i][SZ(flav[i])-1]+flav[i][SZ(flav[i])-2]/2);
    }
    sort(ALL(ma));
    if(SZ(ma)>1){
        res = max(res, ma[SZ(ma)-1]+ma[SZ(ma)-2]);
    }
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/