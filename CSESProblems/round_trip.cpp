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
ll ag[NMAX];
ll vis[NMAX];


vector<ll> bfs(ll v){
    vis[v] = 1;
    queue<pair<ll,ll>> b_q; b_q.push({v,-1});
    while(SZ(b_q)){
        auto cv = b_q.front();
        b_q.pop();
        fore(i,0,SZ(g[cv.fst])){
            ll n = g[cv.fst][i];
            if(vis[n] && n!=cv.snd) return {n,cv.fst,v};
            else if(vis[n]) continue;
            vis[n] = 1; b_q.push({n,cv.fst}); ag[n] = cv.fst;
        }
    }
    return {-1};
}


int main(){FIN;
    ll n,m; cin >> n >> m;
    fore(i,0,m){
        ll x, y; cin >> x >> y; --x; --y;
        g[x].pb(y); g[y].pb(x);
    }
    vector<ll> res; bool p = false;
    fore(i,0,n){
        if(!vis[i]){
            res = bfs(i);
            if(res[0] != -1){p = true; break;}
        }
    }
    if(!p) {cout << "IMPOSSIBLE\n"; return 0;}
    vector<ll> pa_v; ll l = 1; pa_v.pb(res[0]); pa_v.pb(res[1]);
    ll x_aux = res[1];
    set<ll> al;
    while(x_aux != res[2]){
        x_aux = ag[x_aux];
        pa_v.pb(x_aux);
        al.insert(x_aux);
    }
    vector<ll> pa_n;
    if(res[0]!=res[2]){
        x_aux = res[0];
        while(x_aux != res[2]){
            pa_n.pb(x_aux);
            x_aux = ag[x_aux];
        }
    }
    cout << SZ(pa_n) + SZ(pa_v) << "\n";
    fore(i,0,SZ(pa_n)){
        cout << pa_n[i]+1 << " ";
    }
    fore(i,0,SZ(pa_v)){
        cout << pa_v[SZ(pa_v)-1-i]+1 << " ";
    }
    cout << "\n";
    return 0;
}