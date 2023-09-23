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
const ll MOD = 1e9+7;

ll fact[16];
ll dp[32768];
ll n;
ll f(ll mask){
    ll &res = dp[mask];
    if(res!=-1)return res;
    ll cant = 0;
    ll mask_aux = mask; ll i=1;
    ll can_u=0;
    while(mask_aux>0){
        if(mask_aux&1){
            cant+=fact[i];
            can_u+=1;
        }
        ++i;
        mask_aux/=2;
    }
    if(cant>n)return 1e18;
    ll n_aux = n-cant;res = can_u;
    while(n_aux>0){
        if(n_aux&1)++res;
        n_aux/=2;
    }
    mask_aux = mask;
    fore(i,0,15){
        if(mask_aux%2==0){
            res = min(res,f(mask+(1LL<<i)));
        }
        mask_aux/=2;
    }
    return res;
}


int main(){FIN;
    ll t;cin>>t;
    fact[1]=1;
    fore(i,2,16)fact[i]=i*fact[i-1];
    while(t--){
        mset(dp,-1);
        cin>>n;
        ll res = f(0);
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/