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
const ll NMAX = 1e2+10;

ll dp[NMAX];
ll va[NMAX];
ll wi[NMAX];

ll f(ll x, ll w){
    cout << w << " " << wi[x] << "\n";
    if(x==0)return 0;
    if(dp[x]!=-1)return dp[x];
    if(wi[x]<=w) dp[x] = max(f(x-1,w-wi[x])+va[x],f(x-1,w));
    else dp[x] = f(x-1,w);
    cout << x << " " << dp[x] << "\n";
    return dp[x];
}

int main(){FIN;
    ll N, W; cin >> N >> W;
    mset(dp,-1);
    fore(i,1,N+1) cin >> wi[i] >> va[i];
    cout << f(N,W) << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/