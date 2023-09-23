#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

ll add(ll x, ll y){
    return(x+y)%MOD;
}
ll mul(ll x, ll y){
    return(x*y)%MOD;
}

ll n,m;
ll dp[21][1048586];
int g[21][21];

ll f(ll x, ll mask){
    if(mask>=1<<(n-1) && mask != (1<<n)-1)return 0;
    if(mask==(1<<n)-1)return 1;
    ll &res = dp[x][mask];
    if(res!=-1)return res;
    res=0; ll mask_aux = mask;
    fore(i,0,n){
        if(!(mask_aux&1) && g[x][i]){
            res = add(res,mul(g[x][i],f(i,mask+(1LL<<i))));
        }
        mask_aux/=2;
    }
    // cout << x << " " << mask << " " << res << "\n";
    return res;
}


int main(){FIN;
    mset(dp,-1);
    cin>>n>>m;
    fore(i,0,m){
        int x,y; cin >> x >> y; --x;--y;
        g[x][y]++;
    }
    ll res = f(0,1);
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/