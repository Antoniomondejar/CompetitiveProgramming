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
ll dp[NMAX][2];
ll va[NMAX][2];
ll vis[NMAX];
vector<ll> g[NMAX], g_a[NMAX];
void dfs(ll x){
    vis[x] = 1;
    fore(i,0,SZ(g[x])){
        ll n = g[x][i];
        if(vis[n])continue;
        g_a[x].pb(n);
        dfs(n);
    }
}

ll f(ll x, ll w){
    if(SZ(g_a[x])==0)return 0;
    if(dp[x][w]!=-1)return dp[x][w];
    dp[x][w]=0;
    fore(i,0,SZ(g_a[x])){
        dp[x][w]+=max(abs(va[x][w]-va[g_a[x][i]][0])+f(g_a[x][i],0),abs(va[x][w]-va[g_a[x][i]][1])+f(g_a[x][i],1));
    }
    return dp[x][w];
}

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        fore(i,0,n)dp[i][0]=-1,dp[i][1]=-1;
        fore(i,0,n)cin>>va[i][0]>>va[i][1];
        fore(i,0,n-1){
            ll x,y;cin>>x>>y;--x;--y;
            g[x].pb(y);g[y].pb(x);
        }
        dfs(0);
        cout << max(f(0,0),f(0,1)) << "\n";
        fore(i,0,n)g[i].clear(),vis[i]=0,g_a[i].clear();
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/