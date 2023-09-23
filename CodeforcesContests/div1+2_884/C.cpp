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

ll dp[NMAX];
ll n;
ll c[NMAX];
ll f(ll x){
    if(x>=n)return 0;
    ll &res = dp[x];
    if(res!=1e18)return res;
    res = max(f(x+2)+c[x], f(x+2));
    return res;
}

int main(){FIN;
    ll t;cin>>t;
    while(t--){
        cin>>n;
        fore(i,0,n)cin>>c[i];
        fore(i,0,n)dp[i]=1e18;
        bool ne=false;
        ll max_r=c[0];
        fore(i,0,n){
            if(c[i]>=0)ne=true;
            max_r=max(max_r,c[i]);
        }
        if(!ne){cout << max_r << "\n";continue;}
        ll res = max(f(0),f(1));
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/