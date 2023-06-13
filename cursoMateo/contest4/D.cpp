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
const ll NMAX = 4e4+10;
const ll MOD = 1e9+7;
ll add(ll x, ll y){
    return (x+y)%MOD;
}
ll dp[600][NMAX];
vector<ll> pa;

bool is_pal(ll x){
    vector<ll> di;
    while(x>0){
        di.pb(x%10);
        x/=10;
    }
    bool p = true;
    fore(i,0,SZ(di)){
        p &= di[SZ(di)-1-i]==di[i];
    }
    return p;
}

ll f(ll x, ll y){ //Problema de la mochila para expresar un numero como suma de otros.
    if(y == 0) return 1;
    if(y<0) return 0;
    if(x == SZ(pa)) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    dp[x][y] = add(f(x,y-pa[x]),f(x+1,y));
    return dp[x][y];
}

int main(){FIN;
    fore(i,1,NMAX){
        if(is_pal(i)){
            pa.pb(i);
        }
    }
    ll t; cin >> t;
    fore(i,0,600)fore(j,0,NMAX)dp[i][j]=-1;
    fore(i,1,NMAX){
        f(0,i);
    }
    while(t--){
        ll n; cin >> n;
        cout << f(0,n) << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/