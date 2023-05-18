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

const ll NMAX = 1e4+10;

vector<ll> g[NMAX];
ll gr[NMAX][NMAX];

ll bfs(ll v, ll R, ll C){
    queue<ll> b_q; vector<ll> vis(R*C, 0);
    vis[v] = 1;
    b_q.push(v);
    ll res = 1;
    while(SZ(b_q)){
        ll cv = b_q.front();
        b_q.pop();
        fore(i,0,SZ(g[cv])){
            ll n = g[cv][i];
            if(vis[n] || n < cv) continue;
            vis[n] = 1; b_q.push(n); ++res;
        }
    }
    return res;
}


int main(){FIN;
    ll R,C; cin >> R >> C;
    fore(i,0,R) fore(j,0,C) cin >> gr[i][j], --gr[i][j];
    fore(i,0,R){
        fore(j,0,C){
            if(i>0) g[gr[i][j]].pb(gr[i-1][j]);
            if(i<R-1) g[gr[i][j]].pb(gr[i+1][j]);
            if(j>0) g[gr[i][j]].pb(gr[i][j-1]);
            if(j<C-1) g[gr[i][j]].pb(gr[i][j+1]);
        }
    }
    ll res = -1;
    fore(i,0,R*C){
        res = max(res, bfs(i,R,C));
    }
    cout << res << "\n";
    return 0;
}