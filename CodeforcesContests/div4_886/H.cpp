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
const ll MOD = 1e9+7;

vector<pair<ll,ll>> g[NMAX];
ll co[NMAX];ll vis[NMAX];

void dfs(ll x){
    vis[x]=1;
    fore(i,0,SZ(g[x])){
        if(vis[g[x][i].fst])continue;
        co[g[x][i].fst]=co[x]+g[x][i].snd;
        vis[g[x][i].fst]=1;
        dfs(g[x][i].fst);
    }
}

int main(){FIN;
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        fore(i,0,n)g[i].clear(),co[i]=0,vis[i]=0;
        fore(i,0,m){
            ll a,b,d;cin>>a>>b>>d;--a;--b;
            g[b].pb({a,d});
            g[a].pb({b,-d});
        }
        fore(i,0,n){
            if(!vis[i])
                dfs(i);
        }
        bool p = true;
        fore(i,0,n){
            fore(j,0,SZ(g[i])){
                p = p&&co[i]+g[i][j].snd==co[g[i][j].fst];
            }
        }
        if(p)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/