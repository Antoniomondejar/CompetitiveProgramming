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
ll dp[NMAX];
ll a[NMAX];
ll n;
ll f(ll x){
    if(x>n-1)return 0;
    if(dp[x]!=-1)return dp[x];
    dp[x]=a[x]+f(x+a[x]);
    return dp[x];
}
int main(){FIN;
    ll t; cin >> t;
    while(t--){
        mset(dp,-1);
        cin >> n;
        fore(i,0,n) cin >>a[i];
        ll max_d = 0;
        fore(i,0,n) max_d = max(max_d, f(i));
        cout << max_d << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/