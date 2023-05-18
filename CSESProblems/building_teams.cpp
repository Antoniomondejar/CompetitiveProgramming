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
const ll NMAX = 1e5 +10;

vector<ll> g[NMAX];
ll c[NMAX];
ll vis[NMAX];


void bfs(ll v){
    vis[v] = 1;
    queue<pair<ll,ll>> b_q;
    b_q.push({v,1});
    while(SZ(b_q)){
        auto cv = b_q.front();
        c[cv.fst] = cv.snd;
        b_q.pop();
        fore(i,0,SZ(g[cv.fst])){
            ll n = g[cv.fst][i];
            if(vis[n]) continue;
            vis[n] = 1; b_q.push({n,cv.snd==1?2:1});
        } 
    }
}

int main(){FIN;
    ll n, m; cin >> n >> m;
    fore(i,0,m){
        ll x,y;
        cin >> x >> y; --x; --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    fore(i,0,n){
        if(!vis[i])
            bfs(i);
    }
    bool p = true;   
    fore(i,0,n){
        fore(j,0,SZ(g[i])){
            if(c[i] == c[g[i][j]]){p = false; break;}
        }
    }
    if(!p) {cout << "IMPOSSIBLE\n"; return 0;}
    fore(i,0,n) cout << c[i] << " ";
    cout << "\n";
    return 0;
}