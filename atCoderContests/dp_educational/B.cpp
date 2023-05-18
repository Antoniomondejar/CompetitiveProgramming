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

ll dp[NMAX];
ll hi[NMAX];
ll k;
ll f(ll x){
    if(x<0)return 1e9+10;
    if(x==0)return 0;
    if(dp[x]!=-1)return dp[x];
    dp[x] = abs(hi[x]-hi[x-1])+f(x-1);
    cout << k << "\n";
    fore(i,2,k+1)dp[x]=min(dp[x],abs(hi[x]-hi[x-i])+f(x-i));
    return dp[x];
}

int main(){FIN;
    ll N; cin >> N >> k;
    mset(dp,-1);
    fore(i,0,N) cin >> hi[i];
    cout << f(N-1) << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/