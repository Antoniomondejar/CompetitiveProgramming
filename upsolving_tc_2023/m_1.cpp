#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define fore(i,a,b) for(int i=a,ggdem=b; i<ggdem; ++i)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF=1e18;
const int NMAX = 1e5+10;

vector<ll> g[NMAX];
pair<ll,ll> times[NMAX];
ll vis[NMAX];
ll ti;

void dfs(ll x){
    vis[x]=1;times[x].fst=ti;
    ++ti;
    fore(i,0,SZ(g[x])){
        if(vis[g[x][i]])continue;
        dfs(g[x][i]);
    }
    times[x].snd=ti;
}

int main(){FIN;
    ll n,q;cin>>n>>q;
    ti=0;
    fore(i, 0, n) {
        ll a;cin>>a;
        if(a==-1){g[0].pb(i+1);g[i+1].pb(0);}
        else {
            g[a+1].pb(i+1);
            g[i+1].pb(a+1);
        }
    }
    dfs(0);
    fore(i, 0, q) {
        ll x,y;cin>>x>>y;
        x++;y++;
        if(x==y){cout << "Yes\n";continue;}
        // cout << res << "\n";
        if (times[x].fst>times[y].fst && times[x].fst<times[y].snd) cout << "Yes\n";
        else cout << "No\n";
    }    
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/