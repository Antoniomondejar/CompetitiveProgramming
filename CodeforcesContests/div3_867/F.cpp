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
ll n,k,c;
vector<ll> g[NMAX];
ll vis[NMAX];
ll dis[NMAX][2];

ll bfs(ll x, ll i){
    queue<ll> b; vis[x]=1;
    dis[x][i] = 0; b.push(x);pair<ll,ll> max_d = {0,x};
    while(SZ(b)){
        ll cv = b.front(); b.pop();
        fore(j,0,SZ(g[cv])){
            ll n = g[cv][j];
            if(vis[n])continue;
            vis[n]=1; dis[n][i]=dis[cv][i]+1;
            if(dis[n][i]>max_d.fst) max_d = {dis[n][i],n};
            b.push(n);
        }
    }
    return max_d.snd;
}

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        cin >> n >> k >> c;
        fore(i,0,n-1){
            ll x,y; cin >> x >> y; --x;--y;
            g[x].pb(y); g[y].pb(x);
        }
        ll ext1 = bfs(0,0);
        fore(i,0,n)vis[i]=0;
        ll ext2 = bfs(ext1,0);
        fore(i,0,n)vis[i]=0;
        bfs(ext2,1);
        queue<pair<ll,ll>> b; b.push({0,0});
        fore(i,0,n)vis[i]=0;
        vis[0] = 1;
        ll max_d = k*max(dis[0][0],dis[0][1]);
        while(SZ(b)){
            auto cv = b.front(); b.pop();
            max_d = max(max_d,k*max(dis[cv.fst][0],dis[cv.fst][1])-cv.snd);
            fore(i,0,SZ(g[cv.fst])){
                ll n = g[cv.fst][i];
                if(vis[n])continue;
                vis[n]=1;b.push({n,cv.snd+c});
            }
        }
        cout << max_d << "\n";
        fore(i,0,n){
            vis[i]=0;
            g[i].clear();
            dis[i][0]=0; dis[i][1]=0;
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/