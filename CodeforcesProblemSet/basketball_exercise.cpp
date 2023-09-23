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
const ll MOD = 1e9+7;

ll dp[NMAX][2];
ll n;
ll a[NMAX], b[NMAX];

ll f(ll x, ll cual){
    if(x==n)return 0;
    ll &res = dp[x][cual];
    if(res != -1)return res;
    if(!cual){
        res = max(b[x]+f(x+1,1),f(x+1,0));
    } else {
        res = max(a[x]+f(x+1,0), f(x+1,1));
    }
    return res;
}

int main(){FIN;
    mset(dp,-1);
    cin>>n;fore(i,0,n)cin>>a[i];
    fore(i,0,n)cin>>b[i];
    ll res=max(f(0,0),f(0,1));
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/