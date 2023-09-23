#include "bits/stdc++.h"
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fore(i,a,b) for (int i=a, ggdem=b; i<ggdem; ++i)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
const ll NMAX = 3e5+10;
const ll MOD = 998244353;

ll n;
ll pa[NMAX], vis[NMAX];
ll dp[NMAX][4];
vector<ll> g[NMAX], g_p[NMAX];

ll mul(ll x, ll y){
    return (x*y)%MOD;
}

ll add(ll x, ll y){
    return (x+y)%MOD;
}

void dfs(ll x){
    vis[x]=1;
    fore(i,0,SZ(g[x])){
        if(vis[g[x][i]])continue;
        pa[g[x][i]]=x;
        dfs(g[x][i]);
    }
}

ll f(ll x, ll cuan){
    ll &res = dp[x][cuan];
    if(res!=-1)return res;
    if(cuan == 0){
        res = 1;
        fore(i,0,SZ(g_p[x])){
            res=mul(res,f(g_p[x][i],0));
        }
        vector<ll> pre(SZ(g_p[x])+1), suf(SZ(g_p[x])+1);
        pre[0]=1,suf[SZ(g_p[x])]=1;
        fore(i,0,SZ(g_p[x])){
            pre[i+1]=mul(pre[i],add(f(g_p[x][i],0),f(g_p[x][i],2)));
        }
        for(int i = SZ(g_p[x])-1;i>=0;i--){
            suf[i]=mul(suf[i+1],add(f(g_p[x][i],0),f(g_p[x][i],2)));
        }
        fore(i,0,SZ(g_p[x])){
            res = add(res, mul(mul(f(g_p[x][i],1),pre[i]), suf[i+1]));
        }
    } else if (cuan == 1){
        res = 1;
        fore(i,0,SZ(g_p[x])){
            res = mul(res, add(f(g_p[x][i],2),f(g_p[x][i],0)));
        }
    } else {
        res = 0;
        vector<ll> pre(SZ(g_p[x])+1), suf(SZ(g_p[x])+1);
        pre[0]=1,suf[SZ(g_p[x])]=1;
        fore(i,0,SZ(g_p[x])){
            pre[i+1]=mul(pre[i],add(f(g_p[x][i],0),f(g_p[x][i],2)));
        }
        for(int i = SZ(g_p[x])-1;i>=0;i--){
            suf[i]=mul(suf[i+1],add(f(g_p[x][i],0),f(g_p[x][i],2)));
        }
        fore(i,0,SZ(g_p[x])){
            res = add(res, mul(mul(f(g_p[x][i],1),pre[i]),suf[i+1]));
        }
    }
    // cout << x << " " << cuan << " " << res << "\n";
    return res;
}


int main(){
    cin>>n;
    fore(i,0,n-1){
        ll x,y;cin>>x>>y;--x;--y;
        g[x].pb(y);g[y].pb(x);
    }
    if(n==1){cout << "1\n";return 0;}
    mset(vis,0);
    pa[0]=-1;
    dfs(0);
    fore(i,0,n){
        fore(j,0,SZ(g[i])){
            if(pa[i]==g[i][j])continue;
            g_p[i].pb(g[i][j]);
        }
    }
    mset(dp,-1);
    ll res = f(0,0);
    cout << res << "\n";
    return 0;
}