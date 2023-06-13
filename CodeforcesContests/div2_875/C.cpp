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

vector<pair<ll,ll>> g[NMAX];
ll vis[NMAX]; 
ll drw[NMAX];
pair<ll,ll> pa[NMAX];
void dfs(ll x){
    vis[x] = 1;
    for(auto i:g[x]){
        if(vis[i.fst])continue;
        vis[i.fst] = 1;
        if(i.snd<pa[x].snd)drw[i.fst]=drw[x]+1;
        else drw[i.fst]=drw[x];
        pa[i.fst] = {x,i.snd};
        dfs(i.fst);
    }
} 

int main(){FIN;
    ll t;cin>>t;
    while(t--){
        ll n; cin >> n;
        fore(i,0,n)vis[i]=0, drw[i]=0, pa[i]={0,0};
        fore(i,0,n-1){
            ll x,y; cin >> x >> y; --x; -- y;
            g[x].pb({y,i});
            g[y].pb({x,i});
        }
        drw[0]=1;
        pa[0]={0,0};
        dfs(0);
        ll res = 1;
        fore(i,0,n){
            res = max(res,drw[i]);
        }
        cout << res << "\n";
        fore(i,0,n)g[i].clear();
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/