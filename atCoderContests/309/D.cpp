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
const ll NMAX = 3e5+10;
const ll MOD = 1e9+7;

vector<ll> g[NMAX];
ll vis[NMAX];
ll dis[NMAX];

ll bfs(ll x){
    queue<ll> b; vis[x]=1;b.push(x);
    dis[x]=0; ll res = 0;
    while(SZ(b)){
        auto cv = b.front();b.pop();
        for(auto i:g[cv]){
            if(vis[i])continue;
            vis[i]=1;
            dis[i]=dis[cv]+1;res = max(res,dis[i]);
            b.push(i);
        }
    }
    return res;
}

int main(){FIN;
    ll n1,n2,m;cin>>n1>>n2>>m;
    fore(i,0,m){
        ll x,y;cin>>x>>y;--x;--y;
        g[x].pb(y);g[y].pb(x);
    }
    ll res = bfs(0)+bfs(n1+n2-1)+1;
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/