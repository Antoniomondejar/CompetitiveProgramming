#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a, ggdem=b; i<ggdem; ++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll NMAX = 3e3+10;
ll a[NMAX], b[NMAX], c[NMAX];
ll n;
ll dp[NMAX][2];

ll f(ll x, ll y){
    if(x == n) return 0;
    ll &res = dp[x][y];
    if(res != -1)return res;
    res = 0;
    if(x == 0){
        res = max(a[0]+f(x+1,1), b[0]+f(x+1,0));
    } else if(x==n-1 && y == 0){
        res = a[x];
    } else if(x==n-1 && y == 1){
        res = b[x];
    } else if(y == 0){
        res = max(a[x]+f(x+1,1),b[x]+f(x+1,0));
    } else {
        res = max(b[x]+f(x+1,1),c[x]+f(x+1,0));
    }
    return res;
}


int main(void){FIN;
    mset(dp,-1);
    cin >> n;
    fore(i,0,n)cin>>a[i];
    fore(i,0,n)cin>>b[i];
    fore(i,0,n)cin>>c[i];
    if(n==1){cout << a[0] <<"\n";return 0;}
    ll res = f(0,0);
    cout << res << "\n";
    return 0;
}