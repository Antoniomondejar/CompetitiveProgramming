#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,thxMat=b;i<thxMat;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

ll n;
ll dp[NMAX][2];
ll di[NMAX];

ll f(ll x, ll can){
    if(x==n)return 1;
    ll &res = dp[x][can];
    if(res!=-1)return res;
    if(can){
        res = max((di[x]+1)*f(x+1,0),di[x]*f(x+1,1));
    } else {
        res = di[x]*f(x+1,0);
    }
    return res;
}



int main(){FIN;
    ll t;cin>>t;
    while(t--){
        cin>>n;
        fore(i,0,n)fore(j,0,2)dp[i][j]=-1;
        ll maxi = 0;
        fore(i,0,n){
            cin>>di[i];
            maxi=max(di[i],maxi);
        }
        ll res = f(0,1);
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/