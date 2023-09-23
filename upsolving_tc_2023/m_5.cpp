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
const ll NMAX = 1e5+10;
const ll MOD = 1e9+7;

vector<ll> g[NMAX];
ll dp[NMAX][2],c[NMAX];

ll add(ll x, ll y){
    return (((x+y)%MOD)+MOD)%MOD;
}

ll mul(ll x, ll y){
    return (x*y)%MOD;
}

ll f(ll x, ll tengo){
    if(SZ(g[x])==0 && !c[x] && tengo)return 0;
    if(c[x] && !tengo) return 0;
    if(SZ(g[x])==0)return 1;
    ll &res = dp[x][tengo];
    if(res!=-1)return res;
    res = 0;
    if(!c[x] && !tengo){
        res = 1;
        fore(i,0,SZ(g[x])){
            res = mul(res,add(f(g[x][i],1),(f(g[x][i],0))));
        }
        ll aux = 1;
        fore(i,0,SZ(g[x])){
            aux = mul(aux,f(g[x][i],0));
        }
        res = add(res,-aux);
    } else {
        res = 1;
        fore(i,0,SZ(g[x])){
            res = mul(res,add(f(g[x][i],1),f(g[x][i],0)));
        }
    }
    cout << x << " " << tengo << " " << res << "\n";
    return res;
}


int main(){FIN;
    mset(dp,-1);
    ll n;cin>>n;
    fore(i,0,n-1){
        ll x;cin>>x;
        g[x].pb(i+1);
    }
    fore(i,0,n)cin>>c[i];
    ll res = f(0,1);
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/