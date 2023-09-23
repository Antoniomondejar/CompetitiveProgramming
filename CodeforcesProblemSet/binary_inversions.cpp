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

ll dp[NMAX][2];
ll n;
ll s[NMAX];
ll on_b[NMAX],ze_a[NMAX];

ll f(ll x, ll did){
    if(x==n)return 0;
    ll &res = dp[x][did];
    if(res!=-1)return res;
    res = 0;
    if(did){
        if(s[x]==0)
            res = f(x+1,did);
        else
            res = ze_a[x]+f(x+1,did);
    } else {
        if(s[x]==0){
            res = max(f(x+1,did),ze_a[x]-on_b[x]+f(x+1,1));
        } else {
            res = max(ze_a[x]+f(x+1,did),on_b[x]+f(x+1,1));
        }
    }
    // cout << x << " " << did << " " << res << " " << ze_a[x] << "\n";
    return res;
}

int main(){FIN;
    ll t;cin>>t;
    while(t--){
        cin>>n;
        fore(i,0,n)dp[i][0]=-1,dp[i][1]=-1;
        ll ze=0;
        fore(i,0,n)cin>>s[i],ze+=s[i]==0;
        ll on=0;
        fore(i,0,n){
            on_b[i]=on;
            ze-=s[i]==0;
            ze_a[i]=ze;
            on+=s[i]==1;
        }
        ll res = f(0,0);
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/