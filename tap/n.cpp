#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int ) x.size())
#define fore(i,a,b) for(int i=a,gmat=b;i<gmat;++i)
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll NMAX = 2e5+10;

ll dp[NMAX][5];
ll n;
ll c[NMAX];

ll f(ll x, ll mod){
    if(x==n) return (mod==0);
    ll &res = dp[x][mod];
    if(res!=-1)return res;
    res = f(x+1,mod)+f(x+1,(mod+c[x])%5);
    cout << x << " " << mod << " " << res << "\n";
    return res;
}


int main(){FIN;
    mset(dp,-1);
    cin>>n;
    fore(i,0,n)cin>>c[i];
    ll res = 0;
    fore(i,0,n){
        res += f(i+1,c[i]%5);
    }
    cout << res << "\n";
    return 0;
}


