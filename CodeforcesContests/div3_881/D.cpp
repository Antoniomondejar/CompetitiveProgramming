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

ll vis[NMAX];
vector<ll> g[NMAX];
ll nodes[NMAX];

ll dfs(ll x){
    vis[x]=1; ll res = 0;
    fore(i,0,SZ(g[x])){
        if(vis[g[x][i]])continue;
        res += dfs(g[x][i]);
    }
    if(res == 0) res = 1;
    nodes[x] = res;
    return res;
}


int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        fore(i,0,n)vis[i]=0,nodes[i]=0,g[i].clear();
        fore(i,0,n-1){
            ll x,y; cin >> x >> y; --x; --y;
            g[x].pb(y); g[y].pb(x);
        }
        ll q; cin >> q;
        dfs(0);
        while(q--){
            ll x,y; cin >> x >> y; --x; --y;
            cout << nodes[x]*nodes[y] << "\n";
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/