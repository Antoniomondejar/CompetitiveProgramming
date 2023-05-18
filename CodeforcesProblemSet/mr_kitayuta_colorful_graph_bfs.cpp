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
const ll NMAX = 1e2+10;
ll vis[NMAX];
vector<pair<ll,ll>> g[NMAX];

bool bfs(ll x, ll y, ll c){
    mset(vis,0);
    queue<ll> b; vis[x] = 1;
    b.push(x);
    while(SZ(b)){
        ll cv = b.front();
        b.pop();
        fore(i,0,SZ(g[cv])){
            auto n = g[cv][i];
            if(n.snd != c || vis[n.fst]) continue;
            if(n.fst == y) return true;
            vis[n.fst] = 1; b.push(n.fst);
        }
    }
    return false;
}

int main(){FIN;
    ll n, m; cin >> n >> m;
    set<ll> co;
    fore(i,0,m){
        ll x,y,c; cin >> x >> y >> c;
        g[x].pb({y,c});
        g[y].pb({x,c});
        co.insert(c);
    }
    ll q; cin >> q;
    fore(i,0,q){
        ll res = 0;
        ll x, y; cin >> x >> y;
        for(auto i:co){
            if(bfs(x,y,i)) ++res;
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/