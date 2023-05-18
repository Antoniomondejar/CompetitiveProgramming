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
const ll NMAX= 2e5 +10;

vector<ll> g[NMAX];
ll vis[NMAX];

bool bfs(ll x){
    vis[x] = 1;
    queue<ll> b; b.push(x);
    bool p = true;
    while(SZ(b)){
        ll cv = b.front(); b.pop();
        if(SZ(g[cv])!=2) p = false;
        fore(i,0,SZ(g[cv])){
            ll n = g[cv][i];
            if(vis[n])continue;;
            vis[n] = 1; b.push(n);
        }
    }
    return p;
}

int main(){FIN;
    ll n,m; cin >> n >> m;
    fore(i,0,m){
        ll x, y; cin >> x >> y; --x; --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    ll res = 0;
    fore(i,0,n){
        if(!vis[i]){
            ll aux = bfs(i);
            res += aux;
        }
    }
    cout << res << "\n";
    return 0;
}