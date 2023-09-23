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

ll n,x,k;
ll dp[NMAX][21];
ll a[NMAX];

ll f(ll i, ll rest){
    if(n-i<rest)return -1e16;
    if(i==n)return 0;
    ll &res = dp[i][rest];
    // cout << i << " " << rest << " " << res << "\n";
    if(res!=1e18)return res;
    // cout << i << " " << rest << "\n";
    res = 0;
    if(rest==n-i){
        res = max(0LL,x+a[i]+f(i+1,rest-1));
    } else if(rest==0){
        res = max(0LL,-x+a[i]+f(i+1,0));
    } else {
        res = max({0LL,-x+a[i]+f(i+1,rest),x+a[i]+f(i+1,rest-1)});
    }
    return res;
}

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        cin>>n>>k>>x;
        fore(i,0,n)fore(j,0,21)dp[i][j]=1e18;
        fore(i,0,n)cin>>a[i];
        ll res = 0;
        fore(i,0,n){
            res = max(res,f(i,min(n-i,k)));
            res = max(res,f(i,max(0LL,k-i)));
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/