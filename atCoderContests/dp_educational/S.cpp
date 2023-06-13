#include "bits/stdc++.h"
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
const ll NMAX = 1e4+10;
const ll MOD = 1e9+7;

ll add(ll x, ll y){
    return (x+y)%MOD;
}

string K;
ll D;
ll dp[NMAX][110][2];

ll f(ll x, ll m, ll b){
    if(x == SZ(K)) return m==0;
    ll &res = dp[x][m][b];
    if(res != -1) return res;
    res = 0;
    if(!b){
        ll di = K[x]-'0';
        res = f(x+1, (m+di)%D, 0);
        fore(i,0,di){
            res = add(res, f(x+1, (m+i)%D, 1));
        }
    } else {
        res = 0;
        fore(i,0,10){
            res = add(res, f(x+1, (m+i)%D, 1));
        }
    }
    return res;
}

int main(){FIN;
    cin>>K>>D;
    mset(dp,-1);
    cout << ((f(0,0,0)-1)%MOD+MOD)%MOD << '\n';
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/