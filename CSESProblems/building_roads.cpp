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
const ll NMAX = 1e5 + 10;

vector<ll> g[NMAX];
ll vis[NMAX];

ll bfs(ll v){
    queue<ll> b_q;
    vis[v] = 1;
    b_q.push(v);
    while(SZ(b_q)){
        ll cv = b_q.front();
        b_q.pop();
        fore(i,0,SZ(g[cv])){
            ll n = g[cv][i];
            if(vis[n])continue;
            vis[n] = 1; b_q.push(n);
        }
    }
    return v+1;
}

int main(){FIN;
    ll n,m; cin >> n >> m;
    fore(i,0,m){
        ll x,y;
        cin >> x >> y; --x; --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    vector<ll> c_r;
    fore(i,0,n){
        if(!vis[i])
            c_r.pb(bfs(i));
    }
    cout << SZ(c_r)-1 << "\n";
    fore(i,1,SZ(c_r)){
        cout << c_r[i-1] << " " << c_r[i] << "\n";
    }
    return 0;
}