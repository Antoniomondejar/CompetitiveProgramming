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

pair<ll,ll> dp[NMAX][2];
vector<ll> g[NMAX];
ll pa[NMAX], vis[NMAX];

pair<ll,ll> f(ll x, ll did){
    pair<ll,ll> &res = dp[x][did];
    if(res.fst!=-1)return res;
    res = {0,-1};
    if(did){
        fore(i,0,SZ(g[x])){
            if(pa[x]==g[x][i])continue;
            res.fst += f(g[x][i],0).fst;
            res.snd += f(g[x][i],0).snd; 
        }
    } else {
        pair<ll,ll> res_aux_1 = {1,-SZ(g[x])}, res_aux_2 = {0,-1};
        fore(i,0,SZ(g[x])){
            if(pa[x]==g[x][i])continue;
            res_aux_1.fst += f(g[x][i],1).fst;
            res_aux_1.snd += f(g[x][i],1).snd;
        }
        fore(i,0,SZ(g[x])){
            if(pa[x]==g[x][i])continue;
            res_aux_2.fst += f(g[x][i],0).fst;
            res_aux_2.snd += f(g[x][i],0).snd; 
        }
        res = max(res_aux_1,res_aux_2);
    }
    // cout << x << " " << did << " " << res.fst << " " << res.snd << "\n";
    return res;
}

void dfs(ll x){
    vis[x]=1;
    fore(i,0,SZ(g[x])){
        if(vis[g[x][i]])continue;
        vis[g[x][i]]=1;pa[g[x][i]]=x;
        dfs(g[x][i]);
    }
}

vector<ll> ans;

void build(ll x, ll did){
    pair<ll,ll> res = f(x,did);
    if(did){
        ans[x]=1;
        fore(i,0,SZ(g[x])){
            if(pa[x]==g[x][i])continue;
            build(g[x][i],0);
        }
    } else {
        pair<ll,ll> res_aux_1 = {1,-SZ(g[x])}, res_aux_2 = {0,-1};
        fore(i,0,SZ(g[x])){
            if(pa[x]==g[x][i])continue;
            res_aux_1.fst += f(g[x][i],1).fst;
            res_aux_1.snd += f(g[x][i],1).snd;
        }
        fore(i,0,SZ(g[x])){
            if(pa[x]==g[x][i])continue;
            res_aux_2.fst += f(g[x][i],0).fst;
            res_aux_2.snd += f(g[x][i],0).snd; 
        }
        if(res == res_aux_1){
            ans[x]=SZ(g[x]);
            fore(i,0,SZ(g[x])){
                if(pa[x]==g[x][i])continue;
                build(g[x][i],1);
            }
        } else {
            ans[x]=1;
            fore(i,0,SZ(g[x])){
                if(pa[x]==g[x][i])continue;
                build(g[x][i],0);
            }
        }
    }
}


int main(){FIN;
    ll n;cin>>n;
    ans.resize(n);
    fore(i,0,n-1){
        ll x,y;cin>>x>>y;--x;--y;
        g[x].pb(y);g[y].pb(x);
    }
    if(n==2){cout << "2 2\n";cout << "1 1\n";return 0;}
    dfs(0);
    fore(i,0,n)dp[i][0]={-1,-1},dp[i][1]={-1,-1};
    build(0,0);
    pair<ll,ll> res = f(0,0);
    cout << res.fst << " " << -res.snd << "\n";
    fore(i,0,n) cout << ans[i] << " "; 
    cout << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/