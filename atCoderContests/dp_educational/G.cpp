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
ll dp[NMAX];

ll f(ll x){
    if(dp[x]!=-1)return dp[x];
    if(SZ(g[x])==0)return 0;
    fore(i,0,SZ(g[x])){
        dp[x] = max(dp[x],f(g[x][i])+1);
    }
    return dp[x];
}

int main(){FIN;
    ll N,M; cin>>N>>M;
    fore(i,0,M){
        ll x, y; cin>>x>>y; --x;--y;
        g[x].pb(y);
    }
    mset(dp,-1);
    ll max_d = 0;
    fore(i,0,N){
        max_d = max(max_d,f(i));
    }
    cout << max_d << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/