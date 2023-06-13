#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll NMAX = 85;
int dp[NMAX][NMAX][NMAX][NMAX];
vector<pair<ll,ll>> g[NMAX];
ll n,k,m;

int f(ll x, ll k, ll mi, ll ma){
    if(k == 0) return 0;
    if(x==n) return 80010;
    if(dp[x][k][mi][ma] != -1) return dp[x][k][mi][ma];
    ll res = 80010;
    fore(i,0,SZ(g[x])){
        if(g[x][i].first>mi && g[x][i].first<ma){
            if(x<g[x][i].first){
                res = min(res,g[x][i].second+f(g[x][i].first, k-1, x, ma));
            } else {
                res = min(res,g[x][i].second+f(g[x][i].first, k-1, mi, x));
            }
        }
    }
    dp[x][k][mi][ma] = res;
    return res;
}

int main(void){FIN;
    cin >>n>>k>>m;
    mset(dp,-1);
    fore(i,0,m){
        ll x,y,c; cin>>x>>y>>c;--x;--y;
        g[x].pb({y,c});
    }
    int res = 80010;
    fore(i,0,n){
        res = min(res, f(i,k-1,-1,NMAX));
    }
    if(res >= 80010) cout << "-1\n";
    else cout << res << "\n";
    return 0;
}