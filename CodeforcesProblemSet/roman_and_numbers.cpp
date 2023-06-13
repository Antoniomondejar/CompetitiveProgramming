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
 
ll dp[100][262145];
ll n,m;
vector<int> di;
int dis[10];
ll fact[19];
ll modM[1010];
void get_d(ll x){
    ll aux;
    while(x!=0){
        aux = x%10;
        di.pb(aux);
        dis[aux]++;
        x/=10;
    }
}
 
ll sz, sz_di;
 
ll f(int mod, ll mask){
    if(mask == sz) return mod==0;
    if(dp[mod][mask] != -1) return dp[mod][mask];
    ll aux = mask;
    ll res = 0;
    fore(i,0,sz_di){
        if(!(aux&1)){
            res += f(modM[mod*10+di[i]], mask + (1LL<<i));
        }
        aux>>=1LL;
    }
    dp[mod][mask] = res;
    return res;
}
 
int main(){FIN;
    fact[0]=1;
    fore(i,1,19)fact[i]=fact[i-1]*i;
    cin>>n>>m;
    fore(i,0,1010)modM[i]=i%m;
    if(n==1e18){cout << ((ll)1e18%m==0?1:0) << "\n";return 0;}
    mset(dp,-1);
    get_d(n);
    sz_di = SZ(di);
    sz = (1LL<<sz_di)-1;
    ll res = 0;
    fore(i,0,sz_di){
        if(di[i]==0)continue;
        res += f(modM[di[i]], 1LL<<i);
    }
    for(auto i:dis){
        res = res/fact[i];
    }
    cout << res << "\n";
    return 0;
}
 
/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/