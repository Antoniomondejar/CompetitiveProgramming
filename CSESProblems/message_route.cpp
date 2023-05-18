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
const ll NMAX = 1e5+10;

vector<ll> g[NMAX];
ll vis[NMAX];
ll ag[NMAX];

bool bfs(ll n){
    vis[0] = 1;
    queue<ll> b_q; b_q.push(0);
    while(SZ(b_q)){
        ll cv = b_q.front();
        b_q.pop();
        for(auto i:g[cv]){
            if(vis[i])continue;
            vis[i] = 1; ag[i] = cv; b_q.push(i);
            if(i==n) return true;
        }
    }
    return false;
}


int main(){FIN;
    ll n,m; cin >> n >> m;
    fore(i,0,m){
        ll x,y; cin >> x >> y; --x; --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    bool p = bfs(n-1);
    if(!p) cout << "IMPOSSIBLE\n";
    ll k = 1; ll x_aux = n-1; vector<ll> pa; pa.pb(n-1);
    while(x_aux != 0){
        x_aux = ag[x_aux]; ++k;
        pa.pb(x_aux);
    }
    cout << k << "\n";
    fore(i,0,k) cout << pa[k-1-i]+1 << " ";
    cout << "\n";
    return 0;
}